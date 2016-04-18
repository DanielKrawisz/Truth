package com.thingobjectentity.math.natural

import com.thingobjectentity.math.set.Member
import com.thingobjectentity.math.logic.Equal

/**
  * Axioms of number theory and of plus, multiply, and power.
  *
  * Created by cosmos on 4/15/16.
  */
trait ℕ {
  val zero : Zero

  def suc[x](dom : Member[x, ℕ]) : Suc[x]
  def suc[x, y](xy : Equal[x, y]) : Equal[Suc[x], Suc[y]]
  def prev[x, y](xy : Equal[Suc[x], Suc[y]]) : Equal[x, y]

  def plusBase[x]() : Equal[x, Plus[x, Zero]]
  def plusInductive[x, y]() : Equal[Suc[Plus[x, y]], Plus[x, Suc[y]]]

  def plus[x, y, z](num : x, dom : Member[x, ℕ], yz : Equal[y, z])
    : Equal[Plus[y, x], Plus[z, x]]

  def timesBase[x]() : Equal[Zero, Times[Zero, x]]
  def timesInductive[x, y]() : Equal[Plus[Times[x, y], y], Times[x, Suc[y]]]

  def times[x, y, z](num : x, dom : Member[x, ℕ], yz : Equal[y, z])
    : Equal[Times[y, x], Times[z, x]]

  def powBase[x]() : Equal[Suc[Zero], Pow[x, Zero]]
  def powInductive[x, y]() : Equal[Times[Pow[x, y], y], Pow[x, Suc[y]]]

  def pow[x, y, z](num : x, dom : Member[x, ℕ], yz : Equal[y, z])
    : Equal[Pow[y, x], Pow[z, x]]

  def contradiction[x] (cont : Equal[x, Suc[x]]) : Nothing

  def induction[x, F[_]] (base : F[Zero], inductive : F[x] => F[Suc[x]])
    : Member[x, ℕ] => F[x]
}
