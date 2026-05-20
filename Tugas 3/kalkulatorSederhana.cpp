#include <stdio.h>

double tambah(double a, double b) { 
	return a + b; 
}

double kurang(double a, double b) { 
	return a - b; 
}

double kali(double a, double b)   { 
	return a * b; 
}

double bagi(double a, double b)   { 
	return a / b; 
}

double modulo(double a, double b) { 
	return (double)((long long)a % (long long)b); 
}

double operasi(double a, char op, double b) {
    switch (op) {
        case '+': return tambah(a, b);
        case '-': return kurang(a, b);
        case '*': return kali(a, b);
        case '/': return bagi(a, b);
        case '%': return modulo(a, b);
    }
    return 0;
}

int main() {
    double num1, num2, result;
    char op;

    printf("\n  KALKULATOR\n");
    printf("  Operasi (+ - * / %%)\n");
    
    while (1) {
        printf("  Ketik huruf apa saja (contoh: q) untuk keluar\n");
        printf("--------------------------\n\n");
        
        printf("  Angka pertama : ");
        if (scanf("%lf", &num1) != 1) {
            printf("\n  Sampai jumpa!\n\n");
            break;
        }

        printf("  Operasi       : ");
        scanf(" %c", &op);

        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%') {
            printf("  Operasi tidak valid.\n\n");
            continue;
        }
        
        printf("  Angka kedua   : ");
        if (scanf("%lf", &num2) != 1) {
            printf("\n  Bukan angka valid. Keluar.\n\n");
            break;
        }

        if ((op == '/' && num2 == 0) || (op == '%' && (long long)num2 == 0)) {
            printf("\n  ERROR: Tidak bisa bagi atau modulo dengan nol\n\n");
            continue;
        }

        result = operasi(num1, op, num2);
        
        printf("\n  Hasil : %g %c %g = %g\n\n", num1, op, num2, result);
    }

    return 0;
}