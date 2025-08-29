// DV Array Notes

#include <iostream>
using namespace std;

int nums[6] = {8, 6, 2, 9, 1, 11};

int main(){

    for (int i = 0; i < size(nums) - 1; i++){
        for (int j = 0; j < size(nums) - 1; j++){

            if (nums[j] > nums[j+1]){
               int swap = nums[j];
               nums[j] = nums[j+1];
               nums[j+1] = swap;
            }

            cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << " " << nums[4] << " "<< nums[5] << endl; 
        }
    }
    
    
    return 0;
}