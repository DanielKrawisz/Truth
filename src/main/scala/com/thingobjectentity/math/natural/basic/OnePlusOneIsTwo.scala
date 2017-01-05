package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural.{Plus, Suc, Zero, ℕ}

/**
  * Proof that 1 + 1 = 2
  *
  * My first proof in scala! You can read the proof by
  * looking at the types of the values. If you change
  * the proof, the ide tells you you're wrong!
  *
  * Created by cosmos on 4/18/16.
  */
class OnePlusOneIsTwo(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms

  def prop() : Equal[Plus[Suc[Zero], Suc[Zero]], Suc[Suc[Zero]]] = {

    val step1 : Equal[Suc[Zero], Suc[Zero]] = N.suc(a.reflexive())

    val plusZero : Equal[Suc[Zero], Plus[Suc[Zero], Zero]] = N.plusBase().reverse()

    val step2 : Equal[Suc[Plus[Suc[Zero], Zero]], Suc[Suc[Zero]]] =
      N.suc(step1.transformLeft(plusZero))

    val one : Suc[Zero] = N.suc(N.zero.isNatural, N.zero)

    val step3 : Equal[Plus[Suc[Zero], Suc[Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      N.plus(one.isNatural, step1)

    val step4 : Equal[Suc[Plus[Suc[Zero], Zero]], Plus[Suc[Zero], Suc[Zero]]] =
      step3.transformLeft(N.plusInductive().reverse())

    a.transitive(step4.reverse(), step2)
  }
}
