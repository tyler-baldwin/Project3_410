/*
 * print_ts.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: Tyler Baldwin
 */
#include "print_ts.h"
#include <mutex>
#include <iostream>

std::mutex mutt;

void PRINT1(std::string &txt) {
	mutt.lock();
	std::cout << txt;
	mutt.unlock();
}
void PRINT2(std::string &txt, std::string &txt1) {
	mutt.lock();
	std::cout << txt << txt1;
	mutt.unlock();
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	mutt.lock();
	std::cout << txt << txt1 << txt2;
	mutt.unlock();
}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3) {
	mutt.lock();
	std::cout << txt << txt1 << txt2 << txt3;
	mutt.unlock();

}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2,
		std::string &txt3, std::string &txt4) {
	mutt.lock();
	std::cout << txt << txt1 << txt2 << txt3 << txt4;
	mutt.unlock();

}
