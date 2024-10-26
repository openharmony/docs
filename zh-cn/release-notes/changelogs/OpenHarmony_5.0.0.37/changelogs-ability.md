# ability子系统Changelog

## cl.ability.1 createModuleContext接口废弃

**访问级别**

公开接口。

**废弃原因**

使用该接口创建的context无法正确获取资源。

**废弃影响**

该变更为兼容性变更，提供了新接口。

**起始 API Level**

9

**废弃发生版本**

从OpenHarmony SDK 5.0.0.37开始。

**废弃的接口/组件**

|接口声明|废弃说明|替代接口|
|-------|-------|-------|
|createModuleContext(moduleName: string): Context|用这个接口创建的context无法正确获取资源，建议使用替代接口。|createModuleContext(context: Context, moduleName: string): Promise<Context>|

**适配指导**

需要使用新的替代接口，替代接口为带context入参的createModuleContext。

废弃前代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
废弃后代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      common.createModuleContext(this.context,'entry').then((data: Context)=>{
        moduleContext = data;
      }).catch((err : BusinessError)=>{
        console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
## cl.ability.2 createModuleContext接口废弃

**访问级别**

系统接口。

**废弃原因**

使用该接口创建的context无法正确获取资源。

**废弃影响**

该变更为兼容性变更，提供了新接口。

**起始 API Level**

9

**废弃发生版本**

从OpenHarmony SDK 5.0.0.37开始。

**废弃的接口/组件**

|接口声明|废弃说明|替代接口|
|-------|-------|-------|
|createModuleContext(bundleName: string, moduleName: string): Context|用这个接口创建的context无法正确获取资源，建议使用替代接口。|createModuleContext(context: Context, bundleName: string, moduleName: string): Promise<Context>|

**适配指导**

需要使用新的替代接口，替代接口为带context入参的createModuleContext。

废弃前代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('bunlename', 'entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
废弃后代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      common.createModuleContext(this.context, 'bunlename', 'entry').then((data: Context)=>{
        moduleContext = data;
      }).catch((err : BusinessError)=>{
        console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## cl.ability.3 createBundleContext接口废弃

**访问级别**

系统接口。

**废弃原因**

使用该接口创建的context无法正确获取资源。

**废弃影响**

该变更为兼容性变更，提供了新接口。

**起始 API Level**

9

**废弃发生版本**

从OpenHarmony SDK 5.0.0.37开始。

**废弃的接口/组件**

|接口声明|废弃说明|替代接口|
|-------|-------|-------|
|createBundleContext(bundleName: string): Context|用这个接口创建的context无法正确获取资源，建议使用替代接口。|createBundleContext(context: Context, bundleName: string): Promise<Context>|

**适配指导**

需要使用新的替代接口，替代接口为带context入参的createBundleContext。

废弃前代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let bundleContext: common.Context;
    try {
      bundleContext = this.context.createBundleContext('bundlename');
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
废弃后代码示例：

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let bundleContext: common.Context;
    try {
      common.createBundleContext(this.context,'bundlename').then((data: Context)=>{
        bundleContext = data;
      }).catch((err : BusinessError)=>{
        console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```