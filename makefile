
APP=main.app

CXX=g++

SRC+=main.cpp
SRC+=PPMCreater.cpp

OBJS=$(SRC:.cpp=.o)

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

clean:
	@rm -f $(APP) *.o
