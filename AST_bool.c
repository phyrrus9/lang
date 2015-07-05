char *next; //ptr to input stream
void *parseData; //ptr to struct type returned
struct block *AST;

enum parseType S();
enum parseType E();
enum parseType T();
enum parseType F();

bool S01();
bool S02();
bool S03();
bool S04();
bool S05();
bool S06();
bool S07();
bool S08();
bool S09();
bool S10();
bool S11();
bool S12();
bool S13();
bool S14();
bool S15();
bool S16();
bool S17();
bool S18();
bool S19();
bool S20();

bool E01();
bool E02();
bool E03();

bool T01();
bool T02();
bool T03();
bool T04();

bool F01();
bool F02();

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
	if (!E01()) {
		next = save;
		if (!E02()) {
			next = save;
			if (!E03()) {
				return tERR;
			} else return tE03;
		} else return tE02;
	} else return tE01;
	return tERR;
}

enum parseType T()
{
	char *save = next;
	if (!T01()) {
		next = save;
		if (!T02()) {
			next = save;
			if (!T03()) {
				if (!T04()) {
					return tERR;
				} else return tT04;
			} else return tT03;
		} else return tT02;
	} else return tT01;
	return tERR;
}

enum parseType F()
{
	char *save = next;
	if (!F01()) {
		next = save;
		if (!F02()) {
			return tERR:
		} else return tF02;
	} else return tF01;
	return tERR;
}