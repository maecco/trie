# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Debug flags
DEBUG_FLAGS = -g

# Object directory
OBJDIR = obj/

# Executable
TARGET = program

# Default rule
all: $(OBJDIR) $(TARGET)

# Debug rule
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(OBJDIR) $(TARGET)_debug

# Make object dir
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files for regular build
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o))) $(OBJDIR)main.o

# Object files for debug build
DEBUG_OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=_debug.o))) $(OBJDIR)main_debug.o

# Linking regular build
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Linking debug build
$(TARGET)_debug: $(DEBUG_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling src files for regular build
$(OBJDIR)%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiling src files for debug build
$(OBJDIR)%_debug.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiling main.cpp for regular build
$(OBJDIR)main.o: main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiling main.cpp for debug build
$(OBJDIR)main_debug.o: main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJDIR) $(TARGET) $(TARGET)_debug

# Phony
.PHONY: all clean debug
