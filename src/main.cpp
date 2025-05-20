#include <iostream>

#include <raylib.h>

int main(void) {
  // TODO: Add more stuff
  // NOTE: This was done to do more stuff
  // WARN: This may do more stuff
  // HACK: Doing some hacking...
  // FIX: No idea how to do more stuff
  // PERF: This does less stuff as time increases
  // TEST: Null pointer was dereferenced
  std::cout << "hello juniorpen01s template\n";

  InitWindow(800, 800, "juniorpen01's Template");

  Image cat_img = LoadImage("res/cat.jpg");
  ImageResize(&cat_img, 800, 800);

  Texture cat = LoadTextureFromImage(cat_img);

  UnloadImage(cat_img);

  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawTexture(cat, 0, 0, RAYWHITE);
    EndDrawing();
  }

  UnloadTexture(cat);
  CloseWindow();
}
