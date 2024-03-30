//
//  Classe MergeSort
//  arquivo hpp
//  DEITEL
//--OnLooker

#ifndef  MERGESORT
#define  MERGESORT
//#define  MYDEBUG

// ==============================================
// --- Bibliotecas ---
#include <vector>
using std::vector;


// ==============================================
// --- Classe ---
class MergeSort
{
  public:
    MergeSort(int);                //construtor inicializa vetor
    void sort();                   //classifica��o por intercala��o
    void displayElements() const;  //exibe elementos do vetor

  private:
    int sizeVec;                          //tamanho do vetor
    vector<int> dados;                    //vetor de ints
    void sortSubVector(int,int,char);     //classifica o subvetor
    void merge(int,int,int,int);          //mescla os dois vetores classificados
    void displaySubVector(int,int) const; //exibe o subvetor


}; //end class



#endif










// ==============================================
// --- Fim. ---
