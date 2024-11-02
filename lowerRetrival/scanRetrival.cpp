#include <./../common/Vector.h>
#include <scanRetrival.h>
#include <queue>

ScanRetrival::ScanRetrival(){}

void ScanRetrival::init(){
    vecs.clear();
}
void ScanRetrival::merge(const std::vector<Vector> &vec){
    for(auto item:vec) vecs.push_back(item);
}
void ScanRetrival::merge(const Vector &vec){
    vecs.push_back(vec);
}
std::vector<Vector> ScanRetrival::query(const Vector &vec,int k){
    std::priority_queue<std::pair<float,Vector> > qu;
    for(auto item:vecs) qu.push(std::make_pair(-getVectorDis(item,vec),item));
    std::vector<Vector> res;
    while(!qu.empty()&&res.size()<k){
        Vector item=qu.top().second;
        res.push_back(item);
    }
    return res;
}