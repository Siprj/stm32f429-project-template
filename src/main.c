#include <stdint.h>
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include "lcd_log.h"


int main()
{
    return 0;
}

void assert_failed(uint8_t* file, uint32_t line)
{
    LCD_Init();

    /* LCD Layer initialization */
    LCD_LayerInit();

    /* Enable the LTDC */
    LTDC_Cmd(ENABLE);

    /* Set LCD foreground layer */
    LCD_SetLayer(LCD_FOREGROUND_LAYER);

    /* Clear the LCD */
    LCD_Clear(LCD_COLOR_WHITE);

    LCD_LOG_Init();
    LCD_LOG_SetHeader((uint8_t*)"header");
    LCD_LOG_SetFooter((uint8_t*)"footer");

    LCD_ErrLog("%s: %d\n", file, (int)line);
    while(1);
}

