.PHONY: clean install uninstall

CXX		= g++ 
CXXFLAGS= -std=gnu++1z -O2
CXXLIBS	= -lgsl -lgslcblas

VPATH	= src
PREFIX	= ~

cpps 	= fit histo mean
shs		= loglog plot
gos		= png2rgba rgba2png


targets	= $(cpps) $(shs) $(gos)

all: $(targets)


$(cpps): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(CXXLIBS)

$(shs): %: %.sh
	cp $< $@

$(gos): %: %.go
	go build -o $@ $<


install:
	mkdir -p $(PREFIX)/bin
	cp $(targets) $(PREFIX)/bin/

uninstall:
	mkdir -p $(PREFIX)/bin
	rm -f $(PREFIX)/bin/$(targets)


clean:
	rm -f $(targets)
