package com.thingobjectentity.math.logic

/**
  * Created by cosmos on 4/15/16.
  */
object Tautologies {

  def taut1[A, B, C] (f: A => (B => C)) : ((A => B) => (A => C)) = {

    (g : (A => B)) => (a : A) => f(a)(g(a))

  }
}
