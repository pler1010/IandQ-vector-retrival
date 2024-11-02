#ifndef H_BASICRETRIVAL
#define H_BASICRETRIVAL

#include <./../common/Vector.h>
#include <vector>

class BasicRetrival{
protected:
    std::vector<Vector> vecs;
public:
    BasicRetrival(){}
    virtual void init()=0;
    virtual void merge(const Vector &vec)=0;
    virtual void merge(const std::vector<Vector> &vec)=0;
    virtual std::vector<Vector> query(const Vector &ve,int k)=0;
    int size(){
        return vecs.size();
    }
    std::vector<Vector> getVecs(){
        return vecs;
    }
};

#endif