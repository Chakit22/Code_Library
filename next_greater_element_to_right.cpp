vector<long long> nextLargerElement(vector<long long> arr, int n) {
    // Your code here
    vector<long long>v(n, -1);

    stack<long long>s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() <= arr[i])
            s.pop();

        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        v[i] = s.top();
        s.push(arr[i]);
    }

    return v;
}