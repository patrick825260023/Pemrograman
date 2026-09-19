#include <stdio.h>

int main() {
    int n1 = 1, n2 = 1, next;
    
    printf("1. %d %d ", n1, n2);
    
    // Outer loop 
    next = n1 + n2;
    while (next <= 21) {
        printf("%d ", next);
        n1 = n2;
        n2 = next;
        next = n1 + n2;
    }
    printf("\n");
    
    return 0;
}



#include <stdio.h>

int main() {
    printf("2.\n");
    char huruf = 'A';
    int total_baris = 4;

    // Outer loop 
    for (int i = 1; i <= total_baris; i++) {
        
        // Inner loop 1
        for (int j = i; j < total_baris; j++) {
            printf("  "); 
        }
        
        // Inner loop 2
        for (int k = 1; k <= i; k++) {
            printf("%c ", huruf);
            huruf++; 
        }
        
        
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

int main() {
    printf("3.\n");
    int n = 5;

    // Outer loop 
    for (int i = n; i >= 1; i -= 2) {
        
        // Inner loop 1
        for (int j = 0; j < (n - i) / 2; j++) {
            printf("  ");
        }
        
        // Inner loop 2
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        
        printf("\n");
    }

    
    // Outer loop 
    for (int i = 3; i <= n; i += 2) {
        
        // Inner loop 1
        for (int j = 0; j < (n - i) / 2; j++) {
            printf("  ");
        }
        
        // Inner loop 2
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        
        printf("\n");
    }

    return 0;
}



#include <stdio.h>

int main() {
    printf("4.\n");
    int n = 5;
    int num1 = 7;
    int num2 = 10;
    
    int inc1 = 8;         

    // Outer loop 
    for (int i = 1; i <= n; i++) {
        
        // Inner loop 
        for (int j = 1; j <= (n - i + 1); j++) {
            printf("*");
        }
        
      
        printf(" %d %d\n", num1, num2);
        
      
        num1 += inc1;     
        
        if (i == 1) inc1 += 4;      
        else if (i == 2) inc1 += 3; 
        else if (i == 3) inc1 += 2; 
        
       
        if (i == 1) num2 += 8;      
        else if (i == 2) num2 += 6; 
        else if (i == 3) num2 += 4; 
        else if (i == 4) num2 += 2; 
    }

    return 0;
}



#include <stdio.h>

int main() {
    printf("5.\n");
    int total_baris = 5;

    // Outer loop
    for (int i = 0; i < total_baris; i++) {
        
        // Inner Loop 
        for (int j = 0; j < (total_baris - i - 1); j++) {
            printf("  "); 
        }

        int angka = 1; 

        // Inner Loop Angka
        for (int j = 0; j <= i; j++) {
            printf("%4d", angka); 
            
           
            angka = angka * (i - j) / (j + 1);
        }
        
        
        printf("\n");
    }

    return 0;
}