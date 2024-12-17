#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
const long long int maxTam = 1000000;

//cache 
vector<long long int> cache (maxTam, 0);

//passos 
//1 - criar cache, vetor para cada número, tamanho de 100000
//2 - Verificar se o número já existe no cache 
//3- Se existe não precisa continuar a fazer os passos do número
//4 - atualizar cache

long long int sequenciaAte1(long long int n){

    int sequenciaTotal = 1;

    if (n == 1){
        return 1;
    }

    if (n < maxTam && cache[n] != 0) return cache[n];

    if (n % 2 == 0){
        sequenciaTotal += sequenciaAte1(n/2); 
    }else{
        sequenciaTotal += sequenciaAte1((n*3)+1);
    }

    //atualizando cache
    if(n < maxTam) cache[n] = sequenciaTotal;
    return sequenciaTotal;
 
};

int main() {

    int sequenciaAtual = 0;
    int sequenciaMaxima = 0;
    int maiorNumero = 0;
    auto tempo_inicio = chrono::high_resolution_clock::now();
    for (int i =1; i<= maxTam; i++){
        sequenciaAtual = sequenciaAte1(i);
        if (maiorNumero == 0 ) maiorNumero = i;
        else {
            if (sequenciaAtual > sequenciaMaxima){
                sequenciaMaxima = sequenciaAtual;
                maiorNumero = i;
            }
        }
    }

    auto tempo_fim = chrono::high_resolution_clock::now();
    long long int tempo_total = chrono::duration_cast<chrono::milliseconds>(tempo_fim - tempo_inicio).count();
    cout << "Maior número:" << maiorNumero << endl;
    cout << "Sequencia:" << sequenciaMaxima << endl;
    cout << "Tempo: " << tempo_total;
  return 0;
}