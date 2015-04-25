#!/bin/bash

if [ "$CXX" = "g++" ]; then
  chmod +x misc/gcc_update.sh
  ./misc/gcc_update.sh --version 4.9
fi

if [ "$CXX" = "clang++" ]; then
  chmod +x misc/clang_update.sh
  ./misc/clang_update.sh --version 3.5 --libc++
fi
