#This library works only on Sequential Containers


#Command to execute client program with library


g++ -o Client ClientApp.cpp -I ../Sorting/Sorting/include -L ../Sorting/Sorting/bin/Debug/ -lSorting


#Sorting inputs

1)InsertionSort(begin,end,size);
2)QuickSort(begin,end,size);
3)HeapSort(begin,end,size);
4)HeapSort(begin,end,size,heap_type);//Overloaded Funtion
5)MergeSort
