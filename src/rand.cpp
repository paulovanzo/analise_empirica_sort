#include <ctime>
#include <fstream>
#include "../include/rand.hpp"

void generate(){

    std::ofstream arquivo;

	arquivo.open(("../data/vectors.txt"));

    srand(time(NULL));

    for (int tam = 10; tam < 500; tam+=10)
    {
      for (int k = 0; k < 50; ++k)
      {
        for (int i = 0; i < tam; ++i)
        { 
          arquivo << 1+rand()%tam << " ";
        }
        arquivo << "\n";
	    }
    }

	arquivo.close();

}