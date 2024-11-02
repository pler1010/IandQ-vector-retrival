#ifndef H_RETRIVAL
#define H_RETRIVAL
#include <../common/Vector.h>
#include <../lowerRetrival/basicRetrival.h>
#include <vector>

class Retriever{
private:
    BasicRetrival *retriever[32];
    long long Pow[32];
public:
    void init();
    void insert(const Vector &vec);
    std::vector<Vector> query(const Vector &vec);
    
};

#endif