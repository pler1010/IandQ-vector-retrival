#include <Vector.h>


Vector::Vector(const std::vector<float> &initvec){
    vec=initvec;
}

int Vector::size()const{
    return vec.size();
}

float Vector::get(int i)const{
    return vec[i];
}

void Vector::print(){
    for(float item:vec) printf("%f ",item);
    puts("");
}

float getVectorDis(const Vector &a,const Vector &b){
    float ans=0;
    for(int i=0;i<a.size();i++){
        float temp=a.get(i)-b.get(i);
        ans+=temp*temp;
    }
    return ans;
}

bool operator < (const Vector &a,const Vector &b){
    for(int i=0;i<a.size();i++){
        if(a.get(i)<b.get(i)) return true;
        if(a.get(i)>b.get(i)) return false;
    }
    return false;
}