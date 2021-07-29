#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "ir.h"
#include "key.h"
#include "lcd.h"
#include "gui.h"

u8 Rece[20]={128,64,192,32,160,96,224,16,144,80,208,48,176,112,240,8,136,72,200,40};

int main(void)
{ 
	u8 key=0,flag=0;
	int array[20];
	u8 i=0,k=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2	  
	LED_Init();//初始化
	KEY_Init();//IO初始化
	delay_init();	
	LCD_Init();	 	  
	uart_init(9600);	 	//串口初始化为9600
	TIM3_2PWM_Init(1893,0);//38kHZ载波	
	ir_re_init();
	printf("收到");
	LCD_Clear(BLACK);    //清屏
	gui_circle(128/2,128/2,WHITE,128/2-2, 0); //画圆
	gui_circle(128/2,128/2,WHITE,128/2-3, 0);//画圆

	Gui_StrCenter(0,10,BLUE,YELLOW,"Mcudev",16,1);//居中显示
	Gui_StrCenter(0,28,RED,BLUE,"Temp:32℃",16,1);//居中显示
	Gui_StrCenter(0,46,YELLOW,BLUE,"Hum:20%",16,1);//居中显示
	Gui_StrCenter(0,64,WHITE,BLUE,"VOL:3.2V",16,1);//居中显示
	Gui_StrCenter(0,82,GREEN,BLUE,"I:1.25mA",16,1);//居中显示
	Gui_StrCenter(0,100,RED,BLUE,"12:20AM",16,1);//居中显示
	delay_ms(2000);
	LCD_Clear(BLACK);
  	while(1) 
	{	
		i++;
		if(i==60)
		{
			i=0;
			k=k+1;
			LCD_Clear(BLACK);
		}
//		LCD_ShowString(0,0,16,"Pant:",1);
//		LCD_ShowNum(40,0,k,3,16);
		key=Remote_Scan();		
//		LCD_ShowString(0,0,16,"KeyValue:",1);
//		LCD_ShowNum(72,0,key,3,16);
		LCD_ShowString(0,16,16,"Receive:",1);
		if(key)
		{
			switch(key)
			{
				case 128: 
					flag=1;
					LCD_ShowNum(64,16,flag,2,16);
					key=array[0];
					LCD_ShowString(0,32,16,"This Car Pass",1);
					break;
				case 64: 
					flag=2;
					LCD_ShowNum(64,16,flag,2,16);
					key=array[1];
					LCD_ShowString(0,32,16,"This Car Pass",1);
					break;
				case 192: 
					flag=3;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[2]=192;	
						LCD_ShowNum(97,16,array[2],3,16);						
					}					
					if(array[2]==Rece[2])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;
				case 32: 
					flag=4;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[3]=32;
					}
					if(array[3]==Rece[3])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 160: 
					flag=5;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[4]=160;
					}
					if(array[4]==Rece[4])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 96: 
					flag=6;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[5]=96;
					}
					if(array[5]==Rece[5])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 224: 
					flag=7;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[6]=224;
					}
					if(array[6]==Rece[6])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 16: 
					flag=8;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[7]=16;
					}
					if(array[7]==Rece[7])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;
				case 144: 
					flag=9;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[8]=114;
					}
					if(array[8]==Rece[8])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 80: 
					flag=10;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[9]=80;
					}
					if(array[9]==Rece[9])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;
				case 208: 
					flag=11;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[10]=108;
					}
					if(array[10]==Rece[10])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;					
				case 48: 
					flag=12;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[11]=48;
					}
					if(array[11]==Rece[11])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;		
				case 176: 
					flag=13;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[12]=176;
					}
					if(array[12]==Rece[12])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;			
				case 122: 
					flag=14;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[13]=122;
					}
					if(array[13]==Rece[13])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;				
				case 240: 
					flag=15;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[14]=240;
					}
					if(array[15]==Rece[15])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;				
				case 8: 
					flag=16;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[15]=8;
					}
					if(array[15]==Rece[15])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 136: 
					flag=17;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[16]=136;
					}
					if(array[16]==Rece[16])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;	
				case 72: 
					flag=18;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[17]=72;
					}
					if(array[17]==Rece[17])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;				
				case 200: 
					flag=19;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[18]=200;
					}
					if(array[18]==Rece[18])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;			
				case 40: 
					flag=20;
					LCD_ShowNum(64,16,flag,2,16);
					if(WK_UP==1)
					{
						array[19]=40;
					}
					if(array[19]==Rece[19])
					{
						LCD_ShowString(0,32,16,"This Car Pass",1);
					}break;						
			}
		}
	} 
}


