//Aluno: Bruno William Varela da Silva TADS 2021

#include <iostream>

using namespace std;

float fMedias(float n1, float n2, float n3){ //questao 2 - fazer a media do aluno
  float result;
  result = (n1 + n2 + n3) / 3;
  return result;
}

void fSituacao(float situacao){ //questao 3 - fazer a situaçao cujo o aluno se encontra
  if(situacao < 3){
    cout << "REPROVADO, TENTE NOVAMENTE.";
  }else{
    if((situacao >= 3) && (situacao < 7)){
    cout << "RECUPERACAO, VOCE TERA OUTRA CHANCE.";
    }else{
      if(situacao >= 7){
      cout << "APROVADO, PARABENS.";
      }
    }
  }
  return;
}

int fMaior(int idadeM){ //questao 4 - pegar a maior idade dentre os 10 alunos
  int maiorM, maior, posicaoM, i;
  for(i = 1; i < 10; i++){
   if(idadeM > maiorM){
    maior = idadeM;
    posicaoM = i;
   }
  }
  return maior;
}

int fMediaGeral(float n1, float n2, float n3, float n4, float n5, float n6, float n7, float n8, float n9, float n10){ //questao 5 - pegar todas as notas dos 10 alunos e dividir por 10 para saber a media
  int i;
  float result;
  for(i = 0;i < 10;i++){
    result = (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;
  }
  return result;
}

int main() {
  int i, j, situacao1, maior, posicaoM;
  float notasAl, todasNotas;
  
  struct Aluno{ //questao 1 - declarar todas as variaveis para registro do aluno
    char nome[40];
    int idade;
    float media[10];
    float notas[3]; 
  };//definição struct
    struct Aluno turma[10]; //vetor com 10 posicoes para guardar a nota dos 10 alunos

    cout << "\n============BEM VINDO(A) AO SISTEMA DE NOTAS UFRN============\n";

  for(i = 0; i < 10; i++){ //usar o "for" pois sabemos que são 10 notas que serão recebidas;
    
    cout << "\n\t\t\t\t ==========ALUNO " << i+1 << "==========";
    cout << "\nINFORME SEU NOME (SOMENTE O PRIMEIRO NOME É NECESSARIOS) : ";
    cin >> turma[i].nome;

    cout << "\nINFORME SUA IDADE : ";
    cin >> turma[i].idade;

    for(j = 0; j < 3; j++){ //usando "for" novamente, pois 3 notas vão ser recebidas;
      cout << "\nINFORME SUA NOTA DA AV." << j+1 << ": ";
      cin >> turma[i].notas[j];
    }
    //chamar funçao
    notasAl = fMedias(turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]); //passar as 3 medias para receber a situacao e a media
    cout << "================================================";
    cout << "\nSUA MEDIA FOI: " << notasAl << endl;
    turma[i].media[i] = notasAl;
    cout << "================================================\n";
    fSituacao(notasAl);
    posicaoM = i;
    
    cout << "\n";
    maior = turma[0].idade; //subistituir a variavel para passar (fora do main) e receber o resultado
    maior = fMaior(turma[i].idade);

    // turma[i].media[i] = turma[i].media[i] + notasAl;

    
  }

  todasNotas = fMediaGeral(turma[0].media[0], turma[1].media[1], turma[2].media[2], turma[3].media[3], turma[4].media[4], turma[5].media[5], turma[6].media[6], turma[7].media[7], turma[8].media[8], turma[9].media[9]); //enviando todas as medias para o escopo de cima, para que seja calculada a media de todos os 10 alunos

  cout << "\nA MAIOR IDADE É DE: " << maior << " E O ALUNO ESTA NA POSIÇAO: " << posicaoM;
  
  cout << "\nA MEDIA GERAL FOI DE: " << todasNotas;

  return 0;
}