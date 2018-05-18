#define PRESSED 1
#define NOT_PRESSED 0
const unsigned long SHORT_PRESS = 100;
const unsigned long LONG_PRESS = 3000;

typedef struct Buttons
{
    unsigned long counter = 0;
    bool prevState = NOT_PRESSED;
    bool currentState;
} Button;

int getState()
{
  if (touchRead(T0) > 50)
  {
    return NOT_PRESSED;
  }
  else
  {
    return PRESSED;
  }
}

Button button;

void gotTouch()
{
    button.currentState = getState();
    if (button.currentState != button.prevState)
    {
        if (button.currentState == PRESSED)
        {
            button.counter = millis();
        }
        else
        {
            unsigned long diff = millis() - button.counter;
            if (diff >= SHORT_PRESS && diff < LONG_PRESS)
            {
                Serial.println("pressed");
            }
            else if (diff >= LONG_PRESS)
            {
                Serial.println("long pressed");
            }
        }
        button.prevState = button.currentState;
    }
}

void setup()
{
  touchAttachInterrupt(T0, gotTouch, 80);
}

void loop()
{
}
