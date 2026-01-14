# Makefile for 12-DynamicMemoryManagement/programs/CharStackSimplified
#****************************************************************

PROGRAMS = \
    CharStackUnitTest \
    ReverseAlphabet

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

CharStackUnitTest: CharStackUnitTest.o charstack.o
	g++ $(LDOPTIONS) -o CharStackUnitTest CharStackUnitTest.o charstack.o $(LIB)

ReverseAlphabet: ReverseAlphabet.o charstack.o
	g++ $(LDOPTIONS) -o ReverseAlphabet ReverseAlphabet.o charstack.o $(LIB)

CharStackUnitTest.o: CharStackUnitTest.cpp charstack.h
	g++ $(CPPOPTIONS) -c CharStackUnitTest.cpp

ReverseAlphabet.o: ReverseAlphabet.cpp charstack.h
	g++ $(CPPOPTIONS) -c ReverseAlphabet.cpp

charstack.o: charstack.cpp charstack.h
	g++ $(CPPOPTIONS) -c charstack.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
