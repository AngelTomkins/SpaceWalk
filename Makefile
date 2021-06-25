CFLAGS = -std=c++20 -I. `sdl2-config --libs --cflags`

TARGET = a.out
$(TARGET): *.cpp *.hpp
		g++ $(CFLAGS) -o $(TARGET) *.cpp $(LDFLAGS)
		
test: ./a.out
	./a.out