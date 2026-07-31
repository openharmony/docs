# 游戏控制器术语
<!--Kit: Game Controller Kit-->
<!--Subsystem: Game-->
<!--Owner: @weixin_42784160-->
<!--Designer: @wudejun2025-->
<!--Tester: @fei_0805-->
<!--Adviser: @luwy2025-->

## A

### Axis Event；轴事件
游戏手柄上模拟量输入的事件类型，包括摇杆（LeftThumbstick、RightThumbstick）、方向键（DPAD）、扳机（LeftTrigger、RightTrigger）等物理轴的动作。轴事件提供连续变化的数值，用于表达精细的方向和力度控制。

## B

### Button Event；按键事件
游戏手柄上数字量输入的事件类型，包括A、B、X、Y按钮，方向键（DPAD），肩键（LeftShoulder、RightShoulder），扳机键（LeftTrigger、RightTrigger）等。按键事件仅表示按下和释放两种状态，用于表达离散的操控意图。

## D

### Device Monitor；设备监听
Game Controller Kit提供的设备状态监控能力。开发者通过注册设备监听回调，可实时获取设备接入（上线）和设备移除（下线）的事件通知，并支持查询当前所有在线设备的具体信息。

## G

### Game Device；游戏设备
游戏控制器服务中管理的游戏外设设备。每个游戏设备具有唯一标识符（deviceId）、设备名称、产品信息、版本号等属性。游戏设备包括游戏手柄等多种类型。

### Game Pad；游戏手柄
一种游戏专用外设输入设备，通过有线或无线方式与主机连接。游戏手柄包含多种物理轴（摇杆、扳机）和数字按键（方向键、功能键），用于向游戏发送用户操控指令。