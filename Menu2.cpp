#include "Arduino.h"
#include "Menu2.h"
void Menu2::initmenu(LiquidCrystal_I2C* outlcd)
{
lcd=outlcd;

}

void Menu2::Drawmenu(Buttons& Butt)

{


  //Serial.println(mainmenudrawrequest);
  //Serial.println(maindrawed);
  //Serial.println(main);
if ((currentmenu==main)&&(drawed==0))
this->mainview();


else if ((Butt.b2pressed != b2prev )&&(currentmenu==main)) {
  if (Butt.b2pressed == LOW) {
Serial.println("2painettu");
lcd->setCursor(10, currentitem);
if (currentitem<=3)
{
//Serial.println(currentitem);

currentitem=currentitem+1;

lcd->print(" ");
lcd->setCursor(10, currentitem);
lcd->print("<");
  }
if((currentitem >3) && (currentitem <=(NUMITEMS(string_table))))
{
  Serial.print("toinen rivi");
  Serial.println(currentitem);
  lcd->setCursor(10, currentitem);
  lcd->print(" ");
  lcd->setCursor(18, currentitem-4);
  lcd->print("<");
}
}
b2prev=Butt.b2pressed;
}

else if ((Butt.b1pressed != b1prev )&&(currentmenu==main)) {


  if (Butt.b1pressed == LOW) {
Serial.println("1painettu");

lcd->setCursor(10, currentitem);
if ((currentitem>0)&& (currentitem <=3))
{
 if (currentitem <=(NUMITEMS(string_table)))
{
currentitem=currentitem-1;
}
lcd->print(" ");
lcd->setCursor(10, currentitem);
lcd->print("<");
  }
else if(currentitem ==4)
{
  Serial.println(currentitem);
  lcd->setCursor(18, currentitem-4);
  lcd->print(" ");
  if (currentitem <=(NUMITEMS(string_table)))
{
  currentitem=currentitem-1;
  lcd->setCursor(10, currentitem-4);
  lcd->print("<");
}
}
else if(currentitem >4)
{
  Serial.println(currentitem);
  lcd->setCursor(18, currentitem-4);
  lcd->print(" ");
   if (currentitem <=(NUMITEMS(string_table)))
{
  currentitem=currentitem-1;
}
  lcd->setCursor(10, currentitem-4);
  lcd->print("<");
}
}
  
b1prev=Butt.b1pressed;
}

else if ((Butt.b3pressed != b3prev )&&(currentmenu==main)) {
  if (Butt.b3pressed == LOW) {
Serial.println("painettu");
switch(currentitem) {
    case 0 :
 drawed=0;
    currentmenu=equipment;
break;
    case 1 :
    drawed=0;
   currentmenu=holesize;
break;
   case 2 :
    drawed=0;
    currentmenu=viscosity;
break;
    case 3 :
    drawed=0;
    currentmenu=correction;
break;
    case 4 :
    drawed=0;
    currentmenu=quit;
break;

     }

}
b3prev=Butt.b3pressed;
}
else if ((currentmenu==equipment)&&(drawed==0))
{
this->typemenu(drawed,0);
}
else if ((Butt.b1pressed != b1prev )&&(currentmenu==equipment)) {


  if (Butt.b1pressed == LOW) {
Serial.println("machines");
 if (currentmachine <=(NUMITEMS(machines)+1)&&(currentmachine>0))
{
lcd->setCursor(12, currentmachine);
lcd->print(" ");
currentmachine=currentmachine-1;
lcd->setCursor(12, currentmachine);
lcd->print("<");
  }

}
b1prev=Butt.b1pressed;
}
else if ((Butt.b2pressed != b2prev )&&(currentmenu==equipment)) {
  if (Butt.b2pressed == LOW)
  {


 if (currentmachine <(NUMITEMS(machines)))
{
//Serial.println(currentitem);
lcd->setCursor(12, currentmachine);
lcd->print(" ");
currentmachine=currentmachine+1;
lcd->setCursor(12, currentmachine);
lcd->print("<");
Serial.println(currentmachine);
  }
  }
b2prev=Butt.b2pressed;
}

else if ((Butt.b3pressed != b3prev )&&(currentmenu==equipment)) {
  if (Butt.b3pressed == LOW) {
Serial.println("painettu");
switch(currentmachine) {
    case 0 :
 drawed=0;
  
   while (!eeprom_is_ready());
      cli();
   eeprom_write_word((uint16_t*)960, 300);
    eeprom_write_word((uint16_t*)964, 10);
     eeprom_write_word((uint16_t*)968, currentmachine);
     sei();
      this->typemenu(drawed,currentmachine);
  // Serial.println(selected);
break;
    case 1 :
    drawed=0;
    while (!eeprom_is_ready());
      cli();
    eeprom_write_word((uint16_t*)960, 300);
    eeprom_write_word((uint16_t*)964, 24);
    eeprom_write_word((uint16_t*)968, currentmachine);
  sei();
   this->typemenu(drawed,currentmachine);
break;
   case 2 :
    drawed=0;
    while (!eeprom_is_ready());
      cli();
    eeprom_write_word((uint16_t*)960, 300);
    eeprom_write_word((uint16_t*)964, 17);
    eeprom_write_word((uint16_t*)968, currentmachine);
    sei();
   this->typemenu(drawed,currentmachine);
 break;
   case 3 :
    drawed=0;
    currentmenu=main;
break;


     }

}
b3prev=Butt.b3pressed;
}

else if ((currentmenu==holesize)&&(drawed==0))
{
this->holemenu(drawed);
}
else if ((Butt.b1pressed != b1prev )&&(currentmenu==holesize)) {


  if (Butt.b1pressed == LOW) {

holewidth=holewidth+1;
 while (!eeprom_is_ready());
      cli();
eeprom_write_word((uint16_t*)962, holewidth);
sei();
this->holemenu(drawed);

}
b1prev=Butt.b1pressed;
}
else if ((Butt.b2pressed != b2prev )&&(currentmenu==holesize)) {
  if (Butt.b2pressed == LOW)
  {
holewidth=holewidth-1;
 while (!eeprom_is_ready());
      cli();
eeprom_write_word((uint16_t*)962, holewidth);
sei();
this->holemenu(drawed);

}
b2prev=Butt.b2pressed;
}

else if ((Butt.b3pressed != b3prev )&&(currentmenu==holesize)) {
  if (Butt.b3pressed == LOW) {
Serial.println("3painettu");
currentmenu=main;
drawed=0;

}
b3prev=Butt.b3pressed;
}
else if ((currentmenu==viscosity)&&(drawed==0))
{
this->viscositymenu(drawed);
}
else if ((Butt.b1pressed != b1prev )&&(currentmenu==viscosity)) {


  if (Butt.b1pressed == LOW) {

density=density+10;
 while (!eeprom_is_ready());
      cli();
eeprom_update_word((uint16_t*)986, density);
sei();
this->viscositymenu(drawed);

}
b1prev=Butt.b1pressed;
}
else if ((Butt.b2pressed != b2prev )&&(currentmenu==viscosity)) {
  if (Butt.b2pressed == LOW)
  {
density=density-10;
 while (!eeprom_is_ready());
      cli();
eeprom_write_word((uint16_t*)964, density);
sei();
this->viscositymenu(drawed);

}
b2prev=Butt.b2pressed;
}

else if ((Butt.b3pressed != b3prev )&&(currentmenu==viscosity)) {
  if (Butt.b3pressed == LOW) {
Serial.println("3painettu");
currentmenu=main;
drawed=0;

}
b3prev=Butt.b3pressed;
}


else if ((currentmenu==correction)&&(drawed==0))
{
this->correctionmenu(drawed);
}
else if ((Butt.b1pressed != b1prev )&&(currentmenu==correction)) {


  if (Butt.b1pressed == LOW) {

correctionfac=correctionfac+1;
 while (!eeprom_is_ready());
      cli();
eeprom_write_word((uint16_t*)966, correctionfac);
sei();
this->correctionmenu(drawed);

}
b1prev=Butt.b1pressed;
}
else if ((Butt.b2pressed != b2prev )&&(currentmenu==correction)) {
  if (Butt.b2pressed == LOW)
  {
correctionfac=correctionfac-1;
 while (!eeprom_is_ready());
      cli();
eeprom_write_word((uint16_t*)966, correctionfac);
sei();
this->correctionmenu(drawed);

}
b2prev=Butt.b2pressed;
}

else if ((Butt.b3pressed != b3prev )&&(currentmenu==correction)) {
  if (Butt.b3pressed == LOW) {
Serial.println("3painettu");
currentmenu=main;
drawed=0;

}
b3prev=Butt.b3pressed;
}
else if ((currentmenu==quit)&&(drawed==0))
{
  this->quitmenu();
}


}
