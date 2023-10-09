#include <iostream>
int main()
{
      int a = 10, b = 5, c = 3, x = 32, rez;

      printf("Which input value would you like for x?");

            std::cout << (" Value for x: ");
            std::cin >> x;

      __asm {

            mov eax, x

            cmp eax, 20;
            je equal;
            cmp eax, 20;
            jl smaller;
            cmp eax, 30;
            jg bigger;

            //equal or smaller
            equal:
                  mov eax, b;
                  imul eax, x;
                  mov ebx, a;
                  add eax, ebx;
                  mov rez, eax;
                  jmp exit_one;

            smaller:
                  mov eax, x
                        cdq;
                  idiv c;
                  mov ebx, eax;
                  imul ebx, ebx;
                  imul ebx, eax;
                  mov ecx, a;
                  add ecx, a;
                  mov eax, ecx;
                  jmp exit_one;

            bigger:
                  mov eax, x;
                        mov ebx, c;
                        cdq;
                        div c;
                        imul eax, 2;
                        mov ebx, eax;
                        imul ebx, ebx;
                        imul ebx, eax;
                        mov ecx, a;
                        add ecx, ebx;
                        mov eax, ecx;

                  jmp exit_one;
            exit_one:
                  mov rez, eax;
      }

      printf("%d", rez);
      return 0;
}
