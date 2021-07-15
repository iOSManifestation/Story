//Name- Kaviraj Pandey
//Regno- 200970008
//Date of Creation- 26-05-21
//Week 3 Program 1- Wap to evaluate postfix expression


#include <iostream>
#include <stack>
#include <string>
using namespace std;

// function prototyping
int operatorAndPrecedence(char c);
string infixToPostfix(string s);
int evalPostfix(string postfix);
int calculate(int a, int b, char operatorSign);

//The function to return precedence of operators
int operatorAndPrecedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

 
//The function to convert infix expression to prefix expression
string infixToPostfix(string s) {
    //stack object
    stack<char> st;
    // this is used to store the result
    string result;
    
    // traversal left to right
    for(int i = 0; i < s.length(); i++) {
        // first char checking
        char c = s[i];
 
        // If the scanned character is an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an ‘(‘, push it to the stack. left parenthesis
        else if(c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’, right parenthesis
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && operatorAndPrecedence(s[i]) <= operatorAndPrecedence(st.top())) {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }//End of for loop
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }
    // end result is our postfix expression
    return result;
}

//Evaluate postfix expression

int evalPostfix(string postfix) {
    stack<int>st1;
    char ch;
    for(int i = 0; i < postfix.length(); i++)
	{
	  ch = postfix[i];
	  if(ch >= '0' && ch <='9')// for single digit
	  {
	    st1.push(ch-'0'); //
	  }
	//found operator
	 else {
	    int a,b;
	    b = st1.top();
	    st1.pop();
	    a = st1.top();
	     st1.pop();
	   st1.push(calculate(a,b,ch));
	  }
	}
	return st1.top();
    }

//calculation of stack items accroding to operator sign
int calculate(int a, int b, char operatorSign) {
    if(operatorSign=='+') {
        return a+b;
    }
    else if(operatorSign=='-') {
        return a-b;
    }
    else if(operatorSign=='*') {
        return a*b;
    }
    else if(operatorSign=='/') {
        return a/b;
    }
    else if(operatorSign=='^') {
        return pow(a,b);
    } else if(operatorSign =='%') {
        return a%b;
    } else {
        return 0;
    }
}


int main() {
   string postfixexpr, infixexpr;
   int ans;
   cout << "Enter infix expression to evaluate in postfix\n";
   cin >> infixexpr;
   postfixexpr = infixToPostfix(infixexpr);
   cout << "Postfix expression is: " << postfixexpr << endl;
   ans = evalPostfix(postfixexpr);
   cout << "Answer is : " << ans << endl;
   return 0;
} 


























































