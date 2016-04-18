package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member
import com.thingobjectentity.math.logic.Equals

/**
  * Axioms of number theory and of plus, multiply, and power.
  *
  * Created by cosmos on 4/15/16.
  */
trait Naturals {
  val zero : Zero

  def suc[x](num : x, dom : Member[x, Naturals]) : Suc[x]
  def suc[x, y](xy : Equals[x, y]) : Equals[Suc[x], Suc[y]]
  def prev[x, y](xy : Equals[Suc[x], Suc[y]]) : Equals[x, y]

  def plusBase[x]() : Equals[x, Plus[x, Zero]]
  def plusInductive[x, y]() : Equals[Plus[x, Suc[y]], Suc[Plus[x, y]]]

  def plus[x, y, z](num : x, dom : Member[x, Naturals], yz : Equals[y, z])
    : Equals[Plus[y, x], Plus[z, x]]

  def timesBase[x]() : Equals[Zero, Times[Zero, x]]
  def timesInductive[x, y]() : Equals[Times[x, Suc[y]], Plus[Times[x, y], y]]

  def times[x, y, z](num : x, dom : Member[x, Naturals], yz : Equals[y, z])
    : Equals[Times[y, x], Times[z, x]]

  def powBase[x]() : Equals[Suc[Zero], Pow[x, Zero]]
  def powInductive[x, y]() : Equals[Pow[x, Suc[y]], Times[Pow[x, y], y]]

  def pow[x, y, z](num : x, dom : Member[x, Naturals], yz : Equals[y, z])
    : Equals[Pow[y, x], Pow[z, x]]

  def contradiction[x] (cont : Equals[x, Suc[x]]) : Nothing

  def induction[x, F[_]] (base : F[Zero], inductive : F[x] => F[Suc[x]])
    : Member[x, Naturals] => F[x]
}
