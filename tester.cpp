/*
 * tester.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: Tyler Baldwin
 */
#include <vector>
#include <thread>
#include <iostream>
//#include <pthread.h>
#include "tester.h"
#include "print_ts.h"
//stores running and stopped threads
std::vector<std::thread> vecThreads(std::thread::hardware_concurrency());
bool pleaseStop;
struct params {
	std::string s;
	WHICH_PRINT wp;
	int numTimesToPrint;
	int millisecond_delay;
} p;
/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp,
		int numTimesToPrint, int millisecond_delay) {

	p.s = s;
	p.wp = wp;
	p.numTimesToPrint = numTimesToPrint;
	p.millisecond_delay = millisecond_delay;

	for (int i = 0; i < numThreads; i++) {
		//vecThreads.push_back(std::thread t(threadJob, s, wp, numTimesToPrint, millisecond_delay));
		vecThreads.push_back(std::thread(threadJob));
		//vecThreads.push_back(std::thread(joinThreads));
		//t.join();
	}

//	for (int i = 0; i < numThreads / 2; i++) {
//		switch (wp) {
//		case P1: {
//			std::thread p1 (PRINT1, s);
//			vecThreads.push_back(p1);
//		}
//			break;
//		case P2:
//			break;
//		case P3:
//			break;
//		case P4:
//			break;
//		case P5:
//			break;
//
//		}

}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {

}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for (auto &t : vecThreads) {
		t.join();
	}
}

void threadJob() {

	for (int i = 0; i < p.numTimesToPrint; i++) {
		switch (p.wp) {
		case P1:
			PRINT1(p.s);
			break;
		case P2:
			PRINT2(p.s, p.s);
			break;
		case P3:
			PRINT3(p.s, p.s, p.s);
			break;
		case P4:
			PRINT4(p.s, p.s, p.s, p.s);
			break;
		case P5:
			PRINT5(p.s, p.s, p.s, p.s, p.s);
			break;

		}

		//std::this_thread::sleep_for(std::chrono::milliseconds(p.millisecond_delay));

	}

}

int main() {
	pleaseStop = false;
	int numbThreads = std::thread::hardware_concurrency();

	startThreads("A", numbThreads, P2, 4, 1000);
	startThreads("B", numbThreads, P3, 5, 1000);

	//joinThreads();

}
