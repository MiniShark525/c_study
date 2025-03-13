#define _CRT_SECURE_NO_WARNINGS 1

#define row 60//��������
#define col 80//��������
#define Width 30//ɽ������ֵ

typedef unsigned char uchar;
typedef unsigned int uint;

uchar image[row * col] = { 0 };//ͼ������
uchar image1[row][col] = { 0 };//ͼ���ֵ����ʱ��������1
uchar image2[row][col] = { 0 };//ͼ���ֵ����ʱ��������2

uint GrayValue[256] = { 0 };//ͳ�ƻҶ�ֵ�ֲ�
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
    uint H1 = 0;//��һ�߷�ֵ
    uchar D1 = 0;//��һ�Ҷ�ֵ
    for (i = 0; i < 256; i++)//���������ҵ���һ�߷�
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
    char FindH2 = 0;//�ж��Ƿ��ҵ��˵ڶ��߷�ı�־λ
    for (i = H1 - 5; i > 0; i -= 5)//�ӵ�һ�߷�ֵ������С
    {
        for (j = 0; j < 256; j++)
        {
            if (GrayValue[j] > i && abs(j - D1) > Width)//����������i���һҶ�ֵ���һ�߷�ľ�����ڿ����ֵʱ����ȡ�ڶ��߷�
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
    if (FindH2)//�ҵ�����ɽ���
    {

        if (D1 < D2)
        {
            for (i = D1; i < D2; i++)//��ɽ��֮����ɽ��
            {
                if (GrayValue[i] < H3)
                {
                    H3 = GrayValue[i];//��¼ɽ�Ⱥ���
                    D3 = i;//��¼ɽ�ȻҶ�ֵ
                }
            }
        }
        else
        {
            for (i = D2; i < D1; i++)//��ɽ��
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
    /****************************ͼ���ֵ��******************************/
    for (i = 0; i < 4800; i++)
    {
        if (image[i] > YvZhi)//�жϻҶ�ֵ
        {
            image1[i / 80][i % 80] = 0;//�׵�
        }
        else
        {
            image1[i / 80][i % 80] = 1;//�ڵ�
        }
    }
    /****************************������*********************************/
    uchar MLine[61] = { 39 };//���ߣ���61λ���ʼֵ
    uchar LLine[60] = { 0 };//����
    uchar RLine[60] = { 79 };//����
    //��������
    for (j = 59; j >= 0; j--)
    {
        for (i = MLine[j + 1]; i > 0; i--)//������
        {
            if (image1[j][i - 1] - image1[j][i] == 1)
            {
                LLine[j] = i;
            }
        }
        for (i = MLine[j + 1]; i < 79; i++)//������
        {
            if (image1[j][i + 1] - image1[j][i] == 1)
            {
                RLine[j] = i;
            }
        }
        MLine[j] = (LLine[j] + RLine[j]) / 2;//�ҵ�������е�
    }
    /**************************�������ƫ��******************************/
    uchar Prospect = 15;


	return 0;
}