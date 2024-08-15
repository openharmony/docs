# 设置分布式文件数据等级

不同设备本身的安全能力差异较大，一些小的嵌入式设备安全能力远弱于平板等设备类型。用户或者应用不同的文件数据有不同安全诉求，例如个人的健康信息和银行卡信息等不期望被弱设备读取。因此，OpenHarmony提供一套完整的数据分级、设备分级标准，并针对不同设备制定不同的数据流转策略，具体规则请参见[数据、设备安全分级](../database/access-control-by-device-and-data-level.md)。

## 接口说明

API详细介绍请参见[ohos.file.securityLabel](../reference/apis-core-file-kit/js-apis-file-securityLabel.md)。

**表1** 设置文件数据等级

| 接口名 | 功能 | 接口类型 | 支持同步 | 支持异步 | 
| -------- | -------- | -------- | -------- | -------- |
| setSecurityLabel | 设置文件安全标签 | 方法 | √ | √ | 
| getSecurityLabel | 获取文件安全标签 | 方法 | √ | √ | 

> **须知：**
>
> 1. 对于不满足安全等级的文件，跨设备仍然可以看到该文件，但是无权限打开访问该文件。
>
> 2. 分布式文件系统的数据等级默认为S3，应用可以主动设置文件的安全等级。

## 开发示例

获取通用文件沙箱路径，并设置数据等级标签。示例中的context的获取方式请参见[获取UIAbility的上下文信息](../application-models/uiability-usage.md#获取uiability的上下文信息)。

  
```ts
import { securityLabel } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

// 获取需要设备数据等级的文件沙箱路径
let context = getContext(this) as common.UIAbilityContext; // 获取UIAbilityContext信息
let pathDir = context.filesDir;
let filePath = pathDir + '/test.txt';

//打开文件
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
// 设置文件的数据等级为s0
securityLabel.setSecurityLabel(filePath, 's0').then(() => {
  console.info('Succeeded in setSecurityLabeling.');
  fs.closeSync(file);
}).catch((err: BusinessError) => {
  console.error(`Failed to setSecurityLabel. Code: ${err.code}, message: ${err.message}`);
});
```
