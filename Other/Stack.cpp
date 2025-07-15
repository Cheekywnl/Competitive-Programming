#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '{' || c == '(' || c == '['){
            st.push(c);
        }
        else if(c == ')'){
            if(st.empty()) return false;
            if(st.top() == '('){
                st.pop();
            }
            else return false;
        }
        else if(c == '}'){
            if(st.empty()) return false;
            if(st.top() == '{'){
                st.pop();
            }
            else return false;
        }
        else if(c == ']'){
            if(st.empty()) return false;
            if(st.top() == '['){
                st.pop();
            }
            else return false;
        }
    }
    if(st.empty()){
        return true;
    }
    return false;;
}

// making a MinStack in c++
class MinStack {
public:

    vector<int> values;
    vector<int> mins;
    
    MinStack() {}

    void push(int val) {
        values.push_back(val);
        if(mins.empty() || val <= mins.back()){ // note back is just the last element of a vector in c++.
            mins.push_back(val);
        }
    }
    
    void pop() {
        if(values.back() == mins.back()){
            mins.pop_back();
        }
        values.pop_back();
    }
    
    int top() {
        return values.back();
    }
    
    int getMin() {
        return mins.back();
    }
};

// just note its normally temp2 OP temp1
int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for(string s : tokens){
        if(s == "+"){
            int temp1 = numbers.top();
            numbers.pop();
            int temp2 = numbers.top();
            numbers.pop();
            numbers.push(temp1 + temp2);
        }
        else if(s == "-"){
            int temp1 = numbers.top();
            numbers.pop();
            int temp2 = numbers.top();
            numbers.pop();
            numbers.push(temp2 - temp1);
        }
        else if(s == "*"){
            int temp1 = numbers.top();
            numbers.pop();
            int temp2 = numbers.top();
            numbers.pop();
            numbers.push(temp1 * temp2);
        }
        else if(s == "/"){
            int temp1 = numbers.top();
            numbers.pop();
            int temp2 = numbers.top();
            numbers.pop();
            numbers.push(temp2 / temp1);
        }
        else{
            numbers.push(stoi(s));
        }
    }
    return numbers.top();
}

vector<string> generateParenthesis(int n){

    struct State{
        string current;
        int open;
        int closed;
    };

    stack<State> stk;
    vector<string> output;
    stk.push({"", 0, 0});

    while(!stk.empty()){
        State s = stk.top();
        stk.pop();

        if(s.current.length() == n * 2){
            output.push_back(s.current);
            continue;
        }

        if(s.open < n){
            stk.push({s.current + "(", s.open + 1, s.closed});
        }

        if(s.closed < s.open){
            stk.push({s.current + ")", s.open, s.closed + 1});
        }
    }

    return output;
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> output(temperatures.size(), 0);
    stack<pair<int, int>> stk;
    for(int i = 0; i < temperatures.size(); i++){
        while(!stk.empty() && temperatures[i] > stk.top().first){ // note order of logical operations matter, always !stk.empty() first.
            output[stk.top().second] = i - stk.top().second;
            stk.pop();
        }
        stk.push({temperatures[i], i});
    }
    return output;
}

// note make sure you go in reverse order since fleet updating logic is simpler.
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> order;
    for(int i = 0; i < position.size(); i++){
        order.push_back({position[i], speed[i]});
    }
    sort(order.rbegin(), order.rend());
    // rbegin is the reverse iterator
    int output = 0;
    double lastFleetTime = 0;
    for(int i = 0; i < order.size(); i++){
        double time = (double)(target - order[i].first) / order[i].second;
        // make sure you cast to double.
        if(time > lastFleetTime){
            output++;
            lastFleetTime = time; 
        }
        // going in reverse so only update when overtaking the last one in a fleet.
    }
    return output;
}

int myLargestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> width(n, 1);
    stack<int> stk;

    for(int i = 0; i < n; i++){
        while(!stk.empty() && heights[stk.top()] >= heights[i]){ 
            int top = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            width[top] = i - left - 1;
        } 
        stk.push(i);
    }

    while(!stk.empty()) stk.pop();

    for(int i = n - 1; i >= 0; i--){
        while(!stk.empty() && heights[stk.top()] >= heights[i]){ 
            int top = stk.top();
            stk.pop();
            int right = stk.empty() ? n : stk.top();
            width[top] = right - i - 1;
        } 
        stk.push(i);
    }

    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        width[top] += stk.empty() ? n : (stk.top() - top  - 1); 
    }

    int maxArea = 0;
    for(int i = 0; i < heights.size(); i++){
        if(width[i] * heights[i] > maxArea) maxArea = width[i] * heights[i];
    }

    return maxArea;
}

// chatGPT's approach, same time complexity uses one monotonic stack and just nicer:

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    stack<int> index;
    heights.push_back(0); // adds a sentinel value so that we process all bars.
    for(int i = 0; i < heights.size(); i++){
        while(!index.empty() && heights[i] < heights[index.top()]){
            int height = heights[index.top()];
            index.pop();
            int width = index.empty() ? i : i - index.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        index.push(i);
    }

    heights.pop_back();
    return maxArea;
}

int main(){
    return 0;
}