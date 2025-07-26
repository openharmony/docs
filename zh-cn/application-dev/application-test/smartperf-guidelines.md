# SmartPerf Device性能工具使用指导

## 工具简介

SmartPerf Device是一款基于系统开发的性能功耗测试工具，操作简单易用。该工具可以监测性能、功耗相关指标，包括FPS、CPU、GPU、RAM、Temp等，通过量化的指标项了解应用、整机性能状况。

在开发过程中，会使用到有屏或无屏设备，对此SmartPerf Device提供了两种方式：分别是Device-hap端和Device-daemon端。Device-hap端适用于有屏设备，支持可视化操作。测试时是通过悬浮窗的开始和暂停来实时展示性能指标数据，保存后可生成数据报告，在报告中可分析各指标数据详情。Device-daemon端支持shell命令行方式，同时适用于有屏和无屏设备。

### 指标说明

- CPU：每秒读取一次设备节点下CPU大中小核的频点和各核使用率，衡量应用占用CPU资源的情况，占用过多的CPU资源会导致芯片发烫。
- GPU：每秒读取一次设备节点下GPU的频点和负载信息，衡量应用占用GPU资源的情况，当GPU占用过多时，会导致性能下降，应用程序的运行速度变慢。
- FPS：应用界面每秒刷新次数，衡量应用画面的流畅度，FPS越高通常表示图像流畅度越好，用户体验也越好。
- TEMP：每秒读取一次设备节点下GPU温度、系统芯片温度信息。
- RAM：每秒读取一次应用进程的实际物理内存，衡量应用的内存占比情况。
- snapshot：每2秒截取一张应用界面截图。

## 实现原理

下图展示了SmartPerf Device工具的主要功能组成。Device-hap端设置好采集项和采集参数后，启动应用，FPS、RAM、Trace等指标通过消息发送给Device-daemon端，Device-daemon端进行数据采集、持久化和数据分析，将生成的报告回传给Device-hap端，Device-hap端进行可视化显示。

![图片说明](figures/SmartPerfStru.png)

## 约束与限制

1. Device-daemon端<!--Del-->、Device-hap端<!--DelEnd-->在API 9版本开始预置使用。<!--RP1--><!--RP1End-->

2. Device-daemon端执行需连接硬件设备，Device-hap端需在有屏幕设备使用。

3. <!--RP2-->Device-daemon端执行前需完成[hdc环境配置](https://gitee.com/openharmony/developtools_hdc)。<!--RP2End--> 

<!--RP3-->
## SmartPerf Device-hap端

下面的操作步骤和界面内容以RK3568设备为例。

### 获取应用列表

点击设备上"SmartPerf Device-hap端"应用图标，进入"首页"，点击"请选择一个应用"，在应用列表页选择需要测试的应用。

![图片说明](figures/SmartPerfConfig1.png)
![图片说明](figures/SmartPerfConfig2.png)
![图片说明](figures/SmartPerfConfig3.png)

### 设置采集参数

应用选择完成后回到开始测试页面，根据实际业务需要，配置"测试指标"。同时，可修改测试名称（测试名称包含测试的应用名称和测试时间，会呈现在报告列表中），是否抓取trace，选择是否开启截图。配置完成后，点击底部"开始测试"按钮。

### 悬浮窗控制采集

点击悬浮窗"start"开始采集，点击悬浮窗"计时器"（如下图中00:07）暂停采集。再次点击"计时器"，继续开始采集。双击"计时器"，实时展示采集数据。长按"计时器"，结束采集。<br>整个过程中，可拖动悬浮框调整悬浮框位置。

![图片说明](figures/SmartPerfControl1.png)
![图片说明](figures/SmartPerfControl2.png)

### 查看报告

点击"报告"，查看测试报告列表。点击项目，进入报告详情页，查看测试指标项详情。

![图片说明](figures/SmartPerfReport1.png)
![图片说明](figures/SmartPerfReport2.png)

## SmartPerf Device-daemon端

### 采集前提

#### 进入shell

  ```
  C:\Users\issusser>hdc shell
  $
  ```

#### 拉起和查看daemon进程

  ```
  C:\Users\issusser>hdc shell
  // 拉起daemon进程
  $ SP_daemon 
  // 查看daemon进程是否存在
  $ ps -ef | grep SP_daemon
  shell          1584     1 0 21:50:05 ?     00:00:00 SP_daemon
  shell          1595  1574 3 21:51:02 pts/0 00:00:00 grep SP_daemon
  $
  ```

#### 执行和查看帮助命令

  ```
  $ SP_daemon --help
  OpenHarmony performance testing tool SmartPerf command-line version
   Usage: SP_daemon [options] [arguments]
    
   options:
    -N              set the collection times(default value is 0) range[1,2147483647], for example: -N 10
    -PKG            set package name, must add, for example: -PKG ohos.samples.ecg
    -PID            set process pid, must add, for example: -PID 3568
    -threads        get threads, must add -PID or -PKG for example:
                    -threads -PID 3568 or -threads -PKG ohos.samples.ecg
    -fds            get file descriptor, must add -PID or -PKG for example:
                    -fds -PID 3568 or -fds -PKG ohos.samples.ecg
    -c              get device CPU frequency and CPU usage, process CPU usage and CPU load ..
    -ci             get cpu instructions and cycles
    -g              get device GPU frequency and GPU load
    -f              get app refresh fps(frames per second) and fps jitters and refreshrate
    -profilerfps    get refresh fps and timestamp
    -sections       set collection time period(using with profilerfps)
    -t              get remaining battery power and temperature..
    -p              get battery power consumption and voltage(Not supported by some devices)
    -print          start mode print log
    -r              get process memory and total memory
    -snapshot       get screen capture
    -net            get uplink and downlink traffic
    -start          collection start command
    -stop           collection stop command
    -VIEW           set layler, for example: -VIEW DisplayNode
    -OUT            set csv output path.
    -d              get device DDR information
    -screen         get screen resolution
    -deviceinfo     get device information
    -server         start a process to listen to the socket message of the start and stop commands
    -clear          clear the process ID
    -ohtestfps      used by the validator to obtain the fps, the collection times can be set
    -editorServer   start a process to listen to the socket message of the editor
    -recordcapacity get the battery level difference
    --version       get version
    --help          get help
    -editor         scenario-based collection identifier, parameter configuration items can be added later
    responseTime   get the page response delay after an application is operated
    completeTime   get the page completion delay after an application is operated
    fpsohtest      used by the validator to obtain the fps
    example1:
    SP_daemon -N 20 -c -g -t -p -r -net -snapshot -d
    SP_daemon -N 20 -PKG ohos.samples.ecg -c -g -t -p -f -r -net -snapshot -d
    SP_daemon -start -c
    SP_daemon -stop
    example2: These parameters need to be used separately
    SP_daemon -screen
    SP_daemon -deviceinfo
    SP_daemon -server
    SP_daemon -clear
    SP_daemon -ohtestfps 10
    SP_daemon -editorServer
    SP_daemon -recordcapacity
    example3: These parameters need to be used separately
    SP_daemon -editor responseTime ohos.samples.ecg app name
    SP_daemon -editor completeTime ohos.samples.ecg app name
    SP_daemon -editor fpsohtest
    
    
    
    command exec finished!
   $
  ```

### 基础采集

#### 通过-N开启采集

| 命令参数   |必选| 说明                   |
| :-----| :-----| :--------------------- |
| -N    |是| 设置采集次数，一秒采集一次。    |
| -PKG  |否| 设置包名。                |
| -PID  |否| 设置进程ID或者线程ID。                |
| -threads  |否| 采集应用子线程数量。                |
| -fds  |否| 采集应用文件描述符，仅支持root用户采集。                |
| -c    |否| 采集cpu的频点和使用率。<br>设置应用包名时，采集整机和应用CPU信息。 <br>不设置应用包名时，采集整机CPU信息。     |
| -ci    |否| 采集cpu的指令数。<br>设置应用包名时，采集整机和应用CPU指令数。 <br>不设置应用包名时，采集整机CPU指令数。     |
| -g    |否| 采集gpu的频点和负载信息。   |
| -f    |否| 采集指定应用的fps以及屏幕刷新率，必须设置应用包名。        |
| -t    |否| 采集GPU温度、系统芯片温度。           |
| -r    |否| 采集内存。<br>设置应用包名时，采集整机和应用内存信息。 <br>不设置应用包名时，采集整机内存信息。             |
| -snapshot |否| 屏幕截图。             |
| -net |否| 采集网络速率。              |
| -VIEW |否| 设置图层，需要先获取应用图层名。                |
| -d    |否| 采集DDR。                 |
| -sections|否| 设置分段采集。          |

##### 使用示例
- 设置包名并采集1次应用的线程数量

  ```
    $ SP_daemon -N 1 -PKG ohos.samples.ecg -threads
 
    order:0 timestamp=1741415592481
    order:1 threadsNum=18847:113|
    order:2 tids=18847:43411 43409 43350 43236 25783 25622 25384 25381 19423 19170 19167 19166 19165 19163 19162 19159 19157 19156 19154 19153 19152 19151 19150 19149 19147 19146 19145 19142 19141 19140 19139 19136 19135 19134 19120 19112 19111 19088 19083 19081 19077 19076 19075 19074 19073 19072 19071 19070 19055 19044 19040 19039 19034 19033 19032 19031 19030 19029 19028 19027 19019 19017 19016 19015 19014 19013 19012 19011 19009 19007 19006 19005 19004 19003 19001 19000 18999 18998 18997 18996 18995 18994 18993 18992 18991 18990 18989 18988 18987 18986 18985 18984 18983 18982 18981 18980 18977 18974 18946 18942 18936 18934         18933 18931 18930 18929 18928 18927 18926 18925 18924 18923 18847|
 
    command exec finished!
    $
  ```

- 采集2次整机CPU大中小核频率、各核使用率

  ```
    $ SP_daemon -N 2 -c

    order:0 timestamp=1501839064260
    order:1 TotalcpuUsage=0.502513
    order:2 TotalcpuidleUsage=99.497487
    order:3 TotalcpuioWaitUsage=0.000000
    order:4 TotalcpuirqUsage=0.000000
    order:5 TotalcpuniceUsage=0.000000
    order:6 TotalcpusoftIrqUsage=0.000000
    order:7 TotalcpusystemUsage=0.251256
    order:8 TotalcpuuserUsage=0.251256
    order:9 cpu0Frequency=1992000
    order:10 cpu0Usage=1.000000
    order:11 cpu0idleUsage=99.000000
    order:12 cpu0ioWaitUsage=0.000000
    order:13 cpu0irqUsage=0.000000
    order:14 cpu0niceUsage=0.000000
    order:15 cpu0softIrqUsage=0.000000
    order:16 cpu0systemUsage=0.000000
    order:17 cpu0userUsage=1.000000
    order:18 cpu1Frequency=1992000
    order:19 cpu1Usage=0.000000
    order:20 cpu1idleUsage=100.000000
    order:21 cpu1ioWaitUsage=0.000000
    order:22 cpu1irqUsage=0.000000
    order:23 cpu1niceUsage=0.000000
    order:24 cpu1softIrqUsage=0.000000
    order:25 cpu1systemUsage=0.000000
    order:26 cpu1userUsage=0.000000
    order:27 cpu2Frequency=1992000
    order:28 cpu2Usage=1.000000
    order:29 cpu2idleUsage=99.000000
    order:30 cpu2ioWaitUsage=0.000000
    order:31 cpu2irqUsage=0.000000
    order:32 cpu2niceUsage=0.000000
    order:33 cpu2softIrqUsage=0.000000
    order:34 cpu2systemUsage=1.000000
    order:35 cpu2userUsage=0.000000
    order:36 cpu3Frequency=1992000
    order:37 cpu3Usage=0.000000
    order:38 cpu3idleUsage=100.000000
    order:39 cpu3ioWaitUsage=0.000000
    order:40 cpu3irqUsage=0.000000
    order:41 cpu3niceUsage=0.000000
    order:42 cpu3softIrqUsage=0.000000
    order:43 cpu3systemUsage=0.000000
    order:44 cpu3userUsage=0.000000

    ...

    command exec finished!
    $
  ```

- 设置包名并采集2次整机CPU大中小核频率、各核使用率以及进程CPU使用率、负载

  ```
    $ SP_daemon -N 2 -PKG ohos.samples.ecg -c



    order:0 timestamp=1741415021814
    order:1 ChildProcCpuLoad=NA
    order:2 ChildProcCpuUsage=NA
    order:3 ChildProcId=NA
    order:4 ChildProcSCpuUsage=NA
    order:5 ChildProcUCpuUsage=NA
    order:6 ProcAppName=ohos.samples.ecg
    order:7 ProcCpuLoad=2.742330
    order:8 ProcCpuUsage=7.825508
    order:9 ProcId=18847
    order:10 ProcSCpuUsage=2.014652
    order:11 ProcUCpuUsage=5.810856
    order:12 TotalcpuUsage=22.527016
    order:13 TotalcpuidleUsage=77.472984
    order:14 TotalcpuioWaitUsage=0.000000
    order:15 TotalcpuirqUsage=0.083126
    order:16 TotalcpuniceUsage=0.000000
    order:17 TotalcpusoftIrqUsage=0.000000
    order:18 TotalcpusystemUsage=7.148795
    order:19 TotalcpuuserUsage=15.295096
    order:20 cpu0Frequency=1430000
    order:21 cpu0Usage=52.475248
    order:22 cpu0idleUsage=47.524752
    order:23 cpu0ioWaitUsage=0.000000
    order:24 cpu0irqUsage=0.000000

    ...

    command exec finished!
    $
  ```

- 设置进程ID并采集2次整机CPU大中小核频率、各核使用率以及进程CPU使用率、负载

  ```
    $ SP_daemon -N 2 -PID 18847 -c
 
 
 
    order:0 timestamp=1741415133211
    order:1 ChildProcCpuLoad=NA
    order:2 ChildProcCpuUsage=NA
    order:3 ChildProcId=NA
    order:4 ChildProcSCpuUsage=NA
    order:5 ChildProcUCpuUsage=NA
    order:6 ProcAppName=ohos.samples.ecg
    order:7 ProcCpuLoad=2.510634
    order:8 ProcCpuUsage=7.005678
    order:9 ProcId=18847
    order:10 ProcSCpuUsage=2.697061
    order:11 ProcUCpuUsage=4.308617
    order:12 TotalcpuUsage=24.979114
    order:13 TotalcpuidleUsage=75.020886
    order:14 TotalcpuioWaitUsage=0.000000
    order:15 TotalcpuirqUsage=0.083542
    order:16 TotalcpuniceUsage=0.000000
    order:17 TotalcpusoftIrqUsage=0.000000
    order:18 TotalcpusystemUsage=8.270677
    order:19 TotalcpuuserUsage=16.624896
    order:20 cpu0Frequency=1430000
    order:21 cpu0Usage=50.000000
    order:22 cpu0idleUsage=50.000000
    order:23 cpu0ioWaitUsage=0.000000
    order:24 cpu0irqUsage=0.000000
    ...
    command exec finished!
    $
  ```
  >**说明**
  >
  >- 使用该命令采集时需进入被测应用内。

- 采集1次整机GPU频率和负载
 
  ```
    $ SP_daemon -N 1 -g
    
    
    
    order:0 timestamp=1503078740268
    order:1 gpuFrequency=200000000
    order:2 gpuLoad=38.000000
    
    command exec finished!
    $
  ```

- 采集2次整机温度

  ```
    $ SP_daemon -N 2 -t

    order:0 timestamp=1502720711191
    order:1 gpu-thermal=42500.000000
    order:2 soc-thermal=43.125000
    
    
    order:0 timestamp=1502720712191
    order:1 gpu-thermal=41875.000000
    order:2 soc-thermal=42.500000

    command exec finished!
    $
  ```

- 采集2次整机内存

  ```
    $ SP_daemon -N 2 -r
    order:0 timestamp=1705041562521
    order:1 memAvailable=7339224
    order:2 memFree=7164708
    order:3 memTotal=11641840

    order:0 timestamp=1705041563527
    order:1 memAvailable=7339136
    order:2 memFree=7164684
    order:3 memTotal=11641840

    command exec finished!
    $
  ```

- 设置包名并采集1次整机和指定应用进程内存

  ```
    $ SP_daemon -N 1 -PKG ohos.samples.ecg -r
 
 
 
    order:0 timestamp=1741415257059
    order:1 arktsHeapPss=44835
    order:2 childCarktsHeapPss=NA
    order:3 childGpuPss=NA
    order:4 childGraphicPss=NA
    order:5 childHeapAlloc=NA
    order:6 childHeapFree=NA
    order:7 childHeapSize=NA
    order:8 childNativeHeapPss=NA
    order:9 childPrivateClean=NA
    order:10 childPrivateDirty=NA
    order:11 childPss=NA
    order:12 childSharedClean=NA
    order:13 childSharedDirty=NA
    order:14 childStackPss=NA
    order:15 childSwap=NA
    order:16 childSwapPss=NA
    order:17 gpuPss=222377
    order:18 graphicPss=184276
    order:19 heapAlloc=154696
    order:20 heapFree=780
    order:21 heapSize=163208
    order:22 memAvailable=4612096
    order:23 memFree=1240924
    order:24 memTotal=11692696
    order:25 nativeHeapPss=85290
    order:26 privateClean=195816
    order:27 privateDirty=418973
    order:28 pss=693349
    order:29 sharedClean=146848
    order:30 sharedDirty=71056
    order:31 stackPss=2492
    order:32 swap=25360
    order:33 swapPss=25356

    command exec finished!
    $
  ```

- 设置进程ID并采集1次整机和指定应用进程内存

  ```
    $ SP_daemon -N 1 -PID 18847 -r
 
 
 
    order:0 timestamp=1741415293198
    order:1 arktsHeapPss=45011
    order:2 childCarktsHeapPss=NA
    order:3 childGpuPss=NA
    order:4 childGraphicPss=NA
    order:5 childHeapAlloc=NA
    order:6 childHeapFree=NA
    order:7 childHeapSize=NA
    order:8 childNativeHeapPss=NA
    order:9 childPrivateClean=NA
    order:10 childPrivateDirty=NA
    order:11 childPss=NA
    order:12 childSharedClean=NA
    order:13 childSharedDirty=NA
    order:14 childStackPss=NA
    order:15 childSwap=NA
    order:16 childSwapPss=NA
    order:17 gpuPss=222381
    order:18 graphicPss=184276
    order:19 heapAlloc=154588
    order:20 heapFree=757
    order:21 heapSize=163184
    order:22 memAvailable=4612096
    order:23 memFree=1238420
    order:24 memTotal=11692696
    order:25 nativeHeapPss=85274
    order:26 privateClean=195996
    order:27 privateDirty=418977
    order:28 pss=693440
    order:29 sharedClean=146848
    order:30 sharedDirty=71056
    order:31 stackPss=2492
    order:32 swap=25360
    order:33 swapPss=25356

    command exec finished!
    $
  ```
  >**说明**
  >
  >- 使用该命令采集时需进入被测应用内。
  >- 该命令集成了历史版本-m的数据（arktsHeapPss、gpuPss、graphicPss...）。

- 采集1次整机cpu指令数

  ```
    $ SP_daemon -N 1 -ci

    order:0 cycles per instruction=4.098151
    order:1 hw-cpu-cycles=190604622.000000
    order:2 hw-instructions=46509906.000000
    order:3 timestamp=1609502927840
    command exec finished!
    $
  ```

- 设置包名并采集1次整机和指定应用cpu指令数

  ```
    $ SP_daemon -N 1 -PKG ohos.samples.ecg -ci

    order:0 cycles per instruction=4.121963
    order:1 hw-cpu-cycles=190092457.000000
    order:2 hw-instructions=46116973.000000
    order:3 timestamp=1609502995191
    command exec finished!
    $
  ```
  >**说明**
  >
  >- 使用该命令采集时需进入被测应用内。

- 采集2次截图

  ```
    $ SP_daemon -N 2 -snapshot

    order:0 timestamp=1501837609657
    order:1 capture=data/local/tmp/capture/screenCap_1501837609657.png
    
    
    order:0 timestamp=1501837610657
    order:1 capture=NA

    command exec finished!
    $
  ```
  >**说明**
  >
  >- 截图采集是2秒截取一次。
  >
  >- 截图报告存放路径为：data/local/tmp/capture。
  >
  >- 采集结束后：进入 data/local/tmp/capture 查看生成的截图。
  >
  >- 导出截图到D盘：重启一个命令行工具执行命令： hdc file recv data/local/tmp/capture/screenCap_1700725192774.png D:\。

- 采集2次网络速率

  ```
    $ SP_daemon -N 2 -net

    order:0 timestamp=1705041904832
    order:1 networkDown=0
    order:2 networkUp=0

    order:0 timestamp=1705041905870
    order:1 networkDown=22931
    order:2 networkUp=2004

    command exec finished!
    $
  ```

- 设置包名并采集5次指定应用帧率

  ```
    $ SP_daemon -N 5 -PKG ohos.samples.ecg -f

    order:0 timestamp=1705306472232
    order:1 fps=43
    order:2 fpsJitters=602261688;;8352083;;8267708;;8305209;;8298437;;8308854;;8313542;;8569271;;8061458;;8300521;;8308333;;8309896;;8429167;;8241667;;8258333;;8318229;;8312500;;8304167;;41760937;;16418750;;8298959;;8319270;;8308334;;8313541;;8302605;;8320312;;8298958;;8326042;;8321354;;8301042;;8310417;;8309895;;8308855;;8331250;;8286458;;8343229;;8278125;;8311458;;8306250;;8312500;;8320834;;8346875;;8283333
    order:3 refreshrate=69

    order:0 timestamp=1705306473234
    order:1 fps=40
    order:2 fpsJitters=674427313;;8191145;;8310417;;8319271;;8301562;;8318750;;8302084;;8314062;;8333334;;8283854;;8307812;;8311979;;8310417;;8307813;;8309375;;8323958;;8306250;;8308333;;8317709;;8296875;;8721875;;7895833;;8320833;;8340625;;8276563;;8409896;;8216145;;8310938;;8301042;;8362500;;8252604;;8317708;;8376042;;8256250;;8292187;;8303125;;8313542;;8310417;;8520312
    order:3 refreshrate=69
    ...

    command exec finished!
    $
  ```
 
- 采集10次指定图层帧率

  ```
    $ SP_daemon -N 10 -VIEW DisplayNode -f
    order:0 timestamp=1705306822850
    order:1 fps=15
    order:2 fpsJitters=876291843;;8314062;;8308334;;8314583;;8310417;;8308333;;8326042;;8314583;;8292708;;8492709;;8143750;;8340104;;8294271;;8302604;;8297396
    order:3 refreshrate=69
 
    order:0 timestamp=1705306823852
    order:1 fps=12
    order:2 fpsJitters=906667363;;8279167;;8311458;;8315625;;8291146;;8313021;;8323438;;8293750;;8303125;;8313541;;8301563;;8317708
    order:3 refreshrate=69
    ...

    command exec finished!
    $
  ```
  >**说明**
  >
  >- DisplayNode 是指定的图层名。
  >
  >- 使用该命令采集时，需在传入的图层上操作页面。
  >
  >- 该命令不能与指定应用帧率一起采集（SP_daemon -N 20 -PKG ohos.samples.ecg -f 或 SP_daemon -N 20 -VIEW DisplayNode -f）。

- 采集1次DDR信息

  ```
    $ SP_daemon -N 1 -d
    
    order:0 timestamp=1710916175201
    order:1 ddrFrequency=1531000000
    
    command exec finished!
    $
  ```

- 全量采集示例1，采集整机信息，包括cpu、gpu、温度、内存信息、DDR信息、网络速率、屏幕截图
 
  ```
    $ SP_daemon -N 10 -c -g -t -r -d -net -snapshot

    order:0 timestamp=1501837838664
    order:1 TotalcpuUsage=0.751880
    order:2 TotalcpuidleUsage=99.248120
    order:3 TotalcpuioWaitUsage=0.000000
    order:4 TotalcpuirqUsage=0.000000
    order:5 TotalcpuniceUsage=0.000000
    order:6 TotalcpusoftIrqUsage=0.000000
    order:7 TotalcpusystemUsage=0.501253
    order:8 TotalcpuuserUsage=0.250627
    order:9 cpu0Frequency=1992000
    order:10 cpu0Usage=0.000000
    order:11 cpu0idleUsage=100.000000
    order:12 cpu0ioWaitUsage=0.000000
    order:13 cpu0irqUsage=0.000000
    order:14 cpu0niceUsage=0.000000
    order:15 cpu0softIrqUsage=0.000000
    order:16 cpu0systemUsage=0.000000
    order:17 cpu0userUsage=0.000000
    order:18 cpu1Frequency=1992000
    order:19 cpu1Usage=0.000000
    order:20 cpu1idleUsage=100.000000
    order:21 cpu1ioWaitUsage=0.000000
    order:22 cpu1irqUsage=0.000000
    order:23 cpu1niceUsage=0.000000
    order:24 cpu1softIrqUsage=0.000000
    order:25 cpu1systemUsage=0.000000
    order:26 cpu1userUsage=0.000000
    order:27 cpu2Frequency=1992000
    order:28 cpu2Usage=1.000000
    order:29 cpu2idleUsage=99.000000
    order:30 cpu2ioWaitUsage=0.000000
    order:31 cpu2irqUsage=0.000000
    order:32 cpu2niceUsage=0.000000
    order:33 cpu2softIrqUsage=0.000000
    order:34 cpu2systemUsage=1.000000
    order:35 cpu2userUsage=0.000000
    order:36 cpu3Frequency=1992000
    order:37 cpu3Usage=0.000000
    order:38 cpu3idleUsage=100.000000
    order:39 cpu3ioWaitUsage=0.000000
    order:40 cpu3irqUsage=0.000000
    order:41 cpu3niceUsage=0.000000
    order:42 cpu3softIrqUsage=0.000000
    order:43 cpu3systemUsage=0.000000
    order:44 cpu3userUsage=0.000000
    order:45 gpuFrequency=200000000
    order:46 gpuLoad=0.000000
    order:47 gpu-thermal=40000.000000
    order:48 soc-thermal=40.625000
    order:49 memAvailable=1142820
    order:50 memFree=687988
    order:51 memTotal=1935948
    order:52 ddrFrequency=800000000
    order:53 networkDown=0
    order:54 networkUp=0
    order:55 capture=data/local/tmp/capture/screenCap_1501837838669.png

    ...

    command exec finished!
    $
  ```

- 全量采集示例2，设置包名并采集指定应用信息，包括cpu、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图
 
  ```
    $ SP_daemon -N 10 -PKG ohos.samples.ecg -c -g -t -f -r -d -net -snapshot -threads
    
    order:0 timestamp=1741415955626
    order:1 ChildProcCpuLoad=NA
    order:2 ChildProcCpuUsage=NA
    order:3 ChildProcId=NA
    order:4 ChildProcSCpuUsage=NA
    order:5 ChildProcUCpuUsage=NA
    order:6 ProcAppName=ohos.samples.ecg
    order:7 ProcCpuLoad=2.641511
    order:8 ProcCpuUsage=6.026481
    order:9 ProcId=18847
    order:10 ProcSCpuUsage=1.747202
    order:11 ProcUCpuUsage=4.279279
    order:12 TotalcpuUsage=26.021798
    order:13 TotalcpuidleUsage=73.978202
    order:14 TotalcpuioWaitUsage=0.000000
    order:15 TotalcpuirqUsage=0.068120
    order:16 TotalcpuniceUsage=0.000000
    order:17 TotalcpusoftIrqUsage=0.000000
    order:18 TotalcpusystemUsage=10.762943
    order:19 TotalcpuuserUsage=15.190736
    ...
    order:123 gpuFrequency=279000000
    order:124 gpuLoad=0.000000
    order:125 Battery=35.000000
    order:126 cluster0=51.000000
    order:127 gpu=47.000000
    order:128 npu_thermal=35.000000
    order:129 shell_back=36.627000
    order:130 shell_frame=35.627000
    order:131 shell_front=35.652000
    order:132 soc_thermal=59.259000
    order:133 system_h=37.000000
    order:134 fps=30
    order:135 fpsJitters=33501562;;50251042;;33522396;;16743750;;33482812;;33505730;;33507291;;33505209;;33502604;;50258854;;33518229;;33501563;;16753125;;50247916;;16751563;;33507812;;16740104;;16792188;;33464583;;33497917;;50261458;;33493750;;33511459;;33502083;;16744271;;16756250;;33505729;;50254687;;33507292;;50286979
    order:136 refreshrate=60
    order:137 arktsHeapPss=29564
    order:138 gpuPss=254647
    order:139 graphicPss=215796
    order:140 heapAlloc=174032
    order:141 heapFree=1232
    order:142 heapSize=187924
    order:143 memAvailable=3437568
    order:144 memFree=780152
    order:145 memTotal=11697880
    order:146 nativeHeapPss=91244
    order:147 privateClean=162560
    order:148 privateDirty=488739
    order:149 pss=761908
    order:150 sharedClean=225060
    order:151 sharedDirty=48740
    order:152 stackPss=2596
    order:153 swap=62024
    order:154 swapPss=62024
    order:155 ddrFrequency=1531000000
    order:156 networkDown=215
    order:157 networkUp=0
    ...
    order:180 capture=data/local/tmp/capture/screenCap_1741415955811.png
    order:181 threadsNum=18847:111|
    order:182 tids=18847:45862 45700 25783 25622 25384 25381 19423 19170 19167 19166 19165 19163 19162 19159 19157 19156 19154 19153 19152 19151 19150 19149 19147 19146 19145 19142 19141 19140 19139 19136 19135 19134 19120 19112 19111 19088 19083 19081 19077 19076 19075 19074 19073 19072 19071 19070 19055 19044 19040 19039 19034 19033 19032 19031 19030 19029 19028 19027 19019 19017 19016 19015 19014 19013 19012 19011 19009 19007 19006 19005 19004 19003 19001 19000 18999 18998 18997 18996 18995 18994 18993 18992 18991 18990 18989 18988 18987 18986 18985 18984 18983 18982 18981 18980 18977 18974 18946 18942 18936 18934 18933 18931 18930 18929 18928 18927 18926 18925 18924 18923 18847|
    ...
    
    command exec finished!
    $
  ```

- 全量采集示例3，设置进程ID并采集指定应用信息，包括cpu、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图
 
  ```
    $ SP_daemon -N 10 -PID 18847 -c -g -t -f -r -d -net -snapshot -threads
    
    order:0 timestamp=1741416084766
    order:1 ChildProcCpuLoad=NA
    order:2 ChildProcCpuUsage=NA
    order:3 ChildProcId=NA
    order:4 ChildProcSCpuUsage=NA
    order:5 ChildProcUCpuUsage=NA
    order:6 ProcAppName=ohos.samples.ecg
    order:7 ProcCpuLoad=2.857003
    order:8 ProcCpuUsage=5.932203
    order:9 ProcId=18847
    order:10 ProcSCpuUsage=1.765537
    order:11 ProcUCpuUsage=4.166667
    order:12 TotalcpuUsage=28.442728
    order:13 TotalcpuidleUsage=71.557272
    order:14 TotalcpuioWaitUsage=0.000000
    order:15 TotalcpuirqUsage=0.000000
    order:16 TotalcpuniceUsage=0.000000
    order:17 TotalcpusoftIrqUsage=0.000000
    order:18 TotalcpusystemUsage=9.716860
    order:19 TotalcpuuserUsage=18.725869
    ...
    order:123 gpuFrequency=279000000
    order:124 gpuLoad=0.000000
    order:125 Battery=35.000000
    order:126 cluster0=51.000000
    order:127 gpu=47.000000
    order:128 npu_thermal=35.000000
    order:129 shell_back=36.627000
    order:130 shell_frame=35.627000
    order:131 shell_front=35.652000
    order:132 soc_thermal=59.259000
    order:133 system_h=37.000000
    order:134 fps=30
    order:135 fpsJitters=33501562;;50251042;;33522396;;16743750;;33482812;;33505730;;33507291;;33505209;;33502604;;50258854;;33518229;;33501563;;16753125;;50247916;;16751563;;33507812;;16740104;;16792188;;33464583;;33497917;;50261458;;33493750;;33511459;;33502083;;16744271;;16756250;;33505729;;50254687;;33507292;;50286979
    order:136 refreshrate=60
    order:137 arktsHeapPss=29564
    order:138 gpuPss=254647
    order:139 graphicPss=215796
    order:140 heapAlloc=174032
    order:141 heapFree=1232
    order:142 heapSize=187924
    order:143 memAvailable=3437568
    order:144 memFree=780152
    order:145 memTotal=11697880
    order:146 nativeHeapPss=91244
    order:147 privateClean=162560
    order:148 privateDirty=488739
    order:149 pss=761908
    order:150 sharedClean=225060
    order:151 sharedDirty=48740
    order:152 stackPss=2596
    order:153 swap=62024
    order:154 swapPss=62024
    order:155 ddrFrequency=1531000000
    order:156 networkDown=215
    order:157 networkUp=0
    ...
    order:180 capture=data/local/tmp/capture/screenCap_1741416084923.png
    order:181 threadsNum=18847:113|
    order:182 tids=18847:46736 46734 46731 46663 25783 25622 25384 25381 19423 19170 19167 19166 19165 19163 19162 19159 19157 19156 19154 19153 19152 19151 19150 19149 19147 19146 19145 19142 19141 19140 19139 19136 19135 19134 19120 19112 19111 19088 19083 19081 19077 19076 19075 19074 19073 19072 19071 19070 19055 19044 19040 19039 19034 19033 19032 19031 19030 19029 19028 19027 19019 19017 19016 19015 19014 19013 19012 19011 19009 19007 19006 19005 19004 19003 19001 19000 18999 18998 18997 18996 18995 18994 18993 18992 18991 18990 18989 18988 18987 18986 18985 18984 18983 18982 18981 18980 18977 18974 18946 18942 18936 18934 18933 18931 18930 18929 18928 18927 18926 18925 18924 18923 18847|
    ...
    
    command exec finished!
    $
  ```
  >**说明**
  >
  >- 使用该命令采集时需进入被测应用内。


#### 通过-start开启采集

先执行start开始采集命令，然后操作设备或应用，最后执行stop结束采集命令。

| 命令参数   |必选| 说明                   |
| :-----|:-----| :--------------------- |
| -start |是| 开始采集，该命令参数后可添加基础采集命令，一秒采集一次。            |
| -stop |是| 结束采集，执行后会生成采集报告。              |
| -print |否| 一秒打印一次启停采集信息。              |

##### 使用示例
  
- 启停采集整机CPU大中小核频率、各核使用率

   ```
   # 开始采集
   $ SP_daemon -start -c
   SP_daemon Collection begins
    
    
   command exec finished!
   $
      
   # 结束采集
   $ SP_daemon -stop
   SP_daemon Collection ended
   Output Path: data/local/tmp/smartperf/1/t_index_info.csv
    
    
   command exec finished!
   $
   ```

- 启停采集并打印整机CPU大中小核频率、各核使用率

   ```
    # 开始采集
    # 打印启停采集信息
    $ SP_daemon -start -c -print
    SP_daemon Collection begins
    
    order:0 TotalcpuUsage=20.860927
    order:1 TotalcpuidleUsage=79.139073
    order:2 TotalcpuioWaitUsage=0.000000
    order:3 TotalcpuirqUsage=0.082781
    order:4 TotalcpuniceUsage=0.000000
    order:5 TotalcpusoftIrqUsage=0.000000
    order:6 TotalcpusystemUsage=8.029801
    order:7 TotalcpuuserUsage=12.748344
    order:8 cpu0Frequency=1430000
    order:9 cpu0Usage=44.554455
    order:10 cpu0idleUsage=55.445545
    order:11 cpu0ioWaitUsage=0.000000
    order:12 cpu0irqUsage=0.000000
    order:13 cpu0niceUsage=0.000000
    order:14 cpu0softIrqUsage=0.000000
    order:15 cpu0systemUsage=17.821782
    order:16 cpu0userUsage=26.732673
    order:17 cpu10Frequency=1239000
    order:18 cpu10Usage=0.000000
    order:19 cpu10idleUsage=100.000000
    order:20 cpu10ioWaitUsage=0.000000
    order:21 cpu10irqUsage=0.000000
    order:22 cpu10niceUsage=0.000000
    order:23 cpu10softIrqUsage=0.000000
    order:24 cpu10systemUsage=0.000000
    order:25 cpu10userUsage=0.000000
    order:26 cpu11Frequency=1239000
    order:27 cpu11Usage=0.000000
    order:28 cpu11idleUsage=100.000000
    order:29 cpu11ioWaitUsage=0.000000
    order:30 cpu11irqUsage=0.000000
    order:31 cpu11niceUsage=0.000000
    order:32 cpu11softIrqUsage=0.000000
    order:33 cpu11systemUsage=0.000000
    order:34 cpu11userUsage=0.000000
    ...
    command exec finished!
    $
      
    # 结束采集
    # 在启停打印时，需重新开启命令框执行此命令
    $ SP_daemon -stop
    SP_daemon Collection ended
    Output Path: data/local/tmp/smartperf/1/t_index_info.csv
    
    command exec finished!
    $
   ```
   >**说明**
   >
   >- 开始采集示例1（采整机cpu、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图）：SP_daemon -start -c -g -t -r -d -net -snapshot。
   >
   >- 开始采集示例2（采整机和进程cpu负载、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图、线程数、文件描述符）：SP_daemon -start -PKG ohos.samples.ecg -c -g -t -f -r -d -net -snapshot -threads -fd。
   >
   >- 开始采集示例3（采整机和进程cpu负载、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图、线程数、文件描述符）：SP_daemon -start -PID 18847 -c -g -t -f -r -d -net -snapshot -threads -fd。
   >
   >- 开始采集示例4（采整机cpu、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图、线程数、文件描述符并且打印采集信息）：SP_daemon -start -c -g -t -r -d -net -snapshot -threads -fd -print。
   >
   >- 开始采集示例5（采整机和进程cpu负载、gpu、温度、fps、内存信息、DDR信息、网络速率、屏幕截图、线程数、文件描述符并且打印采集信息）：SP_daemon -start -PID 18847 -c -g -t -f -r -d -net -snapshot -threads -fd -print。
   >
   >- 启停服务文件输出路径为：data/local/tmp/smartperf/1/t_index_info.csv，可通过hdc file recv的方式导出查看报告。具体请参考[查看csv采集结果](#查看csv采集结果)。

#### 查看csv采集结果

若采集结果保存在csv文件中，可以按照如下操作导出和查看结果内容。

  - 采集结果默认输出路径：/data/local/tmp/data.csv

  - 查看文件位置

    ```
    C:\Users\issusser>hdc shell
    $ cd data/local/tmp
    # ls
    data.csv
    $
    ```

  - 导出文件
    ```
    C:\Users\issusser>hdc file recv data/local/tmp/data.csv D:\
    [I][2023-11-08 16:16:41] HdcFile::TransferSummary success
    FileTransfer finish, Size:429, File count = 1, time:6ms rate:71.50kB/s

    C:\Users\issusser>
    ```

  - 打开data.csv查看采集数据

    在自定义导出路径里找到data.csv文件打开查看采集数据表，data.csv数据名描述如下：

    | 数据项    | 说明             |备注|
    | :-----| :--------------------- |:-----|
    | threadsNum              | 线程总数。              |-|
    | tids                    | 线程id。                |-|
    | fdTotal                 | 文件描述符总数。         |-|
    | fds                     | 文件描述符。             |单位：Hz|
    | cpuFrequency            | CPU大中小核频率。        |单位：Hz|
    | cpuUasge                | CPU各核使用率。          |%|
    | cpuidleUsage            | CPU空闲态使用率。        |%| 
    | cpuioWaitUsage          | 等待I/O的使用率。        |%|
    | cpuirqUsage             | 硬中断的使用率。         |%|  
    | cpuniceUsage            | 低优先级用户态使用率。    |%|
    | cpusoftIrqUsage         | 软中断的使用率。         |%| 
    | cpusystemUsage          | 系统/内核态使用率。      |%|
    | cpuuserUsage            | 用户态使用率。           |%| 
    | ProcId                  | 进程id。                |-|
    | ChildProcId             | 子进程id。                |-|
    | ProcAppName             | app包名。                |-| 
    | ProcCpuLoad             | 进程CPU负载占比。        |%|
    | ChildProcCpuLoad        | 子进程CPU负载占比。        |%|
    | ProcCpuUsage            | 进程CPU使用率。          |%| 
    | ChildProcCpuUsage       | 子进程CPU使用率。          |%| 
    | ProcUCpuUsage           | 进程用户态CPU使用率。     |%|
    | ChildProcCpuUsage       | 子进程用户态CPU使用率。          |%| 
    | ProcSCpuUsage           | 进程内核态CPU使用率。     |%| 
    | ChildProcSCpuUsage      | 子进程内核态CPU使用率。     |%|
    | gpuFrequency            | 整机GPU的频率。          |%|
    | gpuLoad                 | 整机GPU的负载占比。      |%|
    | hw-instructions         | 执行的指令数。          |-|
    | cycles per instruction  | 每条指令的平均周期数。    |单位：ns|
    | hw-cpu-cycles           | CPU时钟周期数。          |单位：ns|
    | currentNow              | 当前读到的电流值。       |单位：mA| 
    | voltageNow              | 当前读到的电压值。       |单位：μV| 
    | fps                     | 每秒帧数。              |单位：fps|
    | fpsJitters              | 每一帧绘制间隔。        |单位：ns|
    | refreshrate             | 屏幕刷新率。            |单位：Hz|
    | networkDown             | 下行速率。              |单位：byte/s|
    | networkUp               | 上行速率。              |单位：byte/s|
    | ddrFrequency            | DDR频率。               |单位：Hz|
    | gpu-thermal             | GPU温度。              |单位：°C|
    | soc-thermal             | 系统芯片温度。          |单位：°C|
    | memAvailable            | 整机可用内存。         |单位：KB|
    | memFree                 | 整机空闲内存。         |单位：KB|
    | memTotal                | 整机总内存。           |单位：KB|
    | pss                     | 进程实际使用内存。      |单位：KB|
    | Childpss                | 子进程实际使用内存。      |单位：KB|
    | sharedClean             | 进程共享的未改写页面。      |单位：KB|
    | ChildsharedClean        | 子进程共享的未改写页面。      |单位：KB|
    | sharedDirty             | 进程共享的已改写页面。      |单位：KB|
    | ChildsharedDirty        | 子进程共享的已改写页面。      |单位：KB|
    | priviateClean           | 进程私有的未改写页面。      |单位：KB|
    | ChildpriviateClean      | 子进程私有的未改写页面。      |单位：KB|
    | privateDirty            | 进程私有的已改写页面。      |单位：KB|
    | ChildprivateDirty       | 子进程私有的已改写页面。      |单位：KB|
    | swapTotal               | 进程总的交换内存。          |单位：KB|
    | ChildswapTotal          | 子进程总的交换内存。          |单位：KB|
    | swapPss                 | 进程交换的pss内存。        |单位：KB|
    | ChildswapPss            | 子进程交换的pss内存。        |单位：KB|
    | HeapSize                | 进程堆内存大小。           |单位：KB|
    | ChildHeapSize           | 子进程堆内存大小。           |单位：KB|
    | HeapAlloc               | 进程可分配的堆内存大小。    |单位：KB|
    | ChildHeapAlloc          | 子进程可分配的堆内存大小。    |单位：KB|
    | HeapFree                | 进程剩余的堆内存大小。      |单位：KB|
    | ChildHeapFree           | 子进程剩余的堆内存大小。      |单位：KB|
    | gpuPss                  | 进程使用的gpu内存大小。     |单位：KB|
    | ChildgpuPss             | 子进程使用的gpu内存大小。     |单位：KB|
    | graphicPss              | 进程使用的图形内存大小。     |单位：KB|
    | ChildgraphicPss         | 子进程使用的图形内存大小。     |单位：KB|
    | arktsHeapPss            | 进程使用的arkts内存大小。    |单位：KB|
    | ChildarktsHeapPss       | 子进程使用的arkts内存大小。    |单位：KB|
    | nativeHeapPss           | 进程使用的native内存大小。   |单位：KB|
    | ChildnativeHeapPss      | 子进程使用的native内存大小。   |单位：KB|
    | stackPss                | 进程使用的栈内存大小。       |单位：KB|
    | ChildstackPss           | 子进程使用的栈内存大小。       |单位：KB|
    | timeStamp               | 当前时间戳。            |对应采集时间| 

### 场景化采集

除基本采集外，还支持采集响应和完成时延等内容。场景化采集结果不写入data.csv，采集结果直接在命令框显示。

| 命令参数   |必选| 说明                   |
| :-----|:-----| :--------------------- |
| -editor|是|    场景化采集标识，后可添加参数配置项。         |
| -responseTime|否|    响应时延。         |
| -completeTime|否|    完成时延。         |
| -fpsohtest|否|    validator用于获取fps，1秒采集一次，默认采集10次。       |

#### 使用示例

- 应用响应时延（命令仅支持RK）

  ```
   $ SP_daemon -editor responseTime ohos.samples.ecg ohtest
   time:544ms

   command exec finished!
  ```
  >**说明**
  >
  >- 采集前先进入应用内，在命令框回车后切换至应用内页面，等待打印采集结果。

- 应用完成时延（命令仅支持RK）

  ```
   $ SP_daemon -editor completeTime ohos.samples.ecg ohtest
   time:677ms

   command exec finished!
  ```
  >**说明**
  >
  >- 采集前先进入应用内，在命令框回车后切换至应用内页面，等待打印采集结果。

- validator获取应用页面帧率

  ```
   $ SP_daemon -editor fpsohtest
   set num:10 successfps:0|1726909713442fps:97|1726909714442fps:113|1726909715442fps:116|1726909716442fps:116|1726909717442fps:118|1726909718442fps:114|1726909719442fps:114|1726909720442fps:115|1726909721442fps:118|1726909722442SP_daemon exec finished!
  ```
  >**说明**
  >
  >- 执行命令后需滑动或切换当前页面，等待10s后打印采集结果。

### 其他采集

当前设备电量采集结果可写入csv文件，其它命令需单独采集，采集结果不写入data.csv，仅在命令框显示。

| 命令参数   |必选| 说明                   |
| :-----|:-----| :--------------------- |
| -screen |否| 采集屏幕分辨率和刷新率。               |
| -deviceinfo|否| 获取设备信息。              |
| -server|否|    启停采集用来拉起daemon进程。           |
| -clear|否|    清除所有SP_daemon进程。           |
| -ohtestfps|否|    validator用于获取fps，可设置采集次数（1秒采集一次）。          |
| -editorServer|否|    editor工具用来拉起daemon进程。         |
| -recordcapacity|否|    获取当前设备电量。         |
| -profilerfps |否| 采集当前界面fps。          |

#### 使用示例

- 获取屏幕分辨率

  ```
   $ SP_daemon -screen
   activeMode: 720x1280, refreshrate=69
    
    
   command exec finished!
   $
  ```
  >**说明**
  >
  >- activeMode表示当前屏幕分辨率，refreshrate表示屏幕刷新率。

- 获取设备信息

  ```
   $ SP_daemon -deviceinfo
   abilist: default
   activeMode: 720x1280
   board: hw
   brand: default
   cpu_c1_cluster: 0 1 2 3
   cpu_c1_max: 1992000
   cpu_c1_min: 408000
   cpu_cluster_name: policy0
   daemonPerfVersion: 1.0.5
   deviceTypeName: rk3568
   fullname: OpenHarmony-5.1.0.46
   gpu_max_freq: 800000000
   gpu_min_freq: 200000000
   model: ohos
   name: OpenHarmony 3.2
   sn: 150100424a5444345209d941bec6b900
   version: OpenHarmony 5.1.0.46
    
   command exec finished!
   $
  ```

- 启动一个进程来监听start和stop命令的socket消息

  ```
   $ SP_daemon -server
   $
   $ pidof SP_daemon
   7024
   $
  ```
  >**说明**
  >
  >- 可执行pidof SP_daemon查看进程id。

- 清除SP_daemon进程ID

  ```
   $ pidof SP_daemon
   2725   
   $ SP_daemon -clear
    
    
   command exec finished!
   $
   $ pidof SP_daemon
   $
  ```
  >**说明**
  >
  >- 可执行pidof SP_daemon查看进程id。

- validator用于获取当前页面帧率

  ```
   $ SP_daemon -ohtestfps 10
   set num:10 success
   fps:1|1501926684532
   fps:18|1501926685532
   fps:37|1501926686532
   fps:41|1501926687532
   fps:42|1501926688532
   fps:16|1501926689532
   fps:40|1501926690532
   fps:40|1501926691532
   fps:42|1501926692532
   fps:41|1501926693532
   SP_daemon exec finished!
   $
  ```
  >**说明**
  >
  >- 该条命令里的10表示采集的次数（一秒采集一次），可以设置为其他正整数。


- 启动一个进程来监听editor工具的socket消息

  ```
   $ SP_daemon -editorServer
    
    
   command exec finished!
  ```


- 获取电池电量

  ```
   $ SP_daemon -recordcapacity
   recordTime: 1726903063
   recordPower: 5502
  ```
  >**说明**
  >
  >- recordTime表示时间戳，recordPower表示当前时刻的电量。
  >
  >- 该命令需单独采集，采集结果写入/data/local/tmp/powerLeftRecord.csv，可以使用hdc file recv导出到本地。具体请参考[查看csv采集结果](#查看csv采集结果)。

- 采集当前界面fps

  ```
    $ SP_daemon -profilerfps 10
    set num:10 success
    fps:0|1711692357278
    fps:0|1711692358278
    fps:1|1711692359278
    fps:0|1711692360278
    fps:0|1711692361278
    fps:0|1711692362278
    fps:0|1711692363278
    fps:0|1711692364278
    fps:26|1711692365278
    fps:53|1711692366278
    SP_daemon exec finished!
    $
  ```
  >**说明**
  >
  >- 该条命令里的100表示采集的次数（一秒采集一次），可以设置为其他正整数。

- fps分段采集

  ```
    $ SP_daemon -profilerfps 100 -sections 10
    set num:100 success
    fps:0|1711692393278
    fps:0|1711692394278
    fps:0|1711692395278
    fps:44|1711692396278
    sectionsFps:0|1711692396278
    sectionsFps:0|1711692396378
    sectionsFps:40|1711692396478
    sectionsFps:60|1711692396578
    sectionsFps:60|1711692396678
    sectionsFps:60|1711692396778
    sectionsFps:60|1711692396878
    sectionsFps:40|1711692396978
    sectionsFps:60|1711692397078
    sectionsFps:60|1711692397178
    fps:51|1711692397278

    ...

    SP_daemon exec finished!
    $
  ```
  >**说明**
  >
  >- 该条命令里的100表示采集的次数（一秒采集一次），可以设置为其他正整数，10表示分段：目前支持设置 1-10（正整数）段采集。


<!--RP3End--> 