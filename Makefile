# Makefile

# Define the C++ compiler
CXX = g++
CFLAGS := -g # -Wall
LIB :=-L lib
INC :=-I include

# Define the source directories

SRCDIR := src
BUILDDIR := build

SRCEXTS := c cpp cxx

SRCDIRS =  $(foreach ext, $(SRCEXTS), $(shell find $(SRCDIR) -name '*.$(ext)' -exec dirname {} \; | sort | uniq))
SOURCES := $(foreach ext, $(SRCEXTS), $(shell find $(SRCDIR) -type f -name *.$(ext)))

# Define the object files
OBJDIRS := $(patsubst $(SRCDIR)%,$(BUILDDIR)%,$(SRCDIRS))
OBJECTS := $(foreach ext, $(SRCEXTS), $(shell find $(SRCDIR) -type f -name '*.$(ext)' | sed 's/$(SRCDIR)/$(BUILDDIR)/' | sed 's/$(ext)/o/'))

# Define the executable file
TARGET := bin/hotel
 
# All rule
all: $(TARGET)

# Compile make rule
define compile-rule
${2}: ${1}
	@echo "Compiling ${1}"
	@mkdir -p $(dir ${2})
	$(CXX) $(CFLAGS) $(INC) -c ${1} -o ${2}
endef

SRCOBJ  := $(join $(addsuffix :,$(SOURCES)),$(OBJECTS))
GET_SRC  = $(word 1,$(subst :, ,$1))
GET_OBJ = $(word 2,$(subst :, ,$1))
$(foreach j,$(SRCOBJ),$(eval $(call compile-rule, $(call GET_SRC,$j), $(call GET_OBJ,$j)))) 

# Link rule
$(TARGET): $(OBJECTS)
	@echo " $(CXX) $^ -o $(TARGET) $(LIB)"; $(CXX) $^ $(LIB) -o $(TARGET)

# Clean rule
clean:
	rm -f $(OBJECTS) $(TARGET)

list:
	@echo "SRCDIRS :: $(SRCDIRS)"
	@echo "SOURCES :: $(SOURCES)"
	@echo "OBJDIRS :: $(OBJDIRS)"
	@echo "OBJECTS :: $(OBJECTS)"
	@echo "SRCOBJ :: $(SRCOBJ)"
