# rmdir


## Command Function

This command is used to delete a directory.


## Syntax

rmdir [_-p_] [_dirname..._]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| --help | Displays the parameters supported by the **rmdir** command.| N/A | 
| -p | Deletes a path.| N/A | 
| --ignore-fail-on-non-empty | Suppresses the error message when a non-empty directory is to be deleted.| N/A | 
| dir | Specifies the name of the directory to delete. The directory must be empty. A path is supported.| N/A | 


## Usage Guidelines

- The **rmdir** command can only be used to delete directories.

- The **rmdir** command can delete only one directory at a time.

- The **rmdir** command can delete only empty directories.


## Example

Run **rmdir dir**.


## Output

Delete the directory **dir**.


```
OHOS:/test$ mkdir dir
OHOS:/test$ ls
dir
OHOS:/test$ rmdir dir/
OHOS:/test$ ls
```
