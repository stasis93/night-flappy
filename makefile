#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = -I%SFML_DIR%\\include
CFLAGS = -Wall -std=c++14 -fexceptions
RESINC = 
LIBDIR = -L%SFML_DIR%\\lib
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC) -Iinclude
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB) -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG = 
OUT_DEBUG = bin\\Debug\\jump-sfml.exe

INC_RELEASE = $(INC) -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB) -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE = 
OUT_RELEASE = bin\\Release\\jump-sfml.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\src\\random.o $(OBJDIR_DEBUG)\\src\\Wall.o $(OBJDIR_DEBUG)\\src\\StateManager.o $(OBJDIR_DEBUG)\\src\\PlayingState.o $(OBJDIR_DEBUG)\\src\\Player.o $(OBJDIR_DEBUG)\\src\\PauseState.o $(OBJDIR_DEBUG)\\src\\BackgroundRenderer.o $(OBJDIR_DEBUG)\\src\\Application.o $(OBJDIR_DEBUG)\\main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\src\\random.o $(OBJDIR_RELEASE)\\src\\Wall.o $(OBJDIR_RELEASE)\\src\\StateManager.o $(OBJDIR_RELEASE)\\src\\PlayingState.o $(OBJDIR_RELEASE)\\src\\Player.o $(OBJDIR_RELEASE)\\src\\PauseState.o $(OBJDIR_RELEASE)\\src\\BackgroundRenderer.o $(OBJDIR_RELEASE)\\src\\Application.o $(OBJDIR_RELEASE)\\main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG)\\src md $(OBJDIR_DEBUG)\\src
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\src\\random.o: src\\random.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\random.cpp -o $(OBJDIR_DEBUG)\\src\\random.o

$(OBJDIR_DEBUG)\\src\\Wall.o: src\\Wall.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Wall.cpp -o $(OBJDIR_DEBUG)\\src\\Wall.o

$(OBJDIR_DEBUG)\\src\\StateManager.o: src\\StateManager.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\StateManager.cpp -o $(OBJDIR_DEBUG)\\src\\StateManager.o

$(OBJDIR_DEBUG)\\src\\PlayingState.o: src\\PlayingState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\PlayingState.cpp -o $(OBJDIR_DEBUG)\\src\\PlayingState.o

$(OBJDIR_DEBUG)\\src\\Player.o: src\\Player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Player.cpp -o $(OBJDIR_DEBUG)\\src\\Player.o

$(OBJDIR_DEBUG)\\src\\PauseState.o: src\\PauseState.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\PauseState.cpp -o $(OBJDIR_DEBUG)\\src\\PauseState.o

$(OBJDIR_DEBUG)\\src\\BackgroundRenderer.o: src\\BackgroundRenderer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\BackgroundRenderer.cpp -o $(OBJDIR_DEBUG)\\src\\BackgroundRenderer.o

$(OBJDIR_DEBUG)\\src\\Application.o: src\\Application.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Application.cpp -o $(OBJDIR_DEBUG)\\src\\Application.o

$(OBJDIR_DEBUG)\\main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)\\main.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)\\src
	cmd /c rd $(OBJDIR_DEBUG)

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE)\\src md $(OBJDIR_RELEASE)\\src
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\src\\random.o: src\\random.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\random.cpp -o $(OBJDIR_RELEASE)\\src\\random.o

$(OBJDIR_RELEASE)\\src\\Wall.o: src\\Wall.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Wall.cpp -o $(OBJDIR_RELEASE)\\src\\Wall.o

$(OBJDIR_RELEASE)\\src\\StateManager.o: src\\StateManager.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\StateManager.cpp -o $(OBJDIR_RELEASE)\\src\\StateManager.o

$(OBJDIR_RELEASE)\\src\\PlayingState.o: src\\PlayingState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\PlayingState.cpp -o $(OBJDIR_RELEASE)\\src\\PlayingState.o

$(OBJDIR_RELEASE)\\src\\Player.o: src\\Player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Player.cpp -o $(OBJDIR_RELEASE)\\src\\Player.o

$(OBJDIR_RELEASE)\\src\\PauseState.o: src\\PauseState.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\PauseState.cpp -o $(OBJDIR_RELEASE)\\src\\PauseState.o

$(OBJDIR_RELEASE)\\src\\BackgroundRenderer.o: src\\BackgroundRenderer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\BackgroundRenderer.cpp -o $(OBJDIR_RELEASE)\\src\\BackgroundRenderer.o

$(OBJDIR_RELEASE)\\src\\Application.o: src\\Application.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Application.cpp -o $(OBJDIR_RELEASE)\\src\\Application.o

$(OBJDIR_RELEASE)\\main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)\\main.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)\\src
	cmd /c rd $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

