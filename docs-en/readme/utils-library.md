# Utils Library<a name="EN-US_TOPIC_0000001052623010"></a>

## Overview<a name="section11660541593"></a>

The Utils library stores basic components of OpenHarmony. These basic components are used by OpenHarmony service subsystems and upper-layer applications.

The Utils library provides the following capabilities on different platforms:

-   LiteOS-M platform: KV stores, file operations, timers, and IoT peripheral control
-   LiteOS-A platform: KV stores, timers, and ACE JavaScript APIs

## Directory Structure<a name="section1464106163817"></a>

```
utils/native/lite/          # Root directory of the Utils library
├── file            # Implementation of the file interface
├── hals            # HAL directory
│   └── file       # Header files of the hardware abstraction layer for file operations
├── include         # Files of external interfaces provided by the Utils library
├── js                          # ACE JavaScript API directory                 
│   └── builtin					
│       ├── common
│       ├── deviceinfokit       # Device information kit
│       ├── filekit             # File kit
│       └── kvstorekit          # KV store kit
├── kal             # KAL directory
│   └── timer      # KAL implementation of the timer
 ├── kv_store	       # KV store implementation
│   ├── innerkits   # Internal KV store interfaces
│   └── src	        # KV store source file
└── timer_task       # Timer implementation

base/iot_hardware          # IoT peripheral control
├── frameworks          
│   └── wifiiot_lite   # Implementation of the IoT peripheral control module
├── hals
│   └── wifiiot_lite   # HAL interfaces
└── interfaces
    └── kits            # Interfaces of the IoT peripheral control module

vendor/hisi/hi3861/hi3861_adapter/hals/iot_hardware  # HAL for IoT peripheral control
└── wifiiot_lite       # Implementation of the interfaces at the HAL
```

## Constraints<a name="section1718733212019"></a>

The Utils library is developed using the C language.

**Table  1**  Capabilities and constraints of the Utils library

<a name="table1361018216112"></a>
<table><thead align="left"><tr id="row1661115214112"><th class="cellrowborder" valign="top" width="12.659999999999998%" id="mcps1.2.5.1.1"><p id="p1261115231118"><a name="p1261115231118"></a><a name="p1261115231118"></a>Component</p>
</th>
<th class="cellrowborder" valign="top" width="14.78%" id="mcps1.2.5.1.2"><p id="p11611825118"><a name="p11611825118"></a><a name="p11611825118"></a>Platform</p>
</th>
<th class="cellrowborder" valign="top" width="32.22%" id="mcps1.2.5.1.3"><p id="p1336312010465"><a name="p1336312010465"></a><a name="p1336312010465"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="40.339999999999996%" id="mcps1.2.5.1.4"><p id="p1833742934815"><a name="p1833742934815"></a><a name="p1833742934815"></a>Constraint</p>
</th>
</tr>
</thead>
<tbody><tr id="row10455841151112"><td class="cellrowborder" valign="top" width="12.659999999999998%" headers="mcps1.2.5.1.1 "><p id="p1945511415113"><a name="p1945511415113"></a><a name="p1945511415113"></a>KV store</p>
</td>
<td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.2.5.1.2 "><p id="p668274310317"><a name="p668274310317"></a><a name="p668274310317"></a>LiteOS-M and LiteOS-A platforms</p>
</td>
<td class="cellrowborder" valign="top" width="32.22%" headers="mcps1.2.5.1.3 "><p id="p193638017460"><a name="p193638017460"></a><a name="p193638017460"></a>Provides KV storage for applications.</p>
</td>
<td class="cellrowborder" valign="top" width="40.339999999999996%" headers="mcps1.2.5.1.4 "><p id="p1733717294484"><a name="p1733717294484"></a><a name="p1733717294484"></a>N/A</p>
</td>
</tr>
<tr id="row540314384111"><td class="cellrowborder" valign="top" width="12.659999999999998%" headers="mcps1.2.5.1.1 "><p id="p134041038141112"><a name="p134041038141112"></a><a name="p134041038141112"></a>File operation</p>
</td>
<td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.2.5.1.2 "><p id="p19404193811110"><a name="p19404193811110"></a><a name="p19404193811110"></a>LiteOS-M platform</p>
</td>
<td class="cellrowborder" valign="top" width="32.22%" headers="mcps1.2.5.1.3 "><p id="p113646084618"><a name="p113646084618"></a><a name="p113646084618"></a>Provides unified file operation interfaces that can be used on different underlying chip components.</p>
</td>
<td class="cellrowborder" valign="top" width="40.339999999999996%" headers="mcps1.2.5.1.4 "><p id="p83372029154819"><a name="p83372029154819"></a><a name="p83372029154819"></a>N/A</p>
</td>
</tr>
<tr id="row175322121218"><td class="cellrowborder" valign="top" width="12.659999999999998%" headers="mcps1.2.5.1.1 "><p id="p1053219131219"><a name="p1053219131219"></a><a name="p1053219131219"></a>Timer</p>
</td>
<td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.2.5.1.2 "><p id="p1912957139"><a name="p1912957139"></a><a name="p1912957139"></a>LiteOS-M and LiteOS-A platforms</p>
</td>
<td class="cellrowborder" valign="top" width="32.22%" headers="mcps1.2.5.1.3 "><p id="p15364170194610"><a name="p15364170194610"></a><a name="p15364170194610"></a>Provides unified timer operation interfaces that can be used on different underlying chip components.</p>
</td>
<td class="cellrowborder" valign="top" width="40.339999999999996%" headers="mcps1.2.5.1.4 "><p id="p633742915481"><a name="p633742915481"></a><a name="p633742915481"></a>N/A</p>
</td>
</tr>
<tr id="row1821629675"><td class="cellrowborder" valign="top" width="12.659999999999998%" headers="mcps1.2.5.1.1 "><p id="p198212291879"><a name="p198212291879"></a><a name="p198212291879"></a>IoT peripheral control</p>
</td>
<td class="cellrowborder" valign="top" width="14.78%" headers="mcps1.2.5.1.2 "><p id="p13827290715"><a name="p13827290715"></a><a name="p13827290715"></a>LiteOS-M platform</p>
</td>
<td class="cellrowborder" valign="top" width="32.22%" headers="mcps1.2.5.1.3 "><p id="p4822295710"><a name="p4822295710"></a><a name="p4822295710"></a>Provides the capability of performing operations for peripherals.</p>
</td>
<td class="cellrowborder" valign="top" width="40.339999999999996%" headers="mcps1.2.5.1.4 ">&nbsp;&nbsp;</td>
</tr>
</tbody>
</table>

## Usage<a name="section83091355151312"></a>

-   **KV store**

    Obtaining an interface

    ```
    char key1[] = "rw.sys.version";
    char value1[32] = {0};
    int ret = UtilsGetValue(key1, value1, 32);
    Setting the interface
    char key14[] = "key_14";
    ret = UtilsSetValue(key14, defValue);
    ```

-   **File operation**

    ```
    // open && write
    char fileName[] = "testfile";
    int fd = UtilsFileOpen(fileName, O_RDWR_FS | O_CREAT_FS | O_TRUNC_FS, 0);
    printf("file handle = %d\n", fd);
    int ret = UtilsFileWrite(fd, def, strlen(def));
    printf("write ret = %d\n", ret);
    // stat
    int fileLen = 0;
    ret = UtilsFileStat(fileName, &fileLen);
    printf("file size = %d\n", fileLen);
    // seek
    int fd1 = UtilsFileOpen(fileName, O_RDWR_FS, 0);
    ret = UtilsFileSeek(fd1, 5, SEEK_SET_FS);
    printf("lseek ret = %d\n", ret);
    char buf[32] = {0};
    int readLen = UtilsFileRead(fd1, buf, 32);
    ret = UtilsFileClose(fd1);
    printf("read len = %d : buf = %s\n", readLen, buf);
    // delete
    ret = UtilsFileDelete(fileName);
    printf("delete ret = %d\n", ret);
    ```


## Repositories Involved<a name="section6250105871917"></a>

iothardware\_frameworks\_wifiiot\_lite

iothardware\_hals\_wifiiot\_lite

iothardware\_interfaces\_kits\_wifiiot\_lite

utils\_native\_lite

