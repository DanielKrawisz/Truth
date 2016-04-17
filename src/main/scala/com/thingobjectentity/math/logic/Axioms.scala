package com.thingobjectentity.math.logic

/**
  * All the logic axioms I need for number theory proofs.
  *
  * Created by cosmos on 4/17/16.
  */
trait Axioms {
  def reflexive[x]() : Equals[x, x]

  def transitive[x, y, z]
    (xy : Equals[x, y], yz : Equals[y, z]) : Equals[x, z]
}
