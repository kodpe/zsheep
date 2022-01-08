#!/bin/bash
echo -ne "\e[0m"
version="0-0-1"
alias_path="~/.config/zsheep/zsheep_app/"
#
sa=$(grep -n "# zsheep_${version}" ~/.zshrc)
san=$(awk -F ":" '{print $1}' <<<${sa})

se=$(grep -n "# zsheep_@kodpe" ~/.zshrc)
sen=$(awk -F ":" '{print $1}' <<<${se})

#echo "debug : $san $sen" | cat -e

if (( ${#san} > 0 && ${#sen} > 0))
then
	sed -i"_backup" "${san},${sen}d" ~/.zshrc 
	echo -e "\e[1;32m(>o.o>) zsheep uninstalled : aliases removed"
else
	echo -e "\e[1;31m(>o.o>) zsheep error : no aliases in ~/.zshrc"
fi
	
if [ -d "${HOME}/.config/zsheep" ]
then
	rm -rf ~/.config/zsheep
	echo -e "\e[1;32m(>o.o>) zsheep uninstalled : files removed"
else
	echo -e "\e[1;31m(>o.o>) zsheep error : no ~/.config/zsheep"
	echo -e "\e[1;31m(>o.o>) zsheep error : zsheep is not installed"
fi
#
echo -ne "\e[0m"
exit
