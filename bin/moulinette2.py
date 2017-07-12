#!/usr/bin/python3
#
# Made by duponc_j, modified by sourio_b while supervised by sbriss_a in case he fucked things up (and he did)
# Version: 1.4.1
#

'''
An Epitech norme checker

Usage: python norme.py <dir to scan> [-nocheat] [-verbose] [-score] [-libc]

-verbose: affiche les messages impossible d\'ouvrir
-nocheat: desactive la detection de la triche
-score: affiche le nombre de faute de norme
-libc: active la verification des fonctions de la libc
-malloc: desactive le controle du malloc
-printline: affiche la ligne provoquant une erreur
-return: active verifier le retour des fonctions (return ;)
-comment: ne pas verifier les commentaire

Non geree:
- Indentation
- +<escape>
- verification de la presence de gl_

Bug:
Il est arrivee que le checker ne trouve aucune faute alors qu\'il en existe, si
ce bug vous arrive maillez moi.
'''

import sys,re,os,pwd

blind_logins = [ "Alexis Rouillard" ]

def static_var(varname, value):
    def decorate(func):
        setattr(func, varname, value)
        return func
    return decorate

class norme:
    def __init__(self):
        self.user = []
        self.verbose = 0
        self.cheat = 1
        self.comment = 1
        self.score = 0
        self.note = 0
        self.libc = 1
       # self.malloc = 1
        self.malloc = 0
        self.printline = 0
        self.creturn = 1
        self.the_dir = ""
        
    def new_file(self):
        self.nb_line = 1
        self.nb_return = 0
        self.nb_funcline = 0        
        self.nb_func = 0
        self.sys_include = 0
        self.double_inclusion = 0
        self.is_func = 0
        self.in_comment = 0
        self.out_comment = 0
        self.typedef = 0
        if self.verbose == 1:
            print("Scan: %s" % self.file)
    
    @static_var("passed", 0)
    def check_header(self):
        norme = -1
        if self.check_header.passed:
            norme = 0
        for blind in blind_logins:
            if (blind in self.user):
                return
        if (self.nb_line == 1):
            if (self.line[:2] != '/*'):
                self.print_error('header incorrect', norme)
                self.check_header.__func__.passed = 1
        elif (self.nb_line == 9):
            if (self.line[:2] != '*/'):
                self.print_error('header incorrect', norme)
                self.check_header.__func__.passed = 1
        elif self.nb_line == 4 or self.nb_line == 7 or self.nb_line == 8:
            if self.cheat:
                p = re.compile('([\w-]* [\w-]*)$')
                test = re.search(p, self.line)
                if test:
                    if not test.group(1) in self.user:
                        self.print_error('login '+ test.group(1) +' incorrect', norme)
                        self.check_header.__func__.passed = 1
        elif (self.nb_line == 5):
            if self.cheat:
                p = re.compile('<(.*)@')
                test = re.search(p, self.line)
                if test:
                    if not test.group(1) in self.user:
                        self.print_error('login '+ test.group(1) +' incorrect', norme)
                        self.check_header.__func__.passed = 1
        else:
            if (self.line[:2] != '**'):
                self.print_error('header incorrect', norme)
                self.check_header.__func__.passed = 1

    @static_var("passed", 0)
    def check_virgule(self):
        norme = -1
        if self.check_virgule.passed:
            norme = 0
        n = 0
        quote = 0
        while n < len(self.line) and self.line[n] != '\n' :
            if self.line[n] == '\'' or self.line[n] == '"':
                if quote:
                    quote = 0
                else:
                    quote = 1
            if (self.line[n] == ',') and quote == 0:
                if self.line[n + 1] != ' ' and self.line[n + 1] != '\n' and self.line[n + 1] != '\t':
                    if self.line[-2:-1] == '\\':
                        pass
                    self.print_error('point-virgule ou virgule mal place', norme)
                    self.check_virgule.__func__.passed = 1
                    break
            n = n + 1

    @static_var("passed", 0)
    def check_space_par(self):
        norme = -1
        if self.check_space_par.passed:
            norme = 0
        n = 0
        quote = 0
        while n < len(self.line) and self.line[n] != '\n' :
            if self.line[n] == '\'' or self.line[n] == '"':
                if quote:
                    quote = 0
                else:
                    quote = 1
            if (self.line[n] == '(') and quote == 0:
                if self.line[n + 1] == ' ':
                    self.print_error('espace parenthese ouvrante', norme)
                    self.check_space_par.__func__.passed = 1
                    break
            if (self.line[n] == ')') and quote == 0:
                if self.line[n - 1] == ' ':
                    self.print_error('espace parenthese fermante', norme)
                    self.check_space_par.__func__.passed = 1
                    break
            n = n + 1

    @static_var("passed", 0)
    def check_nbchar(self):
        norme = -5
        if self.check_nbchar.passed:
            norme = 0
        line = self.line.replace('\t', "    ")
        if len(line) > 80:
            note =  len(line) - 80
            self.print_error('chaine de plus de 80 caracteres', norme)
            self.check_nbchar.__func__.passed = 1

    @static_var("passed", 0)
    def check_return(self):
        norme = -1
        if self.check_return.passed:
            norme = 0
        if (self.line[:1] == '\n'):
            if (self.nb_return == 1):
                self.print_error('double retour a la ligne', norme)
                self.check_return.__func__.passed = 1
            else:
                self.nb_return = 1
        else:
            self.nb_return = 0

    @static_var("passed", 0)
    def check_nbline(self):
        norme = -5
        if self.check_nbline.passed:
            norme = 0
        if self.file[-2:] == ".c" or self.file[-2:] == ".h":
            if self.line[:1] == '}':
                self.is_func = 0
                self.nb_funcline = 0
            if self.line[:2] == '};':
                self.is_func = 0
                self.nb_funcline = 0
                self.nb_func = self.nb_func -1
            if self.line[:1] == '{' and self.typedef == 0:
                self.is_func = 1
                self.nb_funcline = 0
                self.nb_func = self.nb_func + 1
                if self.nb_func == 6:
                    self.print_error('plus de 5 fonctions dans le fichier', norme)
                    self.check_nbline.__func__.passed = 1
            else:
                if self.nb_func >= 1 and self.is_func:
                    self.nb_funcline = self.nb_funcline + 1
                    if self.nb_funcline >= 26:
                        self.print_error('fonction de plus de 25 lignes', norme)
                        self.check_nbline.__func__.passed = 1

    @static_var("passed", 0)
    def check_cfunc(self):
        norme = -1
        if self.check_cfunc.passed:
            norme = 0
        p = re.compile('[ \t](if|else|return|while|for|break)(\()')
        test = re.search(p, self.line)
        if test:
            self.print_error('pas d\'espace apres mot clef', norme)
            self.check_cfunc.__func__.passed = 1

    @static_var("passed", 0)
    def check_arg(self):
        norme = -5
        if self.check_arg.passed:
            norme = 0
        if self.line[-2:] == ")\n" and self.line[:1] != '\t'  and self.line[:1] != ' ':
            p = re.compile('(.*),(.*),(.*),(.*),(.*)\)$')
            test = re.search(p, self.line)
            if test and self.line.find(')') == self.line.rfind(')'):
                note = 1
                if len(test.groups()) > 0:
                    note = len(test.groups()) - 4
                self.print_error('plus de 4 arguments passes en parametre', norme)
                self.check_arg.__func__.passed = 1

    @static_var("passed", 0)
    def check_sys_include(self):
        return
        if self.check_sys_include.passed:
            return 
        if self.line[:1] == "#" and self.line[-2:] == "\"\n":
            self.sys_include = 1
        else:
            if self.line[:1] == "#" and self.line[-2:] == ">\n" and self.sys_include == 1:            
                self.print_error('Header systeme mal placee')
                self.check_sys_include.__func__.passed = 1

    @static_var("passed", 0)
    def check_comment(self):
        norme = -5
        if self.check_comment.passed:
            norme = 0
        if self.is_func and self.comment:
            p = re.compile('(//|/\*)')
            test = re.search(p, self.line)
            if test:
                note = 1
                if len(test.groups()) > 0:
                    note = len(test.groups())
                    self.print_error('Commentaires dans le code', norme)
                    self.check_comment.__func__.passed = 1

    @static_var("passed", 0)
    def check_malloc(self):
        if self.check_malloc.passed:
            return 
        p = re.compile('[^x](malloc)(\()')
        test = re.search(p, self.line)
        if test and (self.file != "xmalloc.c"):
            self.print_error('Malloc non verifiee')
            self.check_malloc.__func__.passed = 1

    @static_var("passed", 0)
    def check_double(self):
        return
        norme = -1
        if self.check_double.passed:
            norme = 0
        if self.file[-2:] == ".h":
            if self.line[:1] != '\n':
                if self.double_inclusion != 1:
                    self.double_inclusion = 1
                    if self.line[-4:] != "_H_\n":
                        self.print_error('Header non protegee', norme)
                        self.check_double.__func__.passed = 1
                    else:
                        self.double_inclusion = 1

    @static_var("passed", 0)
    def check_operateur(self, op):
        norme = -1
        if self.check_operateur.passed:
            norme = 0
        n = 0
        quote = 0
        while n < len(self.line) and self.line[n] != '\n' :
            if self.line[n] == '\'' or self.line[n] == '"':
                if quote:
                    quote = 0
                else:
                    quote = 1
            if (self.line[n] == op) and quote == 0:
                if (self.line[n + 1] != ' ' or self.line[n - 1] != ' ') and self.line[n + 1] != ';' and self.line[n + 1] != '=' and self.line[n + 1] != '\n':
                    if self.line[n - 1] != op and self.line[n + 1] != op and not self.line[:n].isspace():
                        msg = 'Operateur %c mal place' % op
                        self.print_error(msg, norme)
                        self.check_operateur.__func__.passed = 1
            n = n + 1

    def check_typedef(self):
        if self.line[:7] == "typedef":
            self.typedef = 1
        else:
            self.typedef = 0
    
    @static_var("passed", 0)
    def check_regex(self, regex, msg):
        norme = -42
        if self.check_regex.passed:
            norme = 0
        p = re.compile(regex)
        test = re.search(p, self.line)
        if test:
            note = 1
            if len(test.groups()) > 0:
                note = len(test.groups())
                self.print_error(msg, norme)
                self.check_regex.__func__.passed = 1

    @static_var("passed", 0)
    def check_returns(self):
        norme = -1
        if self.check_returns.__func__.passed:
            norme = 0
        dot = self.line.rfind(';')
        if dot == -1:
            return
        pos = dot - 1
        left = self.line[:dot]
        while pos >= 0 and (left[pos] == ' ' or left[pos] == '\t'):
            pos = pos - 1
        pos = pos + 1
        ret = self.line.find("return")
        if ret == -1:
            ret = self.line.find("break")
        par = self.line.find("(")
        if (ret != -1 and par == -1):
            pos = pos + 1
        if pos < dot:
            self.print_error("Espaces avant le ';'", norme)
            self.check_returns.__func__.passed = 1

    @static_var("passed", 0)
    def check_endlinespaces(self):
        norme = -1
        if self.check_endlinespaces.passed:
            norme = 0
        dot = self.line.find('\n')
        if dot == -1:
            return
        pos = dot - 1
        left = self.line[:dot]
        while pos >= 0 and (left[pos] == ' ' or left[pos] == '\t'):
            pos = pos - 1
        pos = pos + 1
        if pos < dot:
            self.print_error("Espace(s) en fin de ligne", norme)
            self.check_endlinespaces.__func__.passed = 1

    @static_var("passed", 0)
    def check_line(self):
        norme = -5
        if self.is_func != 1 and self.line.find("/*") != -1:
            self.out_comment = 1
        if  self.out_comment:
            if self.is_func != 1 and self.line.find("*/") != -1:
                self.nb_return = 0
                self.out_comment = 0
            return
        if self.is_func == 1 and self.line.find("/*") != -1 and self.line.find('\"') == -1:
            self.in_comment = 1
            if self.check_line.passed:
                norme = 0
            self.print_error("Commentaires dans le code", norme)
            self.check_line.__func__.passed = 1
            if self.line.find("*/") != -1:
                self.nb_return = 0
                self.in_comment = 0
                return
        self.check_nbline() # DOIT TOUJORS ETRE EN PREMIER
#        self.check_sys_include()
        self.check_virgule()
        self.check_space_par()
        self.check_endlinespaces()
        self.check_returns()
        if self.libc == 0:
            self.check_regex('[^_](printf|atof|atoi|atol|strcmp|strlen|strcat|strncat|strncmp|strcpy|strncpy|fprintf|strstr|strtoc|sprintf|asprintf|perror|strtod|strtol|strtoul)(\()', \
                             'Fonction de la lib C')
        self.check_nbchar()
        self.check_cfunc()
        self.check_arg()
        self.check_return()
        self.check_double()
        self.check_operateur('+')
        self.check_operateur('|')
        self.check_typedef() #DOIT TOUJOURS ETRE EN DERNIER
        if self.malloc:
            self.check_malloc()
        
    def print_error(self, msg, val = -1):
        self.note = self.note + val
        print("Erreur dans %s a la ligne %s:%s => %s"% (self.the_dir + self.file, self.nb_line, msg, val))
        if self.printline:
            print(self.line)

    def get_score(self):
        if self.note < -10:
            return (1)
        elif self.note < -5:
            return (-10)
        return (self.note)

    def cant_open(self, file):
        if (self.verbose or file == sys.argv[1]):
            print("Impossible d'ouvrir %s", file)

    def scandir(self, thedir):
        try:
            dir = os.listdir(thedir)
        except:
            self.cant_open(thedir)
        else:
#            check_makefile(thedir)
            for file in dir:
                try:
                    if os.path.islink(thedir + file):
                        continue
                    if (os.path.isdir(thedir + file)):
                        self.scandir(thedir + "/" + file + "/")
                    self.the_dir = thedir
                    if file[-2:] == '.c' or file[-2:] == '.h':
                        self.file = file
                        self.new_file()
                        file = thedir + file
                        try:
                            fd = open(file, 'r')
                        except IOError:
                            self.cant_open(file)
                        else:
                            for self.line in fd.readlines():
                                if self.nb_line <= 9:
                                    self.check_header()
                                else:
                                    self.check_line()
                                self.nb_line = self.nb_line + 1
                                fd.close()
                except:
                    print("Issue on %s: Please do the norm manually"% file)

    def get_user(self):
        try:
            fd = open(sys.argv[1] + 'auteur')
        except IOError:
            user = os.getenv('USER')
            self.user.append(user)
            try:
                self.user.append(pwd.getpwnam(user)[4]) #Recuperation du nom complet de l'utilisateur
            except:
                pass
        else:
            buffer = fd.read()
            fd.close()
            p = re.compile('([\w]*)')
            test = re.findall(p, buffer)
            for user in test:
                if user:
                    self.user.append(user)
                    self.user.append(pwd.getpwnam(user)[4])


def check_makefile(thedir):
    file = thedir + "Makefile"
    if os.path.isfile(file):
        try:
            fd = open(file, 'r')
        except IOError:
            print("Impossible d'ouvrir le Makefile")
        else:
            buffer = fd.read()
            p = re.compile('(-g|-pg|-lefence)')
            test = re.search(p, buffer)
            if test:
                print("Options de debug dans le Makefile")
            p = re.compile('(-Wall)')
            test = re.search(p, buffer)
            if not test:
                print("-Wall n'est pas dans le Makefile")
            if buffer[:2] != "##":
                print("Header du Makefile invalide")
            fd.close()

def help():
    print("Aide")
    print("Usage: norme.py <dir_to_scan>")
    print("-verbose: affiche les messages impossible d'ouvrir")
    print("-nocheat: desactive la detection de la triche")
    print("-score: affiche le nombre de faute de norme")
    print("-libc: active la verification des fonctions de la libc")
    print("-malloc: desactive le controle du malloc")
    print("-printline: affiche la ligne provoquant une erreur")
    print("-return: active verifier le retour des fonctions (return ;)")
    print("-comment: ne pas verifier les commentaire")
    sys.exit()

def main():
    if len(sys.argv) == 1:
        print("Usage: norme.py <dir_to_scan>")
        sys.exit()
    moulin = norme()
    if '-verbose' in sys.argv[1:]:
        moulin.verbose = 1
    if '-comment' in sys.argv[1:]:
        moulin.comment = 0
    if '-nocheat' in sys.argv[1:]:
        moulin.cheat = 0
    if '-score' in sys.argv[1:]:
        moulin.score = 1
    if '-libc' in sys.argv[1:]:
        moulin.libc = 0
    if '-malloc' in sys.argv[1:]:
        moulin.malloc = 0
    if '-printline' in sys.argv[1:]:
        moulin.printline = 1
    if '-return' in sys.argv[1:]:
        moulin.creturn = 0
    if '--user' in sys.argv[1:]:
        try:
            moulin.user.append(sys.argv[sys.argv.index("--user") + 1])
        except:
            pass
    if '-help' in sys.argv[1:]:
        help()
    if sys.argv[1][-1:] != '/':
        sys.argv[1] = sys.argv[1] + '/'
    if moulin.cheat == 1:
        moulin.get_user()
    try:
        moulin.scandir(sys.argv[1])
    except NameError:
        print("Usage: norme.py <dir_to_scan>")
    if moulin.score:
        print(moulin.get_score(), file=sys.stderr)

if __name__ == "__main__":
    main()
