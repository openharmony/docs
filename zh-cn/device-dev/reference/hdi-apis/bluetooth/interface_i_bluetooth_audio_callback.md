# IBluetoothAudioCallback

## 概述

声明用于音频渲染开启、暂停，和结束的回调函数。

**起始版本：** 4.0

**相关模块：**[HdiA2dp](_hdi_a2dp.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [StartRender](#startrender) () | 启动音频渲染的回调函数。 | 
| [SuspendRender](#suspendrender) () | 暂停音频渲染的回调函数。 | 
| [StopRender](#stoprender) () | 结束音频渲染的回调函数。 | 


## 成员函数说明


### StartRender()

```
IBluetoothAudioCallback::StartRender ()
```

**描述**

启动音频渲染的回调函数。

**起始版本：** 4.0

**返回：**

如果操作成功返回0；否则返回负值。

### StopRender()

```
IBluetoothAudioCallback::StopRender ()
```

**描述**

结束音频渲染的回调函数。

**起始版本：** 4.0

**返回：**

如果操作成功返回0；否则返回负值。

### SuspendRender()

```
IBluetoothAudioCallback::SuspendRender ()
```

**描述**

暂停音频渲染的回调函数。

**起始版本：** 4.0

**返回：**

如果操作成功返回0；否则返回负值。
