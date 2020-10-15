#include <iostream>
#include<fstream>
#include<string>
using namespace std;


class tetris
{
private :
    int row ,col;
    int **arr;

    string type;
    int type_r , type_c;
    int *type_arr;

    int start , move;

public:
    tetris(int r = 0 , int c = 0)
    {
        row = r;
        col = c;
        arr = new int*[r];
        for(int i = 0 ; i < r ; i++)
        {
            arr[i] = new int[c];
        }
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                arr[i][j] = 0;
            }
        }  
    }
    ~tetris()
    {
        for(int i = 0 ; i < row ; i++)
        {
            delete [] arr[i];
        }
        delete [] arr;
    }
    void get_type_data(string);
    void situ(int s , int m) {start = s ; move = m;}
    void run(void);
    void get_arr(ofstream&);
    

};

int main()
{
    ifstream infile("3.data",ios::in);
    ofstream outfile("3.final" ,ios::out);
    if(infile.fail()) cout << "input failed" << endl;
    else if(outfile.fail()) cout << "output failed" << endl;
    else cout << "success" <<endl;

    int row,col,start,move;
    string type;
    

    infile >> row;
    infile >> col;
    tetris play1(row,col);
    while(true)
    {
        infile >> type;
        if(type == "End") break;
        play1.get_type_data(type);
        infile >> start ;
        infile >> move;
        play1.situ(start,move);
        play1.run(); 
    }
        play1.get_arr(outfile);



    
    
     return 0;

}
void tetris::get_arr(ofstream &output)
{
    for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                output << arr[i][j] << " ";
            }
            output << endl;
        }
}
void tetris::run(void)
{
    int test = 0;
    int temp_r = row - 1;
    int loca = start + move - 1 ;
    int type_num = 0;
        do
        {
            if(test == 2) test = 0;
            for(int i = 0 ; i < type_r && test < 2; i++)
            {
                for(int j = 0 ; j < type_c && test < 2; j++)
                {
                    test = arr[temp_r][loca] + type_arr[type_num];
                    if(test != 2)
                    {
                        arr[temp_r][loca] = arr[temp_r][loca] + type_arr[type_num];
                        type_num++;
                        loca++;
                    }
                }
                if(test == 2) type_num = 0;  
                loca = start + move - 1;
                temp_r--;
                
            }
        }
        while(test == 2);
        delete [] type_arr;
        bool count_r;
        int count ;  
        for(int i = row - 1 ; i >= 0 ; i-- )
        {
            count = 0;
            for(int j = 0 ; j < col ; j++)
            {
                if(arr[row - 1][j] == 1) count++;
            }
            if(count == col) count_r = true; 
            else count_r = false;
            if (count_r == true) 
            {
                for (int j = 0 ; j < col ; j++)
                {
                    arr[row - 1][j] = 0;
                }
                for(int m = row - 1 ; m > 0 ; m--)
                {
                  for(int jj = 0 ; jj < col ; jj++)
                  {
                      arr[m][jj] = arr[m - 1][jj];
                  }
                }            
                for(int k = 0 ; k < col ; k++)
                {
                    arr[0][k] = 0;
                }
            }
        }
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
    
}
void tetris::get_type_data(string type)
{
  if (type == "T1") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {0,1,0,1,1,1};
     for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  if (type == "T2") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {0,1,1,1,0,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "T3") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {1,1,1,0,1,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
    
  }
  else if (type == "T4") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {1,0,1,1,1,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "L1") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {1,1,1,0,1,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "L2") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {1,0,0,1,1,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "L3") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {0,1,0,1,1,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "L4") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {1,1,1,0,0,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "J1") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {1,1,0,1,0,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "J2") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {1,1,1,1,0,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "J3") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {1,0,1,0,1,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "J4") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {0,0,1,1,1,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "S1") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {1,1,0,0,1,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "S2") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {0,1,1,1,1,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "Z1") 
  {
    type_r = 2;
    type_c = 3;
    type_arr = new int[6];
    int a[6] = {0,1,1,1,1,0};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "Z2") 
  {
    type_r = 3;
    type_c = 2;
    type_arr = new int[6];
    int a[6] = {1,0,1,1,0,1};
    for(int i = 0 ; i < 6 ; i++) type_arr[i] = a[i];
  }
  else if (type == "I1") 
  {
    type_r = 4;
    type_c = 1;
    type_arr = new int[4];
    int a[4] = {1,1,1,1};
    for(int i = 0 ; i < 4 ; i++) type_arr[i] = a[i];
  }
  else if (type == "I2") 
  {
    type_r = 1;
    type_c = 4;
    type_arr = new int[4];
    int a[4] = {1,1,1,1};
    for(int i = 0 ; i < 4 ; i++) type_arr[i] = a[i];
  }
  else if (type == "O") 
  {
    type_r = 2;
    type_c = 2;
    type_arr = new int[4];
    int a[4] = {1,1,1,1};
    for(int i = 0 ; i < 4 ; i++) type_arr[i] = a[i];
  }
    
    
    
            
}


