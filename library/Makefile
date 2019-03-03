# In this directory, type one of the following:
#   make
#   make all

SUBDIRS = src test

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ 

test: src

clean:
	make -C src clean && make -C test clean

.PHONY: all $(SUBDIRS) clean
