#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment)
    {
        m_start = start;
        m_end = end;
        m_increment = increment;
    }

    // virtual destructor
    virtual ~LookupTable(){};

    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;

protected:
    double m_start;
    double m_end;
    double m_increment;
};

class SquareLookupTable : public LookupTable
{
public:
    SquareLookupTable(double start, double end, double increment) : LookupTable(start, end, increment)
    {
    }

    virtual ~SquareLookupTable(){};

    virtual double getValue(double x)
    {
        if (x > m_end || x < m_start)
            return 0;

        int k_1 = int((x - m_start) / m_increment); //the serial of X_k
        int k_2 = int((x - m_start) / m_increment) + 1;
        double a_1 = m_start + k_1 * m_increment; //the value of X_k
        double a_2 = m_start + k_2 * m_increment;
        double n_1 = a_1 * a_1; //The value of f(X_k)
        double n_2 = a_2 * a_2;
        double res = ((x - a_1) * n_2 + (a_2 - x) * n_1) / (a_2 - a_1);

        // cout<<"k:"<<k_1<<" "<<k_2<<endl;
        // cout<<"a:"<<a_1<<" "<<a_2<<endl;
        // cout<<"n:"<<n_1<<" "<<n_2<<endl;

        return res;
    }
};

class SinLookupTable : public LookupTable
{
public:
    SinLookupTable(double start, double end, double increment) : LookupTable(start, end, increment) {}
    virtual ~SinLookupTable() {}

    virtual double getValue(double x)
    {
        if (x > m_end || x < m_start)
            return 0;

        int k_1 = int((x - m_start) / m_increment); //the serial of X_k
        int k_2 = int((x - m_start) / m_increment) + 1;
        double a_1 = m_start + k_1 * m_increment; //the value of X_k
        double a_2 = m_start + k_2 * m_increment;
        double n_1 = sin(a_1); //The value of f(X_k)
        double n_2 = sin(a_2);
        double res = ((x - a_1) * n_2 + (a_2 - x) * n_1) / (a_2 - a_1);

        // cout<<"k:"<<k_1<<" "<<k_2<<endl;
        // cout<<"a:"<<a_1<<" "<<a_2<<endl;
        // cout<<"n:"<<n_1<<" "<<n_2<<endl;

        return res;
    }
};

class LogLookupTable : public LookupTable
{
public:
    LogLookupTable(double start, double end, double increment) : LookupTable(start, end, increment)
    {
    }

    virtual ~LogLookupTable()
    {
    }

    virtual double getValue(double x)
    {
        if (x > m_end || x < m_start)
            return 0;

        int k_1 = int((x - m_start) / m_increment); //the serial of X_k
        int k_2 = int((x - m_start) / m_increment) + 1;
        double a_1 = m_start + k_1 * m_increment; //the value of X_k
        double a_2 = m_start + k_2 * m_increment;
        double n_1 = log(a_1); //The value of f(X_k)
        double n_2 = log(a_2);
        double res = ((x - a_1) * n_2 + (a_2 - x) * n_1) / (a_2 - a_1);

        // cout << "k:" << k_1 << " " << k_2 << endl;
        // cout << "a:" << a_1 << " " << a_2 << endl;
        // cout << "n:" << n_1 << " " << n_2 << endl;

        return res;
    }
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    LookupTable *b = new SquareLookupTable(1, 9, 1);
    cout << "res"
         << " " << b->getValue(2.23) << endl;
    return 0;
}
