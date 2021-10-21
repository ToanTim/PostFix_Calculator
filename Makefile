CC = -std=c++17 -O2 #Version of C++
LDFLAGS = -g -Wall
FILES = main.cpp lib/*.cpp #add files in here
OUTPUT = main
code: $(FILES)
		g++ $(CC) $(FILES) -o $(OUTPUT) $(LDFLAGS) && ./$(OUTPUT)

.PHONY: build test clean
build: $(FILES) # Folder
		g++ $(CC) $(FILES) -o $(OUTPUT)  $(LDFLAGS)

run: $(OUTPUT) #runcode
		./$(OUTPUT)

clean: $(OUTPUT)
		$(RM) $(OUTPUT)
