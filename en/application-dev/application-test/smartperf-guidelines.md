# SmartPerf User Guide

## Introduction

SmartPerf is a reliable, easy-to-use performance and power consumption test tool. In this tool, you can measure the performance and power consumption of your application with quantitative indicators, such as FPS, CPU, GPU, RAM, and Temp. Targeted at devices with or without screens, SmartPerf provides two modes: SmartPerf-Device and SmartPerf-Daemon. SmartPerf-Device is applicable to devices with screens and provides a visualized, intuitive UI that simplifies your operations. You can start and pause a test with a floating window and view performance data in real time. SmartPerf-Daemon is applicable to devices with and without screens and works with shell commands.

- CPU: The tool reads the frequencies and usage of CPU cores on the test device on a per second basis to measure the CPU usage of the target application. Sustained high CPU may lead to overheating.
- GPU: The tool reads the GPU frequency and load information of the test device on a per second basis to measure the GPU usage of the target application. High GPU usage can lead to performance drops and application slowdowns.
- DDR: The tool reads the DDR frequency information of the test device on a per second basis.
- FPS: The tool reads the frame rate, in frames per second (FPS), of the target application to measure the smoothness of the application image. A higher FPS generally means smoother visuals.
- POWER: The tool reads the current and voltage of the test device on a per second basis.
- TEMP: The tool reads the temperature information of the test device on a per second basis, including the SoC temperature. Abnormal temperature not only detracts from the user experience, but also poses safety risks.
- RAM: The tool reads the RAM usage of the target application on a per second basis.
- TRACE: When the frame drawing time exceeds 100 ms, the tool automatically captures the trace once per minute.
- Screenshot: The tool takes a screenshot of the application UI every second.

## Principles

The figure below demonstrates the main functions of SmartPerf. Set data collection items and parameters on SmartPerf-Device, start the application, and then send data requests for KPIs (such as FPS, RAM, and Trace) from SmartPerf-Device to SmartPerf-Daemon through messages. SmartPerf-Daemon collects, persists, and analyzes data as requested, and then sends the data to SmartPerf-Device for display.

![SmartPerf](figures/SmartPerfStru.png)

## Constraints

1. SmartPerf-Device and SmartPerf-Daemon are pre-installed since API version 9.

2. SmartPerf-Device can only be used on devices with a screen, and SmartPerf-Daemon must be connected to a hardware device.

3. Before using SmartPerf-Daemon, configure the [HDC environment](https://gitee.com/openharmony/developtools_hdc).

## Performing Performance Testing

### SmartPerf-Device

The RK3568 development board is used as an example below.

1. Obtain the application list and select an application.

Start SmartPerf-Device. On the home screen, select the target application.

2. Configure test settings.

After the target application is selected, return to the start page and set the test indicators. You can also change the test name (which includes the name of the target application and the test time and will be displayed in the report), and specify whether to capture traces and whether to enable the screenshot feature. When you are done, click the start button at the bottom.

3. Use the floating window to manage data collection.

To start collection, touch **Start** in the floating window. To pause, touch the timer in the floating window. To resume, touch the timer again. To view the collected data in real time, double-touch the timer. To stop, touch and hold the timer.<br>You can drag the floating window to anywhere you like.

![SmartPerfControl1](figures/SmartPerfControl1.png)


4. View test results.

Click **Report** to access the report list. Touch a report to view its details.

### SmartPerf-Daemon

**Commands**

| Command  | Function                  |Mandatory|
| :-----| :--------------------- |:-----|
| -N    | Set the number of collection times.            |Yes|
| -PKG  | Sets the bundle name.               | No|
| -PID  | Sets the PID of a process (applicable to RAM).|No|
| -c    | Sets whether to collect CPU data.            | No|
| -g    | Sets whether to collect GPU data.            |No|
| -f    | Sets whether to collect FPS data.            |No|
| -t    | Sets whether to collect temperature data.            |No|
| -p    | Sets whether to collect current data.            |No|
| -r    | Sets whether to collect memory data.            |No|

**Example**

1. Run the Win + R command to open the command-line interface (CLI).

```
C:\Users\issusser>hdc shell  // Example
#
```

2. Start the daemon process.

```
C:\Users\issusser>hdc shell
# SP_daemon
#
```

3. Check whether the daemon process is running.

```
C:\Users\issusser>hdc shell
# SP_daemon
# ps -ef | grep SP_daemon
root          1584     1 0 21:50:05 ?     00:00:00 SP_daemon
root          1595  1574 3 21:51:02 pts/0 00:00:00 grep SP_daemon
#
```

4. View the help information.

```
# SP_daemon --help
usage: SP_daemon <options> <arguments>
--------------------------------------------------------------------
These are common commands list:
 -N             set num of profiler <must be non-null>
 -PKG           set pkgname of profiler
 -PID           set process id of profiler
 -OUT           set output path of CSV
 -c             get cpuFreq and cpuLoad
 -g             get gpuFreq and gpuLoad
 -f             get fps and fps jitters
 -t             get soc-temp gpu-temp ..
 -p             get current_now and voltage_now
 -r             get ram(pss)
 -snapshot      get screen capture
--------------------------------------------------------------------
Example: SP_daemon -N 20 -PKG ohos.samples.ecg -c -g -t -p -f
--------------------------------------------------------------------


command exec finished!
#
```

5. Run the collection commands.

5.1 Collect twice the frequency and usage of CPU cores.

```
# SP_daemon -N 2 -PKG com.ohos.contacts -c

order:0 cpu0Frequency=1992000
order:1 cpu0Load=-1.000000
order:2 cpu1Frequency=1992000
order:3 cpu1Load=-1.000000
order:4 cpu2Frequency=1992000
order:5 cpu2Load=-1.000000
order:6 cpu3Frequency=1992000
order:7 cpu3Load=-1.000000
order:8 timestamp=1501941447968


order:0 cpu0Frequency=1416000
order:1 cpu0Load=43.000000
order:2 cpu1Frequency=1416000
order:3 cpu1Load=54.216866
order:4 cpu2Frequency=1416000
order:5 cpu2Load=30.851065
order:6 cpu3Frequency=1416000
order:7 cpu3Load=32.183907
order:8 timestamp=1501941448971

command exec finished!
#
```

5.2 Collect once the GPU frequency and load of the system.

```
# SP_daemon -N 1 -PKG com.ohos.contacts -g

order:0 gpuFrequency=200000000
order:1 gpuLoad=0.000000
order:2 timestamp=1501941537559

command exec finished!
#
```

5.3 Collect twice the system temperature.

```
# SP_daemon -N 2 -PKG com.ohos.contacts -t

order:0 gpu-thermal=40625
order:1 soc-thermal=42500
order:2 timestamp=1501941630698


order:0 gpu-thermal=40625
order:1 soc-thermal=41875
order:2 timestamp=1501941631703

command exec finished!
#
```

5.4 Collect once the current and voltage of the system.

```
# SP_daemon -N 1 -PKG com.ohos.contacts -p

order:0 currentNow=152
order:1 timestamp=1501941900574
order:2 voltageNow=3812359

command exec finished!
#
```

5.5 Collect once the memory information of the system.

- Check the PID.

  ```
  # ps -ef | grep com.ohos.contacts
  10005         1697   264 1 21:56:33 ?     00:00:03 com.ohos.contacts
  20010019      1721   264 0 21:56:33 ?     00:00:00 com.ohos.contactsdataability
  root          1889  1574 1 22:07:11 pts/0 00:00:00 grep com.ohos.contacts
  #
  ```
- Collect the memory information.

  ```
  # SP_daemon -N 1 -PID 1697 -r

  order:0 pss=48890
  order:1 timestamp=1501942183080

  command exec finished!
  #
  ```

5.6 Collect twice the CPU, GPU, device temperature, and current and voltage of the target application.

  ```
  # SP_daemon -N 2 -PKG com.ohos.contacts -c -g -t -p

  order:0 cpu0Frequency=1416000
  order:1 cpu0Load=-1.000000
  order:2 cpu1Frequency=1416000
  order:3 cpu1Load=-1.000000
  order:4 cpu2Frequency=1416000
  order:5 cpu2Load=-1.000000
  order:6 cpu3Frequency=1416000
  order:7 cpu3Load=-1.000000
  order:8 currentNow=119
  order:9 gpu-thermal=35000
  order:10 gpuFrequency=200000000
  order:11 gpuLoad=0.000000
  order:12 soc-thermal=36111
  order:13 timestamp=1501945516584
  order:14 voltageNow=3812635


  order:0 cpu0Frequency=408000
  order:1 cpu0Load=1.980198
  order:2 cpu1Frequency=408000
  order:3 cpu1Load=0.990099
  order:4 cpu2Frequency=408000
  order:5 cpu2Load=0.000000
  order:6 cpu3Frequency=408000
  order:7 cpu3Load=0.990099
  order:8 currentNow=111
  order:9 gpu-thermal=35000
  order:10 gpuFrequency=200000000
  order:11 gpuLoad=0.000000
  order:12 soc-thermal=35555
  order:13 timestamp=1501945517589
  order:14 voltageNow=3812408

  command exec finished!
  #
  ```

6. Export and view the collection results.

- By default, the collection results are saved to **/data/local/tmp/data.csv**.

- To check the path to the test result file:
  ```
  # cd data/local/tmp
  # ls
  data.csv
  #
  ```

- To export the test result file:
  ```
  hdc file recv data/local/tmp/data.csv D:\
  ```
  ```
  C:\Users\issusser>hdc file recv data/local/tmp/data.csv D:\
  [I][2023-11-08 16:16:41] HdcFile::TransferSummary success
  FileTransfer finish, Size:429, File count = 1, time:6ms rate:71.50kB/s

  C:\Users\issusser>
  ```

- Open the **data.csv** file to view data.

  The table below describes the data fields in the **data.csv** file.

  | Data Field   | Description            |Remarks|
  | :-----| :--------------------- |:-----|
  | cpuFrequ     | CPU frequency.       |Unit: Hz|
  | cpuLoad      | CPU load.    |%|
  | currentNow   | Current value. |Unit: mA|
  | fps          | Screen refresh rate.     |Unit: FPS|
  | fpsJitters   | Frame interval.   |Unit: ns|
  | gpuFrequ     | GPU frequency.        |Unit: Hz|
  | gpuLoad      | GPU load.    |%|
  | shell_front  | Front cover temperature.         |Unit: °C|
  | shell_frame  | Frame temperature.         |Unit: °C|
  | shell_back   | Rear cover temperature.         |Unit: °C|
  | soc_thermal  | SoC temperature.          |Unit: °C|
  | system_h     | System temperature.         |Unit: °C|
  | timeStamp    | Timestamp.       |Collection time.|
  | voltageNow   | Voltage value.  |Unit: μV|
