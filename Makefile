###############################################################################
#                                                                             #
#                                 nInvaders++                                 #
#                                                                             #
#                                  MAKEFILE                                   #
#                                                                             #
###############################################################################
#                                                                             #
#                           < oo> <o o> <oo > <ooo>                           #
#                            <^>   /^\   /|\   <|>                            #
#                            >O<   <o>   _o-   -o_                            #
#                            @-@   <+>   #-#   %^%                            #
#                            /~\   /.\   \~/   \./                            #
#                                                                             #
###############################################################################
#                                   BASICS                                    #
###############################################################################
CXX       :=  g++
CXXFLAGS  :=  -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -lncurses
TARGET    :=  hendrvan
SRCDIR    :=  src
BUILDDIR  :=  build
DATADIR   :=  data

.PHONY : all clean run compile doc

all: $(DATADIR) $(BUILDDIR)/ $(BUILDDIR)/object $(BUILDDIR)/object/bonus $(BUILDDIR)/screen  $(OBJECTS) $(TARGET)
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

$(DATADIR):
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/object:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/object/bonus:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@

$(BUILDDIR)/screen:
	@echo -e "\n$(YELLOWT)Creating $@ directory ...$(NOCOL)"
	@mkdir -p $@
###############################################################################

###############################################################################
#                                    FILES                                    #
###############################################################################
SOURCES   :=  $(SRCDIR)/object/smart.cpp $(SRCDIR)/object/falling.cpp $(SRCDIR)/object/ufo.cpp $(SRCDIR)/object/bonus/bonus.cpp $(SRCDIR)/object/missile.cpp $(SRCDIR)/object/invader.cpp $(SRCDIR)/object/moving.cpp $(SRCDIR)/object/player.cpp $(SRCDIR)/object/object.cpp $(SRCDIR)/view.cpp $(SRCDIR)/screen/screen_base.cpp $(SRCDIR)/screen/scr_quit.cpp $(SRCDIR)/screen/scr_settings.cpp $(SRCDIR)/screen/scr_game.cpp $(SRCDIR)/screen/scr_list.cpp $(SRCDIR)/screen/scr_hiscore.cpp $(SRCDIR)/screen/scr_menu.cpp $(SRCDIR)/main.cpp $(SRCDIR)/globals.cpp 

OBJECTS   :=  $(BUILDDIR)/object/smart.o $(BUILDDIR)/object/falling.o $(BUILDDIR)/object/ufo.o $(BUILDDIR)/object/bonus/bonus.o $(BUILDDIR)/object/missile.o $(BUILDDIR)/object/invader.o $(BUILDDIR)/object/moving.o $(BUILDDIR)/object/player.o $(BUILDDIR)/object/object.o $(BUILDDIR)/view.o $(BUILDDIR)/screen/screen_base.o $(BUILDDIR)/screen/scr_quit.o $(BUILDDIR)/screen/scr_settings.o $(BUILDDIR)/screen/scr_game.o $(BUILDDIR)/screen/scr_list.o $(BUILDDIR)/screen/scr_hiscore.o $(BUILDDIR)/screen/scr_menu.o $(BUILDDIR)/main.o $(BUILDDIR)/globals.o 
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
$(TARGET): $(DATADIR) $(BUILDDIR)/ $(BUILDDIR)/object $(BUILDDIR)/object/bonus $(BUILDDIR)/screen  $(OBJECTS)
	@echo -e "\n$(GREEN)Linking ...$(NOCOL)"
	$(CXX) -o $@ $(OBJECTS) $(CXXFLAGS)
###############################################################################

###############################################################################
#                                OBJECT FILES                                 #
###############################################################################

$(BUILDDIR)/object/smart.o: $(SRCDIR)/object/smart.cpp $(SRCDIR)/object/smart.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/falling.o: $(SRCDIR)/object/falling.cpp $(SRCDIR)/object/falling.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/ufo.o: $(SRCDIR)/object/ufo.cpp $(SRCDIR)/object/ufo.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/bonus/bonus.o: $(SRCDIR)/object/bonus/bonus.cpp $(SRCDIR)/object/bonus/bonus.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/missile.o: $(SRCDIR)/object/missile.cpp $(SRCDIR)/object/missile.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/invader.o: $(SRCDIR)/object/invader.cpp $(SRCDIR)/object/invader.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/moving.o: $(SRCDIR)/object/moving.cpp $(SRCDIR)/object/moving.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/player.o: $(SRCDIR)/object/player.cpp $(SRCDIR)/object/player.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/object/object.o: $(SRCDIR)/object/object.cpp $(SRCDIR)/object/object.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/view.o: $(SRCDIR)/view.cpp $(SRCDIR)/view.h $(BUILDDIR)/screen/screen_base.o $(BUILDDIR)/screen/scr_game.o $(BUILDDIR)/screen/scr_hiscore.o $(BUILDDIR)/screen/scr_menu.o $(BUILDDIR)/screen/scr_quit.o $(BUILDDIR)/screen/scr_settings.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/screen_base.o: $(SRCDIR)/screen/screen_base.cpp $(SRCDIR)/screen/screen_base.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_quit.o: $(SRCDIR)/screen/scr_quit.cpp $(SRCDIR)/screen/scr_quit.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_settings.o: $(SRCDIR)/screen/scr_settings.cpp $(SRCDIR)/screen/scr_settings.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_game.o: $(SRCDIR)/screen/scr_game.cpp $(SRCDIR)/screen/scr_game.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_list.o: $(SRCDIR)/screen/scr_list.cpp $(SRCDIR)/screen/scr_list.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_hiscore.o: $(SRCDIR)/screen/scr_hiscore.cpp $(SRCDIR)/screen/scr_hiscore.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/screen/scr_menu.o: $(SRCDIR)/screen/scr_menu.cpp $(SRCDIR)/screen/scr_menu.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"

$(BUILDDIR)/globals.o: $(SRCDIR)/globals.cpp $(SRCDIR)/globals.h $(BUILDDIR)/main.o
	@echo -e "\n$(YELLOW)Building $@ ...$(NOCOL)"
	$(CXX) $(CXXFLAGS) -c $< -o $@ && echo -e "$(GREEN)OK$(NOCOL)"
###############################################################################

