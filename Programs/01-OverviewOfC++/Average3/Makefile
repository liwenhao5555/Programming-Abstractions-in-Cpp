# Makefile for 01-OverviewOfC++/programs/Average3
#****************************************************************

PROGRAMS = \
    Average3

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

Average3: Average3.o
	g++ $(LDOPTIONS) -o Average3 Average3.o $(LIB)

Average3.o: Average3.cpp
	g++ $(CPPOPTIONS) -c Average3.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
