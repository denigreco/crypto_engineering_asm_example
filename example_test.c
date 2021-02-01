#include <stdio.h>
#include "../common/stm32wrapper.h"

extern int power(int x, int e);

int main(void)
{
  clock_setup(CLOCK_FAST);
  gpio_setup();
  usart_setup(115200);

  send_USART_str((unsigned char*)"\n============ IGNORE OUTPUT BEFORE THIS LINE ============\n");
  
  int a = power(3, 5); 

 
  unsigned char output[32];
  sprintf((char *)output, "Output %d", a);


  send_USART_str((unsigned char*)output);
  
  

  while(1);

  return 0;
}
