# 全球化子系统ChangeLog

## cl.resourceManager.1  getStringSync、getStringByNameSync新增接口

相较于之前的版本，在4.0.6.2 版本中，为扩展getStringSync、getStringByNameSync接口字符串匹配功能，新增了接口以及相应的错误码。

| 包名  | 新增接口  |
| --------------- | ---------------------------------------------------- |
| ohos.resourceManager.d.ts | getStringSync(resId: number, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringSync(resource: Resource, ...args: Array<string \| number>): string; |
| ohos.resourceManager.d.ts | getStringByNameSync(resName: string, ...args: Array<string \| number>): string; |

**变更影响**

之前只能直接获取resources中的string资源的value值，在4.0.6.2 及以上版本中可用通过参数格式化string资源的value值，扩展了格式化字符串的查询能力。

新增错误码：

9001007 根据当前id获取的资源格式化失败

9001008 根据当前名称获取的资源格式化失败

**示例代码**

以调用接口getStringSync为例，变更前只支持示例1，变更后示例1、示例2都支持。
```
示例1：
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
示例2：
try {
  this.context.resourceManager.getStringSync($r('app.string.test').id, "format string", 787, 98.78);
} catch (error) {
  console.error(`getStringSync failed, error code: ${error.code}, message: ${error.message}.`)
}
```

**适配指导**
请参考接口说明：

[新增接口参考](../../../application-dev/reference/apis/js-apis-resource-manager.md)

[新增错误码参考](../../../application-dev/reference/errorcodes/errorcode-resource-manager.md)