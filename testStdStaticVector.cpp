#include "boost/container/static_vector.hpp"
#include <iostream>

int main()
{
    boost::container::static_vector<int, 50> staticIntVector(5);

    // std::bad_alloc
    // boost::container::static_vector<int, 50> staticIntVector(51);

    std::cout << "Capacity : " << staticIntVector.capacity() << std::endl;
    std::cout << "Max Size : " << staticIntVector.max_size() << std::endl;
    std::cout << "Size : " << staticIntVector.size() << std::endl;

    for (const auto &element : staticIntVector)
    {
        std::cout << "Value in static vector : " << element << std::endl;
    }

    // Throws an exception
    // std::cout << "Value in static vector : " << staticIntVector.at(6) << std::endl;

    // Fails assertion
    // std::cout << "Value in static vector : " << staticIntVector[6] << std::endl;

    return 1;
}