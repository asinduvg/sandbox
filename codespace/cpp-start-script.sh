#!/bin/bash

#install gTest
sudo apt-get install libgtest-dev -y
sudo apt-get install cmake -y
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp ./lib/libgtest*.a /usr/lib
echo "Google Test successfully configured.."