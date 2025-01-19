#include <iostream>
#include <vector>
using namespace std;


vector<int> merge(vector<int> left, vector<int> right){
    
    vector<int> mergedArr;
    int leftIndex=0;
    int rightIndex=0;
    
    while(leftIndex < left.size() && rightIndex < right.size())
    {
        if(left[leftIndex] < right[rightIndex]){
            mergedArr.push_back(left[leftIndex]);
            leftIndex++;
        }
        else{
            mergedArr.push_back(right[rightIndex]);
            rightIndex++;
        }
    }
    
    while(leftIndex < left.size()){
        mergedArr.push_back(left[leftIndex]);
        leftIndex++;
    }
    while(rightIndex < right.size()){
        mergedArr.push_back(right[rightIndex]);
        rightIndex++;
    }
    
    return mergedArr;
}

vector<int> mergesort(vector<int> arr){
    
    int size = arr.size();
    if(size == 1)
        return arr;
    
    vector<int> left(arr.begin(), arr.begin() + size/2);
    vector<int> right(arr.begin() + size/2 , arr.end() );
    
    cout <<endl<< "Left : ";
    for(auto val : left)
        cout << val << " " ;
        
    cout <<endl<< "Right : ";
    for(auto val : right)
        cout << val << " " ;
        
    return merge(mergesort(left), mergesort(right) );
    
}


int main()
{
    vector<int> arr = {1,67,234,7,3,787,234,12,3467,45,1,34,89};
   
    
    vector<int> sorted(mergesort(arr));
    
  
    cout << "sorted array : " ;
    
    for(auto val : sorted)
        cout << val << " " ;
        
    cout << endl;

    return 0;
}