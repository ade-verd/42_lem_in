OS=`uname`

LOG_CLEAR=\\033[2K
LOG_RED=\\033[1\;31m
LOG_GREEN=\\033[1\;32m
LOG_BLUE=\\033[1\;34m
LOG_VIOLET=\\033[1\;35m
LOG_NOCOLOR=\\033[0m
TITLE=$LOG_CLEAR$LOG_BLUE
SETUP=--$LOG_CLEAR$LOG_GREEN✓$LOG_NOCOLOR\tsetup\ ..................$LOG_VIOLET
KO1=--$LOG_CLEAR$LOG_RED
KO2=x$LOG_NOCOLOR'\t'setup\ ..................$LOG_VIOLET
KO=$KO1$KO2
END=$LOG_NOCOLOR

if [ "$OS" == Darwine ]
	then
	if !(brew ls --versions sdl2 > /dev/null)
	then
		echo -e $TITLE setup prerequisites$END
		echo -e $SETUP libSDL2 $END
#		brew update && brew install sdl2
	fi
elif [ "$OS" == Linuxe ]
	then
	if !(dpkg -s libsdl2-dev > /dev/null)
	then
		echo -e $TITLE setup prerequisites $END
		echo -e $SETUP libSDL2 $END
#		sudo apt-get install --yes libsdl2-dev
	fi
else
	echo -e $TITLE setup prerequisites$END
	echo -e $KO libSDL2 $END Please check and install manually
fi