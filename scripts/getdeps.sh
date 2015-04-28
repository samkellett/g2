#!/bin/bash -e
readonly DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

if [ "$CXX" = "g++" ]; then
  chmod +x $DIR/misc/travis/cpp/gcc_update.sh
  $DIR/misc/travis/cpp/gcc_update.sh --version 4.9
fi

if [ "$CXX" = "clang++" ]; then
  chmod +x $DIR/misc/travis/cpp/clang_update.sh
  $DIR/misc/travis/cpp/clang_update.sh --version 3.5 --libc++
fi
