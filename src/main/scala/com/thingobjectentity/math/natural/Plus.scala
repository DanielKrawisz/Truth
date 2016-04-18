package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member

/**
  * Created by cosmos on 4/15/16.
  */
trait Plus[X, Y] {

  // Proof that this is a natural number.
  val isNatural : Member[Plus[X, Y], ℕ]

  val left : X
  val right : Y
}
