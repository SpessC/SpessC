#include "engine.h"

int loadConfig() {
	FILE* fp;
	char errorBuffer[512];
	

	fp = fopen("engine/config/engine.toml", "r");
	if (fp == NULL) {
		TraceLog(LOG_ERROR, "could not load engine.toml!");
		return -1;
	}


	toml_table_t* engine = toml_parse_file(fp, errorBuffer, sizeof(errorBuffer));
	if (engine == NULL) {
		TraceLog(LOG_ERROR, "could not parse the toml!");
		return -1;
	}


	fclose(fp);


	toml_table_t* window_table = toml_table_in(engine, "window");
	if (window_table == NULL) {
		TraceLog(LOG_ERROR, "could not find [window], defaulting!");

		window_data.width = 800;
		window_data.height = 600;
		window_data.fullscreen = 0;
		window_data.resizable = 0;

		toml_free(engine);
		return 0;
	}


	toml_array_t* resolution_toml = toml_array_in(window_table, "resolution");
	if (resolution_toml == NULL) {
		TraceLog(LOG_ERROR, "could not find resolution, defaulting!");

		window_data.width = 800;
		window_data.height = 600;
	} else {
		window_data.width = toml_int_at(resolution_toml, 0).u.i;
		window_data.height = toml_int_at(resolution_toml, 1).u.i;
	}
	

	toml_datum_t resizable_toml = toml_bool_in(window_table, "resizable");
	if (resizable_toml.ok == 0) {
		TraceLog(LOG_ERROR, "could not find resizable, defaulting!");

		window_data.resizable = false;
	} else {
		window_data.resizable = resizable_toml.u.b;
	}


	toml_datum_t fullscreen_toml = toml_bool_in(window_table, "fullscreen");
	if (fullscreen_toml.ok == 0) {
		TraceLog(LOG_ERROR, "could not find fullscreen, defaulting!");

		window_data.fullscreen = false;
	} else {
		window_data.fullscreen = fullscreen_toml.u.b;
	}


	toml_free(engine);
	return 0;
}