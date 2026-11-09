#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int mid = (n + 1) / 2;

    for (int i = 1; i <= n; ++i)
    {
        int spaces = abs(i - mid);
        int stars = n - 2 * spaces;

        // Print spaces
        for (int s = 1; s <= spaces; ++s)
            cout << "  ";

        // Print stars
        for (int j = 1; j <= stars; ++j)
            cout << "* ";

        cout << endl;
    }

    return 0;
}