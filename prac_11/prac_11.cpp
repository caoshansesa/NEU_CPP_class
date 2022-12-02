// Fig. 24.11: ThreadedFibonacci.cpp
// Fibonacci calculations performed in separate threads
#include <ctime>
#include <future>
#include <iomanip>
#include <iostream>
using namespace std;

// class to represent the results
class ThreadData
{
  public:
    time_t startTime; // time thread starts processing
    time_t endTime;   // time thread finishes processing
};                    // end class ThreadData

unsigned long long int fibonacci(unsigned int n); // function prototype
ThreadData startFibonacci(unsigned int n);        // function prototype

int main()
{
    cout << fixed << setprecision(6);
    cout << "Calculating fibonacci( 45 ) and fibonacci( 44 ) "
         << "in separate threads" << endl;

    cout << "Starting thread to calculate fibonacci( 45 )" << endl;
    auto futureResult1 = async(launch::async, startFibonacci, 45);
    cout << "Starting thread to calculate fibonacci( 44 )" << endl;
    auto futureResult2 = async(launch::async, startFibonacci, 44);

    // wait for results from each thread
    ThreadData result1 = futureResult1.get();
    ThreadData result2 = futureResult2.get();

    // determine time that first thread started
    time_t startTime = (result1.startTime < result2.startTime) ? result1.startTime : result2.startTime;

    // determine time that last thread terminated
    time_t endTime = (result1.endTime > result2.endTime) ? result1.endTime : result2.endTime;

    // display total time for calculations
    cout << "Total calculation time = " << difftime(endTime, startTime) / 60.0 << " minutes" << endl;
} // end main

// executes function fibonacci asynchronously
ThreadData startFibonacci(unsigned int n)
{
    // create a ThreadData object to store times
    ThreadData result = {0, 0};

    cout << "Calculating fibonacci( " << n << " )" << endl;
    result.startTime = time(nullptr); // time before calculation
    auto fibonacciValue = fibonacci(n);
    result.endTime = time(nullptr); // time after calculation

    // display fibonacci calculation result and total calculation time
    cout << "fibonacci( " << n << " ) = " << fibonacciValue << endl;
    cout << "Calculation time = " << difftime(result.endTime, result.startTime) / 60.0 << " minutes\n" << endl;
    return result;
} // end function startFibonacci

// Recursively calculates fibonacci numbers
unsigned long long int fibonacci(unsigned int n)
{
    // base case
    if (0 == n || 1 == n)
    {
        return n;
    }    // end if
    else // recursive step
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    } // end else
} // end function fibonacci

