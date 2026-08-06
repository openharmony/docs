# Mixing Use of Custom Components
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

State management V1 (V1 for short) provides a series of state variable decorators (V1 decorators for short), such as @State, @Prop, and @Link, which can be used in custom components decorated with @Component (V1 custom components for short).

However, V1 has many restrictions on the observation of nested classes. For example, you need to use \@ObjectLink to break down nested classes so that deep data can be observed.

Therefore, API version 12 provides you with a new set of state management V2 (V2 for short). You can declare custom components decorated by \@ComponentV2 (V2 custom components for short) and use them with a new set of decorators (V2 decorators for short). For example, \@Local and \@Param.

The proposal of V2 not only solves the disadvantage of V1 in observing nested classes, but also enhances the functions of some decorators. For example, the \@Monitor of V2 can not only sense the changed data, but also obtain the data before the change.

In terms of design, the code of V1 and V2 are expected to be completely isolated because V2 can do better than V1 in certain scenarios. However, from the actual perspective, the code developed in V1 have a solid foundation and it is not practical to migrate the entire code to V2 at a time. Therefore, it is allowed to use some capabilities of V2 in the code of V1 and capabilities of V1 is not completely prohibited in V2. For example, a custom component of V1 uses a custom component of V2, or V1 uses a decorator of V2. In this way, a problem of mixed use of V1 and V2 occurs.

This guide describes the scenario where V1 and V2 are used together to help developers migrate V1 code to V2.

> **NOTE**
>
> State management V2 is supported since API version 12.
> The rules for mixed use described in this topic apply only to API version 18 and earlier. Since API version 19, to help you migrate your application from V1 to V2 more easily, state management provides new APIs [enableV2Compatibility](../../reference/apis-arkui/js-apis-stateManagement.md#enablev2compatibility19) and [makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19). For details, see [Mixing Use of State Management V1 and V2](./arkts-v1-v2-mixusage.md).

## **Overview**

The rules for mixed use of V1 and V2 state management are as follows:

* The decorators of V2 cannot be used in the custom components of V1. Otherwise, an error is reported during compilation.

* If no variable is transferred between components, the custom components of V2 can be used in the custom components of V1, including the custom components decorated by the third-party \@ComponentV2.

* When variables are passed between components, such as passing variables of V1 to the custom components of V2, constraints are as follows:
  - Variables that are not decorated by decorators in V1 (common variables) can be received only by using \@Param in V2.
  - Variables decorated by the decorator in V1 (state variables) can be received only by using \@Param in V2 and are limited to simple data types such as boolean, number, enum, string, undefined and null.

* The decorators of V1 cannot be used in the custom components of V2. Otherwise, an error is reported during compilation.

* When no variable is passed between components, custom components of V2 can use custom components of V1 as well as import \@Component decorated custom components of a third party.

* When variables are passed between components, such as passing variables of V2 to the custom components of V1, constraints are as follows:
  - The V2 common variable (not using the state variable decorator) is transferred to the V1 custom component.

    If V1 uses state variables to receive the data, only the following V1 state variable decorators can be used: [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), and [\@Provide](./arkts-provide-and-consume.md).

  - The V2 state variable (using the state variable decorator) is transferred to the V1 custom component.

    If V1 uses a state variable decorator (also supported only by \@State, \@Prop, and \@Provide) to decorate received data, built-in data such as Array, Set, Map, and Date is not supported. Note that the V2 state variable supports the function type, but the V1 state variable decorator does not support the function type. If the function type is transferred, verification will be performed during runtime. Take \@State as an example. For details, see [\@State Constraints](./arkts-state.md#constraints).

  - [\@Link](./arkts-link.md) in V1 complies with the original initialization rules and can be initialized only by V1 state variables. For details, see [\@Link Initialization Rules](./arkts-link.md#variable-transferaccess-rules).

## State Management Decorator Overview

### Decorators of V1

|  Type |                            Decorator                           |
| :----------: | :----------------------------------------------------------: |
| Intra-component decorator| [\@State](./arkts-state.md), [\@Prop](./arkts-prop.md), [\@Link](./arkts-link.md), [\@ObjectLink](./arkts-observed-and-objectlink.md), [\@Provide](./arkts-provide-and-consume.md), [\@Consume](./arkts-provide-and-consume.md), [\@StorageProp](./arkts-appstorage.md), [\@StorageLink](./arkts-appstorage.md), [\@LocalStorageProp](./arkts-localstorage.md), [\@LocalStorageLink](./arkts-localstorage.md), [\@Watch](./arkts-watch.md)|
| Class-related decorator|                     \@Observed, \@Track                     |

### Decorators of V2

|  Type |                            Decorator                           |
| :----------: | :----------------------------------------------------------: |
| Intra-component decorator| [\@Local](./arkts-new-local.md), [\@Param](./arkts-new-param.md), [\@Provider](./arkts-new-provider-and-consumer.md), [\@Consumer](./arkts-new-provider-and-consumer.md), [\@Once](./arkts-new-once.md), [\@Event](./arkts-new-event.md), [\@Monitor](./arkts-new-monitor.md), [\@Computed](./arkts-new-computed.md)|
| Class-related decorator|                [\@ObservedV2](./arkts-new-observedV2-and-trace.md), [\@Trace](./arkts-new-observedV2-and-trace.md), [\@Type](./arkts-new-type.md)                |

### Data Types Supported by State Management Decorators

State management supports the following data types:

| Data Type    | Keyword                                            |
| ------------ | -------------------------------------------------- |
| Simple type| boolean, number, enum, string, null, undefined    |
| Function type| function (supported only by \@Event, \@Monitor, and \@Computed of V2)|
| Object type  | Object                                             |
| Class type   | Class                                              |
| Built-in type    | Array, Map, Set, Date                             |



## Constraints

### Mixing Use of Decorators of V1 and V2 Is Forbidden

**1. The decorators of V2 cannot be used in the custom components of V1.**

```typescript
@Component
struct Child {
  // @Param cannot be used in @Component. Otherwise, an error is reported during compilation.
  // @Once and @Require are capability extension decorators of @Param and must be used together with @Param.
  @Param message: string = "";                 
  @Event changeMessage: (val: string) => void;  // @Event cannot be used in @Component. Otherwise, an error is reported during compilation.

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.changeMessage('world hello');
        })
    }
  }
}

@Entry
@Component
struct Index {
  @Local message: string ='Hello World'; // @Local cannot be used in @Component. Otherwise, an error is reported during compilation.

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Divider()
        .color(Color.Blue)
      Child({
        message: this.message,
        changeMessage: (val: string) => {
          this.message = val;
        }
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

The intra-component decorators in V2 cannot be used in the custom components of V1. Otherwise, an error is reported during compilation.

The sample code shows how \@Local, \@Param, \@Event, \@Provider, \@Consumer, \@Monitor and \@Computed decorators work.

**2. The decorators of V1 cannot be used in the custom components of V2.**

```typescript
@ComponentV2
struct Child {
  @Prop message: string = "";   // @Prop cannot be used in @ComponentV2. Otherwise, an error is reported during compilation.
  @Link myId: number;           // @Link cannot be used in @ComponentV2. Otherwise, an error is reported during compilation.

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Text(`${this.myId}`)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.myId++;
        })
    }
  }
}

@Entry
@ComponentV2
struct Index {
  @State message: string = 'Hello World';      // @State cannot be used in @ComponentV2. Otherwise, an error is reported during compilation.
  @State @Watch('idChange') myId: number = 1;  // @Watch cannot be used in @ComponentV2. Otherwise, an error is reported during compilation.

  idChange(propName: number) : void {
    console.info(`id changed ${this.myId}`);
  }

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Divider()
        .color(Color.Blue)
      Child({
        message: this.message,
        myId: this.myId
      })
    }
    .height('100%')
    .width('100%')
    .margin(5)
  }
}
```

The intra-component decorators in V1 cannot be used in the custom components of V2. Otherwise, an error is reported during compilation.

The sample code shows how \@ObjectLink, \@Provide, \@Consume, \@StorageProp, \@StorageLink, \@LocalStorageProp, and \@LocalStorageLink decorators work.

### Using Multiple Decorators to Decorate the Same Variable Is Forbidden (Except \@Watch, \@Once, and \@Require)

```typescript
@Component
struct Child {
  @State @Prop message: string = "";  // Multiple decorators of V1 cannot decorate the same variable. Otherwise, an error is reported during compilation.

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
    }
  }
}

@Entry
@ComponentV2
struct Index {
  @Local @Param message: string = 'Hello World'; // Multiple decorators of V2 cannot decorate the same variable. Otherwise, an error is reported during compilation.

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
      Divider()
        .color(Color.Blue)
      Child({
        message: this.message
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

All decorators cannot decorate the same variable except extended decorators \@Watch, \@Once, and \@Require that can be used with other decorators.

## Introduction to Mixed Use  

### Mixing Use of Decorators of V1 and V2

1. Use the class object decorated by \@ObservedV2 in the customized component of V1.

```typescript
@ObservedV2
class Info {
  @Trace myId: number;     // Observable.
  name: string;             // Not observable.
  @Track trackId: number = 1;   // As a decorator of V1, @Track cannot be used in @ObservedV2. Otherwise, an error is reported during compilation. Remove @Track to eliminate the error.
  
  constructor(id?: number, name?: string) {
    this.myId = id || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class message extends Info {  // Classes inherited from @ObservedV2 cannot be decorated by Observed. Otherwise, an error is reported during compilation. Remove @Observed to eliminate the error.
}

class MessageInfo extends Info {
}

@Entry
@Component
struct Index {
  info1: Info = new Info();                      // @ObservedV2 decorated class can be used in V1, and @Trace decorated class is observable.
  @State info2: Info = new Info();               // @ObservedV2 decorated class cannot be decorated by the decorator of V1. Otherwise, an error is reported during compilation. Remove @State to eliminate the error.

  @State messageInfo: MessageInfo = new MessageInfo();  // Classes inherited from @ObservedV2 cannot be decorated by the decorator of V1. Otherwise, an error is reported during runtime. Remove @State to eliminate the error.
  build() {
    Column() {
      Text(`info1 name: ${this.info1.name}`)            // name is not decorated by @Trace and is not observable.
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.name += 'b';
        })
      Text(`info1 id: ${this.info1.myId}`)              // myId is decorated by @Trace and is observable.
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`info2 id: ${this.info2.myId}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info2.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfo id: ${this.messageInfo.myId}`) // A crash occurs during runtime when the class inherited from @ObservedV2 is decorated by the decorators of V1. Remove @State to eliminate the error.
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.messageInfo.myId += 1;
        })
    }
    .height('100%')
    .width('100%')
    .margin(5)
  }
}
```

Using \@ObservedV2 must comply with the following rules:

* \@ObservedV2 can decorate only Class; \@Trace and \@Type can decorate only class properties and can be used only in \@ObservedV2.
* \@Track cannot be used in \@ObservedV2.
* A class decorated by \@ObservedV2 cannot be directly decorated by the decorator of V1. Otherwise, an error is reported during compilation.
* In the example, the code can be executed properly after you remove the decorator that reports error. The property change can be observed only when the class is decorated by \@Trace.

**2. Use the \@Observed decorated class object in a custom component of V2.**

```typescript
@Observed
class Info {
  @Track myId: number;       // Not observable. Only associated update caused by other property changes can be prevented.
  name: string;                 // Not observable.
  @Trace trackId: number = 1;     // As a decorator of V2, @Trace cannot be used in @Observed. Otherwise, an error is reported during compilation. Remove @Trace to eliminate the error.
  constructor(id?: number, name?: string) {
    this.myId = id || 0;
    this.name = name || 'aaa';
  }
}

@ObservedV2
class message extends Info {      // @ObservedV2 decorated class cannot inherit from @Observed. Otherwise, an error is reported during compilation. Remove @ObservedV2 to eliminate the error.
}

class MessageInfo extends Info {  
}

@Entry
@ComponentV2
struct Index {
  info1: Info = new Info();             // @Observed decorated class can be used in V2.
  @Local info2: Info = new Info();      // @Observe decorated class cannot be decorated by the decorator of V2. Otherwise, an error is reported during compilation. Remove @Local to eliminate the error.
  @Local messageInfo: MessageInfo = new MessageInfo(); 
  build() {
    Column() {
      Text(`info1 name: ${this.info1.name}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.name += 'b';
        })
      Text(`info1 id: ${this.info1.myId}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`info2 id: ${this.info2.myId}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info2.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      // Classes inherited from @ObservedV2 are decorated by the decorator of V2, but the class properties cannot be observed by the decorator of V2. Therefore, you are not advised to use the @Observed decorated classes in V2.
      Text(`messageInfo id: ${this.messageInfo.myId}`)   
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.messageInfo.myId += 1;
        })
    }
    .height('100%')
    .width('100%')
    .margin(5)
  }
}
```

You are not advised to use \@Observed decorated classes in V2 because \@Observed and \@Track decorated class properties can only be distinguished but not be observed. In-depth data can be observed only when \@Observed and \@ObjectLink are used to split nested data. However, \@ObjectLink cannot be used in custom components of V2.

When migrating code from V1 to V2, you are not advised to use \@Observed decorated classes in \@ComponentV2 because they are not observable. If this function must be used, comply with the following rules:

* \@Observed can only decorate class, and \@Trace cannot be used in \@Observed.
* \@Observed and \@Track decorated classes are not observable and you can use the decorators only to prevent the entire class from being refreshed when a class property is changed.
* Classes inherited from @Observed are decorated by the decorator of V2, but the class properties cannot be observed the intra-component decorator of V2. Therefore, class property changes cannot be observed using \@Observed.
* In the example, the code can be executed properly after you remove the decorator that reports error. Because the observation capability is unavailable, you are not advised to use \@Observed in V2.

### Mixing Use of Custom Components of V1 and V2 When No Variable Is Passed

**1. Use the custom components of V2 in V1.**

<!-- @[v1_use_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V2InV1.ets) -->

``` TypeScript
@ComponentV2
struct Child6 {
  @Local message: string = 'hello';

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
    }
  }
}

@Entry
@Component
struct Index6 {
  @State message: string = 'Hello World';

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Child6()
    }
    .height('100%')
    .width('100%')
  }
}
```

When V2 custom components are used in V1, if no variable passing is involved, there will be no impact. If variable passing is involved, follow the instructions in [Mixing Use of State Management V1 and V2](arkts-v1-v2-mixusage.md).

**2. Use the custom components of V1 in V2.**

<!-- @[v2_use_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V1InV2.ets) -->

``` TypeScript
@Component
struct Child3 {
  @State message: string = 'hello';

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
    }
  }
}

@Entry
@ComponentV2
struct Index3 {
  @Local message: string = 'Hello World';

  build() {
    Column() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Child3()
    }
    .height('100%')
    .width('100%')
  }
}
```

When V1 custom components are used in V2, if no variable passing is involved, there will be no impact. If variable passing is involved, follow the instructions in [Mixing Use of State Management V1 and V2](arkts-v1-v2-mixusage.md).

### Mixing Use of Custom Components of V1 and V2 When Variables Are Passed

**1. V1 > V2: Pass the common variables of V1 to the custom component of V2.**

<!-- @[v1_to_v2_common_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V1CommonVariablesToV2CustomComponent.ets) -->

``` TypeScript
class Info2 {
  public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@ComponentV2
struct Child2 {
  // V2 strictly manages data input. When receiving data from the parent component, the @Param decorator must be used to receive data.
  @Param @Once message: string = 'hello';                  // Changes are observable and can be synchronized to the parent component through @Event. @Once can be used to change @Param decorated variables.
  @Param @Once undefinedVal: string | undefined = undefined;  // @Once can be used to change @Param decorated variables.
  @Param info: Info2 = new Info2();                         // The class attribute changes cannot be observed.
  @Require @Param set: Set<number>;

  build() {
    Column() {
      Text(`child message:${this.message}`) // Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })

      Divider()
        .color(Color.Blue)
      Text(`undefinedVal:${this.undefinedVal}`) // Display undefinedVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefinedVal = 'change to define';
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`) // Display info:myId.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => {  // Display set.
        Text(`${item}`)
          .fontSize(30)
      })
    }
    .margin(5)
  }
}

@Entry
@Component
struct Index2 {
  message: string = 'Hello World';       // Simple type.
  undefinedVal: undefined = undefined;    // Simple type, undefined
  info: Info2 = new Info2();               // Class type
  set: Set<number> = new Set([10, 20]);  // Built-in type.

  build() {
    Column() {
      Text(`message:${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Child2({
        message: this.message,
        undefinedVal: this.undefinedVal,
        info: this.info,
        set: this.set
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

When the common variables of V1 are passed to a custom component of V2, constraints are as follows:

* The custom component of V2 must receive data through \@Param.
* To observe the received data changes, use \@Param; to observe the received class changes, use \@ObservedV2 and \@Trace.

**2. V1 > V2: Pass the state variables of V1 to the custom component of V2.**

<!-- @[v1_to_v2_state_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V1StateVariablesToV2CustomComponent.ets) -->

``` TypeScript
class Info4 {
  public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@ComponentV2
struct Child4 {
  // V2 strictly manages data input. When receiving data from the parent component, the @Param decorator must be used to receive data.
  @Param @Once message: string = 'hello';
  @Param @Once undefinedVal: string | undefined = undefined;  // @Once can be used to change @Param decorated variables.
  @Param info: Info4 = new Info4();
  @Require @Param set: Set<number>;
  build() {
    Column() {
      Text(`child message:${this.message}`) // Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefinedVal:${this.undefinedVal}`) // Display undefinedVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefinedVal = 'change to define';
        })
      Divider()
        .color(Color.Blue)
      Text('info id:${this.info.myId}') // Display info:myId.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => { // Display set.
        Text(`${item}`)
          .fontSize(30)
      })
    }
    .margin(5)
  }
}

@Entry
@Component
struct Index4 {
  @State message: string = 'Hello World';       // Simple type data can be passed.
  @State undefinedVal: undefined = undefined;    // Simple type data, undefined, can be passed.
  @State info: Info4 = new Info4();               // Class type cannot be passed. Otherwise, an error is reported during compilation. Remove @State to eliminate the error.
  @State set: Set<number> = new Set([10, 20]);  // Built-in type cannot be passed. Otherwise, an error is reported during compilation. Remove @State to eliminate the error.

  build() {
    Column() {
      Text(`message:${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Child4({
        message: this.message,
        undefinedVal: this.undefinedVal,
        info: this.info,
        set: this.set
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

When the state variable of V1 is passed to the custom component of V2, the following rules are followed:

* Only simple variables are supported. For other types of data, an error is reported during compilation.

* In the example, the \@State decorator is used. Other decorators such as \@Prop, \@Link, \@ObjectLink, \@Provide, \@Consume, \@StorageProp, \@StorageLink, \@LocalStorageProp and \@LocalStorageLink work in the same way as \@State.

**3. V2 > V1: Pass the common variables of V2 to the custom component of V1.**

<!-- @[v2_to_v1_common_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V2CommonVariablesToV1CustomComponent.ets) -->

``` TypeScript
class Info5 {
  public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Component
struct Child5 {
  // State variable received by V1 from V2. Only @State, @Prop, and @Provide decorators can be used.
  @State  message: string = 'hello';             // Changes are observable.
  @State info: Info5 = new Info5();                  // Top-level class property changes are observable.
  @Prop undefinedVal: undefined | string = undefined;
  @Provide setMap: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`)     // Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefinedVal:${this.undefinedVal}`)     // Display undefinedVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefinedVal = 'change to define';
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`)             // Display info:myId.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.setMap.values()), (item: number) => {  // Display set.
        Text(`${item}`)
          .fontSize(30)
      })
    }
    .margin(5)
  }
}

@Entry
@ComponentV2
struct Index5 {
  message: string = 'Hello World';       // Simple type.
  undefinedVal: undefined = undefined;    // Simple type: undefined.
  info: Info5 = new Info5();               // Class type
  set: Set<number> = new Set([10, 20]);  // Built-in type.

  build() {
    Column() {
      Text(`message:${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })
      Divider()
        .color(Color.Blue)
      Child5({
        message: this.message,
        undefinedVal: this.undefinedVal,
        info: this.info,
        setMap: this.set
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

When a common variable of V2 is passed to a custom component of V1:

* V1 can receive data without using the decorator. The received variables are common variables in the V1 custom component.

* When V1 uses a decorator to receive data, data can be received only through \@State, \@Prop, and \@Provide.

**4. V2 > V1: Pass the state variables of V2 to the custom component of V1.**

<!-- @[v2_to_v1_state_variables](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/V2StateVariablesToV1CustomComponent.ets) -->

``` TypeScript
class Info7 {
  public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Component
struct Child7 {
  // State variable received by V1 from V2. Only @State, @Prop, and @Provide can be used.
  @State  message: string = 'hello';            // Changes are observable.
  @State info: Info7 = new Info7();                // Top-level class property changes are observable.
  @Prop undefinedVal: undefined | string = undefined;
  @Provide set: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`)     // Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefinedVal:${this.undefinedVal}`)     // Display undefinedVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefinedVal = 'change to define';
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`)     // Display info:myId.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })

      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => {  // Display set.
        Text(`${item}`)
          .fontSize(30)
      })
    }
    .margin(5)
  }
}

@Entry
@ComponentV2
struct Index7 {
  @Local message: string = 'Hello World';           // Simple type data can be passed.
  @Provider() undefinedVal: undefined = undefined;   // Simple type data, undefined, can be passed.
  @Consumer() info: Info7 = new Info7();              // Class type can be passed.
  @Param set: Set<number> = new Set([10, 20]);      // Built-in type cannot be passed. Otherwise, an error is reported during compilation. Remove @Param to eliminate the error.

  build() {
    Column() {
      Text(`message:${this.message}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world hello';
        })

      Divider()
        .color(Color.Blue)
      Child7({
        message: this.message,
        undefinedVal: this.undefinedVal,
        info: this.info,
        set: this.set
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

When the state variables of V2 are passed to a custom component of V1, constraints are as follows:

* V1 can receive data without using the decorator. The received variables are also common variables in the custom component of V1.
* When V1 uses a decorator to receive data, data can be received only through \@State, \@Prop, and \@Provide.
* When V1 uses a decorator to receive data, data of the built-in type is not supported.

### Summary

Based on the analysis of the scenario where V1 and V2 are used together, the following conclusions are drawn:

1. When the code of V2 is mixed with the code of V1 (that is, the component or class data of V1 is transferred to V2), most capabilities of V1 are disabled in V2.

2. When the code of V1 is mixed with the code of V2 (that is, the component or class data of V2 is transferred to V1), some functions are opened. For example, \@ObservedV2 and \@Trace are the most helpful for observing V1 nested data.

Therefore, during code development, you are not advised to use V1 and V2 together for mixed development. However, you can gradually migrate the code of V1 to V2 to steadily replace the function code of V1. In addition, you are not advised to use the code of V1 in V2.

## Supplementary Scenarios

Classes can be nested at multiple levels because they are decorated by \@Observed and \@ObservedV2, leading to a complex scenario. This section mainly describes the self-nesting of the class type and the nesting of the built-in type. Lack of in-depth observation capability like \@ObservedV2 and @Trace, the in-depth nesting of \@Observed is not discussed. Only the use scenarios of \@ObservedV2 in V1 are discussed.

### Using \@Observed and \@ObjectLink to Observe Nested Classes

<!-- @[obseved_object_link](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/ObserveNestedClasses_ObservedAndObjectLink.ets) -->

``` TypeScript
@Observed
class Info1 {
  public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class MessageInfo1 {         // One-layer nesting
  @Track public info: Info1;        // Prevent the info from being updated due to the change of messageId.
  @Track public messageId: number; // Prevent the info from being updated when the messageId is changed.

  constructor(info?: Info1, messageId?: number) {
    this.info = info || new Info1();
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested1 {     // Dual-level nesting.
  public messageInfo: MessageInfo1;

  constructor(messageInfo?: MessageInfo1) {
    this.messageInfo = messageInfo || new MessageInfo1();
  }
}

@Component
struct GrandSon1 {
  @ObjectLink info1: Info1;

  build() {
    Column() {
      Text(`ObjectLink info info.myId:${this.info1.myId}`)  // After @ObjectLink disassembles the level twice, the change is observable.
        .fontSize(30)
        .onClick(() => {
          this.info1.myId++;
        })
    }
  }
}

@Component
struct Child1 {
  @ObjectLink messageInfo: MessageInfo1;

  build() {
    Column() {
      Text(`ObjectLink MessageInfo messageId:${this.messageInfo.messageId}`)  // After @ObjectLink disassembles the levels, the change of the top-level class property is observable.
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      Text(`ObjectLink MessageInfo info.myId:${this.messageInfo.info.myId}`)  // After @ObjectLink disassembles the level, the change is not observable.
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.info.myId++;
        })
      GrandSon1({info1: this.messageInfo.info});                // Continue to split a layer of subcomponents.
    }
  }
}

@Entry
@Component
struct Index1 {
  @State messageInfoNested: MessageInfoNested1 = new MessageInfoNested1();  // For the data nested at three levels, you need to observe all data.

  build() {
    Column() {
      // Observe messageInfoNested.
      Text(`messageInfoNested messageId:${this.messageInfoNested.messageInfo.messageId}`)  // @State can only observe the top-level class properties but not their changes.
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      // Observe messageInfoId through @ObjectLink.
      Child1({messageInfo: this.messageInfoNested.messageInfo})      // After disassembling, you can use @ObjectLink to observe the lower-level changes.
      Divider()
        .color(Color.Blue)
    }
    .height('100%')
    .width('100%')
    .margin(10)
  }
}
```

The preceding example is a three-layer nesting scenario, which indicates that:

* The observation capability of the decorator of V1 is to function as a proxy for data. Therefore, when data is nested, the decorator of V1 can only disassemble the child component to observe lower-level data through \@Observed and \@ObjectLink.

* \@Track can prevent the **info** in the **MessageInfo** class from being updated when the **messageId** is changed. You can remove \@Track to observe the change. When the **messageId** is changed, the **info** is also changed. However, this change cannot be observed by \@ObjectLink.

### Using @ObsevedV2 and @Trace to Observe Nested Classes

<!-- @[obseved_trace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/CustomComponentsMixingUse/entry/src/main/ets/pages/MixingUseofCustomComponents/ObserveNestedClasses_ObsevedV2AndTrace.ets) -->

``` TypeScript
@ObservedV2
class Info {
  @Trace public myId: number;
  public name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class MessageInfo { // One-level nesting.
  @Track public info: Info;        // Prevent the info from being updated due to the change of messageId.
  @Track public messageId: number; // Prevent the info from being updated when the messageId is changed.

  constructor(info?: Info, messageId?: number) {
    this.info = info || new Info();   // Use the input info or create an Info.
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested { // Dual-level nesting. If MessageInfoNested is decorated by @ObservedV2, it cannot be decorated by the state variable decorator of V1, such as @State.
  public messageInfo: MessageInfo;

  constructor(messageInfo?: MessageInfo) {
    this.messageInfo = messageInfo || new MessageInfo();
  }
}

@Component
struct Child {
  @ObjectLink messageInfo: MessageInfo;

  build() {
    Column() {
      Text(`ObjectLink MessageInfo messageId:${this.messageInfo.messageId}`)  // After @ObjectLink disassembles the levels, the change of the top-level class property is observable.
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.messageId++;
        })
    }
  }
}

@Entry
@Component
struct Index {
  @State messageInfoNested: MessageInfoNested = new MessageInfoNested();  // For the data nested at three levels, you need to observe the internal data.

  build() {
    Column() {
      // Observe messageInfoNested. @State can only observe the top-level data and cannot observe the changes.
      Text(`messageInfoNested messageId:${this.messageInfoNested.messageInfo.messageId}`)
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfoNested name:${this.messageInfoNested.messageInfo.info.name}`)   // Being not decorated by @Trace, it is not observable.
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.info.name += 'a';
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfoNested myId:${this.messageInfoNested.messageInfo.info.myId}`) // Decorated by @Trace, data changes can be observed no matter how many levels data is nested in.
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      // Observe messageInfoId through @ObjectLink.
      Child({messageInfo: this.messageInfoNested.messageInfo})      // After disassembling, you can use @ObjectLink to observe the lower-level changes.
    }
    .height('100%')
    .width('100%')
    .margin(10)
  }
}
```

When \@ObservedV2+\@Trace is used, the following information is displayed:

* \@ObservedV2 and \@Trace realizes the observation capability to the class properties. Therefore, when a class property is marked by @Trace, the change can be observed regardless of the number of nested levels.
* When \@ObservedV2 and \@Observed are nested, whether the class object can be decorated by the decorator of V1 depends on the decorator used by the outermost class. For example, in the example, the class decorated by \@ObservedV2 does not affect the outermost class decorated by the decorator of V1.
