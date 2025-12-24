#define TIGR_IMPLEMENTATION
#include <tigr.h>


int main(int argc, char *argv[]) {
  Tigr *screen = tigrWindow(320, 240, "Hello, World!", 0);
  int colorIndex = 0;
  TPixel colors[] = {tigrRGB(0xff, 0x00, 0x00), tigrRGB(0x00, 0xff, 0x00),
                     tigrRGB(0x00, 0x00, 0xff), tigrRGB(0xff, 0xff, 0x00)};

  while (!tigrClosed(screen)) {
    if (tigrKeyDown(screen, TK_SPACE)) {
      colorIndex = (colorIndex + 1) % 4;
    }

    tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
    tigrPrint(screen, tfont, 100, 110, colors[colorIndex], "Hello, World!");
    tigrUpdate(screen);
  }

  tigrFree(screen);
  return 0;
}
