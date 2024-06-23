
#ifndef ONESTR_MYSTRING_H
#define ONESTR_MYSTRING_H
#include "Counter.h"
class MyString {

public:

    Counter *m_pMyCounter;

    MyString();

    explicit MyString(const char * ptr);

    MyString(const MyString &oth);

    MyString (MyString && oth) noexcept;

    MyString& operator=(const MyString &oth);

    MyString& operator=(MyString && oth) noexcept;

    ~MyString();

    const char* Getstr();

    static void PrintStrs();

    static void ChangeRegister();

};
#endif
