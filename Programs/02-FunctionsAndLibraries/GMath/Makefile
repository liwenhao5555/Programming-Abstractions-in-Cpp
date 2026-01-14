# Makefile for 02-FunctionsAndLibraries/programs/GMath
#****************************************************************

PROGRAMS = \
    TrigTable

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TrigTable: TrigTable.o gmath.o
	g++ $(LDOPTIONS) -o TrigTable TrigTable.o gmath.o $(LIB)

TrigTable.o: TrigTable.cpp gmath.h
	g++ $(CPPOPTIONS) -c TrigTable.cpp

gmath.o: gmath.cpp gmath.h
	g++ $(CPPOPTIONS) -c gmath.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
