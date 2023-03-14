# writeproc


## 命令功能

proc fs支持传入字符串参数，需要每个文件实现自己的写方法。


## 命令格式

writeproc &lt;_data_&gt;  &gt;&gt;  /proc/&lt;_filename_&gt;


## 参数说明

**表1** 参数说明

| 参数     | 参数说明                                                   |
| -------- | ---------------------------------------------------------- |
| data     | 要输入的字符串，以空格为结束符，如需输入空格，请用""包裹。 |
| filename | data要传入的proc文件。                                     |


## 使用指南

proc文件实现自身的write函数，调用writeproc命令后会将入参传入write函数。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> procfs不支持多线程访问。

## 特殊说明

shell端暂不支持。

## 使用实例

举例：writeproc test &gt;&gt; /proc/uptime


## 输出说明

```
OHOS \# writeproc test &gt;&gt; /proc/uptime

[INFO]write buf is: test

test &gt;&gt; /proc/uptime
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> uptime proc文件临时实现write函数，INFO日志为实现的测试函数打印的日志。