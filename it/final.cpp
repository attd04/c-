//
//  main.cpp
//  it exam
//
//  Created by Autumn Tiede on 1/17/23.

#include <iostream>
#include <math.h>

int main()
{
    printf("f(x) = f(x-1) + ceil(x^3 / b), x ∈ N = {1,2,... + ∞}\n");
    
    int b = 5, f0 = 10, c = 0, x, rez, rez1, result;
    

    
    std::cout << "\nEnter a value for x: ";
    std::cin >> x;
    
    int xx = (x-1);
    
    __asm {
        // part 1
        mov eax, x;
        add eax, 1
        imul eax, eax;
        imul eax, x;
        cdq;
        idiv b;
        mov rez, eax;
        
        // f(x-1)
        mov eax, x;
        sub eax, 1;
        imul eax, eax;
        imul eax, xx;
        idiv b;
        mov rez1, eax;
        
        
    
       
    }
    rez = float(rez);
    rez = ceil(double(rez));
    rez1 = float(rez1);
    rez1 = ceil(double(rez1));
    
    
    
    printf("%d\n", rez);
    printf("%d\n", rez1);
    
    result = ceil(double(rez + rez1));

    
    printf("-------------------------------------------\n");
    printf("Results of the calculations:\n");
    printf("The recurrent function is; f(x) = f(x-1) + ceil(x^3 / b), x ∈ N = {1,2,... + ∞}, \nwhere b = 5, and f(0) = 10 \n");
    printf("The entered value: x = %d\n",x);
    printf("The calculated value of the function f: f(x) = %d\n", result);
    printf("-------------------------------------------\n");
    
    
}
