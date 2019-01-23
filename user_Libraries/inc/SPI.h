#ifndef SPI_H
#define SPI_H

#define RS_1	GPIO_SetBits(GPIOB, GPIO_Pin_14)   
#define RS_0	GPIO_ResetBits(GPIOB, GPIO_Pin_14) 
#define CE_1	GPIO_SetBits(GPIOC, GPIO_Pin_6)  
#define CE_0	GPIO_ResetBits(GPIOC, GPIO_Pin_6) 

void SPI_Configuration(void);
void WriteControlRegister(char c);

#endif
