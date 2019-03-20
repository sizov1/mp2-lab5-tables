#ifndef __TLINK_H
#define __TLINK_H

#define PTLink TLink<T>*

// TLink - класс звена списка 

template <typename T>
class TList;

template <typename T>
class TLink
{
    private:
        PTLink pNext;
        T data;
    public:
        TLink();
        TLink(T val);
        TLink(const TLink<T>& t);

        T GetDatValue();
        PTLink GetNextLink();

        TLink<T>& operator += (const TLink<T>& q);   // сложение двух звеньев идущих друг за другом:
                                                     // 1) сложить data этих звеньев 
                                                     // 2) указатель на next переставить на next 

        friend class TList<T>;
        friend class Polynomial;
};

template <typename T>
TLink<T>::TLink()
{
    pNext = nullptr;
}

template <typename T>
TLink<T>::TLink(T val)
{
    pNext = nullptr;
    data = val;
}

template <typename T>
T TLink<T>::GetDatValue()
{
    return data;
}

template <typename T>
PTLink TLink<T>::GetNextLink()
{
    return pNext;
}

template <typename T>
TLink<T>& TLink<T>::operator += (const TLink<T>& q)
{
    (*this).data += q.data;
    (*this).pNext = q.pNext;
    return *this;
}



#endif