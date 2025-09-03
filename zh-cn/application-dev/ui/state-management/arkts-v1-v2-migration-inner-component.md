# 组件内状态变量迁移指导

本文档主要介绍数据组件内的状态变量的迁移场景，包含以下场景。
| V1装饰器名                | V2装饰器名                  |
|------------------------|--------------------------|
| [\@State](./arkts-state.md)                 | 无外部初始化：[\@Local](./arkts-new-local.md)<br/>外部初始化一次：[\@Param](./arkts-new-param.md)[\@Once](./arkts-new-once.md) |
| [\@Prop](./arkts-prop.md)                   | [\@Param](./arkts-new-param.md)                   |
| [\@Link](./arkts-link.md)                  | [\@Param](./arkts-new-param.md)[\@Event](./arkts-new-event.md)    |
|  [\@ObjectLink](./arkts-observed-and-objectlink.md)           |[\@Param](./arkts-new-param.md)[\@Event](./arkts-new-event.md)                   |
|  [\@Provide](./arkts-provide-and-consume.md)               |[\@Provider](./arkts-new-Provider-and-Consumer.md)                | 
| [\@Consume](./arkts-provide-and-consume.md)               |[\@Consumer](./arkts-new-Provider-and-Consumer.md)                |
| [\@Watch](./arkts-watch.md)               |[\@Monitor](./arkts-new-monitor.md)                |
| 无计算属性相关能力，需要重复计算 | [\@Computed](./arkts-new-Computed.md)                |

## 各装饰器迁移示例

### @State->@Local

**迁移规则**

在V1中，\@State装饰器用于装饰组件内部的状态变量，在V2中提供了\@Local作为其替代能力，但两者在观察能力和初始化规则上存在明显差异。针对不同的使用场景，迁移策略如下：

- 简单类型：对于简单类型的变量，可以直接将\@State替换为\@Local。
- 复杂类型：V1中的@State可以观察复杂对象的第一层属性变化，而V2中的\@Local只能观察对象自身的变化。如果需要追踪对象内部的属性变化，可以结合使用\@ObservedV2和\@Trace。
- 外部初始化：V1中，\@State支持从外部传递初始值，但在V2中，\@Local禁止外部初始化。若需要从外部传递初始值，可以使用\@Param和\@Once装饰器来实现类似的效果。

**示例**

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

**迁移规则**

在V1中，@Link允许父组件和子组件之间进行双向数据绑定。迁移到V2时，可以用@Param和@Event模拟双向同步。@Param实现父到子的单向传递，子组件再通过@Event回调函数触发父组件的状态更新。

**示例**

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

V2迁移策略：使用@Param和@Event。

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

**迁移规则**

在V1中，@Prop装饰器用于从父组件传递参数给子组件，这些参数在子组件中可以被直接修改。在V2中，@Param取代了@Prop的作用，但@Param是只读的，子组件不能直接修改参数的值。因此，根据场景的不同，有几种迁移策略：

- 简单类型：对于简单类型的参数，可以直接将@Prop替换为@Param。
- 复杂类型：如果传递的是复杂对象且需要严格的单向数据绑定，可以对对象进行深拷贝，防止子组件修改父组件的数据。
- 子组件修改变量：如果子组件需要修改传入的参数，可以使用@Once来允许子组件对在本地修改该变量。但需要注意，如果使用了\@Once，则代表当前子组件只会被初始化一次，后续并没有父组件到子组件的同步能力。

**示例**

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

V2迁移策略：直接替换。

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

V2迁移策略：使用深拷贝。

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

V2迁移策略：使用@Param和@Once。

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

### @Provide/@Consume -> @Provider/@Consumer
**迁移规则**

V1的@Provide/@Consume和V2@Provider/@Consumer定位和作用大体类似，基本可以实现丝滑替换，但是有以下细微差距，开发者可根据自己代码实现来参考是否需要调整：
在V1中，@Provide和@Consume用于父子组件之间的数据共享，可以通过alias（别名）或属性名匹配，同时@Consume必须依赖父组件的@Provide，不允许本地初始化。而V2中，@Provider和@Consumer增强了这些特性，使数据共享更加灵活。根据不同的场景，有以下迁移策略：

- V1中\@Provide/\@Consume在没有指定alias的情况下，可以直接使用。V2中\@Provider/\@Consumer是标准装饰器，且参数可选，所以不管有无指定alias后面需要必须跟随“()”。
- alias和属性名匹配规则：V1中，@Provide和@Consume可以通过alias或属性名匹配；V2中，alias是唯一的匹配key，指定alias后只能通过alias匹配。
- 本地初始化支持：API version 20以前，@Consume不允许本地初始化，必须依赖父组件；从API version 20开始，@Consume支持本地初始化，当找不到对应的@Provide时使用本地默认值；V2中，@Consumer支持本地初始化，当找不到对应的@Provider时使用本地默认值。
- 从父组件初始化：V1中，@Provide可以直接从父组件初始化；V2中，@Provider不支持外部初始化，需用@Param和@Once接受初始值并赋给 @Provider。
- 重载支持：V1中，@Provide默认不支持重载，需设置 allowOverride；V2中，@Provider默认支持重载，@Consumer会向上查找最近的@Provider。
**示例**

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

V2迁移策略：确保alias一致，没有指定alias的情况下，依赖属性名进行匹配。

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

V2迁移策略：@Consumer可以本地初始化。

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

V2迁移策略：使用@Param接受初始值，再赋值给@Provider。

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

V2迁移策略：去掉allowOverride。

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
**迁移规则**

在V1中，\@Watch用于监听状态变量的变化，并在变量变化时触发指定回调函数。在V2中，\@Monitor替代了\@Watch，可以更灵活地监听变量的变化，并获取变量变化前后的值。具体的迁移策略如下：

- 单变量监听：对于简单的场景，可以直接用@Monitor替换@Watch，效果一致。
- 多变量监听：V1的@Watch无法获取变化前的值。在V2中，\@Monitor支持同时监听多个变量，并可以访问变量变化前后的状态。
**示例**

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

V2迁移策略：直接替换。

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

V2迁移策略：同时监听多个变量，以及获取变化前的值。

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
**迁移规则**

V1中并没有提供计算属性的概念，所以对于UI中的冗余计算，并没有办法可以减少重复计算。V2针对该场景，提供了@Computed装饰器，可以帮助开发者减少重复计算。

V1：

在下面的例子中，每次改变`lastName`都会触发Text组件的刷新，每次Text组件的刷新，都需要重复计算`this.lastName + ' ' + this.firstName`。

```ts
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

```ts
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