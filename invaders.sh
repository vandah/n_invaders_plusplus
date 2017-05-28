#!/bin/bash
clear

in11="< oo>"
in12="<o o>"
in13="<oo >"
in14="<ooo>"

in21="<^>"
in22="/^\\ "
in23="/|\\ "
in24="<|>"

in31=">O<"
in32="<o>"
in33="_o-"
in34="-o_"

in41="@-@"
in42="<+>"
in43="#-#"
in44="%^%"

in51="/~\\ "
in52="/.\\ "
in53="\\~/"
in54="\\./"

ds11=">==<"
ds12="----"
ds13=" -- "

ds21=">-<"
ds22="---"
ds23=" - "

ds31=">-<"
ds32="---"
ds33=" - "

ds41=">-<"
ds42="---"
ds43=" - "

ds51=">-<"
ds52="---"
ds53=" - "

while :;do
	for k in {1..5};do
		for i in\
			"\033[1;35m$in11\n\033[1;32m$in21\n\033[1;34m$in31\n\033[1;36m$in41\n\033[1;33m$in51\033[0m"\
			"\033[1;35m$in12\n\033[1;32m$in22\n\033[1;34m$in32\n\033[1;36m$in42\n\033[1;33m$in52\033[0m"\
			"\033[1;35m$in13\n\033[1;32m$in23\n\033[1;34m$in33\n\033[1;36m$in43\n\033[1;33m$in53\033[0m"\
			"\033[1;35m$in14\n\033[1;32m$in24\n\033[1;34m$in34\n\033[1;36m$in44\n\033[1;33m$in54\033[0m"
	do echo -e $i; sleep 0.16; clear; done;done
	for i in\
		"\033[1;31m$ds11\n$ds21\n$ds31\n$ds41\n$ds51\033[0m"\
		"\033[1;31m$ds12\n$ds22\n$ds32\n$ds42\n$ds52\033[0m"\
		"\033[1;31m$ds13\n$ds23\n$ds33\n$ds43\n$ds53\033[0m"
do echo -e $i; sleep 0.16; clear; done
sleep 0.7
done
