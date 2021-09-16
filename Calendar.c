#include <stdio.h>
int dark(int y)
{
    int wow = 0;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        wow = 1;
    }
    return wow;
}
int first(int d, int m, int y)
{
    int branch;
    if (dark(y) == 1)
    {
        switch (m)
        {
        case 1:
            branch = d;
            break;
        case 2:
            branch = 31 + d;
            break;
        case 3:
            branch = 31 + 29 + d;
            break;
        case 4:
            branch = 31 * 2 + 29 + d;
            break;
        case 5:
            branch = 31 * 2 + 30 + 29 + d;
            break;
        case 6:
            branch = 31 * 3 + 30 + 29 + d;
            break;
        case 7:
            branch = 31 * 3 + 30 * 2 + 29 + d;
            break;
        case 8:
            branch = 31 * 4 + 30 * 2 + 29 + d;
            break;
        case 9:
            branch = 31 * 5 + 30 * 2 + 29 + d;
            break;
        case 10:
            branch = 31 * 5 + 30 * 3 + 29 + d;
            break;
        case 11:
            branch = 31 * 6 + 30 * 3 + 29 + d;
            break;
        case 12:
            branch = 366 - (31 - d);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (m)
        {
        case 1:
            branch = d;
            break;
        case 2:
            branch = 31 + d;
            break;
        case 3:
            branch = 31 + 28 + d;
            break;
        case 4:
            branch = 31 * 2 + 28 + d;
            break;
        case 5:
            branch = 31 * 2 + 30 + 28 + d;
            break;
        case 6:
            branch = 31 * 3 + 30 + 28 + d;
            break;
        case 7:
            branch = 31 * 3 + 30 * 2 + 28 + d;
            break;
        case 8:
            branch = 31 * 4 + 30 * 2 + 28 + d;
            break;
        case 9:
            branch = 31 * 5 + 30 * 2 + 28 + d;
            break;
        case 10:
            branch = 31 * 5 + 30 * 3 + 28 + d;
            break;
        case 11:
            branch = 31 * 6 + 30 * 3 + 28 + d;
            break;
        case 12:
            branch = 365 - (31 - d);
        default:
            break;
        }
    }
    return branch;
}
void second()
{
    int d, m, y;
    printf("Nhap ngay:\n");
    scanf("%d", &d);
    printf("Nhap thang:\n");
    scanf("%d", &m);
    printf("Nhap nam:\n");
    scanf("%d", &y);
    if (d <= 0 || m <= 0 || y <= 0 || d > 31 || m > 12)
    {
        printf("Ngay nhap vao khong ton tai!");
    }
}
void main()
{
    int d, m, y;
    int ngay_them;

    second(d, m, y);
    printf("Nhap ngay cong them:\n");
    scanf("%d", &ngay_them);

    int tong = first(d, m, y) + ngay_them;

    for (int i = y;; i++)
    {
        if (dark(i))
        {
            if (tong <= 366)
                break;
            else
            {
                tong -= 366;
                y += 1;
            }
        }
        else
        {
            if (tong <= 365)
                break;
            else
            {
                tong -= 365;
                y += 1;
            }
        }
    }

    for (int i = 1;; i++)
    {
        if ((tong - first(0, i, y)) < 0)
        {
            m = i - 1;
            d = tong - first(0, i - 1, y);
            break;
        }
    }
    printf("%d/%d/%d", d, m, y);
}
