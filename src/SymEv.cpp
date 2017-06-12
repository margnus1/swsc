/* Copyright (C) 2017 Magnus Lång
 *
 * This file is part of Nidhugg.
 *
 * Nidhugg is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Nidhugg is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "SymEv.h"
#include "Debug.h"

#include <sstream>

void SymEv::set(SymEv other) {
  // if (kind != EMPTY) {
    if(kind != other.kind) {
      llvm::dbgs() << "Merging incompatible events " << *this << " and "
                   << other << "\n";
      assert(false);
    }
#ifndef NDEBUG
    switch(kind) {
    case LOAD: case STORE:
    case M_INIT: case M_LOCK: case M_UNLOCK: case M_DELETE:
    case C_INIT: case C_SIGNAL: case C_BRDCST: case C_DELETE:
      /* Without stable symbolic addresses, this is all we can check, I think */
      // assert(arg.addr.size == other.arg.addr.size);
      if(arg.addr.size != other.arg.addr.size) {
        llvm::dbgs() << "Merging incompatible events " << *this << " and "
                     << other << "\n";
        assert(false);
      }
      break;
    case C_WAIT:
      assert(arg.apair.first.size  == other.arg.apair.first.size
          && arg.apair.second.size == other.arg.apair.second.size);
      break;
    case FULLMEM: case NONDET:
      break;
    default:
      assert(false && "Unknown kind");
    }
#endif
  // }
  *this = other;
}

static std::string mref_to_string(ConstMRef mref) {
  std::stringstream out;
  out << "*" << std::hex << mref.ref << std::dec;
  out << "(" << mref.size << ")";
  return out.str();
}

std::string SymEv::to_string() const {
    switch(kind) {
    // case EMPTY:    return "Empty()";
    case LOAD:     return "Load("    + mref_to_string(arg.addr) + ")";
    case STORE:    return "Store("   + mref_to_string(arg.addr) + ")";
    case FULLMEM:  return "Fullmem()";

    case M_INIT:   return "MInit("   + mref_to_string(arg.addr) + ")";
    case M_LOCK:   return "MLock("   + mref_to_string(arg.addr) + ")";
    case M_UNLOCK: return "MUnlock(" + mref_to_string(arg.addr) + ")";
    case M_DELETE: return "MDelete(" + mref_to_string(arg.addr) + ")";

    case C_INIT:   return "CInit("   + mref_to_string(arg.addr) + ")";
    case C_SIGNAL: return "CSignal(" + mref_to_string(arg.addr) + ")";
    case C_BRDCST: return "CBrdcst(" + mref_to_string(arg.addr) + ")";
    case C_WAIT:   return "CWait("   + mref_to_string(arg.apair.first)
        + "," + mref_to_string(arg.apair.second) + ")";
    case C_DELETE: return "CDelete(" + mref_to_string(arg.addr) + ")";

    default:
      abort();
    }
}

bool SymEv::has_addr() const {
  switch(kind) {
  case LOAD: case STORE:
  case M_INIT: case M_LOCK: case M_UNLOCK: case M_DELETE:
  case C_INIT: case C_SIGNAL: case C_BRDCST: case C_DELETE:
    return true;
  case C_WAIT:
  case FULLMEM: case NONDET:
    return false;
  default:
    abort();
  }
}

bool SymEv::has_apair() const {
  switch(kind) {
  case C_WAIT:
    return true;
  case LOAD: case STORE:
  case M_INIT: case M_LOCK: case M_UNLOCK: case M_DELETE:
  case C_INIT: case C_SIGNAL: case C_BRDCST: case C_DELETE:
  case FULLMEM: case NONDET:
    return false;
  default:
    abort();
  }
}
