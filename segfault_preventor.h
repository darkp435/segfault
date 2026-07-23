#ifndef SEGFAULT_PREVENTOR_H
#define SEGFAULT_PREVENTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
# only losers use Windows
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

static LONG WINAPI segfault_preventor_win32_handler(EXCEPTION_POINTERS* info) {
    if (info->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
        HANDLE file = CreateFileW(L"bruh.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        if (file == INVALID_HANDLE_VALUE) {
            printf("Failed to create file: %lu\n", GetLastError());
            return 1;
        }

        const char* text = "The programmer who wrote this is NOT getting a raise... HA!\n";
        DWORD written;

        for (int _ = 0; _ < 1000; _++) {
            WriteFile(file, text, (DWORD)strlen(text), &written, NULL);
        }
        CloseHandle(file);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

static inline void prevent_segfaults() {
    AddVectoredExceptionHandler(1, segfault_preventor_win32_handler);
}

#elif __APPLE__ || __MACH__ || __linux__
#include <unistd.h>

#include <fcntl.h>
#include <signal.h>
#include <string.h>

static void segfault_preventor_posix_handler(int sig) {
	(void) sig;

	int fd = open("bruh.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1) {
		const char* text = "The programmer who write this is NOT getting a raise... HA!\n";
		size_t len = strlen(text);

		for (int _ = 0; _ < 1000; _++) {
			ssize_t off = 0;
			while (off < (ssize_t) len) {
				ssize_t written = write(fd, text + off, len - off);
				if (written <= 0) break;
				off += written;
			}
		}
		close (fd);
	}
	signal(SIGSEGV, SIG_DFL);
}

static inline void prevent_segfaults() {
	signal(SIGSEGV, segfault_preventor_posix_handler);
}

#else
#error Oof, the target operating system does not support segfault_preventor.h!
#endif // OS checks

#ifdef __cplusplus
}
#endif

#endif // SEGFAULT_PREVENTOR_H
