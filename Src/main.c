#include "gpio.h"
#include "stm32f1xx.h"
#include "sharp96.h"
#include "rcc_config.h"
#include "tim.h"
#include "spi.h"
#include "test_img.h"

#define TEST	1
uint8_t data[LCD_BUF_SIZE];

int main(void){
	SysClockConfig();

	SPI1_pin_init();
	SPI1_master_config();
	SPI1_enable();
	Timer2Config();

	LCD_init();
	GPIO_Pin_Configure(LED, OUTPUT_10MHZ, OUTPUT_GP_OD);
	LCD_enable();


	if(TEST){
		for (int i = 0; i < LCD_BUF_SIZE; i++){
			data[i] = 0xff;
		}
		char str[] = "HELLO PIF";
		LCD_get_string(3, 7, data, str);
		LCD_send_image(data);
		LCD_display();
		Delay_ms(1000);
		LCD_send_image(stitch);
	}

	while(1){
		GPIO_toogle_out_pin(LED);
		LCD_display();
		Delay_ms(500);

	}


}
