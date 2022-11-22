# Ones and Zeroes

A bytebeat tune. To play the song, run `make noise`. To build an Actually
Portable Executable, run `make` with an optional `MODE`.

## To play the executable

### aplay

```sh
noises.com | aplay
# or with pledge
pledge stdio noises.com | aplay
```

### VLC

```sh
noises.com | vlc --demux=rawaud --rawaud-channels 1 --rawaud-samplerate 8000
```

## Experiment with the song

```sh
noises.com 'Pass in seed phrases' 'Each phrase is played for 30 seconds' | aplay
```
