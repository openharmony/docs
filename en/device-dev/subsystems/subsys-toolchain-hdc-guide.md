# hdc\_std<a name="EN-US_TOPIC_0000001080478129"></a>

hdc\_std \(OpenHarmony Device Connector\) is a command line tool provided by OpenHarmony for debugging. With this tool, you can interact with real devices or simulators from a Windows or Linux OS.

This section describes how to set up the hdc\_std environment and use its common commands.

## Preparations<a name="section05992022154916"></a>

**Obtaining hdc\_std:**

Obtain **hdc\_std** from the **prebuilt** directory at [developtools\_hdc\_standard](https://gitee.com/openharmony/developtools_hdc_standard).

**Example:**

To obtain hdc\_std on Windows, obtain the executable file **hdc\_std.exe** from **prebuilt/windows** and place it in a directory on the disk.

## Important Notes<a name="section19543134915210"></a>

-   If an exception occurs when you are using hdc\_std, run the **hdc\_std kill** command to kill the hdc\_std service or run the **hdc\_std start -r** command to restart the service process.
-   If no device information is obtained after **hdc\_std list targets** is executed, use the task manager to check whether the **hdc.exe** process exists. If it exists, kill the process.

## Option-related Commands<a name="section618522925119"></a>

The following commands are available:

### -h/help -v/version<a name="section51533527212"></a>

Obtains hdc help and version information.

**Table 1** Command description

  | Return Value | Description | 
  | -------- | -------- |
  | Required information | hdc help or version information. |

Examples:

hdc\_std -h / hdc\_std  help

hdc\_std -v / hdc\_std  version

### -t key<a name="section1180555115159"></a>

Connects to a device with a specified key.

**Table 2** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | key | Key that identifies the device. The value is in the &nbsp;IP address:port&nbsp; format or is a USB serial number. | 
  | **Return Value** | **Description** | 
  | 1. error:&nbsp;device&nbsp;'\*\*\*'&nbsp;not&nbsp;found<br/>2. Nothing&nbsp;to&nbsp;do... | 1. The device does not exist<br>2. The command appended to **-t key** does not exist. | 

Examples:

This option must be used together with a specific operation command. The following uses the shell command as an example:

**hdc\_std list targets** \(obtain device information\)

**hdc\_std  -t   _key_   shell** \(replace  _key_  with the device information obtained\)

>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>You can connect to multiple devices from the device you use for development. Each device has a unique key. The key can be  _IP address:Port number_  for a device connected through a network or the serial number for a device connected through USB.

## Querying the Device List<a name="section174891132104218"></a>

The following command is used to query the device list:

### list targets\[-v\]<a name="section12911142313168"></a>

Displays all the connected devices.

**Table 3** Command description

| Parameter | Description | 
| -------- | -------- |
| -v | Prints detailed device information. | 
| **Return Value** | **Description** | 
| 1. Device information<br/>2. [Empty] | 1. A list of connected devices.<br/>2. No device information is found. | 

Examples:

hdc\_std list targets

hdc\_std list targets -v

## Service Process Commands<a name="section680531510497"></a>

The following commands are available:

### target mount<a name="section396717571168"></a>

Mounts a partition, such as **/system**, with the read and write permissions.

**Table 4** Command description

  | Parameter | Description |  
  | -------- | -------- |
  | None | None | 
  | **Return Value** | **Description** | 
  | 1. Mount&nbsp;finish<br/>2. Returned information | 1. Information returned when the operation is successful.<br/>2. Information returned when the operation fails. | 

Example:

hdc\_std target mount

### smode \[off\]<a name="section179951621713"></a>

Grants the root permission to a background service process. The **off** option is used to revoke the granted permission.

Examples:

hdc\_std smode

hdc\_std smode off

### kill \[-r\]<a name="section419144621712"></a>

Stops a service process.

**Table 5** Command description

  | Parameter | Description |  
  | -------- | -------- |
  | -r | Triggers the service restart. | 
  | **Return Value** | **Description** | 
  | 1. Kill&nbsp;server&nbsp;finish<br/>2. Error information | 1. Information returned when the operation is successful.<br/>2. The operation fails. | 

Example:

hdc\_std kill

### start \[-r\]<a name="section184811812183"></a>

Starts a service process.

**Table 6** Command description

  | Parameter | Description |  
  | -------- | -------- |
  | -r | Restarts the service process if it has started. | 
  | **Return Value** | **Description** | 
  | None | None |

Examples:

hdc\_std start

## Network Commands<a name="section71176123212"></a>

The following commands are available:

### tconn  _host_\[:_port_\]\[-remove\]<a name="section191911334206"></a>

Connects to a device with a specified IP address and port number.

**Table 7** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | host[:port] | IP address and port number of the device to be connected. | 
  | -remove | Disconnects from the specified device. | 
  | **Return Value** | **Description** | 
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std tconn 192.168.0.100:8710

### tmode usb<a name="section17840182562015"></a>

Restarts the daemon process and connects to the device using USB.

**Table 8** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | None | None |
  | **Return Value** | **Description** |
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std tmode usb

### tmode port  _port-number_<a name="section101113462113"></a>

Restarts the daemon process and connects to the device over TCP.

**Table 9** Command description

  | Parameter | Description | 
  | -------- | -------- | 
  | port-number | Port number used to connect to the device. | 
  | **Return Value** | **Description** | 
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std tmode port 8710

>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>After this command is executed, the remote daemon process exits and restarts, and the TCP connection is enabled by default. If you do not include **port-number** in this command, a random port will be used to connect to the device.

## File Commands<a name="section173133523013"></a>

The following commands are available:

### file send  _local remote_<a name="section126223231307"></a>

Sends a file to a remote device.

**Table 10** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | local | Path of the file to send. | 
  | remote | Destination path on the remote device. | 
  | **Return Value** | **Description** |
  | 1. Error information<br/>2. File transfer result | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std file send E:\\a.txt   /data/local/tmp/a.txt

### file recv \[-a\]  _remote local_<a name="section26966541304"></a>

Receives a file from a remote device.

**Table 11** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | -a | File retention timestamp mode. | 
  | local | Path on the local device to receive the file. | 
  | remote | File path on the remote device. | 
  | **Return Value** | **Description** |
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std file recv  /data/local/tmp/a.txt   ./a.txt

## App Commands<a name="section2072647133819"></a>

The following commands are available:

### install \[-r/-d/-g\]  _package_<a name="section49615195111"></a>

Installs the OpenHarmony application.

**Table 12** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | package | OpenHarmony application installation package. | 
  | -r | Replaces an existing application. | 
  | -d | Allows downgraded installation. | 
  | -g | Grants permission dynamically. | 
  | **Return Value** | **Description** |
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std install  _hwadmin.hap_

### uninstall \[-k\]  _package_<a name="section167618461814"></a>

Uninstalls the OpenHarmony application.

**Table 13** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | package | OpenHarmony application installation package. | 
  | -k | Retains **/data/cache**. | 
  | **Return Value** | **Description** |
  | 1. Error information<br/>2. None | 1. The operation fails.<br/>2. The operation is successful. | 

Example:

hdc\_std uninstall  _package_

## Debugging Commands<a name="section112861250195015"></a>

The following commands are available:

### hilog<a name="section32171612221"></a>

Obtains logs for debugging.

**Table 14** Command description

  | Parameter | Description | 
  | -------- | -------- |
  | None | None | 
  | **Return Value** | **Description** |
  | Returned information | Obtained logs. | 

Example:

hdc\_std hilog

### shell \[_command_\]<a name="section524235625"></a>

Executes a command remotely or enters an interactive command environment.

**Table 15** Command description

  | Parameter | Description |
  | -------- | -------- |  
  | command | Command to be executed. | 
  | **Return Value** | **Description** |
  | Returned information | Execution result of the command. | 

Examples:

hdc\_std shell

## Troubleshooting<a name="section592920255582"></a>

### hdc\_std Fails to Connect to a Device<a name="section74019384588"></a>

-  **Symptom**

   **\[Empty\]** is displayed in the output after the **hdc\_std list targets** command is executed.

-  **Solutions**
    1.  The device cannot be identified.

        Check whether **HDC Device** exists in the universal serial bus device of the device manager. If **HDC Device** does not exist, the device cannot be connected. In this case, remove and then insert the device or burn the latest image for the device.

    2.  hdc\_std works improperly.

        Run the **hdc kill** or **hdc start -r** command to kill or restart the hdc service. Then, run the **hdc list targets** command to check whether device information can be obtained.

    3.  hdc\_std does not match the device.

        If the latest image is burnt on the device, the latest hdc\_std version must be used. As hdc\_std is updated continuously, obtain hdc\_std of the latest version from the **developtools\_hdc\_standard** repository in the **prebuilt** directory.



## hdc\_std Fails to Run<a name="section6825095917"></a>

-  **Symptom**

    The **hdc\_std.exe** file does not run after being clicked.

-  **Solutions**

   **hdc\_std.exe** requires no installation. It can be directly used on a disk or added to environment variables. Open the cmd window and run the **hdc\_std** command to use **hdc\_std.exe**.
