#include <iostream>
using namespace std;

class SolveSetZeros{
    public:
    vector<vector<int>> setZeros(int &rows, int &cols, vector<vector<int>> &matrix){
        bool firstColZeros = false;
        bool firstRowZeros = false;

        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                firstColZeros = true;
            }
        }
        for(int i = 0; i < cols; i++){
            if(matrix[0][i] == 0){
                firstRowZeros = true;
            }
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                } 
            }
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }   
        
        if(firstColZeros){
            for(int n = 0; n < rows; n++){
                matrix[n][0] = 0;
            }
        }
        if(firstRowZeros){
            for(int n = 0; n < cols; n++){
                matrix[0][n] = 0;
            }
        }
        return matrix;
    }
};

void print_banner(){
    cout << endl;
    cout << "########################################" << endl
         << "############              ##############" << endl
         << "#########   Set Zero Program   #########" << endl
         << "############              ##############" << endl
         << "########################################"<< endl << endl;
}
int get_inputs(int &rows, int &cols, vector<vector<int>> &matrix){
    cout << "Number of rows ";
    cin >> rows;
    cout << endl << "Number of cols ";
    cin >> cols;
    matrix.resize(rows, vector<int>(cols));
    cout << "Enter the matrix input : " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> matrix[i][j];
        }
    }
    return 0;
}
int main(){
    int rows, cols;
    vector<vector<int>> matrix;
    SolveSetZeros solve;
 
    print_banner();
    get_inputs(rows, cols, matrix);
    matrix = solve.setZeros(rows, cols, matrix);

    cout << "Output Matrix " << endl; 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] <<  " ";
        }
        cout << endl;
    }
    return 0;
}