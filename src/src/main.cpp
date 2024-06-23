#include "MyString.h"

using namespace std;

Counter* Counter::Head = nullptr;

size_t Counter::m_curCounters = 0;

int main()
{
	MyString c("s");

	MyString f("s");

	MyString d("hello");

	MyString f1("2");

	MyString f2 = std::move(c);

	MyString::ChangeRegister();

	MyString::PrintStrs();

	system("pause");

	return 0;

}
