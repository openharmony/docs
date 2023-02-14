# mv


## Command Function

This command is used to move files.


## Syntax

mv [_-fivn_] *SOURCE... DEST*


## Parameters

**Table 1** Parameter description

| Parameter  | Description                                                    | Value Range                                       |
| ------ | ------------------------------------------------------------ | ----------------------------------------------- |
| -help  | Displays help information.                                                  | N/A                                             |
| -f     | Forcibly overwrites the target file.                                  | N/A                                             |
| -i     | Provides information before moving a file that would overwrite an existing file or directory. Enter **y** to overwrite the file or directory, and enter **n** to cancel the operation.| N/A                                             |
| -n     | Do not overwrite any existing file or directory.                            | N/A                                             |
| -v     | This parameter does not take effect although it is supported by the latest Toybox code.      | N/A                                             |
| SOURCE | Specifies the file to move.                                                | This command cannot be used to move a directory. It can be used to move multiple files at a time.|
| DEST   | Specifies the destination file path.                                              | Both a directory and a file are supported.                             |


## Usage Guidelines

- **SOURCEFILE** supports wildcard characters * and ?. The asterisk (*) indicates any number of characters, and the question mark (?) represents a single character. **DEST** does not support wildcard characters. If the specified **SOURCE** matches multiple files, **DEST** must be a directory.

- If **DEST** is a directory, this directory must exist. In this case, the destination file is named after the source file.

- If **DEST** is a file, the directory for this file must exist.

- If the destination file already exists, it will be overwritten.

## Note

Currently, the shell does not support this command. mksh supports it. To switch to mksh, run **cd bin** and **./mksh**.

## Example

Run the following commands:

- mv -i test.txt testpath/

- mv test?.txt testpath/ (Move **test3.txt**, **testA.txt**, and **test_.txt**)


## Output

Example 1: Move a file.


```
OHOS:/$ touch test.txt
OHOS:/$ mkdir testpath
OHOS:/$ touch testpath/test.txt
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):y
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ cp testpath/test.txt ./
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):n
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
```

Example 2: Move files.


```
OHOS:/$ ls
bin  etc  proc    storage  test.txt   testA.txt  testpath  usr
dev  lib  sdcard  system   test3.txt  test_.txt  userdata  vendor
OHOS:/$ mv test?.txt testpath/
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ ls testpath/
test.txt  test3.txt  testA.txt  test_.txt
```
