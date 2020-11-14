#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    array[i][j]=0;
    }}
  /*for(int i =0;i<7;i++){
    for(int j =0;j<7;j++){
      array[i][j]=0;
    }
  }*/

  while(!file.eof()){
  file>>x;
  int_x = stoi(x);
  file>>y;
  int_y = stoi(y);
  file>>z;
  double_z = stod(z);
  /*cout<<int_x<<endl;
  cout<<int_y<<endl;
  cout<<double_z<<endl;
*/
  array[int_x][int_y] = double_z;
  //cout<<array[int_x][int_y]<<endl;
  /*cout<<x;
  cout<<y;
  cout<<z<<endl;*/
  }
  for(int i = 0; i < 7; i++){
    cout<<"ROW "<< i<<endl;
    for(int j = 0; j < 7; j++){
      
      cout<<"   "<<array[i][j]<<"   ";
    }
    cout<<endl<<"----------------------------------------------------------"<<endl;
  }
  
return 0;
}