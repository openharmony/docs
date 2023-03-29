# chown


## Command Function

This command is used to change the owner of a file.


## Syntax

chown [_owner_] [_pathname_]


## Parameters

**Table 1** Parameter description

| Parameter    | Description    | Value Range      |
| -------- | ------------ | -------------- |
| owner    | Specifies the file owner. | [0, 0xFFFFFFFF] |
| pathname | Specifies the file path. | An existing file |


## Usage Guidelines

This command does not apply to the FAT file system.

## Note

Currently, the shell does not support this command.

## Example

Run **chown 100 testfile**.


## Output

Change the UID of the **testfile** file in **/dev** to **100**.

```
OHOS:/dev$ touch testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 0 100 0 1970-01-01 00:00 testfile
OHOS:/dev$ chown 100 testfile
OHOS:/dev$ ll testfile
-rw-r--r-- 0 100 100 0 1970-01-01 00:00 testfile
```
