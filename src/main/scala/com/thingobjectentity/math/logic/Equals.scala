package com.thingobjectentity.math.logic

/**
  * Created by cosmos on 4/15/16.
  */
trait Equals[X, Y] {

  def right : (X => Y)
  def left : (Y => X)

  def reverse() : Equals[Y, X]

  def transformLeft[Z](xz : Equals[X, Z]) : Equals[Z, Y]
  def transformRight[Z](yz : Equals[Y, Z]) : Equals[X, Z]
}
