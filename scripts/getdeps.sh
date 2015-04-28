#!/bin/bash -e
readonly DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# Upgrade GCC
if [ "$CXX" = "g++" ]; then
  chmod +x $DIR/misc/travis/cpp/gcc_update.sh
  $DIR/misc/travis/cpp/gcc_update.sh --version 4.9
fi

# Upgrade Clang
if [ "$CXX" = "clang++" ]; then
  chmod +x $DIR/misc/travis/cpp/clang_update.sh
  $DIR/misc/travis/cpp/clang_update.sh --version 3.5 --libc++
fi

# Make directory for libs to live in.
mkdir -p ~/opt
sudo mkdir -p /usr/local/include

# Get Meta
git clone https://github.com/ericniebler/meta.git ~/opt/meta
sudo ln -s ~/opt/meta/include /usr/local/meta
