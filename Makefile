###############################################################################
#                                                                             #
#                                SPACE INVADERS                               #
#                                                                             #
#                                   MAKEFILE                                  #
#                                                                             #
###############################################################################
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
#                                                                             #
###############################################################################
#                                    BASICS                                   #
###############################################################################
CXX       :=  g++
CXXFLAGS  :=  -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -lcurses
TARGET    :=  hendrvan
###############################################################################

###############################################################################
#                                  EXTENSIONS                                 #
###############################################################################
SRCEXT    :=  cpp
HDREXT    :=  hpp
###############################################################################

###############################################################################
#                                 DIRECTORIES                                 #
###############################################################################
SRCDIR    :=  src
BUILDDIR  :=  build
DATADIR   :=  data
###############################################################################

###############################################################################
#                                  FIND FILES                                 #
###############################################################################
SOURCES   :=  $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS   :=  $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
HEADERS   :=  $(shell find $(SRCDIR) -type f -name *.$(HDREXT))
###############################################################################

###############################################################################
#                                    COLORS                                   #
###############################################################################
YELLOW    :=  \033[1;33m
YELLOWT   :=  \033[0;33m
RED       :=  \033[1;31m
GREEN     :=  \033[1;32m
GREENT    :=  \033[0;32m
NOCOL     :=  \033[0m
###############################################################################

.PHONY : all clean run compile doc

all: $(BUILDDIR) $(OBJECTS) $(TARGET)

###############################################################################
#                                    TARGET                                   #
###############################################################################
$(TARGET): $(DATADIR) $(BUILDDIR) $(OBJECTS)
	@echo -e "\n$(GREEN)Linking ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
###############################################################################

###############################################################################
#                                 OBJECT FILES                                #
###############################################################################
$(BUILDDIR)/view.o: $(SRCDIR)/view.$(SRCEXT) $(BUILDDIR)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object.o: $(SRCDIR)/object.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/main.o: $(SRCDIR)/main.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/globals.o: $(SRCDIR)/globals.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr.o: $(SRCDIR)/scr.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_list.o: $(SRCDIR)/scr_list.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_quit.o: $(SRCDIR)/scr_quit.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_menu.o: $(SRCDIR)/scr_menu.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_game.o: $(SRCDIR)/scr_game.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_settings.o: $(SRCDIR)/scr_settings.$(SRCEXT)
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"
###############################################################################

###############################################################################
#                                 DIRECTORIES                                 #
###############################################################################
$(BUILDDIR):
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(DATADIR):
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

###############################################################################

###############################################################################
#                                  UTILITIES                                  #
###############################################################################
clean:
	@echo -e "\n$(RED)Cleaning ...$(NOCOL)"
	rm -rf $(BUILDDIR) $(TARGET) doc

run: $(TARGET)
	./$<

compile: $(TARGET)

doc:
	doxygen
###############################################################################
