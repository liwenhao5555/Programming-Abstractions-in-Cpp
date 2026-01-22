# Makefile for 06-DesigningClasses/programs/TokenScannerClass
#****************************************************************

PROGRAMS = \
    TestTokenScanner

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestTokenScanner: TestTokenScanner.o tokenscanner.o
	g++ $(LDOPTIONS) -o TestTokenScanner TestTokenScanner.o tokenscanner.o $(LIB)

TestTokenScanner.o: TestTokenScanner.cpp tokenscanner.h
	g++ $(CPPOPTIONS) -c TestTokenScanner.cpp

tokenscanner.o: tokenscanner.cpp tokenscanner.h
	g++ $(CPPOPTIONS) -c tokenscanner.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
