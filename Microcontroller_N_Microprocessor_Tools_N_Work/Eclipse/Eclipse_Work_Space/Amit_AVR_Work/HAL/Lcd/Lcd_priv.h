/*
 * Lcd_priv.h
 *
 *  Created on: Sep 27, 2023
 *      Author: LENOVO
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_

#define FOUR_BIT     40
#define EIGHT_BIT    80

#define LCD_WRITENLATCH_ERROR_STATE_COND       10
#define LCD_SEND_STRING_ERROR_STATE_COND       2

#define LCD_MAX_PATTERN_NUM  8

#define LCD_MIN_NUM_ROWS   1
#define LCD_MIN_NUM_COLS   1

#define LCD_MAX_NUM_ROWS   2
#define LCD_MAX_NUM_COLS   16

#define LCD_BIT_MASK   1

#define LCD_BYTE_7     7
#define LCD_BYTE_6     6
#define LCD_BYTE_5     5
#define LCD_BYTE_4     4
#define LCD_BYTE_3     3
#define LCD_BYTE_2     2
#define LCD_BYTE_1     1
#define LCD_BYTE_0     0

#define LCD_DISPLAY_RIGHT           0X04
#define LCD_DISPLAY_LEFT            0X06

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

#define LCD_ROW_1_COL_1_BASE_ADDRESS  0X80
#define LCD_NUM_TO_ROW_2_COL_1_SHIFT  0X40

#define LCD_NUM_OF_BYTES_PER_CHART    8

static ES_t enuWriteNLatch(u8 Copy_u8Byte);

static ES_t enuIntToString(s32 Copy_s32Num, char* Copy_pcIntNumString);

static ES_t enuDisplayNum(s32 Copy_s32Num);

#endif /* HAL_LCD_LCD_PRIV_H_ */
