/* spectrum.h */
/*
This file is part of a program that implements a Software-Defined Radio.

Copyright (C) 2004, 2005, 2006, 2007, 2008 by Frank Brickle, AB2KT and Bob McGwier, N4HY

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

The authors can be reached by email at

ab2kt@arrl.net
or
rwmcgwier@gmail.com

or by paper mail at

The DTTS Microwave Society
6 Kathleen Place
Bridgewater, NJ 08807
*/

#ifndef _spectrum_h
#define _spectrum_h

#include <fromsys.h>
#include <defs.h>
#include <banal.h>
#include <splitfields.h>
#include <datatypes.h>
#include <bufvec.h>
#include <cxops.h>
#include <ringb.h>
#include <lmadf.h>
#include <fftw3.h>
#include <window.h>

#define SPEC_MAG	(0)
#define SPEC_PWR	(1)
#define SPEC_SEMI_RAW	(0)
#define SPEC_PRE_FILT	(1)
#define SPEC_POST_FILT	(2)
#define SPEC_POST_AGC	(3)
#define SPEC_POST_DET	(4)
#define SPEC_PREMOD	(4)
#define SPEC_LAST_TIME	(0)
#define SPEC_LAST_FREQ	(1)  


typedef
struct _spec_block {
  BOOLEAN flag, polyphase;
  Windowtype wintype;
  int buflen,
      fill,
      label,
      last,
      mask,
      planbits,
      rxk,
      scale,
      size,
      stamp,
      type;
  CXB accum, timebuf, freqbuf;
  REAL *output, *oscope, *window;
  fftwf_plan plan;
} SpecBlock;

extern void init_spectrum(SpecBlock *sb);
extern void reinit_spectrum(SpecBlock *sb);
extern void snap_spectrum(SpecBlock *sb, int label, int stamp);
extern void snap_scope(SpecBlock *sb, int label, int stamp);
extern void compute_spectrum(SpecBlock *sb);
extern void finish_spectrum(SpecBlock *sb);

#endif
