#include <bits/stdc++.h>
using namespace std;

vector<long long> twotoonethousanddigits(){
    vector<long long> output;
    output.push_back(1);
    for(long long i = 0; i < 1000; i++){
        long long carry = 0;
        for(size_t j = 0; j < output.size(); j++){
            output[j] *= 2;
            output[j] += carry;
            carry = output[j]/10;
            output[j] %= 10;
            if(j + 1 == output.size()){
                output.push_back(carry);
                break;
            }
        }
    }

    return output;
}

void problem16(){
    long long output = 0;
    vector<long long> digits = twotoonethousanddigits();
    for(size_t i = 0; i < digits.size(); i++){
        output += digits[i];
    }
    cout << output << endl;
}

void problem17() {
    long long output = 0;

    // Length of words for 1-19
    unordered_map<int, int> length = {
        {1, 3}, {2, 3}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 5}, {8, 5}, {9, 4},
        {10, 3}, {11, 6}, {12, 6}, {13, 8}, {14, 8}, {15, 7}, {16, 7}, {17, 9},
        {18, 8}, {19, 8}
    };

    // Length of words for tens (20, 30, ..., 90)
    unordered_map<int, int> tens = {
        {20, 6}, {30, 6}, {40, 5}, {50, 5}, {60, 5}, {70, 7}, {80, 6}, {90, 6}
    };

    for (int j = 1; j <= 1000; j++) {
        int i = j;

        // Handle "one thousand" case explicitly before the rest of the loop
        if (i == 1000) {
            output += 11;  // "one thousand" has 11 letters
            i = 0;  
        }

        // Handle hundreds (100-999)
        if (i >= 100) {
            output += length[i / 100];  // Add the word for the hundreds place (1-9)
            output += 7;  // Add "hundred"
            i %= 100;  // Reduce i to the remainder (i.e., the part less than 100)

            if (i > 0) {
                output += 3;  // Add "and" if there's something left (since it's not a clean hundred)
            }
        }

        // Handle tens (20, 30, ..., 90)
        if (i >= 20) {
            output += tens[(i / 10) * 10];  // Get the length for the tens place
            i %= 10;  // Reduce i to the ones part
        }

        // Handle ones (1-19)
        if (i > 0) {
            output += length[i];
        }
    }

    cout << output << endl;
}
// Eighteen has 8 LETTERS not 9 - note the use of case checking + dictionary = no while loop

void problem18(){
    vector<vector<long long>> grid;
    for(int i = 0; i < 15; i++){
        string line;
        vector<long long> numbers;
        getline(cin, line);
        stringstream ss(line);
        long long number;
        while(ss >> number){
            numbers.push_back(number);
        }
        grid.push_back(numbers);
    }
    
    for(int i = grid.size() - 2; i >= 0; i--){
        for(int j = 0; j < grid[i].size(); j++){
            int max = 0;
            long long left = grid[i + 1][j];
            long long right = grid[i + 1][j + 1];
            if(left > right){
                max = left;
            }
            else{
                max = right;
            }
            grid[i][j] += max;
        }
    }

    cout << grid[0][0] << endl;
}

long long dfs(int row, int column, vector<vector<long long>> grid){
    if(row == grid.size() - 1){
        return grid[row][column];
    }
    
    long long leftPath = dfs(row + 1, column, grid);
    long long rightPath = dfs(row + 1, column + 1, grid);

    return grid[row][column] + max(leftPath, rightPath);
}

void problem18Bad(){
    vector<vector<long long>> grid;
    for(int i = 0; i < 15; i++){
        string line;
        vector<long long> numbers;
        getline(cin, line);
        stringstream ss(line);
        long long number;
        while(ss >> number){
            numbers.push_back(number);
        }
        grid.push_back(numbers);
    }
    
    cout << dfs(0,0, grid) << endl;
}

/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

365 days in a normal year
366 in days in a leap year which occurs on any year which mod 4 == 0 except those centuries which are not congruent to 0 mod 400
Leap year means 29 days in Feb
31 days in Jan
28 days in Feb - 29 on leap year
31 days in March
30 days in April
31 days in May
30 days in June
31 days in July
31 days in August
30 days in September
31 days in October
30 days in November
31 days in December   
*/
void problem19(){
    long long count = 0;
    long long currentWeekDay = 2;
    // i.e we are starting on a Tuesday since 1 + 365 mod 7
    long long year = 1;
    bool leapYear = false;
    while(year <= 100){
        int day = 1;
        if(year % 4 == 0 && year != 0){
            leapYear = true;
        }
        if(leapYear){
            while(day <= 366){
                if(currentWeekDay % 7 == 0){
                    // currentWeekDay %= 7; redundant line
                    if(day == 1 || day == 32 || day == 61 || day == 92 || day == 122 || day == 153 || day == 183 || day == 214 || day == 245 || day == 275 || day == 306 || day == 336){
                        count++;
                    }
                }
                day++;
                currentWeekDay++;
            }
        }
        if(!leapYear){
            while(day <= 365){
                if(currentWeekDay % 7 == 0){
                    currentWeekDay %= 7;
                    if(day == 1 || day == 31 || day == 60 || day == 91 || day == 121 || day == 152 || day == 182 || day == 213 || day == 244 || day == 274 || day == 305 || day == 335){
                        count++;
                    }
                }
                day++;
                currentWeekDay++;
            }
        }
        year++;
        leapYear = false;
    }

    cout << count << endl;
}

vector<int> addition(vector<int> a, vector<int> b){
    int carry = 0;
    int maxSize = max(a.size(), b.size());

    for(int i = 0; i < maxSize; i++){
        if(i >= a.size()){
            a.push_back(0);
        }

        int digitB = (i < b.size()) ? b[i] : 0;
        // i.e if i is out of bounds for b, use 0 otherwise use b[i]

        a[i] = a[i] + b[i] + carry;
        
        carry = a[i] / 10;
        a[i] %= 10;
    }

    if(carry != 0){
        a.push_back(carry);
    }
    return a;
}

vector<int> multiply(vector<int> a, int b){
    vector<int> output = a;
    for(int i = 0; i < b; i++){
        output = addition(output, a);
    }
    return output;
}

vector<int> fastMultiply(vector<int> a, int b){
    vector<int> result;
    int carry = 0;

    // note this carry still works because something like 1 x 100 will just have a carry of 10 which then turns 
    // into a carry of 1 for the column 2 ahead of 1 so this already accounts for this.
    for(int i = 0; i < a.size(); i++){
        int prod = a[i] * b + carry;
        result.push_back(prod % 10);
        carry = prod / 10;
    }

    while (carry > 0) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

void problem20(){
    vector<int> digits = {1};
    for(int i = 2; i <= 100; i++){
        digits = fastMultiply(digits, i);
    }
    long long count = 0;
    for(int i = 0; i < digits.size(); i++){
        count += digits[i];
    }
    cout << count << endl;
}

int main(){
    problem16();
    problem17();
    problem18();
    problem19();
    problem20();
    return 0;
}