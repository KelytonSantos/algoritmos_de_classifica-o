
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

    cout << "Vetor n\xc6o classificado:" << endl;
    sortVector.displayElements();               //apresenta vetor gerado
    cout << endl << endl;

    sortVector.sort();                          //classifica o vetor em ordem crescente

    cout << "Vetor classificado em ordem crescente:" << endl;
    sortVector.displayElements();               //imprime o vetor classificado

    cout << endl;

    cout << "\n\n Fim." << endl;
    while(1);
    return 0;
} 

