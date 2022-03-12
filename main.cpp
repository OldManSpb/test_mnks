/**
(C) 2022 Andrei Saenko 
*/


#include <iostream>
#include <vector> 
#include <string>
#include <cassert>
using namespace std;

class ArrayHandler
{
public:
  
  ArrayHandler(vector<vector <int>> a) : source_arr(a) {}
  ~ArrayHandler();
  
  //Make deductions as required in the test
  void process(int nb)
  {
      assert(nb > 2);
      int repeats_counter = 1;
      //add additional member
      source_arr.push_back({{0,0}});
      //Clear array
      result_arr.clear();
      for (int i=0 ; i < source_arr.size()-1; i++)
      {
        //Push to result array if next member is different and reset counter
        if (source_arr[i][1] != source_arr[i+1][1]){
           result_arr.push_back(source_arr[i]);
           repeats_counter = 1;
        }
        //Push if counter is equal first or nb 
        else{
            if(repeats_counter == 1 || repeats_counter == nb)
            {
                result_arr.push_back(source_arr[i]);
            }
            //Increment counter to nb and reset it
            if(++repeats_counter > nb)
            { 
                repeats_counter = 1;
            }
        }
        
      }
      //Remove additional member
      source_arr.pop_back();
  }
  
  //Get result array in a string format
  string get_result_array_printable()
  {
    return get_array_printable(result_arr);    
  }
  
  //Get original array in a string format
  string get_source_array_printable()
  {
    return get_array_printable(source_arr);
  }
  
  
private:

  //Get array in string format as in test requirements    
  string get_array_printable(vector<vector<int>> arr)
  {
    string result = "";  
    for (int i = 0; i < arr.size(); i++)
    {
        result += "(" + to_string(arr[i][0]) + "," + to_string(arr[i][1]) + "),";
    }
    result.pop_back();
    return result;
  }
  
  //Private members  
  vector<vector<int>> source_arr{{0,0}};
  vector<vector<int>> result_arr{{0,0}};
    
};



int main()
{
    ArrayHandler* arrH = new ArrayHandler({{1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10}});
    arrH->process(3);
    cout << "Original array: " << arrH->get_source_array_printable() << endl;
    cout << "Result array (3): " << arrH->get_result_array_printable() << endl;
    arrH->process(4);
    cout << "Result array (4): " << arrH->get_result_array_printable() << endl;
    
    return 0;
}
