# DOCS
# SYNTAX: targets: prerequisites
# 		<recipe>
#  $< : First prerequisite listed
#  .Phony : Targets are not files they are commands, ignore file with same name
#
# COMPILER ARGS:
# -O0: notice the capital o here. Optimization level indicator 0 fastest compile and more debug friendly (DEFAULT : -O1)
# -Wall: this is a toggle always include Warning supressino after this toggle
# -Wshadow: Issue warning when your decalre a var and again declare it thereby shadwoing the previous
# -pedantic-erros: Generate more portability code issuing erros if some headers missing and stuff like that

.PHONY: temprun loose clean

temp: temp.cpp
	$(g++) g++ temp.cpp -ggdb3 -O0 -o temp -Wall -Werror -Wextra -Wshadow -pedantic-errors -lm

temprun:temp
	./temp

aa: aa.cpp
	$(g++) g++  -ggdb3 -O0 -o aa -Wall -Werror -Wextra -Wshadow -pedantic-errors -lm

loose: temp.cpp
	$(g++) g++ temp.cpp -ggdb3 -o temp -Wall -ledit -lm

clean:
	rm ./a.out ./temp ./aa

# Run all cpp files with g++
OBJCpp=$(patsubst %.cpp, %.out, $(wildcard *.cpp))
%.out: %.cpp
	$(g++) g++ $< -ggdb3 -o $@ -Wall -Werror -Wextra -Wshadow -pedantic-errors -lm

all: $(OBJCpp)

