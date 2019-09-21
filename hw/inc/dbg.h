#ifndef DBG_H
#define DBG_H

#include <printf.h>

#if defined(__INFO__) || defined(__DBG__) || defined(__WARN__) || defined(__ERR__)
#define DBG_ERR(format, ...) printf ("[ERROR] %s::%s(%d) - "format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DBG_ERR(format, ...)
#endif

#if defined(__INFO__) || defined(__DBG__) || defined(__WARN__)
#define DBG_WARN(format, ...) printf ("[WARN] %s::%s(%d) - "format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DBG_WARN(format, ...)
#endif

#if defined(__INFO__) || defined(__DBG__)
#define DBG_INFO(format, ...) printf ("[INFO] %s::%s(%d) - "format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DBG_INFO(format, ...)
#endif

#ifdef __DBG__
#define DBG_DEBUG(format, ...) printf ("[DEBUG] %s::%s(%d) - "format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define DBG_DEBUG(format, ...)
#endif

#endif // DBG_H
