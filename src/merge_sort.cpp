#include "../include/merge_sort.hpp"

void merge_sort(vector <int> &list, int begin, int end){
    
    //  Checks if there's still elements to be sorted 
    if (begin < end){
        
        //  Sets the middle element index
        size_t mid = (size_t)begin + (end - begin) / 2;

        // Sorts the left side of the list
        merge_sort(list, begin, mid);

        // Sorts the right side of the list
        merge_sort(list, mid+1, end);

        // Sorts both sides together
        merge(list, (size_t)begin, mid, (size_t)end);

    }
}

void merge(vector <int> &list, size_t begin, size_t mid, size_t end){

    // Copies the orginal list into the auxiliar list
    vector <int> aux = list;
   
    //  Indexes that will be used to access elements in both original and auxiliar lists
    size_t i = begin, j = (mid + 1), k = begin;

    // Sorts the original list according to the auxiliar one
    while(i <= mid && j <= end){
        if(aux.at(i) <= aux.at(j)){
            list.at(k) = aux.at(i);
            i++;
        }else{
            list.at(k) = aux.at(j);
            j++;
        }
        k++;
    }

    //  Copies the rest of the left side of the auxiliar list into the original one
    while(i <= mid){
        list.at(k) = aux.at(i);
        k++;
        i++;
    }
}