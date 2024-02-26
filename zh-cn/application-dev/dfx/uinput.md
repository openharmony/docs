# uinput


uinput可模拟用户操作设备，用于稳定性等压力测试。


## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。


## uinput功能

| 命令 | 含义说明 | 
| -------- | -------- |
| -K&nbsp;&nbsp;--keyboard | 注入按键事件。 | 
| -T&nbsp;&nbsp;--touch | 注入触控事件。 | 
| -M&nbsp;&nbsp;--mouse | 注入鼠标事件。 | 
| -k --knuckle | 注入指关节事件。 | 
| -?&nbsp;&nbsp;--help | 命令详细说明 | 


## 常用命令

1. 输入uinput -K -d 18 -u 18，按下并弹起电源键。参考：[键值定义说明](../reference/apis-input-kit/js-apis-keycode.md)。

2. 输入uinput -T -m 100 200 500 800 1000，手指从100 200 移动到 500 800 耗时1秒。!
