//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Start code
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } else {
                result += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < n1) sum1 += arr1[i++];
        while (j < n2) sum2 += arr2[j++];

        result += max(sum1, sum2);

        return result;
    }
}; //End code

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends