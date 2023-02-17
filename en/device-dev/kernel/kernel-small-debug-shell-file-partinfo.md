# partinfo


## Command Function

This command is used to query information about the partitions of a hard disk or SD card identified by the system.


## Syntax

partinfo &lt;*dev*inodename_&gt;


## Parameters

  **Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| dev_inodename | Specifies the name of the partition to be queried.| A valid partition name| 


## Usage Guidelines

None.


## Example

Run **partinfo /dev/mmcblk0p0**.


## Output

System partition information:


```
OHOS # partinfo /dev/mmcblk0p0
part info :
disk id          : 0
part_id in system: 1
part no in disk  : 0
part no in mbr   : 0
part filesystem  : 00
part sec start   : 20480
part sec count   : 102400
```
