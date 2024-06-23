

#ifndef ONESTR_COUNTER_H

#define ONESTR_COUNTER_H

#include "string.h"
#pragma warning(disable: 4996)
#include <iostream>
class Counter {

public:

	char* m_pStr;

	size_t  m_nOwners;

	Counter* Next;

	static Counter* Head;

	static size_t m_curCounters;

	explicit Counter(const char* str);

	~Counter();

	void AddOwner();

	void RemoveOwner();

	static Counter* FindCounter(const char* str);

	static void PrintAll();

	static void ChangeRegister();

};
#endif
