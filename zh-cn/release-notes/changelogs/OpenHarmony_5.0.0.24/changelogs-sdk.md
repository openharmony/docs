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


## cl.sdk.2 TS文件中使用ArkTS全局声明式接口告警级别提升

**变更原因**

TS文件中不允许使用ArkTS全局声明式接口，应对异常场景进行编译拦截。

**变更影响**

影响应用编译行为。

***变更前：***

TS文件中使用ArkTS全局声明式接口，给出warn类型告警，提示内容如下：

"Cannot find name 'xxx'."

***变更后：***

TS文件中使用ArkTS全局声明式接口，给出error类型告警，提示内容如下：

"Cannot find name 'xxx'."

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

此变更仅影响编译行为。

**适配指导**

若由于TS文件中使用ArkTS全局声明式接口，导致应用编译报错，可参考如下修改方式：

错误示例：
```ts
// 当前为TS文件
let pictureSource: Resource;
```

**场景一：编译报错的TS文件可以变更为ETS文件**

将TS文件后缀修改为.ets

**场景二：编译报错的TS文件不可以变更为ETS文件**

1.删除不必要的ArkTS全局声明式接口调用

2.提出合理诉求，将常用全局式接口迁移至component/common_ts_ets_api.d.ts文件中

## cl.sdk.3 引用二级目录下的API告警

**变更原因**

不允许引用SDK中二级目录下的API文件，应对异常场景进行编译拦截。

**变更影响**

影响应用编译行为。

***变更前：***

引用SDK中二级目录下的API文件，给出warn类型告警，提示内容如下：

"Cannot find module 'xxx' or its corresponding type declarations."

***变更后：***

引用SDK中二级目录下的API文件，给出error类型告警，提示内容如下：

"Cannot find module 'xxx' or its corresponding type declarations."

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.24开始。

**变更的接口/组件**

此变更仅影响编译行为。

**适配指导**

若由于引用SDK中二级目录下的API文件，导致应用编译报错，可参考如下修改方式：

1.在SDK一级目录接口文件中搜索相关接口名称

2.替换正确的接口调用方式

错误示例：
```ts
import Context from 'application/Context';
let currentContext: Context;
```

正确示例：
```ts
import common from '@ohos.app.ability.common';
let currentContext: common.Context;
```