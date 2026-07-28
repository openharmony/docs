# addMonitor and clearMonitor APIs: Dynamically Adding and Removing Listeners

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:06:35.594Z pushedAt=2026-07-22T09:54:10.562Z -->

The [addMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#addmonitor20) and [clearMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#clearmonitor20) APIs enable you to dynamically add or remove listeners for state variables in state management V2.

Before using these APIs, it is recommended that you familiarize yourself with the following concepts: [\@ObservedV2/\@Trace](./arkts-new-observedV2-and-trace.md) and [\@Monitor](./arkts-new-monitor.md).

>**NOTE**
>
>The **addMonitor** and **clearMonitor** APIs from **UIUtils** are supported in state management V2 since API version 20.

## **Overview**

If the decorator [\@Monitor](./arkts-new-monitor.md) is declared in [\@ObservedV2](./arkts-new-observedV2-and-trace.md) and [\@ComponentV2](./arkts-create-custom-components.md#componentv2), all \@ObservedV2 and \@ComponentV2 instances will have the same listening callback by default, and the corresponding listening callback cannot be canceled or deleted.

For scenarios requiring dynamic management of listeners, use the [addMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#addmonitor20) and [clearMonitor](../../reference/apis-arkui/js-apis-stateManagement.md#clearmonitor20) APIs to add or remove listeners on individual \@ObservedV2 and \@ComponentV2 instances.

- To use **addMonitor** and **clearMonitor**, you must import the **UIUtils** utility.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```

- These APIs only support state variables from state management V2.

- The **clearMonitor** API can only remove listeners added dynamically via **addMonitor**; it cannot remove static callbacks defined using the \@Monitor decorator.

## Use Rules

- The **addMonitor** and **clearMonitor** APIs support batch processing by accepting an array of state variable paths to add or remove listeners for multiple properties simultaneously.

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onChange1);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User name ${this.user.name}`)
        .fontSize(20)
        .onClick(() => {
          // Change the value of name, triggering the onChange1 listener.
          this.user.name += '!';
        })
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age increments, triggering the onChange1 listener.
          this.user.age++;
        })
      Button('clear name and age monitor fun')
        .onClick(() => {
          // Remove the onChange1 listener for both age and name properties.
          // Subsequent changes to these properties will not trigger callbacks.
          UIUtils.clearMonitor(this.user, ['age', 'name'], this.user.onChange1);
        })
    }
  }
}
```

- A single state variable path can have multiple listeners registered via **addMonitor**. However, attempting to register a listener with the same function name more than once for the same path will result in operation failure and generate an error log.

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange2(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange2: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // Correct usage: Register the onChange1 listener for age.
    UIUtils.addMonitor(this, 'age', this.onChange1);
    // Correct usage: Register the onChange2 listener for age.
    UIUtils.addMonitor(this, 'age', this.onChange2);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1 in View: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    // Error: Attempting to register another listener named onChange1 for age
    // Print an error log indicating the addition failure: FIX THIS APPLICATION ERROR: AddMonitor 'onChange1' owned by 'User' path: 'age' - failed when adding duplicate path
    UIUtils.addMonitor(this.user, 'age', this.onChange1);
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age increments, triggering both onChange1 and onChange2 listeners.
          this.user.age++;
        })
    }
  }
}
```

- The [isSynchronous](../../reference/apis-arkui/js-apis-stateManagement.md#monitoroptions20) configuration option for a listener is established during its initial registration and becomes immutable thereafter. Any subsequent attempt to modify it for the same listener will fail and produce an error log.

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    // Correct usage: register the listener function onChange1 for age. When options is not set, the default is an asynchronous listener callback.
    UIUtils.addMonitor(this, 'age', this.onChange1);
    // Error: Attempting to modify the synchronization mode after initial registration
    // Fails with this log: FIX THIS APPLICATION ERROR: addMonitor failed, current function onChange1 has already register as async, cannot change to sync anymore.
    UIUtils.addMonitor(this, 'age', this.onChange1, { isSynchronous: true });
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age increments, triggering onChange1 asynchronously.
          // Log: onChange1: User property age change from 0 to 2.
          this.user.age++;
          this.user.age++;
        })
    }
  }
}
```

- The **clearMonitor** API enables removal of listeners for specified paths. You can either remove a specific listener by providing the listener parameter, or remove all listeners for the path by omitting this parameter.

  Note that when **clearMonitor** is called, if it is found that the current callback has not been registered on the state variable corresponding to the path, or if the state variable currently has no listener functions, a warning log will be printed to alert you that the deletion has failed.

After a listener function is removed, changes to the state variable will no longer trigger the corresponding listener function.

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange1(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange1: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange2(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange2: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  onChange3(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange3: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, 'age', this.onChange1);
    UIUtils.addMonitor(this, 'age', this.onChange2);
    UIUtils.addMonitor(this, 'age', this.onChange3);
  }
}

@Entry
@ComponentV2
struct Page {
  user: User = new User();

  build() {
    Column() {
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // Step 1: Click the component to increment the age value, triggering onChange1, onChange2, and onChange3.
          this.user.age++;
        })
      Button('clear age onChange1').onClick(() => {
        // Step 2: Click the button to remove the onChange1 listener. Subsequent clicks on User age will only trigger onChange2 and onChange3.
        // Step 3: Click the button to attempt removal again. This attempt fails because onChange1 has already been removed.
        // Error log: FIX THIS APPLICATION ERROR: cannot clear path age for onChange1 because it was never registered with addMonitor.
        UIUtils.clearMonitor(this.user, 'age', this.user.onChange1);
      })
      Button('clear age monitors').onClick(() => {
        // Step 4: Click the button to remove all listeners registered for the age property. After this operation, clicking User age will not trigger any callbacks.
        UIUtils.clearMonitor(this.user, 'age');
      })
      Button('clear name monitors').onClick(() => {
        // Step 5: Click the button to remove listeners for the name property. This operation fails because there are no listeners registered.
        // Print error log: FIX THIS APPLICATION ERROR: cannot clear path name for current target User because no Monitor function for this path was registered
        UIUtils.clearMonitor(this.user, 'name');
      })
    }
  }
}
```

## Constraints

- The **addMonitor** and **clearMonitor** APIs only support adding or removing listeners for instances decorated with \@ComponentV2 or \@ObservedV2 that contain at least one \@Trace decorated variable. Attempting to use these APIs on non-conforming instances will result in a runtime error (error code: 130000).

  The following example demonstrates this constraint for **addMonitor**; the same limitation applies to **clearMonitor**.

  ```ts
  import { UIUtils } from '@kit.ArkUI';

  @ObservedV2
  class A {
    @Trace a: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // Correct usage
      UIUtils.addMonitor(this, 'a', this.onChange);
    }
  }
  
  @Observed
  class B {
    @Track b: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`B property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // Invalid target object parameter: The current this refers to an object decorated with @Observed.
      // Error code: 130000
      UIUtils.addMonitor(this, 'b', this.onChange);
    }
  }
  
  class C {
    @Track c: number = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`C property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // Invalid target object parameter: The current this refers to a regular class.
      // Error code: 130000
      UIUtils.addMonitor(this, 'c', this.onChange);
      // Incorrect usage: Invalid target object parameter undefined.
      // Error code: 130000
      UIUtils.addMonitor(undefined, 'c', this.onChange);
    }
  }
  
  let a: A = new A();
  let b: B = new B();
  let c: C = new C();
  ```

- The observation path in **addMonitor** and **clearMonitor** must be a string or array. Passing any unsupported type will trigger a runtime error with code 130001.

  The following example demonstrates this constraint for **addMonitor**; the same limitation applies to **clearMonitor**.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  
  @ObservedV2
  class A {
    @Trace a: number = 0;
    @Trace b: number = 0;
    invalidPath: number | string = 0;
  
    onChange(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // Correct usage
      UIUtils.addMonitor(this, 'a', this.onChange);
      // Correct usage
      UIUtils.addMonitor(this, ['a', 'b'], this.onChange);
      // Error: The path must be string or array type (error code: 130001).
      UIUtils.addMonitor(this, this.invalidPath as string, this.onChange);
      // Error: The path must be string or array type (error code: 130001).
      UIUtils.addMonitor(this, undefined, this.onChange);
    }
  }
  
  let a: A = new A();
  ```

- The callback function in **addMonitor** is mandatory and must be a named function (not anonymous) and of method type. Passing an unsupported type will trigger a runtime error with code 130002.

  For **clearMonitor**, the callback function is optional. When provided, it must be a named function (not anonymous) and of function type.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  
  @ObservedV2
  class A {
    @Trace a: number = 0;
    @Trace b: number = 0;
    invalidFunc: Function | number = 0;
  
    onChange1(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    onChange2(mon: IMonitor) {
      mon.dirty.forEach((path: string) => {
        console.info(`A property ${path} change from ${mon.value(path)?.before} to   ${mon.value(path)?.now}`);
      });
    }
  
    constructor() {
      // Correct usage: Register onChange1 for variable a.
      UIUtils.addMonitor(this, 'a', this.onChange1);
      // Correct usage: Register onChange2 for variable a.
      UIUtils.addMonitor(this, 'a', this.onChange2);
      // Correct usage: Register onChange1 for variable b.
      UIUtils.addMonitor(this, 'b', this.onChange1);
      // Error: The callback must be a named function (error code: 130002).
      UIUtils.addMonitor(this, 'a', undefined);
      // Error: Anonymous functions are not supported (error code: 130002).
      UIUtils.addMonitor(this, 'a', (mon: IMonitor) => {});
      // Error: The provided callback is not of function type (error code: 130002).
      UIUtils.addMonitor(this, 'a', this.invalidFunc as (mon: IMonitor) => void);
    }
  }
  
  let a: A = new A();
  // Correct usage: Remove the onChange1 listener for a.
  UIUtils.clearMonitor(a, 'a', a.onChange1);
  // Correct usage: Remove all listeners for a.
  UIUtils.clearMonitor(a, 'a');
  // Correct usage. Equivalent to passing no parameters, which removes all listener functions of a.
  UIUtils.clearMonitor(a, 'a', undefined);
  // Error: Anonymous functions are not supported (error code: 130002).
  UIUtils.clearMonitor(a, 'a', (mon: IMonitor) => {});
  ```

## Rules for Listening for Changes with addMonitor

The rules for listening for changes with **addMonitor** and the [\@Monitor](./arkts-new-monitor.md) decorator are largely consistent. The comparison is shown in the table below.

|  Scenario | addMonitor| @Monitor  |
|------|----|------|
| [Listening for @Trace decorated properties in \@ObservedV2 classes](#listening-for-trace-decorated-properties-in-observedv2-classes-and-state-variables-in-componentv2-components)   | Supported| Supported|
| [Listening for state variables in \@ComponentV2 components](#listening-for-trace-decorated-properties-in-observedv2-classes-and-state-variables-in-componentv2-components) | Supported| Supported|
| [Listening for Index and Length Changes of Array-Type State Variables](#listening-for-index-and-length-changes-of-array-type-state-variables) | Supported| Supported|
| [Monitoring API Calls on Built-in Type State Variables](#monitoring-api-calls-on-built-in-type-state-variables) | Not supported by default. Supported via configuration options starting from API version 26.0.0 | Not supported by default. Supported via configuration options starting from API version 26.0.0 |
| [Independent Path Change Monitoring](#listening-for-paths-independently) | Supported | Not supported by default. Supported via configuration options starting from API version 26.0.0 |
| [Listening for Variable Accessibility Changes](#listening-for-variable-accessibility-changes) | Supported | Not supported by default. Supported via configuration options starting from API version 26.0.0 |
| [Configuring Synchronous Listeners](#configuring-synchronous-listeners) | Supported| Not supported|
| [Listening for Synchronous State Variable Changes in Constructors](#listening-for-synchronous-state-variable-changes-in-constructors)  | Supported| Not supported|
| [Dynamically Canceling Listening of \@ObservedV2/\@ComponentV2 Instances](#dynamically-canceling-listening-of-observedv2componentv2-instances)  | Supported| Not supported|
| [Using Paths with Wildcards](#using-paths-with-wildcards) | Not supported by default. Supported via configuration options starting from API version 26.0.0 | Not supported by default. Supported via configuration options starting from API version 26.0.0 |

## When to Use

### Listening for @Trace Decorated Properties in \@ObservedV2 Classes and State Variables in \@ComponentV2 Components

In the following example:

- An **onChange** listener is added for **age** and **name** in the constructor of **User**.

- In the **aboutToAppear** lifecycle callback of the custom component **Page**, an **onChangeInView** listener is added for **user**.

- Clicking **Text(`User name ${this.user.name}`)** changes the value of **name** and triggers **onChange**.

- Clicking **Text(`User age ${this.user.age}`)** changes the value of **age** and triggers **onChange**.

- Clicking **Text(`reset User`)** reassigns the entire **user** object and triggers **onChangeInView**.

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 0;
  @Trace name: string = 'Jack';

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onChange);
  }
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  onChangeInView(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange in View: View property ${path} change from ${JSON.stringify(mon.value(path)?.before)} to ${JSON.stringify(mon.value(path)?.now)}`);
    });
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'user', this.onChangeInView);
  }

  build() {
    Column() {
      Text(`User name ${this.user.name}`)
        .fontSize(20)
        .onClick(() => {
          // Change the value of name, triggering the onChange listener.
          this.user.name += '!';
        })
      Text(`User age ${this.user.age}`)
        .fontSize(20)
        .onClick(() => {
          // age increments, triggering the onChange listener.
          this.user.age++;
        })
      Text(`reset User`)
        .fontSize(20)
        .onClick(() => {
          // Reassign the entire user object, triggering the onChangeInView listener
          this.user = new User();
        })
    }
  }
}
```

### Listening for Index and Length Changes of Array-Type State Variables

The following example shows how to listen for index and length changes of an array.

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Page {
  @Local arr: string[] = ['a', 'b', 'c']

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: View property ${path} change from ${JSON.stringify(mon.value(path)?.before)} to ${JSON.stringify(mon.value(path)?.now)}`);
    });
  }

  aboutToAppear(): void {
    // Add the onChange listener for array indexes 0, 1, 2, and array length.
    UIUtils.addMonitor(this, ['arr.0', 'arr.1', 'arr.2', 'arr.length'], this.onChange);
  }

  build() {
    Column() {
      Text(`len ${this.arr.length}`).fontSize(20)
      Text(`${this.arr[0]}`).fontSize(20).onClick(() => {
        // Change the array item at index 0.
        // onChange output: onChange: View property arr.0 change from "a" to "az"
        this.arr[0] += 'z';
      })
      Text(`${this.arr[1]}`).fontSize(20).onClick(() => {
        // Change the array item at index 1.
        // onChange output: onChange: View property arr.1 change from "b" to "bz"
        this.arr[1] += 'z';
      })
      Text(`${this.arr[2]}`).fontSize(20).onClick(() => {
        // Change the array item at index 2.
        // onChange output: onChange: View property arr.2 change from "c" to "cz"
        this.arr[2] += 'z';
      })
      Text(`push`).fontSize(20).onClick(() => {
        // Push a new array item 'd' at the end of the array, with index 3, which is not monitored.
        // The array length changes, and length changes are monitored.
        // onChange output: onChange: View property arr.length change from 3 to 4
        this.arr.push('d');
      })
      Text(`shift`).fontSize(20).onClick(() => {
        // Remove the first array element.
        // 0: az -> bz
        // 1: bz -> cz
        // 2: cz -> d
        // length: 4 -> 3
        // onChange callback:
        // onChange: View property arr.0 change from "az" to "bz"
        // onChange: View property arr.1 change from "bz" to "cz"
        // onChange: View property arr.2 change from "cz" to "d"
        // onChange: View property arr.length change from 4 to 3
        this.arr.shift();
      })
    }
  }
}
```

### Listening for Paths Independently

\@Monitor does not support independent path listening, requiring correct parameters to be passed. [Passing non-state variables may cause unintended side-effect monitoring](./arkts-new-monitor.md#passing-correct-input-parameters-to-monitor).

**addMonitor** implements independent listening for different paths. In this example, clicking **Button('change age&name')** outputs:

``` ts
property path:age change from 24 to 25
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class Info {
  name: string = 'John';
  @Trace age: number = 24;

  onPropertyChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.info(`property path:${path} change from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`);
    });
  }

  constructor() {
    UIUtils.addMonitor(this, ['age', 'name'], this.onPropertyChange);
  }
}

@Entry
@ComponentV2
struct Index {
  info: Info = new Info();
  build() {
    Column() {
      Button('change age&name')
        .onClick(() => {
          this.info.age = 25; // Change both state variable age and non-state variable name.
          this.info.name = 'Johny';
        })
    }
  }
}
```

### Listening for Variable Accessibility Changes

[\@Monitor does not record the state of a state variable when it is inaccessible](./arkts-new-monitor.md#variables-cannot-be-observed-during-accessibility-changes), so it cannot listen for accessibility changes.

**addMonitor** records inaccessible states, enabling listening for accessibility changes. Example:

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User | undefined | null = new User();

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear() {
    UIUtils.addMonitor(this, ['user.age'], this.onChange);
  }

  build() {
    Column() {
      Text(`User age ${this.user?.age}`).fontSize(20)
      Button('set user to undefined').onClick(() => {
          // age: from accessible to inaccessible
          // Trigger onChange: User property user.age change from 10 to undefined.
          this.user = undefined;
        })
      Button('set user to User').onClick(() => {
        // age: from inaccessible to accessible
        // Trigger onChange: User property user.age change from undefined to 10.
        this.user = new User();
      })
      Button('set user to null').onClick(() => {
        // age: from accessible to inaccessible
        // Trigger onChange: User property user.age change from 10 to undefined.
        this.user = null;
      })
    }
  }
}
```

### Configuring Synchronous Listeners

Unlike \@Monitor, which only supports asynchronous listening, **addMonitor** can be configured with synchronous listeners. In the following example, clicking **Text(`User age ${this.user.age}`)** increments the value of **age** twice, triggering the **onChange** listener twice:

``` ts
onChange: User property user.age change from 10 to 11
onChange: User property user.age change from 11 to 12
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    // addMonitor supports configuration as a synchronous listener function.
    UIUtils.addMonitor(this, 'user.age', this.onChange, { isSynchronous: true })
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`).fontSize(20).onClick(() => {
        this.user.age++;
        this.user.age++;
      })
    }
  }
}
```

With \@Monitor, only one callback is triggered:

``` ts
onChange: User property user.age change from 10 to 12
```

```ts
@ObservedV2
class User {
  @Trace age: number = 10;
}

@Entry
@ComponentV2
struct Page {
  @Local user: User = new User();

  // @Monitor supports only asynchronous listening.
  @Monitor('user.age')
  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`User age ${this.user.age}`).fontSize(20).onClick(() => {
        this.user.age++;
        this.user.age++;
      })
    }
  }
}
```

### Listening for Synchronous State Variable Changes in Constructors

Unlike [\@Monitor, which constructs asynchronously](./arkts-new-monitor.md#effective-and-expiration-time-of-variable-listening-by-the-monitor-in-the-class), **addMonitor** operates synchronously. The listener **this.onMessageChange** is added to **message** immediately after **UIUtils.addMonitor(this, 'message', this.onMessageChange);** execution. In the following example:

- Page initialization constructs an **Info** instance, triggering **onMessageChange**.

- Clicking **Button('change message')** also triggers **onMessageChange**.

The output logs are as follows:

``` ts
message change from not initialized to initialized
message change from initialized to Index aboutToAppear
message change from Index aboutToAppear to Index click to change message
```

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class Info {
  @Trace message: string = 'not initialized';

  constructor() {
    // addMonitor can monitor changes to message in the constructor.
    UIUtils.addMonitor(this, 'message', this.onMessageChange);
    this.message = 'initialized';
  }
  onMessageChange(monitor: IMonitor) {
    console.info(`message change from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }
}

@Entry
@ComponentV2
struct Page {
  info: Info = new Info();

  aboutToAppear(): void {
    this.info.message = 'Index aboutToAppear';
  }

  build() {
    Column() {
      Button('change message')
        .onClick(() => {
          this.info.message = 'Index click to change message';
        })
    }
  }
}
```

### Dynamically Canceling Listening of \@ObservedV2/\@ComponentV2 Instances

Unlike @Monitor, **addMonitor** and **clearMonitor** enable dynamic management of listeners for different \@ObservedV2/\@ComponentV2 instances. Example:

```ts
import { UIUtils } from '@kit.ArkUI';

@ObservedV2
class User {
  @Trace age: number = 10;

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`onChange: User property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  constructor(needMonitor: boolean) {
    if (needMonitor) {
      UIUtils.addMonitor(this, 'age', this.onChange);
    }
  }
}

@Entry
@ComponentV2
struct Page {
  @Local user1: User = new User(true);
  @Local user2: User = new User(false);
  @Local count: number = 10;

  build() {
    Column() {
      Text(`user1 age ${this.user1.age}`).fontSize(20).onClick(() => {
        // With a monitor listener
        this.user1.age++;
      })
      Text(`user2 age ${this.user2.age}`).fontSize(20).onClick(() => {
        // Without monitor listeners
        this.user2.age++;
      })
      Button(`remove user1 monitor`).onClick(() => {
        UIUtils.clearMonitor(this.user1, 'age', this.user1.onChange);
      })

      Button(`change count`).onClick(() => {
        this.count++;
      })

      Child({ needMonitor: true, count: this.count })
      Child({ needMonitor: false, count: this.count })
    }
  }
}

@ComponentV2
struct Child {
  @Param needMonitor: boolean = false;
  @Param count: number = 0;

  onChange(mon: IMonitor) {
    mon.dirty.forEach((path: string) => {
      console.info(`Child needMonitor ${this.needMonitor} onChange: property ${path} change from ${mon.value(path)?.before} to ${mon.value(path)?.now}`);
    });
  }

  aboutToAppear(): void {
    if (this.needMonitor) {
      UIUtils.addMonitor(this, 'count', this.onChange);
    }
  }

  build() {
    Column() {
      Text(`${this.count}`).fontSize(20)
    }
  }
}
```

### Using Paths with Wildcards

Starting from API version 26.0.0, **MonitorOptions** introduces the `enableWildcard` configuration option (default value: **false**). When explicitly set to **true**, **addMonitor** supports the use of wildcard paths. If `enableWildcard` is not set to **true** but a wildcard path is used, the path is considered invalid and the **addMonitor** call does not take effect.

`enableWildcard` takes effect when a listener is created for the function for the first time and cannot be changed thereafter. The check on the `enableWildcard` value occurs when a wildcard is detected in the path. When a listener is created for the first time with `enableWildcard` set to **true**, subsequent paths that do not contain wildcards will not trigger a check on the `enableWildcard` value. Therefore, even if `enableWildcard` is passed as **false** at that point, the **false** value is ignored and the listener is still added. When a listener is created for the first time with `enableWildcard` set to **false**, any subsequent path containing a wildcard is considered invalid regardless of whether `enableWildcard` is passed as **true**, and the **addMonitor** call does not take effect.

The correct way to use wildcards is as follows:

```ts
UIUtils.addMonitor(this, 'obj.*', this.onChange, { enableWildcard: true });
```

The following usage retains the original behavior and does not take effect:

```ts
// enableWildcard is not configured to true, and the path is invalid.
UIUtils.addMonitor(this, 'obj.*', this.onChange);
```

For the rules on using wildcard paths, refer to the description of [listening for paths with wildcards](arkts-new-monitor.md#listening-for-paths-with-wildcards) in the @Monitor documentation.

The following is an example of using **addMonitor** with wildcards to observe object property changes.

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { UIUtils } from '@kit.ArkUI';
@ObservedV2
class ClassA {
  @Trace propA: number = 8;
  @Trace propB: number = 99;

  constructor(a: number, b: number) {
    this.propA = a;
    this.propB = b;
  }
}

@Entry
@ComponentV2
struct MonitorWildcardObject {
  @Local cls: ClassA = new ClassA(100, 100);

  onClsChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onClsChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'cls.*', this.onClsChanged, { enableWildcard: true });
  }

  build() {
    Column() {
      Button(`Change propA: ${this.cls.propA}`)
        .onClick(() => {
          this.cls.propA += 1; // Triggers onClsChanged.
        })
      Button(`Change propB: ${this.cls.propB}`)
        .onClick(() => {
          this.cls.propB += 1; // Triggers onClsChanged.
        })
      Button('Assign new object')
        .onClick(() => {
          this.cls = new ClassA(-200, -200); // Triggers onClsChanged.
        })
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'cls.*'); // Cancel monitoring.
        })
    }
  }
}
```

### Monitoring API Calls on Built-in Type State Variables

Starting from API version 26.0.0, you can monitor API calls on Array, Map, Set, and Date type state variables by configuring wildcards.

**Using Wildcards to Monitor Array Object Changes**

addMonitor with wildcards enabled can monitor Array API calls. When any Array method is called, the callback registered by addMonitor is executed, even if the array is empty or the method does not actually modify the array content. The APIs include `push`, `pop`, `shift`, `splice`, `unshift`, `copyWithin`, `fill`, `reverse`, and `sort`.

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@ObservedV2
class Person {
  @Trace firstName: string = 'first';
  @Trace lastName: string = 'last';
  constructor(first: string = 'no first', last: string = 'no last') {
    this.firstName = first;
    this.lastName = last;
  }
}

@ObservedV2
class ArrayOfPerson extends Array<Person> {}

@ObservedV2
class TopArray extends Array<ArrayOfPerson> {}

@Entry
@ComponentV2
struct DocAddMonitorAPIArrayOfArrays {
  @Local topArray: TopArray = this.makeNewTopArray();

  topArrayMonitor1Star(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray[1]: ${monitor.dirty.toString()}`);
  }

  topArrayMonitorStar(monitor: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `TopArray: ${monitor.dirty.toString()}`);
  }

  makeNewTopArray(): TopArray {
    return new TopArray(
      new ArrayOfPerson(new Person('Adrian'), new Person('Andrew'), new Person('Aaliyah'), new Person('Amir'), new Person('Angel')),
      new ArrayOfPerson(new Person('Carter'), new Person('Charlie'), new Person('Cooper'), new Person('Cole'), new Person('Callie')),
      new ArrayOfPerson(new Person('Daniel'), new Person('Daisy'), new Person('Dawson'), new Person('Dana'), new Person('Dalton'))
    );
  }

  aboutToAppear(): void {
    // Enable wildcard.
    UIUtils.addMonitor(this, 'topArray.1.*', this.topArrayMonitor1Star, { enableWildcard: true });
    UIUtils.addMonitor(this, 'topArray.*', this.topArrayMonitorStar, { enableWildcard: true });
  }

  build() {
    Column() {
      // Both topArrayMonitor1Star and topArrayMonitorStar callbacks are triggered.
      Button('topArray = new TopArray')
        .onClick(() => {
          this.topArray = this.makeNewTopArray();
        })

      // When topArray[1][0] exists, the topArrayMonitor1Star callback is triggered, and the topArrayMonitorStar callback is not triggered.
      Button('topArray[1][0] = new Person')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0) {
            this.topArray[1][0] = new Person();
          }
        })

      // When topArray[0][1] exists, neither the topArrayMonitor1Star nor the topArrayMonitorStar callback is triggered.
      Button('topArray[0][1] = new Person')
        .onClick(() => {
          if (this.topArray.length > 0 && this.topArray[0].length > 1) {
            this.topArray[0][1] = new Person();
          }
        })

      // When topArray[1] exists, the topArrayMonitor1Star callback is triggered, and the topArrayMonitorStar callback is not triggered.
      Button('topArray[1].push')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1] instanceof ArrayOfPerson) {
            this.topArray[1].push(new Person());
          }
        })

      // When the length of topArray is greater than 2, both topArrayMonitor1Star and topArrayMonitorStar callbacks are triggered.
      Button('topArray.shift (length>2)')
        .onClick(() => {
          if (this.topArray.length > 2) {
            this.topArray.shift();
          }
        })

      // When topArray[0] exists, the topArrayMonitor1Star callback is not triggered, and the topArrayMonitorStar callback is triggered.
      Button('topArray[0] = new ArrayOfPerson')
        .onClick(() => {
          if (this.topArray.length > 0) {
            this.topArray[0] = new ArrayOfPerson(new Person(), new Person());
          }
        })

      // When topArray[1][0] exists, neither the topArrayMonitor1Star nor the topArrayMonitorStar callback is triggered.
      Button('topArray[1][0].last update')
        .onClick(() => {
          if (this.topArray.length > 1 && this.topArray[1].length > 0 && this.topArray[1][0] instanceof Person) {
            this.topArray[1][0].lastName += '~';
          }
        })

      // The topArrayMonitor1Star callback is not triggered, and the topArrayMonitorStar callback is triggered.
      Button('topArray = new TopArray, keep [1]')
        .onClick(() => {
          let newTop = this.makeNewTopArray();
          newTop[1] = this.topArray[1]; // topArray.1 is unchanged, and the last determined value before the wildcard in the path 'topArray.1.*' is unchanged.
          this.topArray = newTop;
        })

      // The topArrayMonitor1Star callback is not triggered, and the topArrayMonitorStar callback is triggered.
      Button('topArray.push')
        .onClick(() => {
          this.topArray.push(new ArrayOfPerson(new Person(), new Person()));
        })

      // Cancel monitoring.
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'topArray.1.*');
          UIUtils.clearMonitor(this, 'topArray.*');
        })
    }
  }
}
```

**Using Wildcards to Monitor Date Object Changes**

Wildcards can be used to monitor API calls on Date objects.

```ts
UIUtils.addMonitor(target, 'dateInstance.*', callback, { enableWildcard: true });
```

The listener registered by addMonitor is invoked in the following cases:

- `dateInstance` is assigned a new value.

- Any Date API is called, including `setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, and `setUTCMilliseconds`. The listener callback registered by addMonitor is triggered even if these APIs do not actually change the Date value.

The following is an example of using wildcards to monitor a Date object.

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2 struct DocAddMonitorAPIDate {
  @Local date: Date = new Date();

  onDateChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onDateChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    // Enable wildcard.
    UIUtils.addMonitor(this, 'date.*', this.onDateChanged, { enableWildcard: true });
  }

  build() {
    Column({ space: 5 }) {
      // The API call triggers onDateChanged.
      Button(`date.setMilliseconds(1000)`)
        .onClick(() => {
          this.date.setMilliseconds(1000);
        })
      // The API call triggers onDateChanged.
      Button(`date.setTime(1000000)`)
        .onClick(() => {
          this.date.setTime(1000000);
        })
      // The API call triggers onDateChanged.
      Button(`Assign new Date`)
        .onClick(() => {
          this.date = new Date();
        })
      // Assigning the same value as a whole does not trigger onDateChanged.
      Button(`Re-assign the same Date`)
        .onClick(() => {
          let sameDate = this.date;
          this.date = sameDate;
        })
      // Cancel monitoring.
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'date.*');
        })
    }
  }
}
```

**Using Wildcards to Listening for Map Object Changes**

Wildcards can be used to listen for API calls on **Map** objects.

```ts
UIUtils.addMonitor(target, 'mapInstance.*', callback, { enableWildcard: true });
```

The listener registered by **addMonitor** is invoked in the following cases:

- `mapInstance` is assigned a new value.

- **Map** APIs such as `set`, `delete`, and `clear` are called. Unlike **Array** and **Date**, the callback is triggered only when a change actually occurs. This means that calling `clear` on an empty **Map**, calling `delete` on a non-existent **Map** key, and calling `set` without actually changing the value do not trigger the listener callback registered by **addMonitor**.

Unlike **Array**, **addMonitor** cannot monitor a specific key of a **Map**.

The following is an example of using wildcards to monitor a Map object.

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2
struct DocAddMonitorAPIMap {
  @Local map: Map<string, string> = new Map<string, string>();
  cnt: number = 0;

  onMapSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  onMapChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onMapChanged, dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    UIUtils.addMonitor(this, 'map.size', this.onMapSizeChanged);
    // Enable wildcard.
    UIUtils.addMonitor(this, 'map.*', this.onMapChanged, { enableWildcard: true });
  }

  build() {
    Column({ space: 5 }) {
      Text(`map.size: ${this.map.size}`)
      Text(`map.get('one'): ${this.map.get('one')}`)
      // On the first tap, both onMapSizeChanged and onMapChanged callbacks are triggered.
      Button(`Init, map.set('one', 'A'), map.set('two', 'B')`)
        .onClick(() => {
          this.map.set('one', 'A');
          this.map.set('two', 'B');
        })
      // Both onMapSizeChanged and onMapChanged callbacks are triggered.
      Button(`Add new, map.set('three' + this.cnt, 'C')`)
        .onClick(() => {
          this.cnt++;
          this.map.set('three' + this.cnt, 'C')
        })
      // When 'one' does not exist, neither the onMapSizeChanged nor the onMapChanged callback is triggered.
      // When 'one' exists, both onMapSizeChanged and onMapChanged callbacks are triggered.
      Button(`Delete from map: map.delete('one')`)
        .onClick(() => {
          this.map.delete('one')
        })
      // When the map is not empty, both onMapSizeChanged and onMapChanged callbacks are triggered.
      // When the map is empty, neither the onMapSizeChanged nor the onMapChanged callback is triggered.
      Button(`Clear map`)
        .onClick(() => {
          this.map.clear();
        })
      // On the first tap and assuming ('one' -> 'A') exists, only the onMapChanged callback is triggered.
      // If ('one' -> 'TWO') has already been set, neither the onMapSizeChanged nor the onMapChanged callback is triggered.
      Button(`Update one to 'TWO' - map.set('one', 'TWO')`)
        .onClick(() => {
          this.map.set('one', 'TWO');
        })
      // When 'one' does not exist in the Map, both onMapSizeChanged and onMapChanged callbacks are triggered.
      // When 'one' exists in the Map, neither the onMapSizeChanged nor the onMapChanged callback is triggered.
      Button(`Update one to the same - map.set('one', sameval)`)
        .onClick(() => {
          const sameval = this.map.get('one') ?? 'one' ;
          this.map.set('one', sameval);
        })
      // When 'one' does not exist in the Map, both onMapSizeChanged and onMapChanged callbacks are triggered.
      // When 'one' exists in the Map, only the onMapChanged callback is triggered.
      Button(`Update one to new value - map.set('one', newval)`)
        .onClick(() => {
          let newval = 'x' + (++this.cnt);
          this.map.set('one', newval);
        })
      // When the map is empty, only the onMapChanged callback is triggered.
      // When the map is not empty, both onMapChanged and onMapSizeChanged callbacks are triggered.
      Button(`new map`)
        .onClick(() => {
          this.map = new Map();
        })
      // Cancel monitoring.
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'map.size');
          UIUtils.clearMonitor(this, 'map.*');
        })
    }
    .border({ style: BorderStyle.Solid, width: 2, color: Color.Green })
  }
}
```

**Using Wildcards to Listening for Set Object Changes**

Wildcards can be used to listen for API calls on **Set** objects.

```ts
UIUtils.addMonitor(target, 'setInstance.*', callback, { enableWildcard: true });
```

The listener registered by **addMonitor** is invoked in the following cases:

- `setInstance` is assigned a new value.

- **Set** APIs such as `add`, `delete`, and `clear` are called. Unlike **Array** and **Date**, the callback is triggered only when a change actually occurs. This means that calling `clear` on an empty **Set**, calling `delete` on a non-existent **Set** element, and calling `add` without actually adding a new element do not trigger the listener callback registered by **addMonitor**.

Unlike **Array**, **addMonitor** cannot monitor a specific element of a Set.

The following is an example of using wildcards to monitor a **Set** object.

```ts
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@ComponentV2 struct DocAddMonitorAPISet {
  @Local set: Set<string> = new Set<string>();
  cnt: number = 0;

  onSetChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetChanged, dirty: ${m.dirty.toString()}`);
  }

  onSetSizeChanged(m: IMonitor) {
    hilog.info(0xFF00, 'testTag', '%{public}s', `onSetSizeChanged, size dirty: ${m.dirty.toString()}`);
  }

  aboutToAppear(): void {
    // Enable wildcard.
    UIUtils.addMonitor(this, 'set.*', this.onSetChanged, { enableWildcard: true });
    UIUtils.addMonitor(this, 'set.size', this.onSetSizeChanged);
    this.set.add('one');
    this.set.add('two');
  }

  build() {
    Column({ space: 5 }) {
      // Both onSetChanged and onSetSizeChanged callbacks are triggered.
      Button(`Add three<Num> to the set`)
        .onClick(() => {
          this.cnt++;
          this.set.add('three' + this.cnt);
        })
      // When the element does not exist, neither the onSetChanged nor the onSetSizeChanged callback is triggered.
      // When the element exists, both onSetChanged and onSetSizeChanged callbacks are triggered.
      Button(`Delete 'three<Num>' from the set - set.delete(...)`)
        .onClick(() => {
          this.set.delete('three' + this.cnt);
        })
      // When the set is not empty, both onSetChanged and onSetSizeChanged callbacks are triggered.
      // When the set is empty, neither the onSetChanged nor the onSetSizeChanged callback is triggered.
      Button(`Clear the set - set.clear()`)
        .onClick(() => {
          this.set.clear();
        })
      // When the set is not empty, both onSetChanged and onSetSizeChanged callbacks are triggered.
      // When the set is empty, only the onSetChanged callback is triggered.
      Button(`Assign new set`)
        .onClick(() => {
          this.set = new Set();
        })
      // When the set does not contain 'one', both onSetChanged and onSetSizeChanged callbacks are triggered.
      // When the set contains 'one', neither the onSetChanged nor the onSetSizeChanged callback is triggered.
      Button(`Add 'one' to the set`)
        .onClick(() => {
          this.set.add('one');
        })
      // Cancel monitoring.
      Button('clearMonitor')
        .onClick(() => {
          UIUtils.clearMonitor(this, 'set.*');
          UIUtils.clearMonitor(this, 'set.size');
        })
    }
  }
}
```