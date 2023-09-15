#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;
    int height = 0;
    int lineheight = 1;
    int maxheight = 2;
    bool ascending = true;
    int acc = 0;

    while (acc != x) {
        acc += 1;
        if (height == lineheight - 1) {
            cout << acc << endl;
            if (maxheight == lineheight) {
                maxheight += 1;
                ascending = false;
            } else if (1 == lineheight) {
                ascending = true;
            }
            lineheight += ascending ? 1 : -1;
            height = 0;
        } else {
            cout << acc << " ";
            height += 1;
        }
    }
    return 0;
}

// the most surprising thing is that it worked first try.
// there is probably a faster non-iterative solution, considering the sum of
// consecutive integers is easily calculated in O(1). It's up to the reader to
// find that solution.
