# stack


## 命令功能

查看系统各堆栈使用情况。


## 命令格式

stack


## 参数说明

无


## 使用指南

无


## 使用实例

输入：stack


## 输出说明

**示例** 系统堆栈使用情况

```
OHOS # stack
 stack name    cpu id     stack addr     total size   used size
 ----------    ------     ---------      --------     --------
  svc_stack      1        0x405c4000     0x2000       0x484
  svc_stack      0        0x405c6000     0x2000       0xae4
  exc_stack      1        0x405c8000     0x1000       0x0
  exc_stack      0        0x405c9000     0x1000       0x0
```

**表1** 输出说明

| 输出 | 说明 | 
| -------- | -------- |
| stack&nbsp;name | 系统堆栈名 | 
| cpu&nbsp;id | cpu&nbsp;号 | 
| stack&nbsp;addr | 栈地址 | 
| total&nbsp;size | 堆栈大小 | 
| used&nbsp;size | 堆栈实际使用大小 | 
