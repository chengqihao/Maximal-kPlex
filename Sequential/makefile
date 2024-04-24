FLAG = -g --std=c++14 -msse4.2 -O3 -Ofast

#FLAG = -g --std=c++14 -O2 
ifdef PROMPT
	FLAG := $(FLAG) -DPROMPT
endif

ifdef OPT
	FLAG := $(FLAG) -Ofast
endif
#-fcilkplus

ifdef SET
	FLAG := $(FLAG) -DSET
endif

all: 
	g++ $(FLAG) kPlexEnum.cpp -o PlexEnum
	g++ toBin.cpp -o toBin
clean:
	rm PlexEnum
