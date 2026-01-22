# Makefile for 13-EfficiencyAndRepresentation/programs/ListEditor
#****************************************************************

PROGRAMS = \
    SimpleTextEditor

ARCH = i386
CPPOPTIONS = -IStanfordCPPLib -arch $(ARCH) -fvisibility-inlines-hidden
LDOPTIONS = -LStanfordCPPLib -arch $(ARCH)
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS)

SimpleTextEditor: SimpleTextEditor.o buffer.o
	g++ $(LDOPTIONS) -o SimpleTextEditor SimpleTextEditor.o buffer.o $(LIB)

SimpleTextEditor.o: SimpleTextEditor.cpp buffer.h
	g++ $(CPPOPTIONS) -c SimpleTextEditor.cpp

buffer.o: buffer.cpp buffer.h
	g++ $(CPPOPTIONS) -c buffer.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)
