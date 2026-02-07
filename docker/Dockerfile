FROM ubuntu:25.04

ARG DEBIAN_FRONTEND=noninteractive

# Dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    ca-certificates \
    ccache \
    clang \
    cmake \
    git \
    libassimp-dev \
    libboost-dev \
    libcurl4-openssl-dev \
    libglu1-mesa-dev \
    libhunspell-dev \
    liblua5.1-0-dev \
    libpcre2-dev \
    libpugixml-dev \
    libpulse-dev \
    libqt6core5compat6-dev \
    libqt6opengl6-dev \
    libsecret-1-dev \
    libssl-dev \
    libxkbcommon-dev \
    libyajl-dev \
    libzip-dev \
    libzstd-dev \
    lua-filesystem \
    lua-rex-pcre2 \
    lua-sql-sqlite3 \
    lua-zip \
    luarocks \
    ninja-build \
    openssl \
    qt6-multimedia-dev \
    qt6-speech-dev \
    qt6-tools-dev \
    qtkeychain-qt6-dev \
    zlib1g-dev

run rm -rf /var/lib/apt/lists/*

RUN luarocks install luautf8 && \
    luarocks install lua-yajl && \
    luarocks install lrexlib-pcre2

# Without this, clang-tidy/format doesn't find the correct c++ headers
ENV CPLUS_INCLUDE_PATH="${CPLUS_INCLUDE_PATH:+${CPLUS_INCLUDE_PATH}:}/usr/lib/gcc/x86_64-linux-gnu/9/include"

RUN useradd -ms /bin/bash mudlet

RUN mkdir -p /home/mudlet/build
VOLUME /home/mudlet/build

WORKDIR /home/mudlet/
COPY --chown=mudlet:mudlet .clang-tidy CMakeLists.txt CPPLINT.cfg mudlet.desktop mudlet.png mudlet.svg ./
COPY --chown=mudlet:mudlet 3rdparty 3rdparty
COPY --chown=mudlet:mudlet CI CI
COPY --chown=mudlet:mudlet cmake cmake
COPY --chown=mudlet:mudlet src src
COPY --chown=mudlet:mudlet templates templates
COPY --chown=mudlet:mudlet test test
COPY --chown=mudlet:mudlet translations translations

CMD cd build && cmake .. -G Ninja && ninja -j 2
