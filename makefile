DEPS= medrep
compile: main.cpp 
	 g++ main.cpp -o $(DEPS)
	 clear

ascending: $(DEPS)
	 ./$(DEPS) -a

descending: $(DEPS)
	 ./$(DEPS) -d

clean: $(DEPS)
	 rm $(DEPS)
