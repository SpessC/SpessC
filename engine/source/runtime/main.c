#include "engine.h"

int main(int argc, char* argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	initRender();

	int running = 1;
	SetTargetFPS(60);

	while (running) {
		if (WindowShouldClose()) {
			running = 0;
		}

		BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();

	}
	CloseWindow();
	return EXIT_SUCCESS;
	
}