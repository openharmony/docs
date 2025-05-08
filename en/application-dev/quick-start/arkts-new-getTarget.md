# getTarget API: Obtaining Original Objects

To obtain the original object before adding a proxy in the state management, you can use the [getTarget](../reference/apis-arkui/js-apis-StateManagement.md#gettarget) API.

Before reading this topic, you are advised to read [\@Observed](./arkts-observed-and-objectlink.md) and [\@ObservedV2](./arkts-new-observedV2-and-trace.md).

>**NOTE**
>
>The **getTarget** API in UIUtils is supported since API version 12.

## Overview

The state management framework adds proxies to original objects of the class, Date, Map, Set, and Array types to observe attribute changes and API invoking. Proxies will change the variable types. In scenarios such as type determination and Node-API invoking, unexpected results may be generated because the variable type is not the type of the original object.

- Import the UIUtils to use the **getTarget** API.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  ```

- In state management V1, a proxy is added to the class objects decorated by @Observed and the class, Date, Map, Set, and Array decorated by @State or other state variable decorators to observe the changes of top-level attributes or changes invoked by APIs.
- In state management V2, a proxy is added to Date, Map, Set, and Array decorated by \@Trace, \@Local or other state variable decorators to observe changes invoked by APIs.

Use **getTarget** to obtain the original objects of these proxy objects.

## Constraints

- Only the parameters of the object type can be passed by **getTarget**.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  let res = UIUtils.getTarget(2); // Incorrect usage. The input parameter is of the non-object type.
  @Observed
  class Info {
    name: string = "Tom";
  }
  let info: Info = new Info();
  let rawInfo: Info = UIUtils.getTarget (info); // Correct usage.
  ```

- Changes to the content in the original object obtained by **getTarget** cannot be observed nor trigger UI re-renders.

  ```ts
  import { UIUtils } from '@kit.ArkUI';
  @Observed
  class Info {
    name: string = "Tom";
  }
  @Entry
  @Component
  struct Index {
    @State info: Info = new Info();
    
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
        Button(`Change the attributes of the proxy object`)
          .onClick(() => {
            this.info.name = "Alice"; // Text component can be re-rendered.
          })
        Button(`Change the attributes of the original object`)
          .onClick(() => {
            let rawInfo: Info = UIUtils.getTarget(this.info);
            The rawInfo.name = "Bob"; // Text component cannot be re-rendered.
          })
      }
    }
  }
  ```

## Use Scenarios

### Obtaining the Original Object Before Adding a Proxy in the State Management V1

State management V1 adds proxies to objects in the following scenarios:

1. \@Observed decorated class instance. When this class instance is created, a proxy is added to the instance. However, objects that are not created by using the **new** operator are not proxied.

```ts
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // Proxied.
let nonObservedClass: NonObservedClass = new NonObservedClass(); // Not proxied.
```

2. Complex object decorated by the state variable decorator. When state variables decorators such as \@State or \@Prop are used to decorate Class, Map, Set, Date, and Array, proxies are added. If the object is already a proxy object, the proxy will not be created again.

```ts
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // Proxied.
let nonObservedClass: NonObservedClass = new NonObservedClass(); // Not proxied.
@Entry
@Component
struct Index {
  @State observedObject: ObservedClass = observedClass; // Proxy will not be created repeatedly for proxied data.
  @State nonObservedObject: NonObservedClass = nonObservedClass; // A proxy is created.
  @State numberList: number[] = [1, 2, 3]; // A proxy is created for the Array type.
  @State sampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // A proxy is created for the Map type.
  @State sampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // A proxy is created for the Set type.
  @State sampleDate: Date = new Date(); // A proxy is created for the Date type.
  
  build() {
    Column() {
      Text(`this.observedObject === observedClass: ${this.observedObject === observedClass}`) // true
      Text(`this.nonObservedObject === nonObservedClass: ${this.nonObservedObject === nonObservedClass}`) // false
    }
  }
}
```

Use **UIUtils.getTarget** to obtain the original objects before proxies are added.

```ts
import { UIUtils } from '@kit.ArkUI';
@Observed
class ObservedClass {
  name: string = "Tom";
}
class NonObservedClass {
  name: string = "Tom";
}
let observedClass: ObservedClass = new ObservedClass(); // Proxied.
let nonObservedClass: NonObservedClass = new NonObservedClass(); // Not proxied.
let globalNumberList: number[] = [1, 2, 3]; // Not proxied.
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // Not proxied.
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // Not proxied.
let globalSampleDate:Date = new Date (); // Not proxied.
@Entry
@Component
struct Index {
  @State observedObject: ObservedClass = observedClass; // Proxy will not be created repeatedly for proxied data.
  @State nonObservedObject: NonObservedClass = nonObservedClass; // A proxy is created.
  @State numberList: number[] = globalNumberList; // A proxy is created for the Array type.
  @State sampleMap: Map<number, string> = globalSampleMap; // A proxy is created for the Map type.
  @State sampleSet: Set<number> = globalSampleSet; // A proxy is created for the Set type.
  @State sampleDate: Date = globalSampleDate; // A proxy is created for the Date type.
  
  build() {
    Column() {
      Text(`this.observedObject === observedClass: ${this.observedObject ===
           observedClass}`) // true
      Text(`UIUtils.getTarget(this.nonObservedObject) === nonObservedClass: ${UIUtils.getTarget(this.nonObservedObject) ===
           nonObservedClass}`) // true
      Text(`UIUtils.getTarget(this.numberList) === globalNumberList: ${UIUtils.getTarget(this.numberList) ===
           globalNumberList}`) // true
      Text(`UIUtils.getTarget(this.sampleMap) === globalSampleMap: ${UIUtils.getTarget(this.sampleMap) ===
           globalSampleMap}`) // true
      Text(`UIUtils.getTarget(this.sampleSet) === globalSampleSet: ${UIUtils.getTarget(this.sampleSet) ===
           globalSampleSet}`) // true
      Text(`UIUtils.getTarget(this.sampleDate) === globalSampleDate: ${UIUtils.getTarget(this.sampleDate) ===
           globalSampleDate}`) // true
    }
  }
}
```

### Obtaining the Original Object Before Adding a Proxy in the State Management V2

A proxy is added to the Map, Set, Date, and Array decorated by \@Trace, \@Local, or other state variable decorators in state management V2. Different from state management V1, the class object instances are not proxied in state management V2.

```ts
@ObservedV2
class ObservedClass {
  @Trace name: string = "Tom";
}
let globalObservedObject: ObservedClass = new ObservedClass(); // Not proxied.
let globalNumberList: number[] = [1, 2, 3]; // Not proxied.
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // Not proxied.
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // Not proxied.
let globalSampleDate:Date = new Date (); // Not proxied.
@Entry
@ComponentV2
struct Index {
  @Local observedObject: ObservedClass = globalObservedObject; // Objects in V2 are not proxied.
  @Local numberList: number[] = globalNumberList; // A proxy is created for the Array type.
  @Local sampleMap: Map<number, string> = globalSampleMap; // A proxy is created for the Map type.
  @Local sampleSet: Set<number> = globalSampleSet; // A proxy is created for the Set type.
  @Local sampleDate: Date = globalSampleDate; // A proxy is created for the Date type.
  
  build() {
    Column() {
      Text(`this.observedObject === globalObservedObject ${this.observedObject === globalObservedObject}`) // true
      Text(`this.numberList === globalNumberList ${this.numberList === globalNumberList}`) // false
    }
  }
}
```

Use **UIUtils.getTarget** to obtain the original objects before proxies are added.

```ts
import { UIUtils } from '@kit.ArkUI';
@ObservedV2
class ObservedClass {
  @Trace name: string = "Tom";
}
let globalObservedObject: ObservedClass = new ObservedClass(); // Not proxied.
let globalNumberList: number[] = [1, 2, 3]; // Not proxied.
let globalSampleMap: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]]); // Not proxied.
let globalSampleSet: Set<number> = new Set([0, 1, 2, 3, 4]); // Not proxied.
let globalSampleDate:Date = new Date (); // Not proxied.
@Entry
@ComponentV2
struct Index {
  @Local observedObject: ObservedClass = globalObservedObject; // Objects in V2 are not proxied.
  @Local numberList: number[] = globalNumberList; // A proxy is created for the Array type.
  @Local sampleMap: Map<number, string> = globalSampleMap; // A proxy is created for the Map type.
  @Local sampleSet: Set<number> = globalSampleSet; // A proxy is created for the Set type.
  @Local sampleDate: Date = globalSampleDate; // A proxy is created for the Date type.
  
  build() {
    Column() {
      Text(`this.observedObject === globalObservedObject ${this.observedObject ===
           globalObservedObject}`) // true
      Text(`UIUtils.getTarget(this.numberList) === globalNumberList: ${UIUtils.getTarget(this.numberList) ===
           globalNumberList}`) // true
      Text(`UIUtils.getTarget(this.sampleMap) === globalSampleMAP: ${UIUtils.getTarget(this.sampleMap) ===
           globalSampleMap}`) // true
      Text(`UIUtils.getTarget(this.sampleSet) === globalSampleSet: ${UIUtils.getTarget(this.sampleSet) ===
           globalSampleSet}`) // true
      Text(`UIUtils.getTarget(this.sampleDate) === globalSampleDate: ${UIUtils.getTarget(this.sampleDate) ===
           globalSampleDate}`) // true
    }
  }
}
```

Decorators in state management V2 generate the **getter** and **setter** methods for the decorated variables and add prefix **\_\_ob\_** in the original variable names. To ensure performance, the **getTarget** API does not process the prefix generated by the decorators in V2. Therefore, when the \@ObservedV2 decorated class object instance is passed in through **getTarget** API, the returned object is still the object itself and the attribute name decorated by \@Trace still has the prefix **\_\_ob\_**.

Some Node-APIs fail to process object attributes as expected due to this prefix.<br>Example:<br>Affected Node-APIs are as below.

```ts
// Class decorated by @ObservedV2.
@ObservedV2
class Info {
  @Trace name: string = "Tom";
  @Trace age: number = 24;
}
let info: Info = new Info(); // info instance passed in through Node-APIs.
```

| Name             | Result                                      |
| ----------------------- | ---------------------------------------------- |
| napi_get_property_names | Returns value that is **\_\_ob\_name** or **\_\_ob\_age**.       |
| napi_set_property       | Changes values successfully using **name** or **\_\_ob\_name**.      |
| napi_get_property       | Obtains values using **name** or **\_\_ob\_name**.      |
| napi_has_property       | Returns **true** using **name** or **\_\_ob\_name**.        |
| napi_delete_property    | Deletes an attribute successfully adding the prefix **\_\_ob\_**.|
| napi_has_own_property   | Returns **true** using **name** or **\_\_ob\_name**.        |
| napi_set_named_property | Changes values successfully using **name** or **\_\_ob\_name**.      |
| napi_get_named_property | Obtains values using **name** or **\_\_ob\_name**.      |
| napi_has_named_property | Returns **true** using **name** or **\_\_ob\_name**.        |
