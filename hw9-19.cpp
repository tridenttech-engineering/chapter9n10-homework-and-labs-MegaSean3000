#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype to calculate the monthly payment
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

    // Get inputs from the user
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

    // Calculate monthly payments for both options
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Output the monthly payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;

    // Calculate and display the total amount paid over the loan period
    double creditTotal = creditPayment * term * 12;
    double dealerTotal = dealerPayment * term * 12;

    cout << "Total paid to the credit union: $" << creditTotal << endl;
    cout << "Total paid to the dealer: $" << dealerTotal << endl;

    return 0;
}

// Function definition to calculate the monthly payment
double getPayment(int prin, double monthRate, int months)
{
    double monthPay = 0.0;

    // If the interest rate is 0 (monthRate is 0), the formula simplifies
    if (monthRate == 0) {
        return prin / months;  // Monthly payment is just the principal divided by months
    }

    // Normal case for non-zero interest rate
    double denominator = 1 - pow(1 + monthRate, -months);

    // Calculate monthly payment using the formula
    monthPay = prin * monthRate / denominator;

    return monthPay;
}
