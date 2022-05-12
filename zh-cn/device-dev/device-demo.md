# 场景Demo示例

本页面提供了典型场景的部分简单有趣的示例，可以帮助您迅速了解OpenHarmony的开发和使用。

 **表 1** 智能家居场景Demo示例
| 示例 | 简介 | 系统 | OpenHarmony版本 | 
| -------- | -------- | -------- | -------- |
| [智能加湿器](https://growing.openharmony.cn/mainPlay/detail?sampleId=3727) | 此样例使用JS编写本地设备应用界面，通过JSI机制与HDF交互来控制加湿器和显示当前湿度。样例还显示日期时间、天气和WIFI状态、阈值调解功能。还已接入数字管家应用，支持远程操作和日程安排,语音控制加湿器开关功能。 | LiteOS-M | 3.1 Beta |
| [智能门铃](https://growing.openharmony.cn/mainPlay/detail?sampleId=3728) | 此样例使用人感配合按键监测入户门前状态：“无人”，“不明人员逗留”，“访客按门铃”。将这些信息实时同步到室内屏幕上，并且在监测到门前有人时，蜂鸣器会报警，提醒室内用户。在设备联网的情况下，这些信息将同步到数字管家，用户可通过数字管家远程一键开锁。 | LiteOS-M | 3.1 Beta | 
| [智能保险柜](https://growing.openharmony.cn/mainPlay/detail?sampleId=3731) | 此样例利用碰一碰配网接入数字管家，并外接震动传感器，实现保险柜实时监控及报警功能。如果保险柜被震动，则手机会收到告警。 | LiteOS-M | 3.1 Beta | 
| [智能烟感系统](https://growing.openharmony.cn/mainPlay/detail?sampleId=3703) | 智能烟感系统通过实时监测环境中烟雾浓度，当烟雾浓度超标时，及时向用户发出警报。在连接网络后，配合数字管家应用，用户可以远程配置智能烟感系统的报警阈值，远程接收智能烟感系统报警信息。实现对危险及时报警，及时处理，守护居家安全。 | LiteOS-M | 1.0.1 LTS | 
| [智能可燃气体检测系统](https://growing.openharmony.cn/mainPlay/detail?sampleId=3704) | 此样例是基于BearPi套件开发的智能可燃气体检测开发样例，该系统内主要由小熊派单板套件和和MQ5可燃气体检测传感器组成。 智能可燃气体检测系统可以通过云和手机建立连接，可以在手机上控制感应的阈值，传感器感知到的可燃气体浓度超过阈值之后，将会通过云传给手机，并报警。 | LiteOS-M | 1.0.1 LTS | 
| [智能甲醛检测系统](https://growing.openharmony.cn/mainPlay/detail?sampleId=3705) | 此样例是基于BearPi套件开发的智能甲醛检测系统开发样例，该设备硬件部分主要由小熊派单板套件和和甲醛检测传感器组成。智能甲醛检测系统可以通过云和手机建立连接，可以在手机上设置甲醛浓度阈值，传感器感知到的甲醛浓度超过阈值之后，将会通过云传给手机，并报警。 | LiteOS-M | 1.0.1 LTS | 
| [智慧窗帘](https://growing.openharmony.cn/mainPlay/detail?sampleId=3706) | 智能窗帘设备不仅接收数字管家应用下发的指令来控制窗帘开启的时间，而且还可以加入到数字管家的日程管理中。通过日程可以设定窗帘开关的时间段，使窗帘在特定的时间段内自动打开或者关闭；通过日程管家还可以实现窗帘和其他的智能设备联动。 | LiteOS-M | 1.0.1 LTS | 
| [智能扫地机](https://growing.openharmony.cn/mainPlay/detail?sampleId=3707) | 此样例采用润和的智能小车套件为硬件模型，通过修改代码具备了扫地机器人简易的避障功能及防跌落功能，并且能通过wifi接入数字管家应用场景。智能扫地机不仅能接收数字管家应用下发的指令启动或停止扫地机器人，而且还可以加入到数字管家的日程管理中。通过日程可以设定智能扫地机启动的时间段，使其在特定的时间段内，智能扫地机自动启动或者停止。 | LiteOS-M | 1.0.1 LTS | 
| [智能养花机](https://growing.openharmony.cn/mainPlay/detail?sampleId=3708) | 智能养花机通过感知花卉、盆栽等植宠生长环境的温度、湿度信息，适时为它们补充水分。在连接网络后，配合数字管家应用，用户可远程进行浇水操作。用户还可在应用中设定日程，有计划的按日、按周进行浇水。在日程中用户可添加其它智能设备（例如：智能窗帘），一起呵护植宠的成长。 | LiteOS-M | 1.0.1 LTS | 
| [护花使者](https://growing.openharmony.cn/mainPlay/detail?sampleId=3699) | 此样例是用BearPi-HM_Nano开发板加上一块“护花使者“底板及抽水电机等配件，快速DIY出一款具备远程监测土壤湿度并实现远程浇水的设备。该项目具备成本低、耗时少、操作简单等特点，时时刻刻呵护您的植物，伴其茁壮成长。 | LiteOS-M | 1.1.0 LTS | 
| [智能垃圾桶](https://growing.openharmony.cn/mainPlay/detail?sampleId=3709) | 智能垃圾桶可以通过数字管家应用来监测垃圾桶当前可用容量，提醒主人及时处理垃圾；通过日程管家可以实现和其他智能设备联动。 | LiteOS-M | 1.0.1 LTS | 
| [智能风扇](https://growing.openharmony.cn/mainPlay/detail?sampleId=3711) | 智能风扇设备不仅接收数字管家应用下发的指令来控制风扇开启的时间，调节风扇挡位，更改风扇定时时间，而且还可以加入到数字管家的日程管理中。通过日程可以设定风扇相关的任务，使其在特定的时间段内，风扇自动打开或者关闭，调节挡位大小和定时时间；通过日程管家还可以实现风扇和其他的智能设备联动。 | LiteOS-M | 1.0.1 LTS | 
| [启航KP_IOT智能风扇模块](https://growing.openharmony.cn/mainPlay/detail?sampleId=3802) | 此样例主要展示基于软通动力启航KP_IoT智能开发套件智能风扇控制，让开发者在学习过程中找到开发的乐趣，从而创造更多实用的应用场景。 | LiteOS-M | 3.0 LTS | 
| [智能手表](https://growing.openharmony.cn/mainPlay/detail?sampleId=3712) | 此样例是基于BearPi套件开发的智能儿童手表系统，该系统通过与GSM模块（型号：SIM808）的通信来实现通话和定位功能。 智能儿童手表系统可以通过云和手机建立连接，同步时间和获取天气信息，通过手机下达日程安排到儿童手表，并显示在儿童手表的屏幕端，还可以通过SIM808模块获取地理位置信息，接收和拨打电话等功能。 | LiteOS-M | 1.0.1 LTS | 
| [智能台灯（BearPi-HM Nano）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3713) | 智能台灯设备不仅接收数字管家应用下发的指令来控制台灯的开关及亮度，而且还可以加入到数字管家的日程管理中。通过日程可以设定台灯开关的时间段，使其在特定的时间段内，台灯自动打开或者熄灭，并能自动调节相应时间段台灯的亮度；通过日程管家还可以实现台灯和其他的智能设备联动。此样例演示如何在BearPi-HM Nano开发板上实现智能台灯。 | LiteOS-M | 1.0.1 LTS | 
| [智能台灯（Pegasus Wi-Fi IoT）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3793) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上实现智能台灯。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS | 
| [智能炫彩灯](https://growing.openharmony.cn/mainPlay/detail?sampleId=3787) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用PWM实现炫彩灯。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS | 
| [智能光控灯](https://growing.openharmony.cn/mainPlay/detail?sampleId=3788) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用ADC实现智能光控灯。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS | 
| [JS灯控应用](https://growing.openharmony.cn/mainPlay/detail?sampleId=3804) | 该样例利用OpenHarmony JS API接口，开发灯控应用，并与开发板进行交互。 | LiteOS-A | 3.0 LTS | 
| [启航KS_智能灯光控制](https://growing.openharmony.cn/mainPlay/detail?sampleId=3801) | 本次实验主要讲述基于软通动力启航KS_IoT智能开发套件智能灯光控制，让开发者在学习过程中找到开发的乐趣，从而创造更多实用的应用场景。 | LiteOS-M | 1.1.3 LTS | 
| [智能温湿度采集](https://growing.openharmony.cn/mainPlay/detail?sampleId=3789) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用I2C实现智能温湿度采集。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS  |
| [智能电子牌](https://growing.openharmony.cn/mainPlay/detail?sampleId=3710) | 此样例是基于hi3516dv300开发板，使用开源鸿蒙OpenHarmony 开发的应用。通过该应用不仅可以查看时间、日期以及对应的室内外温湿度、空气质量等，还可以查看当日的行程，让我们随时随地把握行程，不会遗漏任何重要的安排。 | LiteOS-A | 1.0.1 LTS |
| [智能中控面板](https://growing.openharmony.cn/mainPlay/detail?sampleId=3714) | 此样例是基于Hi3516开发板，使用开源OpenHarmony开发的应用。通过控制面板可以控制同一局域网内的空调，窗帘，灯等智能家居设备。 | LiteOS-A | 1.0.1 LTS |
| [智能猫眼3516](https://growing.openharmony.cn/mainPlay/detail?sampleId=3716) | 此样例是基于Hi3516开发板，使用开源OpenHarmony开发的应用。通过手机应用可以看到Hi3516摄像头捕获的数据。 | LiteOS-A | 1.0.1 LTS |
| [智能猫眼3518](https://growing.openharmony.cn/mainPlay/detail?sampleId=3717) | 此样例是基于Hi3518开发板，使用开源OpenHarmony开发的应用。通过手机应用可以看到Hi3518摄像头捕获的数据。 | LiteOS-A | 1.0.1 LTS |
| [智能环境监控](https://growing.openharmony.cn/mainPlay/detail?sampleId=3794) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上实现智能环境监测系统。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS  |
| [温度监控](https://growing.openharmony.cn/mainPlay/detail?sampleId=3803) | 此样例演示如何根据温度传感设备上报的数据来显示设备所在环境中的温度，并在手机端实时展现。 | LiteOS-M | 3.0 LTS |
| [WIFI连接热点实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3795) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上开发wifi_STA模式。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS |
| [路由器热点功能](https://growing.openharmony.cn/mainPlay/detail?sampleId=3795) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上开发wifi_AP模式。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS |



 **表 2** 影音娱乐场景Demo示例
| 示例 | 简介 | 系统 | OpenHarmony版本 | 
| -------- | -------- | -------- | ------ |
| [贪吃蛇](https://growing.openharmony.cn/mainPlay/detail?sampleId=3718) | 此样例是基于LYEVK-3861开发板IOT套件开发的简易贪吃蛇小游戏，使用了套件中的OLED屏幕扩展板和带按键的照明板。用OLED屏幕显示游戏运行界面，按键复用为游戏选择和游戏控制方向键。 | LiteOS-M | 3.0 LTS |
| [音乐播放](https://growing.openharmony.cn/mainPlay/detail?sampleId=3719) | 此样例是基于LYEVK-3861开发板IOT套件开发的音乐播放放器，通过不同频率的PWM波驱动蜂鸣器可以产生不同音符的声音，利用这一特点，就可以奏出一段音乐。 | LiteOS-M | 3.0 LTS |
| [智能相机](https://growing.openharmony.cn/mainPlay/detail?sampleId=3715) | 此样例是基于Hi3516开发板，使用开源OpenHarmony3.0 LTS开发的应用。通过获取摄像头数据，实现预览拍照以及路视频等功能。并且通过后台AI服务识别唤醒词来进行语音控制拍照及录视频。 | LiteOS-A | 3.0 LTS |
| [多功能OLED屏幕](https://growing.openharmony.cn/mainPlay/detail?sampleId=3791) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用SSD 1306库驱动OLED屏。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS |



 **表 3** 快速上手场景Demo示例
| 示例 | 简介 | 系统 | OpenHarmony版本 | 
| -------- | -------- | -------- | ------ |
| [任务交替打印](https://growing.openharmony.cn/mainPlay/detail?sampleId=3722) | 此样例演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口进行多线程开发。 | LiteOS-M | 1.1.0 LTS | 
| [定时器](https://growing.openharmony.cn/mainPlay/detail?sampleId=3723) | 此样例演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口进行定时器开发。 | LiteOS-M | 1.1.0 LTS |
| [事件](https://growing.openharmony.cn/mainPlay/detail?sampleId=3724) | 此样例演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口使用事件标志同步线程。 | LiteOS-M | 1.1.0 LTS |
| [互斥锁](https://growing.openharmony.cn/mainPlay/detail?sampleId=3725) | 此样例演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口使用互斥来同步任务。 | LiteOS-M | 1.1.0 LTS |
| [信号量](https://growing.openharmony.cn/mainPlay/detail?sampleId=3726) | 此样例演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口通过信号量同时从不同的线程访问共享资源。 | LiteOS-M | 1.1.0 LTS |
| [基于LYEVK-3861接入华为IoT平台](https://growing.openharmony.cn/mainPlay/detail?sampleId=3721) | 此样例是基于LYEVK-3861A IoT 开发套件开发，通过温湿度传感器模块获取温度，并上传华为云服务器。 | LiteOS-M | 3.0 LTS |
| [Pegasus智能家居套件样例开发--PWM（pwm_beer）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3755) | 此样例使用润和软件Pegasus Wi-Fi IoT智能家居套件中的蜂鸣器播放两只老虎音乐。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--oled_player](https://growing.openharmony.cn/mainPlay/detail?sampleId=3756) | 此样例使用润和软件Pegasus Wi-Fi IoT智能家居套件中的OLED屏，播放视频。 | LiteOS-M | 1.0.1 LTS</br>3.0 LTS |
| [Pegasus智能家居套件样例开发--等待（Delay）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3759) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行OS延时开发。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--互斥锁（Mutex）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3760) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行互斥锁开发。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--软定时器（Timer）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3758) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行定时器开发。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--信号量（Semaphore）](https://growing.openharmony.cn/mainPlay/detail?sampleId=3761) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行信号量开发。| LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--线程](https://growing.openharmony.cn/mainPlay/detail?sampleId=3757) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行线程开发。| LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--消息队列](https://growing.openharmony.cn/mainPlay/detail?sampleId=3762) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行消息队列开发。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [Pegasus智能家居套件样例开发--IO控制](https://growing.openharmony.cn/mainPlay/detail?sampleId=3763) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上使用cmsis 2.0 接口进行IO口控制开发。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [串口通信实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3790) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上实现串口通信。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS |
| [基于LYEVK-3861 接入华为IoT平台](https://growing.openharmony.cn/mainPlay/detail?sampleId=3721) | 本样例是基于LYEVK-3861A IoT 开发套件开发，通过温湿度传感器模块获取温度，并上传华为云服务器。 | LiteOS-M | 3.0 LTS |



 **表 4** 智慧出行场景Demo示例
| 示例 | 简介 | 系统 | OpenHarmony版本 | 
| -------- | -------- | -------- | ------ |
| [智慧停车](https://growing.openharmony.cn/mainPlay/detail?sampleId=3720) | 此样例是基于LYEVK-3861A IoT 开发套件开发，通过获取光照强度变化感知是否有车停放。 | LiteOS-M | 3.0 LTS | 
| [智能交通灯](https://growing.openharmony.cn/mainPlay/detail?sampleId=3792) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上实现智能交通灯实验。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS | 



 **表 5** 智慧办公Demo示例
| 示例 | 简介 | 系统 | OpenHarmony版本 | 
| -------- | -------- | -------- | ------ |
| [蓝牙键盘](https://growing.openharmony.cn/mainPlay/detail?sampleId=3700) | 此样例是基于润和Neptune开发板开发的蓝牙键盘开发样例，搭配USB转串口模块，实现有线键盘转成蓝牙键盘的功能。 | LiteOS-M | 1.1.0 LTS | 
| [TCP客户端实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3797) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上完成TCP客户端实验。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS | 
| [TCP服务端实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3798) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上完成TCP服务端实验。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS | 
| [UDP客户端实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3799) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上完成UDP客户端实验。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS | 
| [UDP服务端实验](https://growing.openharmony.cn/mainPlay/detail?sampleId=3800) | 此样例演示如何在Pegasus Wi-Fi IoT智能家居套件上完成UDP服务端实验。 | LiteOS-M | 1.0.1 LTS<br>3.0 LTS | 