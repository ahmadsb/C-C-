
// test --> index with expeected
#ifndef PERSON_H
#define PERSON_H
class Person{
public:
    Person(const char fullName[32], unsigned int id, unsigned char age);
    ~Person();
    // Person(const Person&other);
private:
    unsigned int m_id;
    unsigned char m_age;
    char m_fullName[32];
   
};

#endif

