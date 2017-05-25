###############################################################################
#                                                                             #
#                               SPACE INVADERS                                #
#                                                                             #
#                                  MAKEFILE                                   #
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
#                                   BASICS                                    #
###############################################################################
CXX       :=  g++
CXXFLAGS  :=  -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb `pkg-config --libs ncurses`
TARGET    :=  hendrvan

.PHONY : all clean run compile doc

all: $(BUILDDIR) $(OBJECTS) $(TARGET)
###############################################################################

###############################################################################
#                                   COLORS                                    #
###############################################################################
YELLOW    :=  \033[1;33m
YELLOWT   :=  \033[0;33m
RED       :=  \033[1;31m
GREEN     :=  \033[1;32m
GREENT    :=  \033[0;32m
NOCOL     :=  \033[0m
###############################################################################

###############################################################################
#                                 DIRECTORIES                                 #
###############################################################################
SRCDIR    :=  src
BUILDDIR  :=  build
DATADIR   :=  data

$(BUILDDIR):
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(DATADIR):
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/scr:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/object:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@
###############################################################################

###############################################################################
#                                    FILES                                    #
###############################################################################
SOURCES   :=  $(SRCDIR)/scr/scr.cpp $(SRCDIR)/scr/scr_quit.cpp $(SRCDIR)/scr/scr_settings.cpp $(SRCDIR)/scr/scr_game.cpp $(SRCDIR)/scr/scr_list.cpp $(SRCDIR)/scr/scr_hiscore.cpp $(SRCDIR)/scr/scr_menu.cpp $(SRCDIR)/object/object.cpp $(SRCDIR)/view.cpp $(SRCDIR)/main.cpp $(SRCDIR)/globals.cpp 

OBJECTS   :=  $(BUILDDIR)/scr/scr.o $(BUILDDIR)/scr/scr_quit.o $(BUILDDIR)/scr/scr_settings.o $(BUILDDIR)/scr/scr_game.o $(BUILDDIR)/scr/scr_list.o $(BUILDDIR)/scr/scr_hiscore.o $(BUILDDIR)/scr/scr_menu.o $(BUILDDIR)/object/object.o $(BUILDDIR)/view.o $(BUILDDIR)/main.o $(BUILDDIR)/globals.o 
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

###############################################################################
#                                   TARGET                                    #
###############################################################################
$(TARGET): $(BUILDDIR) $(DATADIR) $(BUILDDIR)/scr $(BUILDDIR)/object $(OBJECTS)
	@echo -e "\n$(GREEN)Linking ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
###############################################################################

###############################################################################
#                                OBJECT FILES                                 #
###############################################################################

$(BUILDDIR)/scr/scr.o: $(SRCDIR)/scr/scr.cpp $(SRCDIR)/scr/scr.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_quit.o: $(SRCDIR)/scr/scr_quit.cpp $(SRCDIR)/scr/scr_quit.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_settings.o: $(SRCDIR)/scr/scr_settings.cpp $(SRCDIR)/scr/scr_settings.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_game.o: $(SRCDIR)/scr/scr_game.cpp $(SRCDIR)/scr/scr_game.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_list.o: $(SRCDIR)/scr/scr_list.cpp $(SRCDIR)/scr/scr_list.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_hiscore.o: $(SRCDIR)/scr/scr_hiscore.cpp $(SRCDIR)/scr/scr_hiscore.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr/scr_menu.o: $(SRCDIR)/scr/scr_menu.cpp $(SRCDIR)/scr/scr_menu.h $(BUILDDIR)/main.o $(BUILDDIR)/scr/scr.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/object.o: $(SRCDIR)/object/object.cpp $(SRCDIR)/object/object.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/view.o: $(SRCDIR)/view.cpp $(SRCDIR)/view.h $(BUILDDIR)/scr/scr.o $(BUILDDIR)/scr/scr_game.o $(BUILDDIR)/scr/scr_hiscore.o $(BUILDDIR)/scr/scr_menu.o $(BUILDDIR)/scr/scr_quit.o $(BUILDDIR)/scr/scr_settings.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/globals.o: $(SRCDIR)/globals.cpp $(SRCDIR)/globals.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"
###############################################################################

