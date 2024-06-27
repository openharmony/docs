# SDK子系统Changelog

## cl.sdk.1 FA/Stage模型应用使用仅Stage/FA模型可用接口告警级别提升

**变更原因**

FA/Stage模型中不允许使用仅Stage/FA模型可用接口，应对异常场景进行编译拦截。

**变更影响**

影响应用编译行为。

***变更前：***

FA模型中使用仅Stage模型可用接口做应用编译时，给出warn类型告警，提示内容如下：

"This API is used only in Stage Mode, but the current Mode is FA."

Stage模型中使用仅FA模型可用接口做应用编译时，给出warn类型告警，提示内容如下：

"This API is used only in FA Mode, but the current Mode is Stage."

***变更后：***

FA模型中使用仅Stage模型可用接口做应用编译时，给出error类型告警，提示内容如下：

"This API is used only in Stage Mode, but the current Mode is FA."

Stage模型中使用仅FA模型可用接口做应用编译时，给出error类型告警，提示内容如下：

"This API is used only in FA Mode, but the current Mode is Stage."

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

此变更仅影响编译行为，涉及到的接口及其替换用接口参考[《API模型转换清单》](./api-model-switch.md)

**适配指导**

若由于FA/Stage模型应用使用仅Stage/FA模型可用接口，导致应用编译报错，可参考如下修改方式：

根据当前报错接口信息，在[《API模型转换清单》](./api-model-switch.md)中查找报错接口，查看该接口在Stage模型下是否存在可替换接口

**场景一：仅FA/Stage模型可用接口在Stage/FA模型中存在可替换接口**

错误示例：

```ts
// 当前工程为Stage模型
import featureAbility from '@ohos.ability.featureAbility';

let context: featureAbility.Context = featureAbility.getContext().getApplicationContext();
```

正确示例：

```ts
// 当前工程为Stage模型
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let applicationContext: common.Context;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.error(`getApplicationContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

**场景二：仅FA/Stage模型可用接口在Stage/FA模型中无意义（即无可替代接口），删除相关错误接口调用代码即可。**
