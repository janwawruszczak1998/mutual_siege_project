#ifndef OBJECTCOUNTER_HPP
#define OBJECTCOUNTER_HPP

template <typename T>
class ObjectCounter
{
public:
    ObjectCounter(){
        counter_++;
    }
    ObjectCounter(const ObjectCounter& oc){
        counter_++;
    }
    virtual ~ObjectCounter(){
        counter_--;
    }

protected:
    static unsigned counter_;
};

template<typename T>
unsigned ObjectCounter<T>::counter_ = 0;

#endif // OBJECTCOUNTER_H
