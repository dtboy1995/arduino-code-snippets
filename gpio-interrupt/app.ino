int pin = 13; // gpio pin脚
void setup()
{
  attachInterrupt(pin, func, CHANGE); // 边沿中断
}
void loop()
{
}
void func()    // 中断处理函数
{
  digitalRead(pin); // 获取gpio的电平值做相应的处理
}
