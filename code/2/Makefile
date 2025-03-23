
# Enter here BIN-name and sources #
BIN     = kraftsport
SOURCE  = $(wildcard *.cpp)
###################################

OBJF    = $(SOURCE:%.cpp=%.o)
DEPFILE = deps.d
LFLAGS  =           
CFLAGS  = -O2 -Wall -std=c++17

# Platform configuration
PLATFORM = $(shell uname)
ifeq ($(PLATFORM), Win)
	TARGET = $(BIN).exe
else 
	TARGET = $(BIN).out
endif

all: $(BIN)

-include $(DEPFILE)

$(DEPFILE): $(SOURCE)
	$(CXX) -MM $(CFLAGS) $(SOURCE) > $(DEPFILE)	

$(BIN): $(OBJF)
	$(CXX) $(LFLAGS) $(OBJF) -o $(TARGET) 

clean:
	rm -f $(OBJF) $(TARGET) $(DEPFILE)

.cpp.o: 
	$(CXX) $(CFLAGS) -c $< -o $@