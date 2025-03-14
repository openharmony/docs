# Viewing HiTraceMeter Logs

## Viewing Logs on DevEco Studio

In CPU Insight of DevEco Studio Profiler, you can display HiTraceMeter logs for analyzing the CPU usage and thread running status of applications and services and viewing the CPU consumption in a specified period. For details, see [CPU Activity Analysis: CPU](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-insight-session-cpu-V5).

## Viewing Logs Using a Command Line Tool

1. Set up the environment for OpenHarmony Device Connector (hdc). For details, see [Environment Setup](hdc.md#environment-setup).

2. In the **Terminal** window of DevEco Studio or the CLI on the host, run the **hdc shell** command to connect to the device, and run the [hitrace](hitrace.md) command on the device to capture HiTraceMeter logs.

   ```shell
   PS D:\xxx\xxx> hdc shell
   # hitrace --trace_begin app
   ```

3. Run the program that enables HiTraceMeter logging on the device.

4. Dump the HiTraceMeter log file that contains the HiTraceMeter logging information in step 3.

   - Logs are printed in the window by default.

   ```shell
   # hitrace --trace_dump
   ```

   - You can create a file to save logs in the **/data/local/tmp/** directory (other directories are unavailable).

   ```shell
   # hitrace --trace_dump -o /data/local/tmp/trace.ftrace
   ```

5. Run the **hitrace** command on the device to stop capturing HiTraceMeter logs.

   ```shell
   # hitrace --trace_finish
   ```

6. Exit the device, enter the host, and export the HiTraceMeter logs to the current directory.

   ```shell
   # exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

7. You can search for keywords such as the logging name in the HiTraceMeter logs to check whether the logging is successful.

8. Display and analyze the HiTraceMeter logs.

   - In DevEco Studio Profiler, select **Open File** to import the HiTraceMeter logs for analysis. For details, see [CPU Activity Analysis: CPU](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-insight-session-cpu-V5).
   - Use [HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host) for analysis. You can download the tool from [developertools_smartperf_host Release](https://gitee.com/openharmony/developtools_smartperf_host/releases).
