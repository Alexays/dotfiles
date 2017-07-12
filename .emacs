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
 '(package-selected-packages
   (quote
    (web-mode whitespace-cleanup-mode auto-package-update smartparens flycheck)))
 '(show-paren-mode t))
(custom-set-faces
 )
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
;; ----------------------------------
;;       INDENTATION & OTHER
;; ----------------------------------
(require 'auto-complete-config)
(require 'package)
(add-to-list 'ac-dictionary-directories "~/.emacs.d/lisp/ac-dict")
(ac-config-default)
(add-to-list 'package-archives
             '("MELPA Stable" . "https://stable.melpa.org/packages/") t)
(package-initialize)
(global-flycheck-mode)
(smartparens-global-mode t)
(defun my-c-mode-common-hook ()
  (setq flycheck-clang-include-path (list "include" "../include" "../../include" "../../../include")))
(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)
