bool isUgly(int n) {
    if (n <= 0)
        return false;

    while (n > 1) {
        //if n has any other factors other than these then it will directly break;
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 5 == 0)
            n /= 5;
        else
            break;
    }
    return n == 1; //if at last n is not 1 then it definitely means it had one of the prime factors other than 2,3 5.
}