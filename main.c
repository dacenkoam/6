#include <stdio.h>
#include <graphics.h>				//подключение графической библиотеки
#include <math.h>
#include <locale.h>

void square(int n, int x1, int y1, int x2, int y2){
    double a1,a2,b1,b2;
    if (n>0){
        a1=x1+(x2-x1)/3;
        a2=x1+2*(x2-x1)/3;
        b1=y1+(y2-y1)/3;
        b2=y1+2*(y2-y1)/3;
        rectangle(a1,b1,a2,b2);

        square(n-1,x1,y1,a1,b1);
        square(n-1,a1,y1,a2,b1);
        square(n-1,a2,y1,x2,b1);
        square(n-1,a2,b1,x2,b2);
        square(n-1,a2,b2,x2,y2);
        square(n-1,a1,b2,a2,y2);
        square(n-1,x1,b2,a1,y2);
        square(n-1,x1,b1,a1,b2);

    }





}
int main()
{
    setlocale(LC_ALL,"Rus");
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(728,728);
    initgraph(&gd, &gm,"");			//открытие графического режима

    int  n;
    printf("Введите глубину рекурсии:\n");
    scanf("%d",&n);
    square(n, 0,0,728,728);
    readkey();									//задержка
    closegraph();								//закрытие графики
    return 0;
}
