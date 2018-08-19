alias ls='ls --color=auto'
alias sl='ls'
alias yolo='yay -Syu --devel --timeupdate --combinedupgrade'
alias yolor='$HOME/.bin/yolor'
alias docktest='docker run -v /home/alex:/home/alex -i -t d4a7f5a2dd50 /bin/zsh'
alias maek='make'
alias gdba='git branch --no-color --merged | command grep -vE "^(\*|\s*(master|develop|dev)\s*$)" | command xargs -n 1 git branch -d'

export TERM=xterm-256color

export PATH=/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/home/alex/.bin:/home/alex/.bin/flutter/bin:/opt/android-ndk
export ANDROID_HOME=/opt/android-sdk
export ANDROID_NDK=/opt/android-ndk
export SDKMANAGER_OPTS="--add-modules java.se.ee"

export GEOMETRY_SYMBOL_PROMPT="❯"
export GEOMETRY_SYMBOL_EXIT_VALUE="❯"

source /usr/share/zsh/share/antigen.zsh

antigen use oh-my-zsh
antigen bundle git
antigen bundle pip
antigen bundle lein
antigen bundle command-not-found
antigen bundle djui/alias-tips
antigen bundle zsh-users/zsh-history-substring-search
antigen bundle zsh-users/zsh-completions
antigen bundle zdharma/fast-syntax-highlighting
antigen bundle zsh-users/zsh-autosuggestions
antigen bundle zpm-zsh/autoenv
antigen theme geometry-zsh/geometry
antigen apply
