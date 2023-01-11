# 时间时区子系统ChangeLog

## cl.time.1 接口异常抛出变更

时间时区子系统时间相关接口异常抛出：201权限否定异常、202非系统应用异常和401参数无效异常。

**变更影响**

基于此前版本开发的应用，继续使用无影响，使用新接口需要捕获并处理抛出的新异常。

**关键接口/组件变更**

变更前：
  - 接口异常抛出message，错误码-1。

变更后：
  - 接口异常抛出message和code，包括201权限否定异常、202非系统应用异常和401参数无效异常。

原接口中标记为废弃的接口，可以使用新接口中的同名接口替换

| 原接口           | 新接口               |
| ---------------- | -------------------- |
| @ohos.systemTime | @ohos.systemDateTime |

**适配指导**

应用中调用systemTime所有接口可参考下列代码进行异常捕获，以setTime接口为例，其他接口适配方法相同。

callback形式调用:

**示例：**

```js
import systemDateTime from @ohos.systemDateTime
// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
try {
    systemDateTime.setTime(time, (error) => {
        //捕获权限否定异常和非系统应用异常
        if (error) {
            console.info(`Failed to setting time. message:${error.message}, code:${error.code}`);
            return;
        }
        console.info(`Succeeded in setting time.`);
    })
} catch(e) {
    //捕获参数校验失败异常
    console.info(`Failed to set time. message:${e.message}, code:${e.code}`);
}
```

promise形式调用：

**示例：**

```js
import systemDateTime from @ohos.systemDateTime
// time对应的时间为2021-01-20 02:36:25
let time = 1611081385000;
try {
    systemDateTime.setTime(time).then(() => {
    	console.info(`Succeeded in setting time.`);
	}).catch((error) => {
        //捕获权限否定异常和非系统应用异常
    	console.info(`Failed to setting time. message:${error.message}, code:${error.code}`);
	});
} catch(e) {
     //捕获参数校验失败异常
    console.info(`Failed to set time. message:${e.message}, code:${e.code}`);
}
```
