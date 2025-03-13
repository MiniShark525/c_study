#define _CRT_SECURE_NO_WARNINGS 1

typedef unsigned char uint8;
typedef unsigned short uint16;

#include <math.h>

//------------------摄像头参数--------------//
uint8 dis_image[60][80];

uint8 image_threshold = 46;  //图像阈值

//0x4D;0x18-0x1A;
uint8 otsuThreshold(uint8* image, uint16 col, uint16 row)
{
#define GrayScale 256//定义256个灰度级
    uint16 width = col;   //图像宽度
    uint16 height = row;  //图像长度
    int pixelCount[GrayScale] = {0};  //每个灰度值所占像素个数
    float pixelPro[GrayScale] = {0}; //每个灰度值所占总像素比例
    int i, j;
    int sumPixel = width * height;//总像素点
    uint8 threshold = 0; //最佳阈值
    uint8* data = image;  //指向像素数据的指针

    //统计灰度级中每个像素在整幅图像中的个数  
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixelCount[(int)data[i * width + j]]++;  //将像素值作为计数数组的下标
            //   pixelCount[(int)image[i][j]]++;    若不用指针用这个
        }
    }

    //遍历灰度级[0,255]  
    float w0 = 0, w1 = 0, u0Sum = 0, u1Sum = 0, u0 = 0, u1 = 0, u = 0, variance = 0, maxVariance = 0;
    //目标像素占总图像比例w0
    //背景像素占总图像比例w1 
    //目标平均灰度值u0 
    //背景平均灰度值u1
    //总平均灰度值u
    //类间方差 variance
    //最大类间方差 maxVariance

//计算每个像素在整幅图像中的比例  
    for (i = 0; i < GrayScale; i++)
    {
        pixelPro[i] = (float)pixelCount[i] / sumPixel;
        u += i * pixelPro[i];  //总平均灰度
    }

    for (i = 0; i < GrayScale; i++)     // i作为阈值 阈值从1-255遍历 
    {

        for (j = 0; j < GrayScale; j++)    //求目标前景和背景
        {
            if (j <= i)   //前景部分    
            {
                w0 += pixelPro[j];
                u0Sum += j * pixelPro[j];
            }
            else   //背景部分  
            {
                w1 += pixelPro[j];
                u1Sum += j * pixelPro[j];
            }
        }
        u0 = u0Sum / w0;
        u1 = u1Sum / w1;

        variance = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);  //类间方差计算公式

        if (variance > maxVariance)   //判断是否为最大类间方差
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
    image_threshold = otsuThreshold(image, 80, 60);  //大津法计算阈值   
    return 0;
}


