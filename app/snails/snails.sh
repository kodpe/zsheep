#!/bin/bash
if ! grep -q "snails.sh" ~/.zshrc
then
	echo 'alias sna="~/bin/snails.sh"' >> ~/.zshrc
	echo 'alias snails="~/bin/snails.sh"' >> ~/.zshrc
	if [ -d "${HOME}/bin" ]
	then
		cp snails.sh ~/bin
	else
		mkdir ~/bin
		cp snails.sh ~/bin
	fi
	echo -e '\e[0;39m>> snails is installed'
	echo
	echo 'How run snails'
	echo -e "do '\e[1;32msna\e[0m' or '\e[1;32msnails\e[0m' in new terminal"
	echo "or run ./snails.sh"
	echo -ne "\e[0m"
	exit
fi

snr=(
		"   .----.   @   @ "
		"  / .---.\`.  \x5C_/  "
		"  | | 0\ \ \_/ )  "
		",-\ \`-.' /.'  /   "
		"'---\`----'----'   "
		"   .----.   @   @|"
		"  / .---.\`.  \x5C_/ |"
		"  | | 0\ \ \_/ ) |"
		",-\ \`-.' /.'  /  |"
		"'---\`----'----'  |"
)

snl=(
		" @   @   .----.    "
		"  \x5C_/  .'.---. \x5C   "
		"  ( \x5C_/ / /0 | |   "
		"   \x5C  '.\x5C '.-' /-. "
		"   '----'-----'--' "
		" @   @   .----.   |"
		"  \x5C_/  .'.---. \x5C  |"
		"  ( \x5C_/ / /0 | |  |"
		"   \x5C  '.\x5C '.-' /-.|"
		"   '----'-----'--'|"
)

newseed() {
	len=$(stty size | awk '{print $2}'); len=$(($len - 40)); len=$(($len / 2))
	csnr=0; csnl=0;
	while (( $csnr == $csnl ));
	do csnr=$(($RANDOM%8)); csnl=$(($RANDOM%8)); done
	rand=$(($RANDOM%6))
	rand=$(($rand + 1))
	speed=$(awk "BEGIN {print 1/${rand}}")
}

snailslove() {
	newseed
	for (( z = $len; z >= 0; z-- )); do 
		if [[ $z -eq 0 ]]; then newseed; fi
		for (( h = 0; h < 5; h++ )); do 
			for (( i = 0; i < $len - $z; i++ )); do echo -ne " "; done
			echo -ne "\e[1;3${csnr}m"
			echo -ne "${snr[$h]}"
			for (( i = 0; i < $z * 2; i++ )); do echo -ne " "; done
			if [[ $z -eq 0 && $h -eq 1 ]]; then echo -ne "\e[1;31m\u2665"; fi
			if [[ $z -eq 0 && $h -ne 1 ]]; then echo -ne " "; fi
			echo -ne "\e[1;3${csnl}m"
			echo -ne "${snl[$h]}"
			echo
		done
		sleep $speed 
		clear
	done
	for (( z = 0; z < $len; z++ )); do 
		for (( h = 0; h < 5; h++ )); do 
			for (( i = 0; i < $len - $z; i++ )); do echo -ne " "; done
			echo -ne "\e[1;3${csnr}m"
			echo -ne "${snl[$h]}"
			for (( i = 0; i < $z * 2; i++ )); do echo -ne " "; done
			echo -ne "\e[1;3${csnl}m"
			echo -ne "${snr[$h]}"
			echo
		done
		sleep $speed 
		clear
	done
}
echo -ne "\e[1;30m"
clear
for (( sna = 0; sna < 99; sna++ )); do
	snailslove
done 
echo -ne "\e[0m"
exit
#for i in "${snail_right[@]}"; do echo -e $i; done #echo all elements
#for (( i = 0; i < ${#snr[@]}; i++ )) do echo -e "${snr[$i]}"; done
#for (( i = 0; i < ${#snl[@]}; i++ )) do echo -e "${snl[$i]}"; done
