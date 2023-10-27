/*
 * HexaDecoder_int.h
 *
 *  Created on: Sep 24, 2023
 *      Author: LENOVO
 */

#ifndef HEXADECODER_INT_H_
#define HEXADECODER_INT_H_

#define HEX_DEC_SSG_LEFT   50
#define HEX_DEC_SSG_RIGHT  100


ES_t HexaDecoder_enuInit(void);

ES_t HexaDecoder_enuDisplayNum(u8 Copy_u8Num);

ES_t HexaDecoder_enuEnableSSG(u8 Copy_u8SSGNum);

ES_t HexaDecoder_enuDisableSSG(u8 Copy_u8SSGNum);

ES_t HexaDecoder_enuStopDisplay(void);

#endif /* HEXADECODER_INT_H_ */
