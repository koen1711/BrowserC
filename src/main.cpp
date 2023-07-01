#include "javascript/V8Engine.h"
#include "html/HTMLParser.h"
#include "raylib.h"

#include <string>

int main(int argc, char **argv) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);



    HTMLParser parser(std::string("<html><head><title>Test</title></head><body><h1>Hello World!</h1></body></html>"), std::string(""));

    parser.parse();

    while (!WindowShouldClose())
    {
        BeginDrawing();


        EndDrawing();
    }



    return 0;
}
