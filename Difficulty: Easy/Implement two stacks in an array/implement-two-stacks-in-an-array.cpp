//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  private:
    int arr[10000 + 1];
    int top1;
    int top2;
  public:

    twoStacks() {
        //do nothing here
        top1 = -1;
        top2 = 10000;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        top1++;
        arr[top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        top2--;
        arr[top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            // Stack Underflow
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if (top2 < 10000) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            // Stack Underflow
            return -1;
        }
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends