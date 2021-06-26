#include "engine.h"

#define GRACK (Color){ 77, 77, 77, 255 }

int main(int argc, char* argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	if (loadConfig() == -1) {
		TraceLog(LOG_ERROR, "Failed to load configuration files!");
		return -1;
	}

	initRender();

	int running = 1;
	SetTargetFPS(60);

	Texture2D logo = LoadTexture("engine/art/templogo.png");
	
	while (running) {
		if (WindowShouldClose()) {
			running = 0;
		}
		BeginDrawing();
		ClearBackground(GRACK);
		DrawTexture(logo, 400 - logo.width/2, 300 - logo.height/2, WHITE);
		EndDrawing();

	}
	CloseWindow();
	return EXIT_SUCCESS;
	
}
