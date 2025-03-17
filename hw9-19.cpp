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
    double totalCredit = 0.0;
    double totalDealer = 0.0;

   
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

   
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

   
    cout << fixed << setprecision(2) << endl;
    if (creditPayment == -1 || dealerPayment == -1) {
        cout << "Error: Invalid loan parameters (denominator was 0)." << endl;
    } else {
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Dealer payment: $" << dealerPayment << endl;

       
        totalCredit = creditPayment * term * 12;
        totalDealer = dealerPayment * term * 12;

        cout << "Total paid for the car through the credit union: $" << totalCredit << endl;
        cout << "Total paid for the car through the dealer: $" << totalDealer << endl;
    }

    return 0;
} 


double getPayment(int prin, double monthRate, int months)
{
    double monthPay = 0.0;

    double denominator = (1 - pow(monthRate + 1, -months));
    if (denominator == 0) {
        return -1;  
    }

   
    monthPay = prin * monthRate / denominator;

    return monthPay;
} // End of getPayment function

