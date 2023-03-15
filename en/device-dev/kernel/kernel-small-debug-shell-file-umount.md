# umount


## Command Function

This command is used to unmount a file system.


## Syntax

umount [_-a [-t TYPE]_] [_dir_]


## Parameters

**Table 1** Parameter description

| Parameter  | Description                                                    | Value Range                  |
| ------ | ------------------------------------------------------------ | -------------------------- |
| --help | Displays the parameters supported by the **umount** command.                              | N/A                        |
| -a     | Unmounts all file systems mounted.                                      | N/A                        |
| -t     | Used together with the **-a** option to restrict the file systems specified by **-a**, allowing only the file system specified by **-t** to be unmounted.| N/A                        |
| dir    | Specifies the directory from which the file system is to be unmounted.                              | Directory mounted with the file system|


## Usage Guidelines

By specifying the **dir** parameter in the **unmount** command, you can unmount the specified file system.

## Note

The shell does not support this command. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- umount ./nfs

- umount -a -t nfs


## Output



Example 1: Unmount the file system from **./nfs**.


```
OHOS:/$ umount ./nfs/
umount ok
```

Example 2: Unmount all NFS directories.


```
OHOS:/$ umount -a -t nfs
umount ok
```
