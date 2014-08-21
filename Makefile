# x-thesaurus makefile
# see LICENSE for license fdetails
# see README for help

SRC = src/x-thesaurus.cpp
CC = g++
BIN = x-thesaurus
INSTALLPATH = /usr/local/bin/
CFLAGS = -Wall
LIBS = -L/usr/lib/x86_64-linux-gnu -lcurl

x-thesaurus : ${SRC}
	
	@echo "build ${SRC}"
	@echo "CC ${CFLAGS} ${SRC} ${LIBS}"
	@${CC} ${CFLAGS} ${SRC} ${LIBS} -o ${BIN}

install : ${BIN}
	
	@echo "yippe! x-thesaurus is about enter into your local bin family"
	@cp ${BIN} ${INSTALLPATH}
	@chmod 755 ${INSTALLPATH}${BIN}
	@echo "yippe! please use me everyday"

uninstall : 
	@echo "uninstalling binary-file (${INSTALLPATH}${BIN})"
	@rm -f ${INSTALLPATH}${BIN}
	@echo "uninstalled :`("

clean :
	@echo "cleaning"
	@echo "rm ${BIN}"
	@rm ${BIN}
	@echo "cleaned"
