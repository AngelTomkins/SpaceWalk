CFLAGS = -std=c++20 -I. -I include -lSDL2_image -lSDL2 `sdl2-config --libs --cflags` -g -Wall

TARGET = a.out
$(TARGET): src/*.cpp include/*.hpp
		g++ $(CFLAGS) -o $(TARGET) src/*.cpp $(LDFLAGS)
		
test: ./a.out
	./a.out

clean: ./a.out
	rm ./a.out