# stack


## Command Function

This command is used to check the usage of each stack in the system.


## Syntax

stack


## Parameters

None.


## Usage Guidelines

None.


## Example

Run **stack**.


## Output

System stack usage:

```
OHOS # stack
 stack name    cpu id     stack addr     total size   used size
 ----------    ------     ---------      --------     --------
  svc_stack      1        0x405c4000     0x2000       0x484
  svc_stack      0        0x405c6000     0x2000       0xae4
  exc_stack      1        0x405c8000     0x1000       0x0
  exc_stack      0        0x405c9000     0x1000       0x0
```

**Table 1** Output description

| Parameter| Description| 
| -------- | -------- |
| stack&nbsp;name | Name of the stack.| 
| cpu&nbsp;id | CPU number.| 
| stack&nbsp;addr | Stack address.| 
| total&nbsp;size | Total stack size.| 
| used&nbsp;size | Size of the stack used.| 
