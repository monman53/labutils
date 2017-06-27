.PHONY: clean install uninstall

CXX		= g++ 
CXXFLAGS= -std=gnu++1z -O2
CXXLIBS	= -lgsl -lgslcblas

VPATH	= src
PREFIX	= ~

cpps 	= fit histo mean sd se
gos		= png2rgba rgba2png 
shs		= loglog plot


targets	= $(cpps) $(shs) $(gos)

all: $(targets)


$(cpps): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(CXXLIBS)

$(gos): %: %.go
	go build -o $@ $<

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
