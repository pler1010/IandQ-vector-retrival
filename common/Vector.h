#ifndef H_VECTOR
#define H_VECTOR
#include <vector>
class Vector{
    std::vector<float> vec;
public:
    Vector(const std::vector<float> &initvec){
        vec.resize(initvec.size());
        for(int item:initvec) vec.push_back(item);
    }
    void print(){
        for(int item:vec) printf("%f ",item);
        puts("");
    }
};
#endif