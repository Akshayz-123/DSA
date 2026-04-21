#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
class Solution{
    public:
        static void solve(vector<int> &input_array){
            int low = 0, mid = 0, high = input_array.size() - 1;
            while(mid <= high){
                if(input_array[mid] == 0){
                    swap(input_array[mid], input_array[low]);
                    low++;
                    mid++;
                }
                else if(input_array[mid] == 1){
                    mid++;
                }
                else{
                    swap(input_array[mid],input_array[high]);
                    high --;
                }
            }
        }
};
class Utils{
    public:
    static void print_banner() {
        cout << endl;
            cout << "########################################" << endl
                << "############              ##############" << endl
                << "#######   Dutch Flag Algorithm   #######" << endl
                << "############              ##############" << endl
                << "########################################"<< endl << endl;
    }
    static void get_input(vector<int> &input_array){
        cout << "Enter the input array elements: ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        while(ss >> x){
            input_array.push_back(x);
        }

    }
    static void print_output(vector<int> output){
        int numElements = output.size();
        cout << "Output : [";
        for(int i = 0; i < numElements; i++){
            cout << output[i] << (i != (numElements - 1) ? ", " : "]");
        }
        cout << endl << endl;
    }
};

int main (){
    vector<int> input_array;
    Utils::print_banner();
    Utils::get_input(input_array);
    Solution::solve(input_array);
    Utils::print_output(input_array);
    return 0;
}