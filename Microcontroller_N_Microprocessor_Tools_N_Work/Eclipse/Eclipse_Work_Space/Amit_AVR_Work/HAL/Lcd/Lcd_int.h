/*
 * Lcd_int.h
 *
 *  Created on: Sep 27, 2023
 *      Author: LENOVO
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define LCD_DISPLAY_RIGHT           0X04
#define LCD_DISPLAY_LEFT            0X06

#define LCD_CLEAR_DISPLAY           0X01
#define LCD_CLEAR_CELL              0X20
#define LCD_CURSOR_OFF              0X0C

#define LCD_PATTERN_0                 0
#define LCD_PATTERN_0_BASE_ADDRESS    0X40

#define LCD_PATTERN_1                 1
#define LCD_PATTERN_1_BASE_ADDRESS    0X48

#define LCD_PATTERN_2                 2
#define LCD_PATTERN_2_BASE_ADDRESS    0X50

#define LCD_PATTERN_3                 3
#define LCD_PATTERN_3_BASE_ADDRESS    0X58

#define LCD_PATTERN_4                 4
#define LCD_PATTERN_4_BASE_ADDRESS    0X60

#define LCD_PATTERN_5                 5
#define LCD_PATTERN_5_BASE_ADDRESS    0X68

#define LCD_PATTERN_6                 6
#define LCD_PATTERN_6_BASE_ADDRESS    0X70

#define LCD_PATTERN_7                 7
#define LCD_PATTERN_7_BASE_ADDRESS    0X78

#define LCD_ROW_1     1
#define LCD_ROW_2     2

#define LCD_COLUMN_1   1
#define LCD_COLUMN_2   2
#define LCD_COLUMN_3   3
#define LCD_COLUMN_4   4
#define LCD_COLUMN_5   5
#define LCD_COLUMN_6   6
#define LCD_COLUMN_7   7
#define LCD_COLUMN_8   8
#define LCD_COLUMN_9   9
#define LCD_COLUMN_10  10
#define LCD_COLUMN_11  11
#define LCD_COLUMN_12  12
#define LCD_COLUMN_13  13
#define LCD_COLUMN_14  14
#define LCD_COLUMN_15  15
#define LCD_COLUMN_16  16


ES_t Lcd_enuInit(void);

ES_t Lcd_enuSendCommand(u8 Copy_u8Command);

ES_t Lcd_enuSendData(u8 Copy_u8Data);

ES_t Lcd_enuSendString(const char * Copy_pcString);

ES_t Lcd_enuSetCursor(u8 Copy_u8RowNum , u8 Copy_u8ColNum);

ES_t Lcd_enuDrawSpecialChar(u8 * Copy_pu8Pattern , u8 Copy_u8PatternNum, u8 Copy_StartPattern , u8 Copy_u8PositionX , u8 Copy_u8PositionY , u8 Copy_u8PrintDirection);

ES_t Lcd_enuWriteIntegarNum(s32 Copy_s32Num);

ES_t Lcd_enuWriteFloatNum(f32 Copy_f32Num);


#endif /* HAL_LCD_LCD_INT_H_ */
