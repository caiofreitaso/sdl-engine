#pragma once
#ifndef KMP_H
#define KMP_H

void kmp_table(int T[], char const* w, size_t len_w)
{
	int pos = 2;
	int cnd = 0;

	T[0] = -1;
	T[1] = 0;

	while (pos < len_w)
	{
		if (w[pos-1] == w[cnd])
		{
			T[pos] = cnd + 1;
			cnd++;
			pos++;
		}
		else
		{
			T[pos] = 0;
			if (cnd > 0)
				cnd = T[cnd];
			else
				pos++;
		}
	}
}

size_t kmp_find(char const* s, char const* w, size_t len_s, size_t len_w)
{
	size_t m = 0;
	size_t i = 0;
	int T[len_w];

	while (m + i < len_s)
	{
		if (w[i] == s[m+i])
		{
			if (i == len_w-1)
				return m;
			i++;
		}
		else
		{
			if (T[i] > -1)
			{
				m += i - T[i];
				i = T[i];
			}
			else
			{
				m++;
				i = 0;
			}
		}
	}

	return len_s;
}

#endif