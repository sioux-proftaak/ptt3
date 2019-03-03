# In this directory, type one of the following:
#   make
#   make all

# Name of your executable
# If you are building a library without test-app (recommended, if
# you test everything automatically), then remove all references to
# EXEC, SOURCES_EXE and OBJECTS_EXE from this Makefile
EXEC = calculator

# -I directives for the directories of your include files
INCLUDE_LOCATIONS = -I. -I../library/inc

# -L directives for the locations of your libraries
LIBRARY_LOCATIONS = -L../library/src

# -l directives for the libaries you need (leave out the lib and the .a parts)
LINKED_LIBRARIES = -lcalculator

# Name of your sources
SOURCES_EXE = $(wildcard *.cpp)

#Don't change these
CXX = g++
CXXFLAGS += -ggdb3 -Wall -Wextra
CPPFLAGS += -D_REENTRANT -DDEBUG $(INCLUDE_LOCATIONS)
OBJECTS_EXE = $(SOURCES_EXE:.cpp=.o)
DEPENDENCY_FILES = $(addprefix .,$(OBJECTS_EXE:.o=.d))

LDFLAGS = -pthread $(LIBRARY_LOCATIONS)

all: $(EXEC)

# Tell make to include the dependency information for your cpp files,
# if they exist, and if we are not executing "clean".
#
# Using dependency information, if you edit a .h file, all relevant
# .cpp files will be rebuilt.
ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEPENDENCY_FILES)
endif

# Tells make how to compile a single source file, and to generate
# dependency information for it.
%.o:%.cpp Makefile
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ -MD -MP -MF .$*.d

# Create your exe
$(EXEC): $(OBJECTS_EXE)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LINKED_LIBRARIES)

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS_EXE) $(DEPENDENCY_FILES)

.PHONY: clean all
