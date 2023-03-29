# touch


## Command Function

- This command is used to create an empty file in a specified directory.

- If this command is executed to create an existing file, the execution will be successful but the timestamp will not be updated.


## Syntax

touch [_filename_]


## Parameters

  **Table 1** Parameter description

| Parameter    | Description                   | Value Range|
| -------- | --------------------------- | -------- |
| --help   | Displays the parameters supported by the **touch** command.| N/A      |
| filename | Specifies the name of the file to create.       | N/A      |


## Usage Guidelines

- The **touch** command creates an empty file that is readable and writeable.

- You can use the **touch** command to create multiple files at a time.

  > **NOTICE**<br>
  > If you run the **touch** command to create a file in a directory storing important system resources, unexpected results such as a system breakdown may occur. For example, if you run the **touch uartdev-0** command in the **/dev** directory, the system may stop responding.

## Note

The shell does not support **--help**  or creation of multiple files at the same time. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- touch file.c

- touch testfile1 testfile2 testfile3


## Output

Example 1: Create a file named **file.c**.


```
OHOS:/tmp$ ls
OHOS:/tmp$ touch file.c
OHOS:/tmp$ ls
file.c
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 file.c*
```

Example 2: Create three files (**testfile1**, **testfile2**, and **testfile3**) at a time.


```
*OHOS:/tmp$
OHOS:/tmp$ touch testfile1 testfile2 testfile3
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile1*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile2*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile3*
OHOS:/tmp$
```
