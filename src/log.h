/**
 * Copyright (c) 2017 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

#define LOG_VERSION "0.1.0"

typedef void (*log_LockFn)(void *udata, int lock);

enum log_types {
	L_TRACE,
	L_DEBUG,
	L_INFO,
	L_WARN,
	L_ERROR,
	L_FATAL
};

void log_log(enum log_types level, void *log_lock, const char *file, int line, const char *fmt, ...);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#define log(type, log_lock, fmt, ...) log_log(type, log_lock, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#pragma clang diagnostic pop

void log_set_udata(void *udata);
void log_set_lock(log_LockFn fn);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_quiet(int enable);

#endif
