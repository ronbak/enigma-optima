#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ciphertext.h"
#include "global.h"
#include "key.h"
#include "stecker.h"
#include "randomNumbers.h"
#include "config/types.h"


// extern definition for external linkage.
extern void SwapStbrett(Key* const key, int i, int k);

/* extracts stecker from key->stbrett to key->sf */
void get_stecker(Key *key)
{
  int i, k = 25;

  key->count = 0;
  for (i = 0; i < 26; i++) {
    if (key->stbrett.letters[i] > i) {
      key->sf[key->count++] = i;
      key->sf[key->count++] = key->stbrett.letters[i];
    }
    else if (key->stbrett.letters[i] == i) {
      key->sf[k--] = i;
    }
  }

}

/* get new order for testing stecker */
void rand_var(text_t var[])
{
  int count;
  int store;
  int i;

  for (count = 25; count > 0; count--) {
    i = GetRandomNumber() % ( count + 1 );
    store = var[count];
    var[count] = var[i];
    var[i] = store;
  }

}

/* arrange var[] in order of frequency of letters in ciphertext */
void set_to_ct_freq(text_t var[], int len)
{
  int f[26] = {0};
  int i, k, c;
  int max, pos = -1;
  int n = 0;

  for (i = 0; i < len; i++) {
    c = ciphertext.plain[i];
    f[c]++;
  }

  for (i = 0; i < 26; i++) {
    max = 0;
    for (k = 0; k < 26; k++)
      if (f[k] >= max) {
        max = f[k];
        pos = k;
      }
    if (pos == -1)
      return;
    f[pos] = -1;
    var[n++] = pos;
  }

}


/*
 * This file is part of enigma-suite-0.76, which is distributed under the terms
 * of the General Public License (GPL), version 2. See doc/COPYING for details.
 *
 * Copyright (C) 2005 Stefan Krah
 *
 */
