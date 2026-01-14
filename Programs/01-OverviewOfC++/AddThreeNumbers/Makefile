# Makefile for 01-OverviewOfC++/programs/AddThreeNumbers
#****************************************************************

PROGRAMS = \
    AddThreeNumbers

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

AddThreeNumbers: AddThreeNumbers.o
	g++ $(LDOPTIONS) -o AddThreeNumbers AddThreeNumbers.o $(LIB)

AddThreeNumbers.o: AddThreeNumbers.cpp
	g++ $(CPPOPTIONS) -c AddThreeNumbers.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
