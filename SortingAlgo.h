#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <vector>
using namespace std;
template <typename T>
class SortingAlgo
{
    public:
        SortingAlgo();
        ~SortingAlgo();
//        vector<int> vec ;
        void GetSorting(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int sortType)
        {
            switch(sortType)
            {
                case 1:
                    this->InsertionSort(it1,it2);
                    break ;
                default :
                    cout<<"Sorting Type not defined"<<endl;
            }
        }
        virtual void InsertionSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int contSize) = 0 ;
        virtual void QuickSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2) = 0 ;
        virtual void HeapSort(typename vector<T>::iterator it1, typename vector<T>::iterator it2, int heap_size, int heap_type) = 0 ;
       /*
        virtual void BubbleSort() = 0 ;
        virtual void SelectionSort() = 0 ;
        virtual void MergeSort() = 0 ;
        virtual void HeapSort() = 0 ;
        virtual void RQuickSort() = 0 ;/*!Random QuickSOrt */
     protected:
    private:
};

template <typename T>
SortingAlgo<T>::SortingAlgo()
{
    //ctor
}
template <typename T>
SortingAlgo<T>::~SortingAlgo()
{
    //dtor
}

#endif // SORTINGALGO_H
