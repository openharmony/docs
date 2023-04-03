# dmesg


## Command Function

This command is used to display system boot and running information.


## Syntax

dmesg

dmesg [_-c/-C/-D/-E/-L/-U_]

dmesg -s [_size_]

dmesg -l [_level_]

dmesg &gt; [_fileA_]


## Parameters

**Table 1** Parameter description

| Parameter           | Description                                | Value Range       |
| --------------- | ---------------------------------------- | --------------- |
| -c              | Prints content in the buffer and clears the buffer.            | N/A             |
| -C              | Clears the buffer.                            | N/A             |
| -D/-E           | Disables or enables printing to the console.                   | N/A             |
| -L/-U           | Disables or enables printing via the serial port.                     | N/A             |
| -s&nbsp;size    | Sets the size of the buffer. size specifies the buffer size to set.| N/A             |
| -l&nbsp;level   | Sets the buffering level.                          | [0, 5] |
| &gt;&nbsp;fileA | Writes the content in the buffer to a file.            | N/A             |


## Usage Guidelines

- This command can be used only after **LOSCFG_SHELL_DMESG** is enabled. To enable **LOSCFG_SHELL_DMESG**, run the **make menuconfig** command in **kernel/liteos_a**. In the displayed dialog box, locate the **Debug** option and set **Enable Shell dmesg** to **Yes**.
  Debug  ---&gt; Enable a Debug Version ---&gt; Enable Shell ---&gt; Enable Shell dmesg

- If no parameter is specified, all content in the buffer is printed.

- The parameters followed by hyphens (-) are mutually exclusive.
  1. Before writing content to a file, ensure that the file system has been mounted.
  2. Disabling the serial port printing will adversely affect shell. You are advised to set up a connection using Telnet before disabling the serial port.


## Example

Run **dmesg> dmesg.log**.


## Output

Write the content in the buffer to the **dmesg.log** file.

```
OHOS # dmesg > dmesg.log
Dmesg write log to dmesg.log success
```
