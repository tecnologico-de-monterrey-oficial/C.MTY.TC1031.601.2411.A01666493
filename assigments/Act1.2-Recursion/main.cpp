#include <iostream>

using namespace std;

int sumIterative(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

int sumRecursive(int n){
    if(n == 0){
        return 0;
    }
    return n + sumRecursive(n-1);
}


int sumFormula(int n){
    return n * (n+1) / 2;
}

int fibonacciIterative(int n){
    int a = 0, b = 1, c;
    if(n == 0){
        return a;
    }
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int fibonacciRecursive(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}


int bacteriaGrowthIterative(int days) {
    int bacteria = 1;
    for (int day = 1; day <= days; day++) {
        int births = bacteria * 378 / 100;
        int deaths = bacteria * 234 / 100;
        bacteria += births - deaths;
        bacteria = max(bacteria, 0);
    }
    return bacteria;
}


int bacteriaGrowthRecursive(int days) {
    if (days == 0) return 1;
    int previousDayBacteria = bacteriaGrowthRecursive(days - 1);
    int births = previousDayBacteria * 378 / 100;
    int deaths = previousDayBacteria * 234 / 100;
    int currentBacteria = previousDayBacteria + births - deaths;
    return max(currentBacteria, 0);
}


double investmentGrowthIterative(double amount, int months) {
    double interestRate = 18.75 / 100;
    for (int month = 1; month <= months; month++) {
        amount += amount * interestRate;
    }
    return amount;
}

double investmentGrowthRecursive(double amount, int months) {
    if (months == 0) return amount;
    return investmentGrowthRecursive(amount + amount * 18.75 / 100, months - 1);
}


double powerIterative(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double powerRecursive(double base, int exponent) {
    if (exponent == 0) return 1;
    return base * powerRecursive(base, exponent - 1);
}


int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
   

    cout << "Sum using iterative method: " << sumIterative(n) << endl;
    cout << "Sum using recursive method: " << sumRecursive(n) << endl;
    cout << "Sum using formula: " << sumFormula(n) << endl;
    cout << "------------------------------------\n";

    cout << "Fibonacci using iterative method: " << fibonacciIterative(n) << endl;
    cout << "Fibonacci using recursive method: " << fibonacciRecursive(n) << endl;
    cout << "------------------------------------\n";

    cout << "Bacteria growth using iterative method: " << bacteriaGrowthIterative(n) << endl;
    cout << "Bacteria growth using recursive method: " << bacteriaGrowthRecursive(n) << endl;
    cout << "------------------------------------\n";

    cout << "Investment growth using iterative method: " << investmentGrowthIterative(1000, n) << endl;
    cout << "Investment growth using recursive method: " << investmentGrowthRecursive(1000, n) << endl;
    cout << "------------------------------------\n";

    cout << "Power using iterative method: " << powerIterative(2, n) << endl;
    cout << "Power using recursive method: " << powerRecursive(2, n) << endl;

    return 0;
}