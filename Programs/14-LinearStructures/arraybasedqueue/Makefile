# Makefile for 14-LinearStructures/programs/ArrayBasedQueue
#****************************************************************

PROGRAMS = \
    TestQueue

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

TestQueue: TestQueue.o
	g++ $(LDOPTIONS) -o TestQueue TestQueue.o $(LIB)

TestQueue.o: TestQueue.cpp queue.h
	g++ $(CPPOPTIONS) -c TestQueue.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
