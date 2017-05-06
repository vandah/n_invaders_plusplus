CXX       :=  g++
CXXFLAGS  :=  -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb
SRCDIR    :=  src
BUILDDIR  :=  build
TARGET    :=  hendrvan
SRCEXT    :=  cpp
HDREXT    :=  hpp
YELLOW    :=  \033[1;33m
YELLOWT   :=  \033[0;33m
RED       :=  \033[1;31m
GREEN     :=  \033[1;32m
NOCOL     :=  \033[0m
SOURCES   :=  $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS   :=  $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
HEADERS   :=  $(shell find $(SRCDIR) -type f -name *.$(HDREXT))

.PHONY : all clean run compile doc

all: $(TARGET) $(OBJECTS)

$(TARGET): $(BUILDDIR) $(BUILDDIR)/main.o
	@echo -e "\n$(GREEN)Linking ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(BUILDDIR)/moving_object.o: $(SRCDIR)/moving_object.%pp $(BUILDDIR)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(BUILDDIR)/player.o: $(BUILDDIR)/moving_object.o $(SRCDIR)/player.%pp
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(BUILDDIR)/invader.o: $(BUILDDIR)/moving_object.o $(SRCDIR)/invader.%pp
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(BUILDDIR)/bonus.o: $(BUILDDIR)/moving_object.o $(SRCDIR)/bonus.%pp
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

$(BUILDDIR):
	@echo -e "\n$(YELLOWT)Creating build directory ...$(NOCOL)"
	mkdir -p $(BUILDDIR)

clean:
	@echo -e "\n$(RED)Cleaning ...$(NOCOL)"
	rm -rf $(BUILDDIR) $(TARGET) doc

run: $(TARGET)
	./$<

compile: $(TARGET)

doc:
	doxygen
