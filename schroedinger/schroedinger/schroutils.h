
#ifndef __SCHRO_SCHROUTILS_H__
#define __SCHRO_SCHROUTILS_H__

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define DIVIDE_ROUND_UP(a,b) (((a) + (b) - 1)/(b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define CLAMP(x,a,b) ((x)<(a) ? (a) : ((x)>(b) ? (b) : (x)))
#define ROUND_UP_SHIFT(x,y) (((x) + (1<<(y)) - 1)>>(y))
#define OFFSET(ptr,offset) ((void *)(((uint8_t *)(ptr)) + (offset)))
#define SCHRO_GET(ptr, offset, type) (*(type *)((uint8_t *)(ptr) + (offset)) )



int ilog2(unsigned int x);
unsigned int round_up_pow2(unsigned int x, int p);

#endif