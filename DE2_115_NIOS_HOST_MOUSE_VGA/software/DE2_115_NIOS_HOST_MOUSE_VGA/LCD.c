#include <unistd.h>
#include <string.h>
#include <io.h>
#include "system.h"
#include "LCD.h"
//-------------------------------------------------------------------------
void LCD_Init()
{
  lcd_write_cmd(LCD_BASE,0x38); 
  usleep(2000);
  lcd_write_cmd(LCD_BASE,0x0C);
  usleep(2000);
  lcd_write_cmd(LCD_BASE,0x01);
  usleep(2000);
  lcd_write_cmd(LCD_BASE,0x06);
  usleep(2000);
  lcd_write_cmd(LCD_BASE,0x80);
  usleep(2000);
}
//-------------------------------------------------------------------------
void LCD_Show_Text(char* Text)
{
  int i;
  for(i=0;i<strlen(Text);i++)
  {
    lcd_write_data(LCD_BASE,Text[i]);
    usleep(2000);
  }
}
//-------------------------------------------------------------------------
void LCD_Line2()
{
  lcd_write_cmd(LCD_BASE,0xC0);
  usleep(2000);
}
//-------------------------------------------------------------------------
void LCD_print(char* Text1, char* Text2)
{
  //  Initial LCD
  LCD_Init();
  //  Show Text to LCD
  LCD_Show_Text("Coord. X: ");
  LCD_Show_Text(Text1);
  //  Change Line2
  LCD_Line2();
  //  Show Text to LCD
  LCD_Show_Text("Coord. Y: ");
  LCD_Show_Text(Text2);
}
//-------------------------------------------------------------------------
