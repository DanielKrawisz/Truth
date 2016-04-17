package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member

/**
  * Created by cosmos on 4/15/16.
  */
trait Times[X, Y] {

  val isNatural : Member[Plus[X, Y], Naturals]
}
