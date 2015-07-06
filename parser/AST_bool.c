#include "AST_bool.h"
#include "AST_parse.h"
#include <stdlib.h>

enum parseType S()
{
	char *save = next;
	if (!S01()) {
		next = save;
		if (!S02()) {
			next = save;
			if (!S03()) {
				next = save;
				if (!S04()) {
					next = save;
					if (!S05()) {
						next = save;
						goto S06_above;
					} else return tS05;
				} else return tS04;
			} else return tS03;
		} else return tS02;
	} else return tS01;
S06_above:
	if (!S06()) {
		next = save;
		if (!S07()) {
			next = save;
			if (!S08()) {
				next = save;
				if (!S09()) {
					next = save;
					if (!S10()) {
						next = save;
						goto S11_above;
					} else return tS10;
				} else return tS09;
			} else return tS08;
		} else return tS07;
	} else return tS06;
S11_above:
	if (!S11()) {
		next = save;
		if (!S12()) {
			next = save;
			if (!S13()) {
				next = save;
				if (!S14()) {
					next = save;
					if (!S15()) {
						next = save;
						goto S16_above;
					} else return tS15;
				} else return tS14;
			} else return tS13;
		} else return tS12;
	} else return tS11;
S16_above:
	if (!S16()) {
		next = save;
		if (!S17()) {
			next = save;
			if (!S18()) {
				next = save;
				if (!S19()) {
					next = save;
					if (!S20()) {
						return tERR;
					} else return tS20;
				} else return tS19;
			} else return tS18;
		} else return tS17;
	} else return tS16;
	return tERR;
}

enum parseType E()
{
	char *save = next;
	if (!E02()) {
		next = save;
		if (!E03()) {
			next = save;
			if (!E01()) {
				return tERR;
			} else return tE01;
		} else return tE03;
	} else return tE02;
	return tERR;
}

enum parseType T()
{
	char *save = next;
	if (!T04()) {
		next = save;
		if (!T02()) {
			next = save;
			if (!T03()) {
				next = save;
				if (!T01()) {
					return tERR;
				} else return tT01;
			} else return tT03;
		} else return tT02;
	} else return tT04;
	return tERR;
}

enum parseType F()
{
	char *save = next;
	if (!F02()) {
		next = save;
		if (!F01()) {
			return tERR;
		} else return tF01;
	} else return tF02;
	return tERR;
}
