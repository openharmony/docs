# 启动子系统JS API变更ChangeLog

## cl.startup.1 包名变更

**变更影响**

原有的@ohos.systemParameterV9包名将被删除无法再使用，需更换为新的@ohos.systemParameterEnhance包名。

**适配指导**

原有的@ohos.systemParameterV9需要变更为@ohos.systemParameterEnhance，包内接口都不变，示例：

```js
import @ohos.systemParameterEnhance
```

