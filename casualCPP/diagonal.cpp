#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of rows and columns: ";
    cin >> n;
    // Create a 2D matrix initialized with spaces
    vector<vector<char> > tricky(n, vector<char>(n, ' '));

    // Place '*' only on the diagonal
    for(int i = 0; i < n; i++) {
        for(int j = 0;j<n;j++){
            if(i == j){
                 tricky[i][j] = '*'; 
            }
        }
        // Only on diagonal positions
    }

    // Print the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << tricky[i][j];  // Print the matrix elements
        }
        cout << endl;  // New line after each row
    }

    return 0;
}
