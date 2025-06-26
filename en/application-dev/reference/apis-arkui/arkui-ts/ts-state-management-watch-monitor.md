# State Variable Change Listening

The state variable listening module provides the capability to observe changes in state variables.

This document is solely for API reference. For details about the usage guidelines and constraints, see the development guide of each API.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Watch

 Watch: (value: string) => PropertyDecorator

The @Watch decorator is used to listen for state variable changes in state management V1. For details about how to use @Watch, see [@Watch Decorator: Getting Notified of State Variable Changes](../../../ui/state-management/arkts-watch.md).

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| value  | string | Yes  | Name of the callback function used for listening. The value is specified by you.|

**Return value**

| Type             | Description                                |
| ----------------- | ------------------------------------ |
| PropertyDecorator | Property decorator. You do not need to concern yourself with this return value.|

**Example**

```ts
@Entry
@Component
struct Index {
  @State @Watch('onChange') num: number = 0; // The @Watch input parameter is the function name.
  onChange() {
    console.info(`num change to ${this.num}`);
  }
  build() {
    Column() {
      Text(`num is: ${this.num}`)
        .onClick(() => {
          this.num++; // This triggers the onChange callback.
        })
    }
  }
}
```

## Monitor<sup>12+</sup>

Monitor: MonitorDecorator

The @Monitor decorator is used to listen for state variable changes in state management V2. For details about how to use @Monitor, see [@Monitor Decorator: Listening for Value Changes of the State Variables](../../../ui/state-management/arkts-new-monitor.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## MonitorDecorator<sup>12+</sup>

type MonitorDecorator = (value: string, ...args: string[]) => MethodDecorator

Represents the actual type of the @Monitor decorator.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type    | Mandatory| Description                                                        |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| value  | string   | Yes  | Variable path name used for listening, specified by you. When only one string is passed, this is the parameter type.|
| args   | string[] | Yes  | Array of variable path names used for listening, specified by you. When multiple strings are passed, this is the parameter type.|

**Return value**

| Type           | Description                                |
| --------------- | ------------------------------------ |
| MethodDecorator | Method decorator. You do not need to concern yourself with this return value.|

**Example**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;
  @Monitor('name') // Listen for one variable.
  onNameChange(monitor: IMonitor) {
    console.info(`name change to ${this.name}`);
  }
  @Monitor('age', 'height') // Listen for multiple variables.
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
          this.info.name = 'Bob'; // Output log: name change to Bob
        })
      Text(`info.age: ${this.info.age}, info.name: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // Output log: age change from 25 to 26
          this.info.height++; // Output log: height change from 175 to 176
        })
    }
  }
}
```

## IMonitor<sup>12+</sup>

When the monitored variable changes, the state management framework will call the registered function and pass the change information of the IMonitor type.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name               | Type           | Mandatory| Description            |
| ------------------- | --------------- | ---- | ---------------- |
| dirty<sup>12+</sup> | Array\<string\> | Yes  | Array of changed paths.|

### value<sup>12+</sup>

value\<T\>(path?: string): IMonitorValue\<T\> | undefined

Obtains the change information for the specified path.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | No  | Path name of the monitored variable. If it is not specified, the first path in the **dirty** array is used by default.|

**Return value**

| Type                                                 | Description                                                        |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [IMonitorValue\<T\>](#imonitorvaluet12)  \| undefined | Path and change information for the monitored variable.<br>**T** is the type of the monitored variable.<br>If the monitored path does not exist, **undefined** is returned.<br>If no path is specified, the information corresponding to the first path in the **dirty** array is returned by default.|

**Example**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;
  @Monitor('name') // Listen for one variable.
  onNameChange(monitor: IMonitor) {
    // If no path is specified for value, the first path in the dirty array is used by default.
    console.info(`path: ${monitor.value()?.path} change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
  @Monitor('age', 'height') // Listen for multiple variables.
  onRecordChange(monitor: IMonitor) {
    // If a path is specified for value, the change information for the specified path is returned.
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
          this.info.name = 'Bob'; // Output log: path: name change from Tom to Bob
        })
      Text(`info.age: ${this.info.age}, info.name: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // Output log: path: age change from 25 to 26
          this.info.height++; // Output log: path: height change from 175 to 176
        })
    }
  }
}
```

## IMonitorValue\<T\><sup>12+</sup>

Provides the specific change information for the monitored variable, obtained through the **value** API of **IMonitor**. **T** is the type of the variable.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                | Type  | Mandatory| Description            |
| -------------------- | ------ | ---- | ---------------- |
| before<sup>12+</sup> | T      | Yes  | Variable value before change.|
| now<sup>12+</sup>    | T      | Yes  | Current variable value.  |
| path<sup>12+</sup>   | string | Yes  | Variable path.    |

**Example**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Monitor('name')
  onNameChange(monitor: IMonitor) {
    // The return value of value is of the IMonitorValue type, through which the variable change information can be obtained.
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
          this.info.name = 'Bob'; // Output log: path: name change from Tom to Bob
        })
    }
  }
}
```
