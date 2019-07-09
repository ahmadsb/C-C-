
#include<cstring>
#include"person.h"
Person::Person(const char fullName[32], unsigned int id, unsigned char age):m_id(id), m_age(age){
    strncpy(m_fullName, fullName, sizeof(m_fullName) - 1);
    m_fullName[sizeof(m_fullName) - 1] = '\0';
}
Person::~Person(){}
// Person::Person(const Person & other){}
