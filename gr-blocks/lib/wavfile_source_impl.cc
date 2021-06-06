/* -*- c++ -*- */
/*
 * Copyright 2004,2008,2010,2013 Free Software Foundation, Inc.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "wavfile_source_impl.h"
#include <gnuradio/io_signature.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdexcept>

namespace gr {
namespace blocks {

wavfile_source::sptr wavfile_source::make(const char* filename, bool repeat)
{
    return gnuradio::get_initial_sptr(new wavfile_source_impl(filename, repeat));
}

wavfile_source_impl::wavfile_source_impl(const char* filename, bool repeat)
    : sync_block("wavfile_source",
                 io_signature::make(0, 0, 0),
                 io_signature::make(1, 2, sizeof(float))),
      d_fp(NULL),
      d_repeat(repeat),
      d_h{}, // Init with zeros
      d_sample_idx(0)
{
    SF_INFO sfinfo;

    sfinfo.format = 0;
    if (!(d_fp = sf_open(filename, SFM_READ, &sfinfo))) {
        perror(filename);
        throw std::runtime_error("Can't open WAV file.");
    }

    d_h.sample_rate = (unsigned)sfinfo.samplerate;
    d_h.nchans = sfinfo.channels;
    if (sfinfo.channels > s_max_channels) {
        throw std::runtime_error("Too many channels");
    }

    switch (sfinfo.format & SF_FORMAT_SUBMASK) {
    case SF_FORMAT_PCM_S8:
        d_h.bytes_per_sample = 1;
        break;
    case SF_FORMAT_PCM_16:
        d_h.bytes_per_sample = 2;
        break;
    case SF_FORMAT_PCM_24:
        d_h.bytes_per_sample = 3;
        break;
    case SF_FORMAT_PCM_32:
        d_h.bytes_per_sample = 4;
        break;
    case SF_FORMAT_PCM_U8:
        d_h.bytes_per_sample = 1;
        break;
    case SF_FORMAT_FLOAT:
        d_h.bytes_per_sample = 4;
        break;
    case SF_FORMAT_DOUBLE:
        d_h.bytes_per_sample = 8;
        break;
    }
    d_h.samples_per_chan = sfinfo.frames;

    if (d_h.samples_per_chan == 0) {
        throw std::runtime_error("WAV file does not contain any samples.");
    }

    set_output_multiple(s_items_size);
    d_buffer.resize(s_items_size * d_h.nchans);

    // Re-set the output signature
    set_output_signature(io_signature::make(1, d_h.nchans, sizeof(float)));
}

wavfile_source_impl::~wavfile_source_impl() { sf_close(d_fp); }

int wavfile_source_impl::work(int noutput_items,
                              gr_vector_const_void_star& input_items,
                              gr_vector_void_star& output_items)
{
    float** out = (float**)&output_items[0];
    int n_out_chans = output_items.size();
    int items = 0;
    int produced = 0;
    int errnum;
    sf_count_t samples;

    for (int i = 0; i < noutput_items; i += s_items_size) {
        if (d_sample_idx >= d_h.samples_per_chan) {
            if (!d_repeat) {
                // if nothing was read at all, say we're done.
                return items ? produced : -1;
            }

            if (sf_seek(d_fp, 0, SEEK_SET) == -1) {
                fprintf(stderr, "[%s] fseek failed\n", __FILE__);
                exit(-1);
            }

            d_sample_idx = 0;
        }

        samples = sf_read_float(d_fp, &d_buffer[0], d_h.nchans * s_items_size);
        items = (int)samples / d_h.nchans;
        for (int n = 0; n < items; n++) {
            for (int chan = 0; chan < d_h.nchans; chan++) {
                if (chan < n_out_chans) {
                    out[chan][n + produced] = d_buffer[chan + (n * d_h.nchans)];
                }
            }
        }

        produced += items;
        d_sample_idx += items;


// Could be a problem area with errnum and sf_error not being defined
        errnum = sf_error(d_fp);
        if (errnum) {
            if (items == 0) {
                fprintf(stderr,
                        "[%s] WAV file has corrupted header or i/o error\n",
                        __FILE__);
                return -1;
            }
            return produced;
        }
    }

    return produced;
}

} /* namespace blocks */
} /* namespace gr */
