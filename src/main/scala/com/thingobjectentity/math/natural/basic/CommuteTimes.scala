package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural._
import com.thingobjectentity.math.set.Member

/**
  * Created by cosmos on 1/4/17.
  */
class CommuteTimes(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms

  class Lemma1[x](c : Equal[Times[Zero, x], Zero]) {
    val claim : Equal[Times[Zero, x], Zero] = c
  }

  // First proof that 0 * x = 0. We already have a proof for x * 0 = 0, but
  // we need the other way.
  def lemma1[x]() : Member[x, ℕ] => Equal[Times[Zero, x], Zero] = {

    val baseCase : Lemma1[Zero] = new Lemma1(N.timesBase[Zero]())

    val inductionCase = (l1 : Lemma1[x]) => {

      val step1 : Equal[Plus[Times[Zero, x], Zero], Zero] = l1.claim.transformLeft(N.plusBase().reverse())

      val step2 : Equal[Times[Zero, Suc[x]], Zero] =
        step1.transformLeft(N.timesInductive())

      new Lemma1[Suc[x]](step2)
    }

    (mem : Member[x, ℕ]) => {
      N.induction(baseCase, inductionCase)(mem).claim
    }
  }
}
