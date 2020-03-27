/*
 * tester.cpp
 *
 *  Created on: Mar 9, 2020
 *      Author: Tyler Baldwin
 */
#include <vector>
#include <thread>
#include <iostream>
#include <pthread.h>
#include "tester.h"
#include "print_ts.h"
//stores running and stopped threads
std::vector<std::thread> vecThreads(std::thread::hardware_concurrency());
bool pleaseStop;
params p;
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
		vecThreads.push_back(std::thread(threadJob, p));
	}
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	pleaseStop = bCancel;
	std::cout << USER_CHOSE_TO_CANCEL << '\n';
}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for (auto &t : vecThreads) {
		if (t.joinable()) {
			t.join();
		}
	}
}

//helper method to give to threads which importantly needs to be declared in the header I provdided
void threadJob(params give) {
	for (int i = 0; i < give.numTimesToPrint; i++) {
		if(pleaseStop){
					return;
		}
		switch (give.wp) {
		case P1:
			PRINT1(give.s);
			break;
		case P2:
			PRINT2(give.s, give.s);
			break;
		case P3:
			PRINT3(give.s, give.s, give.s);
			break;
		case P4:
			PRINT4(give.s, give.s, give.s, give.s);
			break;
		case P5:
			PRINT5(give.s, give.s, give.s, give.s, give.s);
			break;

		}
		std::this_thread::sleep_for(
				std::chrono::milliseconds(p.millisecond_delay));

	}

}

//my main method
int main() {
	pleaseStop = false;
	int numbThreads = std::thread::hardware_concurrency();

	startThreads("ABCD", numbThreads, P4, 300, 10);
	startThreads("xyz", numbThreads, P2, 400, 100);

	std::this_thread::sleep_for(
					std::chrono::milliseconds(1000));
	setCancelThreads(true);

	joinThreads();

}
