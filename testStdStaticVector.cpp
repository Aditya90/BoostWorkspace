#include "boost/container/static_vector.hpp"
#include <iostream>

class Circle
{
private:
    unsigned int radius_{0};
    std::string nameCircle_{};

public:
    Circle() = delete;
    Circle(unsigned int radius, std::string name) : radius_(radius), nameCircle_(name) {}
    virtual ~Circle() = default;

    friend std::ostream &operator<<(std::ostream &output, const Circle &D)
    {
        output << "Name : " << D.nameCircle_ << std::endl;
        output << "Radius : " << D.radius_ << std::endl;
        return output;
    }
};

template <class DataType>
void staticVectorPrintInfo(DataType &dataObject)
{
    std::cout << "Capacity : " << dataObject.capacity() << std::endl;
    std::cout << "Max Size : " << dataObject.max_size() << std::endl;
    std::cout << "Size : " << dataObject.size() << std::endl;

    for (const auto &element : dataObject)
    {
        std::cout << "Value in static vector : " << element << std::endl;
    }

    // Throws an exception
    // std::cout << "Value in static vector : " << dataObject.at(6) << std::endl;

    // Fails assertion
    // std::cout << "Value in static vector : " << dataObject[6] << std::endl;
}

int main()
{
    {
        using IntStaticVector = boost::container::static_vector<int, 50>;

        IntStaticVector staticIntVector(5);
        // std::bad_alloc
        // IntStaticVector staticIntVector(51);

        staticVectorPrintInfo<IntStaticVector>(staticIntVector);

        // Throws an exception
        // std::cout << "Value in static vector : " << staticIntVector.at(6) << std::endl;

        // Fails assertion
        // std::cout << "Value in static vector : " << staticIntVector[6] << std::endl;
    }

    {
        using CircleStaticVector = boost::container::static_vector<Circle, 50>;
        CircleStaticVector staticIntVector(6, {5, "Circle"});

        staticVectorPrintInfo<CircleStaticVector>(staticIntVector);
    }

    return 1;
}