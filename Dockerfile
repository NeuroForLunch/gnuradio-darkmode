FROM neuroforlunch/gnuradio-companion-plus:p2-source-dependencies-u20

# This performs a self check on each push on whether it successfully builds.
# Look for the ✅ in Github or the ❌ to know whether it succeeded or not.

RUN apt-get install -yq \
libsndfile1-dev \
libcairo2-dev \
python3-cairo \
python3-gi-cairo \
libcodec2-dev \
libunwind-dev \
thrift-compiler \
libthrift-c-glib-dev \
libthrift-dev \
python3-thrift \
libqt5svg5-dev \
at-spi2-core \
&& pip3 install PyYAML


# Install GNUradio
# Blacklist the rtl dongle to prevent the system from auto-using it for TV purposes
# Add the necessary exports to have GRC load correctly
RUN mkdir -p /src \
  && cd /src \
  && git clone https://github.com/NeuroForLunch/gnuradio-darkmode.git --depth 1 --branch maint-3.8-audio \
  && cd gnuradio-darkmode \
  && mkdir build \
  && cd build && cmake -DENABLE_INTERNAL_VOLK=OFF ../ \
  && make \
  && make install \
  && ldconfig \
  && cd / \
  && rm -rf /src \
  && echo "blacklist rtl2832\nblacklist rtl2830" > /etc/modprobe.d/blacklist-rtlsdr.conf \
  && echo 'export "PYTHONPATH=/usr/local/lib/python3/dist-packages:/usr/local/lib/python3.6/dist-packages:$PYTHONPATH"' >> ~/.profile \
  && echo 'export "LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH"' >> ~/.profile \
  && echo 'export "PYTHONPATH=/usr/local/lib/python3/dist-packages:/usr/local/lib/python3.6/dist-packages:$PYTHONPATH"' > /etc/profile.d/gnuradio.sh \
  && echo 'export "LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH"' >> /etc/profile.d/gnuradio.sh
