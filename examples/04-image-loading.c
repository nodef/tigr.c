#define TIGR_IMPLEMENTATION
#include <tigr.h>


int main(int argc, char *argv[]) {
  Tigr *screen = tigrWindow(640, 480, "Enhanced Image Loading", 0);
  Tigr *images[2];
  images[0] = tigrLoadImage("images/tigr.png");
  images[1] = tigrLoadImage("images/tigr.png");

  if (!images[0] || !images[1]) {
    tigrError(0, "Failed to load images.");
    return 1;
  }

  int currentImage = 0;

  while (!tigrClosed(screen)) {
    if (tigrKeyDown(screen, TK_SPACE)) {
      currentImage = 1 - currentImage;
    }

    tigrClear(screen, tigrRGB(0, 0, 0));
    tigrBlit(screen, images[currentImage], 100, 100, 0, 0,
             images[currentImage]->w, images[currentImage]->h);
    tigrUpdate(screen);
  }

  tigrFree(images[0]);
  tigrFree(images[1]);
  tigrFree(screen);
  return 0;
}
