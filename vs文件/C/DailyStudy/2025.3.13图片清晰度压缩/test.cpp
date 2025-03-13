#define _CRT_SECURE_NO_WARNINGS 1

typedef unsigned char uint8;

#define MT9V03X_W               (188)//(188)                                           // 图像宽度     范围 [1-752]
#define MT9V03X_H               (188)//(120)                                           // 图像高度     范围 [1-480]

#define BLOCK_SIZE 2    //降低图片分辨率程度
#define NEW_WIDTH (MT9V03X_W / BLOCK_SIZE)  //压缩后图像宽度
#define NEW_HEIGHT (MT9V03X_H / BLOCK_SIZE) //压缩后图像高度

uint8 image_threshold = 0;  //图像阈值
uint8 bin_image[NEW_HEIGHT][NEW_WIDTH];//二值化处理后图像数据
uint8  new_image[NEW_HEIGHT][NEW_WIDTH];//压缩后的图片数据数组
uint8  mt9v03x_image[MT9V03X_H][MT9V03X_W];    // 必须4字节对齐

/*!
 *  @brief  分块处理并降低分辨率
 */
void block_compress(void)
{
    for (int y = 0; y < NEW_HEIGHT; y++)
    {
        for (int x = 0; x < NEW_WIDTH; x++)
        {
            int block_sum = 0;
            int block_count = 0;
            for (int i = y * BLOCK_SIZE; i < (y + 1) * BLOCK_SIZE; i++)
            {
                for (int j = x * BLOCK_SIZE; j < (x + 1) * BLOCK_SIZE; j++)
                {
                    block_sum += mt9v03x_image[i][j];
                    block_count++;
                }
            }
            new_image[y][x] = block_sum / block_count;  // 取块内像素的平均值作为新像素值
        }
    }
}