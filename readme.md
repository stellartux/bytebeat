# Bytebeat

Monorepo for various bytebeat experiments. To play a song with `aplay`,
run `make $(SONGNAME)`. To play a song with another playback method, compile the
song by running `make o/tiny/$(SONGNAME).com`, or
`make MODE=$(MODE) o/$(MODE)/$(SONGNAME).com`.

## Playback

On Linux with ALSA, piping the audio to `aplay` should just work. On Windows and
Mac, it's possible to play raw audio by piping to VLC.

## Song Info

### `ones-and-zeroes`

Seeded pseudo-random arpeggiation, pass in seed phrases or play with the
default seed.

```sh
ones-and-zeroes.com | aplay
ones-and-zeroes.com | vlc --demux=rawaud --rawaud-channels=1 --rawaud-samplerate=8000
ones-and-zeroes.com 'Pass in seed phrases' 'Each phrase is played for 30 seconds' | aplay
```

### `headachegoldfish`

A C and JavaScript polyglot bytebeat. Play by compiling in C, or running with
Node, Deno or QuickJS.

```sh
headachegoldfish.com | aplay --rate=14080
headachegoldfish.com | vlc --demux=rawaud --rawaud-channels=1 --rawaud-samplerate=14080

node src/headachegoldfish.c | aplay -r 14080
deno run src/headachegoldfish.c | aplay -r 14080
qjs --std src/headachegoldfish.c | aplay -r 14080
```
