//
//  Classe MergeSort
//  arquivo cpp
//  DEITEL

//---OnLooker

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "MergeSort.hpp"


// ==============================================
// --- Construtor ---
MergeSort::MergeSort(int vectorSize){
    sizeVec = (vectorSize > 0 ? vectorSize : 10);  //assegura que o tamanho do vetor ser� positivo
    srand(time(0));                                //srand para gerar n�meros aleat�rios

    for(int i=0;i<sizeVec;i++)
        dados.push_back(10+rand()%90);               //preenche o vetor automaticamente com n�meros de 10 a 99

}


// ==============================================
// --- Realiza a classifica��o por intercala��o ---
void MergeSort::sort(){
    sortSubVector(0, sizeVec-1,'a');  //classifica o vetor inteiro de forma recursiva
} 

void MergeSort::displayElements() const{
    displaySubVector(0, sizeVec-1);
} //end displayElements


// ==============================================
// --- Realiza a classifica��o do subvetor ---
void MergeSort::sortSubVector(int low,int high, char order){
    #ifdef MYDEBUG
    static int cnt = 0;
    cout << " Chamou sortSubVector: " << ++cnt << endl;
    cout << " Order: " << order << endl;
    #endif

  //caso b�sico de teste; tamanho do vetor � igual a 1
    if((high-low)>=1)
    {
        int middle1 = (low+high)/2;   //calcula meio do vetor
        int middle2 = middle1+1;      //calcula o pr�ximo elemento

        #ifdef MYDEBUG
        cout << "---------------" << endl;
        cout << "low=     " << low << endl;
        cout << "middle1= " << middle1 << endl;
        cout << "middle2= " << middle2 << endl;
        cout << "high=    " << high << endl;
        cout << "---------------" << endl;
        #endif

    //gera sa�da do passo de divis�o
        cout << "split   ";
        displaySubVector(low,high);
        cout << endl << "        ";
        displaySubVector(low,middle1);
        cout << endl << "        ";
        displaySubVector(middle2,high);
        cout << endl << endl;

    //divide o vetor pela metade, classifica cada metade
        sortSubVector(low, middle1,'b');   //primeira metade do vetor
        sortSubVector(middle2, high,'c');  //segunda metade do vetor

    //intercala 2 vetores classificados ap�s as chamadas de divis�o retornarem
        merge(low, middle1, middle2, high);
    } //end if

    #ifdef MYDEBUG
    cout << "==================\n"
         << "Order: " << order <<"  RETORNOU\n"
         << "==================\n";
    #endif

} //end sortSubVector


// ==============================================
// --- Mescla os subvetores ---
void MergeSort::merge(int left,int middle1,int middle2,int right){
    int leftIndex     = left;      //�ndice no subvetor esquerdo
    int rightIndex    = middle2;   //�ndice no subvetor direito
    int combinedIndex = left;      //�ndice no vetor de trabalho tempor�rio
    vector<int> combined(sizeVec); //vetor de trabalho

  //gera sa�da dos dois subvetores antes da intercala��o
    cout << "merge:  ";
    displaySubVector(left,middle1);
    cout << endl << "        ";
    displaySubVector(middle2, right);
    cout << endl;

  //intercala vetores at� alcan�ar o final de um deles
    while(leftIndex <= middle1 && rightIndex <= right){
    //insere o menor dos dois elementos atuais no resultado
    //e se move para o pr�ximo espa�o no vetor
        if(dados[leftIndex] <= dados[rightIndex])
            combined[combinedIndex++] = dados[leftIndex++];
        else
            combined[combinedIndex++] = dados[rightIndex++];

    } //end while

    if(leftIndex == middle2){
        while(rightIndex <= right)  //copia restante do vetor direito
        combined[combinedIndex++] = dados[rightIndex++];

    } //end if
    else{
    
        while(leftIndex <= middle1)  //copia restante do vetor esquerdo
          combined[combinedIndex++] = dados[leftIndex++];
    } 


  //copia valores de volta para o vetor original
    for(int i=left; i<=right; i++)
    dados[i] = combined[i];

  //gera sa�da do vetor intercalado
    cout << "        ";
    displaySubVector(left,right);
    cout << endl << endl;


} //end merge


// ==============================================
// --- Exibe o subvetor ---
void MergeSort::displaySubVector(int low,int high) const{
    for(int i=0; i<low; i++)
        cout << "   ";

    for(int i=low; i<=high;i++)
        cout << " " << dados[i];

}