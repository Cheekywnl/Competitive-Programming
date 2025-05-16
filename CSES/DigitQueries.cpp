#include <iostream>
#include <vector>
using namespace std;

/*
Consider an infinite string that consists of all positive long longegers in increasing order:
12345678910111213141516171819..
Task: to process q queries of the form: what is the digit at position k in the string?
*/

/*
Thought process, for each input k keep minusing 9x1, 90x2, 900x3, .... until negative then add back whatever
Then keep reecursivley minusing 1 or 2 or 3 or whatever it might be until 0
Then do however many numbers you have minused e.g 321 and find the remainderth digit 
e.g for 34958 it would be 10000
(10^n - 10^n-1)*n
*/

long long tenPw(long long n){
    // assuming n >= 0
    long long output = 1;
    while(n > 0){
        output *= 10;
        n--;
    }
    return output;
}

char digitQuery(long long k){
    long long count = 0;
    long long digits = 0;
    while(k >= 0){
        digits++;
        k -= (tenPw(digits) - tenPw(digits - 1)) * digits;
    }
    k += (tenPw(digits) - tenPw(digits - 1)) * digits;
    // we now should have a small positive number or 0;
    count = (k - 1)/digits;
    k = (k - 1) % digits;
    // this is the remainder
    string i = to_string(tenPw(digits - 1) + count);
    return i[k];
}

void digitQueries(long long q){
    long long k;
    vector<long long> output;
    for(long long i = 0; i < q; i++){
    
        cin >> k;
        output.push_back(digitQuery(k));
    }
    for(size_t i = 0; i < output.size(); i++){
    //  ^ vector<long long>::size_type (might have a really big output)
        cout << (char)output[i] << endl;
        // for converting ascii value to char ^
    }
    return;
}
/*
Note this now works:
Using long long instead of int because of CSES's constrains for the test cases (1 <= k <= 10^18)
The logic for my code was mostly correct, however note that there were many one off errors, mainly k is
"1 based" so I should be doing k-1 not k. 
*/

// chatGPT's code:
char digitQuery(int k){
    int digits = 0;
    while(k > 0){
        digits++;
        int numCount = tenPw(digits) - tenPw(digits - 1);
        int totalDigits = numCount * digits;
        
        if (k > totalDigits) {
            k -= totalDigits;
        } else {
            // Find the exact number and its digit
            int numberIndex = (k - 1) / digits;  // Zero-based index
            int digitIndex = (k - 1) % digits;   // Zero-based index within the number
            
            int actualNumber = tenPw(digits - 1) + numberIndex;
            string numStr = to_string(actualNumber);
            
            return numStr[digitIndex];
        }
    }
    return '0';  // Should never reach here
}

/*
Note chatGPT's main function is much nicer:
int main() {
    long long q, k;
    cout << "Enter number of queries: ";
    cin >> q;
    
    while (q--) {
        cin >> k;
        cout << digitQuery(k) << endl;
    }
    
    return 0;
}
*/
int main(){
    long long q;
    //cout << "Enter q:" << endl;
    cin >> q; 
    digitQueries(q);
    return 0;
}