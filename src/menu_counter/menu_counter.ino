#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/******************************************
 *        
 *        
 *        I/O definitions PINS
 *        
 *        
 ******************************************/
 
#define DEVICE_NAME_LCD " Flavio Hernan "
#define VERSION_FW "0.1"

#define BT0 PD4
#define BT1 PD5
#define BT2 PD6
#define BT3 PD7

#define PLED1 PB1

#define BUZ PB5


/*************************************************** 
 *                 
 *                 
 *                 FSM
 *                 
 *                 
 ***************************************************/



enum states { S1, S2, MAX_STATES } current_state;
enum events { E1, E2, MAX_EVENTS } new_event;


void out_s1_e1 (void);
void out_s1_e2 (void);
void out_s2_e1 (void);
void out_s2_e2 (void);

enum events get_new_event (void);


void (*const state_table [MAX_STATES][MAX_EVENTS]) (void) = {

    { out_s1_e1, out_s1_e2 }, /* state 1 */
    { out_s2_e1, out_s2_e2 } /* state 2 */
};


void out_s1_e1 (void) {}
void out_s1_e2 (void) {}
void out_s2_e1 (void) {}
void out_s2_e2 (void) {}

enum events get_new_event (void)
{
    return E1;
}


void bipBuzzer()
{
  PORTB |= 1 << BUZ;
  _delay_ms(50);
  PORTB &= ~(1 << BUZ);
}

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.home();
  lcd.print(DEVICE_NAME_LCD);
  lcd.setCursor(0, 1);
  lcd.print("    Ver         ");
  lcd.setCursor(8, 1);
  lcd.print(VERSION_FW);
  bipBuzzer();
}

void loop() {
 
}
