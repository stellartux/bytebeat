COSMODIR=/opt/cosmo
CFLAGS=-g -Os -static -fno-pie -no-pie -nostdlib -nostdinc -gdwarf-4 -fno-omit-frame-pointer -pg -mnop-mcount -mno-tls-direct-seg-refs
LFLAGS=-Wl,--gc-sections -fuse-ld=bfd -Wl,--gc-sections -Wl,-T,$(COSMODIR)/o/$(MODE)/ape/ape.lds -include $(COSMODIR)/o/cosmopolitan.h $(COSMODIR)/o/$(MODE)/libc/crt/crt.o $(COSMODIR)/o/$(MODE)/ape/ape-no-modify-self.o $(COSMODIR)/o/$(MODE)/cosmopolitan.a
AUDIOOUT=aplay
# vlc --demux=rawaud --rawaud-channels 1 --rawaud-samplerate 8000

SONGS=ones-and-zeroes

all: $(foreach SONG,$(SONGS),o/$(SONG))

all.com: $(foreach SONG,$(SONGS),o/$(MODE)/$(SONG).com)

o/$(MODE)/ones-and-zeroes.com: src/ones-and-zeroes.c
	mkdir -p o/$(MODE)
	$(CC) $(CFLAGS) -o $@.dbg src/ones-and-zeroes.c $(LFLAGS)
	objcopy -S -O binary $@.dbg $@
	rm $@.dbg

o/ones-and-zeroes: src/ones-and-zeroes.c
	$(CC) -Os -o $@ src/ones-and-zeroes.c

.PHONY: clean
clean:
	rm -r o/*

.PHONY: noise
noise: o/ones-and-zeroes
	o/ones-and-zeroes | $(AUDIOOUT)
