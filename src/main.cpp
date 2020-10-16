#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "../include/bubble_sort.hpp"
#include "../include/merge_sort.hpp"
#include "../include/selection_sort.hpp"
#include "../include/rand.hpp"

int main()
{

	generate();

	std::ifstream vectors;
	
    std::ofstream output_bubble;
    std::ofstream output_merge;
    std::ofstream output_selection;

	vectors.open("../data/vectors.txt");

    output_bubble.open("../output_bubble.txt");
    output_merge.open("../output_merge.txt");
    // output_selection.open("../output_selection.txt");

    //O que nosso algoritmo vai buscar

    std::string v;

	for (int indexI{50}; indexI <= 500; indexI += 50)
	{   
        int bubble_values[50]{};
       	int merge_values[50]{};
        // int selection_values[50];

        int bubble_sum{0};
        int merge_sum{0};
        // int selection_sum{0};

        int bubble_average{0};
        int merge_average{0};
        // int selection_average{0};

		std::vector<int> list; //Inicialização do vector
        
		for (int indexJ{0}; indexJ < 50; indexJ++)
		{
			std::stringstream stream(v);

			getline(vectors,v); // Pega cada linha

        	// Percorre toda a stringstream com os valores da string {v} e insere em std::vector<int>list

			for(int h{0}; h < indexI; ++h){
            	int k;
            	stream >> k;
            	list.push_back(k);
        	}

			std::vector<int> listcp1 = list;
			std::vector<int> listcp2 = list;
			// std::vector<int> listcp3 = list;
			
			//Tempo de execução do bubble sort
			auto start_time = chrono::steady_clock::now();

			bubble( listcp1 );

			auto end_time = chrono::steady_clock::now();
			auto difference = end_time - start_time;

			bubble_values[indexJ] = chrono::duration<long double, milli>(difference).count();

			//Tempo de execução do selection sort
			/*
			start_time = chrono::steady_clock::now();

			selection( listcp3 );

			end_time = chrono::steady_clock::now();
			difference = end_time - start_time;

			selection_values[indexJ] = chrono::duration<long double, milli>(difference).count();

			*/

            //Tempo de execução do merge sort
			start_time = chrono::steady_clock::now();

			merge_sort ( listcp2, 0 , listcp2.size()-1 );

			end_time = chrono::steady_clock::now();
			difference = end_time - start_time;

			merge_values[indexJ] = chrono::duration<long double, milli>(difference).count();

			std::cout << "Tamanho: " << indexI  << " Teste: " <<  indexJ << std::endl;
		}
		// Média dos tempos
		for (int indexJ{0}; indexJ < 50; indexJ++)
		{
			bubble_sum += bubble_values[indexJ];
			merge_sum += merge_values[indexJ];
            // selection_sum += selection_values[indexJ];
		}

		bubble_average = bubble_sum / 50;
		merge_average = merge_sum / 50;
        // selection_average = selection_sum / 50;

		//Imprimindo as médias nos arquivos de saída
		output_bubble << indexI << " " << bubble_average << endl;
		output_merge << indexI << " " << merge_average << endl;
        // output_selection << indexI << " " << selection_average << endl;

	}

	//Fechando as instancias arquivos de saida
	vectors.close();
	output_bubble.close();
	output_merge.close();
    // output_selection.close();

	return 0;
}