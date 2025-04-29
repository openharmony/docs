# V1->V2迁移指导

## 概述
ArkUI状态管理的主要职责是：负责将可观察数据的变化自动同步到UI界面，实现数据驱动的UI刷新，使开发者能更加够专注于UI界面的实现和设计。

在状态管理框架的演进过程中，先后推出了状态管理V1和V2两个版本。V1强调组件层级的状态管理，而V2则增强了对数据对象的深度观察与管理能力，不再局限于组件层级。通过V2，开发者能够更灵活地控制数据和状态，实现更高效的UI刷新。具体V1和V2的区别可以参见[状态管理概述](./arkts-state-management-overview.md)。

## V1V2使用指引
1. V2是V1的增强版本，正在持续迭代优化来为开发者提供更多功能和灵活性。
2. 对于新开发的应用，建议直接使用V2版本范式来进行开发。
3. 对于已经使用V1的应用，如果V1的功能和性能已能满足需求，则不必立即切换到V2。
4. 对于需要在现阶段混用V1和V2的场景，请参阅[混用文档](./arkts-custom-component-mixed-scenarios.md)。编译器、工具链、IDE对某些不推荐的误用和混用场景会进行校验，虽然开发者可能可以通过特殊手段绕过这些校验，但还是强烈建议开发者遵循[混用文档](./arkts-custom-component-mixed-scenarios.md)的指导，避免因双重代理等问题给应用带来不确定性。

## 迁移指南的目的
1. 对希望将现有V1应用迁移到V2的开发者，提供系统化的模板和指导，帮助完成V1到V2的迁移。
2. 对希望逐步将V1应用过渡到V2的开发者，提供参考，结合本迁移文档与[混用文档](./arkts-custom-component-mixed-scenarios.md)，可以帮助开发者实现逐步改造。
3. 尚未开始开发应用但已熟悉V1状态管理规则的开发者，可以参考本迁移文档及V2各个装饰器和接口的文档，开始使用V2进行应用开发。

## V1V2能力对比及迁移简表
| V1装饰器名                | V2装饰器名                  | 说明 |
|------------------------|--------------------------|--------------------------|
| \@Observed              | \@ObservedV2              | 表明当前对象为可观察对象。但两者能力并不相同。 <br/>\@Observed可观察第一层的属性，需要搭配\@ObjectLink使用才能生效。 <br/>\@ObservedV2本身无观察能力，仅代表当前class可被观察，如果要观察其属性，需要搭配\@Trace使用。  |
| \@Track                 | \@Trace                   | V1装饰器\@Track为精确观察，不使用则无法做到类属性的精准观察。 <br/>V2\@Trace装饰的属性可以被精确跟踪观察。|
| \@Component             | \@ComponentV2             | \@Component为搭配V1状态变量使用的自定义组件装饰器。<br/>@ComponentV2为搭配V2状态变量使用的自定义组件装饰器。 |
|\@State                 | 无外部初始化：@Local<br/>外部初始化一次：\@Param\@Once | \@State和\@Local类似都是数据源的概念，在不需要外部传入初始化时，可直接迁移。如果需要外部传入初始化，则可以迁移为\@Param\@Once，详情见[@State->@Local](#state-local)。 |
| \@Prop                  | \@Param                   | \@Prop和\@Param类似都是自定义组件参数的概念。当输入参数为复杂类型时，\@Prop为深拷贝，\@Param为引用。 |
| \@Link                  | \@Param\@Event    | \@Link是框架自己封装实现的双向同步，对于V2开发者可以通过@Param@Event自己实现双向同步。 |
| \@ObjectLink            | \@Param                   | 直接兼容，\@ObjectLink需要被@Observed装饰的class的实例初始化，\@Param没有此限制。 |
| \@Provide               | \@Provider                | 兼容。 |
| \@Consume               | \@Consumer                | 兼容。 |
| \@Watch               | \@Monitor                | \@Watch用于监听V1状态变量的变化，具有监听状态变量本身和其第一层属性变化的能力。状态变量可观察到的变化会触发其\@Watch监听事件。<br/>\@Monitor用于监听V2状态变量的变化，搭配\@Trace使用，可有深层监听的能力。状态变量在一次事件中多次变化时，仅会以最终的结果判断是否触发\@Monitor监听事件。 |
| LocalStorage               | 全局\@ObservedV2\@Trace   | 兼容。 |
| AppStorage               | AppStorageV2   | 兼容。 |
| Environment       | 调用Ability接口获取系统环境变量   | Environment获取环境变量能力和AppStorage耦合。在V2中可直接调用Ability接口获取系统环境变量。 |
| PersistentStorage     | PersistenceV2   | PersistentStorage持久化能力和AppStorage耦合，PersistenceV2持久化能力可独立使用。 |

## 各装饰器迁移示例

### @State->@Local

#### 迁移规则
在V1中，\@State装饰器用于装饰组件内部的状态变量，在V2中提供了\@Local作为其替代能力，但两者在观察能力和初始化规则上存在明显差异。针对不同的使用场景，迁移策略如下：

- 简单类型：对于简单类型的变量，可以直接将\@State替换为\@Local。
- 复杂类型：V1中的@State可以观察复杂对象的第一层属性变化，而V2中的\@Local只能观察对象自身的变化。如果需要追踪对象内部的属性变化，可以结合使用\@ObservedV2和\@Trace。
- 外部初始化：V1中，\@State支持从外部传递初始值，但在V2中，\@Local禁止外部初始化。若需要从外部传递初始值，可以使用\@Param和\@Once装饰器来实现类似的效果。

#### 示例

**简单类型**

对于简单类型变量，V1的@State可以直接替换为V2的@Local。

V1：

```ts
@Entry
@Component
struct Child {
  @State val: number = 10;
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
  @Local val: number = 10;
  build(){
    Text(this.val.toString())
  }
}
```

**复杂类型**

V1的@State能够观察复杂对象的第一层属性变化，但V2的@Local无法观察对象内部变化。为了解决这个问题，需要在类上添加@ObservedV2，并在需要观察的属性上添加@Trace。这样，框架就能追踪对象内部的属性变化。

V1：

```ts
class Child {
  value: number = 10;
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
        .onClick(() => {
          this.child.value++;
        })
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
        .onClick(() => {
          this.child.value++;
        })
    }
  }
}
```

**外部初始化状态变量**

V1的@State变量可以从外部初始化，V2的@Local禁止外部初始化。为实现类似功能，需要用@Param和@Once代替@State，允许外部传入初始值，并确保该值只初始化时同步一次。

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

### @Link -> @Param/@Event

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
        .onClick(() => {
          this.val++;
        })
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
        .onClick(()=> { 
          this.addOne();
        })
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
- 复杂类型：如果传递的是复杂对象且需要严格的单向数据绑定，可以对对象进行深拷贝，防止子组件修改父组件的数据。
- 子组件修改变量：如果子组件需要修改传入的参数，可以使用@Once来允许子组件对在本地修改该变量。但需要注意，如果使用了\@Once，则代表当前子组件只会被初始化一次，后续并没有父组件到子组件的同步能力。

#### 示例

**简单类型**

对于简单类型变量，V1的@Prop可以直接替换为V2的@Param。

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
**复杂类型的单向数据传递**

在V2中，传递复杂类型时，如果希望实现严格的单向数据绑定，防止子组件修改父组件的数据，需要在使用@Param传递复杂对象时进行深拷贝以避免传递对象的引用。

V1实现：

```ts
class Fruit {
  apple: number = 5;
  orange: number = 10;
}

@Component
struct Child {
  // @Prop传递Fruit类，当子类修改属性，父类不受影响
  @Prop fruit: Fruit;
  build() {
    Column() {
      Text("child apple: "+ this.fruit.apple.toString())
      Text("child orange: "+ this.fruit.orange.toString())
      Button("apple+1")
        .onClick(() => {
          this.fruit.apple++;
        })
      Button("orange+1")
        .onClick(() => {
          this.fruit.orange++;
        })
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
        .onClick( ()=> {
          this.fruit.apple++;
        })
      Button("orange+1")
        .onClick(() => {
          this.fruit.orange++;
        })
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

**子组件修改变量**

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
        .onClick(()=> {
          this.value++;
        })
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
        .onClick(() => {
          this.value++;
        })
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

在V1中，子组件可以修改\@Prop的变量，且只会在本地更新，不会同步回父组件。父组件数据源更新时，会通知子组件更新，并覆写子组件本地\@Prop的值。

V1：
- 改变子组件`Child`的`localValue`，不会同步回父组件`Parent`。
- 父组件更新`value`，通知子组件`Child`更新，并覆写本地子组件`localValue`的值。

```ts
@Component
struct Child {
  @Prop localValue: number = 0;

  build() {
    Column() {
      Text(`${this.localValue}`).fontSize(25)
      Button('Child +100')
        .onClick(() => {
          // 改变localValue不会传递给父组件Parent
          this.localValue += 100;
        })
    }
  }
}

@Entry
@Component
struct Parent {
  @State value: number = 10;
  build() {
    Column() {
      Button('Parent +1')
        .onClick(() => {
          // 改变value的值，通知子组件Child value更新
          this.value += 1;
        })
      Child({ localValue: this.value })
    }
  }
}
```
V2中，\@Param本地不可写，和\@Once搭配使用只会同步一次。如果要实现子组件本地可写，且父组件后续更新还是能通知子组件，可以借助\@Monitor来实现这一效果。

V2实现：
- 父组件`Parent`更新通知子组件`value`的刷新，并回调\@Monitor修饰的`onValueChange`回调方法，`onValueChange`将更新后的值赋值给`localValue`。
- 子组件`Child`改变`localValue`的值，不会同步给父组件`Parent`。
- 父组件`Parent`中再次改变`value`，将会继续通知给子组件，并覆写子组件本地`localValue`的值。

```ts
@ComponentV2
struct Child {
  @Local localValue: number = 0;
  @Param value: number = 0;
  @Monitor('value')
  onValueChange(mon: IMonitor) {
    console.info(`value has been changed from ${mon.value()?.before} to ${mon.value()?.now}`);
    // 父组件value变化时，通知子组件value更新，回调Monitor函数，将更新的值覆写给本地的localValue
    this.localValue = this.value;
  }

  build() {
    Column() {
      Text(`${this.localValue}`).fontSize(25)
      Button('Child +100')
        .onClick(() => {
          // 改变localValue不会传递给父组件Parent
          this.localValue += 100;
        })
    }
  }
}

@Entry
@ComponentV2
struct Parent {
  @Local value: number = 10;
  build() {
    Column() {
      Button('Parent +1')
        .onClick(() => {
          // 改变value的值，通知子组件Child value更新
          this.value += 1;
        })
      Child({ value: this.value })
    }
  }
}
```

### @ObjectLink/@Observed/@Track -> @ObservedV2/@Trace
#### 迁移规则
在V1中，@Observed与@ObjectLink装饰器用于观察类对象及其嵌套属性的变化，但V1只能直接观察对象的第一层属性。对于嵌套对象的属性，必须通过自定义组件和@ObjectLink实现观察。此外，V1中提供了@Track装饰器来实现对属性级别变化的精确控制。

在V2中，@ObservedV2与@Trace结合使用，可以高效地实现类对象及其嵌套属性的深度观察，省去了对自定义组件的依赖，简化了开发流程。同时，@Trace装饰器还具备精确更新的能力，替代了V1中的@Track，从而实现更高效的UI刷新控制。根据不同的场景，有以下迁移策略：

- 嵌套对象的属性观察：V1中需要通过自定义组件和@ObjectLink观察嵌套属性，V2中则可以使用@ObservedV2和@Trace直接观察嵌套对象，简化了代码结构。
- 类属性的精确更新：V1中的@Track可以用V2中的@Trace取代，@Trace可以同时观察和精确更新属性变化，使代码更简洁高效。

#### 示例
**嵌套对象属性观察方法**

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
        .onClick(() => {
          this.address.city += "a";
        })
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
        .onClick(() => {
          this.user.address.city += "a";
        })
    }
  }
}
```
**类属性变化观测**

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
        .onClick(() => {
          this.user.age++;
        })
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
        .onClick(() => {
          this.user.age++;
        })
    }
  }
}
```

### @Provide/@Consume -> @Provider/@Consumer
#### 迁移规则
V1的@Provide/@Consume和V2@Provider/@Consumer定位和作用大体类似，基本可以实现丝滑替换，但是有以下细微差距，开发者可根据自己代码实现来参考是否需要调整：
在V1中，@Provide和@Consume用于父子组件之间的数据共享，可以通过alias（别名）或属性名匹配，同时@Consume必须依赖父组件的@Provide，不允许本地初始化。而V2中，@Provider和@Consumer增强了这些特性，使数据共享更加灵活。根据不同的场景，有以下迁移策略：

- V1中\@Provide/\@Consume在没有指定alias的情况下，可以直接使用。V2中\@Provider/\@Consumer是标准装饰器，且参数可选，所以不管有无指定alias后面需要必须跟随“()”。
- alias和属性名匹配规则：V1中，@Provide和@Consume可以通过alias或属性名匹配；V2中，alias是唯一的匹配key，指定alias后只能通过alias匹配。
- 本地初始化支持：V1中，@Consume不允许本地初始化，必须依赖父组件；V2中，@Consumer支持本地初始化，当找不到对应的@Provider时使用本地默认值。
- 从父组件初始化：V1中，@Provide可以直接从父组件初始化；V2中，@Provider不支持外部初始化，需用@Param和@Once接受初始值并赋给 @Provider。
- 重载支持：V1中，@Provide默认不支持重载，需设置 allowOverride；V2中，@Provider默认支持重载，@Consumer会向上查找最近的@Provider。
#### 示例
**alias和属性名匹配规则**

在V1中，@Provide和@Consume的匹配既可以通过alias，也可以通过属性名。在V2中，alias成为唯一的key，如果在@Consumer中制定了alias，只能通过alias而非属性名进行匹配。

V1实现:

```ts
@Component
struct Child {
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
struct Parent {
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
struct Child {
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
struct Parent {
  @Provider('text') message: string = "Hello World";
  build(){
    Column(){
      Child()
    }
  }
}
```

**V1的@Consume不支持本地初始化，V2支持**

V1中，@Consume不允许本地初始化变量，必须依赖父组件的@Provide，否则会抛出异常。迁移到V2后，@Consumer允许本地初始化，当找不到对应的@Provider，会使用本地默认值。

V1实现：

```ts
@Component
struct Child {
  // @Consume禁止本地初始化，当找不到对应的@Provide时抛出异常
  @Consume message: string;
  build(){
    Text(this.message)
  }
}

@Entry
@Component
struct Parent {
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
struct Child {
  // @Consumer允许本地初始化，当找不到@Provider的时候使用本地默认值
  @Consumer() message: string = "Hello World";
  build(){
    Text(this.message)
  }
}

@Entry
@ComponentV2
struct Parent {
  build(){
    Column(){
      Child()
    }
  }
}
```

**V1的@Provide可以从父组件初始化，V2不支持**

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

V2迁移策略：使用@Param接受初始值，再赋值给@Provider

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
  @Param @Once initialValue: number = 0;
  @Provider() childValue: number = this.initialValue;
  build() {
    Column(){
      Text(this.childValue.toString())
    }
  }
}
```

**V1的@Provide默认不支持重载，V2默认支持**

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
在V1中，\@Watch用于监听状态变量的变化，并在变量变化时触发指定回调函数。在V2中，\@Monitor替代了\@Watch，可以更灵活地监听变量的变化，并获取变量变化前后的值。具体的迁移策略如下：

- 单变量监听：对于简单的场景，可以直接用@Monitor替换@Watch，效果一致。
- 多变量监听：V1的@Watch无法获取变化前的值。在V2中，\@Monitor支持同时监听多个变量，并可以访问变量变化前后的状态。
#### 示例
**单变量监听**

对于简单案例，V1的@Watch可以直接替换为替换为V2的@Monitor。

V1实现：

```ts
@Entry
@Component
struct watchExample {
  @State @Watch('onAppleChange') apple: number = 0;
  onAppleChange(): void {
    console.log("apple count changed to "+this.apple);
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Button("add apple")
        .onClick(() => {
          this.apple++;
        })
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
    console.log(`apple changed from ${monitor.value()?.before} to ${monitor.value()?.now}`);
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Button("add apple")
        .onClick(()=> {
          this.apple++;
        })
    }
  }
}
```

**多变量监听**

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
    console.log("apple count changed to "+this.apple);
  }
  onOrangeChange(): void {
    console.log("orange count changed to "+this.orange);
  }

  build() {
    Column(){
      Text(`apple count: ${this.apple}`)
      Text(`orange count: ${this.orange}`)
      Button("add apple")
        .onClick(() => {
          this.apple++;
        })
      Button("add orange")
        .onClick(() => {
          this.orange++;
        })
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

  // @Monitor回调，支持监听多个变量，可以获取变化前的值
  @Monitor('apple','orange')
  onFruitChange(monitor: IMonitor) {
    monitor.dirty.forEach((name: string) => {
      console.log(`${name} changed from ${monitor.value(name)?.before} to ${monitor.value(name)?.now}`);
    });
  }

  build() {
    Column() {
      Text(`apple count: ${this.apple}`)
      Text(`orange count: ${this.orange}`)
      Button("add apple")
        .onClick(() => {
          this.apple++;
        })
      Button("add orange")
        .onClick(() => {
          this.orange++;
        })
    }
  }
}
```
### @Computed
#### 迁移规则
V1中并没有提供计算属性的概念，所以对于UI中的冗余计算，并没有办法可以减少重复计算。V2针对该场景，提供了@Computed装饰器，可以帮助开发者减少重复计算。

V1：
在下面的例子中，每次改变`lastName`都会触发Text组件的刷新，每次Text组件的刷新，都需要重复计算`this.lastName + ' ' + this.firstName`。
```
@Entry
@Component
struct Index {
  @State firstName: string = 'Li';
  @State lastName: string = 'Hua';

  build() {
    Column() {
      Text(this.lastName + ' ' + this.firstName)
      Text(this.lastName + ' ' + this.firstName)
      Button('changed lastName').onClick(() => {
        this.lastName += 'a';
      })

    }
  }
}
```

V2:
使用V2中的\@Computed，每次改变`lastName`仅会触发一次计算。

```
@Entry
@ComponentV2
struct Index {
  @Local firstName: string = 'Li';
  @Local lastName: string = 'Hua';

  @Computed
  get fullName() {
    return this.firstName + ' ' + this.lastName;
  }

  build() {
    Column() {
      Text(this.fullName)
      Text(this.fullName)
      Button('changed lastName').onClick(() => {
        this.lastName += 'a';
      })
    }
  }
}
```
### LocalStorage->全局@ObservedV2/@Trace
#### 迁移规则
LocalStorage的目的是为了实现页面间的状态变量共享。之所以提供这个能力，是因为V1状态变量和View层耦合，无法由开发者自主地实现页面间状态变量的共享。
对于状态管理V2，状态变量的观察能力内嵌到数据本身，不再和View层耦合，所以对于状态管理V2，不再需要类似LocalStorage的能力，可以使用全局@ObservedV2/@Trace，由开发者自己import和export，自己实现状态变量的页面间共享。

#### 示例
**基本场景**

V1:
通过windowStage.[loadContent](../../reference/apis-arkui/js-apis-window.md#loadcontent9)和[getShared](../../reference/apis-arkui/arkui-ts/ts-state-management.md#getshareddeprecated)接口实现页面间的状态变量共享。
```
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  para:Record<string, number> = { 'count': 47 };
  storage: LocalStorage = new LocalStorage(this.para);

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Page1', this.storage);
  }
}
```
在下面的示例中，使用\@LocalStorageLink，可以使得开发者本地的修改同步回LocalStorage中。

```
// Page1.ets
// 通过getShared接口获取stage共享的LocalStorage实例
@Entry(LocalStorage.getShared())
@Component
struct Page1 {
  @LocalStorageLink('count') count: number = 0;
  pageStack: NavPathStack = new NavPathStack();
  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

```
// Page2.ets
@Builder
export function Page2Builder() {
  Page2()
}

// Page2组件获得了父亲Page1组件的LocalStorage实例
@Component
struct Page2 {
  @LocalStorageLink('count') count: number = 0;
  pathStack: NavPathStack = new NavPathStack();
  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。
```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "LocalStorage example"
      }
    }
  ]
}
```
V2:
- 声明\@ObservedV2装饰的MyStorage类，并import需要使用的页面中。
- 声明被\@Trace的属性作为页面间共享的可观察的数据。

```
// storage.ets
@ObservedV2
export class MyStorage {
  static singleton_: MyStorage;
  static instance() {
    if(!MyStorage.singleton_) {
      MyStorage.singleton_ = new MyStorage();
    };
    return MyStorage.singleton_;
  }
  @Trace count: number = 47;
}
```

```
// Page1.ets
import { MyStorage } from './storage';

@Entry
@ComponentV2
struct Page1 {
  storage: MyStorage = MyStorage.instance();
  pageStack: NavPathStack = new NavPathStack();
  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

```
// Page2.ets
import { MyStorage } from './storage';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  storage: MyStorage = MyStorage.instance();
  pathStack: NavPathStack = new NavPathStack();
  build() {
    NavDestination() {
      Column() {
        Text(`${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
使用Navigation时，需要添加配置系统路由表文件src/main/resources/base/profile/route_map.json，并替换pageSourceFile为Page2页面的路径，并且在module.json5中添加："routerMap": "$profile:route_map"。
```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "LocalStorage example"
      }
    }
  ]
}
```

如果开发者需要实现类似于\@LocalStorageProp的效果，希望本地的修改不要同步回LocalStorage中，如以下示例:
- 在`Page1`中改变`count`值，因为count是\@LocalStorageProp装饰的，所以其改变只会在本地生效，并不会同步回LocalStorage。
- 点击`push to Page2`，跳转到`Page2`中。因为在`Page1`中改变`count`值并不会同步会LocalStorage，所以在`Page2`中Text组件依旧显示原本的值47。
- 点击`change Storage Count`，调用LocalStorage的setOrCreate，改变`count`对应的值，并通知所有绑定该key的变量。

```ts
// Page1.ets
export let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('count', 47);

@Entry(storage)
@Component
struct Page1 {
  @LocalStorageProp('count') count: number = 0;
  pageStack: NavPathStack = new NavPathStack();
  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            storage.setOrCreate('count', storage.get<number>('count') as number + 100);
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

```ts
// Page2.ets
import { storage } from './Page1'
@Builder
export function Page2Builder() {
  Page2()
}

// Page2组件获得了父亲Page1组件的LocalStorage实例
@Component
struct Page2 {
  @LocalStorageProp('count') count: number = 0;
  pathStack: NavPathStack = new NavPathStack();
  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            storage.setOrCreate('count', storage.get<number>('count') as number + 100);
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
在V2中，可以借助\@Local和\@Monitor实现类似的效果。
- \@Local装饰的`count`变量为组件本地的值，其改变不会同步回`storage`。
- \@Monitor监听`storage.count`的变化，当`storage.count`改变时，在\@Monitor的回调里改变本地\@Local的值。

```ts
// Page1.ets
import { MyStorage } from './storage';

@Entry
@ComponentV2
struct Page1 {
  storage: MyStorage = MyStorage.instance();
  pageStack: NavPathStack = new NavPathStack();
  @Local count: number = this.storage.count;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    console.log(`Page1 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }
  build() {
    Navigation(this.pageStack) {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            this.storage.count += 100;
          })
        Button('push to Page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })
      }
    }
  }
}
```

```ts
// Page2.ets
import { MyStorage } from './storage';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  storage: MyStorage = MyStorage.instance();
  pathStack: NavPathStack = new NavPathStack();
  @Local count: number = this.storage.count;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    console.log(`Page2 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }
  build() {
    NavDestination() {
      Column() {
        Text(`${this.count}`)
          .fontSize(50)
          .onClick(() => {
            this.count++;
          })
        Button('change Storage Count')
          .onClick(() => {
            this.storage.count += 100;
          })
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```

**自定义组件接收LocalStorage实例场景**

为了配合Navigation的场景，LocalStorage支持作为自定义组件的入参，传递给以当前自定义组件为根节点的所有子自定义组件。
对于该场景，V2可以采用多个全局\@ObservedV2/\@Trace实例来替代。

V1:
```ts
let localStorageA: LocalStorage = new LocalStorage();
localStorageA.setOrCreate('PropA', 'PropA');

let localStorageB: LocalStorage = new LocalStorage();
localStorageB.setOrCreate('PropB', 'PropB');

let localStorageC: LocalStorage = new LocalStorage();
localStorageC.setOrCreate('PropC', 'PropC');

@Entry
@Component
struct MyNavigationTestStack {
  @Provide('pageInfo') pageInfo: NavPathStack = new NavPathStack();

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      // 传递不同的LocalStorage实例
      pageOneStack({}, localStorageA)
    } else if (name === 'pageTwo') {
      pageTwoStack({}, localStorageB)
    } else if (name === 'pageThree') {
      pageThreeStack({}, localStorageC)
    }
  }

  build() {
    Column({ space: 5 }) {
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); //将name指定的NavDestination页面信息入栈
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
      .borderWidth(1)
    }
  }
}

@Component
struct pageOneStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropA') PropA: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        // 显示'PropA'
        NavigationContentMsgStack()
        // 显示'PropA'
        Text(`${this.PropA}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageTwoStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropB') PropB: string = 'Hello World';

  build() {
    NavDestination() {
      Column() {
        // 显示'Hello'，当前LocalStorage实例localStorageB没有PropA对应的值，使用本地默认值'Hello'
        NavigationContentMsgStack()
        // 显示'PropB'
        Text(`${this.PropB}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })

      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct pageThreeStack {
  @Consume('pageInfo') pageInfo: NavPathStack;
  @LocalStorageLink('PropC') PropC: string = 'pageThreeStack';

  build() {
    NavDestination() {
      Column() {
        // 显示'Hello'，当前LocalStorage实例localStorageC没有PropA对应的值，使用本地默认值'Hello'
        NavigationContentMsgStack()
        // 显示'PropC'
        Text(`${this.PropC}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })

      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
  }
}

@Component
struct NavigationContentMsgStack {
  @LocalStorageLink('PropA') PropA: string = 'Hello';

  build() {
    Column() {
      Text(`${this.PropA}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```
V2：

声明\@ObservedV2装饰的class代替LocalStorage。其中LocalStorage的key可以用\@Trace装饰的属性代替。
```ts
// storage.ets
@ObservedV2
export class MyStorageA {
  @Trace propA: string = 'Hello';
  constructor(propA?: string) {
      this.propA = propA? propA : this.propA;
  }
}

@ObservedV2
export class MyStorageB extends MyStorageA {
  @Trace propB: string = 'Hello';
  constructor(propB: string) {
    super();
    this.propB = propB;
  }
}

@ObservedV2
export class MyStorageC extends MyStorageA {
  @Trace propC: string = 'Hello';
  constructor(propC: string) {
    super();
    this.propC = propC;
  }
}
```

在`pageOneStack`、`pageTwoStack`和`pageThreeStack`组件内分别创建`MyStorageA`、`MyStorageB`、`MyStorageC`的实例，并通过\@Param传递给其子组件`NavigationContentMsgStack`，从而实现类似LocalStorage实例在子组件树上共享的能力。

```ts
// Index.ets
import { MyStorageA, MyStorageB, MyStorageC } from './storage';

@Entry
@ComponentV2
struct MyNavigationTestStack {
   pageInfo: NavPathStack = new NavPathStack();

  @Builder
  PageMap(name: string) {
    if (name === 'pageOne') {
      pageOneStack()
    } else if (name === 'pageTwo') {
      pageTwoStack()
    } else if (name === 'pageThree') {
      pageThreeStack()
    }
  }

  build() {
    Column({ space: 5 }) {
      Navigation(this.pageInfo) {
        Column() {
          Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
            .width('80%')
            .height(40)
            .margin(20)
            .onClick(() => {
              this.pageInfo.pushPath({ name: 'pageOne' }); //将name指定的NavDestination页面信息入栈
            })
        }
      }.title('NavIndex')
      .navDestination(this.PageMap)
      .mode(NavigationMode.Stack)
      .borderWidth(1)
    }
  }
}

@ComponentV2
struct pageOneStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageA: MyStorageA = new MyStorageA('PropA');

  build() {
    NavDestination() {
      Column() {
        // 显示'PropA'
        NavigationContentMsgStack({storage: this.storageA})
        // 显示'PropA'
        Text(`${this.storageA.propA}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageTwo', null);
          })
      }.width('100%').height('100%')
    }.title('pageOne')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct pageTwoStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageB: MyStorageB = new MyStorageB('PropB');

  build() {
    NavDestination() {
      Column() {
        // 显示'Hello'
        NavigationContentMsgStack({ storage: this.storageB })
        // 显示'PropB'
        Text(`${this.storageB.propB}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageThree', null);
          })

      }.width('100%').height('100%')
    }.title('pageTwo')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct pageThreeStack {
  pageInfo: NavPathStack = new NavPathStack();
  @Local storageC: MyStorageC = new MyStorageC("PropC");

  build() {
    NavDestination() {
      Column() {
        // 显示'Hello'
        NavigationContentMsgStack({ storage: this.storageC })
        // 显示'PropC'
        Text(`${this.storageC.propC}`)
        Button('Next Page', { stateEffect: true, type: ButtonType.Capsule })
          .width('80%')
          .height(40)
          .margin(20)
          .onClick(() => {
            this.pageInfo.pushPathByName('pageOne', null);
          })

      }.width('100%').height('100%')
    }.title('pageThree')
    .onBackPressed(() => {
      this.pageInfo.pop();
      return true;
    })
    .onReady((context: NavDestinationContext) => {
      this.pageInfo = context.pathStack;
    })
  }
}

@ComponentV2
struct NavigationContentMsgStack {
  @Require@Param storage: MyStorageA;

  build() {
    Column() {
      Text(`${this.storage.propA}`)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
    }
  }
}
```

### AppStorage->AppStorageV2
上一小节中，对于全局的@ObserveV2/@Trace的改造并不适合跨Ability的数据共享，该场景可以使用AppStorageV2来替换。

V1:
AppStorage是和应用进程绑定了，可以跨Ability实现数据共享。
在下面的示例中，使用\@StorageLink，可以使得开发者本地的修改同步回AppStorage中。

```
// EntryAbility Index.ets
import { common, Want } from '@kit.AbilityKit';
@Entry
@Component
struct Index {
  @StorageLink('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

```
// EntryAbility1 Index1.ets
import { common, Want } from '@kit.AbilityKit';
@Entry
@Component
struct Index1 {
  @StorageLink('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```
V2:
可以使用AppStorageV2实现跨Ability共享。
如下面示例：

```
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace count: number = 0
}

@Entry
@ComponentV2
struct Index {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.storage.count}`)
        .fontSize(50)
        .onClick(() => {
          this.storage.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}

```

```
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace count: number = 0
}

@Entry
@ComponentV2
struct Index1 {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    build() {
      Column() {
        Text(`EntryAbility1 count: ${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
        Button('Jump to EntryAbility').onClick(() => {
          let wantInfo: Want = {
            bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
            abilityName: 'EntryAbility'
          };
          this.context.startAbility(wantInfo);
        })
      }
    }
}
```

如果开发者需要实现类似于\@StorageProp的效果，希望本地的修改不要同步回AppStorage中，而AppStorage的变化又可以通知给使用\@StorageProp装饰器的组件，可以参考以下示例对比。

V1：

```ts
// EntryAbility Index.ets
import { common, Want } from '@kit.AbilityKit';
@Entry
@Component
struct Index {
  @StorageProp('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          AppStorage.setOrCreate('count', AppStorage.get<number>('count') as number + 100);
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

```ts
// EntryAbility1 Index1.ets
import { common, Want } from '@kit.AbilityKit';
@Entry
@Component
struct Index1 {
  @StorageProp('count') count: number = 0;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          AppStorage.setOrCreate('count', AppStorage.get<number>('count') as number + 100);
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

V2:
开发者可以借助\@Monitor和\@Local来实现类似的效果，示例如下。

```ts
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace count: number = 0;
}

@Entry
@ComponentV2
struct Index {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  @Local count: number = this.storage.count;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    console.log(`Index1 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }
  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          this.storage.count += 100;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility1'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

```ts
import { common, Want } from '@kit.AbilityKit';
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
export class MyStorage {
  @Trace count: number = 0;
}

@Entry
@ComponentV2
struct Index1 {
  @Local storage: MyStorage = AppStorageV2.connect(MyStorage, 'storage', () => new MyStorage())!;
  @Local count: number = this.storage.count;
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  @Monitor('storage.count')
  onCountChange(mon: IMonitor) {
    console.log(`Index1 ${mon.value()?.before} to ${mon.value()?.now}`);
    this.count = this.storage.count;
  }

  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(25)
        .onClick(() => {
          this.count++;
        })
      Button('change Storage Count')
        .onClick(() => {
          this.storage.count += 100;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication', // 替换成AppScope/app.json5里的bundleName
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```

### Environment->调用Ability接口直接获取系统环境变量
V1中，开发者可以通过Environment来获取环境变量，但Environment获取的结果无法直接使用，需要配合AppStorage才能得到对应环境变量的值。
在切换V2的过程中，开发者无需再通过Environment来获取环境变量，可以直接通过[UIAbilityContext的config属性](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#属性)获取系统环境变量。
V1:
以`languageCode`为例。
```ts
// 将设备languageCode存入AppStorage中
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';
  build() {
    Row() {
      Column() {
        // 输出当前设备的languageCode
        Text(this.languageCode)
      }
    }
  }
}
```

V2:
封装Env类型来传递多个系统环境变量。

```
// Env.ts
import { ConfigurationConstant } from '@kit.AbilityKit';

export class Env {
  language: string | undefined;
  colorMode: ConfigurationConstant.ColorMode | undefined;
  fontSizeScale: number | undefined;
  fontWeightScale: number | undefined;
}

export let env: Env = new Env();
```
在`onCreate`里获得需要的系统环境变量：
```
// EntryAbility.ets
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { env } from '../pages/Env';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    env.language = this.context.config.language;
    env.colorMode = this.context.config.colorMode;
    env.fontSizeScale = this.context.config.fontSizeScale;
    env.fontWeightScale = this.context.config.fontWeightScale;
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index');
  }
}

```
在页面中获得当前Env的值。
```
// Index.ets
import { env } from '../pages/Env';

@Entry
@ComponentV2
struct Index {
  build() {
    Row() {
      Column() {
        // 输出当前设备的环境变量
        Text(`languageCode: ${env.language}`).fontSize(20)
        Text(`colorMode: ${env.colorMode}`).fontSize(20)
        Text(`fontSizeScale: ${env.fontSizeScale}`).fontSize(20)
        Text(`fontWeightScale: ${env.fontWeightScale}`).fontSize(20)
      }
    }
  }
}
```

### PersistentStorage->PersistenceV2
V1中PersistentStorage提供了持久化UI数据的能力，而V2则提供了更加方便使用的PersistenceV2接口来替代它。
- PersistentStorage持久化的触发时机依赖AppStorage的观察能力，且与AppStorage耦合，开发者无法自主选择写入或读取持久化数据的时机。
- PersistentStorage使用序列化和反序列化，并没有传入类型，所以在持久化后，会丢失其类型，且对象的属性方法不能持久化。

对于PersistenceV2：
- 与PersistenceV2关联的\@ObservedV2对象，其\@Trace属性的变化，会触发整个关联对象的自动持久化。
- 开发者也可以调用[PersistenceV2.save](./arkts-new-persistencev2.md#save手动持久化数据)和[PersistenceV2.globalConnect](./arkts-new-persistencev2.md#使用globalconnect存储数据)接口来手动触发持久化写入和读取。

V1:

```ts
class data {
  name: string = 'ZhangSan';
  id: number = 0;
}

PersistentStorage.persistProp('numProp', 47);
PersistentStorage.persistProp('dataProp', new data());

@Entry
@Component
struct Index {
  @StorageLink('numProp') numProp: number = 48;
  @StorageLink('dataProp') dataProp: data = new data();

  build() {
    Column() {
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`numProp: ${this.numProp}`)
        .onClick(() => {
          this.numProp += 1;
        })
        .fontSize(30)

      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.name: ${this.dataProp.name}`)
        .onClick(() => {
          this.dataProp.name += 'a';
        })
        .fontSize(30)
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.id: ${this.dataProp.id}`)
        .onClick(() => {
          this.dataProp.id += 1;
        })
        .fontSize(30)

    }
    .width('100%')
  }
}
```

V2:

下面的案例展示了：
- 将`PersistentStorage`的持久化数据迁移到V2的PersistenceV2中去，其中V2对被@Trace标记的数据可以自动持久化，对于非@Trace数据需要开发者自己手动调用save进行持久化。
- 示例中的move函数和需要显示的组件放在了一个ets中，开发者可以定义自己的move函数，并放入合适的位置进行统一迁移操作。
```ts
// 迁移到globalConnect
import { PersistenceV2, Type } from '@kit.ArkUI';

// 接受序列化失败的回调
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

class Data {
  name: string = 'ZhangSan';
  id: number = 0;
}

@ObservedV2
class V2Data {
  @Trace name: string = '';
  @Trace Id: number = 1;
}

@ObservedV2
export class Sample {
  // 对于复杂对象需要@Type修饰，确保序列化成功
  @Type(V2Data)
  @Trace num: number = 1;
  @Trace V2: V2Data = new V2Data();
}

// 用于判断是否完成数据迁移的辅助数据
@ObservedV2
class StorageState {
  @Trace isCompleteMoving: boolean = false;
}

function move() {
  let movingState = PersistenceV2.globalConnect({type: StorageState, defaultCreator: () => new StorageState()})!;
  if (!movingState.isCompleteMoving) {
    PersistentStorage.persistProp('numProp', 47);
    PersistentStorage.persistProp('dataProp', new Data());
    let num = AppStorage.get<number>('numProp')!;
    let V1Data = AppStorage.get<Data>('dataProp')!;
    PersistentStorage.deleteProp('numProp');
    PersistentStorage.deleteProp('dataProp');

    // V2创建对应数据
    let migrate = PersistenceV2.globalConnect({type: Sample, key: 'connect2', defaultCreator: () => new Sample()})!;  // 使用默认构造函数也可以
    // 赋值数据，@Trace修饰的会自动保存，对于非@Trace对象，也可以调用save保存，如：PersistenceV2.save('connect2'); 
    migrate.num = num;
    migrate.V2.name = V1Data.name;
    migrate.V2.Id = V1Data.id;

    // 将迁移标志设置为true
    movingState.isCompleteMoving = true;
  }
}

move();

@Entry
@ComponentV2
struct Page1 {
  @Local refresh: number = 0;
  // 使用key:connect2存入数据
  @Local p: Sample = PersistenceV2.globalConnect({type: Sample, key:'connect2', defaultCreator:() => new Sample()})!;

  build() {
    Column({space: 5}) {
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`numProp: ${this.p.num}`)
        .onClick(() => {
          this.p.num += 1;
        })
        .fontSize(30)

      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.name: ${this.p.V2.name}`)
        .onClick(() => {
          this.p.V2.name += 'a';
        })
        .fontSize(30)
      // 应用退出时会保存当前结果。重新启动后，会显示上一次的保存结果
      Text(`dataProp.id: ${this.p.V2.Id}`)
        .onClick(() => {
          this.p.V2.Id += 1;
        })
        .fontSize(30)
    }
    .width('100%')
  }
}
```

## 存量迁移场景

对于已经使用V1开发的大型应用，一般不太可能做到一次性的从V1迁移到V2，而是分批次和分组件的部分迁移，这就必然会带来V1和V2的混用。

这种场景，一般是父组件是状态管理V1，而迁移的子组件为状态管理V2。为了模拟这种场景，我们举出下面的示例：
- 父组件是\@Component，数据源是\@LocalStorageLink。
- 子组件是\@ComponentV2，使用\@Param接受数据源的数据。

这种情况，我们可以通过以下策略进行迁移：
- 声明一个\@ObservedV2装饰的class来封装V1的数据。
- 在\@Component和\@ComponentV2之间，定义一个桥接的\@Component自定义组件。
- 在桥接层：
    - V1->V2的数据同步，可通过\@Watch的监听触发\@ObservedV2装饰的class的属性的赋值。
    - V2->V1的数据同步，可通过在\@ObservedV2装饰的class里声明Monitor，通过LocalStorage的API反向通知给V1状态变量。

具体示例如下：
```
let storage: LocalStorage = new LocalStorage();

@ObservedV2
class V1StorageData {
  @Trace title: string = 'V1OldComponent'
  @Monitor('title')
  onStrChange(monitor: IMonitor) {
    monitor.dirty.forEach((path: string) => {
      console.log(`${path} changed from ${monitor.value(path)?.before} to ${monitor.value(path)?.now}`)
      if (path === 'title') {
        storage.setOrCreate('title', this.title);
      }
    })
  }
}
let v1Data: V1StorageData = new V1StorageData();

@Entry(storage)
@Component
struct V1OldComponent {
  @LocalStorageLink('title') title: string = 'V1OldComponent';

  build() {
    Column() {
      Text(`V1OldComponent: ${this.title}`)
        .fontSize(20)
        .onClick(() => {
          this.title = 'new value from V1OldComponent';
        })
      Bridge()
    }
  }
}


@Component
struct Bridge {
  @LocalStorageLink('title')@Watch('titleWatch') title: string = 'Bridge';
  titleWatch() {
    v1Data.title = this.title;
  }

  build() {
    NewV2Component()
  }
}
@ComponentV2
struct NewV2Component {
  build() {
    Column() {
      Text(`NewV2Component: ${v1Data.title}`)
        .fontSize(20)
        .onClick(() => {
          v1Data.title = 'NewV2Component';
        })
    }
  }
}
```

## 其他迁移场景

### 滑动组件

#### List

开发者可以通过[ChildrenMainSize](../../reference/apis-arkui/arkui-ts/ts-container-list.md#childrenmainsize12)来设置List的子组件在主轴方向的大小信息。

V1：

在状态管理V1中，可以通过[\@State](./arkts-state.md)装饰观察其api调用。

具体示例如下：

```ts
@Entry
@Component
struct ListExample {
  private arr: Array<number> = new Array(10).fill(0);
  private scroller: ListScroller = new ListScroller();
  @State listSpace: number = 10;
  @State listChildrenSize: ChildrenMainSize = new ChildrenMainSize(100);

  build() {
    Column() {
      Button('change Default').onClick(() => {
        this.listChildrenSize.childDefaultSize += 10;
      })

      Button('splice 5').onClick(() => {
        this.listChildrenSize.splice(0, 5, [100, 100, 100, 100, 100]);
      })

      Button('update 5').onClick(() => {
        this.listChildrenSize.update(0, 200);
      })

      List({ space: this.listSpace, scroller: this.scroller }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text(`item-` + item)
          }.backgroundColor(Color.Pink)
        })
      }
      .childrenMainSize(this.listChildrenSize) // 10
    }
  }
}
```

V2：

但在状态管理V2中，[\@Local](./arkts-new-local.md)只能观察本身的变化，无法观察第一层的变化，又因为ChildrenMainSize定义在框架中，开发者无法使用[\@Trace](./arkts-new-observedV2-and-trace.md)来标注ChildrenMainSize的属性，此时可以使用[makeObserved](./arkts-new-makeObserved.md)替代。

具体示例如下：

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct ListExample {
  private arr: Array<number> = new Array(10).fill(0);
  private scroller: ListScroller = new ListScroller();
  listSpace: number = 10;
  // 使用makeObserved的能力来观测ChildrenMainSize
  listChildrenSize: ChildrenMainSize = UIUtils.makeObserved(new ChildrenMainSize(100));

  build() {
    Column() {
      Button('change Default').onClick(() => {
        this.listChildrenSize.childDefaultSize += 10;
      })

      Button('splice 5').onClick(() => {
        this.listChildrenSize.splice(0, 5, [100, 100, 100, 100, 100]);
      })

      Button('update 5').onClick(() => {
        this.listChildrenSize.update(0, 200);
      })

      List({ space: this.listSpace, scroller: this.scroller }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text(`item-` + item)
          }.backgroundColor(Color.Pink)
        })
      }
      .childrenMainSize(this.listChildrenSize) // 10
    }
  }
}
```

#### WaterFlow

开发者可以通过[WaterFlowSections](../../reference/apis-arkui/arkui-ts/ts-container-waterflow.md#waterflowsections12)来设置WaterFlow瀑布流分组信息。

需要注意的是，数组arr的长度需要与WaterFlowSections的中所有SectionOptions的itemsCount的总和保持一致，否则WaterFlow无法处理，导致UI不刷新。

以下两个示例请按照'push option' -> 'splice option' -> 'update option'的顺序进行点击。

V1：

在状态管理V1中，可以通过[\@State](./arkts-state.md)装饰观察其api调用。

具体示例如下：

```ts
@Entry
@Component
struct WaterFlowSample {
  @State colors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Blue, Color.Pink];
  @State sections: WaterFlowSections = new WaterFlowSections();
  scroller: Scroller = new Scroller();
  @State private arr: Array<number> = new Array(9).fill(0);
  oneColumnSection: SectionOptions = {
    itemsCount: 4,
    crossCount: 1,
    columnsGap: '5vp',
    rowsGap: 10,
  };
  twoColumnSection: SectionOptions = {
    itemsCount: 2,
    crossCount: 2,
  };
  lastSection: SectionOptions = {
    itemsCount: 3,
    crossCount: 3,
  };

  aboutToAppear(): void {
    let sectionOptions: SectionOptions[] = [this.oneColumnSection, this.twoColumnSection, this.lastSection];
    this.sections.splice(0, 0, sectionOptions);
  }

  build() {
    Column() {
      Text(`${this.arr.length}`)

      Button('push option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 1,
          crossCount: 1,
        };
        this.sections.push(section);
        this.arr.push(100);
      })

      Button('splice option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 8,
          crossCount: 2,
        };
        this.sections.splice(0, this.arr.length, [section]);
        this.arr = new Array(8).fill(10);
      })

      Button('update option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 8,
          crossCount: 2,
        };
        this.sections.update(1, section);
        this.arr = new Array(16).fill(1);
      })

      WaterFlow({ scroller: this.scroller, sections: this.sections }) {
        ForEach(this.arr, (item: number) => {
          FlowItem() {
            Text(`${item}`)
              .border({ width: 1 })
              .backgroundColor(this.colors[item % 6])
              .height(30)
              .width(50)
          }
        })
      }
    }
  }
}
```

V2：

但在状态管理V2中，[\@Local](./arkts-new-local.md)只能观察本身的变化，无法观察第一层的变化，又因为WaterFlowSections定义在框架中，开发者无法使用[\@Trace](./arkts-new-observedV2-and-trace.md)来标注WaterFlowSections的属性，此时可以使用[makeObserved](./arkts-new-makeObserved.md)替代。

具体示例如下：

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct WaterFlowSample {
  colors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Blue, Color.Pink];
  // 使用makeObserved的能力来观测WaterFlowSections
  sections: WaterFlowSections = UIUtils.makeObserved(new WaterFlowSections());
  scroller: Scroller = new Scroller();
  @Local private arr: Array<number> = new Array(9).fill(0);
  oneColumnSection: SectionOptions = {
    itemsCount: 4,
    crossCount: 1,
    columnsGap: '5vp',
    rowsGap: 10,
  };
  twoColumnSection: SectionOptions = {
    itemsCount: 2,
    crossCount: 2,
  };
  lastSection: SectionOptions = {
    itemsCount: 3,
    crossCount: 3,
  };

  aboutToAppear(): void {
    let sectionOptions: SectionOptions[] = [this.oneColumnSection, this.twoColumnSection, this.lastSection];
    this.sections.splice(0, 0, sectionOptions);
  }

  build() {
    Column() {
      Text(`${this.arr.length}`)

      Button('push option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 1,
          crossCount: 1,
        };
        this.sections.push(section);
        this.arr.push(100);
      })

      Button('splice option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 8,
          crossCount: 2,
        };
        this.sections.splice(0, this.arr.length, [section]);
        this.arr = new Array(8).fill(10);
      })

      Button('update option').onClick(() => {
        let section: SectionOptions = {
          itemsCount: 8,
          crossCount: 2,
        };
        this.sections.update(1, section);
        this.arr = new Array(16).fill(1);
      })

      WaterFlow({ scroller: this.scroller, sections: this.sections }) {
        ForEach(this.arr, (item: number) => {
          FlowItem() {
            Text(`${item}`)
              .border({ width: 1 })
              .backgroundColor(this.colors[item % 6])
              .height(30)
              .width(50)
          }
        })
      }
    }
  }
}
```

### Modifier

#### attributeModifier

开发者可以通过[attributeModifier](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#attributemodifier)动态设置组件的属性方法。

V1：

在状态管理V1中，可以通过[\@State](./arkts-state.md)装饰观察其变化。

具体示例如下：

```ts
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  isDark: boolean = false;

  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.isDark) {
      instance.backgroundColor(Color.Black);
    } else {
      instance.backgroundColor(Color.Red);
    }
  }
}

@Entry
@Component
struct AttributeDemo {
  @State modifier: MyButtonModifier = new MyButtonModifier();

  build() {
    Row() {
      Column() {
        Button('Button')
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.isDark = !this.modifier.isDark;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

V2：

但在状态管理V2中，[\@Local](./arkts-new-local.md)只能观察本身的变化，无法观察第一层的变化，如果要观察attributeModifier的属性变化，可以使用[makeObserved](./arkts-new-makeObserved.md)替代。

具体示例如下：

```ts
import { UIUtils } from '@kit.ArkUI';

class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  isDark: boolean = false;

  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.isDark) {
      instance.backgroundColor(Color.Black);
    } else {
      instance.backgroundColor(Color.Red);
    }
  }
}

@Entry
@ComponentV2
struct AttributeDemo {
  // 使用makeObserved的能力观测attributeModifier的属性this.modifier
  modifier: MyButtonModifier = UIUtils.makeObserved(new MyButtonModifier());

  build() {
    Row() {
      Column() {
        Button('Button')
          .attributeModifier(this.modifier)
          .onClick(() => {
            this.modifier.isDark = !this.modifier.isDark;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

#### CommonModifier

动态设置组件的属性类。以[CommonModifier](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#自定义modifier)为例。

V1：

在状态管理V1中，可以通过[\@State](./arkts-state.md)装饰观察其变化。

具体实例如下：

```ts
import { CommonModifier } from '@ohos.arkui.modifier';

class MyModifier extends CommonModifier {
  applyNormalAttribute(instance: CommonAttribute): void {
    super.applyNormalAttribute?.(instance);
  }

  public setGroup1(): void {
    this.borderStyle(BorderStyle.Dotted);
    this.borderWidth(8);
  }

  public setGroup2(): void {
    this.borderStyle(BorderStyle.Dashed);
    this.borderWidth(8);
  }
}

@Component
struct MyImage1 {
  @Link modifier: CommonModifier;

  build() {
    // 此处'app.media.app_icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
    Image($r('app.media.app_icon'))
      .attributeModifier(this.modifier as MyModifier)
  }
}

@Entry
@Component
struct Index {
  @State myModifier: CommonModifier = new MyModifier().width(100).height(100).margin(10);
  index: number = 0;

  build() {
    Column() {
      Button($r('app.string.EntryAbility_label'))
        .margin(10)
        .onClick(() => {
          console.log('Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.myModifier as MyModifier).setGroup1();
            console.log('Modifier', 'setGroup1');
          } else {
            (this.myModifier as MyModifier).setGroup2();
            console.log('Modifier', 'setGroup2');
          }
        })

      MyImage1({ modifier: this.myModifier })
    }
    .width('100%')
  }
}
```

V2：

但在状态管理V2中，[\@Local](./arkts-new-local.md)只能观察本身的变化，无法观察第一层的变化，又因为[CommonModifier](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#自定义modifier)在框架内是通过其属性触发刷新，此时可以使用[makeObserved](./arkts-new-makeObserved.md)替代。

具体示例如下：

```ts
import { UIUtils } from '@kit.ArkUI';
import { CommonModifier } from '@ohos.arkui.modifier';

class MyModifier extends CommonModifier {
  applyNormalAttribute(instance: CommonAttribute): void {
    super.applyNormalAttribute?.(instance);
  }

  public setGroup1(): void {
    this.borderStyle(BorderStyle.Dotted);
    this.borderWidth(8);
  }

  public setGroup2(): void {
    this.borderStyle(BorderStyle.Dashed);
    this.borderWidth(8);
  }
}

@ComponentV2
struct MyImage1 {
  @Param @Require modifier: CommonModifier;

  build() {
    // 此处'app.media.app_icon'仅作示例，请开发者自行替换，否则imageSource创建失败会导致后续无法正常执行。
    Image($r('app.media.app_icon'))
      .attributeModifier(this.modifier as MyModifier)
  }
}

@Entry
@ComponentV2
struct Index {
  // 使用makeObserved的能力来观测CommonModifier
  @Local myModifier: CommonModifier = UIUtils.makeObserved(new MyModifier().width(100).height(100).margin(10));
  index: number = 0;

  build() {
    Column() {
      Button($r('app.string.EntryAbility_label'))
        .margin(10)
        .onClick(() => {
          console.log('Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.myModifier as MyModifier).setGroup1();
            console.log('Modifier', 'setGroup1');
          } else {
            (this.myModifier as MyModifier).setGroup2();
            console.log('Modifier', 'setGroup2');
          }
        })

      MyImage1({ modifier: this.myModifier })
    }
    .width('100%')
  }
}
```

#### 组件Modfier

动态设置组件的属性类。以Text组件为例。

V1：

在状态管理V1中，可以通过[\@State](./arkts-state.md)装饰观察其变化。

具体示例如下：

```ts
import { TextModifier } from '@ohos.arkui.modifier';

class MyModifier extends TextModifier {
  applyNormalAttribute(instance: TextModifier): void {
    super.applyNormalAttribute?.(instance);
  }

  public setGroup1(): void {
    this.fontSize(50);
    this.fontColor(Color.Pink);
  }

  public setGroup2(): void {
    this.fontSize(50);
    this.fontColor(Color.Gray);
  }
}

@Component
struct MyImage1 {
  @Link modifier: TextModifier;
  index: number = 0;

  build() {
    Column() {
      Text('Test')
        .attributeModifier(this.modifier as MyModifier)

      Button($r('app.string.EntryAbility_label'))
        .margin(10)
        .onClick(() => {
          console.log('Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.modifier as MyModifier).setGroup1();
            console.log('Modifier', 'setGroup1');
          } else {
            (this.modifier as MyModifier).setGroup2();
            console.log('Modifier', 'setGroup2');
          }
        })
    }
  }
}

@Entry
@Component
struct Index {
  @State myModifier: TextModifier = new MyModifier().width(100).height(100).margin(10);
  index: number = 0;

  build() {
    Column() {
      MyImage1({ modifier: this.myModifier })

      Button('replace whole')
        .margin(10)
        .onClick(() => {
          this.myModifier = new MyModifier().backgroundColor(Color.Orange);
        })
    }
    .width('100%')
  }
}
```

V2：

但在状态管理V2中，[\@Local](./arkts-new-local.md)只能观察本身的变化，无法观察第一层的变化，此时可以使用[makeObserved](./arkts-new-makeObserved.md)替代。

具体示例如下：

```ts
import { UIUtils } from '@kit.ArkUI';
import { TextModifier } from '@ohos.arkui.modifier';

class MyModifier extends TextModifier {
  applyNormalAttribute(instance: TextModifier): void {
    super.applyNormalAttribute?.(instance);
  }

  public setGroup1(): void {
    this.fontSize(50);
    this.fontColor(Color.Pink);
  }

  public setGroup2(): void {
    this.fontSize(50);
    this.fontColor(Color.Gray);
  }
}

@ComponentV2
struct MyImage1 {
  @Param @Require modifier: TextModifier;
  index: number = 0;

  build() {
    Column() {
      Text('Test')
        .attributeModifier(this.modifier as MyModifier)

      Button($r('app.string.EntryAbility_label'))
        .margin(10)
        .onClick(() => {
          console.log('Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.modifier as MyModifier).setGroup1();
            console.log('Modifier', 'setGroup1');
          } else {
            (this.modifier as MyModifier).setGroup2();
            console.log('Modifier', 'setGroup2');
          }
        })
    }
  }
}

@Entry
@ComponentV2
struct Index {
  // 使用makeObserved的能力观测TextModifier
  @Local myModifier: TextModifier = UIUtils.makeObserved(new MyModifier().width(100).height(100).margin(10));
  index: number = 0;

  build() {
    Column() {
      MyImage1({ modifier: this.myModifier })

      Button('replace whole')
        .margin(10)
        .onClick(() => {
          this.myModifier = UIUtils.makeObserved(new MyModifier().backgroundColor(Color.Orange));
        })
    }
    .width('100%')
  }
}
```
