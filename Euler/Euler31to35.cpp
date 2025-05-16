#include <bits/stdc++.h>
using namespace std;

/*
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Initial idea:
Can make it with 1 Two Pound Coin
Then since thats the max, change it to a one pound coin, that's too small then add a two pound coin, thats too large
Change that two pound coin to a one pound coin, thats max
Change that to a 50p coin, too small, then another 50 p coin
change that last 50 coin e.t.c until whatever, then change the second last 50p coin e.t.c then change that last one pound coin
*/

int coinValue(vector<int> coins){
    int output = 0;
    output += coins[0] * 1;
    output += coins[1] * 2; 
    output += coins[2] * 5;
    output += coins[3] * 10;
    output += coins[4] * 20;
    output += coins[5] * 50;
    output += coins[6] * 100;
    output += coins[7] * 200;
    return output;
}

void problem31(){
    set<vector<int>> count;
    vector<int> p = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<int> coins(8, 0);

    int index = 7;
    while(index != 7){
        
    }

    cout << count.size() << endl;
}

int main(){
    problem31();
    return 0;
}