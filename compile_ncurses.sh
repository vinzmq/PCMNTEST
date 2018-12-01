#!/bin/sh
cd ncurses-5.7
./configure --prefix=/opt/ncurses
make
sudo make install
