#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
class Utils{
    public:
        static void print_banner(){
            cout << endl;
            cout << "########################################" << endl
                << "############              ##############" << endl
                << "#########    Pascal Triangle   #########" << endl
                << "############              ##############" << endl
                << "########################################"<< endl << endl;
        }
        static void get_inputs(int &numRows){
            cout << "Enter the number of rows you want : ";
            cin >> numRows;
            cout << endl;
        }
        static void print_output(vector<vector<int>> triangle, int numRows){
            for(int i = 0; i < numRows; i++){
                for(int k = 0; k < numRows - i - 1; k++){
                    cout << " ";
                }
                for(int j = 0; j < i+1; j++){
                    cout << setw(2) << triangle[i][j] << " ";
                }
                cout << endl;
            }
        }
};    

class Solve{
    public:
        vector<vector<int>> generate_pascal_1(int numRows){
            vector<vector<int>> triangle(numRows, vector<int>(numRows));
            for(int i = 0; i < numRows; i ++){
                triangle[i].resize(i+1);
                triangle[i][0] = triangle[i][i] = 1;
                // cout << triangle[i].size() << endl;
                for(int j = 1; j <= i-1; j++){
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
            }
            return triangle;
        }
        vector<vector<int>> generate_pascal_2(int numRows){
            vector<vector<int>> triangle;
            for(int i = 0; i < numRows; i++){
                vector<int> row(i+1, 1);
                for(int j = 1; j <= i-1; j++){
                    row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
                triangle.push_back(row);
            }
            return triangle;
        }
};

int main(){
    int numRows;
    Utils::print_banner();
    Utils::get_inputs(numRows);
    Solve solve;
    vector<vector<int>> triangle1 = solve.generate_pascal_1(numRows);
    Utils::print_output(triangle1, numRows);
    vector<vector<int>> triangle2 = solve.generate_pascal_2(numRows);
    Utils::print_output(triangle2, numRows);
    return 0;
}