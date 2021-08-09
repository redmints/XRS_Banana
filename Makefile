MKDIR_P = mkdir -p
OUT_DIR = out
SRC_DIR = src
BINARY = banana

.PHONY: directories

all: directories build docu
binary: directories build

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}
build:
	g++ -std=c++11 -c ${SRC_DIR}/Utils.cpp -o ${OUT_DIR}/Utils.o
	g++ -std=c++11 -c ${SRC_DIR}/controllers/accueil.cpp -o ${OUT_DIR}/accueil.o
	g++ -std=c++11 -L/usr/local/Cellar/openssl@1.1/1.1.1k/lib/ -lpthread -lcrypto -g -Wall -o ${OUT_DIR}/${BINARY} ${OUT_DIR}/*.o ${SRC_DIR}/main.cpp
docu:
	doxygen doc/Doxyfile; \
	make -C doc/latex/;
clean:
	$(RM) -rf ${OUT_DIR}/*
	$(RM) -rf ${SRC_DIR}/*.gch
	$(RM) -rf doc/latex
