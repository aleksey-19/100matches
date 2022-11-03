TARGET = Matches
CC = g++
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

PREF_BIN = ./bin/

PREF_BUILD = ./obj/
PREF_BUILD_PROJ = ${PREF_BUILD}src/proj/
PREF_BUILD_LIBPROJ = ${PREF_BUILD}src/libproj/

PREF_SRC = ./src/
PREF_SRC_PROJ = ${PREF_SRC}proj/
PREF_SRC_LIBPROJ = ${PREF_SRC}libproj/

#################################################
TESTCFLAGS = -g -w -Wall

TARGET_TEST = test_unit

PREF_SRC_TEST = ./test/

PREF_TEST_BUILD_TEST = ${PREF_BUILD}test/
PREF_TEST_BUILD_SRC_LIBPROJ = ${PREF_BUILD}src/libproj/


default : all

all : ${TARGET} test

${TARGET} : ${PREF_BUILD_PROJ}main.o ${PREF_BUILD_LIBPROJ}libproj.a
	${CC} ${CFLAGS} -o ${PREF_BIN}$@ $^

${PREF_BUILD_PROJ}main.o : ${PREF_SRC_PROJ}main.cpp
	${CC} -c ${CFLAGS} ${CPPFLAGS} -o $@ $<

${PREF_BUILD_LIBPROJ}game.o : ${PREF_SRC_LIBPROJ}game.cpp
	${CC} -c ${CFLAGS} ${CPPFLAGS} -o $@ $<

${PREF_BUILD_LIBPROJ}Start.o : ${PREF_SRC_LIBPROJ}Start.cpp
	${CC} -c ${CFLAGS} ${CPPFLAGS} -o $@ $<

${PREF_BUILD_LIBPROJ}libproj.a : ${PREF_BUILD_LIBPROJ}game.o ${PREF_BUILD_LIBPROJ}Start.o
	ar rcs $@ $^

clean :
	rm ${PREF_BIN}${TARGET} ${PREF_BIN}${TARGET_TEST} ${PREF_BUILD_LIBPROJ}*.* ${PREF_BUILD_PROJ}*.*

####################################

test : ${TARGET_TEST}

${TARGET_TEST} : ${PREF_TEST_BUILD_TEST}test.o ${PREF_TEST_BUILD_SRC_LIBPROJ}libproj.a
	${CC} ${TESTCFLAGS} -o ${PREF_BIN}$@ $^

${PREF_TEST_BUILD_TEST}test.o : ${PREF_SRC_TEST}test.cpp
	${CC} -c ${TESTCFLAGS} -o $@ $<
