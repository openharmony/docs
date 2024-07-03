# 元能力子系统-ChangeLog

## Context.setWakeUpScreen接口废弃变更
从API12开始，废弃此接口。

**访问级别**

公开接口

**变更原因**

setWakeUpScreen接口存在安全风险，不再对三方应用开放。

**变更影响**

该接口删除无法再使用，请应用进行更新使用，否则会影响原有功能。

- 涉及接口

```js
  setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback<void>): void;
  setWakeUpScreen(wakeUp: boolean): Promise<void>;
```

- 变更前：

```js
  setWakeUpScreen(wakeUp: boolean, callback: AsyncCallback<void>): void;
  setWakeUpScreen(wakeUp: boolean): Promise<void>;
```

- 变更后：删除接口，停止对外开放。

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**适配指导**

该接口删除后无法再使用，请适配更新，系统应用建议使用window.setWakeUpScreen替代。