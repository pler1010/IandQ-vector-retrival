#ifndef H_VECTOR
#define H_VECTOR
#include <vector>
#include <cstdio>
class Vector{
private:
    std::vector<float> vec;
public:
    Vector(const std::vector<float> &initvec);
    int size()const;
    float get(int i)const;
    void print();
    friend bool operator < (const Vector &a,const Vector &b);
};
float getVectorDis(const Vector &a,const Vector &b);
#endif