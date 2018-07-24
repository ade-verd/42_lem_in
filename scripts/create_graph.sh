#!/bin/sh
if [ $# -ne 2 ]
then
	read -p "Please indicate path of graph.DOT: " DOTFILE
	read -p "Please indicate path of output.PNG: " PNGFILE
else
	DOTFILE=$1;
	PNGFILE=$2;
fi

mkdir -p .graph
dot -Tpng $DOTFILE -o $PNGFILE

OS=`uname`
if [ "$OS" == Darwin ]
	then
	open $PNGFILE
elif [ "$OS" == Linux ]
	then
	eog $PNGFILE
#	feh $PNGFILE
#	xdg-open $PNGFILE
fi