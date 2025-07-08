TARGET = Compiler 
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -static-libstdc++

ifeq ($(OS),Windows_NT)  # for windows users xD
	SRCS = $(shell powershell -Command "Get-ChildItem -Recurse -Filter *.cpp | Resolve-Path -Relative")
else
	SRCS = $(shell find . -name '*.cpp' )
endif

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I./include $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I./include -c $< -o $@

clean:
ifeq ($(OS),Windows_NT) # for windows users xD
	del Compiler.exe
else
	rm -f $(OBJS) $(TARGET)
endif
	
	

