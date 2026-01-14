# Makefile for 04-Streams/programs/ShowFileContents3
#****************************************************************

PROGRAMS = \
    ShowFileContents

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

ShowFileContents: ShowFileContents.o
	g++ $(LDOPTIONS) -o ShowFileContents ShowFileContents.o $(LIB)

ShowFileContents.o: ShowFileContents.cpp
	g++ $(CPPOPTIONS) -c ShowFileContents.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
