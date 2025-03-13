#define _CRT_SECURE_NO_WARNINGS 1

typedef unsigned char uint8;
typedef unsigned short uint16;

#include <math.h>

//------------------����ͷ����--------------//
uint8 dis_image[60][80];

uint8 image_threshold = 46;  //ͼ����ֵ

//0x4D;0x18-0x1A;
uint8 otsuThreshold(uint8* image, uint16 col, uint16 row)
{
#define GrayScale 256//����256���Ҷȼ�
    uint16 width = col;   //ͼ����
    uint16 height = row;  //ͼ�񳤶�
    int pixelCount[GrayScale] = {0};  //ÿ���Ҷ�ֵ��ռ���ظ���
    float pixelPro[GrayScale] = {0}; //ÿ���Ҷ�ֵ��ռ�����ر���
    int i, j;
    int sumPixel = width * height;//�����ص�
    uint8 threshold = 0; //�����ֵ
    uint8* data = image;  //ָ���������ݵ�ָ��

    //ͳ�ƻҶȼ���ÿ������������ͼ���еĸ���  
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixelCount[(int)data[i * width + j]]++;  //������ֵ��Ϊ����������±�
            //   pixelCount[(int)image[i][j]]++;    ������ָ�������
        }
    }

    //�����Ҷȼ�[0,255]  
    float w0 = 0, w1 = 0, u0Sum = 0, u1Sum = 0, u0 = 0, u1 = 0, u = 0, variance = 0, maxVariance = 0;
    //Ŀ������ռ��ͼ�����w0
    //��������ռ��ͼ�����w1 
    //Ŀ��ƽ���Ҷ�ֵu0 
    //����ƽ���Ҷ�ֵu1
    //��ƽ���Ҷ�ֵu
    //��䷽�� variance
    //�����䷽�� maxVariance

//����ÿ������������ͼ���еı���  
    for (i = 0; i < GrayScale; i++)
    {
        pixelPro[i] = (float)pixelCount[i] / sumPixel;
        u += i * pixelPro[i];  //��ƽ���Ҷ�
    }

    for (i = 0; i < GrayScale; i++)     // i��Ϊ��ֵ ��ֵ��1-255���� 
    {

        for (j = 0; j < GrayScale; j++)    //��Ŀ��ǰ���ͱ���
        {
            if (j <= i)   //ǰ������    
            {
                w0 += pixelPro[j];
                u0Sum += j * pixelPro[j];
            }
            else   //��������  
            {
                w1 += pixelPro[j];
                u1Sum += j * pixelPro[j];
            }
        }
        u0 = u0Sum / w0;
        u1 = u1Sum / w1;

        variance = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);  //��䷽����㹫ʽ

        if (variance > maxVariance)   //�ж��Ƿ�Ϊ�����䷽��
        {
            maxVariance = variance;
            threshold = i;
        }
    }
    return threshold;
}

int main(void)
{
    uint8 image[60 * 80] = {0};
    image_threshold = otsuThreshold(image, 80, 60);  //��򷨼�����ֵ   
    return 0;
}


