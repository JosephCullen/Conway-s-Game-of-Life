#include <iostream>
#include <cstdlib>
using namespace std;
//The height and width are 52 because there is a 
//ring of zeros around the whole array
#define WIDTH 52
#define HEIGHT 52

//start array
int array [HEIGHT][WIDTH];
//the array that holds the next year until it
//is copied back to array to print
int newArray [HEIGHT][WIDTH];
//Just prints the array
void arrayPrint();
//This sets up the ring of zeros around the array
void zeroSetup();
//This runs 10 times to simulate 10 years
void lifetime();
//Copies newArray into array
void copyArray();

int main ()
{
  //These two for loops go through the whole array
  //and gives each element a random value from
  //1-10 then checks to see if is less than or 
  //greater than 5 and assigns 1 or 0 to the 
  //element accordingly
  for(int i = 0; i <= HEIGHT; i++){
    for(int j = 0; j <= WIDTH; j++){
      int r = rand() % 10 + 1;
      // cout << r;
      if(r <= 5){
        array[i][j] = 1;
      }
      else if(r >= 6)
        array[i][j] = 0;
    }
  }
  zeroSetup();
}

void arrayPrint(){
  for(int i = 0; i <= HEIGHT; i++){
    for(int j = 0; j <= WIDTH; j++){
      if(array[i][j] == 1){
        cout << array[i][j];
      }
      else
        cout << array[i][j];
    }
    cout << "\n";
  }
}

void zeroSetup(){
  //goes through the edge of the arry making 
  //elements zero
  for(int i = 0; i <= HEIGHT; i++){
    array[i][0] = 0;
    array[0][i] = 0;
    array[HEIGHT][i] = 0;
    array[i][WIDTH] = 0;
  }

  //prints the initial array then stats the
  //life cycle 
  arrayPrint();
  lifetime();
}

void lifetime(){
  for(int k = 0; k < 10; k++){
    for(int i = 1; i <= HEIGHT-1; i++){
      for(int j = 1; j <= WIDTH-1; j++){
        int total = array[i-1][j-1] + array[i-1][j]
          +array[i-1][j+1] + array[i][j+1] 
          + array[i+1][j+1]
        +array[i+1][j] + array[i+1][j-1] + array[i][j-1];

        if(total <= 1 || total >= 4){
          newArray[i][j] = 0;
        }

        if(array[i][j] == 1 && (total == 2 || total == 3)){
          newArray[i][j] = 1;
        }else if(array[i][j] == 0 && total == 3){
          newArray[i][j] = 1;
        }
      }
    }
    copyArray();
    arrayPrint();
  }
}

void copyArray(){
  for(int i = 0; i <= HEIGHT; i++){
    for(int j = 0; j <= WIDTH; j++){
      array[i][j] = newArray[i][j];
    }
  }
}
