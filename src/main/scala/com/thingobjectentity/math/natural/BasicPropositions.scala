package com.thingobjectentity.math.natural

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.set.Member

/**
  * Basic proofs in number theory.
  *
  * Created by cosmos on 4/16/16.
  */
trait BasicPropositions extends ℕ with Axioms {

  //
  //        1 + 1 == 2
  //
  // My first proof using scala. I like how you can read the proof
  // by reading the types of the variables.
  def proposition1() : Equal[Plus[Suc[Zero], Suc[Zero]], Suc[Suc[Zero]]] = {

    val step1 : Equal[Suc[Zero], Suc[Zero]] = suc(reflexive())

    val plusZero : Equal[Suc[Zero], Plus[Suc[Zero], Zero]] = plusBase()

    val step2 : Equal[Suc[Plus[Suc[Zero], Zero]], Suc[Suc[Zero]]] =
      suc(step1.transformLeft(plusZero))

    val one : Suc[Zero] = suc(zero.isNatural)

    val step3 : Equal[Plus[Suc[Zero], Suc[Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      plus(one, one.isNatural, step1)

    val step4 : Equal[Suc[Plus[Suc[Zero], Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      step3.transformLeft(plusInductive().reverse())

    transitive(step4.reverse(), step2)
  }

  // We have to define a new type every time we make an inductive argument.
  class Lemma1[x](c : Equal[Plus[x, Zero], Plus[Zero, x]]) {
    val claim : Equal[Plus[x, Zero], Plus[Zero, x]] = c
  }

  // First proof using mathematical induction! It says that 0 + x = x + 0
  def lemma1[x]() : Member[x, ℕ] => Equal[Plus[x, Zero], Plus[Zero, x]] = {

    val baseCase : Lemma1[Zero] = new Lemma1(reflexive())

    val inductionCase = (l1 : Lemma1[x]) => {

      val step1 : Equal[Suc[x], Suc[Plus[Zero, x]]] =
        suc(l1.claim.transformLeft(plusBase().reverse()))

      val step2 : Equal[Plus[Suc[x], Zero], Plus[Zero, Suc[x]]] =
        step1.transformLeft(plusBase()).transformRight(plusInductive())

      new Lemma1[Suc[x]](step2)
    }

    (mem : Member[x, ℕ]) => {
      induction(baseCase, inductionCase)(mem).claim
    }
  }

  // Next we prove by induction over x that Suc(x) = 1 + x
  class Lemma2[x](c : Equal[Suc[x], Plus[Suc[Zero], x]]) {
    val claim : Equal[Suc[x], Plus[Suc[Zero], x]] = c
  }

  def lemma2[x]() : Member[x, ℕ] => Equal[Suc[x], Plus[Suc[Zero], x]] = {

    val step1 : Equal[Suc[Zero], Plus[Suc[Zero], Zero]] =
      plus(zero, zero.isNatural, reflexive[Suc[Zero]]()).transformLeft(plusBase().reverse())

    val baseCase : Lemma2[Zero] = new Lemma2(step1)

    val inductionCase = (l2 : Lemma2[x]) => {

      val step1 : Equal[Suc[Suc[x]], Plus[Suc[Zero], Suc[x]]] =
        suc(l2.claim).transformRight(plusInductive())

      new Lemma2[Suc[x]](step1)
    }

    (mem : Member[x, ℕ]) => {
      induction(baseCase, inductionCase)(mem).claim
    }
  }

  // Next we prove by induction over y that that Suc(x + y) = Suc(x) + y
  // We have an axiom that says Suc(x + y) = x + Suc(y) but we need to go the other way.
  class Lemma3[x]() {

    class inner[y](c: Member[x, ℕ] => Equal[Suc[Plus[x, y]], Plus[Suc[x], y]]) {
      val claim = c
    }

    // Here's the proof.
    def lemma3[y]():
    Member[y, ℕ] => Member[x, ℕ] => Equal[Suc[Plus[x, y]], Plus[Suc[x], y]] = {

      // This is the construction of the base case for the inductive argument.
      val step1 = (xN: Member[x, ℕ]) => {

        // We need to use lemma 1 twice in the base case.
        val lem1x = lemma1[x]()(xN).reverse()
        val lem1sx = lemma1[Suc[x]]()(suc(xN).isNatural).reverse()

        // This says that s(x + 0) = s(x) + 0
        suc(reflexive[Plus[Zero, x]]().transformLeft(lem1x))
          .transformRight(plusInductive()).transformRight(lem1sx)

      }

      val baseCase = new this.inner[Zero](step1)

      // Now we do the induction case!
      val inductionCase = (l3: this.inner[y]) => {
        val step1: (Member[x, ℕ] => Equal[Suc[Plus[x, Suc[y]]], Plus[Suc[x], Suc[y]]]) =
          (xN: Member[x, ℕ]) => {
            val hypothesis: Equal[Suc[Plus[x, y]], Plus[Suc[x], y]] = l3.claim(xN)

            suc(hypothesis.transformLeft(plusInductive()))
              .transformRight(plusInductive())
          }

        new this.inner[Suc[y]](step1)
      }

      (mem: Member[y, ℕ]) => {
        induction(baseCase, inductionCase)(mem).claim
      }
    }
  }

  // Finally we prove that x + y = y + x by inducting over y.
  class CommutativePlus[x]() {

    class inner[y](c : Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]]) {
      val claim : Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]] = c
    }

    def commutativePlus[y]() :
      Member[y, ℕ] => Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]] = {

      (yN: Member[y, ℕ]) => {

        val baseCase = new inner[Zero](lemma1[x]())

        val inductionCase : (inner[y] => inner[Suc[y]]) = (comm: inner[y]) => {
          val step1 : (Member[x, ℕ] => Equal[Plus[x, Suc[y]], Plus[Suc[y], x]]) =
            (xN : Member[x, ℕ]) => {

            val lem3 : Equal[Suc[Plus[y, x]], Plus[Suc[y], x]] =
              new Lemma3[y].lemma3[x]()(xN)(yN)

            suc(comm.claim(xN)).transformLeft(plusInductive()).transformRight(lem3)
          }

          new inner[Suc[y]](step1)
        }

        induction(baseCase, inductionCase)(yN).claim
      }
    }
  }

}