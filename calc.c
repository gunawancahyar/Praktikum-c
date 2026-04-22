#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    double a, b, r;
    char input[50];
    char op;

    while (1) {
        printf("Masukkan (contoh: 3 + 4 atau q untuk keluar): ");

        fgets(input, sizeof(input), stdin);

        //  kontrol input
        if (input[0] == 'q') {
            break;
        }

        //  proses
        if (sscanf(input, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("Format salah\n");
            continue;
        }

        switch(op) {
            case '+': r = a + b; break;
            case '-': r = a - b; break;
            case '*': r = a * b; break;
            case '/': 
                if (b == 0) {
                    printf("Error: pembagian nol\n");
                    continue;
                }
                r = a / b; 
                break;
            case '^': r = pow(a, b); break; // pangkat
            default:
                printf("Operator salah\n");
                continue;
        }

        printf("%.2lf %c %.2lf = %.2lf\n", a, op, b, r);
    }

    return 0;
}