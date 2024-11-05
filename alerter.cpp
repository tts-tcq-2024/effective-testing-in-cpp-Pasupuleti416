#include <iostream>
using namespace std;

class Alerter {
public:
    static int alertFailureCount; // Static variable to count alert failures

    // Flag to simulate network failure
    static bool simulateNetworkFailure;

    static int networkAlertStub(float celcius) {
        cout << "ALERT: Temperature is " << celcius << " celcius" << endl;
        // Simulate a failure based on the flag
        return simulateNetworkFailure ? 500 : 200;
    }

    static void alertInCelcius(float farenheit) {
        float celcius = (farenheit - 32) * 5 / 9;
        int returnCode = networkAlertStub(celcius);
        if (returnCode != 200) {
            // Count the failure correctly
            alertFailureCount += 1;  // Increment failure count on non-ok response
        }
    }
};

// Initialize static variables
int Alerter::alertFailureCount = 0;
bool Alerter::simulateNetworkFailure = false;

int main() {
    // Test case: Initially, we simulate a successful network call
    Alerter::alertInCelcius(400.5f);
    Alerter::alertInCelcius(303.6f);

    // Show count of failed alerts before simulating a failure
    cout << Alerter::alertFailureCount << " alerts failed." << endl;

    // Simulate network failure
    Alerter::simulateNetworkFailure = true;

    // Test case: Now, with simulated network failure
    Alerter::alertInCelcius(400.5f);
    Alerter::alertInCelcius(303.6f);

    // Show count of failed alerts after simulating failure
    cout << Alerter::alertFailureCount << " alerts failed after simulation." << endl;

    cout << "All is well (maybe!)" << endl;

    return 0;
}
