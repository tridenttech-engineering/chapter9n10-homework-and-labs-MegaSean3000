 #include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getPayment(int, double, int);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

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

    // Calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Check for errors in payment calculation
    if (creditPayment == -1 || dealerPayment == -1) {
        cout << "Error: Invalid loan rates (denominator in formula is 0)." << endl;
    } else {
        // Output the monthly payments
        cout << fixed << setprecision(2) << endl;
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Dealer payment: $" << dealerPayment << endl;

        // Calculate and display the total amount paid over the loan period
        double creditTotal = creditPayment * term * 12;
        double dealerTotal = dealerPayment * term * 12;

        cout << "Total paid to the credit union: $" << creditTotal << endl;
        cout << "Total paid to the dealer: $" << dealerTotal << endl;
    }

    return 0;
}

double getPayment(int prin, double monthRate, int months)
{
    double monthPay = 0.0;
    
    // Check if the denominator in the payment formula is zero
    if (1 - pow(monthRate + 1, -months) == 0) {
        return -1; // Return -1 if denominator is zero
    }
    
    // Calculate the monthly payment
    monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
    return monthPay;
}
