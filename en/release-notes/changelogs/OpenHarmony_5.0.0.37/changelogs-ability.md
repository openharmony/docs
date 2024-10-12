# Ability Subsystem Changelog

## cl.ability.1 Deprecated the createModuleContext API

**Access Level**

Public API

**Reason for Change**

The context created using this API cannot obtain resources correctly.

**Change Impact**

This change is a compatibility change. A new API is provided.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.37

**Deprecated APIs/Components**

|Deprecated API|Description|Substitute API|
|-------|-------|-------|
|createModuleContext(moduleName: string): Context|The context created using this API cannot obtain resources correctly. You are advised to use the substitute API.|createModuleContext(context: Context, moduleName: string): Promise\<Context>|

**Adaptation Guide**

Use **createModuleContext** with the input parameter **context** in the code.

Code example before deprecation:

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
Code example after deprecation:

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
## cl.ability.2 Deprecated the createModuleContext API

**Access Level**

System API

**Reason for Change**

The context created using this API cannot obtain resources correctly.

**Change Impact**

This change is a compatibility change. A new API is provided.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.37

**Deprecated APIs/Components**

|Deprecated API|Description|Substitute API|
|-------|-------|-------|
|createModuleContext(bundleName: string, moduleName: string): Context|The context created using this API cannot obtain resources correctly. You are advised to use the substitute API.|createModuleContext(context: Context, bundleName: string, moduleName: string): Promise\<Context>|

**Adaptation Guide**

Use **createModuleContext** with the input parameter **context** in the code.

Code example before deprecation:

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
Code example after deprecation:

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

## cl.ability.3 Deprecated the createBundleContext API

**Access Level**

System API

**Reason for Change**

The context created using this API cannot obtain resources correctly.

**Change Impact**

This change is a compatibility change. A new API is provided.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.37

**Deprecated APIs/Components**

|Deprecated API|Description|Substitute API|
|-------|-------|-------|
|createBundleContext(bundleName: string): Context|The context created using this API cannot obtain resources correctly. You are advised to use the substitute API.|createBundleContext(context: Context, bundleName: string): Promise\<Context>|

**Adaptation Guide**

Use **createBundleContext** with the input parameter **context** in the code.

Code example before deprecation:

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
Code example after deprecation:

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
