/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: James Baron
 */
#include "./includes/Smalltalk.h"
#include "./includes/constants.h"
#include "./includes/Watch.h"
std::string nationality;
int iPerson;
int current_phrase;
std::vector<std::string> mySmallTalk;
std::unique_ptr<Watch> pWatch;

Smalltalk::Smalltalk(std::string myNationality, int iPerson) :
		nationality(myNationality), iPerson(iPerson) {
	current_phrase = 0;
	pWatch = 0;
}
Smalltalk::~Smalltalk(void) {
	if (pWatch != 0) {
		pWatch.reset();
	}
}
std::string Smalltalk::saySomething() {
	if (current_phrase >= mySmallTalk.size()) {
		current_phrase = 0;
	}
	return mySmallTalk[current_phrase++];

}
std::string Smalltalk::getTime() {
	if (pWatch != 0) {
		Watch *tmp = pWatch.get();
		return tmp->getTime();
	} else {
		return I_DO_NOT_HAVE_A_WATCH;
	}
}
std::unique_ptr<Watch> Smalltalk::takeWatch() {
	if (pWatch != 0) {
		std::unique_ptr<Watch> tmpWatch(std::move(pWatch));
		pWatch = 0;
		return tmpWatch;
	} else {

		return std::unique_ptr<Watch>(nullptr);
	}
}
bool Smalltalk::giveWatch(std::unique_ptr<Watch> &pWatch) {
	if (this->pWatch != NULL) {
		return false;
	}
	this->pWatch = std::move(pWatch);
	return true;
}

