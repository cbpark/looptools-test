CXXFLAGS := -g -O2 -Wall -Wextra
LDFLAGS  :=
RM       := rm -f

EXE := simple_test higgs_self_energy

# LoopTools
LT       := /usr
CXX      := $(LT)/bin/f++
CXXFLAGS += -I$(LT)/include
LDFLAGS  += -L$(LT)/lib -looptools

.PHONY: all clean

all: $(EXE)

%: %.o
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean::
	$(RM) $(EXE)
