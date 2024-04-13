#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ДЕФАЙНЫ ДЛЯ ИГРОВЫХ ОБЪЕКТОВ

#define DINO_WIDTH 25 // размеры
#define DINO_HEIGHT 26
#define DINO_INIT_X 10 // Спавн динозавика
#define DINO_INIT_Y 29 // Спавн динозавика

#define BASE_LINE_X 0
#define BASE_LINE_Y 54
#define BASE_LINE_X1 127
#define BASE_LINE_Y1 54

#define TREE1_WIDTH 11
#define TREE1_HEIGHT 23

#define TREE2_WIDTH 22
#define TREE2_HEIGHT 23

#define TREE_Y 35

#define JUMP_PIXEL 22 // высота прыжка в пикселях
Adafruit_SSD1306 display(128, 64, &Wire, -1);


static const unsigned char PROGMEM dino1[]={
  // 'dino', 25x26px
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x06, 0xff, 0x00, 0x00, 0x0e, 0xff, 0x00, 
0x00, 0x0f, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x0f, 0xc0, 0x00, 
0x00, 0x0f, 0xfc, 0x00, 0x40, 0x0f, 0xc0, 0x00, 0x40, 0x1f, 0x80, 0x00, 0x40, 0x7f, 0x80, 0x00, 
0x60, 0xff, 0xe0, 0x00, 0x71, 0xff, 0xa0, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x7f, 0xff, 0x80, 0x00, 
0x7f, 0xff, 0x80, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 
0x03, 0xfc, 0x00, 0x00, 0x01, 0xdc, 0x00, 0x00, 0x01, 0x8c, 0x00, 0x00, 0x01, 0x8c, 0x00, 0x00, 
0x01, 0x0c, 0x00, 0x00, 0x01, 0x8e, 0x00, 0x00
};

static const unsigned char PROGMEM tree1[]={
  // 'tree1', 11x23px
0x1e, 0x00, 0x1f, 0x00, 0x1f, 0x40, 0x1f, 0xe0, 0x1f, 0xe0, 0xdf, 0xe0, 0xff, 0xe0, 0xff, 0xe0, 
0xff, 0xe0, 0xff, 0xe0, 0xff, 0xe0, 0xff, 0xe0, 0xff, 0xc0, 0xff, 0x00, 0xff, 0x00, 0x7f, 0x00, 
0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00
};

static const unsigned char PROGMEM tree2[]={
  // 'tree2', 22x23px
0x1e, 0x01, 0xe0, 0x1f, 0x03, 0xe0, 0x1f, 0x4f, 0xe8, 0x1f, 0xff, 0xfc, 0x1f, 0xff, 0xfc, 0xdf, 
0xff, 0xfc, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xfc, 0xff, 0xff, 
0xfc, 0xff, 0xef, 0xfc, 0xff, 0x83, 0xfc, 0xff, 0x03, 0xfc, 0xff, 0x03, 0xf8, 0x7f, 0x03, 0xe0, 
0x1f, 0x03, 0xe0, 0x1f, 0x03, 0xe0, 0x1f, 0x03, 0xe0, 0x1f, 0x03, 0xe0, 0x1f, 0x03, 0xe0, 0x1f, 
0x03, 0xe0, 0x1f, 0x03, 0xe0
};

void setup() 
{
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.clearDisplay();
    //==bad intro==
  introMessage();
    //кнопОчка на старт
  while(digitalRead(2) == 0);
  delay(300);
  play();
}

void loop() 
{
}

// экран приветсвия
void introMessage(){
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,5);
  display.println("Dino Game");
  

  display.setTextSize(1);
  
  display.setCursor(5,45);
  display.println("Enter 1 To Play ");

  display.display();
}

// прыжки динозашки
void moveDino(int y, int type=0)
{
  display.drawBitmap(DINO_INIT_X, y, dino1, DINO_WIDTH, DINO_HEIGHT, SSD1306_WHITE);
}

// Движ деревьев
void moveTree(int x, int type=0)
{
  if(type==0)
  {
    display.drawBitmap(x, TREE_Y, tree1, TREE1_WIDTH, TREE1_HEIGHT, SSD1306_WHITE);
  }
  else if(type==1){
    display.drawBitmap(x, TREE_Y, tree2, TREE2_WIDTH, TREE2_HEIGHT, SSD1306_WHITE);
  }  
}

// Экран на смерть
void gameOver(int score=0)
{
  display.clearDisplay();

  display.setTextSize(2);             // x2  масштаб
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,5);
  display.println("Game Over");
  

  display.setTextSize(1);

  display.setCursor(10,30);
  display.print("Score: ");
  display.print(score);

  
  display.setCursor(1,45);
  display.println("Go cry like a child");

  display.display();
}

// Вывод очков
void displayScore(int score)
{
  display.setTextSize(1);
  display.setCursor(64,10);
  display.print("Score: ");
  display.print(score);
}

// Основаная функция игры
void play()
{
  int tree_x=127;
  int tree1_x=195;
  int tree_type = random(0,2);
  int tree_type1 = random(0,2);

  int dino_y = DINO_INIT_Y;
  int jump=0;

  int score=0;
  
  while(true)
  {
    display.clearDisplay();

    if (digitalRead(2) == 0 && jump==0) jump=1;
    if(jump==1)
    {
      dino_y--;
      if(dino_y== (DINO_INIT_Y-JUMP_PIXEL))
      {
        jump=2;
        score++;
      }
    }
    else if(jump==2)
    {
      dino_y++;
      if(dino_y== DINO_INIT_Y) jump=0; 
    }

    if(tree_x <= (DINO_INIT_X+DINO_WIDTH) && tree_x >= (DINO_INIT_X+(DINO_WIDTH/2)))
    {
      if(dino_y>=(DINO_INIT_Y-3))
      {
        Serial.println("Died from tree");
        break;
      }    
    }

    if(tree1_x <= (DINO_INIT_X+DINO_WIDTH) && tree1_x >= (DINO_INIT_X+(DINO_WIDTH/2)))
    {
      if(dino_y>=(DINO_INIT_Y-3))
      {
        Serial.println("Died from tree1");
        break;
      }    
    }

    displayScore(score);
    moveTree(tree_x,tree_type);
    moveTree(tree1_x,tree_type1);
    moveDino(dino_y);
    display.drawLine(0, 54, 127, 54, SSD1306_WHITE);
    
    //move all shit
    tree_x--;
    tree1_x--;

    //respawn if out of screen
    if(tree_x==0) {
      tree_x = 127;
      tree_type = random(0,1);
    }

    if(tree1_x==0) {
      tree1_x = 195;
      tree_type1 = random(0,1);
    }
    display.display();
  }

  Serial.println("Game Over");
  gameOver(score);
}
