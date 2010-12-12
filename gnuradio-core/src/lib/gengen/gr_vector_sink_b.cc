/* -*- c++ -*- */
/*
 * Copyright 2004,2008 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

// WARNING: this file is machine generated.  Edits will be over written

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gr_vector_sink_b.h>
#include <algorithm>
#include <gr_io_signature.h>


gr_vector_sink_b::gr_vector_sink_b (int vlen)
  : gr_sync_block ("vector_sink_b",
		   gr_make_io_signature (1, 1, sizeof (unsigned char) * vlen),
		   gr_make_io_signature (0, 0, 0)),
    d_vlen(vlen)
{
}

int
gr_vector_sink_b::work (int noutput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items)
{
  unsigned char *iptr = (unsigned char *) input_items[0];
  for (int i = 0; i < noutput_items * d_vlen; i++)
    d_data.push_back (iptr[i]);

  return noutput_items;
}


gr_vector_sink_b_sptr
gr_make_vector_sink_b (int vlen)
{
  return gr_vector_sink_b_sptr (new gr_vector_sink_b (vlen));
}

std::vector<unsigned char>
gr_vector_sink_b::data () const
{
  return d_data;
}