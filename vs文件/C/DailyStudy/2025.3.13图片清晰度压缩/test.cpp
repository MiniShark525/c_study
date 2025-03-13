#define _CRT_SECURE_NO_WARNINGS 1

typedef unsigned char uint8;

#define MT9V03X_W               (188)//(188)                                           // ͼ����     ��Χ [1-752]
#define MT9V03X_H               (188)//(120)                                           // ͼ��߶�     ��Χ [1-480]

#define BLOCK_SIZE 2    //����ͼƬ�ֱ��ʳ̶�
#define NEW_WIDTH (MT9V03X_W / BLOCK_SIZE)  //ѹ����ͼ����
#define NEW_HEIGHT (MT9V03X_H / BLOCK_SIZE) //ѹ����ͼ��߶�

uint8 image_threshold = 0;  //ͼ����ֵ
uint8 bin_image[NEW_HEIGHT][NEW_WIDTH];//��ֵ�������ͼ������
uint8  new_image[NEW_HEIGHT][NEW_WIDTH];//ѹ�����ͼƬ��������
uint8  mt9v03x_image[MT9V03X_H][MT9V03X_W];    // ����4�ֽڶ���

/*!
 *  @brief  �ֿ鴦�����ͷֱ���
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
            new_image[y][x] = block_sum / block_count;  // ȡ�������ص�ƽ��ֵ��Ϊ������ֵ
        }
    }
}