.PHONY: clean install uninstall

CXX		= g++ 
CXXFLAGS= -std=gnu++1z -O2 -pg

VPATH	= src
PREFIX	= ~

cpps 	= fit hist mean
shs		= loglog plot

targets	= $(cpps) $(shs)

all: $(targets)

$(cpps): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(shs): %: %.sh
	cp $< $@


install:
	mkdir -p $(PREFIX)/bin
	cp $(targets) $(PREFIX)/bin/
	

uninstall:
	mkdir -p $(PREFIX)/bin
	rm -f $(PREFIX)/bin/$(targets)


clean:
	rm -f $(targets)
