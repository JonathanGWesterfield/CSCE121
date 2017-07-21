#include<iostream>
#include <vector>
using namespace std;

int add(vector<int> nums)
{
  if(nums.size() ==  0)
  {
    return 0;
  }
  int val = nums.at(0);
  nums.erase(nums.begin());
  return val + add(nums);
}
int main()
{
  vector<int> vals {2,7,4};
  for(int i = 0; i< vals.size(); i++)
  {
    cout << vals.at(i);
    if( i == vals.size() - 1)
    {
      cout << " = ";
    }
    else
    {
      cout << " + ";
    }
  }
  cout << sum;
}
