# Makefile for 17-Sets/programs/SetClass
#****************************************************************

PROGRAMS = \
    TestSetClass

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestSetClass: TestSetClass.o
	g++ $(LDOPTIONS) -o TestSetClass TestSetClass.o $(LIB)

TestSetClass.o: TestSetClass.cpp set.h
	g++ $(CPPOPTIONS) -c TestSetClass.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
