# @Monitor：状态变量修改监听

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

@Monitor装饰器在[状态管理V2](../../../ui/state-management/arkts-state-management-overview.md#状态管理v2)中用于监听状态变量修改，使得状态变量支持深度监听。适用于需要在状态变量或其嵌套属性发生变化时执行自定义逻辑（如数据同步、UI刷新、日志记录等）的场景。相比[状态管理V1](../../../ui/state-management/arkts-state-management-overview.md#状态管理v1)的[@Watch](./ts-state-management-watch.md)，@Monitor支持深度监听嵌套对象属性的变化，并从API版本26.0.0开始支持通配符能力，可更灵活地匹配状态变量路径。

开发指南参考：[@Monitor装饰器：状态变量修改异步监听](../../../ui/state-management/arkts-new-monitor.md)。

> **说明：**
>
> 从API version 12开始，支持该装饰器。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## @Monitor

Monitor: MonitorDecorator

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## MonitorDecorator

type MonitorDecorator = (value: string | MonitorDecoratorOptions, ...args: string[]) => MethodDecorator

@Monitor装饰器的实际类型。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型     | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| value  | string \| [MonitorDecoratorOptions](#monitordecoratoroptions) | 是   | 在API版本26.0.0之前，该参数为监听的状态变量名路径，路径以点号（.）分隔表示嵌套属性（如'a.b.c'），内容由开发者指定。当开发者仅传入一个字符串时，入参为string类型。从API版本26.0.0开始，该参数也可以为MonitorDecoratorOptions类型的对象，用于配置通配符能力。 |
| ...args   | string[] | 否   | 用于监听的状态变量名路径数组，路径以点号（.）分隔表示嵌套属性（如'a.b.c'），内容由开发者指定。当开发者已使用MonitorDecoratorOptions或传入多个字符串时，入参为该类型。不传该参数时默认为空，当value为string类型时，仅监听value参数指定的状态变量路径；当value为MonitorDecoratorOptions类型时，需通过该参数指定监听的状态变量路径。传入undefined时，对应的监听不生效。 |

**返回值：**

| 类型            | 说明                                 |
| --------------- | ------------------------------------ |
| MethodDecorator | 方法装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;

  // 监听一个状态变量
  @Monitor('name')
  onNameChange() {
    console.info(`name change to ${this.name}`);
  }

  // 监听多个状态变量
  @Monitor('age', 'height')
  onRecordChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }
}

@Entry
@ComponentV2
struct Index {
  @Local info: Info = new Info();

  build() {
    Column() {
      Text(`info.name: ${this.info.name}`)
        .onClick(() => {
          this.info.name = 'Bob'; // 输出日志：name change to Bob
        })
      Text(`info.age: ${this.info.age}, info.height: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // 输出日志：age change from 25 to 26
          this.info.height++; // 输出日志：height change from 175 to 176
        })
    }
  }
}
```

## MonitorDecoratorOptions

@Monitor装饰器的配置选项。

### 属性

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API版本26.0.0开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型    | 只读 | 可选 | 说明                                                         |
| -------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| enableWildcard | boolean | 否   | 是   | 是否支持通配符能力。true：使能通配符能力，路径中可使用通配符（'*'）进行模糊监听；false：关闭通配符能力。默认值为true。 |


## IMonitor

当监听的状态变量变化时，状态管理框架侧将回调开发者注册的函数，并传入变化信息。变化信息的类型为IMonitor。

### 属性

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 类型            | 只读 | 可选 | 说明             |
| ------------------- | --------------- | ---- | ---- | ---------------- |
| dirty | Array\<string\> | 否   | 否   | 被监听的状态变量中发生变化的属性路径数组，路径格式与@Monitor装饰器指定的状态变量名路径一致，支持点号分隔的嵌套属性路径（如'a.b.c'）。从API版本26.0.0开始，当通配符能力开启时，该数组中可能包含通配符路径，通过[value](#value)()方法查询通配符路径将返回undefined。 |

### value

value\<T\>(path?: string): IMonitorValue\<T\> | undefined

获取指定path的变化信息。

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 否   | 被监听的状态变量路径名。未指定时默认使用变化路径数组dirty中的第一个路径。从API版本26.0.0开始，默认使用dirty中第一个非通配符路径。当指定路径为通配符路径时，返回undefined。 |

**返回值：**

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [IMonitorValue\<T\>](#imonitorvaluet)  \| undefined | @Monitor监听状态变量的路径以及变化前后值信息。<br>T为监听状态变量的类型。<br>当监听的路径不存在时，返回undefined。<br>API版本26.0.0之前，当未指定路径时，默认返回变化路径数组dirty中第一个路径对应的信息。<br>从API版本26.0.0开始，当未指定路径时，默认返回变化路径数组dirty中第一个非通配符路径对应的信息。<br>当指定路径为通配符路径时，返回undefined。<br>当未指定路径，且变化路径数组dirty中所有路径均为通配符路径时，返回undefined。 |

**示例：**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;

  // 监听一个状态变量
  @Monitor('name')
  onNameChange(monitor: IMonitor) {
    // 未指定value的入参时，默认使用dirty中的第一个路径作为入参
    console.info(`path: ${monitor.value()?.path} change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  // 监听多个状态变量
  @Monitor('age', 'height')
  onRecordChange(monitor: IMonitor) {
    // 指定value的入参时，将返回入参路径path对应的状态变量变化值信息
    monitor.dirty.forEach((path: string) => {
      console.info(`path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }
}

@Entry
@ComponentV2
struct Index {
  @Local info: Info = new Info();

  build() {
    Column() {
      Text(`info.name: ${this.info.name}`)
        .onClick(() => {
          this.info.name = 'Bob'; // 输出日志：path: name change from Tom to Bob
        })
      Text(`info.age: ${this.info.age}, info.height: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // 输出日志：path: age change from 25 to 26
          this.info.height++; // 输出日志：path: height change from 175 to 176
        })
    }
  }
}
```

## IMonitorValue\<T\>

@Monitor监听状态变量变化的具体信息，通过IMonitor的value接口获取。T为状态变量类型。

### 属性

**卡片能力：** 从API version 23开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                 | 类型   | 只读 | 可选 | 说明             |
| -------------------- | ------ | ---- | ---- | ---------------- |
| before | T      | 否   | 否   | 状态变量变化前的值。 |
| now    | T      | 否   | 否   | 状态变量当前的值。   |
| path   | string | 否   | 否   | 状态变量的路径。     |

**示例：**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Monitor('name')
  onNameChange(monitor: IMonitor) {
    // value的返回值为IMonitorValue类型，可以通过该返回值获取状态变量变化的信息
    console.info(`path: ${monitor.value()?.path} change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}
@Entry
@ComponentV2
struct Index {
  @Local info: Info = new Info();
  build() {
    Column() {
      Text(`info.name: ${this.info.name}`)
        .onClick(() => {
          this.info.name = 'Bob'; // 输出日志：path: name change from Tom to Bob
        })
    }
  }
}
```