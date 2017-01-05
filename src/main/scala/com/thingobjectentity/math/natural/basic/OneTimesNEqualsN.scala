package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural.{Plus, Suc, _}
import com.thingobjectentity.math.set.Member

/**
  * Proof that 1 * n = n
  *
  * Created by cosmos on 1/4/17.
  */
class OneTimesNEqualsN(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms

  class Prop[x](c : Equal[Times[Suc[Zero], x], x]) {
    val claim : Equal[Times[Suc[Zero], x], x] = c
  }

  def prop[x]() : Member[x, ℕ] => Equal[Times[Suc[Zero], x], x] = {

    val baseCase : Prop[Zero] = new Prop(N.timesBase())

    (mem : Member[x, ℕ]) => {
      val memOne : Member[Suc[Zero], ℕ] = N.suc(N.zero.isNatural)
      val memTimesOne : Member[Times[Suc[Zero], x], ℕ] = N.times(memOne, mem)

      val plusOne : Equal[Suc[Times[Suc[Zero], x]], Plus[Suc[Zero], Times[Suc[Zero], x]]] = new OnePlusNEqualsSucN(N, a).prop()(memTimesOne)

      val commutePlus : Equal[Plus[Times[Suc[Zero], x], Suc[Zero]], Plus[Suc[Zero], Times[Suc[Zero], x]]] = new CommutePlus(N, a).commuter(memTimesOne, memOne)

      val inductionCase : Prop[x] => Prop[Suc[x]] = (l2 : Prop[x]) => {

        val step1 : Equal[Suc[Times[Suc[Zero], x]], Suc[x]] = N.suc(l2.claim)
        val step2 : Equal[Plus[Suc[Zero], Times[Suc[Zero], x]], Suc[x]] = step1.transformLeft(plusOne)
        val step3 : Equal[Plus[Suc[Zero], Times[Suc[Zero], x]], Times[Suc[Zero], Suc[x]]] = N.timesInductive().transformLeft(commutePlus)
        val step4 : Equal[Times[Suc[Zero], Suc[x]], Suc[x]] = step2.transformLeft(step3)

        new Prop[Suc[x]](step4)
      }

      N.induction(baseCase, inductionCase)(mem).claim
    }
  }
}
