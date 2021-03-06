package com.thingobjectentity.math.natural.basic

import com.thingobjectentity.math.logic.{Axioms, Equal}
import com.thingobjectentity.math.natural.{Plus, Suc, _}
import com.thingobjectentity.math.set.Member

/**
  * Proof the addition commutes! That is, x + y = y + x
  *
  * Created by cosmos on 4/18/16.
  */
class CommutePlus(naturals : ℕ, axioms : Axioms) {
  val N = naturals
  val a = axioms

  // We have to define a new type every time we make an inductive argument.
  class Lemma1[x](c : Equal[Plus[x, Zero], Plus[Zero, x]]) {
    val claim : Equal[Plus[x, Zero], Plus[Zero, x]] = c
  }

  // First proof using mathematical induction! It says that 0 + x = x + 0
  def lemma1[x]() : Member[x, ℕ] => Equal[Plus[x, Zero], Plus[Zero, x]] = {

    val baseCase : Lemma1[Zero] = new Lemma1(a.reflexive())

    val inductionCase = (l1 : Lemma1[x]) => {

      val step1 : Equal[Suc[x], Suc[Plus[Zero, x]]] =
        N.suc(l1.claim.transformLeft(N.plusBase()))

      val step2 : Equal[Plus[Suc[x], Zero], Plus[Zero, Suc[x]]] =
        step1.transformLeft(N.plusBase().reverse()).transformRight(N.plusInductive())

      new Lemma1[Suc[x]](step2)
    }

    (mem : Member[x, ℕ]) => {
      N.induction(baseCase, inductionCase)(mem).claim
    }
  }

  // Next we prove by induction over y that that Suc(x + y) = Suc(x) + y
  // We have an axiom that says Suc(x + y) = x + Suc(y) but we need to go the other way.
  class Lemma2[x]() {

    class inner[y](c: Member[x, ℕ] => Equal[Suc[Plus[x, y]], Plus[Suc[x], y]]) {
      val claim = c
    }

    // Here's the proof.
    def lemma2[y]():
    Member[y, ℕ] => Member[x, ℕ] => Equal[Suc[Plus[x, y]], Plus[Suc[x], y]] = {

      // This is the construction of the base case for the inductive argument.
      val step1 = (xN: Member[x, ℕ]) => {

        // We need to use lemma 1 twice in the base case.
        val lem1x = lemma1[x]()(xN).reverse()
        val lem1sx = lemma1[Suc[x]]()(N.suc(xN)).reverse()

        // This says that s(x + 0) = s(x) + 0
        N.suc(a.reflexive[Plus[Zero, x]]().transformLeft(lem1x))
          .transformRight(N.plusInductive()).transformRight(lem1sx)

      }

      val baseCase = new this.inner[Zero](step1)

      // Now we do the induction case!
      val inductionCase = (l3: this.inner[y]) => {
        val step1: (Member[x, ℕ] => Equal[Suc[Plus[x, Suc[y]]], Plus[Suc[x], Suc[y]]]) =
          (xN: Member[x, ℕ]) => {
            val hypothesis: Equal[Suc[Plus[x, y]], Plus[Suc[x], y]] = l3.claim(xN)

            N.suc(hypothesis.transformLeft(N.plusInductive()))
              .transformRight(N.plusInductive())
          }

        new this.inner[Suc[y]](step1)
      }

      (mem: Member[y, ℕ]) => {
        N.induction(baseCase, inductionCase)(mem).claim
      }
    }
  }

  // Finally we prove that x + y = y + x by inducting over y.
  class CommutativePlus[x]() {

    class inner[y](c : Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]]) {
      val claim : Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]] = c
    }

    def commutativePlus[y]() :
    Member[y, ℕ] => Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]] = {

      (yN: Member[y, ℕ]) => {

        val baseCase = new inner[Zero](lemma1[x]())

        val inductionCase : (inner[y] => inner[Suc[y]]) = (comm: inner[y]) => {
          val step1 : (Member[x, ℕ] => Equal[Plus[x, Suc[y]], Plus[Suc[y], x]]) =
            (xN : Member[x, ℕ]) => {

              val lem3 : Equal[Suc[Plus[y, x]], Plus[Suc[y], x]] =
                new Lemma2[y].lemma2[x]()(xN)(yN)

              N.suc(comm.claim(xN)).transformLeft(N.plusInductive()).transformRight(lem3)
            }

          new inner[Suc[y]](step1)
        }

        N.induction(baseCase, inductionCase)(yN).claim
      }
    }
  }

  def prop[x, y]() : Member[y, ℕ] => Member[x, ℕ] => Equal[Plus[x, y], Plus[y, x]] = {
    new CommutativePlus().commutativePlus()
  }

  def commuter[x, y](dx : Member[x, ℕ], dy : Member[y, ℕ]) : Equal[Plus[x, y], Plus[y, x]] = {
    prop[x, y]()(dy)(dx)
  }

  def plus[x, y, z](dx : Member[x, ℕ], dy : Member[y, ℕ], dz : Member[z, ℕ], yz : Equal[y, z]) : Equal[Plus[x, y], Plus[x, z]] = {
    val cl : Equal[Plus[y, x], Plus[x, y]] = commuter(dy, dx)
    val cr : Equal[Plus[z, x], Plus[x, z]] = commuter(dz, dx)

    N.plus(dx, yz).transformLeft(cl).transformRight(cr)
  }
}
