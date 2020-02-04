# README

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