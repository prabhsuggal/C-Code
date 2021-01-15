CC=g++
CFLAGS= -std=c++11 -g -Wall -I.
RM=rm

targets=$(shell for file in `find . -name '*.cpp' -type f -print | sed 's/\.cpp/\.out/'`; do echo "$$file "; done;)

all: $(targets)

%.out: %.cpp
	$(CC) -o $@ $< $(CFLAGS)

clean:
	${RM} $(targets)
