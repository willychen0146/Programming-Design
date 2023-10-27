#include<iostream>
using namespace std;

int main(){
  // declare
  int total_person, total_film, target_id;
  int max_score, max_score_id;

  // create id and their score list
  int** id_list = nullptr;
  int** score_list = nullptr;

  // create other recording array
  int* list_size = nullptr;
  int* read_score = nullptr;
  int* frequency_score = nullptr;

  // reading data from the input 
  cin >> total_person >> total_film >> target_id;

  // initiate the array
  id_list = new int*[total_person];
  score_list = new int*[total_person];
  list_size = new int[total_person];
  read_score = new int[total_film];
  frequency_score = new int[total_film];

  // reading input and store them into id_list and score_list array
  for(int i = 0; i < total_person; i++)
  {
    cin >> list_size[i];
    // cout << list_size[i] << " ";

    // according the input list_size to create the array size
    id_list[i] = new int[list_size[i]];
    score_list[i] = new int[list_size[i]];

    // get different person movie id and score array
    for(int j = 0; j < list_size[i]; j++){
        cin >> id_list[i][j] >> score_list[i][j];
        // cout << id_list[i][j] << " " << score_list[i][j] << " ";
    }
    // cout << endl;
  }  

  // let read_score and frequency_score array element all be 0
  // If target person has seen the movie, change that read_score element to -1.
  for(int i = 0; i < total_film; i++){
    read_score[i] = 0;
    frequency_score[i] = 0;
    for(int j = 0; j < list_size[target_id - 1]; j++){
      if(id_list[target_id - 1][j] == (i + 1)){
        read_score[i] = -1;
      }
    }
  }

  // If read_score = 0, sum the total score to read_score array and record the frequency_score
  for(int i = 0; i < total_film; i++){
    if(read_score[i] == 0){
      for(int j = 0; j < total_person; j++){
        for(int k = 0;k < list_size[j]; k++){
          if(id_list[j][k] == (i + 1)){
            read_score[i] += score_list[j][k];
            frequency_score[i]++;
          }
        }
      }
    }
  }

  // find the highest scored movie (compute score first, if identity --> frequency)
  max_score = 0;
  max_score_id = 0;
  for(int i = 0; i < total_film; i++){
    if(read_score[i] > max_score){
      max_score = read_score[i];
      max_score_id = i;
    }
    else if(read_score[i] == max_score){
      if(frequency_score[i] > frequency_score[max_score_id]){
        max_score = read_score[i];
        max_score_id = i;
      }
    }
  }

  // output the result
  cout<< max_score_id + 1 << "," << frequency_score[max_score_id] << "," << read_score[max_score_id] << endl;




  // for(int i = 0; i < total_film; i++){
  //   cout<<read_score[i]<<" ";
  // }
  // for(int i = 0; i < total_film; i++){
  //   cout<<frequency_score[i]<<" ";
  // }

  // for(int i = 0; i < total_person; i++)
  // {
  //   cout << list_size[i] <<" ";
  //   for(int j=0;j<list_size[i];j++){
  //       cout << id_list[i][j]<<" "<<score_list[i][j]<<" ";
  //   }
  //   cout << endl;
  // }  



  return 0;
}

