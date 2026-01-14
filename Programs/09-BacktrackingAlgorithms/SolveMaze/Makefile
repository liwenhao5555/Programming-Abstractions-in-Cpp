# Makefile for 09-BacktrackingAlgorithms/programs/SolveMaze
#****************************************************************

PROGRAMS = \
    SolveMaze

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

SolveMaze: SolveMaze.o maze.o
	g++ $(LDOPTIONS) -o SolveMaze SolveMaze.o maze.o $(LIB)

SolveMaze.o: SolveMaze.cpp maze.h
	g++ $(CPPOPTIONS) -c SolveMaze.cpp

maze.o: maze.cpp maze.h
	g++ $(CPPOPTIONS) -c maze.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
