# Makefile for 16-Trees/programs/AVLTree
#****************************************************************

PROGRAMS = \
    AVLTreeTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

AVLTreeTest: AVLTreeTest.o avltree.o
	g++ $(LDOPTIONS) -o AVLTreeTest AVLTreeTest.o avltree.o $(LIB)

AVLTreeTest.o: AVLTreeTest.cpp avltree.h
	g++ $(CPPOPTIONS) -c AVLTreeTest.cpp

avltree.o: avltree.cpp avltree.h
	g++ $(CPPOPTIONS) -c avltree.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
