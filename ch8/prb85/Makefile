CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif


_ALL=xref_impl

all: $(_ALL)

xref_impl: xref_impl.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
