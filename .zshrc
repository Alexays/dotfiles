alias ls='ls --color=auto'
alias sl='ls'
alias yolo='pacaur -Syua'
alias yolor='/home/rouill_a/bin/.yolor'
alias emacs='emacs -nw'
alias ne='emacs'
alias push_repo='git up && push_repo'
alias log='git log --pretty=full --stat --graph --decorate=full'
alias chromium='chromium --process-per-site'

export TERM=xterm-256color

export PATH=/bin:/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/home/rouill_a/bin:/opt/android-ndk
export ANDROID_HOME=/opt/android-sdk
export ANDROID_NDK=/opt/android-ndk

### C Graphical Programming Environement Variable
export LIBRARY_PATH=$LIBRARY_PATH:/home/rouill_a/.graph_programming/lib
export LD_LIBRARY_PATH=$LIBRARY_PATH:/home/rouill_a/.graph_programming/lib
export CPATH=$CPATH:/home/rouill_a/.graph_programming/include

export GEOMETRY_SYMBOL_PROMPT="❯"
export GEOMETRY_SYMBOL_EXIT_VALUE="❯"

export PATH="$HOME/.cargo/bin:$PATH"

# load zgen
source $HOME/.zgen/zgen.zsh

# if the init scipt doesn't exist
if ! zgen saved; then

    zgen prezto prompt theme 'eayo'

    zgen prezto
    zgen prezto git
    zgen prezto command-not-found
    zgen prezto syntax-highlighting
    zgen prezto history-substring-search
    zgen prezto autosuggestions
    zgen prezto completion

    # plugins
    zgen load bhilburn/powerlevel9k
    zgen load zsh-users/zsh-syntax-highlighting

    # completion
    #zgen load zsh-users/zsh-completions src

    #theme
    #zgen load frmendes/geometry geometry

    # generate the init script from plugins above
    zgen save
fi
