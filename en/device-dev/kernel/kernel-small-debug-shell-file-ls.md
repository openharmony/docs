# ls


## Command Function

This command is used to display the content of a directory.


## Syntax

ls [_-ACHLSZacdfhiklmnopqrstux1_] [_--color_[_=auto_]] [_directory..._]

> **NOTE**<br>
>  During the system boot process, **ls=toybox ls --color=auto**, **ll = ls -alF**, **la=ls -A**, and **l=ls -CF** commands have been enabled using **alias** so that the initial actions of these commands are the same as those on Linux. For details, see **Output**. To view help information, run **toybox ls --help**.


## Parameters

**Table 1** Command parameter description

| Parameter  | Description                                                    | Value Range                     |
| ------ | ------------------------------------------------------------ | ----------------------------- |
| --help | Displays parameters supported by the **ls** command and their usage.                        | N/A                           |
| -a     | Displays all files, including hidden files.                     | N/A                           |
| -b     | Escapes non-graphical characters.                                            | N/A                           |
| -c     | Uses **ctime** as the file timestamp. This parameter must be used together with **-l**.       | N/A                           |
| -d     | Displays only the directory, rather than listing the content of the directory.                      | N/A                           |
| -i     | Displays the node ID of a file.                                          | N/A                           |
| -p     | Adds a slash (/) after the directory.                                     | N/A                           |
| -q     | Displays non-printable characters, such as "?".                                   | N/A                           |
| -s     | Provides information about the memory occupied by the directory and its members, in 1024 bytes.          | N/A                           |
| -u     | Uses the last access time of the file as the timestamp. This option is used together with **-l**.  | N/A                           |
| -A     | Lists all files except implied . and ..                                       | N/A                           |
| -H     | Follows symbolic links listed in the command line.                                        | N/A                           |
| -L     | Follows symbolic links.                                              | N/A                           |
| -Z     | Displays security context.                                                | N/A                           |
| path   | Specifies the path of the target directory.<br/>If **path** is left blank, the content of the current directory is displayed.<br>If **path** is an invalid directory, "ls&nbsp;error:&nbsp;No&nbsp;such&nbsp;directory." is displayed.<br><br>If **path** is a valid directory, the content of the specified directory is displayed. | Left blank<br>A valid directory|

**Table 2** Output format parameters

| Parameter   | Description                               |
| ------- | --------------------------------------- |
| -1      | Lists one file per line.                     |
| -c      | Lists entries by column.                         |
| -g      | Like **-l**, but do not list the owner. |
| -h      | Displays the total size of files in the directory, in KiB.|
| -l      | Displays detailed information about files in the directory.       |
| -m      | Fills width with a list of entries separated by a comma.                     |
| -n      | Like **-l**, but lists numeric user and group IDs.|
| -o      | Like **-l**, but do not list group information. |
| -x      | Lists entries by line, instead of by column.                         |
| -ll     | Lists the file time attribute as ns.               |

**Table 3** Parameters for sorting (by the initial letter by default)

| Parameter| Description                                  |
| ---- | ------------------------------------------ |
| -f   | Do not sort.                                  |
| -r   | Sorts in reverse order.                        |
| -t   | Sorts by time, newest first.|
| -S   | Sorts by file size, largest first.          |

**Table 4** Color printing

| Parameter| Default Configuration                                  |
| ---- | ------------------------------------------ |
| --color  | device=yellow symlink=turquoise/red dir=blue socket=purple files: exe=green suid=red suidfile=redback stickydir=greenback=auto means detect if output is a tty. |

## Usage Guidelines

The file node information of the FAT file system inherits from its parent node. The parent node ID is **0**. Therefore, if you run the **ls -i** command on the Hi3516D V300 development board, the file node IDs displayed are all **0**.


## Note

The shell does not support **ls** parameters. mksh supports them. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- ls

- ll


## Output

Example 1: **ls** command output

```
OHOS:/$ ls
bin  etc  nfs   sdcard   system    usr
dev  lib  proc  storage  userdata  vendor
```

Example 2: **ll** command output

```
OHOS:/$ ll
total 20
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 bin/
drwxr-xr-x 0 0 0    0 1970-01-01 00:00 dev/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 etc/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 lib/
drwxrwxrwx 0 0 0 4096 2021-10-25 02:17 nfs/
dr-xr-xr-x 0 0 0    0 1970-01-01 00:00 proc/
drwxrwxrwx 1 0 0 4096 1979-12-31 00:00 sdcard/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 storage/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 system/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 userdata/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 usr/
drwxrwxrwx 1 0 0 2048 2021-11-21 17:52 vendor/
```
