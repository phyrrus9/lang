enum parseType { tNOCODE, tERR,
	tS01 = tNOCODE,
	tS02 = tNOCODE,
	tS03 = tNOCODE,
	tS19 = tNOCODE,
	tS11 = tS07,
	tS04, tS05, tS06, tS07, tS08, tS09,
	tS10, tS12, tS13, tS14, tS15, tS16,
	tS17, tS18, tS20, tE01, tE02, tE03,
	tT01, tT02, tT03, tT04, tF01, tF02
};
struct block_node {
	enum parseType t;
	void *match;
	struct block_node *next;
};
struct block {
	struct block_node *head,
			  *tail;
	unsigned int num;
};
struct S04_st {
	struct S08_st *assign;
	struct S03_st *ret;
};
struct S05_st {
	enum parseType t; //E0x of match
	void *match; //ptr to struct of t
};
struct S06_st {
	char *name;
};
struct S07_st {
	char *name;
};
struct S08_st {
	enum parseType t; //E0x of match
	void *match; //ptr to struct of t
	char *name; //name of <var>
};
struct S09_st {
	struct block *statements;
	char *name;
};
struct S10_st {
	char *name;
};
struct S11_st {
	char *name;
};
struct S12_st {
	enum parseType t; //E0x
	void *match; //struct of t
};
struct S13_st {
	enum parseType t; //E0x
	void *match; //struct of t
};
struct S14_st {
	char *name;
};
struct S15_st {
	char *name;
};
struct S16_st {
	char *name;
};
struct S17_st {
	enum parseType t; //E0x
	void *match; //struct of t
};
struct S18_st {
	char *name;
};
struct S20_st {
	enum parseType t; //E0x
	void *match; //struct of t
	char *ifTrue,
	     *ifFalse;
};
struct E01_st {
	enum parseType t; //T0x
	void *match; //struct of t
};
struct E02_st {
	enum parseType t[2]; //T0x
	void *match[2]; //structs of t[n]
};
struct E03_st {
	enum parseType t[2]; //T0x
	void *match[2]; //structs of t[n]
};
struct T01_st {
	enum parseType t; //F0x
	void *match;
};
struct T02_st {
	enum parseType t[2]; //F0x, E0x
	void *match[2];
};
struct T03_st {
	enum parseType t[2]; //F0x, E0x
	void *match[2];
};
struct T04_st {
	enum parseType t; //E0x
	void *match;
};
struct F01_st {
	int value;
};
struct F02_st {
	char *name;
};