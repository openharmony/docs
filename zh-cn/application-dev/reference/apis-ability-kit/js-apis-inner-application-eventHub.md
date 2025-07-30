# EventHub

EventHub是绑定在特定Context对象上的事件中心，提供订阅、取消订阅、触发事件的能力。主要用于[UIAbility组件与UI的数据通信](../../application-models/uiability-data-sync-with-ui.md)。

不同的Context对象拥有不同的EventHub对象，不同EventHub对象之间无法直接通信。事件的订阅、取消订阅、触发都作用在某一个具体的EventHub对象上。

由于Worker、Taskpool通过Actor模型实现[多线程并发](../../arkts-utils/multi-thread-concurrency-overview.md#多线程并发模型)，不同虚拟机实例之间拥有独占的内存，因此EventHub对象不能用于线程间的数据通信。


> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
>  - 本模块接口仅可在Stage模型下使用。

## 约束限制

- 不支持在进程间通过Eventhub对象进行数据通信。
- 不支持在Worker、TaskPool线程间通过EventHub对象进行数据通信。如需进行跨线程通信，参考[使用Emitter进行线程间通信](../../basic-services/common-event/itc-with-emitter.md)。
- 不支持同一线程内不同Context对象的EventHub对象间进行数据通信。
- 通过[sendableContextManager](js-apis-app-ability-sendableContextManager.md)转换后的Context对象与原先的Context对象属于不同Context对象，不支持其EventHub对象间的数据通信。

## 导入模块
 
```ts
import { common } from '@kit.AbilityKit';
```

## 使用说明

开发者需要通过Context对象获取EventHub。以下示例通过UIAbility实例的Context对象获取其EventHub对象。

```ts
import { common, UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  eventFunc() {
    console.log('eventFunc is called');
  }

  onCreate() {
    // 调用方式一（推荐）
    this.context.eventHub.on('myEvent', this.eventFunc);

    // 调用方式二
    let eventhub = this.context.eventHub as common.EventHub;
    eventhub.on('myEvent', this.eventFunc);
  }
}
```

## EventHub.on

on(event: string, callback: Function): void;

订阅指定事件。
> **说明：**
>
>  callback被emit触发时，调用方是EventHub对象，如果要修改callback中this的指向，可以使用箭头函数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| callback | Function | 是 | 事件回调，事件触发后调用。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例1：**
callback被emit触发时，调用方是EventHub对象。EventHub对象没有value属性，因此结果是undefined。

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  value: number = 12;

  onCreate() {
    try {
      this.context.eventHub.on('myEvent', this.eventFunc);
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  onForeground() {
    try {
      // 结果：
      // eventFunc is called, value: undefined
      this.context.eventHub.emit('myEvent');
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc() {
    console.log(`eventFunc is called, value: ${this.value}`);
  }
}
```

**示例2：**
callback使用箭头函数时，调用方是EntryAbility对象。EntryAbility对象里存在value属性，因此结果是12。

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  value: number = 12;

  onCreate() {
    try {
      // 支持使用匿名函数订阅事件
      this.context.eventHub.on('myEvent', () => {
        console.log(`anonymous eventFunc is called, value: ${this.value}`);
      });
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  onForeground() {
    try {
      // 结果：
      // anonymous eventFunc is called, value: 12
      this.context.eventHub.emit('myEvent');
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc() {
    console.log(`eventFunc is called, value: ${this.value}`);
  }
}
```

## EventHub.off

off(event: string, callback?: Function): void;

取消订阅指定事件。
 - 传入callback：取消指定的callback对指定事件的订阅，当该事件触发后，将不会回调该callback。
 - 不传callback：取消所有callback对指定事件的订阅。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| callback | Function | 否 | 事件回调。如果不传callback，则取消订阅该事件下所有callback。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    try {
      this.context.eventHub.on('myEvent', this.eventFunc1);
      this.context.eventHub.off('myEvent', this.eventFunc1); // 取消eventFunc1对myEvent事件的订阅
      this.context.eventHub.on('myEvent', this.eventFunc1);
      this.context.eventHub.on('myEvent', this.eventFunc2);
      this.context.eventHub.off('myEvent'); // 取消eventFunc1和eventFunc2对myEvent事件的订阅
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc1() {
    console.log('eventFunc1 is called');
  }

  eventFunc2() {
    console.log('eventFunc2 is called');
  }
}
```

## EventHub.emit

emit(event: string, ...args: Object[]): void;

触发指定事件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| ...args | Object[] | 否 | 可变参数，事件触发时，传递给回调函数的参数。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    this.context.eventHub.on('myEvent', this.eventFunc);
  }

  onDestroy() {
    try {
      // 结果：
      // eventFunc is called,undefined,undefined
      this.context.eventHub.emit('myEvent');
      // 结果：
      // eventFunc is called,1,undefined
      this.context.eventHub.emit('myEvent', 1);
      // 结果：
      // eventFunc is called,1,2
      this.context.eventHub.emit('myEvent', 1, 2);
    } catch (e) {
      let code: number = (e as BusinessError).code;
      let msg: string = (e as BusinessError).message;
      console.error(`EventHub emit error, code: ${code}, msg: ${msg}`);
    }
  }

  eventFunc(argOne: number, argTwo: number) {
    console.log(`eventFunc is called, ${argOne}, ${argTwo}`);
  }
}
```
