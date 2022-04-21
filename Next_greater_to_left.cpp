vector<int> Next_greater_left(int arr[], int n) {
    stack<int>st;
    vector<int>ngl(n);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() and arr[st.top()] <= arr[i])
            st.pop();
        if (!st.empty())
            ngl[i] = st.top();
        else
            ngl[i] = -1;

        st.push(i);
    }
    return ngl;
}