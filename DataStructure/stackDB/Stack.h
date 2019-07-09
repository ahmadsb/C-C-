#ifndef STACK_GENERATE_H
#define STACK_GENERATE_H
#include <vector>
template <typename T>
class Stack
{
  public:
    Stack(); // implicit
    bool empty();
    const T getSize();
    const T getTop() const;
    bool push(const T &value);
    T pop();

  private:
    T m_top;
    std::vector<T> m_arr;
    T m_size;
    //prevent coding
    ~Stack();
    Stack(const Stack &);
    Stack &operator=(const Stack &);
};

template <typename T>
Stack<T>::Stack() : m_top(-1), m_size(100)
{
}

template <typename T>
bool Stack<T>::empty()
{
    return (-1 == m_top);
}
template <typename T>
const T Stack<T>::getSize()
{
    return m_size;
}

template <typename T>
const T Stack<T>::getTop() const
{
    return arr[m_top];
}
template <typename T>
bool Stack<T>::push(const T &value)
{
    if (m_size - 1 == top)
        return false;
    m_arr[++top] = value;
    return true;
}

template <typename T>
T Stack<T>::pop()
{
    if (!empty())
        return arr[m_top--];
    return -1;
}

#endif