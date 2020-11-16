#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
double findMin(vector<double>numbers,bool sptSet[]);
vector<double>eraseMin(vector<double>numbers,double minNumber);
void printPath(vector<int>parent, int j);
void printSolution(vector<double>tempTotal, int n,vector<int>parent);
void djikstra(double arrayHolder[21][21],int start);

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
  /*for(int i = 0; i < 21; i++){
    for(int j = 0; j < 21; j++){
    array[i][j]=-1;
    }}*/
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
  /*for(int i = 0; i < 7; i++){
    cout<<"NODE #"<< i<<endl;
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

create the temp arrray to find next node
for(int i = 0; i < 1; i++){
    for(int j = 0; j < 7; j++){
      if(array[i][j] != -1)
        tempArray.push_back(array[i][j]);
      }
    }
    tempMin = findMin(tempArray);
    //cout<<"Here is the min: "<<findMin(tempArray);
    tempArray = eraseMin(tempArray, tempMin);
    size = tempArray.size();
    //cout<<endl<<"this is the size of the temp array: "<<size<<endl;
//*/
djikstra(array,0);
  file.close();
return 0;
}
double findMin(vector<double>numbers,bool sptSet[]){
  int size;
  double tempMin;
  double min,min_index;
  size = numbers.size();
      for (int v = 0; v < 21; v++) 
        if (sptSet[v] == false && 
                   numbers[v] <= min) 
            min = numbers[v], min_index = v; 
  
    return min_index; 
  /*for(int i = 0; i < size-1; i++){
    tempMin = numbers[i];
    if(tempMin > numbers[i+1])
      tempMin = numbers[i+1]; 
  }
  min = tempMin;
  return min;*/
}
/*
int minDistance(int dist[],  
                bool sptSet[]) 
{ 
      
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && 
                   dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} */
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
void djikstra(double arrayHolder[21][21],int start){
vector<double>costTotal;
bool countedAlready[21];
vector<int>shortestPath;

for (int i = 0; i < 21; i++) 
    { 
        shortestPath[0] = -1; 
        costTotal[i] = -1; 
        countedAlready[i] = false; 
    }

    shortestPath[start] = 0;

    for (int count = 0; count < 21 - 1; count++) 
    { 

        int u = findMin(costTotal,countedAlready); 
  
        // Mark the picked vertex  
        // as processed 
        countedAlready[u] = true; 
  
        // Update dist value of the  
        // adjacent vertices of the 
        // picked vertex. 
        for (int v = 0; v < 21; v++) 

            if (!countedAlready[v] && arrayHolder[u][v] && 
                costTotal[u] + arrayHolder[u][v] < costTotal[v]) 
            { 
                shortestPath[v] = u; 
                costTotal[v] = costTotal[u] + arrayHolder[u][v]; 
            }  
    }     
    printSolution(costTotal, 21,shortestPath); 
}
void printSolution(vector<double>tempTotal, int n,vector<int>parent) 
{ 
    int src = 0; 
    cout<< ("Vertex\t Distance\tPath"); 
    for (int i = 1; i < 21; i++) 
    { 

        cout<<"\n"<<src<<"->"<<i<<tempTotal[i]<<src;
        printPath(parent, i); 
    } 
} 
void printPath(vector<int>parent, int j) 
{ 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 