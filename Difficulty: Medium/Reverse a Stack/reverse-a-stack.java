class Solution {
   
    
    public static void reverseStack(Stack<Integer> st) {
        Stack<Integer> stac = new Stack<Integer>();
        while(!st.empty()){
            stac.push(st.pop());
        }
        st.addAll(stac);
        
}
}
