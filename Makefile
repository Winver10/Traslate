# Makefile for Traslate - Cross-platform To-Do List Manager

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = traslate
SOURCES = Source.cpp comandProcesser.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

install:
	cp $(TARGET) /usr/local/bin/

.PHONY: clean install