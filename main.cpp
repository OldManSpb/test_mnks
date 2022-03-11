/**
(C) 2022 Andrei Saenko 
*/

#include <iostream>
#include <vector> 
using namespace std;

class ArrayHandler
{
public:
  
  ArrayHandler(vector<vector <int>> a) : source_arr(a) {}
  
  void process(int nb)
  {
      vector<vector<int>> last_value{{0,0}};
      cout << last_value[0][0] << " \n";
      for (int i=0 ; i < source_arr.size(); i++){
        cout << source_arr[i][1] << " " << last_value[0][1] << endl;
        
        result_arr.push_back(source_arr[i]);
        
        last_value[0] = source_arr[i];
    }     
  }
  
private:
  vector<vector<int>> source_arr;
  vector<vector<int>> result_arr;
    
};



int main()
{
    ArrayHandler* arrH = new ArrayHandler({{1,2},{3,4},{5,6}});
    arrH->process(3);
    
    return 0;
}
