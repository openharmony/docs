# Restrictions and Extensions

## Restrictions on Using ArkTS in Generators

ArkTS has the following restrictions on generators:

- Expressions can be used only in character strings (${expression}), **if/else** statements, **ForEach** parameters, and component parameters.

- No expressions should cause any application state variables (that is, variables decorated by **@State**, **@Link**, and **@Prop**) to change. Otherwise, undefined and potentially unstable framework behavior may occur.

- The generator function cannot contain local variables.

None of the above restrictions applies to anonymous function implementations of event methods (such as **onClick**).

## Two-Way Binding of Variables

ArkTS supports two-way binding through **$$**, which is usually used for variables whose state values change frequently.

- **$$** supports variables of primitive types and variables decorated by **@State**, **@Link**, or **@Prop**.
- **$$** supports only the **show** parameter of the **[bindPopup](../reference/arkui-ts/ts-universal-attributes-popup.md)** attribute method, the **checked** attribute of the **[\<Radio>](../reference/arkui-ts/ts-basic-components-radio.md)** component, and the **refreshing** parameter of the **[\<Refresh>](../reference/arkui-ts/ts-container-refresh.md)** component.
- When the variable bound to **$$** changes, only the current component is rendered, which improves the rendering speed.

```ts
// xxx.ets
@Entry
@Component
struct bindPopupPage {
  @State customPopup: boolean = false

  build() {
    Column() {
      Button('Popup')
        .margin(20)
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup($$this.customPopup, {
          message: "showPopup"
        })
    }
  }
}
```

![popup](figures/popup.gif)

## Restrictions on Data Type Declarations of State Variables

The data type declaration of the **@State**, **@Provide**, **@Link**, or **@Consume** decorated state variables can consist of only one of the primitive data types or reference data types.

Example:

```ts
// xxx.ets
@Entry
@Component
struct IndexPage {
  // Incorrect: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${this.message}`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![hello](figures/hello.PNG)

## Initialization and Restrictions of Custom Components' Member Variables

The member variables of a component can be initialized in either of the following ways:

- Local initialization:

  ```ts
  @State counter: Counter = new Counter()
  ```
- Initialization using constructor parameters:

  ```ts
  MyComponent({counter: $myCounter})
  ```

The allowed method depends on the decorator of the state variable, as shown in the following table.

| Decorator       | Local Initialization| Initialization Using Constructor Parameters|
| ------------ | ----- | ----------- |
| @State       | Mandatory   | Optional         |
| @Prop        | Forbidden   | Mandatory         |
| @Link        | Forbidden   | Mandatory         |
| @StorageLink | Mandatory   | Forbidden         |
| @StorageProp | Mandatory   | Forbidden         |
| @Provide     | Mandatory   | Optional         |
| @Consume     | Forbidden   | Forbidden         |
| @ObjectLink  | Forbidden   | Mandatory         |
| Normal member variable      | Recommended   | Optional         |

As indicated by the preceding table:

- The **@State** decorated variables must be initialized locally. Their initial values can be overwritten by the constructor parameters.

- The **@Prop** and **@Link** decorated variables must be initialized only by constructor parameters.

Comply with the following rules when using constructors to initialize member variables:

| From the Variable in the Parent Component (Below) to the Variable in the Child Component (Right)| @State | @Link  | @Prop  | Normal Variable|
| -------------------------------------------- | ------ | ------ | ------ | -------- |
| @State                                       | Not allowed| Allowed  | Allowed  | Allowed    |
| @Link                                        | Not allowed| Allowed  | Not recommended| Allowed    |
| @Prop                                        | Not allowed| Not allowed| Allowed  | Allowed    |
| @StorageLink                                 | Not allowed| Allowed  | Not allowed| Not allowed  |
| @StorageProp                                 | Not allowed| Not allowed| Not allowed| Allowed    |
| Normal variable                                    | Allowed  | Not allowed| Not allowed| Allowed    |

As indicated by the preceding table:

- The normal variables of the parent component can be used to initialize the **@State** decorated variables of the child component, but not the **@Link** or **@Prop** decorated variables.

- The **@State** decorated variable of the parent component can be used to initialize the **@Prop**, **@Link** (using **$**), or normal variables of the child component, but not the **@State** decorated variables of the child component.

- The **@Link** decorated variables of the parent component can be used to initialize the **@Link** decorated or normal variables of the child component. However, initializing the **@State** decorated members of the child component can result in a syntax error. In addition, initializing the **@Prop** decorated variables is not recommended.

- The **@Prop** decorated variables of the parent component can be used to initialize the normal variables or **@Prop** decorated variables of the child component, but not the **@State** or **@Link** decorated variables.

- Passing **@StorageLink** and **@StorageProp** from the parent component to the child component is prohibited.

- In addition to the preceding rules, the TypeScript strong type rules need to be followed.
