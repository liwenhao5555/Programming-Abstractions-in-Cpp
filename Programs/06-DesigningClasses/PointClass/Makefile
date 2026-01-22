# Makefile for 06-DesigningClasses/programs/PointClass
#****************************************************************

PROGRAMS = \
    PointTest

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

PointTest: PointTest.o point.o
	g++ $(LDOPTIONS) -o PointTest PointTest.o point.o $(LIB)

PointTest.o: PointTest.cpp point.h
	g++ $(CPPOPTIONS) -c PointTest.cpp

point.o: point.cpp point.h
	g++ $(CPPOPTIONS) -c point.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
