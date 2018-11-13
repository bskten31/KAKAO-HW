/* KAKAO HW */
/* EE 20140672 Kim Bo Seong */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
  int i, j;
  string line;
  int n_line; // n_line x n_line grid
  char* buf; // line buffer (char)
  int** mapp; // each grid possbile or not (1, 0)
  int** path; // possible number of path for each grid
  
  ifstream inf(argv[1]));
  getline(inf, line);
  n_line = line.length();
  
  buf = new char[n_line + 1];
  mapp = new int*[n_line];
  path = new int*[n_line];
  
  for (j = 0; j < n_line; j++){
    mapp[j] = new int[n_line];
    path[j] = new int[n_line];
  }
  
  // make mapp matrix
  strcpy(buf, line.c_stre());
  for (j = 0; j < n_line; j++){
    if (buf[j] == '0')
      mapp[0][j] == 1;
    else if (buf[j] == '1')
      mapp[0][j] == 0;
  }
  
  for (i = 1; i < n_line; i++){
    getline(inf, line);
    strcpy(buf, line.c_str());
    for (j = 0; j < n_line; j++){
      if (buf[j] == '0')
        mapp[i][j] = 1;
      else if (buf[j] == '1')
        mapp[i][j] = 0;
    }
  }
    
  /* make path matrix */
  for (j = 0; j < n_line; j++){// (1,j) row
    if (mapp[0][j] == 0){
      for (; j < n_line; j++)
        path[0][j] == 0;
    }
    else
      path[0][j] = 1;
  }  
    
  for (i = 0; i < n_line; i++){// (i,1) column  
    if (mapp[i][0] == 0){
      for (; i < n_line; i++)
        path[i][0] == 0;
    }
    else
      path[i][0] = 1;
  }
  
  for (i = 1; i < n_line; i++){
    for (j = 1; j < n_line; j++){
      if (mapp[i][j] == 0)
        path[i][j] = 0;
      else
        path[i][j] = path[i-1][j] + path[i][j-1];
      }
  }    
    
  inf.close();  
  
  //result
  cout << "The number of shortest path is " << path[n_line-1][n_line-1] << endl;  
    
  //delete  
  delete buf;
  for (j = 0; j < n_line; j++){
    delete[] mapp[j];
    delete[] path[j];
  }  
  delete[] mapp;
  delete[] path;
  
  return 0;
}    
