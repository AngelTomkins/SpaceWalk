CFLAGS = -std=c++20 -I. `sdl2-config --libs --cflags` -g -Wall

TARGET = a.out
$(TARGET): src/*.cpp src/*.hpp
		g++ $(CFLAGS) -o $(TARGET) src/*.cpp $(LDFLAGS)
		
test: ./a.out
	./a.out
