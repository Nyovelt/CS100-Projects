#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "bits/stdc++.h"

using namespace std;

class ReportParser
{
public:
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    void writeStructuredReport(int sortOption);
    void printReport();
    void sortReport();
    // bool cmp(string a, string b);

private:
    int m_numStudents;
    int m_numInfos;
    int m_sortOption;
    vector<vector<string>> m_Students;
    vector<string> m_Infos;
};

ReportParser::ReportParser(int numStudents, int numInfos)
{
    m_numStudents = numStudents;
    m_numInfos = numInfos;
}

ReportParser::~ReportParser()
{
    // Your code here
}

void ReportParser::readReport()
{
    //storage
    string str;

    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numInfos; j++)
        {
            cin >> str;
            m_Infos.push_back(str);
        }
        m_Students.push_back(m_Infos);
        m_Infos.clear();
    }

    // cout<<m_Students[2][2]<<endl;  //test the function of storage
}

void ReportParser::writeStructuredReport(int sortOption)
{
    m_sortOption = sortOption;
    sortReport();
    printReport();
}

void ReportParser::printReport()
{
    //format
    vector<int> maxLens(m_numInfos, 0);

    for (int j = 0; j < m_numInfos; j++)
        for (int i = 0; i < m_numStudents; i++)
            if (maxLens[j] < (m_Students[i][j].length()))
                maxLens[j] = (m_Students[i][j].length());

    //print
    int maxLength = accumulate(maxLens.begin(), maxLens.end(), +m_numInfos * 3 - 1);
    //cout<<"maxLength:"<<maxLength<<endl;
    printf("/");
    for (int i = 0; i < maxLength; i++)
        printf("-");
    printf("\\\n");
    for (int i = 0; i < m_numStudents; i++)
    {
        for (int j = 0; j < m_numInfos; j++)
        {
            printf("| ");

            cout << m_Students[i][j];
            for (int k = 0; k < (maxLens[j] - m_Students[i][j].length() + 1); k++)
                printf(" ");
        }
        printf("|\n");

        if (i + 1 != m_numStudents)
        {
            for (int j = 0; j < m_numInfos; j++)
            {
                printf("|");
                for (int k = 0; k < (maxLens[j] + 2); k++)
                    printf("-");
            }
            printf("|\n");
        }
    }
    printf("\\");
    for (int i = 0; i < maxLength; i++)
        printf("-");
    printf("/\n");
}

void ReportParser::sortReport()
{
    //sort(m_Students[0][m_sortOption], m_Students[m_numStudents - 1][m_sortOption], cmp);
    for (int i = 0; i < m_numStudents - 1; i++)
    {
        for (int j = 0; j < m_numStudents - 1 - i; j++)
        {
            if (m_Students[j][m_sortOption].compare(m_Students[j + 1][m_sortOption])>0)
                m_Students[j].swap(m_Students[j + 1]);
        }
    }
}

// bool ReportParser::cmp(string a, string b)
// {
// }

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(m, n);
    p.readReport();
    p.writeStructuredReport(sortOption);
    getchar();
    getchar();
    getchar();
    getchar();
    return 0;
}
