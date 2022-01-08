#!/bin/bash
version="0-0-1"
if ! grep -q "zsheep_${version}" ~/.zshrc
then
	echo "#zsheep alias zsheep_${version} $(date) $(uname -s)"
	echo 'alias gps="~/.config/zsheep/zsheep_app/42gps/gps"' >> ~/.zshrc
	echo 'alias sna="~/.config/zsheep/zsheep_app/snails/snails.sh"' >> ~/.zshrc
	echo 'alias snails="~/.config/zsheep/zsheep_app/snails/snails.sh"' >> ~/.zshrc

	if [ -d "${HOME}/.config" ]
	then
		mkdir ~/.config/zsheep
		cp -rf zsheep_app ~/.config/zsheep
	else
		mkdir ~/.config
		mkdir ~/.config/zsheep
		cp -rf zsheep_app ~/.config/zsheep
	fi
	echo -e '\e[0;39m>> zsheep installed'
	echo
	echo 'How run snails'
	echo -e "do '\e[1;32msna\e[0m' or '\e[1;32msnails\e[0m' in new terminal"
	echo "or run ./snails.sh"
	echo -ne "\e[0m"
fi
