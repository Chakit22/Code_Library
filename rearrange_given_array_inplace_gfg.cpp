void arrange(long long arr[], int n) {
    // Your code here
    for (int i = 0; i < n; ++i) {
        arr[i] = (arr[arr[i]] % n) * n + arr[i];   //element is value_to_be_paced*n + original_val;
    }
    for (int i = 0; i < n; ++i)
        arr[i] = arr[i] / n;
}