# Makefile for 16-Trees/programs/BinarySearchTree
#****************************************************************

PROGRAMS = \
    BSTTest \
    DwarfTree \
    PostorderTraversal \
    PreorderTraversal

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

BSTTest: BSTTest.o bst.o
	g++ $(LDOPTIONS) -o BSTTest BSTTest.o bst.o $(LIB)

DwarfTree: DwarfTree.o bst.o
	g++ $(LDOPTIONS) -o DwarfTree DwarfTree.o bst.o $(LIB)

PostorderTraversal: PostorderTraversal.o bst.o
	g++ $(LDOPTIONS) -o PostorderTraversal PostorderTraversal.o \
                            bst.o $(LIB)

PreorderTraversal: PreorderTraversal.o bst.o
	g++ $(LDOPTIONS) -o PreorderTraversal PreorderTraversal.o bst.o $(LIB)

BSTTest.o: BSTTest.cpp bst.h
	g++ $(CPPOPTIONS) -c BSTTest.cpp

DwarfTree.o: DwarfTree.cpp bst.h
	g++ $(CPPOPTIONS) -c DwarfTree.cpp

PostorderTraversal.o: PostorderTraversal.cpp bst.h
	g++ $(CPPOPTIONS) -c PostorderTraversal.cpp

PreorderTraversal.o: PreorderTraversal.cpp bst.h
	g++ $(CPPOPTIONS) -c PreorderTraversal.cpp

bst.o: bst.cpp bst.h
	g++ $(CPPOPTIONS) -c bst.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
