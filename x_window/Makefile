
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
INCLUDES = 
LDFLAGS = -lX11 -lXrandr -lXinerama -lXext -lXtst -lpthread
LDPATH =

SOURCES = $(shell ls *.cpp)
PROGS = $(subst .cpp,,$(SOURCES))
#PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
