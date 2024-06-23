#include "Counter.h"

Counter::Counter(const char* str) {
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	m_nOwners = 1;
	Next = nullptr;
	if (Head == nullptr)
	{
		Head = this;
	}
	else
	{
		Counter* temp = Head;

		while (temp->Next != nullptr)
		{

			temp = temp->Next;
		}

		temp->Next = this;

	}
	m_curCounters++;
}

Counter::~Counter() {
	delete[] m_pStr;
	m_curCounters--;
}

void Counter::AddOwner() {
	m_nOwners++;
}

void Counter::RemoveOwner() {
	if (--m_nOwners == 0) {
		Counter* temp = Head;
		Counter* Prev = nullptr;
		while (temp != nullptr && temp != this)
		{
			Prev = temp;
			temp = temp->Next;
		}
		if (temp == this)
		{
			if (Prev != nullptr)
			{
				Prev->Next = this->Next;
			}
			else
			{
				Head = this->Next;
			}
		}
		delete this;
	}
}

Counter* Counter::FindCounter(const char* str) {
	Counter* temp = Counter::Head;
	while (temp != nullptr)
	{
		if (strcmp(temp->m_pStr, str) == 0)
		{
			return temp;

		}
		temp = temp->Next;
	}
	return nullptr;
}

void Counter::PrintAll() {
	Counter* temp = Counter::Head;
	int count = 1;
	while (temp != nullptr)
	{
		std::cout << "№ " << count++ << std::endl;
		std::cout << "Str: \n";
		std::cout << temp->m_pStr << std::endl;
		std::cout << "Owners: \n";
		std::cout << temp->m_nOwners << std::endl;
		std::cout << std::endl;
		temp = temp->Next;
	}
}

void Counter::ChangeRegister() {
	Counter* temp = Counter::Head;
	while (temp != nullptr)
	{
		size_t length = strlen(temp->m_pStr);
		for (int i = 0; i < length; i++)
		{
			if (temp->m_pStr[i] >= 'A' && temp->m_pStr[i] <= 'Z')
			{
				temp->m_pStr[i] += 32;
			}
			else if (temp->m_pStr[i] >= 'a' && temp->m_pStr[i] <= 'z')
			{
				temp->m_pStr[i] -= 32;
			}
		}
		temp = temp->Next;
	}
}



