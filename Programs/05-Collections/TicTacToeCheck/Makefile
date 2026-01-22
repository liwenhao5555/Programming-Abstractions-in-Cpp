# Makefile for 05-Collections/programs/TicTacToeCheck
#****************************************************************

PROGRAMS = \
    TicTacToeCheck

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TicTacToeCheck: TicTacToeCheck.o
	g++ $(LDOPTIONS) -o TicTacToeCheck TicTacToeCheck.o $(LIB)

TicTacToeCheck.o: TicTacToeCheck.cpp
	g++ $(CPPOPTIONS) -c TicTacToeCheck.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
