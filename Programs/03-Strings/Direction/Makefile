# Makefile for 03-Strings/programs/Direction
#****************************************************************

PROGRAMS = \
    TestDirection

ARCH ?= $(shell uname -m)
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestDirection: TestDirection.o
	g++ $(LDOPTIONS) -o TestDirection TestDirection.o $(LIB)

TestDirection.o: TestDirection.cpp
	g++ $(CPPOPTIONS) -c TestDirection.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
