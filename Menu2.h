#ifndef Menu2_h
#define Menu2_h
#define NUMITEMS(arg) ((int) (sizeof (arg) / sizeof (arg [0])))
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <avr/pgmspace.h>
#include "Arduino.h"
#include <Buttons.h>

typedef struct
{
   int id;
   int calibrationstatus;
   
} stmachine;



enum menutype { main, equipment, holesize, viscosity,correction, quit};
const char string_0[] PROGMEM = "konetyyppi";   // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "Reikakoko";
const char string_2[] PROGMEM = "Tiheys";
const char string_3[] PROGMEM = "Korjaus";
const char* const string_table[] PROGMEM = {string_0, string_1,string_2,string_3};


const char machine_0[] PROGMEM = "paskavaunu";   // "String 0" etc are strings to store - change to suit.
const char machine_1[] PROGMEM = "Tume";
const char machine_2[] PROGMEM = "GP1006";
const char* const machines[] PROGMEM = {machine_0, machine_1,machine_2};








class Menu2
{


  public:



  void initmenu(LiquidCrystal_I2C* outlcd);
    void Drawmenu(Buttons& Butt);


  private:
      
     
      
      stmachine stmachinearr[3];
      LiquidCrystal_I2C* lcd;
      byte machineinuse=eeprom_read_byte((uint8_t*)968);
      int density;
      int currentmenu;
      int machinetype;
      int holewidth;
      int hamount;
      int correctionfac;
      int drawed;
      int selected;
void quitmenu();
void mainview();
void typemenu(int &drawed, int selected);
void holemenu(int &drawed);
void viscositymenu(int &drawed);
void correctionmenu(int &drawed);
int currentitem=0;
int currentmachine=0;


};

#endif
