# @ohos.data.sendablePreferences (共享用户首选项)


共享用户首选项为应用提供Key-Value键值型的数据处理能力，支持应用持久化轻量级数据，并对其修改和查询。

数据存储形式为键值对，键的类型为字符串型，值的存储数据类型包括number、string、boolean、bigint以及可序列化的object。

共享用户首选项默认加密等级为EL2，持久化文件存储在对应的EL2路径下。设备开机后，若无锁屏密码，可直接访问；若有锁屏密码，此路径下的文件需要至少一次解锁对应用户的锁屏界面后（密码、指纹、人脸等方式解锁皆可）才能够访问。需避免在开机未解锁的情况下访问首选项。修改加密等级的方法请参见[获取和修改加密分区](../../../application-dev/application-models/application-context-stage.md#获取和修改加密分区)。

共享用户首选项可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，性能优于普通的[用户首选项](js-apis-data-preferences.md)，可参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 共享用户首选项无法保证进程并发安全，会有文件损坏和数据丢失的风险，不支持在多进程场景下使用。

## 导入模块

```ts
import { sendablePreferences } from '@kit.ArkData';
```

## 常量

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

| 名称             | 参数类型 | 可读 | 可写 | 说明                                    |
| ---------------- | -------- | ---- | ---- | --------------------------------------- |
| MAX_KEY_LENGTH   | number   | 是   | 否   | Key的最大长度限制为1024个字节。     |
| MAX_VALUE_LENGTH | number   | 是   | 否   | Value的最大长度限制为16 * 1024 * 1024个字节。 |

## sendablePreferences.getPreferences

getPreferences(context: Context, options: Options): Promise&lt;Preferences&gt;

获取Preferences实例，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                                                                                                                                                           |
| ------- | ---------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | 是   | 应用上下文。 |
| options | [Options](#options) | 是   | 与Preferences实例相关的配置选项。        |

**返回值：**

| 类型                                    | 说明                               |
| --------------------------------------- | ---------------------------------- |
| Promise&lt;[Preferences](#preferences)&gt; | Promise对象，返回Preferences实例。<br>该实例继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let preferences: sendablePreferences.Preferences;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.getPreferences(this.context, options);
    promise.then((object: sendablePreferences.Preferences) => {
      preferences = object;
      console.info("Succeeded in getting preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to get preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.getPreferencesSync

getPreferencesSync(context: Context, options: Options): Preferences

获取Preferences实例，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                                         |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | 是   | 应用上下文。 |
| options | [Options](#options) | 是   | 与Preferences实例相关的配置选项。                            |

**返回值：**

| 类型                        | 说明                  |
| --------------------------- | --------------------- |
| [Preferences](#preferences) | 返回Preferences实例。<br>该实例继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let preferences: sendablePreferences.Preferences;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    preferences = sendablePreferences.getPreferencesSync(this.context, options);
  }
}
```

## sendablePreferences.deletePreferences

deletePreferences(context: Context, options: Options): Promise&lt;void&gt;

从缓存中移出指定的Preferences实例，若Preferences实例有对应的持久化文件，则同时删除其持久化文件。使用Promise异步回调。

调用该接口后，不建议再使用旧的Preferences实例进行数据操作，否则会出现数据一致性问题。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                                                         |
| ------- | ---------------- | ---- | ----------------------------------------------------------------------------|
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | 是   | 应用上下文。 |
| options | [Options](#options) | 是   | 与Preferences实例相关的配置选项。                                                                            |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15500010 | Failed to delete preferences file. |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.deletePreferences(this.context, options);
    promise.then(() => {
      console.info("Succeeded in deleting preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, options: Options): Promise&lt;void&gt;

从缓存中移出指定的Preferences实例，使用Promise异步回调。

应用首次调用[getPreferences](#sendablepreferencesgetpreferences)接口获取某个Preferences实例后，该实例会被会被缓存起来，后续再次[getPreferences](#sendablepreferencesgetpreferences)时不会再次从持久化文件中读取，直接从缓存中获取Preferences实例。调用此接口移出缓存中的实例之后，再次getPreferences将会重新读取持久化文件，生成新的Preferences实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名  | 类型             | 必填 | 说明                                                                                                                      |
| ------- | ---------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | 是   | 应用上下文。 |
| options | [Options](#options) | 是   | 与Preferences实例相关的配置选项。                                                                                    |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.removePreferencesFromCache(this.context, options);
    promise.then(() => {
      console.info("Succeeded in removing preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.removePreferencesFromCacheSync

removePreferencesFromCacheSync(context: Context, options: Options):void

从缓存中移出指定的Preferences实例，此为同步接口。

应用首次调用[getPreferences](#sendablepreferencesgetpreferences)接口获取某个Preferences实例后，该实例会被会被缓存起来，后续再次[getPreferences](#sendablepreferencesgetpreferences)时不会再次从持久化文件中读取，直接从缓存中获取Preferences实例。调用此接口移出缓存中的实例之后，再次getPreferences将会重新读取持久化文件，生成新的Preferences实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                                         |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | 是   | 应用上下文。 |
| options | [Options](#options) | 是   | 与Preferences实例相关的配置选项。                            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    sendablePreferences.removePreferencesFromCacheSync(this.context, options);
  }
}
```

## Options

Preferences实例配置选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

| 名称        | 类型   | 必填 | 说明                                                         |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| name        | string | 是   | Preferences实例的名称。                                      |
| dataGroupId | string\|null | 否   | 应用组ID，需要向应用市场获取，暂不支持。<br/>为可选参数。指定在此dataGroupId对应的沙箱路径下创建Preferences实例。当此参数不填时，默认在本应用沙箱目录下创建Preferences实例。<br/> **模型约束：** 此属性仅在Stage模型下可用。|


## Preferences

Preferences继承自[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，提供获取和修改存储数据的接口。

下列接口都需先使用[sendablePreferences.getPreferences](#sendablepreferencesgetpreferences)获取到Preferences实例，再通过此实例调用对应接口。

### get

get(key: string, defValue: lang.ISendable): Promise&lt;lang.ISendable&gt;

从缓存的Preferences实例中获取键对应的值，如果值为null或者非默认值类型，返回默认数据defValue，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

 **参数：**

| 参数名   | 类型                    | 必填 | 说明  |
| -------- | ----------------------- | ---- |--------|
| key      | string                  | 是   | 要获取的存储Key名称，不能为空。  |
| defValue | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 是   | 默认返回值。 |

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | Promise对象，返回键对应的值。 <br>该实例继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let promise = preferences.get('startup', 'default');
promise.then((data: lang.ISendable) => {
  let dataStr = data as string;
  console.info(`Succeeded in getting value of 'startup'. Data: ${dataStr}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get value of 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### getSync

getSync(key: string, defValue: lang.ISendable): lang.ISendable

从缓存的Preferences实例中获取键对应的值，如果值为null或者非默认值类型，返回默认数据defValue，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明            |
| -------- | ----------------------- | ---- |---------------------|
| key      | string                  | 是   | 要获取的存储Key名称，不能为空。  |
| defValue | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 是   | 默认返回值。 |

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 返回键对应的值。 <br>该实例继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { lang } from '@kit.ArkTS';
let value: lang.ISendable = preferences.getSync('startup', 'default');
```

### getAll

getAll(): Promise&lt;lang.ISendable&gt;

从缓存的Preferences实例中获取所有键值数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**

| 类型                  | 说明                                        |
| --------------------- | ------------------------------------------- |
| Promise&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | Promise对象，返回含有所有键值数据。 <br>该对象继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。  |

**错误码：**

以下错误码的详细介绍请参见[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let promise = preferences.getAll();
promise.then((keyValues: lang.ISendable) => {
  for (let value of Object.keys(keyValues)) {
    console.info("getAll " + JSON.stringify(value));
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to get all key-values. code: ${err.code}, message: ${err.message}`);
})
```

### getAllSync

getAllSync(): lang.ISendable

从缓存的Preferences实例中获取所有键值数据，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**

| 类型                  | 说明                                        |
| --------------------- | ------------------------------------------- |
| [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 返回含有所有键值数据。<br>该对象继承[ISendable](../../arkts-utils/arkts-sendable.md#isendable)，可以在ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）传递，传递的行为是引用传递，参考[Sendable使用场景](../../arkts-utils/sendable-guide.md)。 |

**错误码：**

以下错误码的详细介绍请参见[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { lang } from '@kit.ArkTS';

let keyValues: lang.ISendable = preferences.getAllSync();
for (let value of Object.keys(keyValues)) {
  console.info("getAll " + JSON.stringify(value));
}
```

### put

put(key: string, value: lang.ISendable): Promise&lt;void&gt;

将数据写入缓存的Preferences实例中，可通过[flush](#flush)将Preferences实例持久化，使用Promise异步回调。

  > **说明：**
  >
  > 当对应的键已经存在时，put()方法会覆盖其值。可以使用hasSync()方法检查是否存在对应键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                         |
| ------ | ----------------------- | ---- |--------------------------|
| key    | string                  | 是   | 要修改的存储的Key，不能为空。  |
| value  | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 是   | 存储的新值。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.put('startup', 'auto');
promise.then(() => {
  console.info("Succeeded in putting value of 'startup'.");
}).catch((err: BusinessError) => {
  console.error(`Failed to put value of 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### putSync

putSync(key: string, value: lang.ISendable): void

将数据写入缓存的Preferences实例中，可通过[flush](#flush)将Preferences实例持久化，此为同步接口。

  > **说明：**
  >
  > 当对应的键已经存在时，putSync()方法会覆盖其值。可以使用hasSync()方法检查是否存在对应键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型                    | 必填 | 说明                                                         |
| ------ | ----------------------- | ---- | ------------------------ |
| key    | string                  | 是   | 要修改的存储的Key，不能为空。 |
| value  | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | 是   | 存储的新值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
preferences.putSync('startup', 'auto');
```

### has

has(key: string): Promise&lt;boolean&gt;

检查缓存的Preferences实例中是否包含名为给定Key的存储键值对，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | 是   | 要检查的存储key名称，不能为空。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回Preferences实例是否包含给定key的存储键值对，true表示存在，false表示不存在。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.has('startup');
promise.then((val: boolean) => {
  if (val) {
    console.info("The key 'startup' is contained.");
  } else {
    console.error("The key 'startup' dose not contain.");
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to check the key 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### hasSync

hasSync(key: string): boolean

检查缓存的Preferences实例中是否包含名为给定Key的存储键值对，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | 是   | 要检查的存储key名称，不能为空。 |

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 返回Preferences实例是否包含给定key的存储键值对，true表示存在，false表示不存在。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
let isExist: boolean = preferences.hasSync('startup');
if (isExist) {
  console.info("The key 'startup' is contained.");
} else {
  console.error("The key 'startup' dose not contain.");
}
```

### delete

delete(key: string): Promise&lt;void&gt;

从缓存的Preferences实例中删除名为给定Key的存储键值对，可通过[flush](#flush)将Preferences实例持久化，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | 是   | 要删除的存储key名称，不能为空。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.delete('startup');
promise.then(() => {
  console.info("Succeeded in deleting the key 'startup'.");
}).catch((err: BusinessError) => {
  console.error(`Failed to delete the key 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### deleteSync

deleteSync(key: string): void

从缓存的Preferences实例中删除名为给定Key的存储键值对，可通过[flush](#flush)将Preferences实例持久化，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | 是   | 要删除的存储key名称，不能为空。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
preferences.deleteSync('startup');
```

### flush

flush(): Promise&lt;void&gt;

将缓存的Preferences实例中的数据异步存储到共享用户首选项的持久化文件中，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.flush();
promise.then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### clear

clear(): Promise&lt;void&gt;

清除缓存的Preferences实例中的所有数据，可通过[flush](#flush)将Preferences实例持久化，使用Promise异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.clear();
promise.then(() => {
  console.info("Succeeded in clearing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to clear. code: ${err.code}, message: ${err.message}`);
})
```

### clearSync

clearSync(): void

清除缓存的Preferences实例中的所有数据，可通过[flush](#flush)将Preferences实例持久化，此为同步接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**错误码：**

以下错误码的详细介绍请参见[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**示例：**

```ts
preferences.clearSync();
```

### on('change')

on(type: 'change', callback: Callback&lt;string&gt;): void

订阅数据变更，订阅的Key的值发生变更后，在执行[flush](#flush)方法后，触发callback回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                                     |
| -------- | -------- | ---- | ---------------------------------------- |
| type     | string   | 是   | 事件类型，固定值'change'，表示数据变更。 |
| callback | Callback&lt;string&gt; | 是   | 回调函数。返回发生变更的Key。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('change', observer);
preferences.putSync('startup', 'manual');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### on('multiProcessChange')

on(type: 'multiProcessChange', callback: Callback&lt;string&gt;): void

订阅进程间数据变更，多个进程持有同一个首选项文件时，订阅的Key的值在任意一个进程发生变更后，执行[flush](#flush)方法后，触发callback回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件类型，固定值'multiProcessChange'，表示多进程间的数据变更。 |
| callback | Callback&lt;string&gt; | 是   | 回调函数。返回发生变更的Key。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                                |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                           |
| 15500019 | Failed to obtain subscription service. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('multiProcessChange', observer);
preferences.putSync('startup', 'manual');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### on('dataChange')

on(type: 'dataChange', keys: Array&lt;string&gt;, callback: Callback&lt;lang.ISendable&gt;): void

精确订阅数据变更，只有被订阅的key值发生变更后，在执行[flush](#flush)方法后，触发callback回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件类型，固定值'dataChange'，表示精确的数据变更。           |
| keys     | Array&lt;string&gt;                                          | 是   | 需要订阅的key集合。                                          |
| callback | callback: Callback&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | 是   | 回调函数。回调支持返回多个键值对，其中键为发生变更的订阅key，值为变更后的数据：支持number、string、boolean、bigint以及可序列化的object。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let observer = (data: lang.ISendable) => {
  console.info(`observer : ${data}`)
}
let keys = ['name', 'age'];
preferences.on('dataChange', keys, observer);
preferences.putSync('name', 'xiaohong');
preferences.putSync('weight', 125);
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```

### off('change')

off(type: 'change', callback?: Callback&lt;string&gt;): void

取消订阅数据变更。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件类型，固定值'change'，表示数据变更。                     |
| callback | Callback&lt;string&gt; | 否   | 需要取消的回调函数，不填写则全部取消。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('change', observer);
preferences.putSync('startup', 'auto');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('change', observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```

### off('multiProcessChange')

off(type: 'multiProcessChange', callback?: Callback&lt;string&gt;): void

取消订阅进程间数据变更。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 事件类型，固定值'multiProcessChange'，表示多进程间的数据变更。 |
| callback | Callback&lt;string&gt; | 否   | 需要取消的回调函数，不填写则全部取消。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('multiProcessChange', observer);
preferences.putSync('startup', 'auto');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('multiProcessChange', observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```
### off('dataChange')

off(type: 'dataChange', keys: Array&lt;string&gt;, callback?: Callback&lt;lang.ISendable&gt;): void

取消精确订阅数据变更。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.DistributedDataManager.Preferences.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件类型，固定值'dataChange'，表示精确的数据变更。           |
| keys     | Array&lt;string&gt;                                          | 是   | 需要取消订阅的key集合，当keys为空数组时，表示取消订阅全部key；当keys为非空数组时，表示只取消订阅key集合中的key。 |
| callback | Callback&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | 否   | 需要取消的回调函数，若callback不填写，表示所有的callback都需要处理；若callback填写，表示只处理该callback。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[用户首选项错误码](errorcode-preferences.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let observer = (data: lang.ISendable) => {
  console.info(`observer : ${data}`)
}
let keys = ['name', 'age'];
preferences.on('dataChange', keys, observer);
preferences.putSync('name', 'xiaohong');
preferences.putSync('weight', 125);
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('dataChange', keys, observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```
