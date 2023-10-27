#include<iostream>
using namespace std;

int main(){
  // declare
  int total_person, total_film, target_id, closest_distance, closest_distance_id;
  int max_score, max_score_id;

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

  // compute distance_1 list
  for(int i = 0; i < total_person; i++){
    distance_1[i] = 0;
    int j = 0;
    int k = 0;

    while (j < list_size[i] && k < list_size[target_id - 1]) {
      if (id_list[i][j] == id_list[target_id - 1][k]) {
        distance_1[i] += abs(score_list[i][j] - score_list[target_id - 1][k]);
        j++; // Move to the next movie for both users
        k++;
      } else if (id_list[i][j] < id_list[target_id - 1][k]) {
        distance_1[i] += score_list[i][j];
        j++; // Move to the next movie for the current user
      } else {
        distance_1[i] += score_list[target_id - 1][k];
        k++; // Move to the next movie for the target user
      }
    }

    // Handle the case where one user has seen more movies
    while (j < list_size[i]) {
      distance_1[i] += score_list[i][j];
      j++;
    }

    while (k < list_size[target_id - 1]) {
      distance_1[i] += score_list[target_id - 1][k];
      k++;
    }
    // cout << distance_1[0] << " ";
  }

  // compute distance_2 list
  for (int i = 0; i < total_person; i++) {
    distance_2[i] = 0;
    int j = 0;
    int k = 0;

    while (j < list_size[i] && k < list_size[target_id - 1]) {
      if (id_list[i][j] == id_list[target_id - 1][k]) {
        // Both users have seen the movie, distance is 0
        j++; // Move to the next movie for both users
        k++;
      } else if (id_list[i][j] < id_list[target_id - 1][k]) {
        // Only the current user has seen the movie
        distance_2[i] += 1;
        for(int l; l < list_size[target_id - 1]; l++){
          if(id_list[i][j] == id_list[target_id - 1][l]);
          distance_2[i] -= 1;
        }
        j++; // Move to the next movie for the current user
      } else {
        // Only the target user has seen the movie
        distance_2[i] += 1;
        for(int l; l < list_size[target_id - 1]; l++){
          if(id_list[i][j] == id_list[target_id - 1][l]);
          distance_2[i] -= 1;
        }
        // cout << distance_2[2] << " ";
        k++; // Move to the next movie for the target user
      }
    }
    // cout << distance_2[2] << " ";

    // Handle the case where one user has seen more movies
    while (j < list_size[i]) {
      distance_2[i] += 1;
      j++;
    }

    while (k < list_size[target_id - 1]) {
      distance_2[i] += 1;
      k++;
    }
  }
  // cout << distance_2[0] << " ";
  // cout << distance_2[1] << " ";
  // cout << distance_2[2] << " ";

  // Find the most similar person
  // Computing first algorithm --> distance_1
  closest_distance = 100000; // let the distance be very big first
  int closest_distance_2 = 0;
  closest_distance_id = 0;
  for(int i = 0; i < total_person; i++){
    if(distance_1[i] < closest_distance && (i != (target_id - 1))){
      closest_distance = distance_1[i];
      closest_distance_id = i;
    }
    else if(distance_1[i] == closest_distance && (i != (target_id - 1))){
      // If distance_1 is identity -->  computing distance_2
      // if(distance_2[i] < distance_2[closest_distance_id] && (i != (target_id - 1))){
      if(distance_2[i] < distance_2[closest_distance_id] && (i != (target_id - 1))){
        closest_distance_id = i;
        // cout << closest_distance_id << " ";
      }
      // else{
      //   closest_distance_id = closest_distance_id;
      // }
    }
  }
  // cout << closest_distance_id << " ";

  // Find the highest scored movie
  // first use the distance_1 and distance_2 to find the movie
  max_score = 0;
  max_score_id = -1;
  for(int i = 0; i < list_size[closest_distance_id]; i++){
    // find the highest score but the target didn't see it
    if(score_list[closest_distance_id][i] > max_score){
      max_score = score_list[closest_distance_id][i];
      max_score_id = id_list[closest_distance_id][i];
      for(int j = 0; j < list_size[target_id - 1]; j++){
        if(max_score_id == id_list[target_id - 1][j]){
          max_score = 0;
          max_score_id = -1;
        }
      }
      // cout << max_score_id;
    }
  }  
  // cout << max_score_id;

  // if the movie see by most similar person, is all seen by our target, use the old algorithm from part 3
  if(max_score_id == -1){
    max_score = 0;
    max_score_id = -1;
    for(int i = 0; i < total_film; i++){
      if(read_score[i] > max_score){
        max_score = read_score[i];
        max_score_id = i + 1;
      }
      else if(read_score[i] == max_score){
        if(frequency_score[i] > frequency_score[max_score_id]){
          max_score = read_score[i];
          max_score_id = i + 1;
        }
        else if(frequency_score[i] == frequency_score[max_score_id]){
          // if frequency is identity，choose the smaller id
          if(i < max_score_id){
            max_score_id = i + 1;
          }
        }
      }
    }
    // cout << max_score_id << " ";
  }

  // if no one had seen the highest score movie，choose the smaller id
  if(max_score_id == -1){
    for(int i = 0; i < total_film; i++){
      if(read_score[i] == 0){
        max_score_id = i + 1;
        break;
      }
    }
  }

  // output the result
  cout<< max_score_id << "," << frequency_score[max_score_id - 1] << "," << read_score[max_score_id - 1] << endl;

  // destruction
  // Free memory allocated and set the pointer to nullptr
  for (int i = 0; i < total_person; i++) {
      delete[] id_list[i];
      delete[] score_list[i];
  }
  delete[] id_list;
  delete[] score_list;
  delete[] list_size;
  delete[] read_score;
  delete[] frequency_score;

  id_list = nullptr;
  score_list = nullptr;
  list_size = nullptr;
  read_score = nullptr;
  frequency_score = nullptr;

  return 0;
}
