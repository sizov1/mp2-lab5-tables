#ifndef __TLIST_H
#define __TLIST_H
#define PTList TList<T>*

#include "tlink.h"
#include "exception.h"

template <typename T>
class TList
{
    protected:
        PTLink pHead;
    public:
        TList();
        TList(const TList<T>& q);

        bool IsEmpty() const;
        bool IsSort();  // функция проверяет список на упорядоченность элементов
        
        int GetLength() const;
        PTLink GetHead() const;
        PTLink GetFirst() const;
        PTLink GetLast() const;

        virtual void Insert(const T& val);   // вставить на нужное место (по убыванию)
        void Delete(PTLink pl); 

        void Merge(const TList<T>& q);
};

template <typename T>
TList<T>::TList()
{
    PTLink ph = new TLink<T>();   // выделяем память под фиктивную голову
    pHead = ph;
    pHead->pNext = pHead;     // замыкаем список на фиктивной голове
}

template <typename T>
TList<T>::TList(const TList<T>& q)
{
    PTLink ph = new TLink<T>();
    pHead = ph;
    ph->pNext = pHead;
    PTLink pq = q.pHead->pNext; // указатель, которым идём по списку q

    while (pq != q.pHead) {

        PTLink pc = new TLink<T>(pq->data);  // создаем дубликаты звеньев списка q
        ph->pNext = pc;                      // и добавляем эти дубликаты в новый список
        pc->pNext = pHead;                   // после каждой вставки замыкаем список на фиктивной голове

        ph = pc;
        pq = pq->pNext;
    }
    
}

template<typename T>
bool TList<T>::IsEmpty() const
{
    return (pHead->pNext == pHead);
}

template<typename T>
bool TList<T>::IsSort()
{
    PTLink pc = pHead->pNext;
    while (pc->pNext != pHead) {
        if ((pc->pNext)->data > pc->data) {
            return false;
        }
        pc = pc->pNext;
    }
    return true;
}

template <typename T>
int TList<T>::GetLength() const
{
    int length = 0;    
    PTLink pc = pHead->pNext;
    while (pc != pHead) {
        length++;
        pc = pc->pNext;
    }
    return length;
}

template <typename T>
PTLink TList<T>::GetHead() const
{
    return pHead;
}

template <typename T>
PTLink TList<T>::GetFirst() const
{
    if (pHead->pNext == pHead) {
        throw Exception("cannot get first for empty list");
    }
    return pHead->pNext;
}

template <typename T>
PTLink TList<T>::GetLast() const
{
    if (pHead->pNext == pHead) {
        throw Exception("cannot get last for empty list");
    }
    PTLink curr = pHead->pNext;
    while (curr->pNext != pHead) {
        curr = curr->pNext;
    }
    return curr;
}

template <typename T>
void TList<T>::Insert(const T& val)
{
    PTLink ins = new TLink<T>(val);  // создаем звено, которое будем вставлять
    PTLink prev = pHead;
    PTLink curr = pHead->pNext;

    if (prev == curr) {
        // список пустой => всталяем новое звено сразу после фиктивной головы
        pHead->pNext = ins;
        ins->pNext = pHead;
    }
    else {
        // ищем место для вставки нового звена
        while ((curr->data > ins->data) && (curr != pHead)) {
            curr = curr->pNext;
            prev = prev->pNext;
        }
        // вставляем новое звено на нужное место
        prev->pNext = ins;
        ins->pNext = curr;
    }   
}

template <typename T>
void TList<T>::Delete(PTLink pl)
{
    PTLink prev = pHead;
    PTLink curr = pHead->pNext;
    while (curr != pHead) {
        if (curr == pl) {
            prev->pNext = curr->pNext;
            return;
        }
        curr = curr->pNext;
        prev = prev->pNext;
    }
}

template <typename T>
void TList<T>::Merge(const TList<T>& q)
{
    PTLink pCurr = pHead;   // указатель на текущий в результирующем списке 

    PTLink pPrev1 = pHead;
    PTLink pPrev2 = q.pHead;
    PTLink pCurr1 = pHead->pNext;     // указатель, которым идём по первому списку
    PTLink pCurr2 = (q.pHead)->pNext; // указатель, которым идём по второму списку

                                      // идем двумя указателями по спискам
    while ((pCurr1 != pHead) && (pCurr2 != q.pHead)) {

        if ((pCurr1->data) > (pCurr2->data)) {
            // если элемент первого списка больше элемента второго списка 

            // двигаем указатель curr вперед, присваивая ему значение указателя 
            // больше элемента 
            pCurr->pNext = pCurr1;
            pCurr = pCurr1;

            // двигаем указатель, которым идем по первому списку
            pPrev1 = pCurr1;
            pCurr1 = pCurr1->pNext;
        }
        else {

            pCurr->pNext = pCurr2;
            pCurr = pCurr2;

            pPrev2 = pCurr2;
            pCurr2 = pCurr2->pNext;

        }
    }

    if (pCurr1 == pHead) {
        // первый список закончился => присоединяем остаток 
        pPrev1->pNext = pCurr2;
        while (pCurr2 != q.pHead) {
            pPrev2 = pCurr2;
            pCurr2 = pCurr2->pNext;
        }
        pPrev2->pNext = pHead;
    }
    else if (pCurr2 == q.pHead) {
        // второй список закончился => соединаяем с остатком первого 
        pPrev2->pNext = pCurr1;
    }

}


#endif