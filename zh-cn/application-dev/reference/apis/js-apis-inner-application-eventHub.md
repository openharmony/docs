# EventHub

EventHub模块提供了事件中心，提供订阅、取消订阅、触发事件的能力。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
>  - 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用eventHub的功能前，需要通过UIAbility实例的成员变量context获取。

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    eventFunc(){
        console.log("eventFunc is called");
    }

    onForeground() {
        this.context.eventHub.on("myEvent", this.eventFunc);
    }
}
```

## EventHub.on

on(event: string, callback: Function): void;

订阅指定事件。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| callback | Function | 是 | 事件回调，事件触发后调用。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on("myEvent", this.eventFunc);
        // 支持使用匿名函数订阅事件
        this.context.eventHub.on("myEvent", () => {
            console.log("call anonymous eventFunc");
        });
        // 结果：
        // eventFunc is called
        // call anonymous eventFunc
        this.context.eventHub.emit("myEvent"); 
    }

    eventFunc() {
        console.log("eventFunc is called");
    }
}
```

## EventHub.off

off(event: string, callback?: Function): void;

取消订阅指定事件。
 - 传入callback：取消指定的callback对指定事件的订阅，当该事件触发后，将不会回调该callback。
 - 不传callback：取消所有callback对指定事件的订阅。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| callback | Function | 否 | 事件回调。如果不传callback，则取消订阅该事件下所有callback。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on("myEvent", this.eventFunc1);
        this.context.eventHub.off("myEvent", this.eventFunc1); // 取消eventFunc1对myEvent事件的订阅
        this.context.eventHub.on("myEvent", this.eventFunc1);
        this.context.eventHub.on("myEvent", this.eventFunc2);
        this.context.eventHub.off("myEvent");  // 取消eventFunc1和eventFunc2对myEvent事件的订阅
    }

    eventFunc1() {
        console.log("eventFunc1 is called");
    }

    eventFunc2() {
        console.log("eventFunc2 is called");
    }
}
```

## EventHub.emit

emit(event: string, ...args: Object[]): void;

触发指定事件。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| ...args | Object[] | 是 | 可变参数，事件触发时，传递给回调函数的参数。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

export default class MainAbility extends UIAbility {
    onForeground() {
        this.context.eventHub.on("myEvent", this.eventFunc);
        // 结果：
        // eventFunc is called,undefined,undefined
        this.context.eventHub.emit("myEvent");
        // 结果：
        // eventFunc is called,1,undefined
        this.context.eventHub.emit("myEvent", 1);
        // 结果：
        // eventFunc is called,1,2
        this.context.eventHub.emit("myEvent", 1, 2);
    }

    eventFunc(argOne, argTwo) {
        console.log("eventFunc is called," + argOne + "," + argTwo);
    }
}
```
