# Makefile for 15-Maps/programs/StringMapUsingHashing
#****************************************************************

PROGRAMS = \
    PostalLookup

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

PostalLookup: PostalLookup.o stringmap.o
	g++ $(LDOPTIONS) -o PostalLookup PostalLookup.o stringmap.o $(LIB)

PostalLookup.o: PostalLookup.cpp stringmap.h
	g++ $(CPPOPTIONS) -c PostalLookup.cpp

stringmap.o: stringmap.cpp stringmap.h
	g++ $(CPPOPTIONS) -c stringmap.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
