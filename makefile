
TARGET = Compiler 



ifeq ($(OS),Windows_NT)
	CXX = g++
	CXXFLAGS = -Wall -Wextra -std=c++17 -static-libstdc++
	SRCS = $(shell powershell -Command "Get-ChildItem -Recurse -Filter *.cpp | Resolve-Path -Relative")
  
else
	CXX = g++
	CXXFLAGS = -Wall -Wextra -std=c++17 -static-libstdc++
	SRCS = $(shell find . -name '*.cpp' ) 

endif
INCLUDES = -I./include
OBJS = $(SRCS:.cpp=.o)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del Compiler.exe
else
	rm -f $(OBJS) $(TARGET)
endif
	
	

