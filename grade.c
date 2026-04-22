#include <stdio.h>

int main() {
    FILE *fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("File tidak ditemukan\n");
        return 1;
    }

    char nama[100];
    double tugas, uts, uas, akhir;
    char grade;

    int count = 0;
    double total = 0;

    int countA=0, countB=0, countC=0, countD=0, countE=0;

    // skip header
    fscanf(fp, "%*[^\\n]\n");

    while (fscanf(fp, "%[^,],%lf,%lf,%lf\n", nama, &tugas, &uts, &uas) == 4) {

        akhir = 0.3*tugas + 0.3*uts + 0.4*uas;
        total += akhir;
        count++;

        if (akhir >= 85) { grade='A'; countA++; }
        else if (akhir >= 70) { grade='B'; countB++; }
        else if (akhir >= 55) { grade='C'; countC++; }
        else if (akhir >= 40) { grade='D'; countD++; }
        else { grade='E'; countE++; }

        printf("%s => %.2f (%c)\n", nama, akhir, grade);
    }

    printf("\n=== SUMMARY ===\n");
    printf("Rata-rata: %.2f\n", total/count);
    printf("A: %d\nB: %d\nC: %d\nD: %d\nE: %d\n",
           countA, countB, countC, countD, countE);

    fclose(fp);
    return 0;
}