# 自定义组件混用场景指导

在\@Component装饰的自定义组件中（后续称V1的自定义组件），我们为开发者提供了与之对应的状态变量装饰器（后续称V1的装饰器），例如：\@State、\@Prop、\@Link等，然而状态管理V1（简称V1）对于嵌套类的观测存在诸多限制，例如需要开发者通过\@ObjectLink不断拆解嵌套类才能使得深层次数据具备观测能力。为此，在API12中为开发者开发了一套全新的状态管理V2（简称V2），开发者可以声明\@ComponentV2装饰的自定义组件（后续称V2的自定义组件）并搭配了一套全新的装饰器去使用（后续称V2的装饰器），如：\@Local、\@Param等。V2的提出不仅解决了V1对于嵌套类观测的先天性不足，同时对部分装饰器功能进行加强，如V2的\@Monitor对比V1的\@Watch不仅能感知变化后的数据，还能够获取变化之前的数据。

在设计上，我们希望V1和V2的代码是完全隔离的，因为V1能实现的功能，V2能做的更好。但从实际角度出发，V1的开发者已经有很大的基础，让开发者一次性迁移成V2也不符合实际，因此在V1的代码中使用V2的部分能力是允许的，V2中也没有完全禁止V1，这样就涉及到V1和V2的一个混用问题，例如：V1的自定义组件使用了V2的自定义组件或V1去使用V2的装饰器等。

本篇通过对V1、V2之间的混用场景进行较为完善的阐述，旨在指引开发者将V1代码向V2代码迁移。

> **说明：**
>
> 状态管理V2从API version 12开始支持。

## 概述

状态管理V1与V2的混用规则可以概括为：

* V1的自定义组件中不可以使用V2的装饰器，否则编译报错。

* 组件间不存在变量传递时，V1的自定义组件中可以使用V2的自定义组件，包括import第三方\@ComponentV2装饰的自定义组件。

* 组件间存在变量传递时，V1的变量传递给V2的自定义组件，有如下限制：
  - V1中未被装饰器装饰的变量（后称普通变量）：V2只能使用\@Param接收。
  - V1中被装饰器装饰的变量（后称状态变量）：V2存在只能通过\@Param装饰器接收，且仅限于boolean、number、enum、string、undefined、null这些简单类型数据。

* V2的自定义组件中不可以使用V1的装饰器，否则编译报错。

* 组件间不存在变量传递时，V2自定义组件可以使用V1的自定义组件，包括import第三方\@Component装饰的自定义组件。

* 组件间存在变量传递时，V2的变量传递给V1的自定义组件，有如下限制：
  - V2中未被装饰器装饰的变量（后称普通变量）：若V1使用装饰器装饰接收的数据，只能通过\@State、\@Prop、\@Provide。
  - V2中被装饰器装饰的变量（后称状态变量）：若V1使用装饰器装饰接收的数据，不支持内置类型数据：Array、Set、Map、Date。

## 状态管理装饰器总览

### 状态管理V1的装饰器

|  装饰器类别  |                            装饰器                            |
| :----------: | :----------------------------------------------------------: |
| 组件内装饰器 | \@State、\@Prop、\@Link、\@ObjectLink、\@Provide、\@Consume、\@StorageProp、\@StorageLink、\@LocalStorageProp、\@LocalStorageLink、\@Watch |
| 类相关装饰器 |                     \@Observed、\@Track                      |

### 状态管理V2的装饰器

|  装饰器类别  |                            装饰器                            |
| :----------: | :----------------------------------------------------------: |
| 组件内装饰器 | \@Local、\@Param、\@Provider、\@Consumer、\@Once、\@Event、\@Monitor、\@Computed |
| 类相关装饰器 |                \@ObservedV2、\@Trace、\@Type                 |

### 状态管理装饰器支持的数据类型总览

状态管理能够支持的数据类型有：

| 数据类型     | 关键字                                             |
| ------------ | -------------------------------------------------- |
| 简单类型数据 | boolean、number、enum、string、null、undefined     |
| function类型 | function(仅V2的\@Event、\@Monitor、\@Computed支持) |
| Object类型   | Object                                             |
| Class类型    | Class                                              |
| 内置类型     | Array、Map、Set、Date                              |



## 限制条件

### V1和V2的装饰器不允许混用

**1.V1的自定义组件中不可以使用V2的装饰器**

```typescript
@Component
struct Child {
  // @Param不可以在@Component中使用，编译报错
  // @Once @Require都是@Param的能力扩展装饰器，必须和@Param一起连用
  @Param message: string = "";	                 
  @Event changeMessage: (val: string) => void;  // @Event 不可以在@Component中使用，编译报错

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
  @Local message: string = 'Hello World'; // @Local不可以在 @Component中使用，编译报错

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

V2的组件内装饰器不允许在V1的自定义组件中使用，编译会报错。

\@Local、\@Param、\@Event，\@Provider、\@Consumer、\@Monitor、\@Computed和示例代码中的装饰器表现一致。

**2.V2的自定义组件中不可以使用V1的装饰器**

```typescript
@ComponentV2
struct Child {
  @Prop message: string = "";  	// @Prop不可以在@ComponentV2中使用，编译报错
  @Link myId: number;           // @Link不可以在@ComponentV2中使用，编译报错

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
  @State message: string = 'Hello World';      // @State不可以在@ComponentV2中使用，编译报错
  @State @Watch('idChange') myId: number = 1;  // @Watch不可以在@ComponentV2中使用，编译报错

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

V1的组件内装饰器不允许在V2的自定义组件中使用，编译会报错。

\@ObjectLink、\@Provide、\@Consume、\@StorageProp、\@StorageLink、\@LocalStorageProp、\@LocalStorageLink和示例的装饰器表现一致。

### 多个装饰器不允许装饰同一个变量（\@Watch、\@Once、\@Require除外）

```typescript
@Component
struct Child {
  @State @Prop message: string = "";	// 多个V1的装饰器不可以修饰同一个变量，编译器报错

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
  @Local @Param message: string = 'Hello World'; // 多个V2的装饰器不允许修饰同一个变量，编译器报错

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

除了\@Watch、\@Once、\@Require这些能力扩展装饰器可以配合其他装饰器使用外，其他装饰器不允许装饰同一个变量。

## 混用场景介绍   

### V1和V2类相关装饰器的混用

**1.V1的自定义组件中使用被\@ObservedV2装饰的类对象**

```typescript
@ObservedV2
class Info {
  @Trace myId: number;   		// 有观测能力
  name: string;           		// 无观测能力
  @Track trackId: number = 1; 	// @Track作为V1的装饰器，不能在@ObservedV2中使用，编译时报错；消除编译错误请去掉@Track
    
  constructor(id?: number, name?: string) {
    this.myId = id || 0;
    this.name = name || 'aaa';
  }
}

@Observed
class message extends Info {      // 继承自@ObservedV2装饰的类不可以被Observed装饰，编译时报错；消除编译错误请去掉@Observed
}

class MessageInfo extends Info {  // 继承自@ObservedV2装饰的Class不可以被V1的装饰器装饰，运行时报错；消除运行报错请去掉装饰器
}

@Entry
@Component
struct Index {
  info1: Info = new Info();                             // @ObservedV2装饰的Class可以在V1中使用，且被@Trace装饰的类属性具有观测能力
  @State info2: Info = new Info();                      // @ObservedV2装饰的Class不可以被V1的装饰器装饰，否则编译器报错；消除编译错误请去掉装饰器

  @State messageInfo: MessageInfo = new MessageInfo();  // 继承自@ObservedV2的Class不可以被V1装饰器装饰，运行时报错；消除运行错误请去掉装饰器
  build() {
    Column() {
      Text(`info1: ${this.info1.name}`)                 // name未被@Trace装饰，无法观察变化
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.name += 'b';
        })
      Text(`info1: ${this.info1.name}`)                // myId被@Trace装饰，可观察变化
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`info2: ${this.info2.myId}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info2.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfo: ${this.messageInfo.myId}`)   // 继承自@ObservedV2的Class被V1的装饰器装饰时会出现crash，运行时出错
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

\@ObservedV2的使用需要遵循如下规则：

* \@ObservedV2只能装饰Class，\@Trace、\@Type只能装饰类属性，且只能在\@ObservedV2中使用。
* \@Track不可以在\@ObservedV2中使用。
* 对于被\@ObservedV2装饰的Class，不可以直接被V1的装饰器装饰，否则编译时报错。
* 示例中，开发者去掉报错的装饰器即可正常运行，被\@Trace装饰的类属性变化时可以观察到变化，否则不可以观测到变化。

**2.V2的自定义组件中使用被\@Observed装饰的类对象**

```typescript
@Observed
class Info {
  @Track myId: number;   		  // 无观测能力，只能防止因其他属性改变而导致的连带刷新
  name: string;           		  // 无观测能力
  @Trace trackId: number = 1; 	  // @Trace作为V2的装饰器，不能在@Observed中使用，编译时报错；消除编译错误请去掉@Trace
  constructor(id?: number, name?: string) {
    this.myId = id || 0;
    this.name = name || 'aaa';
  }
}

@ObservedV2
class message extends Info {      // @ObservedV2装饰的Class不能继承@Observed，编译时报错；消除编译错误请去掉@ObservedV2
}

class MessageInfo extends Info {  
}

@Entry
@ComponentV2
struct Index {
  info1: Info = new Info();             // @Observed装饰的Class可以在V2中使用
  @Local info2: Info = new Info();      // @Observe装饰的Class不可以被V2的装饰器装饰，否则编译器报错；消除编译错误请去掉@Local
  // 继承自@ObservedV2的Class被V2装饰器装饰,V2的组件内装饰器无类属性观测能力，所以不建议在V2中使用@Observed装饰的Class
  @Local messageInfo: MessageInfo = new MessageInfo(); 
  build() {
    Column() {
      Text(`info1: ${this.info1.name}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.name += 'b';
        })
      Text(`info1: ${this.info1.name}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info1.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      Text(`info2: ${this.info2.myId}`)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info2.myId += 1;
        })
      Divider()
        .color(Color.Blue)
      // 继承自@ObservedV2的Class被V2装饰器装饰,V2的组件内装饰器无类属性观测能力，所以不建议在V2中使用@Observed装饰的Class
      Text(`messageInfo: ${this.messageInfo.myId}`)   
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

不建议开发者在V2中使用\@Observed装饰的Class，因为\@Observed和\@Track仅能对类属性做区分，无观测能力，使用\@Observed和\@ObjectLink拆分嵌套数据才能够观测深层次数据，但\@ObjectLink无法在V2的自定义组件中使用。

开发者在对V1的代码向V2迁移时，\@Observed装饰的Class不建议在\@ComponentV2中使用，无观测能力，如果一定要使用，则遵循以下规则：

* \@Observed只能装饰Class,且\@Trace不可以在\@Observed中使用。
* \@Observed和\@Track无任何观测能力，只能用于防止Class中一个类属性改变而导致整个Class的刷新。
* 继承自\@Observed的Class被V2装饰器装饰,V2的组件内装饰器无类属性观测能力，所以使用\@Observed会无法观测到类属性变化。
* 示例中，开发者去掉报错的装饰器即可正常运行，由于无观测能力，所以不建议V2中使用\@Observed。

### 不存在变量传递时，V1和V2的自定义组件混用

**1.V1中使用V2的自定义组件** 

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

V1中使用V2的自定义组件，当不存在变量传递时无影响，若涉及变量传递，请见下一节V1和V2的数据混用。

**2.V2中使用V1的自定义组件**

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

V2中使用V1的自定义组件，当不存在变量传递时无影响，若涉及变量传递，请见下一节V1和V2的数据混用。

### 存在变量传递时，V1和V2的自定义组件数据混用

**1.V1->V2：V1的普通变量传递给V2的自定义组件**

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
  // V2对数据输入有严格的管理，从父组件接受数据时，必须@Param装饰器进行数据接收
  @Param @Once message: string = "hello";	              // 可以观测到变化，同步回父组件依赖@Event，使用了@Once可以修改@Param装饰的变量
  @Param @Once undefineVal: string | undefined = undefined;  // 使用了@Once可以修改@Param装饰的变量
  @Param info: Info = new Info();		                 // 观测不到类属性变化
  @Require @Param set: Set<number>;
  
  build() {
    Column() {
      Text(`child message:${this.message}`) // 显示 string
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })

      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) // 显示 undefineVal
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`) // 显示 info:myId
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => {  // 显示 Set
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
  message: string = 'Hello World';       // 简单数据
  undefineVal: undefined = undefined;    // 简单类型，undefined
  info: Info = new Info();               // Class类型
  set: Set<number> = new Set([10, 20]);  // 内置 类型

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

当V1的普通变量传递给V2的自定义组件时，有如下限制：

* V2的自定义组件必须通过\@Param接收数据。
* 接收数据的观测能力为\@Param能力，对于接收的Class，需要通过\@ObservedV2和\@Trace才能观察变化。

**2.V1->V2：V1的状态变量传递给V2的自定义组件**

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
  // V2对数据输入有严格的管理，从父组件接受数据时，必须@Param装饰器进行数据接收
  @Param @Once message: string = "hello";
  @Param @Once undefineVal: string | undefined = undefined;  // 使用了@Once可以修改@Param装饰的变量
  @Param info: Info = new Info();
  @Require @Param set: Set<number>;
  build() {
    Column() {
      Text(`child message:${this.message}`) // 显示string
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) // 显示undefineVal
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`) // 显示info:myId
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => {  // 显示Set
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
  @State message: string = 'Hello World';       // 简单类型数据，支持
  @State undefineVal: undefined = undefined;    // 简单类型数据，undefined，支持
  @State info: Info = new Info();               // Class类型，不支持传递，编译器报错；消除编译错误请去掉@State
  @State set: Set<number> = new Set([10, 20]);  // 内置类型，不支持传递，编译器报错；消除编译错误请去掉@State

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

当V1的状态变量给V2的自定义组件时，有如下规则：

* 仅支持简单类型变量，其余类型数据会在编译时报错。

* 示例中使用了\@State装饰器，\@Prop、\@Link、\@ObjectLink、\@Provide、\@Consume、\@StorageProp、\@StorageLink、\@LocalStorageProp、\@LocalStorageLink行为和\@State保持一致。

**3.V2->V1：V2的普通变量传递给V1的自定义组件**

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
  // V1从V2接收的状态变量，若使用装饰器，仅可使用@State、@Prop、@Provide接收
  @State  message: string = "hello";	         // 可以观测到变化
  @State info: Info = new Info();		      	// 可以观测一层类属性变化
  @Prop undefineVal: undefined | string = undefined;   
  @Provide setMap: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`) 	// 显示string
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) 	// 显示undefineVal
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`)		 	// 显示info:myId
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.setMap.values()), (item: number) => {  // 显示 Set
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
  message: string = 'Hello World';       // 简单数据类型
  undefineVal: undefined = undefined;    // 简单数据类型，undefined
  info: Info = new Info();               // Class类型
  set: Set<number> = new Set([10, 20]);  // 内置 类型

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

当V2的普通变量传递给V1自定义组件时：

* V1可以不使用装饰器接收数据，接收过来的变量在V1组定义组件内也会是普通变量。

* V1若使用装饰器接收数据，仅可通过\@State、\@Prop、\@Provide接收。

**4.V2->V1：V2的状态变量传递给V1的自定义组件**

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
  // V1从V2接收的状态变量，仅可使用@State、@Prop、@Provide接收
  @State  message: string = "hello";	        // 可以观测到变化
  @State info: Info = new Info();		        // 可以观测一层类属性变化
  @Prop undefineVal: undefined | string = undefined;
  @Provide set: Set<number> = new Set();
  build() {
    Column() {
      Text(`child message:${this.message}`) 	// 显示 string
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.message = 'world';
        })
      Divider()
        .color(Color.Blue)
      Text(`undefineVal:${this.undefineVal}`) 	// 显示 undefineVal
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.undefineVal = "change to define";
        })
      Divider()
        .color(Color.Blue)
      Text(`info id:${this.info.myId}`) 	// 显示 info:myId
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.info.myId++;
        })

      Divider()
        .color(Color.Blue)
      ForEach(Array.from(this.set.values()), (item: number) => {  // 显示 Set
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
  @Local message: string = 'Hello World';       	// 简单数据类型，支持传递
  @Provider() undefineVal: undefined = undefined;   // 简单数据类型，undefined，支持传递
  @Consumer() info: Info = new Info();          	// Class类型，支持传递
  @Param set: Set<number> = new Set([10, 20]);  	// 内置类型，不支持传递；消除编译错误请去掉@Param

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

V2的状态变量传递给V1的自定义组件，存在如下限制：

* V1可以不使用装饰器接收数据，接收过来的变量在V1组定义组件内也会是普通变量。

* V1若使用装饰器接收数据，仅可通过\@State、\@Prop、\@Provide接收。
* V1若使用装饰器接收数据，不支持内置类型的数据。

### 混用场景总结

通过对V1和V2的混用场景详细梳理，可以看到，当V2的代码混用V1的代码时，即V1的组件或者类数据向V2进行传递，大部分V1的能力在V2都是被禁止的。而V1的代码去混用V2代码时，即V2的组件或者类数据向V1传递，做了部分功能开放，例如\@ObserveV2和\@Trace，这也是对V1嵌套类数据的观测能提供的最大的帮助。所以在代码开发时，不鼓励开发者使用V1和V2进行混用开发，但是对于代码迁移上，可以让V1的开发者逐步将代码向V2进行迁移，从而稳步替换V1的功能代码，并且十分不鼓励开发者在V2的代码架构上混用V1的代码。

## 补充场景

\@Observed和\@ObservedV2由于装饰Class类型，而Class可以进行多层级的嵌套，因此场景相对复杂，本节主要是对Class类型的自嵌套和内置类型的嵌套作一个详细的场景说明。由于\@Observed并没有\@ObservedV2+@Trace那样强大的深层次观测能力，不再对\@Observed的深层次嵌套进行讨论，只讨论\@ObservedV2在V1的使用场景。

### 使用\@Observed+\@ObjectLink观测嵌套类

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
class MessageInfo { 		// 一层嵌套
  @Track info: Info;        // 防止messageId改变导致info的连带刷新
  @Track messageId: number; // 防止messageId改变导致info的连带刷新

  constructor(info?: Info, messageId?: number) {
    this.info = info || new Info();   
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested {	 // 二层嵌套
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
      Text(`ObjectLink info info.myId:${this.info.myId}`)  // 经过@ObjectLink拆解两次之后，观测到变化
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
      Text(`ObjectLink MessageInfo messageId:${this.messageInfo.messageId}`)  // 经过@ObjectLink拆解之后，可以观测一层类属性变化
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      Text(`ObjectLink MessageInfo info.myId:${this.messageInfo.info.myId}`)  // 经过@ObjectLink拆解之后，依旧观测不到变化
        .fontSize(30)
        .onClick(() => {
          this.messageInfo.info.myId++;
        })
      GrandSon({info: this.messageInfo.info});				// 继续拆解一层子组件
    }
  }
}



@Entry
@Component
struct Index {
  @State messageInfoNested: MessageInfoNested = new MessageInfoNested();  // 三层嵌套的数据，需要对所有数据进行观测。

  build() {
    Column() {
      // 观察messageInfoNested
      Text(`messageInfoNested messageId:${this.messageInfoNested.messageInfo.messageId}`)  // @State只有一层类属性观测能力，无法观察到变化
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      // 通过@ObjectLink嵌套观察 messageInfoId
      Child({messageInfo: this.messageInfoNested.messageInfo})      // 经过拆分后，使用@ObjectLink拆分可以观察到深一层的变化
      Divider()
        .color(Color.Blue)
    }
    .height('100%')
    .width('100%')
    .margin(10)
  }
}
```

示例给出了一个三层嵌套的场景，可以看到：

* V1装饰器的观测能力是对数据本身做代理，因此当数据存在嵌套时，V1只能通过\@Observed+\@ObjectLink的方式进行拆分子组件观测深层次数据。
* \@Track是用来防止MessageInfo类中的info被messageId改变而连带刷新，开发者去掉\@Track可观测到，当messageId改变时，info的连带改变，但是这并不是\@ObjectLink的观测能力。

### 使用@ObsevedV2+@Trace观测嵌套类

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
class MessageInfo { // 一层嵌套
  @Track info: Info;        // 防止messageId改变导致info的连带刷新
  @Track messageId: number; // 防止messageId改变导致info的连带刷新

  constructor(info?: Info, messageId?: number) {
    this.info = info || new Info();   // 使用传入的info或创建一个新的Info
    this.messageId = messageId || 0;
  }
}

@Observed
class MessageInfoNested { // 二层嵌套，MessageInfoNested如果是被@ObservedV2装饰，则不可以被V1的状态变量更新相关的装饰器装饰，如@State
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
      Text(`ObjectLink MessageInfo messageId:${this.messageInfo.messageId}`)  // 经过@ObjectLink拆解之后，可以观测一层类属性变化
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
  @State messageInfoNested: MessageInfoNested = new MessageInfoNested();  // 三层嵌套的数据，如何观测内部。

  build() {
    Column() {
      // 观察messageInfoNested，@State只有一层观测能力，无法观察到变化
      Text(`messageInfoNested messageId:${this.messageInfoNested.messageInfo.messageId}`)
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.messageId++;
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfoNested name:${this.messageInfoNested.messageInfo.info.name}`)   // 未被@Trace修饰，无法观测
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.info.name += 'a';
        })
      Divider()
        .color(Color.Blue)
      Text(`messageInfoNested myId:${this.messageInfoNested.messageInfo.info.myId}`)   // 被@Trace修饰，无论嵌套多少层都能观测
        .fontSize(30)
        .onClick(() => {
          this.messageInfoNested.messageInfo.info.myId++;
        })
      Divider()
        .color(Color.Blue)
      // 通过@ObjectLink嵌套观察 messageInfoId
      Child({messageInfo: this.messageInfoNested.messageInfo})      // 经过拆分后，使用@ObjectLink拆分可以观察到深一层的变化
    }
    .height('100%')
    .width('100%')
    .margin(10)
  }
}
```

当使用\@observedV2 + \@Trace可以发现：

* \@observedV2 + \@Trace将观测能力嵌套到类属性上，所以当类属性被@Trace标记时，无论嵌套多少层都可以观测到变化。
* \@ObservdV2和\@Observed嵌套混用时，类对象能否被V1的装饰器装饰取决于最外层Class所使用的类装饰器，例如示例中嵌套在深处的\@ObservedV2装饰的Class不影响最外层的Class被V1的装饰器装饰。