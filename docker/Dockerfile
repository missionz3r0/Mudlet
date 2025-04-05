FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

# Dependencies
RUN apt-get update && apt-get install --no-install-recommends -y \
    build-essential \
    ca-certificates \
    ccache \
    clang \
    clang-format \
    clang-tidy \
    cmake \
    flatpak-builder \
    gdb \
    git \
    libboost-all-dev \
    libboost-dev \
    libglib2.0-dev \
    libglu1-mesa-dev \
    libgstreamer1.0-dev \
    libhunspell-dev \
    liblua5.1-0-dev \
    libpcre3-dev \
    libpugixml-dev \
    libpulse-dev \
    libsecret-1-dev \
    libyajl-dev \
    libzip-dev \
    lua-filesystem \
    lua-sql-sqlite3 \
    lua-zip \
    lua5.1 \
    luarocks \
    mesa-common-dev \
    ninja-build \
    ubuntu-restricted-extras \
    wget \
    zlib1g-dev \
    # QT6
    libqt6core5compat6-dev \
    libqt6opengl6-dev \
    qmake6-bin \
    qt6-base-dev \
    qt6-multimedia-dev \
    qt6-speech-dev \
    qt6-speech-flite-plugin \
    qt6-speech-speechd-plugin \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qtkeychain-qt6-dev

RUN flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

run rm -rf /var/lib/apt/lists/*

RUN luarocks install luautf8 && \
    luarocks install lua-yajl && \
    luarocks install lrexlib-pcre

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

RUN echo 15385 > /proc/sys/user/max_user_namespaces

RUN flatpak-builder --install-deps-from=flathub --install ./build ./CI/org.mudlet.mudlet.yml

CMD ./build/mudlet.flatpak
