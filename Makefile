MKDIR_P = mkdir -p
OUT_DIR = out
SRC_DIR = src
BINARY = banana

.PHONY: directories

all: directories build docu

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}
build:
	g++ -c ${SRC_DIR}/Utils.cpp -o ${OUT_DIR}/Utils.o
	g++ -c ${SRC_DIR}/docker/Image.cpp -o ${OUT_DIR}/Image.o
	g++ -c ${SRC_DIR}/docker/Container.cpp -o ${OUT_DIR}/Container.o
	g++ -c ${SRC_DIR}/docker/Docker.cpp -o ${OUT_DIR}/Docker.o
	g++ -std=c++14 -g -Wall -o ${OUT_DIR}/${BINARY} ${OUT_DIR}/*.o ${SRC_DIR}/main.cpp
docu:
	doxygen doc/Doxyfile; \
	make -C doc/latex/;
clean:
	$(RM) -rf ${OUT_DIR}/*
	$(RM) -rf ${SRC_DIR}/*.gch
	$(RM) -rf doc/latex
