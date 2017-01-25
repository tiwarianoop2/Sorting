#ifndef ALGODEF_H
#define ALGODEF_H
#include <iostream>
#include <cmath>
#include "SortingAlgo.h"

#define MAX 1
#define MIN 0

using namespace std ;
template <typename T>
class AlgoDef:public SortingAlgo<T>
{
    public:
        AlgoDef();
        virtual ~AlgoDef();
        /*!These are sorting function definitions     */
        void InsertionSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int contSize);
        void QuickSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2) ;
        void HeapSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size,int heap_type = MAX) ;
        void MergeSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2) ;
        void BuildMinHeap(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size) ;

    protected:

        /*!These are Helping function    */
        typename vector<T>::iterator QuickPartition(typename vector<T>::iterator it1, typename vector<T>::iterator it2) ;
        void ComparisonSwap(typename vector<T>::iterator it1, typename vector<T>::iterator it2) ;

        /*!HeapSort Helping function */
        void BuildMaxHeap(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size) ;
        //void BuildMinHeap(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size) ;
        void MaxHeapify(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int index, int heap_size) ;
        void MinHeapify(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int index, int heap_size) ;
        int LeftChild(int index, int heap_size) ;
        int RightChild(int index, int heap_size) ;

        /*!MergeSort Helping function*/
        void Merge(typename vector<T>::iterator it1,typename vector<T>::iterator itm, typename vector<T>::iterator it2) ;
    private:
};

template <typename T>
AlgoDef<T>::AlgoDef()
{
    //ctor
}
template <typename T>
AlgoDef<T>::~AlgoDef()
{
    //dtor
}
template <typename T>
int AlgoDef<T>::LeftChild(int index, int heap_size)
{
    int li = (2*index + 1) ;
    if(li > heap_size)
    return -1 ;
    else
    return li ;
}
template <typename T>
int AlgoDef<T>::RightChild(int index, int heap_size)
{
    int ri = (2*index + 2) ;
    if(ri > heap_size)
    return -1 ;
    else
    return ri ;
}
template <typename T>
void AlgoDef<T>::ComparisonSwap(typename vector<T>::iterator it1, typename vector<T>::iterator it2)
{
    T temp = *it1 ;
    *it1 = *it2 ;
    *it2 = temp ;
}

template <typename T>
void AlgoDef<T>::Merge(typename vector<T>::iterator it1, typename vector<T>::iterator itm, typename vector<T>::iterator it2)
{
    int i, j, k ;
    int n1 = itm - it1 + 1 ;
    int n2 =  it2 - itm ;

    /* create temp arrays */
    //array<T,n1> L ;
    //array<T,n2> R ;
    T *L = new T[n1] ;
    T *R = new T[n2] ;
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = *(it1 + i) ;
    for (j = 0; j < n2; j++)
        R[j] = *(itm + 1 + j) ;

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0 ; // Initial index of first subarray
    j = 0 ; // Initial index of second subarray

    /*!Below while loop exit, if either of sub array finish */

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            *it1 = L[i] ;
            i++ ;
        }
        else
        {
            *it1 = R[j] ;
            j++ ;
        }
        it1++ ;
    }

    /*! Check If either sub array remain */
    while (i < n1)
    {
        *it1 = L[i];
        i++;
        it1++;
    }

    /*! Check If either sub array remain */
    while (j < n2)
    {
        *it1 = R[j];
        j++;
        it1++;
    }

    delete []L ;
    delete []R ;
    L = NULL ;
    R = NULL ;
}

/*!Maxheapify target only one node, it will heapify its left/right subtree only, if it get swaped */
template <typename T>
void AlgoDef<T>::MaxHeapify(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int index, int heap_size)
{

    int l = LeftChild(index,heap_size) ;
    int r = RightChild(index,heap_size) ;
    int largest ;
    //std::cout<<"Left Child: "<<*(it1+(l-1))<<std::endl;
    //std::cout<<"Right Child: "<<*(it1+(r-1))<<std::endl;
    /*!
     * Since it1 always point to first element so, decrease left and right index.
     */
    if(l != -1 && l < heap_size && (*(it1 + l) > *(it1 + index)))
            largest = l ;
    else
            largest = index ;

    if(r != -1 && r < heap_size && (*(it1 + r) > *(it1 + largest)))
            largest = r ;

    if(largest!= index)
    {
        ComparisonSwap((it1+index), (it1+largest)) ;
        /*!We do Maxheapify inside "if clause" to ensure, affected subtree after swap get heapify" */
        MaxHeapify(it1,it2,largest, heap_size) ;
    }
}

template <typename T>
void AlgoDef<T>::MinHeapify(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int index, int heap_size)
{

    int l = LeftChild(index,heap_size) ;
    int r = RightChild(index,heap_size) ;
    int smallest ;
    //std::cout<<"Left Child: "<<*(it1+(l-1))<<std::endl;
    //std::cout<<"Right Child: "<<*(it1+(r-1))<<std::endl;
    /*!
     * Since it1 always point to first element so, decrease left and right index.
     */
    if(l != -1 && l < heap_size && (*(it1 + l) < *(it1 + index)))
            smallest = l ;
    else
            smallest = index ;

    if(r != -1 && r < heap_size && (*(it1 + r) < *(it1 + smallest)))
            smallest = r ;

    if(smallest != index)
    {
        ComparisonSwap((it1+index), (it1+smallest)) ;
        /*!We do Minheapify inside "if clause" to ensure, affected subtree after swap get heapify" */
        MinHeapify(it1,it2,smallest, heap_size) ;
    }
}

template <typename T>
void AlgoDef<T>::BuildMaxHeap(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size)
{
    for(int i = (floor(heap_size/2) - 1 ) ; i >= 0 ; --i)
    {
       MaxHeapify(it1,it2,i,heap_size) ;
    }
}

template <typename T>
void AlgoDef<T>::BuildMinHeap(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size)
{
    for(int i = (floor(heap_size/2) - 1 ) ; i >= 0 ; --i)
    {
       MinHeapify(it1,it2,i,heap_size) ;
    }
}

template <typename T>
typename vector<T>::iterator AlgoDef<T>::QuickPartition(typename vector<T>::iterator it1, typename vector<T>::iterator it2)
{
    //cout<<"I am inside Partition"<<endl ;
    int pivotElement = *(it2-1) ; //Take last element as pivot element.
    typename vector<T>::iterator it3 = it1 ;
    typename vector<T>::iterator it4 = it1 ;

    for(; it4 != (it2 -1) ; ++it4)
    {
        if(*it4 <= pivotElement)/*!At this point we donot decide partition around pivot. */
        {
            ComparisonSwap(it3,it4);
            /*! We increase this because in last we use this pointer,
             * to place pivot element at its correct position.
             */
            ++it3 ;
        }
    }
    /*! This swap ensure that pivot element get its right position and divide array around itself */

    ComparisonSwap(it3,(it2-1)) ;
    return it3 ;
}
//TO-DO Either ascending or descending order.
template <typename T>
void AlgoDef<T>::InsertionSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int contSize)
{
    if(contSize == 1)
        return ;
    typename vector<T>::iterator it3 = it1 ;
    typename vector<T>::iterator it4 ;
    it1 = it1 + 1 ;
    for(; it1 != it2 ; ++it1)
    {
        T key = *it1 ;
        it4 = it1 ;//Initialize inner loop pointer
        while(it4 != it3 && *(it4 - 1) > key)
        {
            ComparisonSwap(it4,(it4-1)) ;
            --it4 ;
        }
        *it4 = key ;
    }

}

template <typename T>
void AlgoDef<T>::QuickSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2)
{
    if(it1 < it2)
    {
        //cout<<"I am in QuickSort"<<endl ;
        typename vector<T>::iterator pivotIndex = QuickPartition(it1,it2) ;
        QuickSort(it1 , pivotIndex) ;
        QuickSort(pivotIndex+1 , it2) ;
    }
}

template <typename T>
void AlgoDef<T>::HeapSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size, int heap_type)
{
    if(heap_size == 1)
        return ;
    //TO-DO Max or Min heap
    if(heap_type == MAX)
    {

        cout<<"I am here in MAX : "<<heap_type<<endl ;
        BuildMaxHeap(it1,it2,heap_size) ;/*!This will create Max heap with largest element as root of the tree.*/
        for(int i = heap_size -1 ; i >= 0 ; --i)
        {
            ComparisonSwap(it1+i,it1) ;/*!swap is done because, root will always be largest element */
            //heap_size -= 1 ;
            MaxHeapify(it1,it2,0,i); /*!Here index is given as 0, because swap is done at this place */
        }
    }
    else if(heap_type == MIN)
    {
        cout<<"I am here in MIN : "<<heap_type<<endl ;
        BuildMinHeap(it1,it2,heap_size) ;/*!This will create Max heap with largest element as root of the tree.*/
        for(int i = heap_size-1 ; i >= 0 ; --i)
        {
            ComparisonSwap(it1+i,it1) ;/*!swap is done because, root will always be smallest element */
            //heap_size -= 1 ;
            MinHeapify(it1,it2,0,i); /*!Here index is given as 0, because swap is done at this place */
        }
    }
    else
    {
        cout<<"Wrong heap_type(last parameter) given in heap sort function !"<<endl ;
    }
}

template <typename T>
void AlgoDef<T>::MergeSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2)
{
    if(it1 < it2)
    {
        typename vector<T>::iterator itm ;
        int mid = floor((it2 - it1)/2) ;
        itm = it1 + mid ;
        MergeSort(it1, itm) ;
        MergeSort(itm+1, it2) ;
        Merge(it1,itm,it2) ;
    }
}
#endif // ALGODEF_H
