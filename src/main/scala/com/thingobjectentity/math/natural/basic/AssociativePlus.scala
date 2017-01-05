package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural.{Plus, Suc, Zero, ℕ}
import com.thingobjectentity.math.set.Member

/**
  * A proof of the associativity of addition, in other words (x + y) + z = x + (y + z)
  *
  * Created by cosmos on 1/5/17.
  */
class AssociativePlus(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms
  val commute = new CommutePlus(N, a)

  def lemma1[x, y, z](dx : Member[x, ℕ], dy : Member[y, ℕ], dz : Member[z, ℕ]) : Equal[Suc[Plus[x, Plus[y, z]]], Plus[x, Plus[y, Suc[z]]]] = {
    val step1 : Equal[Plus[x, Suc[Plus[y, z]]], Plus[x, Plus[y, Suc[z]]]] = commute.plus(dx, N.suc(N.plus(dy, dz)), N.plus(dy, N.suc(dz)), N.plusInductive())
    val p : Equal[Plus[x, Suc[Plus[y, z]]], Suc[Plus[x, Plus[y, z]]]] = N.plusInductive().reverse()
    step1.transformLeft(p)
  }

  def lemma2[x, y, z](dx : Member[x, ℕ], dy : Member[y, ℕ], dz : Member[z, ℕ]) : Equal[Suc[Plus[x, Plus[y, z]]], Plus[x, Plus[Suc[y], z]]] = {
    N.plusInductive().transformRight(commute.plus(dx, N.suc(N.plus(dy, dz)), N.plus(N.suc(dy), dz), new commute.Lemma2().lemma2()(dz)(dy)))
  }

  // We proceed by three stages of induction.
  def prop[x, y, z](xm : Member[x, ℕ], ym : Member[y, ℕ], zm : Member[z, ℕ]): Equal[Plus[Plus[x, y], z], Plus[x, Plus[y, z]]] = {
    val om : Member[Zero, ℕ] = N.zero.isNatural
    val oom : Member[Plus[Zero, Zero], ℕ] = N.plus(om, om)

    // A base case for the entire series.
    val allZero : Equal[Plus[Plus[Zero, Zero], Zero], Plus[Zero, Plus[Zero, Zero]]] = commute.commuter(oom, om)

    class StepA[z](c : Equal[Plus[Plus[Zero, Zero], z], Plus[Zero, Plus[Zero, z]]]) {
      val claim = c
    }

    val basea : StepA[Zero] = new StepA(allZero)

    val inductivea : (StepA[z] => StepA[Suc[z]]) = (prev : StepA[z]) => {
      new StepA[Suc[z]](N.suc(prev.claim).transformRight(lemma1(om, om, zm)).transformLeft(N.plusInductive()))
    }

    val propz : Equal[Plus[Plus[Zero, Zero], z], Plus[Zero, Plus[Zero, z]]] = N.induction(basea, inductivea)(zm).claim

    class StepB[y](c : Equal[Plus[Plus[Zero, y], z], Plus[Zero, Plus[y, z]]]) {
      val claim = c
    }

    val baseb : StepB[Zero] = new StepB(propz)

    val inductiveb : (StepB[y] => StepB[Suc[y]]) = (prev : StepB[y]) => {
      val step1 : Equal[Suc[Plus[Plus[Zero, y], z]], Plus[Plus[Zero, Suc[y]], z]] = new commute.Lemma2().lemma2()(zm)(N.plus(N.zero.isNatural, ym)).transformRight(N.plus(zm, N.plusInductive()))
      val step2 : Equal[Plus[Zero, Suc[Plus[y, z]]], Plus[Zero, Plus[Suc[y], z]]] = commute.plus(N.zero.isNatural, N.suc(N.plus(ym, zm)), N.plus(N.suc(ym), zm), new commute.Lemma2().lemma2()(zm)(ym))
      val step3 : Equal[Suc[Plus[Zero, Plus[y, z]]], Plus[Zero, Plus[Suc[y], z]]] = step2.transformLeft(N.plusInductive().reverse())
      new StepB(N.suc(prev.claim).transformLeft(step1).transformRight(step3))
    }

    val propy : Equal[Plus[Plus[Zero, y], z], Plus[Zero, Plus[y, z]]] = N.induction(baseb, inductiveb)(ym).claim

    class StepC[x](c : Equal[Plus[Plus[x, y], z], Plus[x, Plus[y, z]]]) {
      val claim = c
    }

    val basec : StepC[Zero] = new StepC(propy)

    val inductivec : (StepC[x] => StepC[Suc[x]]) = (prev : StepC[x]) => {
      val step1 : Equal[Suc[Plus[x, Plus[y, z]]], Plus[Suc[x], Plus[y, z]]] = new commute.Lemma2().lemma2()(N.plus(ym, zm))(xm)
      val step2 : Equal[Plus[Suc[Plus[x, y]], z], Plus[Plus[Suc[x], y], z]] = N.plus(zm, new commute.Lemma2().lemma2()(ym)(xm))
      val step3 : Equal[Suc[Plus[Plus[x, y], z]], Plus[Plus[Suc[x], y], z]] = new commute.Lemma2().lemma2()(zm)(N.plus(xm, ym)).transformRight(step2)
      new StepC(N.suc(prev.claim).transformRight(step1).transformLeft(step3))
    }

    N.induction(basec, inductivec)(xm).claim
  }
}
