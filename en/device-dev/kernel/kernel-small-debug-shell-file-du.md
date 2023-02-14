# du


## Command Function

This command is used to query the disk space occupied by a file.


## Syntax

du [_-kKmh_] [_file..._]


## Parameters

**Table 1** Parameter description

| Parameter  | Description                                                    |
| ------ | ------------------------------------------------------------ |
| --help | Displays the parameters supported by the **du** command.                                  |
| -k     | Displays the occupied blocks, each of which is 1024 bytes by default.                       |
| -K     | Displays the occupied blocks, each of which is 512 bytes (POSIX).                   |
| -m     | Displays the disk space in MB.                                              |
| -h     | Displays the disk space in human-readable format K, M, and G, for example, **1K**, **243M**, or **2G**.|
| file   | Specifies the target file.                                      |


## Usage Guidelines

- The **du** command is used to obtain the disk usage of a file rather than a directory.

- The value of **file** must be the file name. It cannot contain the directory where the file is located.

## Note

Currently, the shell does not support this command. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run **du -h testfile**.


## Output

Disk space occupied by **testfile**.

```
OHOS:/$ du -h testfile
1.8K    testfile
```
