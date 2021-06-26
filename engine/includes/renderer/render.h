#pragma once

int initRender();

typedef struct {
	int width;
	int height;
	_Bool resizable;
	_Bool fullscreen;
} window_int;

window_int window_data;