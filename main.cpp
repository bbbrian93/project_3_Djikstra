#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
double findMin(vector<double>numbers);
vector<double>eraseMin(vector<double>numbers,double minNumber);
int main() {
  fstream file;
  double array[21][21];
  string x,y;
  string z;
  int int_x,int_y;
  double double_z;

  file.open("net.txt");
  if (!file){
    cout<<"Error in opening file";
    return 0;
  }
  //initialize array
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
    array[i][j]=-1;
    }}
    //fill in array with inputs
  while(!file.eof()){
  file>>x;
  int_x = stoi(x);
  file>>y;
  int_y = stoi(y);
  file>>z;
  double_z = stod(z);
  array[int_x][int_y] = double_z;
  }
  //displays values inputed in the array
  for(int i = 0; i < 7; i++){
    cout<<"ROW "<< i<<endl;
    for(int j = 0; j < 7; j++){
      
      cout<<"   "<<array[i][j]<<"   ";
    }
    cout<<endl<<"----------------------------------------------------------"<<endl;
  }

double counter = 0.00;
int start, finish;
int temp = 1;
vector<double>tempArray;
int size;
int tempMin;

///*create the temp arrray to find next node
for(int i = 0; i < 1; i++){
    for(int j = 0; j < 7; j++){
      if(array[i][j] != -1)
        tempArray.push_back(array[i][j]);
      }
    }
    tempMin = findMin(tempArray);
    cout<<"Here is the min: "<<findMin(tempArray);
    tempArray = eraseMin(tempArray, tempMin);
    size = tempArray.size();
    cout<<endl<<"this is the size of the temp array: "<<size<<endl;
//*/
  file.close();
return 0;
}
double findMin(vector<double>numbers){
  int size;
  double tempMin;
  double min;
  size = numbers.size();
  for(int i = 0; i < size-1; i++){
    tempMin = numbers[i];
    if(tempMin > numbers[i+1])
      tempMin = numbers[i+1]; 
  }
  /* debugging
    cout<<numbers.size()<<endl;
    cout<<numbers[0]<<endl;
    cout<<numbers[1]<<endl;
    cout<<numbers[2]<<endl;
    */
  min = tempMin;
  return min;
}
vector<double>eraseMin(vector<double>numbers,double minNumber){
  vector<double>tempVector = numbers;
  int size;
  double n = minNumber;
  size = tempVector.size();
  for(int i = 0; i < size-1; i++){
    if(tempVector[i]== n){      
      tempVector.erase(numbers.begin()+i) ;
    }
}
tempVector.resize(size-1);
return tempVector;
}