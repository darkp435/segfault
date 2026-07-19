#ifndef SEGFAULT_PREVENTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32

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
// Temporary
#error Linux and MacOS do not currently support segfault preventor. The maintainer is so lazy dawg
#else
#error Oof, the target operating system does not support segfault_preventor.h!
#endif // OS checks

#ifdef __cplusplus
}
#endif

#endif // SEGFAULT_PREVENTOR_H