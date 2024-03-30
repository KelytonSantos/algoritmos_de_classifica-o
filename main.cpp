
//  Algoritmos de Classifica��o
//  Classifica��o de vetor por intercala��o
//  bas. DEITEL
//---OnLooker

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "MergeSort.hpp"


// ==============================================
// --- Fun��o Principal ---
int main()
{

    MergeSort  sortVector(4);                   //cria o objeto vetor para classificar

    sortVector.displayElements();               //apresenta vetor gerado
    cout << endl << endl;

    sortVector.sort();                          //classifica o vetor em ordem crescente

    cout << endl;
    sortVector.displayElements();               //imprime o vetor classificado

    cout << endl;

    cout << "\n\n Fim." << endl;
    return 0;
} 

