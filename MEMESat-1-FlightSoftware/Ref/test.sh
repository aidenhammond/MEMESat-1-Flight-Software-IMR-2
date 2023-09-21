#!/bin/bash
curdur=$(pwd)
fayle="$curdur/build-fprime-automatic-native/Ref/FileRecycler/FileRecyclerComponentAi.xml"
sed -i 's/""/"/g' $fayle
