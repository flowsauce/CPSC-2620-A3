#the compiler: gcc for C program, defined as g++ for C++
CC = g++ -std=c++11

#compiler flags
#-g adds debugging information to the executable file
#-Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall

#the build target exectuable
TARGET = test_Wordset
WORDSET = Wordset
TEST_WORDSET = test_wordset

all: $(TARGET)

$(TARGET): $(WORDSET).o $(TEST_WORDSET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(WORDSET).o $(TEST_WORDSET).cpp

$(WORDSET).o: $(WORDSET).cpp $(WORDSET).h
	$(CC) $(CFLAGS) -c $(WORDSET).cpp

$(TEST_WORDSET).o: $(WORDSET).cpp $(WORDSET).h
	$(CC) $(CFLAGS) -c $(TEST_WORDSET).cpp

clean:
	$(RM) -f $(TARGET) $(WORDSET).o $(TEST_WORDSET).o
