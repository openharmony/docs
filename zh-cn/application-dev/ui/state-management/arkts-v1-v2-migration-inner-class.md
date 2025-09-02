# 数据对象状态变量的迁移指导

本文档主要介绍数据对象内的状态变量的迁移场景，包含以下场景。
| V1装饰器名                | V2装饰器名                  |
|------------------------|--------------------------|
|[\@ObjectLink](./arkts-observed-and-objectlink.md)/[\@Observed](./arkts-observed-and-objectlink.md) /[\@Track](./arkts-track.md)|[\@ObservedV2](./arkts-new-observedV2-and-trace.md)/[\@Trace](./arkts-new-observedV2-and-trace.md)|

## 各装饰器迁移示例

### \@ObjectLink/\@Observed/\@Track -> \@ObservedV2/\@Trace
**迁移规则**

在V1中，\@Observed与\@ObjectLink装饰器用于观察类对象及其嵌套属性的变化，但V1只能直接观察对象的第一层属性。对于嵌套对象的属性，必须通过自定义组件和\@ObjectLink实现观察。此外，V1中提供了@Track装饰器来实现对属性级别变化的精确控制。

在V2中，\@ObservedV2与\@Trace结合使用，可以高效地实现类对象及其嵌套属性的深度观察，省去了对自定义组件的依赖，简化了开发流程。同时，\@Trace装饰器还具备精确更新的能力，替代了V1中的@Track，从而实现更高效的UI刷新控制。根据不同的场景，有以下迁移策略：

- 嵌套对象的属性观察：V1中需要通过自定义组件和\@ObjectLink观察嵌套属性，V2中则可以使用\@ObservedV2和\@Trace直接观察嵌套对象，简化了代码结构。
- 类属性的精确更新：V1中的\@Track可以用V2中的\@Trace取代，\@Trace可以同时观察和精确更新属性变化，使代码更简洁高效。

**示例**

**嵌套对象属性观察方法**

在V1中，无法直接观察嵌套对象的属性变化，只能观察到第一层属性的变化。必须通过创建自定义组件并使用\@ObjectLink来实现对嵌套属性的观察。V2中使用\@ObservedV2和\@Trace，可以直接对嵌套对象的属性进行深度观察，减少复杂度。

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

V2迁移策略：使用\@ObservedV2和\@Trace。

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

在V1中，\@Observed用于观察类实例及其属性的变化，\@Track用于类对象的属性级的观察。在V2中，\@Trace实现了观察和更新属性级别变化的能力，搭配\@ObservedV2实现高效的UI更新。

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

V2迁移策略：使用\@ObservedV2和\@Trace。

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
