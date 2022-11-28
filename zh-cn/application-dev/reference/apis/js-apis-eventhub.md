# EventHub

EventHub模块提供了事件中心，提供订阅、取消订阅、触发事件的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用eventHub的功能前，需要通过Ability实例的成员变量context获取。

```js
import Ability from '@ohos.application.Ability';
export default class MainAbility extends Ability {
    func1(){
        console.log("func1 is called");
    }
    onForeground() {
        this.context.eventHub.on("123", this.func1);
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
| callback | Function | 是 | 事件回调，事件触发后运行。 |

**示例：**
    
  ```js
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.on("123", () => {
              console.log("call anonymous func 1");
          });
          // 结果：
          // func1 is called
          // call anonymous func 1
          this.context.eventHub.emit("123"); 
      }
      func1() {
          console.log("func1 is called");
      }
  }
  ```


## EventHub.off

off(event: string, callback?: Function): void;

取消订阅指定事件。当callback传值时，取消订阅指定的callback；未传值时，取消订阅该事件下所有callback。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | string | 是 | 事件名称。 |
| callback | Function | 否 | 事件回调。如果不传callback，则取消订阅该事件下所有callback。 |

**示例：**
    
  ```js
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.off("123", this.func1); //取消订阅func1
          this.context.eventHub.on("123", this.func1);
          this.context.eventHub.on("123", this.func2);
          this.context.eventHub.off("123");  //取消订阅func1和func2
      }
      func1() {
          console.log("func1 is called");
      }
      func2() {
          console.log("func2 is called");
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
    
  ```js
  import Ability from '@ohos.application.Ability';
  
  export default class MainAbility extends Ability {
      onForeground() {
          this.context.eventHub.on("123", this.func1);
          // 结果：
          // func1 is called,undefined,undefined
          this.context.eventHub.emit("123");
          // 结果：
          // func1 is called,1,undefined
          this.context.eventHub.emit("123", 1);
          // 结果：
          // func1 is called,1,2
          this.context.eventHub.emit("123", 1, 2);
      }
      func1(a, b) {
          console.log("func1 is called," + a + "," + b);
      }
  }
  ```
