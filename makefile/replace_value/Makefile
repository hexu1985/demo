
SOURCES = $(shell ls *.cpp)
PROGS = $(subst .cpp,,$(SOURCES))

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	rm -f $(PROGS)

%: %.cpp
	g++ $^ -o $@
