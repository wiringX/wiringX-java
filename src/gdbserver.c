/*
 * MIT License
 * 
 * Copyright (c) 2016 Josua Mayer <josua.mayer97@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>

#ifdef GDB

__attribute__((constructor))
void gdbserver() {
	int pid = fork();

	if (pid < 0) {
		// dont know what to do, maybe nothing is best
		return;
	} else if (pid > 0) {
		// give user time to start gdb
		printf("Waiting 10 seconds for gdb to attach.\n");
		sleep(10);
		return;
	} else {
		// forked
		// run gdbserver
		const char *format = "/usr/bin/gdbserver --attach %s %i";
		int l = snprintf(NULL, 0, format, "127.0.0.1:11337", getppid());
		char *command = (char *)malloc(l+1);
		snprintf(command, l+1, format, "127.0.0.1:11337", getppid());

		//printf("%s\n", command);
		int r = system(command);
		free(command);

		if(r == -1)
			fprintf(stderr, "\nFailed to exec GDB\n");
	}
}

#endif
