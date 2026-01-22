# Makefile for 05-Collections/programs/CCType
#****************************************************************

PROGRAMS = \
    TestCCType

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestCCType: TestCCType.o cctype.o
	g++ $(LDOPTIONS) -o TestCCType TestCCType.o cctype.o $(LIB)

TestCCType.o: TestCCType.cpp cctype.h
	g++ $(CPPOPTIONS) -c TestCCType.cpp

cctype.o: cctype.cpp cctype.h
	g++ $(CPPOPTIONS) -c cctype.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
