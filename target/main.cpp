#include <retrival/retrival.h>
#include <common/Vector.h>
#include <cstdio>
#include <vector>
int main(){

    Retriever testRetriever;
    testRetrivever.init();

    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    int q,d;
    scanf("%d%d",&q,&d);
    for(int i=1;i<=q;i++){
        int opt;
        scanf("%d",&opt);
        std::vector<float> ve;
        ve.resize(d);
        for(int i=0;i<d;i++) scanf("%f",&ve[i]);
        Vector vec(ve);
        if(opt==0) testRetrivever.insert(vec);
        else{
            std::vector<Vector> res=testRetrivever.query(vec);
            for(auto item:res) item.print();
        }
    }

    return 0;
}