#include "aes.h"

#define DUMP(s, i, buf, sz)  {printf(s);                   \
                              for (i = 0; i < (sz);i++)    \
                                  printf("%02x ", buf[i]); \
                              printf("\n");}

int main(int argc, char *argv[]){
  FILE * fi, *fo;
  uint8_t buf[16]; // One single block of 128bits.
  uint8_t key[32]; // 256 bits --> 14 ciclos.

  //magic

  int i;
  for (i = 0; i < sizeof(buf);i++) buf[i] = i * 16 + i;
  DUMP("cleartext: ", i, buf, sizeof(buf));
  subByte(buf);
  DUMP("      sub: ", i, buf, sizeof(buf));
  shiftRows(buf);
  DUMP("    shift: ", i, buf, sizeof(buf));
  mixColumns(buf);
  DUMP("      mix: ", i, buf, sizeof(buf));

  return 0;
}
