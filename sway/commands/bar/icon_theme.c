#define _XOPEN_SOURCE 500
#include <string.h>
#include "sway/commands.h"

struct cmd_results *bar_cmd_icon_theme(int argc, char **argv) {
	const char *cmd_name = "tray_output";
#ifndef ENABLE_TRAY
	return cmd_results_new(CMD_INVALID, cmd_name, "Invalid %s command "
			"%s called, but sway was compiled without tray support",
			cmd_name, cmd_name);
#else
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, cmd_name, EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	if (!config->current_bar) {
		return cmd_results_new(CMD_FAILURE, cmd_name, "No bar defined.");
	}

	config->current_bar->icon_theme = strdup(argv[0]);

	return cmd_results_new(CMD_SUCCESS, NULL, NULL);
#endif
}
