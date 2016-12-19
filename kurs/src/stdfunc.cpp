#ifndef RANDOMIWE
#define RANDOMIWE

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

uint64_t s[2];

uint64_t randomiwe(void) //xor-shift random 
{
    uint64_t s1 = s[0];
	const uint64_t s0 = s[1];
	const uint64_t result = s0 + s1;
	s[0] = s0;
	s1 ^= s1 << 23;
	s[1] = s1 ^ s0 ^ (s1 >> 18) ^ (s0 >> 5);
    return result;
}

#endif
