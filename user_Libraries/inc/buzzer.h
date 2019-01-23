#ifndef BUZZER_H
#define BUZZER_H

void buzzer_Configuration(void);
void beep(int times);
void shortBeep(int duration, int freq);

extern int buzzerTime;

#define beep_on   TIM3->CCR1 = (TIM3->ARR+1)/8 
#define beep_off  TIM3->CCR1 = 0               
#define setBuzzerFrequency(f) TIM3->ARR=84000000/(f)/140-1 

#endif
