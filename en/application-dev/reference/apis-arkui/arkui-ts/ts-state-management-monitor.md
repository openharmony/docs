# @Monitor: Listening for Value Changes of the State Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=0988540cce75203f9bab8bf4ce7ce0a00963fbfc translatedAt=2026-08-13T07:01:05.750Z pushedAt=2026-08-14T02:20:22.388Z -->

**\@Monitor** is used in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to listen for changes to state variables, so that the state variables support deep listening. It is applicable to scenarios where custom logic (such as data synchronization, UI refresh, and log recording) needs to be executed when state variables or their nested properties change. Compared with [@Watch](./ts-state-management-watch.md) in [state management V1](../../../ui/state-management/arkts-state-management-overview.md#state-management-v1), **\@Monitor** supports deep listening to changes in nested object properties. Since API version 26.0.0, **\@Monitor** also supports wildcard characters, allowing for more flexible matching of variable paths.

For details, see [@Monitor Decorator: Listening for Value Changes of the State Variables](../../../ui/state-management/arkts-new-monitor.md).

> **NOTE**
>
> This decorator is supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## @Monitor

Monitor: MonitorDecorator

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

## MonitorDecorator

type MonitorDecorator = (value: string | MonitorDecoratorOptions, ...args: string[]) => MethodDecorator

Represents the actual type of the **@Monitor** decorator.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type     | Mandatory | Description                                                         |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| value  | string \| [MonitorDecoratorOptions](#monitordecoratoroptions) | Yes   | In versions earlier than API 26.0.0, this parameter indicates the path of the monitored variable name. The path is separated by periods (.) to indicate nested properties (for example, **'a.b.c'**). The content is specified by you. The input value is of the string type when only a string is passed. Since API version 26.0.0, this parameter can also be an object of the **MonitorDecoratorOptions** type, which is used to configure the wildcard capability. |
| ...args   | string[] | No   | Array of paths of the monitored state variable names. The paths are separated by periods (.) to indicate nested properties (for example, **'a.b.c'**). The content is specified by you. The input value is of the type specified by this parameter when **MonitorDecoratorOptions** is used or multiple strings are passed. If this parameter is not passed, the value is empty by default. When the value is of the string type, only the state variable path specified by the **value** parameter is monitored. When the value is of the **MonitorDecoratorOptions** type, the state variable path to be monitored must be specified through this parameter. If **undefined** is passed, the corresponding monitoring does not take effect. |

**Return value**

| Type            | Description                                 |
| --------------- | ------------------------------------ |
| MethodDecorator | Method decorator. You do not need to concern yourself with this return value. |

**Example:**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;

  // Listen for one variable.
  @Monitor('name')
  onNameChange() {
    console.info(`name change to ${this.name}`);
  }

  // Listen for multiple variables.
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
          this.info.name = 'Bob'; // Output log: name change to Bob.
        })
      Text(`info.age: ${this.info.age}, info.height: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // Output log: age change from 25 to 26.
          this.info.height++; // Output log: height change from 175 to 176.
        })
    }
  }
}
```

## MonitorDecoratorOptions

Represents the configuration options of the **@Monitor** decorator.

### Attributes

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Widget capability:** This API can be used in ArkTS widgets since API version 26.0.0.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name           | Type    | Read-Only | Optional | Description                                                  |
| -------------- | ------- | --------- | -------- | ------------------------------------------------------------ |
| enableWildcard | boolean | No        | Yes      | Whether to support the wildcard capability. The value **true** indicates to enable the wildcard capability, allowing the use of wildcards (**'*'**) in the path for fuzzy monitoring, and **false** indicates to disable the wildcard capability. The default value is **true**. |

## IMonitor

When the monitored state variable changes, the state management framework will call the registered function and pass the change information of the **IMonitor** type.

### Properties

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name                | Type            | Read-Only | Optional | Description             |
| ------------------- | --------------- | ---- | ---- | ---------------- |
| dirty | Array\<string\> | No   | No   | Array of paths where properties have changed in the monitored variable. The path format is the same as that of the variable name path specified by **\@Monitor**. Nested property paths separated by periods (.) are supported, for example, **'a.b.c'**. Since API version 26.0.0, when the wildcard capability is enabled, this array may contain wildcard paths, and querying wildcard paths through **[value](#value)()** will return **undefined**. |

### value

value\<T\>(path?: string): IMonitorValue\<T\> | undefined

Obtains the change information for the specified path.

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory | Description                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| path   | string | No   | Path name of the monitored variable. If it is not specified, the first path in the **dirty** array is used by default. Since API version 26.0.0, the first non-wildcard path in **dirty** is used by default. If the specified path is a wildcard path, **undefined** is returned. |

**Return value**

| Type                                                  | Description                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| [IMonitorValue\<T\>](#imonitorvaluet)  \| undefined | Path and change information for the variable monitored by **\@Monitor**.<br>**T** is the type of the monitored variable.<br>If the monitored path does not exist, **undefined** is returned.<br>Prior to API version 26.0.0, if no path is specified, this parameter returns information corresponding to the first path in the **dirty** array of changed paths by default.<br>Since API version 26.0.0, if no path is specified, this parameter returns the first non-wildcard path in the **dirty** array of changed paths by default.<br>If the specified path is a wildcard path, **undefined** is returned.<br>If no path is specified and all paths in the **dirty** array are wildcard paths, **undefined** is returned. |

**Example:**

```ts
@ObservedV2
class Info {
  @Trace name: string = 'Tom';
  @Trace age: number = 25;
  @Trace height: number = 175;

  // Listen for one variable.
  @Monitor('name')
  onNameChange(monitor: IMonitor) {
    // If no path is specified for value, the first path in the dirty array is used by default.
    console.info(`path: ${monitor.value()?.path} change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  // Listen for multiple variables.
  @Monitor('age', 'height')
  onRecordChange(monitor: IMonitor) {
    // If a path is specified for value, the change information for the specified path is returned.
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
          this.info.name = 'Bob'; // Output log: path: name change from Tom to Bob.
        })
      Text(`info.age: ${this.info.age}, info.height: ${this.info.height}`)
        .onClick(() => {
          this.info.age++; // Output log: path: age change from 25 to 26
          this.info.height++; // Output log: path: height change from 175 to 176
        })
    }
  }
}
```

## IMonitorValue\<T\>

Provides the specific information about the state variable changes monitored by **\@Monitor**, obtained through the **value** API of **IMonitor**. **T** is the state variable type.

### Properties

**Widget capability:** This API can be used in ArkTS widgets since API version 23.

**Atomic service API:** This API can be used in atomic services since API version 12.

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name   | Type   | Read-Only | Optional | Description                              |
| ------ | ------ | --------- | -------- | ---------------------------------------- |
| before | T      | No        | No       | Value of the state variable before the change. |
| now    | T      | No        | No       | Current value of the state variable.     |
| path   | string | No        | No       | Path of the state variable.              |

**Example:**

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