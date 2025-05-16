#include <bits/stdc++.h> 
using namespace std; 

void countingRooms(int y, int x){
    int output = 0;
    vector<vector<pair<bool, bool>>> grid(y, vector<pair<bool, bool>>(x));
    
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            char current;
            cin >> current;
            if(current == '.'){
                grid[i][j] = make_pair(true, false);
            }
            else{
                grid[i][j] = make_pair(false, false);
            }
        }
    }

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == make_pair(true, false)){
                grid[i][j].second = true;
                output++;
                queue<pair<int,int>> neighbours;
                neighbours.push({i, j});
                while(!neighbours.empty()){
                    pair<int, int> current = neighbours.front();
                    neighbours.pop(); 
                    if(current.first > 0){
                        if(grid[current.first - 1][current.second] == make_pair(true, false)){
                            neighbours.push({current.first - 1, current.second});
                            grid[current.first - 1][current.second].second = true;
                        }
                    }
                    if(current.first < grid.size() - 1){
                        if(grid[current.first + 1][current.second] == make_pair(true, false)){
                            neighbours.push({current.first + 1, current.second});
                            grid[current.first + 1][current.second].second = true;
                        }
                    }
                    if(current.second > 0){
                        if(grid[current.first][current.second - 1] == make_pair(true, false)){
                            neighbours.push({current.first, current.second - 1});
                            grid[current.first][current.second - 1].second = true;
                        }
                    }
                    if(current.second < grid[0].size() - 1){
                        if(grid[current.first][current.second + 1] == make_pair(true, false)){
                            neighbours.push({current.first, current.second + 1});
                            grid[current.first][current.second + 1].second = true;
                        }
                    }
                }
            }
        }
    }

    /*
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j]){
                cout << 'x';
            }
            else{
                cout << 'o';
            }
        }
        cout << "\n";
    }
    */

    cout << output << endl;
    // complete
}

int main(){
    int c,q; 
    cin >> c >> q; 
    countingRooms(c, q);
    return 0;
}

