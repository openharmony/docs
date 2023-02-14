# cd


## Command Function

This command is used to change the current working directory.


## Syntax

cd [_path_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| path | Specifies the path of the new directory. | You must have the execution (search) permission on the specified directory.|


## Usage Guidelines

- If **path** is not specified, this command switches to the root directory.

- If **path** is specified, this command switches to the specified directory.

- The **path** value starting with a slash (/) represents the root directory.

- The **path** value starting with a dot (.) represents the current directory.

- The **path** value starting with two dots (..) represents the parent directory.

- You can run **cd -** to alternate between two directories that are recently accessed.


## Example

Run **cd ..**.


## Output

Parent directory information:

```
OHOS:/nfs$ cd ../
OHOS:/$ ls
bin  etc  nfs   sdcard   system  tmp  vendor
dev  lib  proc  storage  test    usr
```
