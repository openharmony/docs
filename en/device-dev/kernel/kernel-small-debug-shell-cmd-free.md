# free


## Command Function

This command is used to display the memory usage in the system.


## Syntax

free [_-b | -k | -m | -g | -t_]


## Parameters

**Table 1** Parameter description

| Parameter| Description |
| -------- | -------- |
| No parameter| Displays the memory usage in bytes.|
| --help/-h | Displays the parameters supported by the **free** command.|
| -b | Displays the memory usage in bytes.|
| -k | Display the memory waterline in KiB.|
| -m | Display the memory waterline in MiB.|
| -g | Displays the memory usage in GiB.|
| -t | Displays the memory usage in TiB.|


## Usage Guidelines

None.


## Example

Run **free**, **free -k**, and **free -m**, respectively.


## Output


```
OHOS:/$ free
                total        used        free      shared     buffers
Mem:          2819652     2754468       65184           0           0
-/+ buffers/cache:        2754468       65184
Swap:               0           0           0
OHOS:/$ free -k
                total        used        free      shared     buffers
Mem:             2753        2692          60           0           0
-/+ buffers/cache:           2692          60
Swap:               0           0           0
OHOS:/$ free -m
                total        used        free      shared     buffers
Mem:                2           2           0           0           0
-/+ buffers/cache:              2           0
Swap:               0           0           0
```

**Table 2** Output description

| Parameter| Description|
| -------- | -------- |
| total | Total size of the dynamic memory pool.|
| used | Size of the used memory.|
| free | Size of the unallocated memory.|
| shared | Size of the shared memory.|
| buffers | Size of the buffer.|

