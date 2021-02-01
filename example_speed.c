#include <stdio.h>
#include "../common/stm32wrapper.h"

extern int power(int x, int e);

int main(void)
{
 
  unsigned int oldcount, newcount;

  clock_setup(CLOCK_BENCHMARK);
  gpio_setup();
  usart_setup(115200);

  SCS_DEMCR |= SCS_DEMCR_TRCENA;
  DWT_CYCCNT = 0;
  DWT_CTRL |= DWT_CTRL_CYCCNTENA;

  send_USART_str((unsigned char*)"\n============ IGNORE OUTPUT BEFORE THIS LINE ============\n");
  
  oldcount = DWT_CYCCNT;
    int a = power(3, 5); 
  newcount = DWT_CYCCNT-oldcount;

  unsigned char output[32];
  sprintf((char *)output, "Cost: %d", newcount);
  send_USART_str(output);

  while(1);
  
  return 0;
}
