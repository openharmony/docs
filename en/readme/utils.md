# Utils<a name="EN-US_TOPIC_0000001052623010"></a>

-   [Overview](#section11660541593)
-   [Directory Structure](#section1464106163817)
-   [Usage](#section83091355151312)
-   [Repositories Involved](#section6250105871917)

## Overview<a name="section11660541593"></a>

The Utils repository stores basic components of OpenHarmony. These basic components are used by OpenHarmony subsystems and upper-layer applications.

The Utils library provides the following capabilities on different platforms:

-   LiteOS Cortex-M \(Hi3861 platform\): key value \(KV\) store, file operations, timer, IoT peripheral control, and system attribute dumping
-   LiteOS Cortex-A \(Hi3516 or Hi3518 platform\): KV store, timer, JavaScript APIs for device query and data storage, and system attribute dumping

**Table  1**  Utils capabilities

<a name="table206292206282"></a>
<table><thead align="left"><tr id="row8629020112819"><th class="cellrowborder" valign="top" width="21.22%" id="mcps1.2.4.1.1"><p id="p66291220192816"><a name="p66291220192816"></a><a name="p66291220192816"></a>Module</p>
</th>
<th class="cellrowborder" valign="top" width="24.77%" id="mcps1.2.4.1.2"><p id="p3629122014289"><a name="p3629122014289"></a><a name="p3629122014289"></a>Platform</p>
</th>
<th class="cellrowborder" valign="top" width="54.010000000000005%" id="mcps1.2.4.1.3"><p id="p206298206288"><a name="p206298206288"></a><a name="p206298206288"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1162992082812"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p136291920192814"><a name="p136291920192814"></a><a name="p136291920192814"></a>KV store</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p5629112019284"><a name="p5629112019284"></a><a name="p5629112019284"></a>LiteOS Cortex-M and LiteOS Cortex-A</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p3630112072811"><a name="p3630112072811"></a><a name="p3630112072811"></a>Provides KV storage for applications.</p>
</td>
</tr>
<tr id="row116301920152816"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p96300207286"><a name="p96300207286"></a><a name="p96300207286"></a>File operation</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p1463032012281"><a name="p1463032012281"></a><a name="p1463032012281"></a>LiteOS Cortex-M</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p163042052810"><a name="p163042052810"></a><a name="p163042052810"></a>Provides unified file operation interfaces that can be used on different underlying chip components.</p>
</td>
</tr>
<tr id="row1163022022812"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p66308202284"><a name="p66308202284"></a><a name="p66308202284"></a>Timer</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p26301620192820"><a name="p26301620192820"></a><a name="p26301620192820"></a>LiteOS Cortex-M and LiteOS Cortex-A</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p2630172062815"><a name="p2630172062815"></a><a name="p2630172062815"></a>Provides unified timer operation interfaces that can be used on different underlying chip components.</p>
</td>
</tr>
<tr id="row363012202282"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p4502105418285"><a name="p4502105418285"></a><a name="p4502105418285"></a>JavaScript API</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p199870135293"><a name="p199870135293"></a><a name="p199870135293"></a>LiteOS Cortex-A</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p1550005422814"><a name="p1550005422814"></a><a name="p1550005422814"></a>Provides JavaScript APIs for obtaining device information and storing data.</p>
</td>
</tr>
<tr id="row1763022010287"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p463052016289"><a name="p463052016289"></a><a name="p463052016289"></a>IoT peripheral control</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p1163032011284"><a name="p1163032011284"></a><a name="p1163032011284"></a>LiteOS Cortex-M</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p5630820102812"><a name="p5630820102812"></a><a name="p5630820102812"></a>Provides the capability of performing operations for peripherals.</p>
</td>
</tr>
<tr id="row5553145162815"><td class="cellrowborder" valign="top" width="21.22%" headers="mcps1.2.4.1.1 "><p id="p106300200288"><a name="p106300200288"></a><a name="p106300200288"></a>System attribute dumping</p>
</td>
<td class="cellrowborder" valign="top" width="24.77%" headers="mcps1.2.4.1.2 "><p id="p16300204280"><a name="p16300204280"></a><a name="p16300204280"></a>LiteOS Cortex-M and LiteOS Cortex-A</p>
</td>
<td class="cellrowborder" valign="top" width="54.010000000000005%" headers="mcps1.2.4.1.3 "><p id="p1563018208286"><a name="p1563018208286"></a><a name="p1563018208286"></a>Provides the command line tool for dumping system attributes.</p>
</td>
</tr>
</tbody>
</table>

## Directory Structure<a name="section1464106163817"></a>

```
utils/native/lite/                 # Root directory
├── file                        # Implementation of the file system APIs
├── hals                        # HAL directory
│   └── file                   # Header files of the hardware abstraction layer for file operations
├── include                     # Header files of external APIs
├── js                          # JavaScript APIs
│   └── builtin					
│       ├── common
│       ├── deviceinfokit       # Device information kit
│       ├── filekit             # File kit
│       └── kvstorekit          # KV store kit
├── kal                          # KAL directory
│   └── timer                   # KAL implementation of the timer
├── kv_store	                    # KV store implementation
│   ├── innerkits               # Internal KV store APIs
│   └── src	                    # KV store source file
├── memory
│   └── include                 # Memory pool management APIs
├── os_dump                      # System attribute dumping
├── timer_task                   # Timer implementation
└── unittest                     # Self-test cases

base/iot_hardware                   # IoT peripheral control
├── frameworks          
│   └── wifiiot_lite            # Implementation of the IoT peripheral control module
├── hals
│   └── wifiiot_lite            # HAL API declaration
└── interfaces
    └── kits                     # APIs of the IoT peripheral control module

vendor/hisi/hi3861/hi3861_adapter/hals/iot_hardware  # HAL for IoT peripheral control
└── wifiiot_lite                 # Implementation of the APIs at the HAL
```

## Usage<a name="section83091355151312"></a>

-   **KV store**

    ```
    // Store or update the value of a key.
    const char key1[] = "key_sample";
    const char defValue[] = "test case of key value store.";
    int ret = UtilsSetValue(key1, defValue);
    
    // Obtain the value of the key.
    char value1[32] = {0};
    ret = UtilsGetValue(key1, value1, 32);
    
    // Delete the value of the key.
    UtilsDeleteValue(key1);
    ```

-   **File operation**

    ```
    // Open or create a file.
    const char fileName[] = "testfile";
    int fd = UtilsFileOpen(fileName, O_RDWR_FS | O_CREAT_FS | O_TRUNC_FS, 0);
    
    // Write a specified length of data into a file with the specified file descriptor.
    const char defValue[] = "test case of file system.";
    int ret = UtilsFileWrite(fd, defValue, strlen(defValue));
    
    // Close a file with a specified file descriptor.
    UtilsFileClose(fd);
    
    // Obtain the file size.
    int fileLen = 0;
    ret = UtilsFileStat(fileName, &fileLen);
    printf("file size = %d\n", fileLen);
    
    // Adjust the read and write position offset in a file.
    int fd1 = UtilsFileOpen(fileName, O_RDWR_FS, 0);
    ret = UtilsFileSeek(fd1, 5, SEEK_SET_FS);
    
    // Read a specified length of data from a file with the specified file descriptor and write the data into the buffer.
    char buf[32] = {0};
    int readLen = UtilsFileRead(fd1, buf, 32);
    ret = UtilsFileClose(fd1);
    printf("read len = %d : buf = %s\n", readLen, buf);
    
    // Delete a specified file.
    ret = UtilsFileDelete(fileName);
    ```


-   **System attribute dumping**

    LiteOS Cortex-M kernel: Run the following command over the serial port to dump the current system parameters:

    ```
    AT+SYSPARA
    ```

    LiteOS Cortex-A kernel: Run the  **os\_dump**  command in the  **bin**  directory to dump the current system parameters:

    ```
    ./bin/os_dump syspara
    ```


## Repositories Involved<a name="section6250105871917"></a>

**utils**

[utils\_native\_lite](https://gitee.com/openharmony/utils_native_lite/blob/master/README.md)

[iothardware\_peripheral](https://gitee.com/openharmony/iothardware_peripheral/blob/master/README.md)

