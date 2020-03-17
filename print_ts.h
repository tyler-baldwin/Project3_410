#pragma once
#ifndef PRINT_TS_H_
#define PRINT_TS_H_
#include <string>

//create threadsafe implementations of the following functions
//example
//string s1 = "t";
//string s2 = "s";
//PRINT2(s1,s2);
//PRINT3(s1,s2,s1);
//should output
//ts
//tst
void PRINT1(std::string &txt);
void PRINT2(std::string &txt, std::string &txt1);
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2);
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3);
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4);

#endif /* PRINT_TS_H_ */
