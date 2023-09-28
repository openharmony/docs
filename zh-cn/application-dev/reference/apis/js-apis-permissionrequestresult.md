# PermissionRequestResult

权限请求结果对象，在调用[requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)申请权限时返回此对象表明此次权限申请的结果。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Security.AccessToken

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | 是 | 否 | 用户传入的权限。|
| authResults | Array&lt;number&gt; | 是 | 否 | 相应请求权限的结果：<br>- -1：未授权，表示权限已设置，无需弹窗，需要用户在"设置"中修改。<br>- 0：已授权。<br>- 2：未授权，表示请求无效，可能原因有：<br>  -未在设置文件中声明目标权限。<br>  -权限名非法。<br>  -部分权限存在特殊申请条件，在申请对应权限时未满足其指定的条件，见[ohos.permission.LOCATION](../../security/permission-list.md#ohospermissionlocation)与[ohos.permission.APPROXIMATELY_LOCATION](../../security/permission-list.md#ohospermissionapproximately_location) |

## 使用说明

通过atManager实例来获取。

**示例：**

ArkTS语法不支持直接使用globalThis，需要通过一个单例的map来做中转。开发者需要：

a. 在EntryAbility.ets中导入构建的单例对象GlobalThis。
  ```typescript
    import { GlobalThis } from '../utils/globalThis'; // 需要根据globalThis.ets的路径自行适配
  ```
b. 在onCreate中添加:
  ```typescript
    GlobalThis.getInstance().setContext('context', this.context);
  ```

> **说明：**
>
> 由于在ts中引入ets文件会有告警提示，需要将EntryAbility.ts的文件后缀修改为EntryAbility.ets，并在module.json5中同步修改。

**globalThis.ets示例代码如下：**
```typescript
import common from '@ohos.app.ability.common';

// 构造单例对象
export class GlobalThis {
  private constructor() {}
  private static instance: GlobalThis;
  private _uiContexts = new Map<string, common.UIAbilityContext>();

  public static getInstance(): GlobalThis {
    if (!GlobalThis.instance) {
      GlobalThis.instance = new GlobalThis();
    }
    return GlobalThis.instance;
  }

  getContext(key: string): common.UIAbilityContext | undefined {
    return this._uiContexts.get(key);
  }

  setContext(key: string, value: common.UIAbilityContext): void {
    this._uiContexts.set(key, value);
  }

  // 其他需要传递的内容依此扩展
}
```

```ts
import { BusinessError } from '@ohos.base';
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import common from '@ohos.app.ability.common';
import { GlobalThis } from '../utils/globalThis';

let atManager = abilityAccessCtrl.createAtManager();
try {
  let context: common.UIAbilityContext = GlobalThis.getInstance().getContext('context');
  atManager.requestPermissionsFromUser(context, ["ohos.permission.CAMERA"]).then((data) => {
      console.info("data:" + JSON.stringify(data));
      console.info("data permissions:" + data.permissions);
      console.info("data authResults:" + data.authResults);
  }).catch((err: BusinessError) => {
      console.info("data:" + JSON.stringify(err));
  })
} catch(err) {
  console.log(`catch err->${JSON.stringify(err)}`);
}
```