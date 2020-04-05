#ifndef UTILS_UTILS_SINGLETON_H
#define UTILS_UTILS_SINGLETON_H

template <typename T>
class Singleton {
protected:
    Singleton() = default;;
    Singleton(Singleton const &) = default;;
public:
    static T & instance() {
        static T * instance = new T();
        return *instance;
    }
};

#endif //UTILS_UTILS_SINGLETON_H
