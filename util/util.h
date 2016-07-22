/* horst - Highly Optimized Radio Scanning Tool
 *
 * Copyright (C) 2005-2016 Bruno Randolf (br1@einfach.org)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _UWIFI_UTIL_H_
#define _UWIFI_UTIL_H_

#define MAC_NOT_EMPTY(_mac) (_mac[0] || _mac[1] || _mac[2] || _mac[3] || _mac[4] || _mac[5])

#define MAC_EMPTY(_mac) (!_mac[0] && !_mac[1] && !_mac[2] && !_mac[3] && !_mac[4] && !_mac[5])

#ifndef BIT
#define BIT(nr) (1 << (nr))
#endif

#define TOGGLE_BIT(_x, _m) (_x) ^= (_m)

/**
 * TOGGLE_BITSET() - toggle set of bits as a whole
 * @_x: an integer variable
 * @_s: an integer variable interpreted as a bitset
 * @_t: type (e.g. uint16_t)
 * If any of the bits are set, all bits will be unset. Otherwise, if
 * none of the bits are set, all bits will be set.
 */
#define TOGGLE_BITSET(_x, _s, _type) do {	\
		if ((_x) & (_s))		\
		(_x) &= (_type)~(_s);		\
		else				\
			(_x) |= (_s);		\
		} while(0)

#define max(_x, _y) ((_x) > (_y) ? (_x) : (_y))

#define min(_x, _y) ((_x) < (_y) ? (_x) : (_y))

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

#define MAC_FMT "%02x:%02x:%02x:%02x:%02x:%02x"
#define MAC_PAR(x) x[0], x[1], x[2], x[3], x[4], x[5]

void dump_packet(const unsigned char* buf, int len);
const char* ether_sprintf(const unsigned char *mac);
const char* ether_sprintf_short(const unsigned char *mac);
const char* ip_sprintf(const unsigned int ip);
const char* ip_sprintf_short(const unsigned int ip);
int normalize(float val, int max_val, int max);
int ilog2(int x);

static inline int normalize_db(int val, int max)
{
	if (val <= 30)
		return 0;
	else if (val >= 100)
		return max;
	else
		return normalize(val - 30, 70, max);
}

static inline __attribute__((const))
int is_power_of_2(unsigned long n)
{
	return (n != 0 && ((n & (n - 1)) == 0));
}

#endif
