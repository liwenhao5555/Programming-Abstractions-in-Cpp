# Makefile for 19-Inheritance/programs/Interpreter
#****************************************************************

PROGRAMS = \
    Interpreter

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

Interpreter: Interpreter.o exp.o parser.o
	g++ $(LDOPTIONS) -o Interpreter Interpreter.o exp.o parser.o $(LIB)

Interpreter.o: Interpreter.cpp exp.h parser.h
	g++ $(CPPOPTIONS) -c Interpreter.cpp

exp.o: exp.cpp exp.h
	g++ $(CPPOPTIONS) -c exp.cpp

parser.o: parser.cpp exp.h parser.h
	g++ $(CPPOPTIONS) -c parser.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
