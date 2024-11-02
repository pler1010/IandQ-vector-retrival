#ifndef H_RETRIVAL
#define H_RETRIVAL
#include <../common/Vector.h>
#include <vector>

class Retriever{
private:

public:
    void init();
    void insert(Vector vec);
    std::vector<Vector> query(Vector vec);
    
};

#endif