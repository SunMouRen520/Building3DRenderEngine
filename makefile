all:
	g++ main.cpp -o main.app

clean:
	@rm -f main.app *.o
