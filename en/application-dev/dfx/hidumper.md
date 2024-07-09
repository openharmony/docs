# HiDumper

HiDumper is a command-line tool used to export essential system information for analyzing and locating issues.

## Prerequisites

- The [environment setup](hdc.md#environment-setup) is complete.

- The devices are properly connected.

## Command Description

| Commands| Description|
| -------- | -------- |
| -h  | Displays help information.|
| -lc | Lists all system information clusters.|
| -ls | Lists all system abilities.|
| -c | Obtains system cluster information.|
| -s | Obtains all system ability information.|
| -e | Obtains crash logs.|
| --net | Exports network information.|
| --storage | Exports storage information.|
| -p | Obtains all process and thread information.|
| --cpuusage [pid] | Dumps CPU usage information. If **pid** is specified, dumps the CPU usage of the specified process.|
| --cpufreq | Dumps the actual CPU frequency.|
| --mem [pid] | Dumps the total memory usage. If **pid** is specified, dumps the memory usage of the specified process.|
| --mem-smaps pid [-v] | Exports the total memory usage to **/proc/pid/smaps**. Use **-v** to specify more details.|
| --zip | Compresses the exported information to **/data/log/hidumper**.|

## Examples

1. Display help information.

   ```
   hidumper -h
   ```

   **Example**

   ![](figures/hidumper-h.png)

2. Obtain memory usage of the specified process.

   ```
   hidumper --mem pid
   ```

   **Example**

   ![](figures/hidumper-mem-pid.png)

   The **Graph** field represents the memory size used by the process in the **/proc/process_dmabuf_info** node.
   
3. Obtain memory usage of all processes on the device.

   ```
   hidumper --mem
   ```

   **Example**

   ![](figures/hidumper-mem.png)

4. Obtain CPU usage.

   ```
   hidumper --cpuusage
   ```

   **Example**

   ![](figures/hidumper-cpuusage.png)

5. Obtain CPU usage of the specified process.

   ```
   hidumper --cpuusage pid
   ```

   **Example**

   ![](figures/hidumper-cpuusage-pid.png)

6. Obtain the help information about the ability whose ID is 3301.

   ```
   hidumper -s 3301 -a "-h" 
   ```

   **Example**

   ![](figures/hidumper-s-3301.png)

7. Obtain the help information about RenderService.

   ```
   hidumper -s RenderService -a "h" 
   ```

   **Example**

   ![](figures/hidumper-renderservice-h.png)

8. Obtain the refresh frame rate of a surface.

   ```
   hidumper -s RenderService -a "surface_name fps" 
   ```

   **Example**

   ![](figures/hidumper-renderservice-fps.png)
