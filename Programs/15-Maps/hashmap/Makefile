# Makefile for 15-Maps/programs/HashMap
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

PostalLookup: PostalLookup.o hashmap.o
	g++ $(LDOPTIONS) -o PostalLookup PostalLookup.o hashmap.o $(LIB)

PostalLookup.o: PostalLookup.cpp hashmap.h
	g++ $(CPPOPTIONS) -c PostalLookup.cpp

hashmap.o: hashmap.cpp
	g++ $(CPPOPTIONS) -c hashmap.cpp

hashmapimpl.o: hashmapimpl.cpp
	g++ $(CPPOPTIONS) -c hashmapimpl.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
