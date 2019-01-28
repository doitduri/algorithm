#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int level, len;
    scanf("%d", &level);

    len = 1<<(level+1);
    int *t = new int[len+1];
    int *s = new int[len+1];
    int *p = new int[len+1];

    for(int i=0; i<=len; i++){
        t[i]=0; s[i]=0; p[i]=0;
    }

//    printf("%d\n",len);

    for(int i=2; i<len; i++)
        scanf("%d", &t[i]);

    int left, right ;
    for(int i=1<<level; i>0; i--){
        left = i<<1; right = left+1;
        p[i] = max(p[left]+t[left], p[right]+t[right]);
        s[i] = s[left]+s[right] + (p[i]-p[left]) + (p[i]-p[right]);
    }


    printf("%d", s[1]);
    return 0;
}