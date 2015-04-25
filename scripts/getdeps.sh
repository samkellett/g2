#!/bin/bash -e

if [ "$CXX" = "g++" ]; then
  chmod +x misc/travis/cpp/gcc_update.sh
  ./misc/travis/cpp/gcc_update.sh --version 4.9
fi

if [ "$CXX" = "clang++" ]; then
  chmod +x misc/travis/cpp/clang_update.sh
  ./misc/travis/cpp/clang_update.sh --version 3.5 --libc++
fi
