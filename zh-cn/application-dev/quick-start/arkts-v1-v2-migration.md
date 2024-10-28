# V1-V2迁移指导

## 概述
ArkUI状态管理的主要职责是：负责将可观察数据的变化自动同步到UI界面，实现数据驱动的UI刷新，使开发者能够专注于UI界面的实现和设计，无需关注数据状态变化带来的UI更新。

在状态管理框架的演进过程中，先后推出了状态管理V1和V2两个版本。V1强调组件层级的状态管理，而V2则增强了对数据对象的深度观察与管理能力，不再局限于组件层级。通过V2，开发者能够更灵活地控制数据和状态，实现更高效的UI刷新。具体V1和V2的区别可以参见详细说明（TODO: 超链接）。

## V1V2使用指引
1. V2是V1的增强版本，为开发者提供更多功能和灵活性。
2. 对于新开发的应用，建议直接使用V2版本。
3. 对于已经使用V1的应用，如果V1的功能和性能已能满足需求，则不必立即切换到V2。但建议开发者尽早规划向V2的迁移，以便未来实现平滑过渡和改进。
4. 对于需要在现阶段混用V1和V2的场景，请参阅混用文档（TODO：超链接），请避免违反混用文档规定的场景，引发不确定性。
5. 编译器、工具链、IDE对某些不推荐的误用和混用场景会进行校验，但开发者可能通过特殊手段绕过这些校验。强烈建议开发者遵循混用文档（TODO：超链接）的指导，避免文档明确禁止的混用。

## 本文档的目的
1. 对希望将现有V1应用迁移到V2的开发者，提供系统化的模板和指导，帮助完成V1到V2的迁移。
2. 对希望逐步将V1应用过渡到V2的开发者，提供参考，结合本迁移文档与混用文档，可以帮助开发者实现逐步改造。
3. 尚未开始开发应用但已熟悉V1状态管理规则的开发者，可以参考本迁移文档及V2各个装饰器和接口的文档，开始使用V2进行应用开发。

## 迁移方法简表
| 迁移方法简表           | 旧装饰器名                | 迁移后名                  | 说明 |
|------------------------|--------------------------|--------------------------|------|
| @Observed              | @ObservedV2              | 可观察对象，表明一个可观察对象 |
| @Track                 | @Trace                   | 新装饰器只有 @Trace 装饰的属性才被精确跟踪观察，老装饰器 @Track 为精确观察，不装饰为粗略观察 |
| @Component             | @ComponentV2             | 新装饰器组件 |
| @State                 | @Local 没有接收父组件数据时 | @Param @Once 接收了父组件参数 | @State 接收父组件参数时，仅接收初始值 |
| @Prop                  | @Param                   | 当输入参数为对象时，旧装饰器为拷贝，新装饰器为引用，需要注意本组件的功能是否需要拷贝，如果需要拷贝，则需要拷贝后使用 |
| @Link                  | @Param @Twoway 语法糖    | @Param @Twoway 为语法糖，使用比 @Param + @Event 更简洁而已 |
| @ObjectLink            | @Param                   | 直接兼容，但无输入限制 |
| @Provide               | @Provider                | 兼容 |
| @Consume               | @Consumer                | 兼容 |


## 各装饰器迁移示例

### @State->@Local

#### 迁移规则
在V1 中，@State装饰器用于管理组件内部的数据状态，其功能类似于 V2中的@Local，但两者在观察能力和初始化规则上存在明显差异。针对不同的使用场景，迁移策略如下：

- 简单类型：对于简单类型的变量，可以直接将@State替换为@Local。
- 复杂类型：V1中的@State可以观察复杂对象的第一层属性变化，而V2中的@Local只能观察对象自身的变化。如果需要追踪对象内部的属性变化，可以结合使用@ObservedV2和@Trace。
- 外部初始化：V1 中，@State支持从外部传递初始值，但在V2中，@Local禁止外部初始化。若需要从外部传递初始值，可以使用@Param 和@Once装饰器来实现类似的效果。

#### 示例

##### 简单类型
对于简单类型变量，V1的@State可以直接替换为替换为V2的@Local。

V1实现：

```ts
@Entry
@Component
struct Child {
  @State val: number = 10
  build(){
    Text(this.val.toString())
  }
}
```

V2迁移策略：直接替换。

```ts
@Entry
@ComponentV2
struct Child {
  @Local val: number = 10
  build(){
    Text(this.val.toString())
  }
}
```

##### 复杂类型
V1的@State能够观察复杂对象的第一层属性变化，但V2的@Local无法观察对象内部变化。为了解决这个问题，需要在类上添加@ObservedV2，并在需要观察的属性上添加@Trace。这样，框架就能追踪对象内部的属性变化。

V1实现：

```ts
class Child {
  public value: number = 10;
}

@Component
@Entry
struct example {
  @State child: Child = new Child();
  build(){
    Column() {
      Text(this.child.value.toString())
      // @State可以观察第一层变化
      Button('value+1')
        .onClick(()=>{this.child.value++})
    }
  }
}
```

V2迁移策略：使用@ObservedV2和@Trace。

```ts
@ObservedV2
class Child {
  @Trace public value: number = 10;
}

@ComponentV2
@Entry
struct example {
  @Local child: Child = new Child();
  build(){
    Column() {
      Text(this.child.value.toString())
      // @Local只能观察自身，需要给Child加上@ObservedV2和@Trace
      Button('value+1')
        .onClick(()=>{this.child.value++})
    }
  }
}
```

##### 外部初始化状态变量
V1的@State变量可以从外部初始化，V2的@Local禁止外部初始化。为实现类似功能，需要用@Param和@Once代替@State，允许外部传入初始值，并确保该值只初始化一次。

V1实现：

```ts
@Component
struct Child {
  @State value: number = 0;
  build() {
    Text(this.value.toString())
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column(){
      // @State可以从外部初始化
      Child({ value: 30 })
    }
  }
}
```

V2迁移策略：使用@Param和@Once。

```ts
@ComponentV2
struct Child {
  @Param @Once value: number = 0;
  build() {
    Text(this.value.toString())
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column(){
      // @Local禁止从外部初始化，可以用@Param和@Once替代实现
      Child({ value: 30 })
    }
  }
}
```

### @Link -> @Param/Event

#### 迁移规则
在V1中，@Link允许父组件和子组件之间进行双向数据绑定。迁移到V2时，可以用@Param和@Event模拟双向同步。@Param实现父到子的单向传递，子组件再通过@Event回调函数触发父组件的状态更新。

#### 示例

V1实现：

```ts
@Component
struct Child {
  // @Link可以双向同步数据
  @Link val: number;
  build() {
    Column(){
      Text("child: " + this.val.toString())
      Button("+1")
        .onClick(()=>this.val++)
    }
  }
}

@Entry
@Component
struct Parent {
  @State myVal: number = 10;
  build() {
    Column(){
      Text("parent: " + this.myVal.toString())
      Child({val: this.myVal})
    }
  }
}
```

V2迁移策略：使用@Param和@Event

```ts
@ComponentV2
struct Child {
  // @Param搭配@Event回调实现数据双向同步
  @Param val: number  = 0;
  @Event addOne: () => void;
  build() {
    Column(){
      Text("child: " + this.val.toString())
      Button("+1")
        .onClick(()=>this.addOne())
    }
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local myVal: number = 10
  build() {
    Column() {
      Text("parent: " + this.myVal.toString())
      Child({ val: this.myVal, addOne: () => this.myVal++})
    }
  }
}
```

### @Prop -> @Param

#### 迁移规则
在V1中，@Prop装饰器用于从父组件传递参数给子组件，这些参数在子组件中可以被直接修改。在V2中，@Param取代了@Prop的作用，但@Param是只读的，子组件不能直接修改参数的值。因此，根据场景的不同，有几种迁移策略：

- 简单类型：对于简单类型的参数，可以直接将@Prop替换@Param。
- 子组件修改变量：如果子组件需要修改传入的参数，可以使用@Once 来允许子组件对该参数进行本地化修改。
- 复杂类型：如果传递的是复杂对象且需要严格的单向数据绑定，可以对对象进行深拷贝，防止子组件修改父组件的数据。

#### 示例

##### 简单类型

对于简单类型变量，V1的@Prop可以直接替换为替换为V2的@Param。

V1实现：

```ts
@Component
struct Child {
  @Prop value: number;
  build() {
    Text(this.value.toString())
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column(){
      Child({ value: 30 })
    }
  }
}
```

V2迁移策略：直接替换

```ts
@ComponentV2
struct Child {
  @Param value: number = 0;
  build() {
    Text(this.value.toString())
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column(){
      Child({ value: 30 })
    }
  }
}
```

##### 子组件修改变量
在V1中，子组件可以修改@Prop的变量，然而在V2中，@Param是只读的。如果子组件需要修改传入的值，可以使用@Param和@Once允许子组件在本地修改。

V1实现：

```ts
@Component
struct Child {
  // @Prop可以直接修改变量值
  @Prop value: number;
  build() {
    Column(){
      Text(this.value.toString())
      Button("+1")
        .onClick(()=>this.value++)
    }
  }
}

@Entry
@Component
struct Parent {
  build() {
    Column(){
      Child({ value: 30 })
    }
  }
}
```

V2迁移策略：使用@Param和@Once

```ts
@ComponentV2
struct Child {
  // @Param搭配@Once使用，可以在本地修改@Param变量
  @Param @Once value: number = 0;
  build() {
    Column(){
      Text(this.value.toString())
      Button("+1")
        .onClick(()=>this.value++)
    }
  }
}

@Entry
@ComponentV2
struct Parent {
  build() {
    Column(){
      Child({ value: 30 })
    }
  }
}
```

##### 复杂类型的单项数据传递
在V2中，传递复杂类型时，如果希望实现严格的单向数据绑定，防止子组件修改父组件的数据，需要在使用@Param传递复杂对象时进行深拷贝以避免传递对象的引用。

V1实现：

```ts
class Fruit{
  apple: number = 5;
  orange: number = 10;
}

@Component
struct Child {
  // @Prop传递Fruit类，当子类修改属性，父类不受影响
  @Prop fruit: Fruit;
  build() {
    Column() {
      Text("child apple: "+this.fruit.apple.toString())
      Text("child orange: "+this.fruit.orange.toString())
      Button("apple+1")
        .onClick(()=>this.fruit.apple++)
      Button("orange+1")
        .onClick(()=>this.fruit.orange++)
    }
  }
}

@Entry
@Component
struct Parent {
  @State parentFruit: Fruit = new Fruit();
  build() {
    Column(){
      Text("parent apple: "+this.parentFruit.apple.toString())
      Text("parent orange: "+this.parentFruit.orange.toString())
      Child({ fruit: this.parentFruit })
    }
  }
}
```
​
V2迁移策略：使用深拷贝

```ts
@ObservedV2
class Fruit{
  @Trace apple: number = 5;
  @Trace orange: number = 10;
  // 实现深拷贝，子组件不会修改父组件的数据
  clone(): Fruit {
    let newFruit: Fruit = new Fruit();
    newFruit.apple = this.apple;
    newFruit.orange = this.orange;
    return newFruit;
  }
}

@ComponentV2
struct Child {
  @Param fruit: Fruit = new Fruit();
  build() {
    Column() {
      Text("child")
      Text(this.fruit.apple.toString())
      Text(this.fruit.orange.toString())
      Button("apple+1")
        .onClick(()=>this.fruit.apple++)
      Button("orange+1")
        .onClick(()=>this.fruit.orange++)
    }
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local parentFruit: Fruit = new Fruit();
  build() {
    Column(){
      Text("parent")
      Text(this.parentFruit.apple.toString())
      Text(this.parentFruit.orange.toString())
      Child({ fruit: this.parentFruit.clone()})
    }
  }
}
```

### @ObjectLink/@Observed/@Track -> @ObservedV2/@Trace
#### 迁移规则
在V1中，@Observed与@ObjectLink装饰器用于观察类对象及其嵌套属性的变化，但V1只能直接观察对象的第一层属性。对于嵌套对象的属性，必须通过自定义组件和@ObjectLink实现监控。此外，V1中提供了@Track装饰器来实现对属性级别变化的精确控制。

在V2中，@ObservedV2与@Trace结合使用，可以高效地实现类对象及其嵌套属性的深度监控，省去了对自定义组件的依赖，简化了开发流程。同时，@Trace装饰器还具备精确更新的能力，替代了V1中的@Track，从而实现更高效的UI刷新控制。根据不同的场景，有以下迁移策略：

- 嵌套对象的属性观察：V1中需要通过自定义组件和@ObjectLink监控嵌套属性，V2中则可以使用@ObservedV2和@Trace直接观察嵌套对象，简化了代码结构。
- 类属性的精确更新：V1中的@Track可以用V2中的@Trace取代，@Trace可以同时观察和精确更新属性变化，使代码更简洁高效。

#### 示例
##### 嵌套对象属性观察方法

在V1中，无法直接观察嵌套对象的属性变化，只能观察到第一层属性的变化。必须通过创建自定义组件并使用@ObjectLink来实现对嵌套属性的观察。V2中使用@ObservedV2和@Trace，可以直接对嵌套对象的属性进行深度观察，减少复杂度。

V1实现：

```ts
@Observed
class Address {
  city: string;

  constructor(city: string) {
    this.city = city;
  }
}

@Observed
class User {
  name: string;
  address: Address;

  constructor(name: string, address: Address) {
    this.name = name;
    this.address = address;
  }
}

@Component
struct AddressView {
  // 子组件中@ObjectLink装饰的address从父组件初始化，接收被@Observed装饰的Address实例
  @ObjectLink address: Address;

  build() {
    Column() {
      Text(`City: ${this.address.city}`)
      Button("city +a")
        .onClick(()=>this.address.city += "a")
    }
  }
}

@Entry
@Component
struct UserProfile {
  @State user: User = new User("Alice", new Address("New York"));

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      // 无法直接观察嵌套对象的属性变化，例如this.user.address.city
      // 只能观察到对象第一层属性变化，所以需要将嵌套的对象Address抽取到自定义组件AddressView
      AddressView({ address: this.user.address })
    }
  }
}
```

V2迁移策略：使用@ObservedV2和@Trace

```ts
@ObservedV2
class Address {
  @Trace city: string;

  constructor(city: string) {
    this.city = city;
  }
}

@ObservedV2
class User {
  @Trace name: string;
  @Trace address: Address;

  constructor(name: string, address: Address) {
    this.name = name;
    this.address = address;
  }
}

@Entry
@ComponentV2
struct UserProfile {
  @Local user: User = new User("Alice", new Address("New York"));

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      // 通过@ObservedV2和@Trace可以直接观察嵌套属性
      Text(`City: ${this.user.address.city}`)
      Button("city +a")
        .onClick(()=>this.user.address.city += "a")
    }
  }
}
```
##### 类属性变化观测

在V1中，@Observed用于观察类实例及其属性的变化，@Track则用于对属性级别的变化优化，使得只有被@Track装饰的属性触发UI更新。在V2中，@Trace结合了观察和更新属性级别变化的能力，搭配@ObservedV2实现高效的UI更新。

V1实现：

```ts
@Observed
class User {
  @Track name: string;
  @Track age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@Entry
@Component
struct UserProfile {
  @State user: User = new User('Alice', 30);

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      Text(`Age: ${this.user.age}`)
      Button("increase age")
        .onClick(()=>this.user.age++)
    }
  }
}
```

V2迁移策略：使用@ObservedV2和@Trace

```ts
@ObservedV2
class User {
  @Trace name: string;
  @Trace age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@Entry
@ComponentV2
struct UserProfile {
  @Local user: User = new User('Alice', 30);

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      Text(`Age: ${this.user.age}`)
      Button("Increase age")
        .onClick(()=>this.user.age++)
    }
  }
}
```

### @Provide/@Consume -> @Provider/@Consumer
#### 迁移规则
在V1中，@Provide和@Consume用于父子组件之间的数据共享，可以通过alias或属性名匹配，同时@Consume必须依赖父组件的@Provide，不允许本地初始化。而V2中，@Provider和@Consumer增强了这些特性，使数据共享更加灵活。根据不同的场景，有以下迁移策略：

- alias和属性名匹配规则：V1中，@Provide和@Consume可以通过alias或属性名匹配；V2中，alias是唯一的匹配key，指定alias后只能通过alias匹配。
- 本地初始化支持：V1中，@Consume不允许本地初始化，必须依赖父组件；V2中，@Consumer支持本地初始化，当找不到对应的@Provider时使用本地默认值。
- 从父组件初始化：V1中，@Provide可以直接从父组件初始化；V2中，@Provider不支持外部初始化，需用@Param和@Once接受初始值并赋给 @Provider。
- 重载支持：V1中，@Provide默认不支持重载，需设置 allowOverride；V2中，@Provider默认支持重载，@Consumer会向上查找最近的@Provider。
#### 示例
##### alias和属性名匹配规则
在V1中，@Provide和@Consume的匹配既可以通过alias，也可以通过属性名。在V2中，alias成为唯一的key，如果在@Consumer中制定了alias，只能通过alias而非属性名进行匹配。

V1实现:

```ts
@Component
struct Child{
  // alias和属性名都为key，alias和属性名都可以匹配
  @Consume('text') childMessage: string;
  @Consume message: string;
  build(){
    Column(){
      Text(this.childMessage)
      Text(this.message) // Text是Hello World
    }
  }
}

@Entry
@Component
struct Parent{
  @Provide('text') message: string = "Hello World";
  build(){
    Column(){
      Child()
    }
  }
}
```

V2迁移策略：确保alias一致，没有指定alias的情况下，依赖属性名进行匹配

```ts
@ComponentV2
struct Child{
  // alias是唯一匹配的key，有alias情况下无法通过属性名匹配
  @Consumer('text') childMessage: string = "default";
  @Consumer() message: string = "default";
  build(){
    Column(){
      Text(this.childMessage)
      Text(this.message) // Text是default
    }
  }
}

@Entry
@ComponentV2
struct Parent{
  @Provider('text') message: string = "Hello World";
  build(){
    Column(){
      Child()
    }
  }
}
```

##### V1的@Consume不支持本地初始化，V2支持
V1中，@Consume不允许本地初始化变量，必须依赖父组件的@Provide，否则会抛出异常。迁移到V2后，@Consumer允许本地初始化，当找不到对应的@Provider，会使用本地默认值。

V1实现：

```ts
@Component
struct Child{
  // @Consume禁止本地初始化，当找不到对应的@Provide时抛出异常
  @Consume message: string;
  build(){
    Text(this.message)
  }
}

@Entry
@Component
struct Parent{
  @Provide message: string = "Hello World";
  build(){
    Column(){
      Child()
    }
  }
}
```

V2迁移策略：@Consumer可以本地初始化

```ts
@ComponentV2
struct Child{
  // @Consumer允许本地初始化，当找不到@Provider的时候使用本地默认值
  @Consumer() message: string = "Hello World";
  build(){
    Text(this.message)
  }
}

@Entry
@ComponentV2
struct Parent{
  build(){
    Column(){
      Child()
    }
  }
}
```

##### V1的@Provide可以从父组件初始化，V2不支持
在V1中，@Provide允许从父组件初始化，可以直接通过组件参数传递初始值。在V2中，@Provider禁止从外部初始化。为实现相同功能，可以在子组件中使用@Param @Once接受初始值，然后将其赋值给@Provider变量。

V1实现：

```ts
@Entry
@Component
struct Parent {
  @State parentValue: number = 42;
  build() {
    Column() {
      // @Provide可以从父组件初始化
      Child({ childValue: this.parentValue })
    }
  }
}

@Component
struct Child {
  @Provide childValue: number = 0;
  build(){
    Column(){
      Text(this.childValue.toString())
    }
  }
}
```

V2迁移策略：使用@Param接受，再赋值给@Provider

```ts
@Entry
@ComponentV2
struct Parent {
  @Local parentValue: number = 42;
  build() {
    Column() {
      // @Provider禁止从父组件初始化，替代方案为先用@Param接受，再赋值给@Provider
      Child({ initialValue: this.parentValue })
    }
  }
}

@ComponentV2
struct Child {
  @Param @Once initialValue:number = 0;
  @Provider() childValue: number = this.initialValue;
  build() {
    Column(){
      Text(this.childValue.toString())
    }
  }
}
```

##### V1的@Provide默认不支持重载，V2默认支持
在V1中，@Provide默认不支持重载，无法覆盖上层组件的同名@Provide。若需支持重载，必须设置allowOverride。在V2中，@Provider默认支持重载，@Consumer会向上查找最近的@Provider，无需额外设置。

V1实现:

```ts
@Entry
@Component
struct GrandParent {
  @Provide("reviewVotes") reviewVotes: number = 40;
  build() {
    Column(){
      Parent()
    }
  }
}

@Component
struct Parent {
  // @Provide默认不支持重载，支持重载需设置allowOverride函数
  @Provide({ allowOverride: "reviewVotes" }) reviewVotes: number = 20;
  build() {
    Child()
  }
}

@Component
struct Child {
  @Consume("reviewVotes") reviewVotes: number;
  build() {
    Text(this.reviewVotes.toString()) // Text显示20
  }
}
```

V2迁移策略：去掉allowOverride

```ts
@Entry
@ComponentV2
struct GrandParent {
  @Provider("reviewVotes") reviewVotes: number = 40;
  build() {
    Column(){
      Parent()
    }
  }
}

@ComponentV2
struct Parent {
  // @Provider默认支持重载，@Consumer向上查找最近的@Provider
  @Provider() reviewVotes: number = 20;
  build() {
    Child()
  }
}

@ComponentV2
struct Child {
  @Consumer() reviewVotes: number = 0;
  build() {
    Text(this.reviewVotes.toString()) // Text显示20
  }
}
```

### @Watch -> @Monitor
#### 迁移规则
在V1中，@Watch用于监听状态变量的变化，并在变量变化时触发指定回调函数。在V2中，@Monitor 替代了@Watch，可以更灵活地监听变量的变化，并获取变量变化前后的值。具体的迁移策略如下：

- 单变量监听：对于简单的场景，可以直接用@Monitor替换@Watch，效果一致。
- 多变量监听：V1的@Watch 每次只能监听一个变量，且无法获取变化前的值。在V2中，@Monitor 支持同时监听多个变量，并可以访问变量变化前后的状态。
#### 示例
##### 单变量监听
对于简单案例，V1的@Watch可以直接替换为替换为V2的@Monitor。

V1实现：

```ts
@Entry
@Component
struct watchExample {
  @State @Watch('onAppleChange') apple: number = 0;
  onAppleChange(): void {
    console.log("apple count changed to "+this.apple)
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Button("add apple")
        .onClick(()=> this.apple++)
    }
  }
}
```

V2迁移策略：直接替换

```ts
@Entry
@ComponentV2
struct monitorExample {
  @Local apple: number = 0;
  @Monitor('apple')
  onFruitChange(monitor: IMonitor) {
    console.log(`apple changed from ${monitor.value()?.before} to ${monitor.value()?.now}`)
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Button("add apple")
        .onClick(()=> this.apple++)
    }
  }
}
```

##### 多变量监听
在V1中，每个@Watch回调函数只能监听一个变量，且无法获取变化前的值。迁移到V2后，可以使用一个@Monitor同时监听多个变量以及获取监听变量的变化前后的值。

V1实现：

```ts
@Entry
@Component
struct watchExample {
  @State @Watch('onAppleChange') apple: number = 0;
  @State @Watch('onOrangeChange') orange: number = 0;
  // @Watch 回调，只能监听单个变量，不能获取变化前的值
  onAppleChange(): void {
    console.log("apple count changed to "+this.apple)
  }
  onOrangeChange(): void {
    console.log("orange count changed to "+this.orange)
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Text(`orange count: ${this.orange}`)
      Button("add apple")
        .onClick(()=> this.apple++)
      Button("add orange")
        .onClick(()=> this.orange++)
    }
  }
}
```

V2迁移策略：同时监听多个变量，以及获取变化前的值

```ts
@Entry
@ComponentV2
struct monitorExample {
  @Local apple: number = 0;
  @Local orange: number = 0;
  // @Monitor 回调，支持监听多个变量，可以获取变化前的值
  @Monitor('apple','orange')
  onFruitChange(monitor: IMonitor) {
    monitor.dirty.forEach((name: string) => {
      console.log(`${name} changed from ${monitor.value(name)?.before} to ${monitor.value(name)?.now}`)
    })
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Text(`orange count: ${this.orange}`)
      Button("add apple")
        .onClick(()=> this.apple++)
      Button("add orange")
        .onClick(()=> this.orange++)
    }
  }
}
```