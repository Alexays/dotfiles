source ~/.antigen.zsh

# Load the oh-my-zsh's library.
antigen use oh-my-zsh

# Bundles from the default repo (robbyrussell's oh-my-zsh).
antigen bundle git
antigen bundle heroku
antigen bundle pip
antigen bundle lein
antigen bundle command-not-found

# Syntax highlighting bundle.
antigen bundle zsh-users/zsh-syntax-highlighting

# Load the theme.
antigen bundle frmendes/geometry

# Tell antigen that you're done.
antigen apply

export PROMPT_GEOMETRY_EXEC_TIME=true
export TERM=xterm-256color

alias ls='ls --color=auto'
alias yolo='yaourt -Syua'
alias yolor='/home/rouill_a/bin/.yolor'
alias emacs='emacs -nw'
alias ne='emacs'

export PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/home/rouill_a/.config/bspwm/panel:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/home/rouill_a/bin:/opt/android-ndk
export ANDROID_HOME=/opt/android-sdk
export ANDROID_NDK=/opt/android-ndk

### C Graphical Programming Environement Variable
export LIBRARY_PATH=$LIBRARY_PATH:/home/rouill_a/.graph_programming/lib
export LD_LIBRARY_PATH=$LIBRARY_PATH:/home/rouill_a/.graph_programming/lib
export CPATH=$CPATH:/home/rouill_a/.graph_programming/include

# Add environment variable COCOS_CONSOLE_ROOT for cocos2d-x
export COCOS_CONSOLE_ROOT=/home/rouill_a/Doc/cocos2d/tools/cocos2d-console/bin
export PATH=$COCOS_CONSOLE_ROOT:$PATH

# Add environment variable COCOS_X_ROOT for cocos2d-x
export COCOS_X_ROOT=/home/rouill_a/Downloads
export PATH=$COCOS_X_ROOT:$PATH

# Add environment variable COCOS_TEMPLATES_ROOT for cocos2d-x
export COCOS_TEMPLATES_ROOT=/home/rouill_a/Doc/cocos2d/templates
export PATH=$COCOS_TEMPLATES_ROOT:$PATH

# Add environment variable NDK_ROOT for cocos2d-x
export NDK_ROOT=/opt/android-ndk
export PATH=$NDK_ROOT:$PATH

# Add environment variable ANDROID_SDK_ROOT for cocos2d-x
export ANDROID_SDK_ROOT=/opt/android-sdk
export PATH=$ANDROID_SDK_ROOT:$PATH
export PATH=$ANDROID_SDK_ROOT/tools:$ANDROID_SDK_ROOT/platform-tools:$PATH

# Add environment variable ANT_ROOT for cocos2d-x
export ANT_ROOT=/usr/bin
export PATH=$ANT_ROOT:$PATH
