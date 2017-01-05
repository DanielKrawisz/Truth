package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural.{Plus, Suc, Zero, ℕ}
import com.thingobjectentity.math.set.Member

/**
  * Proof that the successor of n is 1 + n.
  *
  * We use this to prove that multiplication is commutative.
  *
  * Created by cosmos on 1/4/17.
  */
class OnePlusNEqualsSucN(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms

  // The proof proceeds by induction.
  class Prop[x](c : Equal[Suc[x], Plus[Suc[Zero], x]]) {
    val claim : Equal[Suc[x], Plus[Suc[Zero], x]] = c
  }

  def prop[x]() : Member[x, ℕ] => Equal[Suc[x], Plus[Suc[Zero], x]] = {

    val step1 : Equal[Suc[Zero], Plus[Suc[Zero], Zero]] =
      N.plus(N.zero.isNatural, a.reflexive[Suc[Zero]]()).transformLeft(N.plusBase())

    val baseCase : Prop[Zero] = new Prop(step1)

    val inductionCase = (l2 : Prop[x]) => {

      val step1 : Equal[Suc[Suc[x]], Plus[Suc[Zero], Suc[x]]] =
        N.suc(l2.claim).transformRight(N.plusInductive())

      new Prop[Suc[x]](step1)
    }

    (mem : Member[x, ℕ]) => {
      N.induction(baseCase, inductionCase)(mem).claim
    }
  }
}
