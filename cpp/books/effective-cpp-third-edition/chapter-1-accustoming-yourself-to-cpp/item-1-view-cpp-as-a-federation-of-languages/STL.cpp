#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // cref()
#include <chrono>

/******************** PASS-BY-VALUE ********************/
struct IncrementPBV
{
    int operator()(int value) const
    {
        return value + incrementBy;
    }

    int incrementBy;
};
/******************** PASS-BY-VALUE ********************/

/******************** PASS-BY-REFERENCE-TO-CONST ********************/
struct IncrementPBR
{
    int operator()(const int& value) const
    {
        return value + incrementBy;
    }

    int incrementBy;
};
/******************** PASS-BY-REFERENCE-TO-CONST ********************/

/******************** PERF ********************/
struct Increment
{
    int operator()(int value) const
    {
        return value + incrementBy;
    }

    int incrementBy;
};
/******************** PERF ********************/

int main()
{
    const int incrementValue = 10;

    /***** PBV *****/
    std::vector<int> numbersPBV = {1, 2, 3, 4, 5};
    IncrementPBV incrementOpPBV = {};
    incrementOpPBV.incrementBy = incrementValue;
    std::transform(numbersPBV.begin(), numbersPBV.end(), numbersPBV.begin(), incrementOpPBV);
    for (const auto& num : numbersPBV)
    {
        std::cout << num << " ";
    }
    /***** PBV *****/

    std::cout << std::endl;

    /***** PBR *****/
    std::vector<int> numbersPBR = {1, 2, 3, 4, 5};
    IncrementPBR incrementOpPBR = {};
    incrementOpPBR.incrementBy = incrementValue;
    std::transform(numbersPBR.begin(), numbersPBR.end(), numbersPBR.begin(), std::cref(incrementOpPBR));
    for (const auto& num : numbersPBR)
    {
        std::cout << num << " ";
    }
    /***** PBR *****/

    std::cout << std::endl;

    /***** PERF *****/
    const int SIZE = 1000000;
    std::vector<int> numbers(SIZE, 0);

    Increment incrementOp = {};
    incrementOp.incrementBy = incrementValue;

    auto startTime = std::chrono::high_resolution_clock::now();
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), incrementOp);
    auto endTime = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Pass-by-value duration: " << duration << "ms" << std::endl;

    Increment incrementOpRef = incrementOp;
    startTime = std::chrono::high_resolution_clock::now();
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), std::ref(incrementOpRef));
    endTime = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Pass-by-reference duration: " << duration << "ms" << std::endl;
    /***** PERF *****/

    return 0;
}

/*!
CONCLUSION:
    * When using STL, iterators and function objects are modeled on pointers in C
    * For iterators and function objects in the STL, old C pass-by-value performs better
    * Pass-by-value is generally more efficient than pass-by-reference for built-in
      (C-like) types
*/
