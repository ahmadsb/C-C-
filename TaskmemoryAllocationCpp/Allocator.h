#ifndef ALLOCATOR_H
#define ALLOCATOR_H
template<typename T,unsigned long SIZE>
class Allocator :public T{
public:
    Allocator(const T& obj1);
    // ==========//
    //(1) solve Person 'class' with copy ctor. no good 
    //(2) solve this  good
    template<typename A1>
    Allocator(const A1& obj1):T(obj1) {}

    template<typename A1, typename A2>
    Allocator(const A1& obj1, const A2& obj2):T(obj1, obj2) {}

    template<typename A1, typename A2, typename A3>
    Allocator(const A1& obj1, const A2& obj2, const A2& obj3):T(obj1, obj2,obj3) {}
    // ...
    // ======
    static void* s_firstFree;
    static unsigned char s_pool[];

    static void* init_memoryPool();
    void* operator new  (size_t count );
    void operator delete(void * ptr);
private:
    void * operator new[] (size_t);
    void   operator delete[] (void*);
};

template <typename T,unsigned long SIZE>
unsigned char Allocator<T,SIZE>::s_pool[ sizeof(T) * SIZE];


template <typename T,unsigned long SIZE>
void* Allocator<T,SIZE>::s_firstFree = Allocator<T,SIZE>::init_memoryPool();

// ================ [ ctor ] =============//
template<typename T, unsigned long SIZE>
Allocator<T, SIZE>::Allocator(const T& obj1):T(obj1) {}


// ================ [ init. variable static ] =============//
template <typename T,unsigned long SIZE>
void * Allocator<T,SIZE>::init_memoryPool(){

    unsigned char * currFree = s_pool;

    for(size_t i = 0 ;i < SIZE - 1; ++i)
    {
        *(void**)currFree = currFree + sizeof(Allocator);
        currFree = currFree + sizeof(Allocator);
    }
    *(void**)currFree = 0;// NULL == 0 but in 'c' null == (void*) 0

    return s_pool;
}

// ================ [ function operator new ] =============//
template<typename T, unsigned long SIZE>
void* Allocator<T, SIZE>::operator new(size_t count) {
    if(s_firstFree == 0)
        throw std::bad_alloc();

    T* currFree = (T*)s_firstFree;

    s_firstFree =*(void**)s_firstFree;
    return currFree;
}

// ================ [ function operator new ] =============//
template<typename T, unsigned long SIZE>
void Allocator<T, SIZE>::operator delete(void *ptr) {
    *(void **)ptr = s_firstFree;
    s_firstFree = ptr;

}



#endif