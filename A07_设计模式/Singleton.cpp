#include <iostream>
#include <pthread.h>
#include <unistd.h>

/**********************单线程单例类的实现**************************/
class Singleton_1{
public:
    static Singleton_1* GetSingletonObject(){
        if(m_singleton_object == nullptr){
            m_singleton_object = new Singleton_1();
        }
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
        if(m_singleton_object == nullptr){
            m_singleton_object = new Singleton_2();
        }
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
            if(m_singleton_object == nullptr){
                m_singleton_object = new Singleton_3();
            }
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

//Singleton_1, Singleton_2, Singleton_3都属于懒汉式单例模式，即需要的时候才实例化，初始化的时候是nullptr。这种需要处理线程安全问题。

//还有一种饿汉式单例模式，它是初始化就实例化，故需要提前占用系统资源,但它天然线程安全。
/********************饿汉式单例模式实现开始*********************/
class Singleton_4{
public:
    static Singleton_4* GetSingletonObject(){
        return m_singleton_object;
    }
private:
    Singleton_4() = default;
    static Singleton_4* m_singleton_object;
};
Singleton_4* Singleton_4::m_singleton_object = new Singleton_4();
/********************饿汉式单例模式实现结束*********************/

void* thread_1_fun(void* arg){
    Singleton_1* s1 = Singleton_1::GetSingletonObject();
    std::cout << s1 << std::endl;
}

void* thread_2_fun(void* arg){
    Singleton_1* s2 = Singleton_1::GetSingletonObject();
    std::cout << s2 << std::endl;
}

void* thread_3_fun(void* arg){
    Singleton_1* s3 = Singleton_1::GetSingletonObject();
    std::cout << s3 << std::endl;
}


int main(){
    pthread_t thread_1, thread_2, thread_3;
    pthread_create(&thread_1, NULL, &thread_1_fun, NULL);
    pthread_create(&thread_2, NULL, &thread_2_fun, NULL);
    pthread_create(&thread_3, NULL, &thread_3_fun, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);

    return 0;
}