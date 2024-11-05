#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// Function to determine the size based on cms
string size(int cms) {
    if (cms < 38) {
        return "S";
    } else if (cms >= 38 && cms < 42) { // Adjusted to include 38 in "M"
        return "M";
    } else {
        return "L";
    }
}

int main() {
    // Assert statements for size function
    assert(size(37) == "S");
    assert(size(38) == "M");
    assert(size(40) == "M");
    assert(size(42) == "M"); // Added test for 42 to ensure it's "M"
    assert(size(43) == "L");

    // Print confirmation message
    cout << "All is well (maybe!)" << endl;

    return 0;
}
