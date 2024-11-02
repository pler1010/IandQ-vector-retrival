#include <basicRetrival.h>

BasicRetrival::BasicRetrival(){}
int BasicRetrival::size(){
    return vecs.size();
}
std::vector<Vector> BasicRetrival::getVecs(){
    return vecs;
}