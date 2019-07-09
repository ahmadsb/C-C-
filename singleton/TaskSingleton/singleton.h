#ifndef MY_SINGLETON_H
#define MY_SINGLETON_H

template < typename T >
class Singleton 
{
public:
    static T* getInstance();
    const T get();
    virtual ~Singleton();
private:
    static T * m_instance = 0;
      /* prevent copying */
    Singleton();
    Singleton(const Singleton&);
    Singleton& operator= (const Singleton&);
};

template <typename T >
Singleton<T>::Singleton() { };

template <typename T >
Singleton<T>::~Singleton()
{
        delete m_instance;
        m_instance = 0;
}

template <typename T >
T* Singleton<T>::getInstance()
{
    while(true){
        if (!m_instance)
        {
            if (__sync_bool_compare_and_swap(&m_instance, 0, (Singleton *) 1))
            {
                /*assignment to be atmoic opreation*/
                T *ptemp = new T();
                asm volatile("": : :"memory");
                m_instance = ptemp;
                break;
            }
        }
        asm volatile("rep; nop\n": : :"memory");
        break;
    }
       
    return m_instance;
}

template<typename T>
const T Singleton<T>::get(){return *m_instance;}


#endif

