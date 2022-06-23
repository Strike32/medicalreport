DEPS= medrep
compile: medrep.cpp 
	 g++ medrep.cpp -o $(DEPS)
	 clear

inserting: $(DEPS)
	 ./$(DEPS) -i

queuing: $(DEPS)
	 ./$(DEPS) -q

clean: $(DEPS)
	 rm $(DEPS)
