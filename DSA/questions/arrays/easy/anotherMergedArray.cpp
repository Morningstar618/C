#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    int index = nums1.size() - nums2.size();
    int i = 0;

    while (i < nums2.size()) {
        swap(nums1[index], nums2[i]);
        index++; i++;
        
    }

    i = 0;
    while (i < nums1.size()) {
        if (nums1[i] > nums1[i+1] && i+1 < nums1.size()) {
            cout<<nums1[i+1]<<endl;
            swap(nums1[i], nums1[i+1]);
        }
        i++;
    }    

    return nums1;
}

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0,0};
    vector<int> nums2 = {2,2,5,6};

    nums1 = merge(nums1, nums2);
    printArray(nums1);

    return 0;
}