.PHONY: all clean lib src

all: lib src

lib: 
	$(MAKE) -C lib

src: lib
	$(MAKE) -C src

clean: clean-lib clean-src
	
clean-lib:
	$(MAKE) clean -C lib

clean-src:
	$(MAKE) clean -C src