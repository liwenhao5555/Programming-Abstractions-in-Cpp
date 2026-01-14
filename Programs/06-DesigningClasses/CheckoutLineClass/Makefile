# Makefile for 06-DesigningClasses/programs/CheckoutLineClass
#****************************************************************

PROGRAMS = \
    CheckoutLineClass \
    fum

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

CheckoutLineClass: CheckoutLineClass.o
	g++ $(LDOPTIONS) -o CheckoutLineClass CheckoutLineClass.o $(LIB)

fum: fum.o
	g++ $(LDOPTIONS) -o fum fum.o $(LIB)

CheckoutLineClass.o: CheckoutLineClass.cpp
	g++ $(CPPOPTIONS) -c CheckoutLineClass.cpp

fum.o: fum.cpp
	g++ $(CPPOPTIONS) -c fum.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
