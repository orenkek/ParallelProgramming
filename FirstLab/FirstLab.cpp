// FirstLab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>


using namespace std;




static bool IsPrime(long long n) {
    if (n == 1)
        return false;
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
static void PrintAnswer(long long array[], int length) {
    for (long long i = 0; i < length; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;
}

static void OneCore(long long number) {
    cout << "One core work" << endl;
    int volumeOfPrimeNumbers = 0;
    int temp = 0;
    for (long long i = 1; i <= number; i++) {
        if (IsPrime(i))
            volumeOfPrimeNumbers++;
    }

    long long* primeNumbers = new long long[volumeOfPrimeNumbers];
    double t = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (int i = 1; i <= number; i++) {
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
    }
    t = omp_get_wtime() - t;
    PrintAnswer(primeNumbers, temp);
    cout << "Time : " << t << endl << endl;
}
static void TwoCores(long long number) {
    cout << "Two cores work" << endl;
    int volumeOfPrimeNumbers = 0;
    int temp = 0;
    for (long long i = 1; i <= number; i++) {
        if (IsPrime(i)) {
            volumeOfPrimeNumbers++;
        }
    }
    long long* primeNumbers = new long long[volumeOfPrimeNumbers];
    double t = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (long long i = 1; i <= number; i+=2) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 2; i <= number; i+=2) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
    }
    t = omp_get_wtime() - t;
    PrintAnswer(primeNumbers, volumeOfPrimeNumbers);
    cout << "Time : " << t << endl << endl;
}
static void ThreeCores(long long number) {
    cout << "Four cores work" << endl;
    int volumeOfPrimeNumbers = 0;
    int temp = 0;
    for (long long i = 1; i <= number; i++) {
        if (IsPrime(i)) {
            volumeOfPrimeNumbers++;
        }
    }
    long long* primeNumbers = new long long[volumeOfPrimeNumbers];
    double t = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (long long i = 1; i <= number; i += 3) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 2; i <= number; i += 3) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 3; i <= number; i += 3) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
    }
    t = omp_get_wtime() - t;
    PrintAnswer(primeNumbers, volumeOfPrimeNumbers);
    cout << "Time : " << t << endl << endl;
}
static void FourCores(long long number) {
    cout << "Four cores work" << endl;
    int volumeOfPrimeNumbers = 0;
    int temp = 0;
    for (long long i = 1; i <= number; i++) {
        if (IsPrime(i)) {
            volumeOfPrimeNumbers++;
        }
    }
    long long* primeNumbers = new long long[volumeOfPrimeNumbers];
    double t = omp_get_wtime();
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (long long i = 1; i <= number; i += 4) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 2; i <= number; i += 4) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 3; i <= number; i += 4) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
#pragma omp section
        {
            for (long long i = 4; i <= number; i += 4) {
#pragma omp critical
                if (IsPrime(i)) {
                    primeNumbers[temp] = i;
                    temp++;
                }
            }
        }
    }
    t = omp_get_wtime() - t;
    PrintAnswer(primeNumbers, volumeOfPrimeNumbers);
    cout << "Time : " << t << endl << endl;
}
static void WithFor(int number) {
    cout << "With for cycle work" << endl;
    int volumeOfPrimeNumbers = 0;
    int temp = 0;
    for (long long i = 1; i <= number; i++) {
        if (IsPrime(i)) {
            volumeOfPrimeNumbers++;
        }
    }
    long long* primeNumbers = new long long[volumeOfPrimeNumbers];
    double t = omp_get_wtime();
#pragma omp parallel for
    for (long long i = 1; i < number; i++) {
        if (IsPrime(i)) {
            primeNumbers[temp] = i;
            temp++;
        }
    }
    t = omp_get_wtime() - t;
    PrintAnswer(primeNumbers, volumeOfPrimeNumbers);
    cout << "Time : " << t << endl << endl;
}
int main()
{
    int number;
    cout << "Enter end of diapazone range ";
    cin >> number;
    OneCore(number);
    TwoCores(number);
    ThreeCores(number);
    FourCores(number);
    WithFor(number);
}