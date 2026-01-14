# Makefile for 07-IntroductionToRecursion/programs/Palindrome1
#****************************************************************

PROGRAMS = \
    Palindrome

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

Palindrome: Palindrome.o
	g++ $(LDOPTIONS) -o Palindrome Palindrome.o $(LIB)

Palindrome.o: Palindrome.cpp
	g++ $(CPPOPTIONS) -c Palindrome.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
