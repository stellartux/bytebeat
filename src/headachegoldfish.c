/* A C and JavaScript polyglot bytebeat by stellartux

Run this program by piping one of the following into `aplay --rate=14080`:

- `cc -o headachegoldfish headachegoldfish.c && headachegoldfish`
- `deno run headachegoldfish.c`
- `node headachegoldfish.c`
- `qjs --std headachegoldfish.c

*/
//\
/* C

#ifndef __COSMOPOLITAN__
#include <stdio.h> // putchar
#endif
#define let unsigned long
#define function int
#define charCodeAt(s, i) s[i]

unsigned long ipow(unsigned long base, unsigned long exp) {
  unsigned long result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

/*/ // JS

const charCodeAt = (s, i) => s.charCodeAt(i)
const ipow = Math.pow
let putchar

if (this?.print) { // qjs
  putchar = std.out.putByte.bind(std.out)
} else { // node and deno
  const byte = new Uint8Array(1)
  const write = this === undefined 
    ? Deno.stdout.writeSync.bind(Deno.stdout)
    : process.stdout.write.bind(process.stdout)
  putchar = function(c) {
    byte[0] = c
    write(byte)
  }
}

// C and JS */

function main() {
  let n = 0, t = 0, tt = 0;
  for (; 1; t++) {
    tt = (1 << 13) * t / 14080 | 0;
    n = 2 + (3 & ((tt >> 15) - (3 & (tt >> 18))));
    putchar(charCodeAt("HEADACHEGOLDFISH", (tt >> 10) % (8 + (8 & ((tt >> 14) | (tt >> 15)))))
    * ((t * n * ipow(2, n) / ipow(3, n)) & ~7 & 0x1e70 >> (7 & (tt >> 16))));
  }
}
//\
main()
