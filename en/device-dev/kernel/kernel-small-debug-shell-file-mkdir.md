# mkdir


## Command Function

This command is used to create a directory.


## Syntax

mkdir [_-vp_] [_-m mode_] [_dirname..._]


## Parameters

**Table 1** Parameter description

| Parameter     | Description                      |
| --------- | ------------------------------ |
| --help    | Displays the parameters supported by the **mkdir** command.   |
| -m        | Sets the permissions on the directory to create.      |
| -p        | Creates parent and child directories recursively.        |
| -v        | Prints detailed information about the directory creation process.|
| directory | Specifies the directory to create.              |


## Usage Guidelines

For the files created on the FAT file system, the file permission attributes are the same as those of the mounted nodes. Currently, the node permissions include only user read and write. The **group** and **others** permissions do not take effect.

In addition, only the user read and write permissions can be modified. The read and write permissions are **rw** and **ro** only. Therefore, when the **-m** option is specified in the **mkdir** command, only **777** and **555** permissions are available for the created directory, and the execute permission does not take effect.

## Note

Currently, the shell does not support this command. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- mkdir testpath

- mkdir -m 777 testpath

- mkdir -pv testpath01/testpath02/testpath03

## Output

Example 1: Create a directory named **testpath**.


```
OHOS:/tmp$ mkdir testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

Example 2: Create a directory named **testpath** with specified permissions.


```
OHOS:/tmp$ mkdir -m 777 testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

Example 3: Create directories recursively.


```
OHOS:/tmp$ mkdir -pv testpath01/testpath02/testpath03
mkdir: created directory 'testpath01'
mkdir: created directory 'testpath01/testpath02'
mkdir: created directory 'testpath01/testpath02/testpath03'
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath01/
OHOS:/tmp$ ll testpath01/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath02/
OHOS:/tmp$ ll testpath01/testpath02/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath03/
```
