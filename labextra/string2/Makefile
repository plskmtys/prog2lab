#
# Makefile pelda a string1 feladat (3. labor) megoldasanak forditasara 
# gnumake valtozat
# 	Linuxokon es ural2-n is elerheto
#
# A make paranccsorabol magadott FLG valtozo tartalma atadodik a forditonak
# Pl:
# make FLG=-DRENDEZ
#
PROG = string2_test   # a program neve (ezt allitjuk elo)
PROG_S = string2.cpp string2_test.cpp rendez.cpp  # program forras fajljai 
PROG_H = string2.h rendez.h rendez_u8.h gtest_lite.h   # program header fajljai
PROG_L =              # program libjei

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS += -g # es legyeb debug info is
CXXFLAGS += $(FLG) # es amit a parancsorbol megadnak
LDFLAGS = -g # debug a linkelesnel 

######
# osszes object, osszes header osszes lib
OBJS = $(PROG_S:.cpp=.o)
HEADS = $(PROG_H) 
LIBS = $(PROG_L) 
#

# alapertelmezett cel: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# feltetelezzuk, hogy az osszes obj fugg az osszes headertol
$(OBJS): $(HEADS)

# legeneraljuk a dokumentaciot es belinkeljuk a public_html-be
.PHONY: doc
doc:    $(HOME)/public_html
	doxygen Doxyfile
	ln -s `pwd`/html ~/public_html/string2

# public_html letrehozása
$(HOME)/public_html:
	mkdir ~/public_html

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(OBJSUTF) $(PROG) $(PROGUTF) $(HOME)/public_html/string2
	rm -rf html latex rtf
