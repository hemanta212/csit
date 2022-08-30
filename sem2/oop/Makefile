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
	$(g++) g++ temp.cpp -ggdb3 -O0  -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c++11 -lm -o temp

temprun:temp
	./temp

aa: aa.cpp
	$(g++) g++  -ggdb3 -O0 -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c++11 -lm -o aa

loose: temp.cpp
	$(g++) g++ temp.cpp -ggdb3 -Wall -ledit -std=c++11 -lm -o temp

clean:
	rm ./a.out ./temp ./aa

# Run all cpp files with g++
OBJCpp=$(patsubst %.cpp, %.out, $(wildcard *.cpp))
%.out: %.cpp
	$(g++) g++ $< -ggdb3 -Wall -Werror -Wextra -Wshadow -pedantic-errors -std=c++11 -lm -o $@

all: $(OBJCpp)
