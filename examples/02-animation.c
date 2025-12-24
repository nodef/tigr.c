#define TIGR_IMPLEMENTATION
#include <tigr.h>


int main(int argc, char *argv[]) {
  Tigr *screen = tigrWindow(640, 480, "Enhanced Animation", 0);
  float x1 = 0, y1 = 240, x2 = 640, y2 = 120;
  float speed = 100; // pixels per second

  while (!tigrClosed(screen)) {
    float delta = tigrTime();

    if (tigrKeyHeld(screen, TK_UP))
      speed += 50 * delta;
    if (tigrKeyHeld(screen, TK_DOWN))
      speed -= 50 * delta;
    if (speed < 0)
      speed = 0;

    x1 += speed * delta;
    x2 -= speed * delta;

    if (x1 > 640)
      x1 = 0;
    if (x2 < 0)
      x2 = 640;

    tigrClear(screen, tigrRGB(0, 0, 0));
    tigrFill(screen, (int)x1, (int)y1, 50, 50, tigrRGB(255, 0, 0));
    tigrFill(screen, (int)x2, (int)y2, 50, 50, tigrRGB(0, 0, 255));
    tigrPrint(screen, tfont, 10, 10, tigrRGB(255, 255, 255), "Speed: %.2f",
              speed);
    tigrUpdate(screen);
  }

  tigrFree(screen);
  return 0;
}
