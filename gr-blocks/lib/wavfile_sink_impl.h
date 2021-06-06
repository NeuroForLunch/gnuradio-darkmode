/* -*- c++ -*- */
/*
 * Copyright 2008,2009,2013 Free Software Foundation, Inc.
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

#ifndef INCLUDED_GR_WAVFILE_SINK_IMPL_H
#define INCLUDED_GR_WAVFILE_SINK_IMPL_H

#include <gnuradio/blocks/wavfile.h>
#include <gnuradio/blocks/wavfile_sink.h>
#include <sndfile.h> // for SNDFILE

namespace gr {
namespace blocks {

class wavfile_sink_impl : public wavfile_sink
{
private:
    wav_header_info d_h;
    int d_bytes_per_sample_new;
    bool d_append;

    std::vector<float> d_buffer;

    SNDFILE* d_fp;
    SNDFILE* d_new_fp;
    bool d_updated;
    boost::mutex d_mutex;

    static const int s_items_size = 8192;
    static const int s_max_channels = 24;
    
    /*!
     * \brief If any file changes have occurred, update now. This is called
     * internally by work() and thus doesn't usually need to be called by
     * hand.
     */
    void do_update();

    /*!
     * \brief Implementation of set_bits_per_sample without mutex lock.
     */
    void set_bits_per_sample_unlocked(int bits_per_sample);

    /*!
     * \brief Writes information to the WAV header which is not available
     * a-priori (chunk size etc.) and closes the file. Not thread-safe and
     * assumes d_fp is a valid file pointer, should thus only be called by
     * other methods.
     */
    void close_wav();

protected:
   virtual bool stop();

public:
    wavfile_sink_impl(const char* filename,
                      int n_channels,
                      unsigned int sample_rate,
                      wavfile_format_t format,
                      wavfile_subformat_t subformat,
                      bool append);
    virtual ~wavfile_sink_impl();

    virtual bool open(const char* filename);
    virtual void close();

    virtual void set_sample_rate(unsigned int sample_rate);
    virtual void set_bits_per_sample(int bits_per_sample);
    virtual void set_append(bool append);

    int bits_per_sample();
    unsigned int sample_rate();

    virtual int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_GR_WAVFILE_SINK_IMPL_H */
