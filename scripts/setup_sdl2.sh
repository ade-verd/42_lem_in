OS=`uname`

LOG_CLEAR='\033[2K'
LOG_RED='\033[1;31m'
LOG_GREEN='\033[1;32m'
LOG_BLUE='\033[1;34m'
LOG_VIOLET='\033[1;35m'
LOG_NOCOLOR='\033[0m'
X='x'
V='✓'

TITLE=$LOG_CLEAR$LOG_BLUE
TITLE_MSG="setup prerequisites"
END=$LOG_NOCOLOR

SETUP=--$LOG_CLEAR$LOG_GREEN$V$LOG_NOCOLOR'\t'setup\ .....................\ $LOG_VIOLET
KO=--$LOG_CLEAR$LOG_RED$X$LOG_NOCOLOR'\t'setup\ .....................\ $LOG_VIOLET
KO_MSG="Please check and install manually"

NAME="libSDL2"

if [ "$OS" == Darwin ]
	then
	if !(brew ls --versions sdl2 > /dev/null)
	then
		echo -e $TITLE$TITLE_MSG$END
		echo -e $SETUP$NAME$END
		brew update
		brew install sdl2
	fi
elif [ "$OS" == Linux ]
	then
	if !(dpkg -s libsdl2-dev > /dev/null)
	then
		echo -e $TITLE$TITLE_MSG$END
		echo -e $SETUP$NAME$END
		sudo apt-get update
		sudo apt-get install --yes libsdl2-dev
	fi
else
	echo -e $TITLE$TITLE_MSG$END
	echo -e $KO$NAME$END'\t'$KO_MSG
fi
