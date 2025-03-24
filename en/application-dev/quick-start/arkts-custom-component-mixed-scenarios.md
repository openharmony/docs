# Mixing Use of Custom Components

For the \@Component decorated custom components (referred to as the custom components of V1), corresponding state variable decorators (referred to as the decorators of V1), such as \@State, \@Prop, and \@Link, are provided. However, state management V1 (V1 for short) has many restrictions on the observation of nested classes. For example, you need to use \@ObjectLink to continuously disassemble nested classes so that in-depth data can be observed. Therefore, a new set of state management V2 (V2 for short) is developed in API version 12. You can declare \@ComponentV2 decorated custom components (referred to as custom components of V2) and use them with new decorators (referred to as the decorators of V2), such as \@Local and \@Param. The proposal of V2 not only compensates the deficiency of V1 in nested class observation, but also enhances some decorator functions. For example, compared with \@Watch of V1, \@Monitor of V2 can sense the changed data and obtain the data before the change.

In terms of design, the code of V1 and V2 are expected to be completely isolated because V2 can do better than V1 in certain scenarios. However, from the actual perspective, the code developed in V1 have a solid foundation and it is not practical to migrate the entire code to V2 at a time. Therefore, it is allowed to use some capabilities of V2 in the code of V1 and capabilities of V1 is not completely prohibited in V2. For example, a custom component of V1 uses a custom component of V2, or V1 uses a decorator of V2. In this way, a problem of mixed use of V1 and V2 occurs.

This topic describes the mixed use of V1 and V2, aiming at guiding you to migrate code of V1 to V2.

> **NOTE**
>
> State management V2 is supported since API version 12.
> The rules for mixed use described in this topic apply only to API version 17 and earlier. Since API version 18, state management provides new APIs [enableV2Compatibility](../reference/apis-arkui/js-apis-StateManagement.md#enablev2compatibility18) and [makeV1Observed](../reference/apis-arkui/js-apis-StateManagement.md#makev1observed18) to help you solve the problem of mixed use during the migration from V1 to V2. For details, see [Mixing Use of State Management V1 and V2](./arkts-v1-v2-mixusage.md).

## Overview

The rules for mixing the use of V1 and V2 are as follows:

* The decorators of V2 cannot be used in the custom components of V1. Otherwise, an error is reported during compilation.

* When no variable is passed between components, custom components of V1 can use custom components of V2 as well as import \@ComponentV2 decorated custom components of a third party.

* When variables are passed between components, such as passing variables of V1 to the custom components of V2, constraints are as follows:
  - Variables that are not decorated by decorators in V1 (common variables) can be received only by using \@Param in V2.
  - Variables decorated by the decorator in V1 (state variables) can be received only by using \@Param in V2 and are limited to simple data types such as boolean, number, enum, string, undefined and null.

* The decorators of V1 cannot be used in the custom components of V2. Otherwise, an error is reported during compilation.

* When no variable is passed between components, custom components of V2 can use custom components of V1 as well as import \@Component decorated custom components of a third party.

* When variables are passed between components, such as passing variables of V2 to the custom components of V1, constraints are as follows:
  - Variables that are not decorated by decorators in V2 (common variables) can be received by using \@State, \@Prop, and \@Provide in V1.
  - Variables decorated by the decorator in V2 (state variables) of the built-in types, such as Array, Set, Map, and Date, are not supported in V1.

## State Management Decorator Overview

### Decorators of V1

|  Type |                            Decorator                           |
| :----------: | :----------------------------------------------------------: |
| Intra-component decorator| \@State, \@Prop, \@Link, \@ObjectLink, \@Provide, \@Consume, \@StorageProp, \@StorageLink, \@LocalStorageProp, \@LocalStorageLink, \@Watch|
| Class-related decorator|                     \@Observed, \@Track                     |

### Decorators of V2

|  Type |                            Decorator                           |
| :----------: | :----------------------------------------------------------: |
| Intra-component decorator| \@Local, \@Param, \@Provider, \@Consumer, \@Once, \@Event, \@Monitor, \@Computed|
| Class-related decorator|                \@ObservedV2, \@Trace, \@Type                |

### Data Types Supported by State Management Decorators

 

| Type    | Keyword                                            |
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
  // @Once and @Require are the extended decorators of @Param and must be used together with @Param.
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
  @Prop message: string = "";  	// @Prop cannot be used in @ComponentV2. Otherwise, an error is reported during compilation.
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
  @State @Prop message: string = "";	// Multiple decorators of V1 cannot decorate the same variable. Otherwise, an error is reported during compilation.

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

**1. Use the \@ObservedV2 decorated class object in a custom component of V1.**

```typescript
@ObservedV2
class Info {
  @Trace myId: number;   		// Observable.
  name: string;           		// Not observable.
  @Track trackId: number = 1; 	// As a decorator of V1, @Track cannot be used in @ObservedV2. Otherwise, an error is reported during compilation. Remove @Track to eliminate the error.
  
  constructor(id?: number, name?: string) {
    this.myId = id || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class message extends Info {	// Classes inherited from @ObservedV2 cannot be decorated by Observed. Otherwise, an error is reported during compilation. Remove @Observed to eliminate the error.
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
  @Track myId: number;   		  // Not observable. Only associated update caused by other property changes can be prevented.
  name: string;           		  // Not observable.
  @Trace trackId: number = 1; 	  // As a decorator of V2, @Trace cannot be used in @Observed. Otherwise, an error is reported during compilation. Remove @Trace to eliminate the error.
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

When migrating code from V1 to V2, you are not advised to use \@Observed decorated classes in \@ComponentV2 because they are not observable. If you have to use the classes, comply with the following rules:

* \@Observed can only decorate class, and \@Trace cannot be used in \@Observed.
* \@Observed and \@Track decorated classes are not observable and you can use the decorators only to prevent the entire class from being refreshed when a class property is changed.
* Classes inherited from @Observed are decorated by the decorator of V2, but the class properties cannot be observed the intra-component decorator of V2. Therefore, class property changes cannot be observed using \@Observed.
* In the example, the code can be executed properly after you remove the decorator that reports error. Because the observation capability is unavailable, you are not advised to use \@Observed in V2.

### Mixing Use of Custom Components of V1 and V2 When No Variable Is Passed

**1. Use the custom components of V2 in V1.**

```typescript
@ComponentV2
struct Child {
  @Local message: string = "hello";

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
struct Index {
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
      Child()
    }
    .height('100%')
    .width('100%')
  }
}
```

Using the custom components of V2 in V1 performs no impact when no variable is passed.

**2. Use the custom components of V1 in V2.**

```typescript
@Component
struct Child {
  @State message: string = "hello";

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
struct Index {
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
      Child()
    }
    .height('100%')
    .width('100%')
  }
}
```

Using the custom components of V1 in V2 performs no impact when no variable is passed.

### Mixing Use of Custom Components of V1 and V2 When Variables Are Passed

**1. V1 > V2: Pass the common variables of V1 to the custom component of V2.**

```typescript
class Info {
  myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@ComponentV2
struct Child {  
  // V2 strictly manages data input. When receiving data from the parent component, the @Param decorator must be used to receive data.
  @Param @Once message: string = "hello";	              // Changes are observable and can be synchronized to the parent component through @Event. @Once can be used to change @Param decorated variables.
  @Param @Once undefineVal: string | undefined = undefined;  // @Once can be used to change @Param decorated variables.
  @Param info: Info = new Info();		                 // The class property changes are not observable.
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
      Text(`undefineVal:${this.undefineVal}`) // Display undefineVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
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
struct Index {
  message: string = 'Hello World';       // Simple type.
  undefineVal: undefined = undefined;    // Simple type: undefined.
  info: Info = new Info();               // Class type.
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
      Child({
        message: this.message,
        undefineVal: this.undefineVal,
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

```typescript
class Info {
  myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@ComponentV2
struct Child {  
  // V2 strictly manages data input. When receiving data from the parent component, the @Param decorator must be used to receive data.
  @Param @Once message: string = "hello";
  @Param @Once undefineVal: string | undefined = undefined;  // @Once can be used to change @Param decorated variables.
  @Param info: Info = new Info();
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
      Text ('undefineVal:${this.undefineVal}') // Display undefineVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
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
struct Index {
  @State message: string = 'Hello World';       // Simple type data can be passed.
  @State undefineVal: undefined = undefined;    // Simple type data, undefined, can be passed.
  @State info: Info = new Info();               // Class type cannot be passed. Otherwise, an error is reported during compilation. Remove @State to eliminate the error.
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
      Child({
        message: this.message,
        undefineVal: this.undefineVal,
        info: this.info,
        set: this.set
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

When the state variable of V1 is assigned to the custom component of V2, rules are as follows:

* Only simple variables are supported. For other types of data, an error is reported during compilation.

* In the example, the \@State decorator is used. Other decorators such as \@Prop, \@Link, \@ObjectLink, \@Provide, \@Consume, \@StorageProp, \@StorageLink, \@LocalStorageProp and \@LocalStorageLink work in the same way as \@State.

**3. V2 > V1: Pass the common variables of V2 to the custom component of V1.**

```typescript
class Info {
  myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Component
struct Child {  
  // State variable received by V1 from V2. Only @State, @Prop, and @Provide decorators can be used.
  @State  message: string = "hello";	         // Changes are observable.
  @State info: Info = new Info();		      	// Top-level class property changes are observable.
  @Prop undefineVal: undefined | string = undefined;   
  @Provide setMap: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`) 	// Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) 	// Display undefineVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`)		 	// Display info:myId.
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
struct Index {
  message: string = 'Hello World';       // Simple type.
  undefineVal: undefined = undefined;    // Simple type: undefined.
  info: Info = new Info();               // Class type.
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
      Child({
        message: this.message,
        undefineVal: this.undefineVal,
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

* V1 can receive data without using the decorator. The received variables are also common variables in the custom component of V1.

* If V1 uses a decorator to receive data, data can be received only through \@State, \@Prop, and \@Provide.

**4. V2 > V1: Pass the state variables of V2 to the custom component of V1.**

```typescript
class Info {
  myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Component
struct Child {  
  // State variable received by V1 from V2. Only @State, @Prop, and @Provide can be used.
  @State  message: string = "hello";	        // Changes are observable.
  @State info: Info = new Info();		        // Top-level class property changes are observable.
  @Prop undefineVal: undefined | string = undefined;
  @Provide set: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`) 	// Display the string.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) 	// Display undefineVal.
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`) 	// Display info:myId.
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
struct Index {
  @Local message: string = 'Hello World';       	// Simple type data can be passed.
  @Provider() undefineVal: undefined = undefined;   // Simple type data, undefined, can be passed.
  @Consumer() info: Info = new Info();          	// Class type can be passed.
  @Param set: Set<number> = new Set([10, 20]);  	// Built-in type cannot be passed. Otherwise, an error is reported during compilation. Remove @Param to eliminate the error.

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
      Child({
        message: this.message,
        undefineVal: this.undefineVal,
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

* If V1 uses a decorator to receive data, data can be received only through \@State, \@Prop, and \@Provide.
* If a decorator is used to receive data in V1, data of the built-in type cannot be received.

### Summary

According to the detailed analysis of the mixed use of V1 and V2, when the code of V1 is used in V2, that is, components or classes of V1 are passed to V2, most capabilities of V1 are disabled in V2. When the code of V2 is used in V1, that is, components or classes of V2 are passed to V1, some functions are available, for example, \@ObservedV2 and \@Trace. This is also the most helpful way to observe the V1 nested class data. Therefore, during code development, you are not advised to use V1 and V2 together for mixed development. However, you can gradually migrate the code of V1 to V2 to steadily replace the function code of V1. In addition, you are not advised to use the code of V1 in V2.

## Supplementary Scenarios

Classes can be nested at multiple levels because they are decorated by \@Observed and \@ObservedV2, leading to a complex scenario. This section mainly describes the self-nesting of the class type and the nesting of the built-in type. Lack of in-depth observation capability like \@ObservedV2 and @Trace, the in-depth nesting of \@Observed is not discussed. Only the use scenarios of \@ObservedV2 in V1 are discussed.

### Using \@Observed and \@ObjectLink to Observe Nested Classes

```typescript
@Observed
class Info {
  myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class MessageInfo { 		// One-level nesting.
  @Track info: Info;        // Prevent the info from being updated when the messageId is changed.
  @Track messageId: number; // Prevent the info from being updated when the messageId is changed.

  constructor(info?: Info, messageId?: number) {
    this.info = info || new Info();   
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested { // Dual-level nesting.
  messageInfo: MessageInfo;

  constructor(messageInfo?: MessageInfo) {
    this.messageInfo = messageInfo || new MessageInfo();
  }
}

@Component
struct GrandSon {
  @ObjectLink info: Info;

  build() {
    Column() {
      Text(`ObjectLink info info.myId:${this.info.myId}`)  // After @ObjectLink disassembles the level twice, the change is observable.
        .fontSize(30)
        .onClick(() => {
          this.info.myId++;
        })
    }
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
      Divider()
        .color(Color.Blue)
      Text(`ObjectLink MessageInfo info.myId:${this.messageInfo.info.myId}`)  // After @ObjectLink disassembles the level, the change is not observable.
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.info.myId++;
        })
      GrandSon({info: this.messageInfo.info});				// Continue to disassemble the top-level child components.
    }
  }
}



@Entry
@Component
struct Index {
  @State messageInfoNested: MessageInfoNested = new MessageInfoNested();  // For the data nested at three levels, you need to observe all data.

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
      Child({messageInfo: this.messageInfoNested.messageInfo})      // After disassembling, you can use @ObjectLink to observe the lower-level changes.
      Divider()
        .color(Color.Blue)
    }
    .height('100%')
    .width('100%')
    .margin(10)
  }
}
```

The sample code uses a three-layer nesting to show:

* The observation capability of the decorator of V1 is to function as a proxy for data. Therefore, when data is nested, the decorator of V1 can only disassemble the child component to observe lower-level data through \@Observed and \@ObjectLink.
* \@Track is used to prevent the **info** in the **MessageInfo** class from being updated when the **messageId** is changed. You can remove \@Track to observe the change. When the **messageId** is changed, the **info** is also changed. However, this change cannot be observed by \@ObjectLink.

### Using @ObsevedV2 and @Trace to Observe Nested Classes

```typescript
@ObservedV2
class Info {
  @Trace myId: number;
  name: string;

  constructor(myId?: number, name?: string) {
    this.myId = myId || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class MessageInfo { // One-level nesting.
  @Track info: Info;        // Prevent the info from being updated when the messageId is changed.
  @Track messageId: number; // Prevent the info from being updated when the messageId is changed.

  constructor(info?: Info, messageId?: number) {
    this.info = info || new Info();   // Use the input info or create an Info.
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested { // Dual-level nesting. If MessageInfoNested is decorated by @ObservedV2, it cannot be decorated by the state variable decorator of V1, such as @State.
  messageInfo: MessageInfo;

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

The sample code shows:

* \@ObservedV2 and \@Trace nest the observation capability to the class properties. Therefore, when a class property is marked by @Trace, the change can be observed regardless of the number of nested levels.
* When \@ObservdV2 and \@Observed are used together, the decorator used by the outermost class determines whether the class object can be decorated by the decorator of V1. For example, the class decorated by \@ObservedV2 in the lower level does not affect the outermost class decorated by the decorator of V1.

<!--no_check-->