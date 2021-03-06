/***************************************************************
 * @file       area_circle.c
 * @brief      计算圆的面积
 * @author     奈斯创新
 * @version    
 * @date       2022年6月8日
 **************************************************************/

#include <stdio.h>

#define PI (3.14)

 /***************************************************************
  *  @brief     计算圆的面积
  *  @param     无   
  *  @note      无
  *  @Sample usage:     无 
 **************************************************************/
int main(void)
{
    int r = 3;
    int area = r*r*PI;
    printf("半径为%d的圆面积为%d\r\n",r,area);
    return 0;
}