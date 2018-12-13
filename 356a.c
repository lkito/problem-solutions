#include <stdio.h>

int main(int argc, char **argv){
    int n, m, l, r, w;
    scanf("%d", &n);
    int mas[n];
    int jump[n];
    for(int i = 0; i < n; i++){
        mas[i] = 0;
        jump[i] = -1;
    }
    scanf("%d", &m);
    while(m > 0){
        scanf("%d%d%d", &l, &r, &w);
        jump[l - 1] = w - 1;
        jump[w - 1] = r;
        for(int k = l - 1; k <= r - 1; k++){
            if(mas[k] == 0 && k != w - 1){
                mas[k] = w;
            }
            if(k != l - 1 && k != w - 1 && jump[k] != -1){
                k = jump[k] - 1;
                continue;
            }
            if(k < w - 1) jump[k] = w - 1;
            if(k > w - 1) jump[k] = jump[w - 1];
        }
        m--;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", mas[i]);
    }
    return 0;
}