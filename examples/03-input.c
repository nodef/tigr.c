#define TIGR_IMPLEMENTATION
#include <tigr.h>


int main(int argc, char *argv[]) {
  Tigr *screen = tigrWindow(640, 480, "Enhanced Input", 0);
  int x = 320, y = 240;
  int dragging = 0;
  int mouseX, mouseY, mouseButtons;

  while (!tigrClosed(screen)) {
    tigrMouse(screen, &mouseX, &mouseY, &mouseButtons);

    if (mouseButtons & 1) {
      if (!dragging) {
        dragging = 1;
      }
      x = mouseX;
      y = mouseY;
    } else {
      dragging = 0;
    }

    if (tigrKeyHeld(screen, TK_UP))
      y -= 5;
    if (tigrKeyHeld(screen, TK_DOWN))
      y += 5;
    if (tigrKeyHeld(screen, TK_LEFT))
      x -= 5;
    if (tigrKeyHeld(screen, TK_RIGHT))
      x += 5;

    tigrClear(screen, tigrRGB(0, 0, 0));
    tigrFill(screen, x - 25, y - 25, 50, 50,
             dragging ? tigrRGB(255, 255, 0) : tigrRGB(0, 255, 0));
    tigrUpdate(screen);
  }

  tigrFree(screen);
  return 0;
}
