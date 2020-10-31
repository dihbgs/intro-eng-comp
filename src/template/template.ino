#include <Keypad.h>
#include <LiquidCrystal.h>

//KEYPAD......
const byte ROWS = 4;
const byte COLS = 4; 
 
char keys[ROWS][COLS] =                                     
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'.', '0', '#', 'D'}                                            
};

byte rows[ROWS] = {9, 8, 7, 6};                
byte cols[COLS] = {13, 12, 11, 10};                      
 
Keypad keypad = Keypad (makeKeymap(keys), 
rows, cols, ROWS, COLS);

//LCD........
LiquidCrystal lcd(0,1,2,3,4,5);

//VARIAVEIS.....
char opt, key;
String text;
float total;

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  text = ' ';
  opt = ' ';
  key = ' ';
  
  lcd.clear();
  lcd.print("A: Soma");
  lcd.setCursor(0,1);
  lcd.print("B: Subtrai");
  delay(1250);
  
  lcd.clear();
  lcd.print("C: Reseta");
  lcd.setCursor(0,1);
  lcd.print("D: Deleta char");
  delay(1250);
  
  lcd.clear();
  lcd.print("*: Ponto");
  lcd.setCursor(0,1);
  lcd.print("#: Enter");
  delay(1250);
  
  lcd.clear();
  lcd.print("Insira a opcao: ");
  lcd.setCursor(0,1);
  getOption();
  lcd.print(opt);
  delay(250);
  
  lcd.clear();
  switch(opt)
  {
    case 'A':
      lcd.print("Somar: ");
      lcd.setCursor(0,1);
      getValue();
      total += text.toFloat();
      break;
    case 'B':
      lcd.print("Subtrair: ");
      lcd.setCursor(0,1);
      getValue();
      total -= text.toFloat();
      if(total < 0)
        total = 0;
      break;
    default:
      lcd.print("Confirme:");
      lcd.setCursor(0,1);
      lcd.print("Zerar valor?");
      getOption();
      
      if(opt == 'C')
      {
        total = 0;
        lcd.clear();
        lcd.print("Valor resetado");
      }
      break;
  }
  delay(1000);
  
  lcd.clear();
  lcd.print("Valor total:");
  lcd.setCursor(0,1);
  lcd.print(total);
  delay(2500);
}


void menu()
{
  opt = ' ';
  lcd.clear();
  lcd.print("A: Soma");
  lcd.setCursor(0,1);
  lcd.print("B: Subtrai");
  delay(1250);
  
  lcd.clear();
  lcd.print("C: Reseta");
  lcd.setCursor(0,1);
  lcd.print("D: Deleta char");
  delay(1250);
  
  lcd.clear();
  lcd.print("*: Ponto");
  lcd.setCursor(0,1);
  lcd.print("#: Enter");
  delay(1250);
  
  lcd.clear();
  lcd.print("Insira a opcao: ");
  lcd.setCursor(0,1);
  getOption();
  lcd.print(opt);
  delay(250);
  
  lcd.clear();
  switch(opt)
  {
    case 'A':
      lcd.print("Somar: ");
      lcd.setCursor(0,1);
      getValue();
      total += text.toFloat();
      break;
    case 'B':
      lcd.print("Subtrair: ");
      lcd.setCursor(0,1);
      getValue();
      total -= text.toFloat();
      if(total < 0)
        total = 0;
      break;
    default:
      lcd.print("Confirme:");
      lcd.setCursor(0,1);
      lcd.print("Zerar valor?");
      getOption();
      
      if(opt == 'C')
      {
        total = 0;
        lcd.clear();
        lcd.print("Valor resetado");
      }
      break;
  }
  delay(1000);
  
  lcd.clear();
  lcd.print("Valor total:");
  lcd.setCursor(0,1);
  lcd.print(total);
  delay(2500);
}

void getValue()
{
  text = " ";
  
  do
  {
    key = keypad.getKey();
    
    if(key)
    {
      if(key == 'D' && text.length() > 0)
      {
        text.remove( text.length()-1 );	//apaga o ultimo caractere inserido
      }
      else if(!validate(key))
      {
        text += key;
      }
      
      lcd.setCursor(0,1);
      lcd.print(text);
      delay(250);
    }
    
  }	while(key != '#');
}

//Aguarda o usuario inserir uma opcao valida
void getOption()
{
  do
  {
    opt = keypad.getKey();
    
  }	while(!validate(opt));
}

//Verifica se o char e uma opcao valida de menu
bool validate(char opt)
{
  return opt == 'A' || opt == 'B' || opt == 'C';
}