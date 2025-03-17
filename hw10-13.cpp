#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype (changed return type to void)
void getPayment(int prin, double monthRate, int months, double &total);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCredit = 0.0;
    double totalDealer = 0.0;

    // Input values from the user
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments (no return value)
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment);
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment);

    // Display the monthly payments
    cout << fixed << setprecision(2) << endl;
    if (creditPayment == -1 || dealerPayment == -1) {
        cout << "Error: Invalid loan parameters (denominator was 0)." << endl;
    } else {
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Dealer payment: $" << dealerPayment << endl;

        // Calculate and display the total amounts paid
        totalCredit = creditPayment * term * 12;
        totalDealer = dealerPayment * term * 12;

        cout << "Total paid for the car through the credit union: $" << totalCredit << endl;
        cout << "Total paid for the car through the dealer: $" << totalDealer << endl;
    }

    return 0;
} // End of main function

// Function to calculate the monthly payment (void function, modifies 'total')
void getPayment(int prin, double monthRate, int months, double &total)
{
    // Verify that the denominator is not zero
    double denominator = (1 - pow(monthRate + 1, -months));
    if (denominator == 0) {
        total = -1;  // Set total to -1 to indicate error
        return;  // Exit the function if error occurs
    }

    // Calculate the monthly payment if the denominator is not zero
    double monthPay = prin * monthRate / denominator;

    // Update the total (total is passed by reference, so we modify the original variable)
    total = monthPay;
}

