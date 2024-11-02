#ifndef H_SCANRETRIVAL
#define H_SCANRETRIVAL
#include <basicRetrival.h>
#include <vector>
class ScanRetrival:BasicRetrival{
private:
public:
    void init();
    void merge(const std::vector<Vector> &vec);
    void merge(const Vector &vec);
    std::vector<Vector> query(const Vector &ve,int k);
};

#endif