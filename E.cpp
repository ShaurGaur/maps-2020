#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n;
    double og, prev;
    double start, end, tax;
    
    scanf("%d\n", &n);
    int answers[n];

    for (int i = 0; i < n; i++) {
        int count = 1;
        scanf("%lf %lf %lf", &start, &end, &tax);
        double factor = 1 + tax/100;
        
        int cycle = (int) (factor * 10000);
        int counts = (int) ((end - start) * 10000);
        int nc = counts / cycle;
        int left = (counts % cycle) / 100;
        // printf("counts: %d cycle: %d\n", counts, cycle);
        // printf("nc: %d left: %d\n\n", nc, left);
        double ans = nc * tax;
        answers[i] = (int) ans;

        double j = start;
        for (int k = 0; k <= left; k++) {
            double og = j / factor;
            // printf("%d) %.2lf %lf ", count, j, og);
            
            og = round((og) * 100) / 100;
            // printf("%.2lf ", og);

            if (j != start && og - prev == 0){ 
                // printf("oof: %lf - %lf = %lf", og, prev, og - prev);
                answers[i]++;
            }
            prev = og;
            count++;
            // printf("\n");
            j += 0.01;
        }
    }

    for (int a: answers) printf("%d\n", a);
    return 0;
}