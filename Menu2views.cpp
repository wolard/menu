#include "Arduino.h"

#include "Menu2.h"
#include <avr/eeprom.h>
#include <avr/pgmspace.h>


void Menu2::mainview( )
{
char buffer[30];
lcd->clear();
lcd->home ();
int i;


 if (NUMITEMS(string_table)<4)
  {
    for (i = 0; i < NUMITEMS(string_table); i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i])));
lcd->setCursor ( 0, i);
lcd->print(buffer);

 
 
 
 }
  lcd->setCursor(0,3);
  lcd->print("Poistu");
   
lcd->setCursor ( 10, currentitem);
lcd->print("<");
  }
  if (NUMITEMS(string_table)>3)
  {
    for (i = 0; i < NUMITEMS(string_table); i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(string_table[i])));
if (i<4)
{
lcd->setCursor ( 0, i);
lcd->print(buffer);
}
if (i>=4)
 {
lcd->setCursor ( 11, i-3);
lcd->print(buffer);
 }
 
 
}
 lcd->setCursor(11,i-4);
  lcd->print("Poistu");
 
 lcd->setCursor ( 10, currentitem);
lcd->print("<");
  }

drawed=1;

}
void Menu2::typemenu(int &drawed, int selected)
{


 char buffer[30];
lcd->clear();
lcd->home ();
int i;
stmachinearr[0].calibrationstatus=eeprom_read_byte((uint8_t*)974);
stmachinearr[0].id=0;
stmachinearr[1].calibrationstatus=eeprom_read_byte((uint8_t*)979);
stmachinearr[1].id=1; 
stmachinearr[2].calibrationstatus=eeprom_read_byte((uint8_t*)984);
stmachinearr[1].id=2; 
  byte machineinuse=eeprom_read_word((uint16_t*)968);
  for (i = 0; i < NUMITEMS(machines); i++)
{
strcpy_P(buffer, (char*)pgm_read_word(&(machines[i])));
lcd->setCursor ( 0, i);

lcd->print(buffer);
lcd->setCursor ( 1, i);
Serial.print("calibroitu");
Serial.println(stmachinearr[i].calibrationstatus);
if (stmachinearr[i].calibrationstatus==0)
{
 lcd->setCursor(15,i);
  lcd->print("no cal");
}
else
{
  lcd->setCursor(15,i);
  lcd->print("cal");
}
if (machineinuse==i)
{
   lcd->setCursor(11,i);
    lcd->print("*");
}
}
 

  
 
  lcd->setCursor(0,3);
  lcd->print("Poistu");
   
lcd->setCursor ( 12, currentmachine);
lcd->print("<");

  drawed=1;
}
void Menu2::holemenu(int &drawed)
{
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print(F("kuristimen"));
  lcd->setCursor(0,1);
  lcd->print(F("halkaisija:"));
  lcd->setCursor(0,2);
   holewidth=eeprom_read_word((uint16_t*)962);
 lcd->print(holewidth);
 lcd->print("  ");
  lcd->setCursor(5,2);

  lcd->print("cm/100");
  lcd->setCursor(14,3);

  lcd->print("Poistu");
  drawed=1;
}
void Menu2::viscositymenu(int &drawed)
{
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("Aineen");
  lcd->setCursor(0,1);
  lcd->print("Tiheys:");
  density=eeprom_read_word((uint16_t*)986);
  lcd->setCursor(0,2);
     lcd->print(density);
 
lcd->setCursor(4,2);
 lcd->print("kg/m3");
 

  
  lcd->setCursor(14,3);

  lcd->print("Poistu");
  drawed=1;
}
void Menu2::correctionmenu(int &drawed)
{
  lcd->clear();
  lcd->setCursor(0,1);
  lcd->print("korjausarvo:");
  lcd->setCursor(0,2);
    lcd->print("0,");
  correctionfac=eeprom_read_word((uint16_t*)966);
lcd->setCursor(2,2);
  
     lcd->print(correctionfac);
 
  lcd->setCursor(14,3);

  lcd->print("Poistu");
  drawed=1;
}
void Menu2::quitmenu()
{
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("kaynnista uudelleen");
  lcd->setCursor(0,1);
  lcd->print("sammuttamalla virta");

  drawed=1;

}
