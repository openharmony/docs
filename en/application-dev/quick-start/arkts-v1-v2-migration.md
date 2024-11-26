# Migrating Application from V1 to V2

## Overview
ArkUI state management automatically synchronizes observable data changes to the UI to implement data-driven UI re-render, enabling you to focus on UI implementation and design.

During the evolution of the state management framework, state management V1 and V2 are released. V1 emphasizes state management of the components, while V2 enhances the in-depth observation and management of data objects. With V2, you can control data and state more flexibly, facilitating a more efficient UI re-render. For details about the differences between V1 and V2, see [State Management Overview](./arkts-state-management-overview.md).

## How to Use
1. V2 is an enhanced version of V1 and provides more functions and flexibility.
2. For new applications, you are advised to use V2 for development.
3. If the functions and performance of the application can meet the requirements in V1, you do not need to migrate the application to V2 immediately. However, if you cannot observe data changes in a lower level during development, it is recommended that you migrate the application to V2 as soon as possible to achieve smooth application transition and improvement in the future.
4. For details about the mixed use of V1 and V2, see [Mixing Use of Custom Components](./arkts-custom-component-mixed-scenarios.md). The compiler, toolchain, and DevEco Studio can verify some misuse and mixed use scenarios that are not recommended. Although you may bypass these verifications using special methods, you are still advised to follow the guidelines in [Mixing Use of Custom Components](./arkts-custom-component-mixed-scenarios.md) to avoid uncertainty caused by dual proxies.

## Purpose
1. For developers who want to migrate applications from V1 to V2, this document provides systematic templates and guidance.
2. For developers who want to gradually transition applications from V1 to V2, this document together with [Mixing Use of Custom Components](./arkts-custom-component-mixed-scenarios.md) provide guidelines and reference.
3. For developers who have not started to develop applications but are familiar with the state management of V1, this document and documents of the decorators and APIs of V2 provide reference for application development in V2.

## Capability Comparison and Migration Between V1 and V2
| V1 Decorator               | V2 Decorator                 | Description|
|------------------------|--------------------------|--------------------------|
| \@Observed              | \@ObservedV2              | Indicates that this object is an observable object. However, they have different capabilities.<br>\@Observed is used to observe the top-level properties and it takes effect only when it is used together with \@ObjectLink.<br>\@ObservedV2 does not have the observation capability. It only indicates that this class is observable. To observe the class properties, use together with \@Trace. |
| \@Track                 | \@Trace                   | \@Track is used for accurate observation. If it is not used, class properties cannot be accurately observed.<br>\@Trace decorated properties can be accurately traced and observed.|
| \@Component             | \@ComponentV2             | \@Component is the custom component decorator used with the state variables of V1.<br>@ComponentV2 is the custom component decorator used with the state variables of V2.|
|\@State                 | No external initialization: @Local<br>External initialization once: \@Param and \@Once| Similar to \@Local, \@State decorated variables can work as the data source which can be directly migrated without external initialization. If the external initialization is required, use \@Param and \@Once. For details, see [@State -> @Local](#state-local).|
| \@Prop                  | \@Param                   | Similar to \@Param, \@Prop is used to decorate custom component variables. When the input parameter is of the complex type, \@Prop is used to deep copy and \@Param is used to import the parameter.|
| \@Link                  | \@Param\@Event    | \@Link implements a two-way synchronization encapsulated by the framework of V1. Developers using V2 can implement the two-way synchronization through @Param and @Event.|
| \@ObjectLink            | \@Param                   | Compatible. \@ObjectLink needs to be initialized by the instance of the @Observed decorated class, but \@Param does not have this constraint.|
| \@Provide               | \@Provider                | Compatible.|
| \@Consume               | \@Consumer                | Compatible.|
| \@Watch               | \@Monitor                | \@Watch is used to listen for the changes of state variables and their top-level properties in V1. Observable changes of state variables can trigger the \@Watch listening event.<br>\@Monitor is used to listen for the changes of state variables in V2. Used together with \@Trace, in-depth changes can be listened. When a state variable changes frequently in an event, only the final result is used to determine whether to trigger the \@Monitor listening event.|
| LocalStorage               | Global \@ObservedV2 and \@Trace  | Compatible.|
| AppStorage               | AppStorageV2   | Compatible.|
| Environment       | Calls the ability APIs to obtain system environment variables.  | This capability is coupled with the AppStorage. In V2, you can directly call the ability APIs to obtain system environment variables.|
| PersistentStorage     | PersistenceV2   | The persistence capability of PersistentStorage is coupled with the AppStorage, while that of PersistenceV2 can be used independently.|

## Decorator Migration Examples

### @State->@Local

#### Migration Rules
In V1, the \@State decorator is used to decorate state variables inside a component. In V2, the \@Local decorator is provided as a substitute. However, the observation capability and initialization rules of the two decorators are obviously different. The migration policies for different use scenarios are as follows:

- For simple type: Directly replace \@State with \@Local.
- For complex type: In V1, @State can be used to observe the top-level property changes of a complex object. In V2, \@Local can be used to observe only the changes of the object itself. To listen for the internal property changes of an object, you can use \@ObservedV2 and \@Trace together.
- For state variable of external initialization: In V1, \@State supports external initialization, while \@Local in V2 does not support. If the initial value needs to be passed in externally, you can use the \@Param and \@Once decorators.

#### Example

**Simple type**

For simple variables, @State of V1 can be replaced with @Local of V2.

V1:

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

V2:

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

**Complex type**

@State of V1 can observe the changes of the top-level properties of complex objects, but @Local of V2 cannot observe the internal changes of objects. To solve this problem, you need to add @ObservedV2 to the class and add @Trace to the properties to observe in V2. In this way, V2 can listen for property changes inside the object.

V1:

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
      // @State can be used to observe the top-level changes.
      Button('value+1')
        .onClick(() => {
          this.child.value++;
        })
    }
  }
}
```

V2:

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
      // @Local can only observe itself. Add @ObservedV2 and @Trace to Child.
      Button('value+1')
        .onClick(() => {
          this.child.value++;
        })
    }
  }
}
```

**State variable of external initialization**

The @State decorated state variable of V1 can be initialized externally, but the @Local decorated state variable of V2 cannot. To implement similar functions, replace @State with @Param and @Once in V2 to allow passing in initial value externally and ensure that the value is synchronized only once during initialization.

V1:

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
      // @State supports external initialization.
      Child({ value: 30 })
    }
  }
}
```

V2:

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
      // @Local does not support external initialization. Use @Param and @Once instead.
      Child({ value: 30 })
    }
  }
}
```

### @Link -> @Param/@Event

#### Migration Rules
In V1, @Link allows two-way binding between parent and child components. When migrating to V2, you can use @Param and @Event to simulate two-way synchronization. In this way, @Param implements one-way passing from the parent to the child component, and then the child component triggers the state update of the parent component through the @Event callback.

#### Example

V1:

```ts
@Component
struct Child {
  // @Link can synchronize data in a two-way manner.
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

V2:

```ts
@ComponentV2
struct Child {
  // @Param works with @Event to synchronize data in a two-way manner.
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

#### Migration Rules
In V1, the @Prop decorator is used to pass in parameters from the parent component to the child component. These parameters can be directly changed in the child component. In V2, @Param replaces @Prop. However, @Param decorated parameter is read only and cannot be changed in the child component. Therefore, the migration policies for different use scenarios are as follows:

- For simple type: Directly replace@Prop with @Param.
- For complex type: If a complex object is passed and a strict one-way data binding is required, deep copy can be performed on the object to prevent the child component from changing the parent component data.
- For variable to change: If a child component needs to change an input parameter, use @Once to allow the child component to change the variable locally. Note that if \@Once is used, the current child component is initialized only once, and the parent component cannot be synchronized to the child component.

#### Example

**Simple type**

For variables of simple type, directly replace @Prop of V1 with @Param of V2.

V1:

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

V2:

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
**Complex type**

In V2, if you want to implement a strict one-way data binding when passing complex types to prevent child components from changing the parent component data, you need to perform deep copy when using @Param to pass complex objects to avoid object reference.

V1:

```ts
class Fruit {
  apple: number = 5;
  orange: number = 10;
}

@Component
struct Child {
  // @Prop passes the Fruit class. When the properties of the child class are changed, the parent class is not affected.
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
​
V2:

```ts
@ObservedV2
class Fruit{
  @Trace apple: number = 5;
  @Trace orange: number = 10;
  // Implement the deep copy to prevent the child component from changing the parent component data.
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

**Variable to change**

In V1, the child component can change the @Prop decorated variable. In V2, however, @Param decorated variable is read only. If the child component needs to change an input value, you can use @Param and @Once to allow changing the value locally.

V1:

```ts
@Component
struct Child {
  // @Prop can be used to directly change the variable.
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

V2:

```ts
@ComponentV2
struct Child {
  // @Param used together with @Once can change the variable locally.
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

### @ObjectLink/@Observed/@Track -> @ObservedV2/@Trace
#### Migration Rules
In V1, the @Observed and @ObjectLink decorators are used to observe the changes of class objects and their nested properties. However, V1 can only directly observe the top-level object properties. The properties of nested objects must be observed through custom components and @ObjectLink. In addition, V1 provides the @Track decorator to implement precise control over property level changes.

In V2, @ObservedV2 and @Trace are used together to efficiently observe in-depth changes of class objects and their nested properties, eliminating the dependency on custom components and simplifying the development process. In addition, the @Trace decorator, which replaces the @Track of V1, can update class properties precisely, achieving more efficient UI re-render control. The migration policies for different use scenarios are as follows:

- Observing properties of nested objects: In V1, you need to observe nested properties through custom components and @ObjectLink. In V2, you can use @ObservedV2 and @Trace to directly observe nested objects, simplifying the code structure.
- Updating class properties precisely: @Track of V1 can be replaced with @Trace of V2. @Trace can be used to observe and precisely update property changes at the same time, making the code simpler and more efficient.

#### Example
**Observing properties of nested objects**

In V1, the property changes of nested objects cannot be directly observed. Only the top-level property changes can be observed. You must create a custom component and use @ObjectLink to observe the properties of nested objects. In V2, @ObservedV2 and @Trace are used to directly observe the properties of nested objects, reducing complexity.

V1:

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
  // The address decorated by @ObjectLink in the child component is initialized from the parent component and receives the address instance decorated by @Observed.
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
      // The property changes of nested objects cannot be directly observed, for example, this.user.address.city.
      // Only the top-level property changes of the object can be observed. Therefore, the nested object Address needs to be extracted to the custom component AddressView.
      AddressView({ address: this.user.address })
    }
  }
}
```

V2:

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
      // Use @ObservedV2 and @Trace to directly observe the properties of nested objects.
      Text(`City: ${this.user.address.city}`)
      Button("city +a")
        .onClick(() => {
          this.user.address.city += "a";
        })
    }
  }
}
```
**Observing class properties**

In V1, @Observed is used to observe the changes of class instances and their properties, and @Track is used to optimize property-level changes so that only the @Track decorated properties can trigger UI re-renders. In V2, @Trace combines the capability of observing and updating property level changes and works with @ObservedV2 to implement efficient UI re-renders.

V1:

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

V2:

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
#### Migration Rules
The positioning capability and functions of @Provide and @Consume in V1 are similar to those of @Provider and @Consumer in V2. The former two decorators can be smoothly replaced with the later two. However, there are still some differences that allow you to determine whether to adjust them based on your code implementation.
In V1, @Provide and @Consume are used for data sharing between parent and child components. They can be matched by alias or attribute name. In addition, @Consume must depend on @Provide of the parent component and cannot be initialized locally. In V2, @Provider and @Consumer enhance these features to make data sharing more flexible. The migration policies for different use scenarios are as follows:

- In V1, \@Provide or \@Consume can be directly used if no alias is specified. In V2, \@Provider or \@Consumer is a standard decorator and the parameters are optional. Therefore, the alias must be followed by parentheses regardless of whether it is specified.
- Rules for matching aliases and attribute names: In V1, @Provide and @Consume can be matched by aliases or attribute names. In V2, alias is the unique matching key. Only alias can be used for matching when it is specified.
- Local initialization: In V1, @Consume does not support local initialization and must depend on the parent component. In V2, @Consumer supports local initialization. If the corresponding @Provider cannot be found, the local default value is used.
- Initialization from the parent component: In V1, @Provide can be directly initialized from the parent component. In V2, @Provider does not support external initialization. You need to use @Param and @Once to receive the initial value and assign it to @Provider.
- Overloading support: In V1, @Provide does not support overloading by default. You need to set **allowOverride**. In V2, @Provider supports overloading and @Consumer can search for the nearest @Provider upwards.
#### Example
**Rules for matching aliases and attribute names**

In V1, @Provide and @Consume can be matched by alias or attribute name. In V2, an alias is a unique key. If an alias is specified in @Consumer, the alias instead of the attribute name can be used for matching.

V1:

```ts
@Component
struct Child {
  // Both the alias and attribute name are keys and can be used to match.
  @Consume('text') childMessage: string;
  @Consume message: string;
  build(){
    Column(){
      Text(this.childMessage)
      Text(this.message) // The value of Text is "Hello World".
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

V2:

```ts
@ComponentV2
struct Child {
  // The alias is the unique matching key. If the alias exists, the attribute name cannot be used for matching.
  @Consumer('text') childMessage: string = "default";
  @Consumer() message: string = "default";
  build(){
    Column(){
      Text(this.childMessage)
      Text(this.message) // The value of Text is "default".
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

**Local initialization support**

In V1, @Consume does not allow variables to initialize locally and must depend on @Provide of the parent component. Otherwise, an exception is thrown. After migration to V2, @Consumer allows local initialization. If the corresponding @Provider cannot be found, the local default value is used.

V1:

```ts
@Component
struct Child {
  // @Consume prohibits local initialization. If the corresponding @Provide cannot be found, an exception is thrown.
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

V2:

```ts
@ComponentV2
struct Child {
  // @Consumer allows local initialization. Local default value will be used when \@Provider is not found.
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

**Initialization from the parent component**

In V1, @Provide allows initialization from the parent component, and initial values can be passed directly through component parameters. In V2, @Provider prohibits external initialization. To implement the same function, you can use @Param and @Once in the child component to receive the initial value and assign the value to the @Provider variable.

V1:

```ts
@Entry
@Component
struct Parent {
  @State parentValue: number = 42;
  build() {
    Column() {
      // @Provide supports initialization from the parent component.
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

V2:

```ts
@Entry
@ComponentV2
struct Parent {
  @Local parentValue: number = 42;
  build() {
    Column() {
      // @Provider prohibits localization from the parent component. Alternatively, you can use @Param to receive the value and then assign it to @Provider.
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

**Overloading support**

In V1, @Provide does not support overloading by default and cannot override the @Provide with the same name in the upper-level component. To support overloading, **allowOverride** must be set. In V2, @Provider supports overloading by default. @Consumer searches for the nearest @Provider upwards. No additional configuration is required.

V1:

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
  // @Provide does not support overloading by default. Set the **allowOverride** function to enable.
  @Provide({ allowOverride: "reviewVotes" }) reviewVotes: number = 20;
  build() {
    Child()
  }
}

@Component
struct Child {
  @Consume("reviewVotes") reviewVotes: number;
  build() {
    Text(this.reviewVotes.toString ()) // The value of Text is 20.
  }
}
```

V2:

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
  // @Provider supports overloading by default. @Consumer searches for the nearest @Provider upwards.
  @Provider() reviewVotes: number = 20;
  build() {
    Child()
  }
}

@ComponentV2
struct Child {
  @Consumer() reviewVotes: number = 0;
  build() {
    Text(this.reviewVotes.toString ()) // The value of Text is 20.
  }
}
```

### @Watch -> @Monitor
#### Migration Rules
In V1, \@Watch is used to listen for the changes of state variables and the specified callback is invoked when the variables change. In V2, \@Monitor replaces \@Watch to listen for variable changes more flexibly and obtain variable values before and after the changes. The migration policies for different use scenarios are as follows:

- Single-variable listening: In simple scenarios, use @Monitor instead of @Watch.
- Multi-variable listening: @Watch of V1 cannot obtain the value before the change. In V2, \@Monitor can listen for multiple variables at the same time and can access the states of the variables before and after the change.
#### Example
**Single-variable listening**

Use @Monitor of V2 instead of @Watch of V1.

V1:

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

V2:

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

**Multi-variable listening**

In V1, each @Watch callback can listen for only one variable and cannot obtain the value before the change. After migration to V2, you can use one @Monitor to listen for multiple variables at the same time and obtain the values of the variables before and after the change.

V1:

```ts
@Entry
@Component
struct watchExample {
  @State @Watch('onAppleChange') apple: number = 0;
  @State @Watch('onOrangeChange') orange: number = 0;
  // @Watch callback, which is used to listen for only a single variable but cannot obtain the value before change.
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

V2:

```ts
@Entry
@ComponentV2
struct monitorExample {
  @Local apple: number = 0;
  @Local orange: number = 0;

  // @Monitor callback, which is used to listen for multiple variables and obtain the value before change.
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
#### Migration Rules
V1 does not have the concept of computed attribute. Therefore, there is no way to reduce repeated computation in the UI. V2 provides the @Computed decorator to reduce repeated computation.

V1:
In the following example, each time the **lastName** is changed, the **Text** component is re-rendered and **this.lastName +' ' + this.firstName** needs to be computed repeatedly.
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
If \@Computed of V2 is used, the computation is triggered only once each time **lastName** is changed.

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
### LocalStorage -> Global @ObservedV2 or @Trace
#### Migration Rules
LocalStorage is used to share state variables between pages. This capability is provided because state variables of V1 are coupled with the view level and cannot be shared between pages.
For V2, the observation capability of state variables is embedded in the data and is not coupled with the view level. Therefore, V2 does not require a capability similar to **LocalStorage**. You can use the global @ObservedV2 or @Trace to import and export data by yourself, sharing state variables between pages.

#### Example
**Common scenarios**

V1:
Use the windowStage.[loadContent](../reference/apis-arkui/js-apis-window.md#loadcontent9) and [getShared](../reference/apis-arkui/arkui-ts/ts-state-management.md#getshared10) APIs to share state variables between pages.
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

```
// Page1.ets
import { router } from '@kit.ArkUI';

// Use the getShared API to obtain the LocalStorage instance shared by stage.
@Entry(LocalStorage.getShared())
@Component
struct Page1 {
  @LocalStorageLink('count') count: number = 0;
  build() {
    Column() {
      Text(`${this.count}`)
        .fontSize(50)
      Button('push to Page2')
        .onClick(() => {
          router.pushUrl({url: 'pages/Page2'});
        })
    }
  }
}
```

```
// Page2.ets
// Use the getShared API to obtain the LocalStorage instance shared by stage.
@Entry(LocalStorage.getShared())
@Component
struct Page2 {
  @LocalStorageLink('count') count: number = 0;
  build() {
    Column() {
      Text(`${this.count}`)
        .fontSize(50)
    }
  }
}
```
V2:
- Declare the \@ObservedV2 decorated **MyStorage** class and import it to the page to use.
- Declare the \@Trace decorated properties as observable data shared between pages.

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
import { router } from '@kit.ArkUI';
import { MyStorage } from './storage';

@Entry
@ComponentV2
struct Page1 {
  storage: MyStorage = MyStorage.instance();
  build() {
    Column() {
      Text(`${this.storage.count}`)
        .fontSize(50)
      Button('push to Page2')
        .onClick(() => {
          router.pushUrl({url: 'pages/Page2'});
        })
    }
  }
}
```

```
// Page2.ets
import { MyStorage } from './storage';

@Entry
@ComponentV2
struct Page2 {
  storage: MyStorage = MyStorage.instance();
    build() {
      Column() {
        Text(`${this.storage.count}`)
          .fontSize(50)
      }
    }
}
```

**Receiving LocalStorage instance by custom components**

To adapt to the scenario where **Navigation** is used, **LocalStorage** supports the input parameters of a custom component and passed them to all child custom components that use the current custom component as the root node.
In this scenario, you can use multiple global \@ObservedV2 or \@Trace instances instead.

V1:
```
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
      // Pass multiple LocalStorage instances.
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
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
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
        // Display "PropA".
        NavigationContentMsgStack()
        // Display "PropA".
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
        // Display "Hello". This localStorageB does not have the value corresponding to PropA, therefore, the local default value is used.
        NavigationContentMsgStack()
        // Display "PropB".
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
        // Display "Hello". This localStorageC does not have the value corresponding to PropA, therefore, the local default value is used.
        NavigationContentMsgStack()
        // Display "PropC".
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
V2:

Declare the \@ObservedV2 decorated class to replace **LocalStorage**. The key of **LocalStorage** can be replaced with the \@Trace decorated attribute.
```
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

Create the **MyStorageA**, **MyStorageB**, and **MyStorageC** instances in the **pageOneStack**, **pageTwoStack**, and **pageThreeStack** components, and pass the instances to the child component **NavigationContentMsgStack** through \@Param. In this way, the **LocalStorage** instance can be shared in the child component tree.

```
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
              this.pageInfo.pushPath({ name: 'pageOne' }); // Push the navigation destination page specified by name to the navigation stack.
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
        // Display "PropA".
        NavigationContentMsgStack({storage: this.storageA})
        // Display "PropA".
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
        // Display "Hello".
        NavigationContentMsgStack({ storage: this.storageB })
        // Display "PropB".
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
        // Display "Hello".
        NavigationContentMsgStack({ storage: this.storageC })
        // Display "PropC".
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
In the previous section, the global @ObserveV2 or @Trace reconstruction is not suitable for cross-ability data sharing. In this case, **AppStorageV2** can be used.
V1:
**AppStorage** is bound to an application process and can share data across abilities.
Example:

```
// EntryAbility Index.ets
import { common, Want } from '@kit.AbilityKit';
@Entry
@Component
struct Index {
  @StorageLink('count') count: number = 0;
  private context: common.UIAbilityContext= getContext(this) as common.UIAbilityContext;
  build() {
    Column() {
      Text(`EntryAbility count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication',
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
  private context: common.UIAbilityContext= getContext(this) as common.UIAbilityContext;
  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.count}`)
        .fontSize(50)
        .onClick(() => {
          this.count++;
        })
      Button('Jump to EntryAbility').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication',
          abilityName: 'EntryAbility'
        };
        this.context.startAbility(wantInfo);
      })
    }
  }
}
```
V2:
**AppStorageV2** can be used to share data across abilities.
Example:

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
  private context: common.UIAbilityContext= getContext(this) as common.UIAbilityContext;
  build() {
    Column() {
      Text(`EntryAbility1 count: ${this.storage.count}`)
        .fontSize(50)
        .onClick(() => {
          this.storage.count++;
        })
      Button('Jump to EntryAbility1').onClick(() => {
        let wantInfo: Want = {
          bundleName: 'com.example.myapplication',
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
  private context: common.UIAbilityContext= getContext(this) as common.UIAbilityContext;
    build() {
      Column() {
        Text(`EntryAbility1 count: ${this.storage.count}`)
          .fontSize(50)
          .onClick(() => {
            this.storage.count++;
          })
        Button('Jump to EntryAbility').onClick(() => {
          let wantInfo: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
          };
          this.context.startAbility(wantInfo);
        })
      }
    }
}
```
### Environment -> Ability APIs
In V1, you can obtain environment variables through **Environment**. However, the result obtained by **Environment** cannot be directly used. You need to use **Environment** together with **AppStorage** to obtain the value of the corresponding environment variable.
After migration to V2, you can directly obtain the system environment variables through the [config](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#properties) property of **UIAbilityContext** without using **Environment**.
V1:
The following uses **languageCode** as an example.
```
// Save the device language code to AppStorage.
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';
  build() {
    Row() {
      Column() {
        // Output the current device language code.
        Text(this.languageCode)
      }
    }
  }
}
```

V2:
Encapsulates the **Env** type to pass multiple system environment variables.

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
Obtain the required system environment variables from **onCreate**.
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
Obtain the current value of **Env** on the page.
```
// Index.ets
import { env } from '../pages/Env';

@Entry
@ComponentV2
struct Index {
  build() {
    Row() {
      Column() {
        // Output the environment variables of the current device.
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
In V1, **PersistentStorage** provides the capability of persisting UI data. In V2, **PersistenceV2** APIs are provided to replace **PersistentStorage**.
- The triggering time of **PersistentStorage** depends on the observation capability of **AppStorage** and is coupled with **AppStorage**. You cannot select the time to write or read persistent data.
- **PersistentStorage** uses serialization and deserialization. Without inputting types, **PersistentStorage** will lose its type and the property method of the object cannot be persisted.

For PersistenceV2:
- The change of the \@Trace decorated property of the \@ObservedV2 object associated with PersistenceV2 triggers the automatic persistency of the entire associated object.
- You can also call the [PersistenceV2.save](./arkts-new-persistencev2.md#save-persisting-stored-data-manually) and [PersistenceV2.connect](./arkts-new-persistencev2.md#connect-creating-or-obtaining-stored-data) APIs to manually trigger persistent writing and reading.

V1:

```
PersistentStorage.persistProp('aProp', 47);

@Entry
@Component
struct Index {
  @StorageLink('aProp') aProp: number = 48;

  build() {
    Row() {
      Column() {
        // The current result is saved when the application exits. After the restart, the last saved result is displayed.
        Text(`${this.aProp}`)
          .onClick(() => {
            this.aProp += 1;
          })
      }
    }
  }
}
```

V2:

The following case shows:
- Benchmarking against the **PersistentStorage** capability of V1: The change of **aProp** automatically triggers **PersistenceV2**.
- Enhancing the capability compared with the **PersistentStorage** of V1: The **bProp** is not a state variable and its changes cannot be observed or listened for. However, you can still call the [PersistenceV2.save](./arkts-new-persistencev2.md#save-persisting-stored-data-manually) API for persistency.
    - Click **aProp** and the UI is re-rendered.
    - Click **bProp** but the UI is not re-rendered.
    - Click **save storage** to flush the **PersistentStorage** link data to disks.
    - Exit and restart the application. The values of **aProp** and **bProp** displayed in the **Text** component are the values changed last time.
```
import { PersistenceV2 } from '@kit.ArkUI';
// Data center.
@ObservedV2
class Storage {
  @Trace aProp: number = 0;
  bProp: number = 10;
}

// Callback used to receive serialization failure.
PersistenceV2.notifyOnError((key: string, reason: string, msg: string) => {
  console.error(`error key: ${key}, reason: ${reason}, message: ${msg}`);
});

@Entry
@ComponentV2
struct Page1 {
  // Create a KV pair whose key is Sample in PersistenceV2 (if the key exists, the data in PersistenceV2 is returned) and associate it with prop.
  @Local storage: Storage = PersistenceV2.connect(Storage, () => new Storage())!;

  build() {
    Column() {
      Text(`@Trace aProp: ${this.storage.aProp}`)
        .fontSize(30)
        .onClick(() => {
          this.storage.aProp++;
        })

      Text(`bProp:: ${this.storage.bProp}`)
        .fontSize(30)
        .onClick(() => {
          // The page is not re-rendered, but the value of bProp is changed.
          this.storage.bProp++;
        })

      Button('save storage')
        .onClick(() => {
          // Different from V1, PersistenceV2 does not depend on the capability of observing state variables. You can perform persistence proactively.
          PersistenceV2.save(Storage);
        })
    }
  }
}
```

## Existing Application Migration
For large-scale applications that have been developed using V1, it is unlikely to migrate them from V1 to V2 at a time. Instead, they are migrated in batches and by component. As a result, V1 and V2 have to be used together.

In this case, the parent components are of V1, and the migrated child component are of V2. Take the following components as an example:
- The parent component is \@Component, and the data source is \@LocalStorageLink.
- The child component is \@ComponentV2 and uses \@Param to receive data from the data source.

In this case, the following policies can be used for migration:
- Declare a class decorated by \@ObservedV2 to encapsulate the data of V1.
- Define a custom component \@Component between \@Component and \@ComponentV2.
- At the bridging layer:
    - To synchronize data from V1 to V2, use the listening of \@Watch to trigger value changes of the class decorated by \@ObservedV2.
    - To synchronize data from V2 to V1, declare **Monitor** in the class decorated by \@ObservedV2 and use the API of **LocalStorage** to reversely notify state variables of V1.

Example:
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

## Other Migrations

### Scrolling Components

#### List

You can use [ChildrenMainSize](../reference/apis-arkui/arkui-ts/ts-container-list.md#childrenmainsize12) to set the size of the child component of **List** along the main axis.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe the API invoking.

Example:

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

V2:

In V2, however, [\@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. In addition, because **ChildrenMainSize** is defined in the framework, you cannot use [\@Trace](./arkts-new-observedV2-and-trace.md) to mark the attributes of **ChildrenMainSize**. In this case, you can use [makeObserved](./arkts-new-makeObserved.md) instead.

Example:

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct ListExample {
  private arr: Array<number> = new Array(10).fill(0);
  private scroller: ListScroller = new ListScroller();
  listSpace: number = 10;
  // Use the makeObserved capability to observe ChildrenMainSize.
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

You can use [WaterFlowSections](../reference/apis-arkui/arkui-ts/ts-container-waterflow.md#waterflowsections12) to set the water flow item sections.

Note that the length of **arr** must be the same as the total length of **itemsCount** of all **SectionOptions** in **WaterFlowSections**. Otherwise, **WaterFlow** cannot process the array and the UI cannot be re-rendered.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe the API invoking.

Example:

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
        this.arr = new Array(15).fill(1);
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

V2:

In V2, however, [\@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. In addition, because **WaterFlowSections** is defined in the framework, you cannot use [\@Trace](./arkts-new-observedV2-and-trace.md) to mark the attributes of **WaterFlowSections**. In this case, you can use [makeObserved](./arkts-new-makeObserved.md) instead.

Example:

```ts
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct WaterFlowSample {
  colors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Blue, Color.Pink];
  // Use the makeObserved capability to observe WaterFlowSections.
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
        this.arr = new Array(15).fill(1);
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

You can use [attributeModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#attributemodifier) to dynamically set component attributes.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe changes.

Example:

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

V2:

In V2, however, [\@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. To observe the attribute changes of **attributeModifier**, use[makeObserved](./arkts-new-makeObserved.md) instead.

Example:

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
  // Use the makeObserved capability to observe the this.modifier attribute of attributeModifier.
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

Dynamically sets attributes on the current component. The following uses [CommonModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#custom-modifier) as an example.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe changes.

Example:

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

V2:

In V2, however, [\@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. In addition, [CommonModifier](../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#custom-modifier) is re-rendered through its properties in the framework, in this case, you can use [makeObserved](./arkts-new-makeObserved.md) instead.

Example:

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
    Image($r('app.media.app_icon'))
      .attributeModifier(this.modifier as MyModifier)
  }
}

@Entry
@ComponentV2
struct Index {
  // Use the makeObserved capability to observe CommonModifier.
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

#### Component Modifier

Dynamically sets attributes on the current component. The following uses the **Text** component as an example.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe changes.

Example:

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

V2:

In V2, however, [\@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. In this case, you can use [makeObserved](./arkts-new-makeObserved.md) instead.

Example:

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
  // Use the makeObserved capability to observe TextModifier.
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
