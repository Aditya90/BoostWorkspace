# README

## Summary of static_vector

(From proposal)
The static_vector container is useful when:
1. Memory allocation is not possible, e.g., embedded environments without a free store, where only a stack and the static memory segment are available,
2. Memory allocation imposes an unacceptable performance penalty, e.g., with respect to latency,
3. Allocation of objects with complex lifetimes in the static-memory segment is required,
4. std::array is not an option, e.g., if non-default constructible objects must be stored,
5. A dynamically-resizable array is required within constexpr functions,
6. The storage location of the static_vector elements is required to be within the static_vector object itself (e.g. to support memcopy for serialization purposes).


### Notes
1. When used with `-fno-exceptions` and `-fno-rtti`, the exceptions are static assertions. 
2. `std::bad_alloc` if you try to assign more than the capacity of the static vector
```CPP
using IntStaticVector = boost::container::static_vector<int, 50>;

IntStaticVector staticIntVector(5);
// std::bad_alloc
// IntStaticVector staticIntVector(51);
```
3. Referenced https://howardhinnant.github.io/stack_alloc.html which talks about an allocator which can be used to avoid dynamic memory allocation for standard containers. (Need to look into this)

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

## References
1. `static_vector` proposal - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0843r4.html
