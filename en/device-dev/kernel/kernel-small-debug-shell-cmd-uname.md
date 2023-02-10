# uname


## Command Function

This command is used to display the name, version creation time, system name, and version information of the current operating system.


## Syntax

uname [_-a | -s | -r | -m | -n | -v | --help_]


**Table 1** Parameter description

| Parameter  | Description               |
| ------ | ----------------------- |
| --help | Displays help information.|
| No parameter| Displays the operating system name by default. |
| -a     | Displays all data.         |
| -s     | Displays the operating system name.     |
| -r     | Displays the kernel release version.     |
| -m     | Displays the operating system architecture name.     |
| -n     | Displays the network domain name of the host. |
| -v     | Displays version information.         |


## Usage Guidelines

- The **uname** command displays the name of the current operating system by default.

- Except **--help** and **-a**, other parameters can be used together. **uname -a** is equivalent to **uname -srmnv**.

## Note

The **-r**, **-m**, and **-n** parameters are not supported currently. mksh supports these parameters. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- uname -a

- uname -ms


## Output

Example 1: all information of the operating system

```
OHOS:/$ uname -a
LiteOS hisilicon 2.0.0.37 LiteOS 2.0.0.37 Oct 21 2021 17:39:32 Cortex-A7
OHOS:/$
```

Example 2: operating system name and architecture

```
OHOS:/$ uname -ms
LiteOS Cortex-A7
OHOS:/$
```
