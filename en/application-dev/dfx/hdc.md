# hdc

OpenHarmony Device Connector (hdc) is a command line tool used for debugging. You can use it on a Windows, Linux, or macOS system to interact with devices.

## Environment Setup

Obtain hdc from the **toolchains** folder in OpenHarmony SDK. For first-time use, configure the environment variables as follows.

### Setting the Environment Variable **HDC_SERVER_PORT**

**Windows**

1. Choose **This PC > Properties >Advanced system settings > Advanced > Environment Variables**, add the variable **HDC_SERVER_PORT**, and set its value to any port number not in use, such as **7035**.

![Create system variable](figures/hdc_image_001_en.PNG)

2. Restart DevEco Studio.

**macOS**

1. Start the terminal tool and run the following command:

   ```shell
   echo $SHELL 
   ```

   - If the command output is **/bin/bash**, open the **.bash_profile** file.

      ```shell
      vi ~/.bash_profile
      ```

   - If the command output is **/bin/zsh**, open the **.zshrc** file.

      ```shell
      vi ~/.zshrc
      ```

2. Press **i** to enter **Insert** mode.
3. Enter the following content to add **HDC_SERVER_PORT** information to **PATH**.

   ```shell
   HDC_SERVER_PORT=7035
   launchctl setenv HDC_SERVER_PORT $HDC_SERVER_PORT
   export HDC_SERVER_PORT
   ```

4. Press **Esc** to exit **Insert** mode. Then enter **:wq** and press **Enter** to save the settings.
5. Run the following command for the environment variable to take effect.

   - If the **.bash_profile** file is opened in step 1, run the following command: 

      ```shell
      source ~/.bash_profile
      ```

   - If the **.zshrc** file is opened in step 1, run the following command:

      ```shell
      source ~/.zshrc
      ```

6. Restart DevEco Studio.

### (Optional) Setting Global Environment Variables

> **NOTE**
> If global environment variables are not set, you can run commands to go to the **toolchains** directory in the SDK and run hdc commands in the directory for debugging.

**Windows**

Choose **This PC > Properties > Advanced system settings > Advances > Environment Variables**, add the **toolchains** path of the SDK to the value of **Path**.

In the following example, the **toolchains** path of the local SDK is <!--RP1-->**/User/username/sdk/openharmony/10/toolchains**<!--RP1End-->.

![System Variables](figures/hdc_img_002_en.PNG)

![Edit Environment Variable](figures/hdc_image_003_en.PNG)

**Linux/macOS**

1. Start the terminal tool and run the following command:

   ```shell
   echo $SHELL 
   ```

   - If the command output is **/bin/bash**, open the **.bash_profile** file.

      ```shell
      vi ~/.bash_profile
      ```

   - If the command output is **/bin/zsh**, open the **.zshrc** file.

      ```shell
      vi ~/.zshrc
      ```

2. Press **i** to enter **Insert** mode.

3. Enter the following content and add the SDK path to the **PATH**.

   In the following example, the **toolchains** path of the local SDK is <!--RP1-->**_/User/username/sdk/openharmony/10/toolchains_**<!--RP1End-->.

   ```shell
   HDC_SDK_PATH=/User/username/sdk/openharmony/10/toolchains
   launchctl setenv HDC_SDK_PATH $HDC_SDK_PATH # This command needs to be executed only on macOS.
   export PATH=$PATH:$HDC_SDK_PATH
   ```

4. Press **Esc** to exit **Insert** mode. Then enter **:wq** and press **Enter** to save the settings.

5. Run the following command for the environment variable to take effect.

   - If the **.bash_profile** file is opened in step 1, run the following command: 

      ```shell
      source ~/.bash_profile
      ```

   - If the **.zshrc** file is opened in step 1, run the following command:

      ```shell
      source ~/.zshrc
      ```
<!--Del-->
**(Optional for Linux) Granting USB Operation Permission for Non-root Users**

- To temporarily grant the full operation permission on a USB device, run the following command:

   ```shell
   sudo chmod -R 777 /dev/bus/usb/
   ```

- To permanently change the operation permission on a USB device, do as follows:

   1. Run the **lsusb** command to obtain the **vendorID** and **productID** of the USB device.

   2. Create an **udev** rule.

      Edit the **udev** loading rule and replace the default **idVendor** and **idProduct** values of the device with the values obtained in the previous step.

      **MODE="0666"** indicates the permissions of **GROUP** (the user group) for the USB device. Ensure that the login user is in the user group.

        ```shell
        sudo vim /etc/udev/rules.d/90-myusb.rules
        SUBSYSTEMS=="usb", ATTRS{idVendor}=="067b", ATTRS{idProduct}=="2303", GROUP="users", MODE="0666"
        ```

   3. Restart the computer or reload the **udev** rule.

        ```shell
        sudo udevadm control --reload
        ```

> **NOTE**
> A non-root user cannot find the device using hdc in Linux. Granting USB operation permission for non-root users can solve this problem. However, granting the full permission may pose potential security risks. You need to determine whether to grant the permission based on actual requirements.

## Precautions

- If an exception occurs, run the **hdc kill -r** command to kill the hdc process and restart the hdc service.

- If no device information is obtained after the **hdc list targets** command is executed, check whether the hdc process exists in the **Task Manager**. If the process exists, run the **hdc kill -r** command to kill the process and restart the hdc service.


## How to Use
> **NOTE**
>
> - The parameters enclosed in [] in a command are optional.
> - The parameters in italics are variables. Replace them with actual values when running the command. 
<!--DelEnd-->

### Global Option Commands

| Option | Description|
| -------- | -------- |
| -h/help | Displays hdc help information.|
| -v/version | Displays hdc version information.|
| -t [connect-key] [command] | Connects to the specified device. You can run the **hdc list targets** command to obtain the **connect-key**.|
| -l [level] | Sets the levels of the logs generated during the running of the tool. The default value is **LOG_INFO**.|
| wait | Waits for the device to be properly connected and checks whether the device is connected and ready to receive instructions.|
| checkserver | Obtains the **client-server** version.|

1. Display hdc help information.

   ```shell
   hdc -h/help
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | OpenHarmony device connector(HDC) ...<br>---------------------------------global commands:----------------------------------<br>-h/help [verbose]&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;- Print hdc help, 'verbose' for more other cmds<br>..._(Detailed information is omitted here.)_| Help information for hdc commands.|

   **Usage**

   ```shell
   hdc -h or hdc help
   ```

2. Display hdc version information.

   ```shell
   hdc -v/version
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Ver: X.X.Xa | hdc (SDK) version information.|

   **Usage**

   ```shell
   hdc -v or hdc version
   ```

3. Connect to a device. If there is only one device connected, you do not need to specify **connect-key**. If there are multiple devices connected, you must specify **connect-key** each time.

   ```shell
   hdc -t [connect-key] [command]
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | connect-key| Device ID.|
   | command | Command to be executed.|

> **NOTE**
   > The **connect-key** uniquely identifies a device. If the device is connected over the network, the **connect-key** is the IP address. If the device is connected through USB, the **connect-key** is the USB SN.

   **Return value**
| Return Value| Description|
| -------- | -------- |
| Command output| Command execution result, which may vary with the command.|
| [Fail]Not match target founded, check connect-key please | No device matches the *connect-key*.|
| [Fail]Device not founded or connected | The device is not found or connected.|
| [Fail]ExecuteCommand need connect-key? please confirm a device by help info | You must specify one device if there are multiple devices available.|
| Unknown operation command... | The command is not supported.|

   **Usage**

   This option must be used with a command. The following uses the **shell** command as an example.

   ```shell
   hdc list targets  // Display connect-key of all connected devices.
   hdc -t [connect-key] shell // Replace connect-key with the specified device ID.
   ```

4. Specify the runtime log level. The default value is **LOG_INFO**. 

   ```shell
   hdc -l [level] [command]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | [level] | Log level.<br>0: LOG_OFF<br>1: LOG_FATAL<br>2: LOG_WARN<br>3: LOG_INFO<br>4: LOG_DEBUG<br>5: LOG_ALL|
   | command | Command to be executed.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Command output| Command execution result, which may vary with the command.|
   | Log information| Logs of the specified level.|

   **Usage**

   ```shell
   hdc -l 5 shell ls
   ```

5. Wait until the device is connected properly.

   ```shell
   hdc wait // Wait for the device to connect.
   hdc -t connect-key wait // Wait for the specified device to connect. Replace connect-key with the specified device ID.
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | None| After the **hdc wait** command is executed, the process ends when a properly connected device is identified.|

   **Usage**

   ```shell
   hdc wait
   hdc -t connect-key wait
   ```

6. Obtain the client-server version information.

   ```shell
   hdc checkserver
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Client version: Ver: X.X.Xa, Server version: Ver: X.X.Xa | Client-server version information.|

   **Usage**

   ```shell
   hdc checkserver
   ```

### Commands for Viewing Device List

| Command| Description|
| -------- | -------- |
| list targets [-v] | Displays all connected devices. Use **-v** to display detailed device information.|

Display all connected devices.

```shell
hdc list targets[-v]
```

**Return value**
| Return Value| Description|
| -------- | -------- |
| Device information| A list of connected devices.|
| [Empty] | No device is found.|

**Usage**

```shell
hdc list targets
hdc list targets -v
```

### Service Process Commands

| Command| Description|
| -------- | -------- |
| target mount | Mounts the system partition in read/write mode (unavailable to user).|
| target boot [-bootloader\|-recovery] | Restarts a target device. You can use the **-bootloader** option to enter the fastboot mode and the **-recovery** option to enter the recovery mode.|
| target boot [MODE] | Restart a target device to enter the corresponding mode. **MODE** is an option supported by **reboot** in the **/bin/begetctl** command.|
| smode [-r] | Grants the **root** permission to the background hdc service running on the device. You can use the **-r** option to revoke the granted permission (unavailable to user).|
| kill [-r] | Terminates the hdc process. You can use the **-r** option to restart the process.|
| start [-r] | Starts the hdc process. You can use the **-r** option to restart the process.|

1. Mount the system partition in read/write mode.

   ```shell
   hdc target mount
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Mount finish | Mounting succeeded.|
   | [Fail]Mount failed | Mounting failed.|

   **Usage**

   ```shell
   hdc target mount
   ```

2. Restart the target device.

   ```shell
   target boot [-bootloader|-recovery]
   target boot [MODE]
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | Not specified| Restarts a device.|
   | -bootloader| Restarts a device to enter the **fastboot** mode.|
   | -recovery | Restarts a device to enter the **recovery** mode.|
   | MODE | Restarts a device to enter the **MODE** mode. The **MODE** option is supported by **reboot** in the **/bin/begetctl** command. You can run the **hdc shell "/bin/begetctl -h \grep reboot"** command to obtain the options.|  |

   **Usage**

   ```shell
   hdc target boot -bootloader // Restart the device to enter the fastboot mode.
   hdc target boot -recovery // Restart the device to enter the recovery mode.
   hdc target boot shutdown // Shut down the device.
   ```

3. Grant the **root** permission to the background hdc service running on the device.

   ```shell
   hdc smode [-r]
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | No return value| Permission granted.|
   | [Fail]Error information| Failed to grant the permission.|

   **Usage**

   ```shell
   hdc smode  
   hdc smode -r  // Revoke the root permission.
   ```

4. Terminate the hdc service.

   ```shell
   hdc kill [-r]
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Kill server finish | The service is terminated successfully.|
   | [Fail]Error information| Failed to terminate the service.|

   **Usage**

   ```shell
   hdc kill
   hdc kill -r // Restart and terminate the service process. 
   ```

5. Start the hdc service.

   ```shell
   hdc start [-r]
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | No return value| The service is started successfully.|
   | [Fail]Error information| Failed to start the service process.|

   **Usage**

   ```shell
   hdc start
   hdc start -r // Restart the service.
   ```

### Network Commands

| Command| Description|
| -------- | -------- |
| fport ls | Lists all port forwarding tasks.|
| fport _localnode remotenode_ | Sets up a local port forwarding, which forwards data from a local port to a remote port.|
| rport _remotenode localnode_ | Sets up a remote port forwarding, which forwards data from a remote port to a local port.|
| fport rm _taskstr_ | Removes a port forwarding task.|
| tmode usb | This command cannot be used to enable the USB connection channel. You need to enable it on the device setting page.|
| tmode port [port-number] | Enable the network connection channel of the device. Then the daemon process on the device restarts, and the USB connection is interrupted. You need to reconnect the device.|
| tmode port close | Disable the network connection channel of the device. Then the daemon process on the device restarts, and the USB connection is interrupted. You need to reconnect the device.|
| tconn [IP]:[port] [-remove] | Specifies a connection to a device in *IP address: port number* format. Use the **-remove** option to disconnect from the specified device.|

1. List all port forwarding tasks.

   ```shell
   hdc fport ls
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | tcp:1234 tcp:1080 [Forward] | Local port forwarding.|
   | tcp:2080 tcp:2345 [Reverse] | Remote port forwarding.|
   | [empty] | No port forwarding.|

   **Usage**

   ```shell
   hdc fport ls
   ```

2. Set up a local port forwarding, which forwards data from a local port to a remote port.

   ```shell
   hdc fport localnode remotenode
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Forwardport result:OK | The port forwarding is set up properly.|
   | [Fail]Incorrect forward command | Failed to set up the port forwarding due to parameter errors.|
   | [Fail]TCP Port listen failed at XXXX | Failed to set up the port forwarding because the local port is in use.|

   **Usage**

   ```shell
   hdc fport tcp:1234 tcp:1080
   ```


3. Set up a remote port forwarding, which forwards data from a remote port to a local port.

   ```shell
   hdc rport remotenode localnode
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Forwardport result:OK | The port forwarding is set up properly.|
   | [Fail]Incorrect forward command | Failed to set up the port forwarding due to parameter errors.|
   | [Fail]TCP Port listen failed at XXXX | Failed to set up the port forwarding because the local port is in use.|

   **Usage**

   ```shell
   hdc rport tcp:1234 tcp:1080
   ```
4. Remove the specified port forwarding.

   ```shell
   hdc fport rm taskstr
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | _taskstr_ | Port forwarding task, in the format of tcp:XXXX tcp:XXXX.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Remove forward ruler success, ruler:tcp:XXXX tcp:XXXX | The port forwarding is removed successfully.|
   | [Fail]Remove forward ruler failed, ruler is not exist tcp:XXXX tcp:XXXX | Failed to remove the port forwarding because the specified forwarding does not exist.|

   **Usage**

   ```shell
   hdc fport rm tcp:1234 tcp:1080
   ```


5. Enable the USB connection channel of the device.

   ```shell
   hdc tmode usb
   ```

   **Usage**

   ```shell
   hdc tmode usb
   ```
   > **NOTE**
   > This command cannot be used to enable the USB connection channel. You need to enable it on the device setting page.

6. Enable the network connection channel of the device.

   ```shell
   hdc tmode port [port-number]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | port-number | Port number of the connection. The value ranges from 1 to 65536.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Set device run mode successful. | The network connection channel is enabled successfully.|
   | [Fail]ExecuteCommand need connect-key | Failed to enable the network connection channel because no device exists in the list. |
   | [Fail]Incorrect port range | The port number is out of range (1 to 65536).|

   **Usage**

   ```shell
   hdc tmode port 1234
   ```

   > **NOTE**
   > Before changing the connection mode, ensure that the remote device and the local executor are on the same network, and the executor can ping the IP address of the remote device.
   >
   > Otherwise, do not run this command.

   > **NOTE**
   > After the command is executed, the remote daemon process exits and restarts, and the USB connection is disconnected. You need to reconnect the USB connection.

7. Disable the network connection channel of the device.

   ```shell
   hdc tmode port close
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | [Fail]ExecuteCommand need connect-key | Failed to disable the network connection channel because no device exists in the list.|

   **Usage**

   ```shell
   hdc tmode port close
   ```
   > **NOTE**
   > After the command is executed, the remote daemon process exits and restarts, and the USB connection is disconnected. You need to reconnect the USB connection.

8. Connect to the specified device through TCP.

   ```shell
   hdc tconn [IP]:[port] [-remove]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | [IP]:[port]  | Device IP address and port number.|
   | -remove | (Optional) Disconnects from the specified device.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Connect OK | Device connected.|
   | [Info]Target is connected, repeat opration | The device is already connected.|
   | [Fail]Connect failed | Failed to connect the specified device.|

   **Usage**

   ```shell
   hdc tconn 192.168.0.1:8888
   hdc tconn 192.168.0.1:8888 -remove  // Disconnect from the specified device.
   ```

### File Commands

| Command| Description|
| -------- | -------- |
| file send _localpath remotepath_ | Sends a local file to a remote device.|
| file recv _remotepath localpath_ | Sends a file from a remote device to the local device.|

1. Send a local file to a remote device.

   ```shell
   hdc file send localpath remotepath
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | _localpath_ | Path of the file to send on the local device.|
   | _remotepath_ | Destination path on the remote device.|

   **Return value**

   A success message is displayed if the file is sent successfully. Error information is displayed if the file fails to be sent.

   **Usage**

   ```shell
   hdc file send E:\example.txt /data/local/tmp/example.txt
   ```

2. Send a file from a remote device to the local device.

   ```shell
   hdc file recv remotepath localpath
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | _localpath_ | Destination path on the local device.|
   | _remotepath_ | Path of the file to send on the remote device.|

   **Return value**

   A success message is displayed if the file is received successfully. Error information is displayed if the file fails to be received.

   **Usage**

   ```shell
   hdc file recv  /data/local/tmp/a.txt   ./a.txt
   ```

### App Commands

| Command| Description|
| -------- | -------- |
| install _src_ | Installs an app.|
| uninstall _packageName_ | Uninstalls an app.|

1. Install an app.

   ```shell
   hdc install [-r|-s] src
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | src| Installation package name.|
   | -r | Replaces the existing app (.hap).|
   | -s | Install a shared package (.hsp).|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | AppMod finish | The installation is successful.|
   | Error information| The installation fails.|

   **Usage**

   For example, install **example.hap**.

   ```shell
   hdc install E:\example.hap
   ```

2. Uninstall the app.

   ```shell
   hdc uninstall [-k|-s] packageName
   ```

   **Parameters**
   | Name| Description|
   | -------- | -------- |
   | packageName | App installation package.|
   | -k | Retains **/data** and **/cache**.|
   | -s | Uninstalls a shared package.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | AppMod finish | The uninstallation is successful.|
   | Error information| The uninstallation fails.|

   **Usage**

   For example, uninstall **com.example.hello**.

   ```shell
   hdc uninstall com.example.hello
   ```

### Debugging Commands

| Command| Description|
| -------- | -------- |
| jpid | Displays the PIDs of all applications that have enabled JDWP on the device.|
| track-jpid [-a\|-p]  | Displays the PID and name of the application for which JDWP is enabled on the device in real time. If no parameter is specified, only the processes of the **debug** application are displayed. If the **-a** parameter is specified, the processes of the **debug** and **release** applications are displayed. If the **-p** parameter is specified, the **debug** and **release** labels are not displayed.|
| hilog [options] | Obtains the log information of the device. **options** indicates the parameters supported by HiLog. You can run the **hdc hilog -h** command to obtain the parameter information. |
| shell [command] | Runs a debugging command specified by *command*. The supported commands vary with the system type or version. You can run the **hdc shell ls /system/bin** command to view the supported commands. |

1. Obtain log information about the device.

   ```shell
   hdc hilog [options]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | [options] | Parameters supported by HiLog. You can run the **hdc hilog -h** command to obtain the parameter list.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Returned information| Log information obtained.|

   **Usage**

   ```shell
   hdc hilog 
   hdc shell "hilog -r" // Clear the cached logs.
   ```

2. Display the PIDs of all processes that enable JDWP.

   ```shell
   hdc jpid
   ```

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | PID list| PIDs of the applications that enable JDWP|
   | [empty] | No process enables JDWP.|

   **Usage**

   ```shell
   hdc jpid
   ```

3. Display the PIDs and application names of the processes that enable JDWP on the device in real time.

   ```shell
   track-jpid [-a|-p]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | Not specified| Displays only the PIDs, bundle names, and process names of debug applications.|
   | -a | Displays the PIDs, bundle names, and process names of the debug and release applications. |
   | -p | Displays the PIDs, bundle names, and process names of the debug and release applications, but does not display the **debug** and **release** labels.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | PIDs and bundle/process name list| - |
   | [empty] | If no parameter is specified, no process of the debug application enables JDWP. If the **-a** or **-p** parameter is specified, no process enables JDWP.|

   **Usage**

   ```shell
   hdc track-jpid
   ```

4. Run a command.

   ```shell
   hdc shell [command]
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | [command] | Debugging command to be executed. You can run the **help** command to obtain all debugging commands.|

   **Return value**
   | Return Value| Description|
   | -------- | -------- |
   | Command execution result| Execution result of the debugging command.|
   | /bin/sh: XXX : inaccessible or not found | The specified command is not supported.|

   **Usage**

   ```shell
   hdc shell ps -ef  
   hdc shell help -a // List all available commands.
   ```

### Security Command

| Command| Description|
| -------- | -------- |
| keygen FILE | Generates a new key pair and save the private key and public key to **FILE** and **FILE.pub** respectively. The file name **FILE** can be customized.|

1. Generate a new key pair.

   ```shell
   hdc keygen FILE
   ```

   **Parameters**
   | Parameter| Description|
   | -------- | -------- |
   | FILE | Custom file name.|

   **Usage**

   ```shell
   hdc keygen key // Generate the key and key.pub files in the current directory.
   ```


## When to Use

### USB Connection

**Checking the Environment**
| Item| Normal| Exception Handling|
| -------- | -------- | -------- |
| USB debugging| USB debugging is enabled.| If the USB debugging mode is not automatically enabled, restart the device.|
| USB data cable connection| The PC used for debugging is connected to the device USB port using a USB cable.| If you use a USB cable with low bandwidth and no data communication function, the device may fail to be identified. You are advised to use an officially recommended USB cable.|
| USB port| A USB port on the mainboard (USB port on the rear panel of a desktop computer or USB port on a laptop computer) is used.| If you use a conversion adapter, docking station, or USB port on the front panel of a desktop computer, issues such as low bandwidth and USB sync problems may occur, which results in frequent disconnections. Therefore, direct connection between the PC and the device is recommended.|
| hdc environment variable| The help information is displayed after the **hdc -h** command is executed.| For details, see "Environment Setup".|
| Driver| After the device is connected via hdc, **HDC Device** or **HDC Interface** is displayed in **Device Manager**.| Install the driver.|

**Procedure**

```shell
hdc shell // For USB direct connection, ensure that the device is not in TCP connection mode.
```

### TCP Connection

**Checking the Environment**
| Item| Normal| Exception Handling|
| -------- | -------- | -------- |
| Network connection| The PC and the device are on the same network.| Connect the PC and device to the same Wi-Fi network or enable the Wi-Fi hotspot on your device.|
| Network Status| Use **telnet IP:port** to check that the network connection between the PC and the device is normal.| Connect the PC and the device over a stable network.|
| hdc environment variable| The help information is displayed after the **hdc** command is executed.| For details, see "Environment Setup".|

**Procedure**

1. Connect the PC to the device through a USB port.


2. Change the connection mode from USB mode to the TCP mode.

   ```shell
   hdc tmode port 8710// Add a port number after port. The default port number is 8710.
   ```

3. Connect to the device over TCP (the device IP address must be obtained in advance).

   ```shell
   hdc tconn IP:8710
   ```

   You can view the IP address on the device. The port number is the one specified in the previous step. The default port number is 8710.

4. Check the connection.

   ```shell
   hdc list targets
   ```

   If the return value is in the *IP:port* format, the connection is successful.

5. (Optional) Change the TCP mode to the USB mode.

   ```shell
   hdc tmode usb
   ```

   The USB mode is restored.

### Remote Connection

The following figure illustrates a remote connection.

![Remote connection structure](figures/hdc_image_004.PNG)

**Server Configuration**

Connect the server to the device using a USB cable and run the following commands:

```shell
hdc kill          // Terminate the local hdc service.
hdc -s IP:8710 -m // Enable the hdc service for network forwarding.
                  // In the command, IP indicates the IP address of the server. To query the IP address, you can run the ipconfig command on Windows and run the ifconfig command on Unix.
                  // 8710 is the default port number. You can also set it to another port number, for example, 18710.
                  // After startup, the server prints logs.
```

**Client Connection**

Ensure that the client can connect to the server IP address, and then run the following command:
```shell
hdc -s IP:8710 [command] // IP indicates the IP address of the server,
                         // and command can be any available hdc command, for example, list targets.
```

### Obtaining Logs

**Server logs**

Obtain server logs.

```shell
hdc kill ​
hdc -l5 start
```

The collected logs are stored in the following path.

| OS| Path| Remarks|
| -------- | -------- | -------- |
| Windows | %temp%\hdc_logs | The following is an example. Replace *Username* with the actual one.<br>C:\Users\Username\AppData\Local\Temp\hdc_logs|
| Linux | /tmp/hdc_logs | - |
| MacOS | $TMPDIR/hdc_logs | - |

The hdc_logs folder contains the following types of logs:

|Type| Name Format| Function| Remarks|
| -------- | -------- | -------- | -------- |
| Real-time log| hdc.log | Records hdc server logs in real time.| Each time the hdc server is restarted, the original log is renamed and a new hdc.log is recorded.|
| Temporary historical log| hdc-%Y%m%d-%H%M%S.log | Dumps intermediate files generated during historical log archiving.| For example, **16:18:57.921 on September 19, 2024** is recorded as<br>**20240919-161857921**.<br>The generated temporary log file is stored in the format of **hdc-20240919-161857921.log**.|
| Archived historical logs| hdc-%Y%m%d-%H%M%S.log.tgz | Compresses and stores historical logs.| The archive file is a compressed file of the **.tgz** type. You can use a decompression tool to obtain the file.<br>For example, if the name of a temporary historical log file is **hdc-20240919-161857921.log**,<br>the name of the corresponding archived historical log file is **hdc-20240919-161857921.log.tgz**.<br>After an archived historical log file is generated, the corresponding temporary historical log file is automatically deleted.|
| Temporary real-time log| .hdc.cache.log | Records temporary caches generated by real-time logs.| |

**Device Logs**

Enable HiLog to obtain the corresponding logs.

```shell
hdc shell hilog -w start                             // Enable the function of storing HiLog logs.
hdc shell ls /data/log/hilog                     // View the stored HilLog logs.
hdc file recv /data/log/hilog                  // Obtain the stored HilLog logs (including kernel logs).
```

## FAQs

### Failed to Identify the Target Device

**Symptom**

After the **hdc list targets** command is executed, the command output is **[empty]**.

Perform the following operations to locate the fault.

- Case 1: Check whether the target device is displayed in **Device Manager**.

  Windows:

  Check whether **HDC Device** (for a single-port device) or **HDC Interface** (for a composite device) exists under **Universal Serial Bus Controllers** in **Device Manager**.

  Linux:

  Run the **lsusb** command. Check whether **HDC Device** or **HDC Interface** is displayed in the command output.

  macOS:

  View USB devices in **System Information** or **System Overview**.

  1. Press and hold the **Option** key, and click **Menu**.

  2. Choose **System Information** or **System Overview**.

  3. Select **USB** on the left.

  4. Check whether **HDC Device** or **HDC Interface** exists in the device tree.

  **Solution**

  If the device is not displayed, it fails to be identified. You can use any of the following methods to resolve the problem:

  - Use another physical USB port.
  - Replace the USB cable.
  - Use another PC for debugging.
  - Enable the USB debugging mode.
  - Click **OK** to allow USB debugging.
  - If a TCP connection can be set up, run the **hdc tmode usb** command to switch to the USB connection.
  - Restore the factory settings of the device.

- Case 2: A USB device exists, but the driver is damaged. **HDC Device** with a warning icon in yellow is displayed.

  This problem usually occurs in Windows. In **Device Manager/Universal Serial Bus Device**, **HDC Device** is displayed with a yellow warning icon, indicating that the device cannot work properly. To resolve the problem, reinstall the driver. If the problem persists, use another USB cable, docking station, or USB port.

  **Reinstalling the Driver**

  1. Open **Device Manager**, and right-click the **HDC Device** with a warning icon.

  2. In the displayed menu, choose **Update driver**.

  3. In the first prompt window, select **Browse my computer for drivers**.

  4. In the second prompt window, select **Let me pick from a list of available drivers on my computer**.

  5. In the third prompt window, deselect **Show compatible hardware**, select **WinUsb Device** for **Manufacture** and **WinUsb Device** for **Model**, and click **Next**.

- Case 3: "[Fail]Failed to communicate with daemon" is displayed when the device is connected. 

  When "[Fail]Failed to communicate with daemon" is displayed after a hdc command is executed.

  Possible causes are as follows:

  - The hdc or SDK does not match the device. If the device is the latest version, update the hdc or SDK tool to the latest version.
  - The port is occupied.

    This problem usually occurs when hdc and hdc_std use the same **HDC_SERVER_PORT** or the same default port **8710**. Ensure that either hdc or hdc_std is running. This problem also occurs when other software occupies the default hdc port.

- Case 4: "Connect server failed" is displayed when the device is connected.

  The possible causes are as follows:

  - **Port Preemption**

    Solution:
    1. Check the software processes that come with hdc, including software with built-in hdc, such as DevEco Studio and DevEco Testing.

       Stop these software processes and run hdc commands.

    2. Check hdc port status.

       For example, if **HDC_SERVER_PORT** is set to **8710**, run the following command to check the port status.

       Unix:

       ```shell
       netstat -an |grep 8710
       ```

       Windows:

       ```shell
       netstat -an |findstr 8710
       ```

       If the port is used by another software, stop the software process or change the **HDC_SERVER_PORT** environment variable to another port number.

    3. Check for and stop the hdc server of another version.

       Windows:

       Choose **Task Manager** > **Details**, right-click the **hdc.exe** process and choose **Open file location**. Check whether the location is the same as that configured in the environment variable. If not, stop the **hdc.exe** process by running the **hdc kill** command or terminating the process in **Task Manager**. Then, run the hdc command again. (The hdc server will be restarted by running the hdc command.)

       Unix:

       Run the **ps -ef |grep hdc** command to query the hdc server process running in the background and check whether the process startup location is the hdc file location set by the environment variable **Path**. If not, stop the hdc process by running the **hdc kill** or **kill -9 hdc** *PID* command, and run the hdc command again. (The hdc server will be restarted by running the hdc command.)

  - **Registry Exception**

    Solution: Clear the registry. The procedure is as follows:

    1. Press **Win+R** to open the **Run** dialog box, and enter **regedit** to open the registry.
    2. Enter the following address in the address bar, and press **Enter** to access the registry of the USB device driver.

       ```shell
       Computer\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Class\{88bae032-5a81-49f0-bc3d-a4ff138216d6}
       ```

    3. Right-click **UpperFilters** and choose **Edit**. Back up and clear the value data. The backup data can be used to restore the value data if the problem persists.
    4. Refresh the **Device Manager**, remove and reconnect the USB cable to the USB port, or restart the PC.

### Failed to Run hdc

**Symptom**

The **hdc.exe**/hdc binary file cannot be executed using the CLI.

**Possible Causes and Solution**

- Incorrect runtime environment.

  Linux: Ubuntu 18.04 64-bit or later is recommended. If **libc++.so** reference errors are reported, run the **ldd** or **readelf** command to check library reference.

  macOS: macOS 11 or later is recommended.

  Windows: Windows 10 or Windows 11 64-bit is recommended. If the WinUSB library or driver is missing in an earlier version, use [Zadig](https://github.com/pbatard/libwdi/releases) to update it. For Windows 10 or Windows 11 64-bit, use [Zadig](https://github.com/pbatard/libwdi/releases) to install the libusb-win32 driver. For details, see [Zadig](https://github.com/pbatard/libwdi/releases).

- Improper running mode: Use the correct command to run the hdc tool instead of double-clicking the file.

### Common Procedure for Troubleshooting Other Problems

1. Run the **hdc list targets** command.
2. Check whether **HDC Device** exists in **Device Manager**.
3. Run the **hdc kill** command to terminate the server, and then run the **hdc -l5 start** command to collect logs. The **hdc.log** file is stored in the **hdc_logs** folder of the **TEMP** directory on the execution end. The specific directory varies with the OS. For details, see [Obtaining Logs](#obtaining-logs).
4. Locate the problem based on the **hdc.log** file.
