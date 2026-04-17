#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class utils{
public:
    static void print_banner(){
        cout << endl;
        cout << "########################################" << endl
             << "############              ##############" << endl
             << "#########   Next Permutation   #########" << endl
             << "############              ##############" << endl
             << "########################################"<< endl << endl;
    }

    static void get_input(vector<int> &currentPermutation){
        cout << "Current input array (Press Enter to stop) :";
        string line;
        getline(cin, line);

        stringstream ss(line);
        int in;
        while(ss >> in){
            currentPermutation.push_back(in);
        }
        cout << endl;
    }

    static void print_output(const vector<int> &output){
        int numElements = output.size();
        if(numElements > 0){
            cout << "Output - Next Permutation: [";
            for(int i = 0; i < numElements; i++){
                cout << output[i] << (i != numElements - 1 ? ", " : "]");
            }
            cout << endl;
        }
        else{
            cout << "No elements were entered" << endl;
        }
    }
};

class Solution{
public:
    static void solveNextPerm(vector<int> &currentPermutation){
        int numElements = currentPermutation.size();
        if(numElements <= 1) return;

        int index = -1;

        for(int i = numElements - 2; i >= 0; i--){
            if(currentPermutation[i] < currentPermutation[i + 1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(currentPermutation.begin(), currentPermutation.end());
        }
        else{
            for(int i = numElements - 1; i > index; i--){
                if(currentPermutation[i] > currentPermutation[index]){
                    swap(currentPermutation[index], currentPermutation[i]);
                    break;
                }
            }
            reverse(currentPermutation.begin() + index + 1, currentPermutation.end());
        }
    }
};

int main(){
    vector<int> currentPermutation;
    utils::print_banner();
    utils::get_input(currentPermutation);
    if(currentPermutation.empty()){
        utils::print_output(currentPermutation);
        return 0;
    }
    Solution::solveNextPerm(currentPermutation);
    utils::print_output(currentPermutation);
}