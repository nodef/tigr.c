#define TIGR_IMPLEMENTATION
#include <string.h> // Include string.h for strlen
#include <tigr.h>


const char *shaderCode = "\
    void fxShader(out vec4 color, in vec2 uv) {\
        color = vec4(uv.x, uv.y, parameters.x, 1.0);\
    }\
";


int main(int argc, char *argv[]) {
  Tigr *screen = tigrWindow(640, 480, "Enhanced Pixel Shader", TIGR_2X);
  tigrSetPostShader(screen, shaderCode, (int)strlen(shaderCode));

  float parameter = 0.5;

  while (!tigrClosed(screen)) {
    if (tigrKeyHeld(screen, TK_UP))
      parameter += 0.01;
    if (tigrKeyHeld(screen, TK_DOWN))
      parameter -= 0.01;
    if (parameter < 0)
      parameter = 0;
    if (parameter > 1)
      parameter = 1;

    tigrSetPostFX(screen, parameter, 0, 0, 0);
    tigrClear(screen, tigrRGB(0, 0, 0));
    tigrUpdate(screen);
  }

  tigrFree(screen);
  return 0;
}
