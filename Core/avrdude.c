//
//  avrdude.c
//  Core
//
//  Created by Levi Dhuyvetter on 05/12/2020.
//

#include <libavrdude.h>

int ovsigck = 0;
char progbuf[PATH_MAX];
const char* progname = "XcodeAVRDude";
int quell_progress = 0;
int usb_busses = 0;
int verbose = 0;
void avrdude_message(FILE *file, const char *format, ...) {
	return;
}
