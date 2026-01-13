TARGET = mapa
CXX = g++
CXXFLAGS = -Wall -I include -I libs/FastNoiseLite/Cpp
SRCS = test.cpp $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
all: $(TARGET)
$(TARGET) : $(OBJS)
		$(CXX) $(OBJS) -o $(TARGET)
%.o: %.cpp 
		$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
