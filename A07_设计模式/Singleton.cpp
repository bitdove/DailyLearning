#include <iostream>

/**********************单线程单例类的实现**************************/
class Singleton_1{
public:
    static Singleton_1* GetSingletonObject(){
        if(m_singleton_object == nullptr)
            m_singleton_object = new Singleton_1();
        return m_singleton_object;
    }
private:
    Singleton_1() = default;
    static Singleton_1* m_singleton_object;
};
Singleton_1* Singleton_1::m_singleton_object = nullptr;
/********************单线程单例类实现结束*************************/

/**********************多线程单例类的实现*************************/
class Singleton_2{
public:
    static Singleton_2* GetSingletonObject(){
        pthread_mutex_lock(&m_mutex);
        if(m_singleton_object == nullptr)
            m_singleton_object = new Singleton_2();
        pthread_mutex_unlock(&m_mutex);
        return m_singleton_object;
    }
private:
    Singleton_2() = default;
    static pthread_mutex_t m_mutex;
    static Singleton_2* m_singleton_object;
};
Singleton_2* Singleton_2::m_singleton_object = nullptr;
pthread_mutex_t Singleton_2::m_mutex = PTHREAD_MUTEX_INITIALIZER;
/********************多线程单例类实现结束**************************/

/********************多线程Double-Check单例类的实现***************/
class Singleton_3{
public:
    static Singleton_3* GetSingletonObject(){
        if(m_singleton_object == nullptr){
            pthread_mutex_lock(&m_mutex);
            if(m_singleton_object == nullptr)
                m_singleton_object = new Singleton_3();
            pthread_mutex_unlock(&m_mutex);
        }
        return m_singleton_object;
    }
private:
    Singleton_3() = default;
    static pthread_mutex_t m_mutex;
    static Singleton_3* m_singleton_object;
};
Singleton_3* Singleton_3::m_singleton_object = nullptr;
pthread_mutex_t Singleton_3::m_mutex = PTHREAD_MUTEX_INITIALIZER;
/******************多线程Double-Check单例类实现结束****************/


int main(){
    Singleton* s1 = Singleton::GetSingletonObject();
    Singleton* s2 = Singleton::GetSingletonObject();
    if(s1 == s2)
        std::cout << "s1 and s2 are same instance" << std::endl;
    return 0;
}