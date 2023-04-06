# rm


## Command Function

This command is used to delete a file or folder.


## Syntax

rm [_-fv_] *FILE or rm* [_-rv_] [_PATH_ | _filename_]...


## Parameters

**Table 1** Parameter description

| Parameter         | Description                                        |
| ------------- | ------------------------------------------------ |
| -r            | Deletes empty or non-empty directories.                          |
| -f            | Deletes a file or directory forcibly without confirmation. No error will be reported when a file that does not exist is to be deleted.|
| -v            | Displays the deletion process.                                |
| PATH/filename | Specifies the name of the file or directory to delete. The value can be a path.        |


## Usage Guidelines

- The **rm** command can be used to delete multiple files or folders at a time.

- You can run **rm -r** to delete a non-empty directory.

- If the **rm** command without **-f** is used to delete a file that does not exist, an error will be reported.

## Note

The shell does not support **-v** or **-f**. mksh supports them. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- rm testfile

- rm -r testpath/


## Output

Example 1: Delete **testfile**.


```
OHOS:/$ ls
bin  etc  proc    storage  testfile  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm testfile
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```

Example 2: Delete **testpath**, a non-empty directory.


```
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm -r testpath/
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```
