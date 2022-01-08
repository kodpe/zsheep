#!/bin/bash
echo -ne "\e[0m"
version="0-0-1"
alias_path="~/.config/zsheep/zsheep_app/"
#
if ! grep -q "zsheep_${version}" ~/.zshrc
then
	echo "#" >> ~/.zshrc
	echo "# zsheep_${version} $(uname -s) $(date)" >> ~/.zshrc # sa uninstall
	echo "# zsheep alias list" >> ~/.zshrc
	echo 'alias gps="~/.config/zsheep/zsheep_app/42gps/gps"' >> ~/.zshrc
	echo 'alias sna="~/.config/zsheep/zsheep_app/snails/snails.sh"' >> ~/.zshrc
	echo 'alias snails="~/.config/zsheep/zsheep_app/snails/snails.sh"' >> ~/.zshrc
	echo "# zsheep_@kodpe" >> ~/.zshrc # se unistall
	
	if [ -d "${HOME}/.config" ]
	then
		mkdir ~/.config/zsheep
		cp -rf zsheep_app ~/.config/zsheep
	else
		mkdir ~/.config
		mkdir ~/.config/zsheep
		cp -rf zsheep_app ~/.config/zsheep
	fi
	echo -e "\e[1;32m(>o.o>) zsheep installed"
	echo
	echo '> How run snails'
	echo -e "do '\e[1;32msna\e[0m' or '\e[1;32msnails\e[0m' in new terminal"
	echo
	echo '> How run gps'
	echo -e "do '\e[1;32mgps e2r4p8\e[0m' in new terminal"
	echo -ne "\e[0m"
else
	echo -e "\e[1;34m(>o.o>) zsheep install : zsheep already installed"
fi
#
echo -ne "\e[0m"
exit
