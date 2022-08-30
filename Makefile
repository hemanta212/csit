# DOCS
# -O0: notice the capital o here. Optimization level indicator 0 fastest compile and more debug friendly (DEFAULT : -O1)
# -Wall: this is a toggle always include Warning supressino after this toggle
# -Wshadow: Issue warning when your decalre a var and again declare it thereby shadwoing the previous
# -pedantic-erros: Generate more portability code issuing erros if some headers missing and stuff like that

temp: temp.c
	$(CLANG) clang temp.c -ggdb3 -O0 -o temp -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c11 -ledit -lm  

temprun:
	./temp

aa: aa.c
	$(CLANG) clang aa.c -ggdb3 -O0 -o aa -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c11 -ledit -lm  

loose: temp.c
	$(CLANG) clang temp.c -o temp -Wall -std=c11 -ledit -lm  
