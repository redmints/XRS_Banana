all:
	g++ -c src/Utils.cpp -o out/Utils.o
	g++ -c src/Container.cpp -o out/Container.o
	g++ -g -Wall -o out/genux out/*.o src/main.cpp
clean:
	$(RM) -rf out/*
	$(RM) -rf src/*.gch
