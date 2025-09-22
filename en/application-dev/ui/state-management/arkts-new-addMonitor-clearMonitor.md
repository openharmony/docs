# addMonitor and clearMonitor APIs: Dynamically Adding and Removing Listeners
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The [addMonitor](../../reference/apis-arkui/js-apis-StateManagement.md) and [clearMonitor](../../reference/apis-arkui/js-apis-StateManagement.md) APIs in **UIUtils** enable you to dynamically add or remove listeners for state variables in state management V2.

Before using these APIs, it is recommended that you familiarize yourself with the following concepts: [\@ObservedV2/\@Trace](./arkts-new-observedV2-and-trace.md) and [\@Monitor](./arkts-new-monitor.md).

>**NOTE**
>
>These APIs are available since API version 20.


## Overview
The [\@Monitor](./arkts-new-monitor.md) decorator, when declared within an [\@ObservedV2](./arkts-new-observedV2-and-trace.md) or [\@ComponentV2](./arkts-new-componentV2.md) decorated class, automatically applies the same listener callback to all instances of that class. These \@Monitor decorated callbacks are static and cannot be removed.

For scenarios requiring dynamic management of listeners, use the [addMonitor](../../reference/apis-arkui/js-apis-StateManagement.md) and [clearMonitor](../../reference/apis-arkui/js-apis-StateManagement.md) APIs to add or remove listeners on individual \@ObservedV2 and \@ComponentV2 instances.

- To use **addMonitor** and **clearMonitor**, you must import the **UIUtils** utility.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```
- These APIs only support state variables from state management V2.

- The **clearMonitor** API can only remove listeners added dynamically via **addMonitor**; it cannot remove static callbacks defined using the \@Monitor decorator.

## Usage Rules
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
    // fails with this log: FIX THIS APPLICATION ERROR: AddMonitor onChange1 failed when adding path age because duplicate key.
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
- The [isSynchronous](../../reference/apis-arkui/js-apis-StateManagement.md) configuration option for a listener is established during its initial registration and becomes immutable thereafter. Any subsequent attempt to modify it for the same listener will fail and produce an error log.
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
    // Correct usage: Register the onChange1 listener with the default synchronization mode configuration.
    UIUtils.addMonitor(this, 'age', this.onChange1);
    // Error: Attempting to modify the synchronization mode after initial registration
    // fails with this log: FIX THIS APPLICATION ERROR: addMonitor failed, current function onChange1 has already register as async, cannot change to sync anymore.
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
Note: A warning log is generated if the specified listener is not registered for the given path, or if the path has no registered listeners.
Once the listener is removed, state changes no longer invoke the corresponding callback.
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
        // Print the error log FIX THIS APPLICATION ERROR: cannot clear path name for current target User because no Monitor function for this path was registered.
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
  // Correct usage: equivalent to omitting the listener parameter, removing all listeners for b.
  UIUtils.clearMonitor(a, 'a', undefined);
  // Error: Anonymous functions are not supported (error code: 130002).
  UIUtils.clearMonitor(a, 'a', (mon: IMonitor) => {});
  ```

## Rules for Listening for Changes with addMonitor
The rules for listening for changes with **addMonitor** and the [\@Monitor](./arkts-new-monitor.md) decorator are largely consistent. The comparison is shown in the table below.

|  Scenario| addMonitor| @Monitor  |
|------|----|------|
| [Listening for @Trace decorated properties in \@ObservedV2 classes](#listening-for-trace-decorated-properties-in-observedv2-classes-and-state-variables-in-componentv2-components)   | Supported| Supported|
| [Listening for state variables in \@ComponentV2 components](#listening-for-trace-decorated-properties-in-observedv2-classes-and-state-variables-in-componentv2-components) | Supported| Supported|
| [Listening for index and length changes of array-type state variables](#listening-for-index-and-length-changes-of-array-type-state-variables) | Supported| Supported|
| Listening for changes of state variables of the Map, Set, and Date types | Not supported| Not supported|
| [Listening for paths independently](#listening-for-paths-independently) | Supported| Not supported|
| [Listening for variable accessibility changes](#listening-for-variable-accessibility-changes) | Supported| Not supported|
| [Configuring synchronous listeners](#configuring-synchronous-listeners) | Supported| Not supported|
| [Listening for synchronous state variable changes in constructors](#listening-for-synchronous-state-variable-changes-in-constructors)  | Supported| Not supported|
| [Dynamically Canceling Listening of \@ObservedV2/\@ComponentV2 Instances](#dynamically-canceling-listening-of-observedv2componentv2-instances)  | Supported| Not supported|

## Application scenarios
### Listening for @Trace Decorated Properties in \@ObservedV2 Classes and State Variables in \@ComponentV2 Components

In the following example:
- A **onChange** listener is added for **age** and **name** in the constructor of **User**.
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
        // Push new item d to the end of the array (index 4, for which no listener is added).
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
```
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
[\@Monitor](./arkts-new-monitor.md#Unable to listen to variables that are accessible and inaccessible
preventing listening for accessibility transitions.
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
```
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
```
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
```
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
