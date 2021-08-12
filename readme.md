# Overview

This is a Code Nummy about psuedo random number generators, specifically the RANDU algorithm. Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

The first part of this Code Nummy, is to implement the RANDU algorithm. In a second step we will learn why RANDU is a
bad choice for statistical calculations or other numerical method, e.g. Monte Carlo simulations.

![render](https://user-images.githubusercontent.com/2394228/126345222-d841e098-a53f-4757-8f5f-b40fc518d7c4.gif)

# Theory

## Pseudo random number generators

Computers have a hard time with generating random values, as they behave in a deterministic way. However, they can still
create pseudo random numbers, by making use of some clever algebraic rules.

For high quality random numbers, it is recommended to use e.g.
the [Mersenn Twister 19937](https://www.cplusplus.com/reference/random/mt19937/), which is available staring with C++11.

## The RANDU algorithm

This Nummy will take a look at a comparable bad, historical pseudo random number generator named "RANDU". Let's take a
look at The RANDU algorithm:

1. `v[0] = 1` (this is the initial seed)
2. `vMax = 2**31`
3. `v[i+1] = (65539 × v[i]) % vMax`

At the time when this algorithm was introduced, it could be calculated very quickly, because the modulo operation with a
power of two could be calculated efficiently. However, RANDU is highly flawed ("a truly horrible random number
generator", [Donald Knuth, The Art of Computer Programming](https://amzn.to/2teAtd8)), as we will see later on.

# Exercise

## Implementation

Implement the RANDU algorithm in the function `Randu::next()` in the file `src/randu.cpp`. The unit tests
in `test/randu_implementation_test.cpp` will cover the implementation (ignore the rest of the test cases for now).

## Check last decimal digit

Now it is time for us to learn why RANDU is such a bad choice. Take a look at
the `LastDecimalDigitContainsOnlyOddNumbers` test in the file `tests/randu_last_digits_test.cpp`. This test needs to be
written by you.

* It should calculate 5000 pseudo random values using randu.
* For each number, the test is only interested in the last decimal digit. If the pseudo random number is `95552217`, the
  test is interested in the `7`.
* Verify, that only odd digits appear in the last decimal place.
* Why is this a problem for random numbers?

### Bonus objective

* Calculate the distribution of the last decimal digits for the calculated pseudo random values. Is the behavior
  expected to change with the initial seed (`v[0]`)?

## Check last hex digit

The decimal representation of the numbers is bad. But RANDU can do worse!
Let's take a look for the hex representation of the pseudo random numbers. Implement
the `LastDecimalDigitContainsOnlyCertainValues` test. Again, this test is only interested in the last hexadecimal digit.

Verify that only the values `1`, `3`, `9` and `b` appear (for an initial seed of 1).

### Hint

you can use `std::stringstream` and `std::hex`.

### Bonus objective

Take a look at the distribution of the last hexadecimal digit and compare it with the distribution of the last decimal
digits.

## Visual representation in multiple dimensions.

For the last nail in the coffin, let's take a look at the values when using the pseudo random values created by RANDU as
the coordinates.

The test case `WriteTriples` in the file `tests/randu_visualisation_test.cpp` writes tuples of three out in a text file.
Plot the three values in every line as the `(x, y, z)` coordinates in your preferred plotting software (matplotlib,
gnuplot, matlab, ...).

Reproduce the picture shown at the beginning of this readme.

# Further Reading

* [Peter Young (2013): "Randu: a bad random number generator](http://physics.ucsc.edu/~peter/115/randu.pdf)
* [G. Marsaglia (1968): "RANDOM NUMBERS FALL MAINLY IN THE PLANES"](http://www.pnas.org/content/61/1/25)
* [Mersenn Twister 19937 (cplusplus.com)](https://www.cplusplus.com/reference/random/mt19937/)
