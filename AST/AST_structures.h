#ifndef AST_STRUCT_H
#define AST_STRUCT_H

#define ETNOCODE 0x0000
#define ETS07 0x0005
enum parseType {
	tNOCODE = ETNOCODE,
	tERR	= 0x0001,
	tS01	= ETNOCODE,
	tS02	= ETNOCODE,
	tS03	= ETNOCODE,
	tS19	= ETNOCODE,
	tS11	= ETS07,
	tS04	= 0x0002,
	tS05	= 0x0003,
	tS06	= 0x0004,
	tS07	= ETS07,
	tS08	= 0x0006,
	tS09	= 0x0007,
	tS10	= 0x0008,
	tS12	= 0x0009,
	tS13	= 0x000A,
	tS14	= 0x000B,
	tS15	= 0x000C,
	tS16	= 0x000D,
	tS17	= 0x000E,
	tS18	= 0x000F,
	tS20	= 0x0010,
	tE01	= 0x0011,
	tE02	= 0x0012,
	tE03	= 0x0013,
	tT01	= 0x0014,
	tT02	= 0x0015,
	tT03	= 0x0016,
	tT04	= 0x0017,
	tF01	= 0x0018,
	tF02	= 0x0019
};
struct AST_block_node {
	enum parseType t;
	void *match;
	struct AST_block_node *next;
};
struct AST_block {
	struct AST_block_node *head,
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
	struct AST_block *statements;
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

#endif
