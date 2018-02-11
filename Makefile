BASENAME = demo

build:
	cc65 -Oi source/$(BASENAME).c --add-source -o export/$(BASENAME).s
	ca65 export/$(BASENAME).s -o export/$(BASENAME).o
	ca65 source/reset.s -o export/reset.o
	ld65 -C memory.cfg -o export/bin/$(BASENAME).nes export/reset.o export/$(BASENAME).o nes.lib

clean:
	rm -rf ./export/*
	rm -f *.o

test:
	export/bin/$(BASENAME).nes
