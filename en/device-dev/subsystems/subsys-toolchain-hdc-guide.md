# hdc_std


OpenHarmony Device Connector (hdc_std) is a command-line tool used for debugging. You can use it on a Windows, Linux, or macOS system to interact with real devices or simulators.


The following describes how to obtain and use hdc_std.


## How to Obtain

Obtain hdc_std from the **toolchains** directory of the OpenHarmony SDK.

**Example**

If you use hdc_std on Windows, obtain the SDK for Windows and copy **hdc_std.exe** from **toolchains** to a directory on the disk.


## NOTICE

- If an exception occurs when you are using hdc_std, run the **hdc_std kill** command to terminate the hdc_std service or run the **hdc_std start -r** command to restart the service process.

- If no device information is obtained after **hdc_std list targets** is executed, check whether the hdc_std process exists in the **Task Manager**. If yes, terminate it.


## Option-related Commands

The following commands are available:


- **-h/help -v/version**
  
  Displays hdc_std help or version information.
  
  **Table 1** Command description
  | **Return Value**| **Description**|
  | -------- | -------- |
  | Required information| hdc_std help or version information.|

  Example:
  
  ```
  hdc_std -h / hdc_std help
  ```
  
  ```
  hdc_std -v / hdc_std version
  ```
  
   

- **-l 0-5**
  
  Sets the levels of the logs generated during the running of the tool. The default value is **LOG_INFO**.
  
  **Table 2** Command description

  | Parameter| Description|
  | -------- | -------- |
  | 0 | LOG_OFF  |
  | 1 | LOG_FATAL|
  | 2 | LOG_WARN |
  | 3 | LOG_INFO |
  | 4 | LOG_DEBUG|
  | 5 | LOG_ALL  |

  Example:
  
  ```
  hdc_std -l5 start
  ```

- **-t key**
  
  Connects to a device based on the specified key.
  
  **Table 3** Command description

  | Parameter| Description|
  | -------- | -------- |
  | key | Key that identifies the device to connect. The value can be in the *IP address:port number* format or be a USB serial number.|
  | **Return Value** | **Description** |
  | 1. error: device '\*\*\*' not found<br>2. Nothing to do ..| 1. The device does not exist.<br>2. The command appended to **-t key** does not exist.|

  Example:

  **-t key** must be used with a command. The following uses **shell** as an example:

  **hdc_std list targets** (obtain device information)

  **hdc_std -t *key* shell** (replace *key* with the device identifier obtained)

  > **NOTE**<br>
  > You can connect to multiple devices from the device you use for development. Each device has a unique key. The key can be *IP address:port number* for a device to be connected over the network or the serial number for a device to be connected through USB. A specific command must be used with this command.

- **checkserver**
  
  Obtains the client and server version information.
  
  **Table 4** Command description

  | Return Value| Description|
  | -------- | -------- |
  | Client version:  server version: | Client and server version information.|

  Example:

  ```
  hdc_std checkserver
  ```


## Displaying Device Information

Run the following command to display all connected devices:


```
list targets[-v]
```

**Table 5** Command description

| Parameter| Description|
| -------- | -------- |
| -v | Displays detailed device information.|
| **Return Value** | **Description**|
| 1. Device information<br>2. [Empty]| 1. A list of connected devices.<br>2. No device information is found.|


Example:

```
hdc_std list targets
```

```
hdc_std list targets -v
```


## Service Process Commands

The following commands are available:

- **target mount**

  Mounts the **/system** partition in read/write mode.

  **Table 6** Command description

  | Parameter| Description|
  | -------- | -------- |
  | –| –|
  | **Return Value**| **Description**|
  | 1. Mount&nbsp;finish<br>2. Error information| 1. The operation is successful.<br>2. The operation fails.|

  Example:
  
  ```
  hdc_std target mount
  ```
  
    


- **target boot**
  
  Boots the device.
  
   Example:
  
  ```
   hdc_std target boot
  ```
  
   

- **smode [-r]**
  
  Grants the **root** permission to the background hdc service. Use **off** to revoke the granted permissions.
  
  Example:
  
  ```
  hdc_std smode
  ```
  
  ```
   hdc_std smode -r
  ```
  
  

- **kill [-r]**
  
  Terminates the hdc process.
  
  **Table 7** Command description

  | Parameter| Description|
  | -------- | -------- |
  | -r | Restarts the hdc process.|
  | **Return Value**| **Description**|
  | 1. Kill&nbsp;server&nbsp;finish<br>2. Error information| 1. The operation is successful.<br>2. The operation fails.|

  Example:

  ```
  hdc_std kill
  ```

- **start [-r]**
  
  Starts the hdc process.
  
  **Table 8** Command description 

  | Parameter| Description|
  | -------- | -------- |
  | -r | Restarts the hdc process if it has started.|
  | **Return Value**| **Description**|
  | –| –|

  Example:

  ```
  hdc_std start
  ```




## Network Commands

The following commands are available:


- **tconn host[:port][-remove]**

  Connects to a device with the specified IP address and port number.

  **Table 9** Command description

  | Parameter| Description|
  | -------- | -------- |
  | host[:port] | IP address and port number for the device to connect.|
  | -remove | Disconnects from the specified device.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std tconn 192.168.0.100:8710
  ```
  
    

- **tmode usb**
  
  Restarts the daemon process and connects to the device using USB preferentially.

  **Table 10** Command description

  | Parameter| Description|
  | -------- | -------- |
  | –| –|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std tmode usb
  ```
  
    

- **tmode port port-number**
  
  Restarts the daemon process and connects to the device over TCP preferentially. If the TCP connection fails, a USB connection will be initiated.
  
  **Table 11** Command description

  | Parameter| Description|
  | -------- | -------- |
  | port-number | Port used to connect to the device.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std tmode port 8710
  ```
  
    

  > **NOTE**<br>
  > After this command is executed, the remote daemon process exits and restarts, and a TCP connection is set up by default. If the port number is not specified in the command, a random port will be used to connect to the device.

- **fport localnode remotenode**
  
  Forwards data from a host port to a device port.
  
  Example:
  
  ```
  hdc_std fport tcp:1234 tcp:1080
  ```
  
    

- **rport remotenode localnode**
  
  Forwards data from a device port to a host port.
  
  Example:
  
  ```
   hdc_std rport tcp:2080 tcp:2345 
  ```
  
   

- **fport ls**
  
  Lists all port forwarding tasks.
  
  **Table 12** Command description  

  | Parameter| Description|
  | -------- | -------- |
  | –| –|
  | **Return Value**| **Description**|
  | 'tcp:1234 tcp:1080'     [Forward] | Forward port forwarding task.|
  | 'tcp:2080 tcp:2345'     [Reverse] | Reverse port forwarding task.|

  Example:
  
  ```
  hdc_std fport ls 
  ```
  
    

- **fport rm**
  
  Deletes a port forwarding task.
  
  Example:
  
  ```
  hdc_std fport rm tcp:1234 tcp:1080 
  ```
  
   


## File Commands

The following commands are available:


- **file send local remote**
  
  Sends a file to a remote device.
  
  **Table 13** Command description 

  | Parameter| Description|
  | -------- | -------- |
  | local | Path of the file to send.|
  | remote | Destination path on the remote device.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. File transfer result| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std file send E:\a.txt   /data/local/tmp/a.txt
  ```
  
    

- **file recv [-a] remote local**
  
  Receives a file from a remote device.
  
  **Table 14** Command description

  | Parameter| Description|
  | -------- | -------- |
  | -a | Retains the file timestamp.|
  | local | Destination path on the local device.|
  | remote | File path on the remote device.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
   hdc_std file recv  /data/local/tmp/a.txt   ./a.txt
  ```
  
   


## App Commands

The following commands are available:


- **install [-r/-d/-g]** *package*
  
  Installs an OpenHarmony app.
  
  **Table 15** Command description 
  | Parameter| Description|
  | -------- | -------- |
  | package | OpenHarmony app installation package.|
  | -r | Replaces the existing app.|
  | -d | Allows downgrade installation.|
  | -g | Grants permissions dynamically.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std install hwadmin.hap
  ```
  
    

- **uninstall [-k] package**
  
  Uninstalls an OpenHarmony app.
  
  **Table 16** Command description 

  | Parameter| Description|
  | -------- | -------- |
  | package | OpenHarmony app installation package.|
  | -k | Retains **/data/cache**.|
  | **Return Value**| **Description**|
  | 1. Error information<br>2. –| 1. The operation fails.<br>2. The operation is successful.|

  Example:
  
  ```
  hdc_std uninstall package
  ```
  
   


## Debugging Commands

The following commands are available:


- **hilog**

  Obtains logs for debugging.

  **Table 17** Command description  

  | Parameter| Description|
  | -------- | -------- |
  | –| –|
  | **Return Value**| **Description**|
  | Log obtained| Log information obtained.|

  Example: Obtain log information.
  
  ```
  hdc_std hilog
  ```
  
  Clear the cached logs.
  
  ```
  hdc_std shell "hilog -r"
  ```
  
  ​    

- **shell** [*command*]
  
  Executes a command remotely or enters an interactive command environment.
  
  **Table 18** Command description  

  | Parameter| Description|
  | -------- | -------- |
  | command | Command to execute.|
  | **Return Value**| **Description**|
  | Returned information| Command execution result.|

  Example:
  
  ```
  hdc_std shell
  ```
  
    

- **jpid**
  
  Obtains the list of processes that can be debugged.
  
  Example:
  
  ```
  hdc_std jpid
  ```
  
    


## FAQs


### Failed to Connect to a Device from hdc_std

- **Symptom**
  
  After the **hdc_std list targets** command is executed, **[Empty]** is displayed.

- **Solution**
  
  - The device cannot be identified.
  
    Check whether **HDC Device** exists under the **Universal Serial Bus controllers** in the **Device Manager**. If **HDC Device** does not exist, the device cannot be connected. In this case, disconnect and then reconnect the USB connection between the test PC and the OpenHarmony device, or burn the latest image.
  
  - hdc_std works improperly.
  
    Run the **hdc kill** command to terminate the hdc_std process or run the **hdc start -r** command to restart the hdc service. Then, run the **hdc list targets** command to check whether device information can be obtained.
  
  - hdc_std does not match the device.
  
    If the latest image is burnt on the device, the latest hdc_std version must be used.


### hdc_std Fails to Run

- **Symptom**
  
  After you click **hdc_std.exe**, the file fails to execute.
  
- **Solution**
  
  **hdc_std.exe** requires no installation. You can use it after placing it to a local directory or adding the tool path to environment variables. Run the **cmd** command and then run the **hdc_std** command to start the tool.



### Accessing a Server from the Client

1. Run the **kill** command to stop the local server.

2. Run the **-s [ip:]port -m** command to start the remote server.

    Example:

   ```
   hdc_std -s severIP:8710 -m
   ```

   

3. Run **-s [ip:]port** *command* to execute a command on the remote server.

   Example:

   ```
   hdc_std -s severIP:8710 list targets
   ```

   
