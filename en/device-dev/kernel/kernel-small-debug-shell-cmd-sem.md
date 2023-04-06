# sem


## Command Function

This command is used to query information about kernel semaphores.


## Syntax

sem [_ID__ / fulldata_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| ID | Specifies the semaphore ID.| [0, 1023] or [0x0, 0x3FF]|
| fulldata | Displays information about all semaphores in use. <br/>The displayed information includes **SemID**, **Count**, **Original Count**, **Creator TaskEntry**, and **Last Access Time**. | N/A |


## Usage Guidelines

- If no parameter is specified, this command displays the semaphore IDs and the number of times that each semaphore is used.

- If **ID** is specified, the use of the specified semaphore is displayed.

- The **fulldata** parameter depends on **LOSCFG_DEBUG_SEMAPHORE**. Before using this parameter, set **Enable Semaphore Debugging** to **Yes** on **menuconfig**.
  **Debug**  ---&gt; **Enable a Debug Version** ---&gt; **Enable Debug LiteOS Kernel Resource** ---&gt; E**nable Semaphore Debugging**


## Example

- Run **sem**.

- Configure **LOSCFG_DEBUG_SEMAPHORE** and run **sem fulldata**.


## Output

Example 1: brief semaphore information

```
OHOS # sem
   SemID       Count
   ----------  -----
   0x00000000  1
   SemID       Count
   ----------  -----
   0x00000001  0
   SemID       Count
   ----------  -----
   0x00000002  0
   SemID       Count
   ----------  -----
   0x00000003  1
   SemID       Count
   ----------  -----
   0x00000004  0
   SemID       Count
   ----------  -----
   0x00000005  1
   SemID       Count
   ----------  -----
   0x00000006  0
```

**Table 2** Output description

| Parameter| Description|
| -------- | -------- |
| SemID | Semaphore ID.|
| Count | Number of times that the semaphore is used.|

> **NOTE**<br>
> The **ID** value can be in decimal or hexadecimal format.
> 
> When **ID** is a value within [0, 1023], semaphore information of the specified ID is displayed. If the specified semaphore is not used, a message is displayed to inform you of this case. For other values, a message is displayed indicating that the parameter is incorrect.

Example 2: detailed semaphore information

```
OHOS # sem fulldata
Used Semaphore List:
   SemID    Count    OriginalCount   Creator(TaskEntry)    LastAccessTime
   ------   ------   -------------   ------------------    --------------
   0xb      0x0      0x0             0x404978fc            0xa1
   0xc      0x0      0x0             0x404978fc            0xa1
   0xd      0x0      0x0             0x404978fc            0x12c
   0x10     0x0      0x0             0x404978fc            0x195
   0xf      0x0      0x0             0x404978fc            0x195
   0x11     0x0      0x0             0x4041a998            0x1d5
   0x15     0x0      0x0             0x404978fc            0x273
   0x14     0x0      0x0             0x404978fc            0x273
   0x18     0x0      0x0             0x404978fc            0x352
   0x17     0x0      0x0             0x404978fc            0x352
   0x16     0x0      0x0             0x404978fc            0x352
   0x1d     0x1      0x1             0x404978fc            0x385
   0x1e     0x1      0x1             0x404978fc            0x388
   0x1f     0x1      0x1             0x404978fc            0x38d
   0x20     0x1      0x1             0x404978fc            0x38f
   0x21     0x1      0x1             0x404978fc            0x392
   0x3d     0x1      0x1             0x404978fc            0x395
   0x3b     0x1      0x1             0x404978fc            0x395
   0x3c     0x1      0x1             0x404978fc            0x395
   0x39     0x1      0x1             0x404978fc            0x395
   0x3a     0x1      0x1             0x404978fc            0x395
   0x33     0x1      0x1             0x404978fc            0x395
   0x35     0x1      0x1             0x404978fc            0x395
   0x34     0x1      0x1             0x404978fc            0x395
   0x38     0x1      0x1             0x404978fc            0x395
```

**Table 3** Output description

| Parameter| Description|
| -------- | -------- |
| SemID | Semaphore ID.|
| Count | Number of times that the semaphore is used.|
| OriginalCount | Original count of the semaphore.|
| Creator | Address of the entry function of the thread used to create the semaphore.|
| LastAccessTime | Last time when the semaphore was accessed.|
