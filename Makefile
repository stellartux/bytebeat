COSMODIR=/opt/cosmo
CFLAGS=-g -Os -static -fno-pie -no-pie -nostdlib -nostdinc -gdwarf-4 -fno-omit-frame-pointer -pg -mnop-mcount -mno-tls-direct-seg-refs
LFLAGS=-Wl,--gc-sections -fuse-ld=bfd -Wl,--gc-sections -Wl,-T,$(COSMODIR)/o/$(MODE)/ape/ape.lds -include $(COSMODIR)/o/cosmopolitan.h $(COSMODIR)/o/$(MODE)/libc/crt/crt.o $(COSMODIR)/o/$(MODE)/ape/ape-no-modify-self.o $(COSMODIR)/o/$(MODE)/cosmopolitan.a
AUDIOOUT=aplay
#AUDIOOUT=vlc --demux=rawaud --rawaud-channels 1 --rawaud-samplerate 8000
MODE=tiny

SONGS=ones-and-zeroes headachegoldfish

headachegoldfish_FLAGS=-r 14080

all: $(foreach SONG,$(SONGS),o/$(SONG))

all.com: $(foreach SONG,$(SONGS),o/$(MODE)/$(SONG).com)

o/$(MODE)/%.com.dbg: src/%.c
	mkdir -p o/$(MODE)
	$(CC) $(CFLAGS) -o $@ $< $(LFLAGS)

o/$(MODE)/%.com: o/$(MODE)/%.com.dbg
	objcopy -S -O binary $< $@

.PHONY: clean
clean:
	rm -r o/*

%: o/$(MODE)/%.com.dbg
	$< | $(AUDIOOUT) $($@_FLAGS)
