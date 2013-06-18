#=======================================#
#    Parameters to provide              #
#=======================================#
# Compiler
CXX=g++

# Build : debug or optimized
Build=debug

#=======================================#
#=======================================#

#======== Compiler flags =============
CXXFLAGS_optimized=  -O3 -Wall  -Wextra -Wshadow
CXXFLAGS_debug=  -g -pg  -Wall  -Wextra -Wshadow

CXXFLAGS= $(CXXFLAGS_$(Build))

OUT_CODE=SIRoptimize
SRC= $(shell ls *.cpp)
LIB=  $(shell ls *.h)  
OBJ=$(SRC:.cpp=.o)

DATE=$(shell date +%D | sed "s./..g")

all:	$(OUT_CODE)

$(OUT_CODE):$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)  -lstdc++ -lm

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ -c $(@:.o=.cpp) 

tar:
	tar cvfz $(OUT_CODE)_sources_$(DATE).tar.gz $(SRC) $(LIB)  $(OUT_CODE)_sources_$(DATE).ps Makefile

clean:
	rm -f  $(OBJ)

ps:
	enscript --pretty-print --color --fancy-header -r -2 -p $(OUT_CODE)_sources_$(DATE).ps $(LIB) $(SRC)
