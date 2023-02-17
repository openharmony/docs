# chgrp


## Command Function

This command is used to change the file group.


## Syntax

chgrp [_group_] [_pathname_]


## Parameters

**Table 1** Parameter description

| Parameter    | Description  | Value Range      |
| -------- | ---------- | -------------- |
| group    | Specifies the target file group.| [0, 0xFFFFFFFF] |
| pathname | Specifies the file path. | An existing file |


## Usage Guidelines

- Specify **group** to change the file group.
- For the FAT file system, this command cannot be used to change user group IDs.

## Note

Currently, the shell does not support this command.

## Example

Run **chgrp 100 testfile**.


## Output

Change the group ID of the **testfile** file in the **dev/** directory to **100**.

```
OHOS:/dev$ ll testfile
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 testfile
OHOS:/dev$ chgrp 100 testfile                                           
OHOS:/dev$ ll testfile                                                   
-rw-r--r-- 0 0 100 0 1970-01-01 00:00 testfile
OHOS:/dev$
```
