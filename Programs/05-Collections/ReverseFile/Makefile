# Makefile for 05-Collections/programs/ReverseFile
#****************************************************************

PROGRAMS = \
    ReverseFile

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

ReverseFile: ReverseFile.o
	g++ $(LDOPTIONS) -o ReverseFile ReverseFile.o $(LIB)

ReverseFile.o: ReverseFile.cpp filelib.h
	g++ $(CPPOPTIONS) -c ReverseFile.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
