#define _CRT_SECURE_NO_WARNINGS 1

#define row 60//像素行数
#define col 80//像素列数
#define Width 30//山峰宽度阈值

typedef unsigned char uchar;
typedef unsigned int uint;

uchar image[row * col] = { 0 };//图像数据
uchar image1[row][col] = { 0 };//图像二值化临时处理数组1
uchar image2[row][col] = { 0 };//图像二值化临时处理数组2

uint GrayValue[256] = { 0 };//统计灰度值分布
uchar YvZhi = 0;

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i = 0;
    for (i = 0; i < row * col; i++)
    {
        GrayValue[image[i]]++;
    }
    uint H1 = 0;//第一高峰值
    uchar D1 = 0;//第一灰度值
    for (i = 0; i < 256; i++)//遍历数组找到第一高峰
    {
        if (GrayValue[i] > H1)
        {
            H1 = GrayValue[i];
            D1 = i;
        }
    }
    uint H2 = 0;
    uchar D2 = 0;
    int j = 0;
    char FindH2 = 0;//判断是否找到了第二高峰的标志位
    for (i = H1 - 5; i > 0; i -= 5)//从第一高峰值慢慢减小
    {
        for (j = 0; j < 256; j++)
        {
            if (GrayValue[j] > i && abs(j - D1) > Width)//当数量大于i并且灰度值与第一高峰的距离大于宽度阈值时，获取第二高峰
            {
                H2 = i;
                D2 = j;
                FindH2 = 1;
                break;
            }
        }
        if (FindH2)
            break;
    }
    uint H3 = row * col;
    uchar D3 = 0;
    if (FindH2)//找到两个山峰后
    {

        if (D1 < D2)
        {
            for (i = D1; i < D2; i++)//在山峰之间找山谷
            {
                if (GrayValue[i] < H3)
                {
                    H3 = GrayValue[i];//记录山谷海拔
                    D3 = i;//记录山谷灰度值
                }
            }
        }
        else
        {
            for (i = D2; i < D1; i++)//找山谷
            {
                if (GrayValue[i] < H3)
                {
                    H3 = GrayValue[i];
                    D3 = i;
                }
            }

        }
    }
    YvZhi = D3;
    /****************************图像二值化******************************/
    for (i = 0; i < 4800; i++)
    {
        if (image[i] > YvZhi)//判断灰度值
        {
            image1[i / 80][i % 80] = 0;//白点
        }
        else
        {
            image1[i / 80][i % 80] = 1;//黑点
        }
    }
    /****************************找中线*********************************/
    uchar MLine[61] = { 39 };//中线，第61位存初始值
    uchar LLine[60] = { 0 };//左线
    uchar RLine[60] = { 79 };//右线
    //求中心线
    for (j = 59; j >= 0; j--)
    {
        for (i = MLine[j + 1]; i > 0; i--)//找左线
        {
            if (image1[j][i - 1] - image1[j][i] == 1)
            {
                LLine[j] = i;
            }
        }
        for (i = MLine[j + 1]; i < 79; i++)//找右线
        {
            if (image1[j][i + 1] - image1[j][i] == 1)
            {
                RLine[j] = i;
            }
        }
        MLine[j] = (LLine[j] + RLine[j]) / 2;//找到最底下中点
    }
    /**************************求车身横向偏差******************************/
    uchar Prospect = 15;


	return 0;
}