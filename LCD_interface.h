#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

enum LCDMode_t {LCD_MODE_8_BIT, LCD_MODE_4_BIT};

enum LCDCursorMode_t {LCD_CURSOR_ON_BLINK_ON,LCD_CURSOR_ON_BLINK_OFF,
LCD_CURSOR_OFF_BLINK_ON,
LCD_CURSOR_OFF_BLINK_OFF};

typedef struct{
	enum LCDMode_t Mode;
	u8 Size[2];		//rows then columns
	u8 ControlPins[3];
	enum GPIOPortID_t ControlPorts[3];
	u8 *DataPins;
	enum GPIOPortID_t* DataPorts;
	
}LCD_t;



void HLCD_voidInit(LCD_t* LCD);


void HLCD_voidWriteChar(LCD_t* LCD,char c);


void HLCD_voidWriteString(LCD_t* LCD, char* string);


void HLCD_voidWriteArray(LCD_t* LCD, u8* Array, u8 Len);


void HLCD_voidWriteNumber(LCD_t* LCD, s32 Number, u8 Basis);


void HLCD_voidSetPosition(LCD_t* LCD,u8 x_position, u8 y_position);


void HLCD_voidClearScreen(LCD_t* LCD);

//sends the cursor to the beginning
void HLCD_voidGoHome(LCD_t* LCD);

//Sets the Cursor Mode
void HLCD_voidSetCursorMode(LCD_t* LCD, enum LCDCursorMode_t CursorMode);

void HLCD_voidRotateDisplayRight(LCD_t* LCD);

void HLCD_voidRotateDisplayLeft(LCD_t* LCD);

#endif

