# chmod


## Command Function

This command is used to change file operation permissions.


## Syntax

chmod [_mode_] [_filename_]


## Parameters

**Table 1** Parameter description

| Parameter    | Description                                                    | Value Range      |
| -------- | ------------------------------------------------------------ | -------------- |
| mode     | Specifies the permissions for a file or directory. The value is an octal number, representing the permission of **User** (owner), **Group** (group), or **Others** (other groups).| [0, 777]        |
| filename | Specifies the file path.                                    | An existing file |


## Usage Guidelines

- Specify **mode** to change file permissions.

- For the files created on the FAT file system, the file permission attributes are the same as those of the mounted nodes. Currently, the node permissions include only user read and write. The **group** and **others** permissions do not take effect. In addition, only the user read and write permissions can be modified. The read and write permissions are **rw** and **ro** only. There is no such restriction for other file systems.

## Note

Currently, the shell does not support this command.

## Example

Change the permissions on the **hello-openharmony.txt** file to **644** and **777**.


## Output

Modify the permissions on the **hello-openharmony.txt** file in the **/dev** directory.

```
OHOS:/dev$ chmod 644 hello-openharmony.txt
OHOS:/dev$ ll hello-openharmony.txt
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 hello-openharmony.txt
OHOS:/dev$ chmod 777 hello-openharmony.txt
OHOS:/dev$ ll hello-openharmony.txt
-rwxrwxrwx 0 0 0 0 1970-01-01 00:00 hello-openharmony.txt
```
