\# 锁屏服务的Changelog

\## EventType新增系统事件类型

***\*访问级别\****

系统接口

***\*变更原因\****

新增系统事件类型

***\*变更影响\****

该变更为兼容变更。

变更前：不支持strongAuthChanged和screenLockDisabledChanged这两种系统事件。

变更后：支持strongAuthChanged和screenLockDisabledChanged这两种系统事件。

***\*起始API Level\****

API12

***\*变更发生版本\****

从OpenHarmony 5.0.0.38 版本开始。

***\*适配指导\****

下面是接收新的事件类型的Sample代码.

```typescript
try {
  let isSuccess = screenLock.onSystemEvent((event: screenLock.SystemEvent) => {
    console.log(`Succeeded in Registering the system event which related to screenlock. eventType: ${event.eventType}`)
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to register the system event which related to screenlock, Code: ${error.code}, message: ${error.message}`)
}
```

