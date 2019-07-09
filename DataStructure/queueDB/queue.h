#include <iostream>
#include <vector>

template <typename T>
class queue
{
  private:
    T m_front;
    T m_rear;
    size_t m_size;
    std::vector<T> m_arr;
    size_t m_capacity;
    // prevent coding : noncpopyable
    queue(const queue &);
    queue &operator=(const queue &);

  public:
    explicit queue(size_t size);
    bool empty();
    const T front();
    // ~queue(); we want to use in defualt dtor

    const size_t getSize() const;
    void push(const T &);
    T pop();
    bool isFull();
    size_t getSize();
};

template <typename T>
queue<T>::queue(size_t s) : m_capacity(s), m_front(0), m_rear(-1), m_size(0)
{
}

template <typename T>
bool queue<T>::empty()
{
    return (0 == m_size);
}

template <typename T>
bool queue<T>::isFull()
{
    return (getSize() == m_capacity);
}
template <typename T>
const T queue<T>::front()
{
    return m_arr[m_front];
}

template <typename T>
const size_t queue<T>::getSize() const
{
    return m_capacity;
}

template <typename T>
void queue<T>::push(const T &item)
{
    if (isFull())
        return;
    m_arr.push_back(item);
    ++m_rear;
    
    ++m_size;
}

template <typename T>
T queue<T>::pop()
{
    if (!empty())
    {
        --m_size;
        return m_arr[m_front++];
    }

    return -1; // throw exception
}

template <typename T>
size_t queue<T>::getSize()
{
    return m_size;
}