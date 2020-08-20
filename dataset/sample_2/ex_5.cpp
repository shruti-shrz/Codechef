#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int rectCount(const vector<vector<int> >& matrix) 
{ 
    int rows = matrix.size(); 
    if (rows == 0) 
        return 0; 
  
    int columns = matrix[0].size(); 
  
    map<pair<int, int>, int> onePair; 
    int count = 0;
  
    for (int i = 0; i < rows; ++i) { 
        for (int j = 0; j < columns - 1; ++j) { 
            if (matrix[i][j] == 1) {

                for (int k = j + 1; k < columns; ++k) { 
                    if (matrix[i][k] == 1) { 
                        pair<int, int> pr {j, k};
                        count += onePair.count(pr) > 0 ? onePair[pr] : 0;

                        onePair[pr] += 1; 
                    } 
                } 
            }
        } 
    } 

    return count; 
} 

int main()
{
    int T;
    cin >> T;

    while(T--) {
        int W, N, x, y;
        cin >> W >> N;
        vector<vector<int>> matrix(W, vector<int>(W));
        while(N--) {
            cin >> x >> y;
            matrix[x][y] = 1;
        }
        cout << rectCount(matrix) << endl;
    }

    return 0;
}

