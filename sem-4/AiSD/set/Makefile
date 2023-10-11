mainfile:=main
CXX:=g++
CXXEXT:=cpp
CXXFLAGS:=-Wall -o
mainfile_exe:=$(mainfile).x

.PHONY: clean

compile: $(mainfile).$(CXXEXT)
	$(CXX) $(mainfile).$(CXXEXT) $(CXXFLAGS) $(mainfile_exe)

run: $(mainfile).$(CXXEXT) $(mainfile_exe)
	./$(mainfile_exe)

go: compile run

clean:
	rm *.x