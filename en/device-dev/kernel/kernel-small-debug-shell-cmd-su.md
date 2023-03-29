# su


## Command Function

This command is used to switch the user account.


## Syntax

su [_uid_] [_gid_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| uid | Specifies the ID of the target user.| - Left blank<br>- [0, 60000] | 
| gid | Specifies the ID of the target user group.| - Left blank<br>- [0, 60000] | 


## Usage Guidelines

- If no parameter is specified, the **su** command switches to user **root** by default. The **uid** and **gid** for user **root** are both **0**.

- If **uid** and **gid** are specified, this command allows commands to be executed as the user with the specified **uid** and **gid**.

- If the input parameter is out of the range, an error message will be printed.


## Example

Run **su 1000 1000**.


## Output

The user with both **uid** and **gid** of **1000** is switched.

```
OHOS # ls
Directory /data/system/param:
-rw-r--r-- 0 u:0 g:0 hello_1.txt
OHOS # su 1000 1000
OHOS # touch hello 2.txt
OHOS # ls
Directory /data/system/param:
-rw-r--r-- O u:1000 g:1000 hello 2.txt
-гw-r--r-- 0 u:0 g:0 hello_1.txt
```
