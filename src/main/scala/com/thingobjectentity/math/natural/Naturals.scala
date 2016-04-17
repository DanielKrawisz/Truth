package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member
import com.thingobjectentity.math.logic.Equals

/**
  * Created by cosmos on 4/15/16.
  */
trait Naturals {
  val zero : Zero

  def suc[x](num : x) : Suc[x]
  def suc[x, y](xy : Equals[x, y]) : Equals[Suc[x], Suc[y]]
  def prev[x, y](xy : Equals[Suc[x], Suc[y]]) : Equals[x, y]

  def plusBase[x]() : Equals[x, Plus[x, Zero]]
  def plusInductive[x, y]() : Equals[Plus[x, Suc[y]], Suc[Plus[x, y]]]

  def plus[x, y, z](num : x, yz : Equals[y, z]) : Equals[Plus[y, x], Plus[z, x]]
  def minus[x, y, z](yz : Equals[Plus[y, x], Plus[z, x]]) : Equals[y, z]

  def timesBase[x]() : Equals[Zero, Times[Zero, x]]
  def timesInductive[x, y]() : Equals[Times[x, Suc[y]], Plus[Times[x, y], y]]

  def times[x, y, z](num : x, yz : Equals[y, z]) : Equals[Times[y, x], Times[z, x]]
  def divide[x, y, z](yz : Equals[Times[y, x], Times[z, x]]) : Equals[y, z]

  def contradiction[x] (cont : Equals[x, Suc[x]]) : Nothing

}
