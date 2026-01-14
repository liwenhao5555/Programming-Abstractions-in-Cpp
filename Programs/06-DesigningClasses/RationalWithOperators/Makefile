# Makefile for 06-DesigningClasses/programs/RationalWithOperators
#****************************************************************

PROGRAMS = \
    RationalTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

RationalTest: RationalTest.o rational.o
	g++ $(LDOPTIONS) -o RationalTest RationalTest.o rational.o $(LIB)

RationalTest.o: RationalTest.cpp rational.h
	g++ $(CPPOPTIONS) -c RationalTest.cpp

rational.o: rational.cpp rational.h
	g++ $(CPPOPTIONS) -c rational.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
