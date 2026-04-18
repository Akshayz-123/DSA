#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Utils{
    public:
        static void print_banner(){
            cout << endl;
            cout << "########################################" << endl
                << "############              ##############" << endl
                << "########   Kadane's Algorithm   ########" << endl
                << "############              ##############" << endl
                << "########################################"<< endl << endl;
        }
        static void get_input(vector<int> &input){
            cout << "Input array: (Press Enter to complete): ";
            string line;
            getline(cin, line);

            stringstream ss(line);
            int n;
            while(ss >> n){
                input.push_back(n);
            }
        }
        static void print_output(vector<int> input, int iStart, int iEnd, int maxSum){
            cout << endl << "Output array with maxSum = " << maxSum << " : [";

            for(int i = iStart; i <= iEnd; i ++){
                cout << input[i] << (i < iEnd ? " ," : "]");
            }
            cout << endl;
        }
};

class Solution{
    public:
        int kadaneAlgorithm(vector<int> input, int &mStart, int &mEnd){
            long long sum = 0;
            long long maxSum = LLONG_MIN;
            int start = 0;
            mStart = 0;
            mEnd = 0;
            int numElements = input.size();
            for(int i = 0; i < numElements; i ++){
                if(sum == 0){
                    start = i;
                }
                sum += input[i];
                if(sum > maxSum){
                    maxSum = sum;
                    mStart = start;
                    mEnd = i;
                }
                if(sum < 0){
                    sum = 0;
                }
            }
            return maxSum;
        }
};

int main(){

    vector<int> input;
    vector<int> output;
    Solution solve;
    int mStart;
    int mEnd;
    int maxSum;

    Utils::print_banner();
    Utils::get_input(input);
    maxSum = solve.kadaneAlgorithm(input, mStart, mEnd);
    Utils::print_output(input, mStart, mEnd, maxSum);

    return 0;
}