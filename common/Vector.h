#ifndef H_VECTOR
#define H_VECTOR
#include <vector>
#include <cstdio>
class Vector{
private:
    std::vector<float> vec;
public:
    Vector(const std::vector<float> &initvec){
        vec.resize(initvec.size());
        for(float item:initvec) vec.push_back(item);
    }
    int size()const{
        return vec.size();
    }
    float get(int i)const{
        return vec[i];
    }
    void print(){
        for(float item:vec) printf("%f ",item);
        puts("");
    }
};
float getVectorDis(const Vector &a,const Vector &b){
    float ans=0;
    for(int i=0;i<a.size();i++){
        float temp=a.get(i)-b.get(i);
        ans+=temp*temp;
    }
    return ans;
}
#endif