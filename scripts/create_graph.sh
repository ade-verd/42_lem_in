#!/bin/sh
if [ $# -ne 2 ]
then
	read -p "Please indicate path of graph.DOT: " DOTFILE
	read -p "Please indicate path of output: " OUTPUT
else
	DOTFILE=$1;
	OUTPUT=$2;
fi

mkdir -p .graph
dot -Tpng $DOTFILE -o $OUTPUT.png
dot -Tsvg $DOTFILE -o $OUTPUT.svg

OS=`uname`
if [ "$OS" == Darwin ]
	then
	open $OUTPUT.png
elif [ "$OS" == Linux ]
	then
	eog $OUTPUT.png
#	feh $OUTPUT.png
#	xdg-open $OUTPUT.png
fi