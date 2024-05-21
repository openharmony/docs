# @ohos.app.ability.AtomicServiceOptions (AtomicServiceOptions)

AtomicServiceOptions可以作为[openAtomicService()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenatomicservice12)的入参，用于携带参数。继承于[StartOptions](js-apis-app-ability-startOptions.md)。

> **说明：**
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AtomicServiceOptions from '@ohos.app.ability.AtomicServiceOptions';
```

## 属性

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 必填 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| [flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | number | 否 | 否 | 默认传数字。<br />例如通过wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION表示对URI执行读取操作的授权。 |
| parameters | Record\<string, Object> | 否 | 否 | 表示WantParams描述，由开发者自行决定传入的键值对。默认会携带以下key值：<br />- ohos.aafwk.callerPid：表示拉起方的pid。<br />- ohos.aafwk.param.callerBundleName：表示拉起方的Bundle Name。<br />- ohos.aafwk.param.callerToken：表示拉起方的token。<br />- ohos.aafwk.param.callerUid：表示[BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1)中的uid，应用包里应用程序的uid。<br />- component.startup.newRules：表示是否启用新的管控规则。<br />- moduleName：表示拉起方的模块名，该字段的值即使定义成其他字符串，在传递到另一端时会被修改为正确的值。<br />- ohos.dlp.params.sandbox：表示dlp文件才会有。<br />- ability.params.backToOtherMissionStack：表示是否支持跨任务链返回。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AtomicServiceOptions from '@ohos.app.ability.AtomicServiceOptions';
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import wantConstant from '@ohos.app.ability.wantConstant';

export default class EntryAbility extends UIAbility {

  onForeground() {
    let appId: string = '6918661953712445909';
    let options: AtomicServiceOptions = {
      flags: wantConstant.Flags.FLAG_INSTALL_ON_DEMAND,
      parameters: { "demo.result": 123456 }
    };

    try {
      this.context.openAtomicService(appId, options)
        .then((result: common.AbilityResult) => {
          // 执行正常业务
          console.info('openAtomicService succeed');
        })
        .catch((err: BusinessError) => {
          // 处理业务逻辑错误
          console.error(`openAtomicService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`openAtomicService failed, code is ${code}, message is ${message}`);
    }
  }
}
```
