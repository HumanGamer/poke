#ifndef _TIME_MS_H_
#define _TIME_MS_H_

#ifdef _WIN32
#include <Windows.h>

#define CLOCK_MONOTONIC 0

inline int clock_gettime(int, struct timespec* spec)      //C-file part
{
  __int64 wintime; GetSystemTimeAsFileTime((FILETIME*)& wintime);
  wintime -= 116444736000000000i64;  //1jan1601 to 1jan1970
  spec->tv_sec = wintime / 10000000i64;           //seconds
  spec->tv_nsec = wintime % 10000000i64 * 100;      //nano-seconds
  return 0;
}
#endif

inline time_t timems()
{
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (time_t) ts.tv_nsec;
}

#endif /* _TIME_MS_H_ */