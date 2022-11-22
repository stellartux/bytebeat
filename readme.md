# Bytebeat

Monorepo for various bytebeat experiments.

## Ones and Zeroes

A bytebeat tune. To play the song, run `make noise`. To build an Actually
Portable Executable, run `make` with an optional `MODE`.

### To play the executable

#### aplay

```sh
ones-and-zeroes.com | aplay
# or with pledge
pledge stdio ones-and-zeroes.com | aplay
```

#### VLC

```sh
ones-and-zeroes.com | vlc --demux=rawaud --rawaud-channels 1 --rawaud-samplerate 8000
```

### Experiment with the song

```sh
ones-and-zeroes.com 'Pass in seed phrases' 'Each phrase is played for 30 seconds' | aplay
```
