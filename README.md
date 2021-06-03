<p align="center">
<img src="https://github.com/NeuroForLunch/gnuradio-darkmode/raw/maint-3.8/docs/gnuradio.png" width="75%" />
</p>

GNU Radio is a free & open-source software development toolkit that
provides signal processing blocks to implement software radios. It can
be used with readily-available, low-cost external RF hardware to create
software-defined radios, or without hardware in a simulation-like
environment. It is widely used in hobbyist, academic, and commercial
environments to support both wireless communications research and real-world
radio systems.

Please visit the GNU Radio website at https://www.gnuradio.org/ and the
wiki at https://wiki.gnuradio.org/. Bugs and feature requests are
tracked on GitHub's [Issue Tracker](https://github.com/gnuradio/gnuradio/issues).
If you have questions about GNU Radio, please search the **discuss-gnuradio**
mailing list [archive](https://lists.gnu.org/archive/html/discuss-gnuradio/),
as many questions have already been asked and answered. Please also
[subscribe](https://lists.gnu.org/mailman/listinfo/discuss-gnuradio) to
the mailing list and post your new questions there.

<p align="center">
<img src="https://github.com/NeuroForLunch/gnuradio-darkmode/raw/maint-3.8/docs/darkmode-1.png" width="100%" />
</p>

## How to Install GNU Radio


```bash
$ sudo su
$ mkdir -p /src \
    && cd /src \
    && git clone https://github.com/NeuroForLunch/gnuradio-darkmode.git --depth 1 --branch maint-3.8 \
    && cd gnuradio-darkmode \
    && mkdir build \
    && cd build && cmake -DENABLE_INTERNAL_VOLK=OFF ../ \
    && make \
    && make install \
    && ldconfig \
    && cd / \
    && rm -rf /src \
    && exit
```

## Legal Matters

Some files have been changed many times throughout the years. Copyright
notices at the top of source files list which years changes have been
made. For some files, changes have occurred in many consecutive years.
These files may often have the format of a year range (e.g., "2006 - 2021"),
which indicates that these files have had copyrightable changes made
during each year in the range, inclusive.
