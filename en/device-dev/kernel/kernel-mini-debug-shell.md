# Shell

The shell provided by the OpenHarmony kernel supports basic debugging functions and provides commands related to the system, files, and network. It also supports commands customized based on service requirements.

The shell function is used for debugging only. Currently, it does not support the functions such as tab completion and undo with a key.

Some commands can be used only after the corresponding options are enabled by using **make menuconfig**.

## Common Shell Commands

### cat

Displays the content of a text file. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

cat [FILE]

#### Parameters

| Parameter| Description  | Value Range      |
| ---- | ---------- | -------------- |
| FILE | File path.| An existing file.|

### cd

Changes the current directory. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

cd [path]

#### Parameters

| Parameter| Description  | Value Range      |
| ---- | ---------- | -------------- |
| path | File path.| Path of the new directory.|

### cp

Copies a file. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

cp [SOURCEFILE] [DESTFILE]

#### Parameters

| Parameter      | Description      | Value Range                                 |
| ---------- | -------------- | ----------------------------------------- |
| SOURCEFILE | Path of the file to copy.  | Currently, only files are supported. Directories are not supported. The file cannot be empty.|
| DESTFILE   | Path of the file created.| Directory and file names are supported. The directory must exist.         |

### date

Queries the system date and time.

#### Format

date

#### Parameters

None.

### free

Displays the memory usage of the system.

#### Format

free [ -k | -m ]

#### Parameters

| Parameter| Description         | Value Range|
| ---- | ----------------- | -------- |
| -k   | Display the memory usage in KiB.| N/A      |
| -m   | Display the memory usage in MiB.| N/A      |

### help

Displays all commands in this operating system.

#### Format

help

#### Parameters

None.

### ifconfig

Displays the IP address, network mask, gateway, and MAC address of a network adapter. This command can be used only after **LWIP_SHELLCMD_ENABLE** is enabled.

#### Format

ifconfig

#### Parameters

None.

### ls

Displays the content of a directory. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

ls  [DIRECTORY]

#### Parameters

| Parameter     | Description  | Value Range                                                    |
| --------- | ---------- | ------------------------------------------------------------ |
| DIRECTORY | Path of the directory.| If **DIRECTORY** is not specified, the content of the current directory is displayed.<br>If **DIRECTORY** is a valid directory, the content of the specified directory is displayed.<br>Currently, LiteOS-M does not support the root directory /.|

### memusage

Displays the memory waterline.

#### Format

memusage [-k/-m]

#### Parameters

| Parameter| Description         | Value Range|
| ---- | ----------------- | -------- |
| -k   | Display the memory usage in KiB.| N/A      |
| -m   | Display the memory usage in MiB.| N/A      |

### mkdir

Creates a directory. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

mkdir [DIRECTORY]

#### Parameters

| Parameter     | Description  | Value Range                             |
| --------- | ---------- | ------------------------------------- |
| DIRECTORY | Path of the directory.| The value of **DIRECTORY** can be an absolute path or a relative path.|

### ping

Checks whether the network is connected. This command can be used only after **LWIP_SHELLCMD_ENABLE** is enabled.

#### Format

ping [ip]

#### Parameters

| Parameter| Description                      | Value Range|
| ---- | ------------------------------ | -------- |
| ip   | IPv4 address of the network to test.| N/A      |

### pwd

Displays the current path. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

pwd

### rm

Deletes a file or folder. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

rm [FILE] or rm [-r/-R] [FILE]

#### Parameters

| Parameter | Description                       | Value Range                        |
| ----- | ------------------------------- | -------------------------------- |
| FILE  | File or folder name.| The value of **FILE** can be an absolute path or a relative path.|
| -r/-R | If **FILE** is a folder, -r/-R needs to be set.   | N/A                              |

### rmdir

Deletes a folder. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

rmdir [DIRECTORY]

#### Parameters

| Parameter     | Description  | Value Range                             |
| --------- | ---------- | ------------------------------------- |
| DIRECTORY | Path of the directory.| The value of **DIRECTORY** can be an absolute path or a relative path.|

### task

Displays the status of each task.

#### Format

task

The displayed information includes the task No., priority, status, stack information, signal, event, CPU usage, and task name.

### touch

Creates a file. This command can be used only after **LOSCFG_FS_VFS** is enabled.

#### Format

touch [FILE]

#### Parameters

| Parameter| Description| Value Range                        |
| ---- | -------- | -------------------------------- |
| FILE | File name.| The value of **FILE** can be an absolute path or a relative path.|

### stack

Displays the stack information of a task. This command can be used only after **LOSCFG_DEBUG_TOOLS** is enabled. Enabling this function affects the performance.

#### Format

stack [ID]

#### Parameters

| Parameter| Description| Value Range                |
| ---- | -------- | ------------------------ |
| ID   | Task ID.| The task corresponding to the task ID must exist.|

### hwi

Queries the interrupt usage. This command can be used only after **LOSCFG_DEBUG_TOOLS** is enabled. Enabling this function affects the performance.

#### Format

hwi

### st

Queries scheduling information. This command can be used only afterf **LOSCFG_DEBUG_TOOLS** is enabled. Enabling this function affects the performance.

#### Format

st -s | st -e

#### Parameters

| Parameter| Description              | Value Range|
| ---- | ---------------------- | -------- |
| -s   | Start to record scheduling information.      | N/A      |
| -e   | Stop recording and print scheduling information.| N/A      |
