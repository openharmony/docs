# uinput

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

uinput 可模拟用户操作，例如鼠标、键盘、触控板等设备，适用于稳定性等压力测试。

## 环境要求

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 确保设备已成功连接，并执行hdc shell。

## uinput功能

**用法**
```bash
uinput <option> <command> <arg> ...
```

**支持能力**
| 命令简写  | 命令全写   | 含义说明        | 
| -------- | --------   | --------       |
| -M       | --mouse    | 注入鼠标事件。  | 
| -K       | --keyboard | 注入键盘事件。  |
| -S       | --stylus   | 注入触控笔事件。 | 
| -T       | --touch    | 注入触摸事件。  |
| -P       | --touchpad | 注入触控板事件。暂不支持。|
| -?       | --help     | 帮助命令。      | 

> **说明：**
>
> 命令中与坐标相关的参数，单位均为[px(屏幕物理像素单位)](../reference/apis-arkui/arkui-ts/ts-pixel-units.md)。

## 帮助命令

显示uinput工具支持的命令信息。

**命令**
```bash
uinput -? 
uinput --help
```

**使用示例**
```bash
# 显示帮助信息
uinput -? 

# 执行结果
Usage: uinput <option> <command> <arg>...
The option are:
-K  --keyboard
commands for keyboard:
-d <key>                   --down   <key>     -press down a key
-u <key>                   --up     <key>     -release a key
-l <key> [long press time] --long_press <key> [long press time] -press and hold the key
-r <key> [repeat output time] --repeat output <key> [repeat output time] -press and hold the key
-i <time>                  --interval <time>  -the program interval for the (time) milliseconds

...

```

## 鼠标事件

模拟鼠标移动、点击等事件。

### 鼠标移动事件
模拟鼠标移动到以指定屏幕左上角为原点的相对坐标系的位置(dx, dy)。

**命令**
```bash
uinput -M -m <dx> <dy>
uinput --mouse --move <dx> <dy>
```

**使用示例**
```bash
# 模拟鼠标移动到以指定屏幕左上角为原点的相对坐标系的位置(100, 100)。
uinput -M -m 100 100
```

**扩展命令**
```bash
uinput -M -m <dx1> <dy1> <dx2> <dy2> [smooth time] --trace
uinput --mouse --move <dx1> <dy1> <dx2> <dy2> [smooth time] --trace

# 补充选项 --trace 可以模拟鼠标移动到以指定屏幕左上角为原点的相对坐标系的位置及过程。
# [smooth time]移动时间，默认值：1000ms，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 模拟鼠标从(100, 100)花费1500ms移动到(200, 200)。
uinput -M -m 100 100 200 200 1500 --trace
```

### 鼠标按键按下事件
模拟鼠标按下按键，建议与鼠标按键抬起事件搭配使用，确保事件闭环。buttonId：[鼠标按键](#鼠标按键)。

**命令**
```bash
uinput -M -d <buttonId>
uinput --mouse --down <buttonId>
```

### 鼠标按键抬起事件
模拟鼠标抬起按键，建议与鼠标按键按下事件搭配使用，确保事件闭环。buttonId：[鼠标按键](#鼠标按键)。

**命令**
```bash
uinput -M -u <buttonId>
uinput --mouse --up <buttonId>
```

**使用示例**
```bash
# 按下鼠标左键并抬起。
uinput -M -d 0 -u 0
```

### 鼠标按键单击事件
模拟鼠标单击按键。buttonId：[鼠标按键](#鼠标按键)。

**命令**
```bash
uinput -M -c <buttonId>
uinput --mouse --click <buttonId>
```

**使用示例**
```bash
# 单击鼠标左键。
uinput -M -c 0
```

### 双击鼠标按键事件
模拟双击鼠标按键。buttonId：[鼠标按键](#鼠标按键)。

**命令**
```bash
uinput -M -b <dx> <dy> <buttonId> [press time] [click interval time]
uinput --mouse --double_click <dx> <dy> <buttonId> [press time] [click interval time]

# [press time]首次按压时间，可选参数，默认时间为：50ms，取值范围：[1,300]ms，仅支持整数。
# [click interval time]点击间隔时间，可选参数，默认时间为：300ms，取值范围：[1,450]ms，仅支持整数。
设置间隔时间必须在取值范围内，否则操作结果可能产生错误或无效操作。
```

**使用示例**
```bash
# 在（100， 150）这个位置双击鼠标左键。
uinput -M -b 100 150 0 10 10
```

### 鼠标滚轴滚动事件
模拟鼠标滚轴向前/向后滚动，需与鼠标移动事件搭配使用。

**命令**
```bash
uinput -M -m <dx1> <dy1> -s <number>
uinput --mouse --move <dx1> <dy1> --scroll <number>

# number鼠标滚动刻度数，正数向后滚动，负数向前滚动，一个刻度是15。
```

**使用示例**
```bash
# 鼠标移动到以指定屏幕左上角为原点的相对坐标系的位置(100, 200)，鼠标滚轴向后滚动三个刻度。
uinput -M -m 100 200 -s 45
```

### 鼠标拖拽事件
模拟鼠标拖拽。

**命令**
```bash
uinput -M -g <dx1> <dy1> <dx2> <dy2> [total time]
uinput --mouse --drag <dx1> <dy1> <dx2> <dy2> [total time]

# [total time]拖拽总耗时，可选参数，默认值为1000ms，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 模拟按下鼠标左键从(200, 650)耗时15000ms拖动到(500, 300)后释放鼠标左键。
uinput -M -g 200 650 500 300 15000
```

### 设置鼠标事件间隔
设置鼠标事件的程序间隔，以毫秒为单位。需与其它鼠标事件命令搭配使用，否则无意义。

**命令**
```bash
uinput -M -i <time>
uinput --mouse --interval <time>

# time鼠标事件间隔时间，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 单击鼠标左键间隔500ms后再次单击鼠标左键。
uinput -M -c 0 -i 500 -c 0
```

### 鼠标按键
| buttonId |  含义说明 |
| -------- | -------- |
| 0  | 鼠标左键   |
| 1  | 鼠标右键   |
| 2  | 鼠标中键   |
| 3  | 鼠标侧边键 |
| 4  | 鼠标扩展键 |
| 5  | 鼠标前进键 |
| 6  | 鼠标后退键 |
| 7  | 鼠标任务键 |

## 键盘事件

模拟编辑框键盘按键输入事件。

### 键盘按键按下事件
模拟键盘按下按键，建议与键盘按键抬起事件搭配使用，确保事件闭环。keyCode：[键值定义说明](../reference/apis-input-kit/js-apis-keycode.md)。

**命令**
```bash
uinput -K -d <keyCode>
uinput --keyboard --down <keyCode>
```

### 键盘按键抬起事件
模拟键盘抬起按键，必须与键盘按键按下事件搭配使用，确保事件闭环。keyCode：[键值定义说明](../reference/apis-input-kit/js-apis-keycode.md)。

**命令**
```bash
uinput -K -u <keyCode>
uinput --keyboard --up <keyCode>
```

**使用示例**
```bash
# 按下"A"键并抬起。
uinput -K -d 2017 -u 2017
```

### 键盘按键长按事件
模拟键盘按下一个按键并保持设定的时长后抬起。keyCode：[键值定义说明](../reference/apis-input-kit/js-apis-keycode.md)。

**命令**
```bash
uinput -K -l <keyCode> [long press time]
uinput --keyboard --long_press <keyCode> [long press time]

# [long press time]长按时间，可选参数，默认值为3000ms，取值范围：[3000,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 按下"A"键并保持6000ms后抬起。
uinput -K -l 2017 6000
```

### 键盘按键持续输入事件
模拟键盘按下一个按键并在设定的时长内持续输入按下事件后抬起。keyCode：[键值定义说明](../reference/apis-input-kit/js-apis-keycode.md)。

**命令**
```bash
uinput -K -r <keyCode> [repeat output time]
uinput --keyboard --repeat <keyCode> [repeat output time]

# [repeat output time]重复输出时间，可选参数，默认值为3000ms，取值范围：[3000,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 按下"A"键并在4000ms内重复输入。
uinput -K -r 2017 4000
```

### 设置键盘事件间隔
设置键盘事件以毫秒为单位的程序间隔。需与其它键盘事件命令搭配使用，否则无意义。

**命令**
```bash
uinput -K -i <time>
uinput --keyboard --interval <time>

# time键盘事件间隔时间，取值范围：[1,15000]ms。
```

**使用示例**
```bash
# 按下键盘"A"键间隔500ms后释放。
uinput -K -d 2017 -i 500 -u 2017
```

### 键盘文本输入事件
模拟键盘输入文本。不支持与其它命令组合使用。只支持ASCII字符，最大支持输入字符2000个。

**命令**
```bash
uinput -K -t <text>
uinput --keyboard --text <text>
```

**使用示例**
```bash
# 在编辑框输入一段文本"123"
uinput -K -t 123
```

## 触控笔事件

模拟触控笔点击、滑动等事件。

### 触控笔按下事件
模拟触控笔在（dx dy）按下，建议与触控笔抬起事件搭配使用，确保事件闭环。

**命令**
```bash
uinput -S -d <dx> <dy>
uinput --stylus --down <dx> <dy>
```

### 触控笔抬起事件
模拟触控笔在（dx dy）抬起，建议与触控笔按下事件搭配使用，确保事件闭环。

**命令**
```bash
uinput -S -u <dx> <dy>
uinput --stylus --up <dx> <dy>
```

**使用示例**
```bash
# 在（100, 100）位置按下并抬起。
uinput -S -d 100 100 -u 100 100
```

### 触控笔移动事件
模拟触控笔从（dx1, dy1）按下在指定时间内移动到（dx2, dy2）后抬起。

**命令**
```bash
uinput -S -m <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]
uinput --stylus --move <dx1> <dy1> <dx2> <dy2> [smooth time] [-k keep time]

# [smooth time]移动时间，可选参数，默认值为1000ms，取值范围：[1,15000]ms，仅支持整数。
# [-k keep time]移动至目标位置后抬起前的停留时间，可选参数，默认值为0ms，取值范围：[0,60000]ms，仅支持整数。
```

**使用示例**
```bash
# 触控笔从(100, 1000)按下，花费1000ms移动到(100, 2000)后，保持按下1000ms后抬起。
uinput -S -m 100 1000 100 2000 1000 -k 1000
```

### 触控笔单击事件
模拟触控笔在(dx, dy)位置单击。

**命令**
```bash
uinput -S -c <dx> <dy> [click interval]
uinput --stylus --click <dx> <dy> [click interval]

# [click interval]点击间隔时间，可选参数，默认值为100ms，取值范围：[1,450]ms，仅支持整数。
```

**使用示例**
```bash
# 触控笔在(100, 100)位置单击。
uinput -S -c 100 100
```

### 触控笔拖拽事件
模拟触控笔拖拽事件。

**命令**
```bash
uinput -S -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --stylus --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# [Press time]拖拽移动前的按压持续时间，可选参数，默认值为500ms，取值范围：[500,14500]ms，仅支持整数。
# [total time]拖动时间，可选参数，默认值为1000ms，取值范围：[1000,15000]ms，仅支持整数。[total time] - [Press time]不能少于500ms，否则操作结果可能产生错误或无效操作。
```

**使用示例**
```bash
# 模拟触控笔从(100, 150)长按500ms后开始拖拽并在1100ms后拖动到(500, 300)释放。
uinput -S -g 100 150 500 300 500 1100
```

### 设置触控笔事件间隔
设置触控笔事件以毫秒为单位的程序间隔。需与其它触控笔事件命令搭配使用，否则无意义。

**命令**
```bash
uinput -S -i <time>
uinput --stylus --interval <time>

# time间隔时间，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 触控笔在(100, 100)位置按下后，间隔500ms后在(100, 100)位置抬起。
uinput -S -d 100 100  -i 500 -u 100 100
```

## 触摸事件

模拟手指触摸点击、滑动等事件。

### 触摸按下事件
模拟手指触摸在（dx dy）按下，建议与触摸抬起事件搭配使用，确保事件闭环。

**命令**
```bash
uinput -T -d <dx> <dy>
uinput --touch --down <dx> <dy>
```

### 触摸抬起事件
模拟手指触摸在（dx dy）抬起，建议与触摸按下事件搭配使用，确保事件闭环。

**命令**
```bash
uinput -T -u <dx> <dy>
uinput --touch --up <dx> <dy>
```

**使用示例**
```bash
# 在（100, 100）位置按下并抬起。
uinput -T -d 100 100 -u 100 100
```

### 触摸移动事件
模拟手指触摸从(dx1, dy1)按下，在指定时间内移动到(dx2, dy2)后抬起，最多支持三指同时移动。

**命令**
```bash
uinput -T -m <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]
uinput --touch --move <dx1> <dy1> <dx2> <dy2> [-k keep time] [smooth time]

# [-k keep time]按下保持时间，可选参数，默认值为0ms，取值范围：[0,60000]ms，仅支持整数。
# [smooth time]移动时间，可选参数，默认值为1000ms，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 手指触摸从(100, 1000)按下，花费1000ms移动到(100, 2000)后，保持按下1000ms后抬起。
uinput -T -m 100 1000 100 2000 -k 1000 1000

# 三指滑动，第一根手指触摸按下从（300，900）移动到（300,2000），第二根手指触摸按下从（600,900）移动到（600,2000），第三根手指触摸按下从（900,900）移动到（900,2000），移动总时长为200ms，移动结束后手指在屏幕停顿1000m后再抬起。
uinput -T -m 300 900 300 2000 600 900 600 2000 900 900 900 2000 -k 1000 200
```

### 触摸单击事件
模拟手指触摸在(dx, dy)位置单击。

**命令**
```bash
uinput -T -c <dx> <dy> [click interval]
uinput --touch --click <dx> <dy> [click interval]

# [click interval]点击间隔时间，可选参数，默认值为100ms，取值范围：[1,450]ms，仅支持整数。
```

**使用示例**
```bash
# 手指在触摸屏(100, 100)位置单击。
uinput -T -c 100 100
```

### 触摸拖拽事件
模拟手指触摸拖拽事件。

**命令**
```bash
uinput -T -g <dx1> <dy1> <dx2> <dy2> [press time] [total time] 
uinput --touch --drag <dx1> <dy1> <dx2> <dy2> [press time] [total time] 

# [press time]按压时间，可选参数，默认值为500ms，取值范围：[500,14500]ms，仅支持整数。
# [total time]拖动时间，可选参数，默认值为1000ms，取值范围：[1000,15000]ms，仅支持整数。[total time] - [Press time]不能少于500ms，否则操作结果可能产生错误或无效操作。
```

**使用示例**
```bash
# 模拟手指按下从(100, 150)在1100ms拖动到(500, 300)后释放。
uinput -T -g 100 150 500 300 500 1100
```

### 设置触摸事件间隔
设置触摸事件以毫秒为单位的程序间隔。

**命令**
```bash
uinput -T -i <time>
uinput --touch --interval <time>

# time间隔时间，取值范围：[1,15000]ms，仅支持整数。
```

**使用示例**
```bash
# 手指在(100, 100)位置按下后，间隔500ms后在(100, 100)位置抬起。
uinput -T -d 100 100  -i 500 -u 100 100
```

### 触摸屏单指关节双击事件
模拟触摸屏单指关节双击。

**命令**
```bash
uinput -T -k -s <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --single <dx1> <dy1> <dx2> <dy2> [interval time]

# [interval time]间隔时间，可选参数，默认值200ms，取值范围：[1,250]ms，仅支持整数。
```

**使用示例**
```bash
# 单指关节在(100, 100)、(100, 130)位置间隔200ms敲击。
uinput -T -k -s 100 100 100 130
```

### 触摸屏双指关节双击事件
模拟触摸屏双指关节双击。

**命令**
```bash
uinput -T -k -d <dx1> <dy1> <dx2> <dy2> [interval time]
uinput --touch --knuckle --double <dx1> <dy1> <dx2> <dy2> [interval time]

# <dx1> <dy1>第一个指关节坐标，<dx2> <dy2>第二个指关节坐标。
# [interval time]间隔时间，可选参数，默认值200ms，取值范围：[1,250]ms，仅支持整数。
```

**使用示例**
```bash
# 双指关节分别在(100, 100)、(100, 130)位置间隔200ms敲击2次。
uinput -T -k -d 100 100 100 130
```
