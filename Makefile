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
CXXFLAGS  :=  -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -lncursesw
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
###############################################################################

###############################################################################
#                                    FILES                                    #
###############################################################################
SOURCES   :=  $(SRCDIR)/scr.cpp$(SRCDIR)/scr_quit.cpp$(SRCDIR)/scr_settings.cpp$(SRCDIR)/view.cpp$(SRCDIR)/scr_game.cpp$(SRCDIR)/scr_list.cpp$(SRCDIR)/scr_hiscore.cpp$(SRCDIR)/main.cpp$(SRCDIR)/object.cpp$(SRCDIR)/scr_menu.cpp$(SRCDIR)/globals.cpp

OBJECTS   :=  $(BUILDDIR)/scr.o $(BUILDDIR)/scr_quit.o $(BUILDDIR)/scr_settings.o $(BUILDDIR)/view.o $(BUILDDIR)/scr_game.o $(BUILDDIR)/scr_list.o $(BUILDDIR)/scr_hiscore.o $(BUILDDIR)/main.o $(BUILDDIR)/object.o $(BUILDDIR)/scr_menu.o $(BUILDDIR)/globals.o
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
$(TARGET): $(DATADIR) $(BUILDDIR) $(OBJECTS)
	@echo -e "\n$(GREEN)Linking ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)
###############################################################################

###############################################################################
#                                OBJECT FILES                                 #
###############################################################################

$(BUILDDIR)/scr.o: $(SRCDIR)/scr.cpp $(SRCDIR)/scr.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_quit.o: $(SRCDIR)/scr_quit.cpp $(SRCDIR)/scr_quit.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_settings.o: $(SRCDIR)/scr_settings.cpp $(SRCDIR)/scr_settings.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/view.o: $(SRCDIR)/view.cpp $(SRCDIR)/view.h $(BUILDDIR)/scr.o $(BUILDDIR)/scr_menu.o $(BUILDDIR)/scr_hiscore.o $(BUILDDIR)/scr_settings.o $(BUILDDIR)/scr_quit.o $(BUILDDIR)/scr_game.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_game.o: $(SRCDIR)/scr_game.cpp $(SRCDIR)/scr_game.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_list.o: $(SRCDIR)/scr_list.cpp $(SRCDIR)/scr_list.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_hiscore.o: $(SRCDIR)/scr_hiscore.cpp $(SRCDIR)/scr_hiscore.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object.o: $(SRCDIR)/object.cpp $(SRCDIR)/object.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/scr_menu.o: $(SRCDIR)/scr_menu.cpp $(SRCDIR)/scr_menu.h $(BUILDDIR)/scr.o $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/globals.o: $(SRCDIR)/globals.cpp $(SRCDIR)/globals.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"
###############################################################################

