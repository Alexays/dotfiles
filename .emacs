;; ----------------------------------
;;               CUSTOM
;; ----------------------------------
(setq make-backup-files nil) ; stop creating those backup~ files
(setq auto-save-default nil) ; stop creating those #autosave# files
(global-linum-mode 1) ; display line numbers in margin. Emacs 23 only.
(transient-mark-mode 1) ; highlight text selection
(delete-selection-mode 1) ; delete seleted text when typing
(setq user-full-name "Alexis Rouillard")
(setq user-mail-address "alexis.rouillard@epitech.eu")
;; disable menu bar
(tool-bar-mode -1)
(menu-bar-mode -1)
(scroll-bar-mode -1)
;; mode line settings
(setq column-number-mode t)
(setq line-number-mode t)
(setq size-indication-mode t)
;; parenthese en couleur
(custom-set-variables
 '(show-paren-mode t))
(custom-set-faces)
;; auto completation
(icomplete-mode 1)
(setq completion-ignore-case t)
;; make characters after column 80 purple
(setq whitespace-style
  (quote (face trailing lines-tail)))
(add-hook 'find-file-hook 'whitespace-mode)
;; ----------------------------------
;;               THEME
;; ----------------------------------
(add-to-list 'custom-theme-load-path "~/.emacs.d/themes/")
(load-theme 'solarized t)
(set-frame-parameter nil 'background-mode 'dark)
(set-terminal-parameter nil 'background-mode 'dark)
(setq solarized-visibility 'hight);
;; ----------------------------------
;;           EPITECH CONFIG
;; ----------------------------------
(add-to-list 'load-path "~/.emacs.d/lisp")
(load "std.el")
(load "std_comment.el")
(add-to-list 'load-path "~/.emacs.d/lisp")
;; ----------------------------------
;;       INDENTATION & OTHER
;; ----------------------------------
(require 'indent-guide)
(indent-guide-global-mode)
(require 'whitespace)
(require 'autopair)
(autopair-global-mode)
(require 'auto-complete-config)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/lisp/ac-dict")
(ac-config-default)
