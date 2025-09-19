// User function Template for Java
class Solution {
    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        if(st.empty()){
           st.push(x);
           return st;
        }
        int element = st.peek();
        st.pop();
        insertAtBottom(st,x);
        
        st.push(element);
        return st;
    }
}