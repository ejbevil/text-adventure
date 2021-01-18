CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = main.o actionspace.o creaturespace.o game.o inventory.o \
       space.o utilities.o winlosespace.o

adventure: $(OBJS)
	${CXX} ${CXXFLAGS} $(OBJS) -o adventure
    
main.o: actionspace.hpp creaturespace.hpp game.hpp inventory.hpp \
        space.hpp utilities.hpp winlosespace.hpp
        
game.o: game.hpp actionspace.hpp creaturespace.hpp inventory.hpp \
        space.hpp utilities.hpp winlosespace.hpp
        
actionspace.o: actionspace.hpp space.hpp utilities.hpp

creaturespace.o: creaturespace.hpp space.hpp utilities.hpp

winlosespace.o: winlosespace.hpp space.hpp utilities.hpp

space.o: space.hpp

inventory.o: inventory.hpp

utilities.o: utilities.hpp

.PHONY: clean
clean: 
	rm *.o adventure