CXX = g++

SRC_DIR = src
INC_DIR = include
LIB_DIR = lib
BIN_DIR = build

TARGET = $(BIN_DIR)/hexgram.exe

SRCS = $(wildcard $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

INCLUDES = -I$(INC_DIR) -I$(SRC_DIR)

LIBPATH = -L$(LIB_DIR)

LIBS = -lraylib -lrlImgui

CXXFLAGS = -Wall -std=c++17 $(INCLUDES)

LDFLAGS = $(LIBPATH) $(LIBS)

all: $(TARGET) copydll

$(TARGET): $(OBJS)
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

copydll:
	copy /Y "$(LIB_DIR)\*.dll" "$(BIN_DIR)\"

clean:
	del /Q src\*.o
	del /Q "$(BIN_DIR)\*"

run: all
	.\build\hexgram.exe

.PHONY: all clean copydll