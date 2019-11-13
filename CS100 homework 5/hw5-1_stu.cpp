#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser(){};
    virtual ~DataAnalyser(){};
    /** 
     * virtual function "calculate"
     * @param data: the data array need to be calculated
     * @param size: the length of the data
     * @return: the calculated result
     */
    virtual float calculate(float *data, size_t size)
    {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};

// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser
{
    virtual float calculate(float *data, size_t size)
    {
        float max = *data;
        for (int i = 1; i < size; i++)
            if (*(data + i) > max)
                max = *(data + i);
        return max;
    }
};

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser
{
    // Your code here.
    virtual float calculate(float *data, size_t size)
    {
        float min = *data;
        for sint i = 1; i < size; i++)
            if (*(data + i) < min)
                min = *(data + i);
        return min;
    }
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
    // Your code here.
    virtual float calculate(float *data, size_t size)
    {
        float sum = 0;
        for (int i = 0; i < size; i++)
            sum += *(data + i);
        sum /= size;
        return sum;
    }
};

// MedianAnalyser
class MedianAnalyser : public DataAnalyser
{
    virtual float calculate(float *data, size_t size)
    {
        std::sort((data), (data + size));
        // for (int i = 0; i < size; i++)
        //     std::cout << data[i] << std::endl;
        if (!(size % 2))
            return (*(data + size / 2 - 1) + *(data + size / 2)) / 2;
        else
            return *(data + (size - 1) / 2);
    }
};

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser
{
    virtual float calculate(float *data, size_t size)
    {
        double sum = 0;
        double average = 0;
        for (int i = 0; i < size; i++)
            average += *(data + i);
        average /= size;
        //std::cout<<average<<std::endl;
        for (int i = 0; i < size; i++)
        {
            sum += (*(data + i) - average) * (*(data + i) - average);
        }
        //std::cout<<sum<<std::endl;
        return sqrt(sum / size);
    }
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    /* Your can write your own main for testing */
    /* You can change these numbers to whatever you want*/
    float arr[] = {-5.4545, 5.4545, -67, 67, 98.89, -98.89};
    DataAnalyser *foo = new MedianAnalyser();         /* it can be any of the
required 5 child classes */
    std::cout << foo->calculate(arr, 6) << std::endl; /* should be -100 in
this case */
    delete foo;

    return 0;
}