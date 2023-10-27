#include<iostream>
using namespace std;

int main(){
  // declare
  int total_person, total_film, target_id;
  int max_score, max_score_id, distance, choosed_id;

  // create id and their score list
  int** id_list = nullptr;
  int** score_list = nullptr;

  // create other recording array
  int* list_size = nullptr;
  int* read_score = nullptr;
  int* frequency_score = nullptr;
  int* distance_1 = nullptr;
  int* distance_2 = nullptr;

  // reading data from the input 
  cin >> total_person >> total_film >> target_id;

  // initiate the array
  id_list = new int*[total_person];
  score_list = new int*[total_person];
  list_size = new int[total_person];
  read_score = new int[total_film];
  frequency_score = new int[total_film];
  distance_1 = new int[total_person];
  distance_2 = new int[total_person];

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
        for(int k = 0; k < list_size[j]; k++){
          if(id_list[j][k] == (i + 1)){
            read_score[i] += score_list[j][k];
            frequency_score[i]++;
          }
        }
      }
    }
  }

  // compute distance_1 list and distance_2 list 
  for(int i = 0; i < total_person; i++){
    // initiate distance_1 and distance_2 to be -1
    distance_1[i] = -1;
    distance_2[i] = -1;

    for(int j = 0; j < list_size[j]; j++){
      for(int k = 0; k < list_size[target_id - 1]; k++){
        if(id_list[i][j] == id_list[target_id - 1][k]){
          distance_1[i] += abs(score_list[i][j] - score_list[target_id - 1][k]);
          if(id_list[i][j] == (i + 1)){
            distance_2[i] += 1;

          }
        }
        else{
          distance_1[i] += abs(score_list[i][j] - score_list[target_id - 1][k]);
        }
      }
    }
  }

  // find the highest scored movie (compute score first, if identity --> frequency)
  distance = distance_1[0];
  choosed_id = 0;
  max_score = 0;
  max_score_id = 0;
  for(int i = 0; i < total_person; i++){
    if(distance_1[i] < distance){
      distance = distance_1[i];
      choosed_id = i;   
    }
    else if(distance_1[i] == distance){
      if(distance_2[i] < distance_2[choosed_id]){
        distance = distance_2[i];
        choosed_id = i;     
      }     
    }
  }

  for(int i = 0; i < list_size[choosed_id]; i++){


  }
  if()
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



  // destruction
  // Free memory allocated
  for (int i = 0; i < total_person; i++) {
      delete[] id_list[i];
      delete[] score_list[i];
  }
  delete[] id_list;
  delete[] score_list;
  delete[] list_size;
  delete[] read_score;
  delete[] frequency_score;

  return 0;
}


