#include <stdio.h>

int main(void)
{
    int a[10][11] = { 0, };
    int i = 0, j = 0;
    int addr_ij = 0, addr_00 = 0;//a[i][j] 주소와 a[0][0] 주소 저장 변수
    int repeat = 1; //반복을 위한 변수
    int order = 0; //a[i][j]가 몇 번째 값인지 저장하는 변수

    printf("행 i와 열 j의 값을 입력하세요. (범위 : 0<=i<=9, 0<=j<=10)\n");
    scanf_s("%d %d", &i, &j);

    while (repeat) { //범위 밖의 값을 입력했을 때 다시 입력
        if (i >= 10 || i < 0 || j >= 11 || j < 0) {
            if (i >= 10 || i < 0) { //행 값을 범위 밖의 값으로 입력했을 때
                printf("행 값 i를 0<=i<=9 범위에서 다시 입력하세요.");
                scanf_s("%d", &i);
            }
            else if (j >= 11 || j < 0) { //열 값을 범위 밖의 값으로 입력했을 때
                printf("열 값 j를 0<=j<=10 범위에서 다시 입력하세요.");
                scanf_s("%d", &j);
            }
        }
        else repeat = 0; //범위 내의 값 입력 시 반복 종료
    }

    addr_ij = &a[i][j];
    addr_00 = &a[0][0];

    order = (addr_ij - addr_00) / sizeof(a[0][0]) + 1;
    printf("a[%d][%d]는 %d 번째 원소입니다.", i, j, order);

    return 0;
}