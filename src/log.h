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

#include <shared/thread.h>

#define LOG_VERSION "0.1.0"

typedef void (*log_LockFn)(void *udata, int lock);

enum { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

#define log_trace_serve(file, line, fmt, ...) log_log(LOG_TRACE, file, line, fmt, args)
#define log_debug_serve(file, line, fmt, ...) log_log(LOG_DEBUG, file, line, fmt, args)
#define log_info_serve(file, line, fmt, ...)  log_log(LOG_INFO,  file, line, fmt, args)
#define log_warn_serve(file, line, fmt, ...)  log_log(LOG_WARN,  file, line, fmt, args)
#define log_error_serve(file, line, fmt, ...) log_log(LOG_ERROR, file, line, fmt, args)
#define log_fatal_serve(file, line, fmt, ...) log_log(LOG_FATAL, file, line, fmt, args)

#define log_trace_nnl(...) log_log_nnl(LOG_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define log_debug_nnl(...) log_log_nnl(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info_nnl(...)  log_log_nnl(LOG_INFO,  __FILE__, __LINE__, __VA_ARGS__)
#define log_warn_nnl(...)  log_log_nnl(LOG_WARN,  __FILE__, __LINE__, __VA_ARGS__)
#define log_error_nnl(...) log_log_nnl(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_fatal_nnl(...) log_log_nnl(LOG_FATAL, __FILE__, __LINE__, __VA_ARGS__)

void log_set_udata(void *udata);
void log_set_lock(log_LockFn fn);
void log_set_fp(FILE *fp);
void log_set_level(int level);
void log_set_quiet(int enable);

void log_log(int level, const char *file, int line, const char *fmt, va_list args);

void log_log_nnl(int level, const char *file, int line, const char *fmt, ...);

#endif
