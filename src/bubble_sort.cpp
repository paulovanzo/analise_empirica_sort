#include "../include/bubble_sort.hpp"

void bubble (vector <int> &list){
    
    // Evaluates the length of the list
    size_t tam = list.size();

    // Runs across the array 
    for (size_t i = 0; i < tam-1; i++){
        for (size_t j = 0; j < tam-1; j++){
            
            // If the next element is greater then the current element, they switch positions
            if (list.at(j) > list.at(j+1)){
                int aux = list.at(j);
                list.at(j) = list.at(j+1);
                list.at(j+1) = aux;
            }
        }
    }
}