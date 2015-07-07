#include <stdbool.h>

#ifndef AST_BOOL_H
#define AST_BOOL_H

extern char *next; //ptr to input stream
extern void *parseData; //ptr to struct type returned
extern struct AST_block *AST;

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
bool S21();

bool E01();
bool E02();
bool E03();

bool T01();
bool T02();
bool T03();
bool T04();

bool F01();
bool F02();

#endif
