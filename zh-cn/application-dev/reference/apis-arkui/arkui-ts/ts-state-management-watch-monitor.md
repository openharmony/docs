# 状态变量变化监听
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @HelloCrease-->

状态变量监听模块提供了对状态变量变化的感知能力。

本文档仅为API参考说明。实际功能使用与限制见各接口对应的开发指南。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## Watch

 Watch: (value: string) => PropertyDecorator

@Watch装饰器用于状态管理V1中对状态变量变化的监听。@Watch的详细使用方式见[@Watch装饰器：状态变量更改通知](../../../ui/state-management/arkts-watch.md)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| value  | string | 是   | 用于监听的回调函数名，内容由开发者指定。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| PropertyDecorator | 属性装饰器，开发者无需关注该返回值。 |

**示例：**

```ts
@Entry
@Component
struct Index {
  @State @Watch('onChange') num: number = 0; // @Watch入参为函数名
  onChange() {
    console.info(`num change to ${this.num}`);
  }
  build() {
    Column() {
      Text(`num is: ${this.num}`)
        .onClick(() => {
          this.num++; // 会触发onChange函数回调
        })
    }
  }
}
```

## Monitor<sup>12+</sup>

Monitor: MonitorDecorator

@Monitor装饰器用于状态管理V2中对状态变量变化的监听。@Monitor相关内容的详细使用方式见[@Monitor装饰器：状态变量修改监听](../../../ui/state-management/arkts-new-monitor.md)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## MonitorDecorator<sup>12+</sup>

type MonitorDecorator = (value: string, ...args: string[]) => MethodDecorator

@Monitor装饰器的实际类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数**：

| 参数名 | 类型     | 必填 | 说明                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| value  | string   | 是   | 用于监听的变量名路径，内容由开发者指定。当开发者仅传入一个字符串时，入参为该类型。 |
| args   | string[] | 是   | 用于监听的变量名路径数组，内容由开发者指定。当开发者传入多个字符串时，入参为该类型。 |

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
  @Monitor('name') // 监听一个变量
  onNameChange(monitor: IMonitor) {
    console.info(`name change to ${this.name}`);
  }
  @Monitor('age', 'height') // 监听多个变量
  onRecordChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
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

## IMonitor<sup>12+</sup>

当监听的变量变化时，状态管理框架侧将回调开发者注册的函数，并传入变化信息。变化信息的类型即为IMonitor类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 类型            | 必填 | 说明             |
| ------------------- | --------------- | ---- | ---------------- |
| dirty<sup>12+</sup> | Array\<string\> | 是   | 变化路径的数组。 |

### value<sup>12+</sup>

value\<T\>(path?: string): IMonitorValue\<T\> | undefined

获取指定path的变化信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | 否   | 可选，被监听的变量路径名。未指定时默认使用变化路径数组dirty中的第一个路径。 |

**返回值：**

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [IMonitorValue\<T\>](#imonitorvaluet12)  \| undefined | @Monitor监听变量的路径以及变化前后值信息。<br>T为监听变量的类型。<br>当监听的路径不存在时，返回undefined。<br>当未指定路径时，默认返回变化路径数组dirty中第一个路径对应的信息。 |

**示例：**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;
  @Monitor('name') // 监听一个变量
  onNameChange(monitor: IMonitor) {
    // 未指定value的入参时，默认使用dirty中的第一个路径作为入参
    console.info(`path: ${monitor.value()?.path} change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor('age', 'height') // 监听多个变量
  onRecordChange(monitor: IMonitor) {
    // 指定value的入参时，将返回入参路径path对应的变量变化值信息
    monitor.dirty.forEach((path: string) => {
      console.info(`path: ${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    })
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
      Text(`info.age: ${this.info.age}, info.name: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // 输出日志：path: age change from 25 to 26
          this.info.height++; // 输出日志：path: height change from 175 to 176
        })
    }
  }
}
```

## IMonitorValue\<T\><sup>12+</sup>

@Monitor监听变量变化的具体信息，通过IMonitor的value接口获取。T为变量类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                 | 类型   | 必填 | 说明             |
| -------------------- | ------ | ---- | ---------------- |
| before<sup>12+</sup> | T      | 是   | 变量变化前的值。 |
| now<sup>12+</sup>    | T      | 是   | 变量当前的值。   |
| path<sup>12+</sup>   | string | 是   | 变量的路径。     |

**示例：**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Monitor('name')
  onNameChange(monitor: IMonitor) {
    // value的返回值为IMonitorValue类型，可以通过该返回值获取变量变化的信息
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
