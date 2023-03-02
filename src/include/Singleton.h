#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
    public:
    static T& Instance()
    {
        if (!_pInstance)
        {
            Create();
        }

        return *_pInstance;
    }
    protected:
    Singleton() {};
    Singleton(const Singleton&) = delete;

    ~Singleton()
    {
        _pInstance = nullptr;
    }
    void operator=(const Singleton&) = delete;

    inline static T* _pInstance = nullptr;
    static void Create() 
    {
        _pInstance = new T();
    }
};

	
#endif // SINGLETON_H
