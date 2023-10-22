#!/bin/sh
echo $FT_NBR1 | sed -e s/\'/0/g -e s/'\\'/1/g -e s/\"/2/g -e s/\?/3/g -e s/\!/4/g -e s/$/' '/ -e "s/$/""$FT_NBR2"/ -e s/m/0/g -e s/r/1/g -e s/d/2/g -e s/o/3/g -e s/c/4/g | awk '{print "ibase=5;obase=23; "$1 "+" $2;}' | bc | tr '0123456789ABC' 'gtaio luSnemf'
