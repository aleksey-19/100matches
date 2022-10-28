TARGET = Matches
CC = g++
CFLAGS = -g -w -Wall

PREF_SRC = ./100matches/
PREF_BUILD = ./Build/

TEST_MAKEFILE = ./Tests/

SRC = $(wildcard ${PREF_SRC}*.cpp)
OBJ = $(patsubst ${PREF_SRC}%.cpp, ${PREF_BUILD}%.o, ${SRC})

default : all

all : ${TARGET} test

${TARGET} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${TARGET}

${PREF_BUILD}%.o : ${PREF_SRC}%.cpp
	${CC} -c $< -o $@

clean :
	rm ${TARGET} ${PREF_BUILD}*.o
	rm ${TARGET_TEST} ${PREF_BUILD}test/*.o

test :
	cd Tests && make ${TARGET_TEST}

-include ${TEST_MAKEFILE}Makefile