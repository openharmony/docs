# cp


## Command Function

This command is used to create a copy for a file.


## Syntax

cp [_SOURCEFILE_] [_DESTFILE_]


## Parameters

  **Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| --help | Displays help information.| N/A |
| SOURCEFILE | Specifies the file to copy.| This command does not support copy of a directory, but supports copy of multiple files at a time.|
| DESTFILE | Specifies the file to create.| Both a directory and a file are supported.|


## Usage Guidelines

- The name of the source file cannot be the same as that of the destination file in the same path.

- **SOURCEFILE** must exist and cannot be a directory.

- The source file path supports asterisks (*) and question marks (?). The wildcard "\*" indicates any number of characters, and "?" indicates any single character. **DEST** does not support wildcard characters. If the specified **SOURCE** matches multiple files, **DEST** must be a directory.

- If **DEST** is a directory, this directory must exist. In this case, the destination file is named after the source file.

- If the destination file path is a file, the directory for this file must exist. In this case, the file copy is renamed.

- If the destination file does not exist, a new file is created. If the destination file already exists, the existing file is overwritten.

> **NOTICE**<br>
> When important system resources are copied, unexpected results such as a system breakdown may occur. For example, when the **/dev/uartdev-1** file is copied, the system may stop responding.


## Example

Run **cp hello-OHOS.txt hello-openharmony.txt ./tmp/**.


## Output

Copy **hello-OHOS.txt** and **hello-openharmony.txt** to **/tmp/**.

```
OHOS:/$ ls
bin  hello-OHOS.txt     proc     system    vendor
dev  hello-openharmony.txt  sdcard   userdata
etc  lib                storage  usr
OHOS:/$ mkdir tmp
OHOS:/$ cp hello-OHOS.txt hello-openharmony.txt tmp/
OHOS:/$ ll tmp
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-OHOS.txt*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-openharmony.txt*
```
