// LCD Module connections
sbit LCD_RS at RB7_bit;
sbit LCD_EN at RB6_bit;
sbit LCD_D7 at RB2_bit;
sbit LCD_D6 at RB3_bit;
sbit LCD_D5 at RB4_bit;
sbit LCD_D4 at RB5_bit;
// End LCD module connections
// LCD Pin direction
sbit LCD_RS_Direction at TRISB7_bit;
sbit LCD_EN_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB2_bit;
sbit LCD_D6_Direction at TRISB3_bit;
sbit LCD_D5_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB5_bit;
// End of LCD Pin direction
char pwr[7],volt[7],i[7];
float v,current,power;
void main() {
PORTA=0xFF;
TRISA=1;

TRISB=0;
ADC_Init();
Lcd_Init();// Initialize LCD
Lcd_Cmd(_LCD_CLEAR);// Clear Display
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor Off
Lcd_Out(1,1,"POWER IS");// Write “LCD INTERFACE” in the first row
delay_ms(2000);
        v=ADC_Read(0);
        current=ADC_Read(1);

        v=(v*5)/(1024);
        current=(current*5)/(1024);
        power= current*v;
while(1)
{
        //v=ADC_Read(2);
        //current=ADC_Read(1);
//        v= 3;
  //      current = 2;
        //v=(v*5)/(1020);
        //current=(current*5)/(1020);

        FloatToStr(v , volt);
        FloatToStr(power, pwr);
        FloatToStr(current, i);
        Lcd_Out(2,1,pwr);
        //Lcd_Out(2,5,i);
//        Lcd_Out(2,12,"W");
}
}