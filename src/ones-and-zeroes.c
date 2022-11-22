#ifndef __COSMOPOLITAN__
#include <stdio.h>
#endif

#define SCALE(T, K) (128 + (((T)-128) >> (K)) + (128 >> (K)))

static int KickDrum(int t) {
  return 128 + ((t & 0x1c0) >> 1) * !(t & 0xf00) * 2;
}

static int ByteBeat(const char *s, int t) {
  // clang-format off
  return s[15 & t >> 10] *
    (
      (
        (
          t & 0x10000 ?
            ~t & 0x30000 >> 4
          :
          t & 0x8000 ?
            0x3000
          :
          t & 0x4000 ?
            0x1000
          :
            0x2000
        ) & (t - 0xc00) ?
            t
          :
            t * 16 / 9
      )
      & (0x78 & s[15 & t >> 14]) // it's the notes you don't play
    );
  // clang-format on
}

int main(int argc, const char *argv[]) {
  int alFine, i, t;
  const char *s[] = {"", "Oh no!", "ONES AND ZEROES\n", "OhNOs&. . .Zr0ES!",
                     "SeGmEnTaTiOn FaUlT!!1"};
  if (argc == 1) {
    argc = 5;
    argv = s;
  }
  for (i = 0; i < 0x400; i++) {
    putchar(128);
  }
  alFine = 0;
Capo:
  for (i = 1; i < argc; i++) {
    for (t = 0; t <= (alFine ? 0xc000 : 0x40000); t++) {
      putchar(SCALE(ByteBeat(argv[i], t), 3) + KickDrum(t - 0x400));
    }
  }
  if (!alFine) {
    argc = 2;
    alFine = 1;
    goto Capo;
  }
  for (i = 0; i < 0x400; i++) {
    putchar(128);
  }
}
