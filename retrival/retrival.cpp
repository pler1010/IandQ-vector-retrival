
#include <../common/Vector.h>
#include <../lowerRetrival/scanRetrival.h>
#include <retrival.h>
#include <queue>

#define B 16
void Retriever::init(){
    for(int i=0;i<32;i++){
        retriever[i]=new ScanRetrival();
        retriever[i]->init();
    }
    Pow[0]=B;
    for(int i=1;i<32;i++) Pow[i]=Pow[i-1]*B;
}
void Retriever::insert(const Vector &vec){
    retriever[0]->merge(vec);
    for(int i=0;i<31;i++){
        if(retriever[i]->size()==Pow[i]){
            retriever[i+1]->merge(retriever[i]->getVecs());
            retriever[i]->init();
        }
    }
}
std::vector<Vector> Retriever::query(const Vector &vec,int k){
    std::priority_queue<std::pair<float,Vector> > qu;
    for(int i=0;i<32;i++){
        auto temp=retriever[i]->query(vec,k);
        for(auto item:temp) qu.push(std::make_pair(-getVectorDis(vec,item),item));
    }
    std::vector<Vector> res;
    while(!qu.empty()&&res.size()<k){
        Vector item=qu.top().second;
        qu.pop();
        res.push_back(item);
    }
    return res;
}