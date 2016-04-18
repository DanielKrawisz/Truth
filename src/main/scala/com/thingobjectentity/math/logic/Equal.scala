package com.thingobjectentity.math.logic

/**
  * Created by cosmos on 4/15/16.
  */
trait Equal[X, Y] {

  def right : (X => Y)
  def left : (Y => X)

  def reverse() : Equal[Y, X]

  def transformLeft[Z](xz : Equal[X, Z]) : Equal[Z, Y]
  def transformRight[Z](yz : Equal[Y, Z]) : Equal[X, Z]
}
