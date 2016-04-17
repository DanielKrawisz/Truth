package com.thingobjectentity.math.natural

import com.thingobjectentity.math.logic.Equals
import com.thingobjectentity.math.logic.Axioms

/**
  * Basic proofs in number theory.
  *
  * Created by cosmos on 4/16/16.
  */
trait Basic extends Naturals with Axioms {


  // Proof that 1 + 1 == 2
  def lemma1() : Equals[Plus[Suc[Zero], Suc[Zero]], Suc[Suc[Zero]]] = {

    val step1 : Equals[Suc[Zero], Suc[Zero]] = suc(reflexive())

    val plusZero : Equals[Suc[Zero], Plus[Suc[Zero], Zero]] = plusBase()

    val step2 : Equals[Suc[Plus[Suc[Zero], Zero]], Suc[Suc[Zero]]] =
      suc(step1.transformLeft(plusZero))

    val step3 : Equals[Plus[Suc[Zero], Suc[Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      plus(suc(zero), step1)

    val step4 : Equals[Suc[Plus[Suc[Zero], Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      step3.transformLeft(plusInductive())

    transitive(step4.reverse(), step2)
  }
}
