#!/bin/sh
cd ncurses-6.1
./configure --prefix=/opt/ncurses
make
sudo make install
sudo apt install libncurses5-dev libncursesw5-dev
