#include <stdio.h>

int main(void)
{
    int a[10][11] = { 0, };
    int i = 0, j = 0;
    int addr_ij = 0, addr_00 = 0;//a[i][j] �ּҿ� a[0][0] �ּ� ���� ����
    int repeat = 1; //�ݺ��� ���� ����
    int order = 0; //a[i][j]�� �� ��° ������ �����ϴ� ����

    printf("�� i�� �� j�� ���� �Է��ϼ���. (���� : 0<=i<=9, 0<=j<=10)\n");
    scanf_s("%d %d", &i, &j);

    while (repeat) { //���� ���� ���� �Է����� �� �ٽ� �Է�
        if (i >= 10 || i < 0 || j >= 11 || j < 0) {
            if (i >= 10 || i < 0) { //�� ���� ���� ���� ������ �Է����� ��
                printf("�� �� i�� 0<=i<=9 �������� �ٽ� �Է��ϼ���.");
                scanf_s("%d", &i);
            }
            else if (j >= 11 || j < 0) { //�� ���� ���� ���� ������ �Է����� ��
                printf("�� �� j�� 0<=j<=10 �������� �ٽ� �Է��ϼ���.");
                scanf_s("%d", &j);
            }
        }
        else repeat = 0; //���� ���� �� �Է� �� �ݺ� ����
    }

    addr_ij = &a[i][j];
    addr_00 = &a[0][0];

    order = (addr_ij - addr_00) / sizeof(a[0][0]) + 1;
    printf("a[%d][%d]�� %d ��° �����Դϴ�.", i, j, order);

    return 0;
}