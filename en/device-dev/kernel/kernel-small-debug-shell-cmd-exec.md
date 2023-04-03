# exec


## Command Function

This command is a built-in shell command used to execute basic user-mode programs.


## Syntax

exec &lt;*executable-file*&gt;


## Parameters

**Table 1** Parameter description

| Parameter           | Description |
| --------------- | ------------------ |
| executable-file | Specifies a valid executable file.|


## Usage Guidelines

Currently, this command supports only valid binary programs. The programs are successfully executed and then run in the background by default. However, the programs share the same device with the shell. As a result, the output of the programs and the shell may be interlaced.


## Example

Run **exec helloworld**.


## Output


```
OHOS # exec helloworld
OHOS # hello world!
```

> **NOTE**<br>
>  After the executable file is executed, the prompt **OHOS #** is printed first. The shell **exec** command is executed in the background, causing the prompt to be printed in advance.
