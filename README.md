# arduino-code-snippets

# 触摸中断模拟点击

一些esp32 arduino的代码片段

- `touch-interrupt`
  - 可以模拟单机和长按的触发
  - 功能
    - 判断是否是单机
    - 判断是否是长按

# GPIO中断

- **arduino对esp32的gpio中断控制非常简单**
- **函数定义**

```c++
attachInterrupt(pin, function, mode);
```
- **参数详解**
	- `pin` gpio的pin脚值

	- `function` 当中断触发时调用的函数

	- `mode` 中断响应的模式

		- `CHANGE` 边沿触发 只要发生电平变化

		- `RISING` 上升沿触发 低电平到高电平

		- `FALLING` 下降沿触发 高电平到低电平

- **示例代码（arduino）**

```c++
int pin = 13; // gpio pin脚

void setup()
{
  attachInterrupt(pin, func, CHANGE); // 边沿中断
}

void loop()
{

}

void func()	// 中断处理函数
{
  digitalRead(pin); // 获取gpio的电平值做相应的处理
}
```
