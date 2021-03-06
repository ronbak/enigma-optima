#include "global.h"
#include "key.h"

/* initialize key to defaults */
int init_key_default( Key *key, enum ModelType_t model )
{
    Key def_H  = {{{0}}, {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1, EnigmaModel_H, {0}, 0, 0};
    Key def_M3 = {{{0}}, {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1, EnigmaModel_M3, {0}, 0, 0};
    Key def_M4 = {{{0}}, {9, 1, 2, 3}, {0, 0, 0, 0}, {0, 0, 0, 0}, 3, EnigmaModel_M4, {0}, 0, 0};
    switch( model ) {
    case EnigmaModel_H :
        *key = def_H;
        break;
    case EnigmaModel_M3:
        *key = def_M3;
        break;
    case EnigmaModel_M4:
        *key = def_M4;
        break;
    default:
        return 0;
    }
    Fill0To25(key->stbrett.letters);
    Fill0To25(key->sf);
    return 1;
}

/* initializes each key element to the lowest possible value */
int init_key_low( Key *key, enum ModelType_t model )
{
    Key low_H  = {{{0}}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0, EnigmaModel_H, {0}, 0, 0};
    Key low_M3 = {{{0}}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, 1, EnigmaModel_M3, {0}, 0, 0};
    Key low_M4 = {{{0}}, {9, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, 3, EnigmaModel_M4, {0}, 0, 0};
    switch( model ) {
    case EnigmaModel_H :
        *key = low_H;
        break;
    case EnigmaModel_M3:
        *key = low_M3;
        break;
    case EnigmaModel_M4:
        *key = low_M4;
        break;
    default:
        return 0;
    }
    Fill0To25(key->stbrett.letters);
    Fill0To25(key->sf);
    return 1;
}

/* compares ukwnum thru r_mesg, omits g_ring, l_ring        */
/* returns -1 for k1 < k2, 0 for k1 == k2, 1 for k1 > k2    */
int keycmp(const Key *k1, const Key *k2)
{
  if (  k1->ukwnum != k2->ukwnum ) {
    if ( k1->ukwnum > k2->ukwnum ) return 1;
    else return -1;
  }
  if (  k1->slot.g != k2->slot.g ) {
    if ( k1->slot.g > k2->slot.g ) return 1;
    else return -1;
  }
  if (  k1->slot.l != k2->slot.l ) {
    if ( k1->slot.l > k2->slot.l ) return 1;
    else return -1;
  }
  if (  k1->slot.m != k2->slot.m ) {
    if ( k1->slot.m > k2->slot.m ) return 1;
    else return -1;
  }
  if (  k1->slot.r != k2->slot.r ) {
    if ( k1->slot.r > k2->slot.r ) return 1;
    else return -1;
  }
  if (  k1->ring.m != k2->ring.m ) {
    if ( k1->ring.m > k2->ring.m ) return 1;
    else return -1;
  }
  if (  k1->ring.r != k2->ring.r ) {
    if ( k1->ring.r > k2->ring.r ) return 1;
    else return -1;
  }
  if (  k1->mesg.g != k2->mesg.g ) {
    if ( k1->mesg.g > k2->mesg.g ) return 1;
    else return -1;
  }
  if (  k1->mesg.l != k2->mesg.l ) {
    if ( k1->mesg.l > k2->mesg.l ) return 1;
    else return -1;
  }
  if (  k1->mesg.m != k2->mesg.m ) {
    if ( k1->mesg.m > k2->mesg.m ) return 1;
    else return -1;
  }
  if (  k1->mesg.r != k2->mesg.r ) {
    if ( k1->mesg.r > k2->mesg.r ) return 1;
    else return -1;
  }
  return 0;

}

extern
void FixPermutationMapTail(PermutationMap_t* mapping);

extern
void Fill0To25(text_t array[static 26]);

/*
 * This file is part of enigma-suite-0.76, which is distributed under the terms
 * of the General Public License (GPL), version 2. See doc/COPYING for details.
 *
 * Copyright (C) 2005 Stefan Krah
 *
 */
