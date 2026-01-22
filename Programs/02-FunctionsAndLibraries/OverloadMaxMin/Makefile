# Makefile for 02-FunctionsAndLibraries/programs/OverloadMaxMin
#****************************************************************

PROGRAMS = \
    OverloadedMaxMin

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

OverloadedMaxMin: OverloadedMaxMin.o maxmin.o
	g++ $(LDOPTIONS) -o OverloadedMaxMin OverloadedMaxMin.o maxmin.o $(LIB)

OverloadedMaxMin.o: OverloadedMaxMin.cpp maxmin.h
	g++ $(CPPOPTIONS) -c OverloadedMaxMin.cpp

maxmin.o: maxmin.cpp maxmin.h
	g++ $(CPPOPTIONS) -c maxmin.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
