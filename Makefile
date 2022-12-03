# DOCS
# -O0: notice the capital o here. Optimization level indicator 0 fastest compile and more debug friendly (DEFAULT : -O1)
# -Wall: this is a toggle always include Warning supressino after this toggle
# -Wshadow: Issue warning when your decalre a var and again declare it thereby shadwoing the previous
# -pedantic-erros: Generate more portability code issuing erros if some headers missing and stuff like that
CC = clang
CFLAGS = -ggdb3 -O0 -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c11 -lm
TARGET = temp

all: $(TARGET)

$(TARGET): temp.c stack.c infix_postfix.c postfix_calc.c
	$(CC) $(CFLAGS) temp.c -o $(TARGET)

temprun: $(TARGET)
	./temp

aa: aa.c
	$(CC) $(CFLAGS) aa.c -o aa

loose: temp.c
	$(CC) -Wall -std=c11 -lm temp.c -o temp

.PHONY: clean
clean:
	rm ./temp
