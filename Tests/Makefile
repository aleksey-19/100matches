TARGET_TEST = test_unit
CC = g++
CFLAGS = -g -w -Wall

PREF_PROJ = ../100matches/
PREF_BUILD_BACK = ../Build/
PREF_BUILD_TEST = ${PREF_BUILD_BACK}test/

default :all

all : ${TARGET_TEST}

${TARGET_TEST} : test.o game.o
	${CC} ${CFLAGS} ${PREF_BUILD_TEST}test.o ${PREF_BUILD_TEST}game.o -o ../${TARGET_TEST} 

test.o : test.cpp
	${CC} -c test.cpp -o ${PREF_BUILD_TEST}test.o

game.o : ${PREF_PROJ}game.cpp
	${CC} -c ${PREF_PROJ}game.cpp -o ${PREF_BUILD_TEST}game.o
