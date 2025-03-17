#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype (changed return type to void)
void getPayment(int, double, int, double &);

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
        cout <<

