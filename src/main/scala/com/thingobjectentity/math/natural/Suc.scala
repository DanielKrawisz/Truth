package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member

/**
  * Created by cosmos on 4/15/16.
  */
trait Suc[x] {

  // Proof that this expression represents a natural number.
  val isNatural : Member[Suc[x], Naturals]

  // The previous number.
  val previous : x
}
