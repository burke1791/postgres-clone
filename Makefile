all: bin
	+$(MAKE) -C src

bin:
	mkdir $@