# Makefile for 20-StrategiesForIteration/programs/CountNegative
#****************************************************************

PROGRAMS = \
    CountNegative

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

CountNegative: CountNegative.o
	g++ $(LDOPTIONS) -o CountNegative CountNegative.o $(LIB)

CountNegative.o: CountNegative.cpp
	g++ $(CPPOPTIONS) -c CountNegative.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
