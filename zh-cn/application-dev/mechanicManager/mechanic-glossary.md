 # Mechanic Kit术语
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @qxqxqxqxqx-->
<!--Designer: @peter__1024-->
<!--Tester: @Aullar-->
<!--Adviser: @hu-zhiqiong-->

## C
 	 
### Camera Tracking；摄像头跟踪
通过摄像头识别目标并自动控制机械体设备旋转以保持目标在画面中的功能，支持启用/禁用控制和布局设置，用于实现智能跟拍场景。

## G
 
### Gimbal Device；云台设备
一种便携式三轴稳定旋转平台类机械体设备，可搭载摄像头实现稳定拍摄和智能跟踪。
 
## M
  
### Mechanic Device；机械体设备
可通过蓝牙与主机连接并接受旋转控制指令的智能硬件设备（如云台），用于配合摄像头实现稳定拍摄和目标跟踪。

### Mechanic Kit；机械体设备控制器
提供与机械体设备交互能力的Kit，包含设备连接管理、摄像头跟踪控制、旋转控制和状态监听等功能，用于开发机械体设备相关应用。

### Mechanic Kit Protocol；Mechanic Kit协议
机械体设备与Mechanic Kit之间的兼容性规范标准，设备必须符合该协议才能被Mechanic Kit识别和控制，区别于Mechanic Kit（实现规范的软件）和Mechanic Device（符合规范的硬件）。

## R

### Rotation Axis；旋转轴
机械体设备旋转运动的自由度方向，包括偏航轴、横滚轴和俯仰轴，各轴可独立启用或禁用，并具有各自的限位状态，用于描述和控制设备的空间旋转能力。

### Rotation Axis Limit；旋转轴限位
旋转轴在某一方向上已达到最大旋转角度的运行时状态，包括无限制、负方向受限和正方向受限三种情况，用于判断设备是否可以在该方向继续旋转，区别于旋转角度限制（静态约束规格），强调的是轴当前的受限状态。