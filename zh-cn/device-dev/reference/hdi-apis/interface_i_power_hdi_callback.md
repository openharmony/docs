# IPowerHdiCallback


## **概述**

休眠/唤醒状态的回调。

服务创建此回调对象后，可以调用IPowerInterface的接口注册回调，从而订阅休眠/唤醒状态的变化。

**Since：**

3.1

**相关模块:**

[Power](power.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnSuspend](#onsuspend)&nbsp;() | 休眠状态的回调方法。 | 
| [OnWakeup](#onwakeup)&nbsp;() | 唤醒状态的回调方法。 | 


## **成员函数说明**


### OnSuspend()

  
```
IPowerHdiCallback::OnSuspend ()
```

**描述：**

休眠状态的回调方法。

当设备进入休眠状态时，将通过此方法通知给服务。


### OnWakeup()

  
```
IPowerHdiCallback::OnWakeup ()
```

**描述：**

唤醒状态的回调方法。

当设备进入唤醒状态时，将通过此方法通知给服务。
