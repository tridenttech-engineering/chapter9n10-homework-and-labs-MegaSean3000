#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getPayment(int prin, double monthRate, int months);

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
    cout << "Credit union rate (as a decimal): ";
    cin >> creditRate;
    cout << "Dealer rate (as a decimal): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Check if either payment calculation returned -1 (indicating an error in the formula)
    if (creditPayment == -1 || dealerPayment == -1) {
        cout << "Error: Invalid loan parameters (denominator in formula is 0)." << endl;
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

    // If the interest rate is 0 (monthRate is 0), the formula simplifies
    if (monthRate == 0) {
        return prin / months;  // Monthly payment is just the principal divided by months
    }

    // Normal case for non-zero interest rate
    double denominator = 1 - pow(1 + monthRate, -months);

    // If the denominator is zero (this should never really happen unless inputs are malformed)
    if (denominator == 0) {
        return -1;  // Return -1 to indicate an error
    }

    monthPay = prin * monthRate / denominator;

    return monthPay;
}
