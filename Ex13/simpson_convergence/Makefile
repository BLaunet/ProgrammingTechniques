all: convergence.png

clean:
	rm -f *.o convergence.png convergence.dat simpson libintegrate.a

simpson: main.cpp libintegrate.a
	c++ -o $@ -Wall main.cpp -L. -lintegrate

# mskoenz: good job with the lib
libintegrate.a: simpson.cpp simpson.hpp
	c++ -c $<
	ar ruc $@ simpson.o
	ranlib $@

convergence.dat: simpson
	./$^ > $@

convergence.png: convergence.dat
	gnuplot plot.gp

# mskoenz: make a variable INSTAL_DIR = /usr/local and then the three below from this
INSTALL_BIN_DIR = /usr/local/bin
INSTALL_LIB_DIR = /usr/local/lib
INSTALL_INC_DIR = /usr/local/include

install: convergence.png $(INSTALL_BIN_DIR)/plot.gp $(INSTALL_BIN_DIR)/simpson $(INSTALL_LIB_DIR)/libintegrate.a $(INSTALL_INC_DIR)/simpson.hpp

$(INSTALL_BIN_DIR)/plot.gp: plot.gp
	cp $< $@

$(INSTALL_BIN_DIR)/simpson: simpson
	cp $< $@

$(INSTALL_LIB_DIR)/libintegrate.a: libintegrate.a
	cp $< $@

$(INSTALL_INC_DIR)/simpson.hpp: simpson.hpp
	cp $< $@
