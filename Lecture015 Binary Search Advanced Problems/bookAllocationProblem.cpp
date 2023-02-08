#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    
    // as we are going through the array we are trying to allocate the pages to students.
    // Condition : total number of allocated pages should be less then mid value as we need to allocate to others also
    
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    //Search space is defined from 0 to the total sum of the pages
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;    // as we need to allocate the minimum number of pages we go the left side
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
