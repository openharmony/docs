# mount


## Command Function

This command is used to mount a device to a specified directory.


## Syntax

mount [_-f_] [_-t TYPE_] [_-o OPTION,_] [[_DEVICE_] _DIR_]


## Parameters

**Table 1** Parameter description

| Parameter  | Description                                                   | Value Range                                                    |
| ------ | ----------------------------------------------------------- | ------------------------------------------------------------ |
| --help | Displays the parameters supported by the **mount** command.                              | N/A                                                          |
| -f     | Fakes mounting the file system (no mounting is actually performed).                             | N/A                                                          |
| -t     | Specifies the file system type.                                           | vfat, yaffs, jffs, ramfs, nfs, procfs, romfs|
| -o     | Specifies the mount options.                                                 | N/A                                                          |
| DEVICE | Specifies the device to mount (in the format of the device directory).                       | A device in the system                                            |
| DIR    | Specifies the directory.<br>You must have the execution (search) permission on the specified directory.| N/A                                                          |


## Usage Guidelines

By specifying the device to mount, directory, and file system format in the **mount** command, you can successfully mount the file system to the specified directory.

## Note

Currently, the shell does not support this command. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run **mount -t nfs 192.168.1.3:/nfs nfs**.


## Output

Mount the **nfs** directory on the server with IP address of **192.168.1.3** to the newly created **/nfs** directory in the current system.


```
OHOS:/$ mkdir nfs
OHOS:/$ mount -t nfs 192.168.1.3:/nfs nfs
Mount nfs on 192.168.1.3:/nfs, uid:0, gid:0
Mount nfs finished.
OHOS:/$ ls nfs/
16d.xml         gpio_test             ohos_test.txt    userfs_vfat.img
OHOS_Image.bin  hello                 rootfs_vfat.img
dev_tools       mksh_rootfs_vfat.img  test_demo
```
