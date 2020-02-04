# README

## Getting started
1. Download boost from https://www.boost.org/doc/libs/1_72_0/more/getting_started/unix-variants.html
2. Extract the file to the repo folder (if you want to make minimal changes)
3. Point the makefile to the boost folder (a change might only be needed if you changed the boost version)

## static_vector

# Using `at` when out of bounds

1. Enable no-exceptions flag
```
a.out: boost_1_72_0/boost/container/throw_exception.hpp:64: void boost::container::throw_out_of_range(const char*): Assertion `(!msg)&&(str)' failed.
Aborted (core dumped)
```
2. Disable no-exceptions flag
```
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::at out of range
Aborted (core dumped)
```