
#include <../lowerRetrival/scanRetrival.h>
#include <retrival.h>
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
std::vector<Vector> Retriever::query(const Vector &vec){}