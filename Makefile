CXX = g++

SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BIN_DIR = build

TARGET = $(BIN_DIR)/hexgram.exe

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files go into build/
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

INCLUDES = -I$(INC_DIR) -I$(SRC_DIR)

LIBPATH = -L$(LIB_DIR)
LIBS = -lraylib -lrlImgui

CXXFLAGS = -Wall -std=c++17 $(INCLUDES)
LDFLAGS = $(LIBPATH) $(LIBS)

all: $(TARGET) copydll

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files into build/*.o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

copydll:
	copy /Y "$(LIB_DIR)\*.dll" "$(BIN_DIR)\"

clean:
	del /Q "$(BIN_DIR)\*.o"
	del /Q "$(BIN_DIR)\*.exe"
	del /Q "$(BIN_DIR)\*.dll"

run: all
	.\build\hexgram.exe

.PHONY: all clean copydll run