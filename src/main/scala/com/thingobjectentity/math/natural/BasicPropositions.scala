package com.thingobjectentity.math.natural

import com.thingobjectentity.math.logic.{Axioms, Equals}
import com.thingobjectentity.math.set.Member

/**
  * Basic proofs in number theory.
  *
  * Created by cosmos on 4/16/16.
  */
trait BasicPropositions extends Naturals with Axioms {

  //        1 + 1 == 2
  //
  // My first proof using scala. I like how you can read the proof
  // by reading the types of the variables.
  def proposition1() : Equals[Plus[Suc[Zero], Suc[Zero]], Suc[Suc[Zero]]] = {

    val step1 : Equals[Suc[Zero], Suc[Zero]] = suc(reflexive())

    val plusZero : Equals[Suc[Zero], Plus[Suc[Zero], Zero]] = plusBase()

    val step2 : Equals[Suc[Plus[Suc[Zero], Zero]], Suc[Suc[Zero]]] =
      suc(step1.transformLeft(plusZero))

    val one : Suc[Zero] = suc(zero, zero.isNatural)

    val step3 : Equals[Plus[Suc[Zero], Suc[Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      plus(one, one.isNatural, step1)

    val step4 : Equals[Suc[Plus[Suc[Zero], Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      step3.transformLeft(plusInductive())

    transitive(step4.reverse(), step2)
  }

  // We have to define a new type every time we make an inductive argument.
  class Lemma1[x](c : Equals[Plus[Zero, x], Plus[x, Zero]]) {
    val claim : Equals[Plus[Zero, x], Plus[x, Zero]] = c
  }

  // First proof using mathematical induction! It says that 0 + x = x + 0
  def lemma1[x]() : Member[x, Naturals] => Equals[Plus[Zero, x], Plus[x, Zero]] = {

    val baseCase : Lemma1[Zero] = new Lemma1(reflexive())

    val inductionCase = (l1 : Lemma1[x]) => {

      val step1 : Equals[Suc[Plus[Zero, x]], Suc[x]] =
        suc(l1.claim.transformRight(plusBase().reverse()))

      val step2 : Equals[Plus[Zero, Suc[x]], Plus[Suc[x], Zero]] =
        step1.transformRight(plusBase()).transformLeft(plusInductive().reverse())

      new Lemma1[Suc[x]](step2)
    }

    (mem : Member[x, Naturals]) => {
      induction(baseCase, inductionCase)(mem).claim
    }
  }

  class CommutativePlus[x, y](c : Member[x, Naturals] => Equals[Plus[y, x], Plus[x, y]]) {

    class Lemma2[z](c : Member[x, Naturals] => Equals[Plus[z, x], Plus[x, z]]) {
      val claim : Member[x, Naturals] => Equals[Plus[z, x], Plus[x, z]] = c
    }

    val lem2 = new Lemma2[y](c)
  }

  def commutativePlus[x, y]()
    : Member[x, Naturals] => Member[y, Naturals] => CommutativePlus[x, y] = {

    val cp : Lemma2[Zero] = new CommutativePlus(lemma1[x]()).lem2
  }
}
