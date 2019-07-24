export LANG=en_US.UTF-8

export GEOMETRY_SYMBOL_PROMPT="❯"
export GEOMETRY_SYMBOL_EXIT_VALUE="❯"

source /usr/local/share/antigen/antigen.zsh

antigen use oh-my-zsh
antigen bundle git
antigen bundle pip
antigen bundle lein
antigen bundle command-not-found
antigen bundle djui/alias-tips
antigen bundle zsh-users/zsh-history-substring-search
antigen bundle zsh-users/zsh-completions
antigen bundle zsh-users/zsh-syntax-highlighting
antigen bundle zsh-users/zsh-autosuggestions
antigen theme geometry-zsh/geometry
antigen apply
