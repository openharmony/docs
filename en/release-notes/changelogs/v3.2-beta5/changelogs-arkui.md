# ArkUI Subsystem ChangeLog

## cl.arkui.1 Restrictions on Data Type Declarations of State Variables

1. The data types of state variables decorated by state decorators must be explicitly declared. They cannot be declared as **any** or **Date**.

    Example:

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct DatePickerExample {
      // Incorrect: @State isLunar: any = false
      @State isLunar: boolean = false
      // Incorrect: @State selectedDate: Date = new Date('2021-08-08')
      private selectedDate: Date = new Date('2021-08-08')

      build() {
        Column() {
          Button('Switch Calendar')
            .margin({ top: 30 })
            .onClick(() => {
              this.isLunar = !this.isLunar
            })
          DatePicker({
            start: new Date('1970-1-1'),
            end: new Date('2100-1-1'),
            selected: this.selectedDate
          })
            .lunar(this.isLunar)
            .onChange((value: DatePickerResult) => {
              this.selectedDate.setFullYear(value.year, value.month, value.day)
              console.info('select current date is: ' + JSON.stringify(value))
            })

        }.width('100%')
      }
    }
    ```

2. The data type declaration of the **@State**, **@Provide**, **@Link**, or **@Consume** decorated state variables can consist of only one of the primitive data types or reference data types.

    The **Length**, **ResourceStr**, and **ResourceColor** types are combinations of primitive data types or reference data types. Therefore, they cannot be used by the aforementioned types of state variables.
    For details about the definitions of **Length**, **ResourceStr**, and **ResourceColor**, see [Types](../../../application-dev/reference/arkui-ts/ts-types.md).

    Example:

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct IndexPage {
      // Incorrect: @State message: string | Resource = 'Hello World'
      @State message: string = 'Hello World'
      // Incorrect: @State message: ResourceStr = $r('app.string.hello')
      @State resourceStr: Resource = $r('app.string.hello')
    
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

    ![hello](../../../application-dev/quick-start/figures/hello.PNG)

**Change Impact**

1. If the data type of a state variable decorated by a state decorator is declared as **any**, a build error will occur.
    ```ts
    // ArkTS:ERROR Please define an explicit type, not any.
    @State isLunar: any = false
    ```
2. If the data type of a state variable decorated by a state decorator is declared as **Date**, a build error will occur.
    ```ts
    // ArkTS:ERROR The @State property 'selectedDate' cannot be a 'Date' object.
    @State selectedDate: Date = new Date('2021-08-08')
    ```
3. If the data type of a **@State**, **@Provide**, **@Link**, and or **@Consume** decorated state variable is Length, **ResourceStr**, or **ResourceColor**, a build error will occur.
    ```ts
    /* ArkTS:ERROR The state variable type here is 'ResourceStr', it contains both a simple type and an object type,
      which are not allowed to be defined for state variable of a struct.*/
    @State message: ResourceStr = $r('app.string.hello')
    ```

**Key API/Component Changes**

N/A

**Adaptation Guide**

1. Explicitly declare the data type for state variables decorated by state decorators.
2. If a state variable decorated by a state decorator uses the **Date** object, change it to a regular variable – a variable not decorated by any decorator.
3. Adapt the **@State**, **@Provide**, **@Link**, and **@Consume** decorated variables based on the following code snippet so that they do not use the **Length(string|number|Resource)**, **ResourceStr(string|Resource)**, and **ResourceColor(string|number|Color|Resource)** types:
    ```ts
    // Incorrect:
    @State message: ResourceStr = $r('app.string.hello')
    // Corrected:
    @State resourceStr: Resource = $r('app.string.hello')
    ```


## cl.arkui.2 Initialization Rules and Restrictions of Custom Components' Member Variables

Comply with the following rules when using constructors to initialize member variables:

| **From the Variable in the Parent Component (Right) to the Variable in the Child Component (Below)**| **regular** | **@State** | **@Link** | **@Prop** | **@Provide** | **@Consume** | **@ObjectLink** |
|---------------------------------|----------------------------|------------|-----------|-----------|--------------|--------------|------------------|
| **regular**                    | Supported                        | Supported        | Supported       | Supported       | Not supported           | Not supported           | Supported              |
| **@State**                     | Supported                        | Supported        | Supported       | Supported       | Supported          | Supported          | Supported              |
| **@Link**                      | Not supported                         | Supported (1)     | Supported (1)    | Supported (1)    | Supported (1)       | Supported (1)       | Supported (1)           |
| **@Prop**                      | Supported                        | Supported        | Supported       | Supported       | Supported          | Supported          | Supported              |
| **@Provide**                   | Supported                        | Supported        | Supported       | Supported       | Supported          | Supported          | Supported              |
| **@Consume**                   | Not supported                         | Not supported         | Not supported        | Not supported        | Not supported           | Not supported           | Not supported               |
| **@ObjectLink**                | Not supported                         | Not supported     | Not supported        | Not supported        | Not supported           | Not supported           | Not supported               |

| **From the Variable in the Parent Component (Right) to the Variable in the Child Component (Below)**| **@StorageLink** | **@StorageProp** | **@LocalStorageLink** | **@LocalStorageProp** |
|------------------|------------------|------------------|-----------------------|------------------------|
| **regular**                   | Supported              | Not supported               | Not supported                    | Not supported             |
| **@State**                    | Supported              | Supported              | Supported                   | Supported                    |
| **@Link**                     | Supported (1)           | Supported (1)           | Supported (1)                | Supported (1)                 |
| **@Prop**                     | Supported              | Supported              | Supported                   | Supported                    |
| **@Provide**                  | Supported              | Supported              | Supported                   | Supported                    |
| **@Consume**                  | Not supported            | Not supported             | Not supported                 | Not supported                  |
| **@ObjectLink**               | Not supported            | Not supported             | Not supported                 | Not supported                  |

> **NOTE**
>
> **Supported (1)**: The dollar sign ($) must be used, for example, **this.$varA**. 
>
> **regular**: refers to a regular variable that is not decorated by any decorator.

**@StorageLink**, **@StorageProp**, **@LocalStorageLink**, and **@LocalStorageProp** variables cannot be initialized from the parent component.

**Change Impact**

1. Variables decorated by **@LocalStorageLink** and **@LocalStorageProp** cannot be initialized from the parent component.
    ```ts
    @Entry
    @Component
    struct LocalStorageComponent {
        build() {
            Column() {
                Child({
                  /* ArkTS:ERROR Property 'simpleVarName' in the custom component 'Child' cannot
                    initialize here (forbidden to specify). */
                  simpleVarName: 1,
                  /* ArkTS:ERROR Property 'objectName' in the custom component 'Child' cannot
                    initialize here (forbidden to specify). */
                  objectName: new ClassA("x")
                })
            }
        }
    }
    @Component
    struct Child {
        @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
        @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA("x");
        build() {}
    }
    ```
2. The **@ObjectLink** decorated variable cannot be directly initialized from a decorated variable in the parent component. The source of the parent component must be an array item or object attribute decorated by **@State**, **@Link**, **@Provide**, **@Consume**, or **@ObjectLink**.
    ```ts
    let NextID : number = 0;
    
    @Observed class ClassA {
      public id : number;
      public c: number;
      constructor(c: number) {
        this.id = NextID++;
        this.c = c;
      }
    }
    
    @Component
    struct Child {
      @ObjectLink varA : ClassA;
      build() {
        Row() {
          Text('ViewA-' + this.varA.id)
        }
      }
    }
    
    @Component
    struct Parent {
      @Link linkValue: ClassA
      build() {
        Column() {
          /* ArkTS:ERROR The @Link property 'linkValue' cannot be assigned to
            the @ObjectLink property 'varA'.*/
          Child({ varA: this.linkValue })
        }
      }
    }
    ```

**Key API/Component Changes**

N/A

**Adaptation Guide**
1. When building a child component, do not perform the build on the variables decorated by **@LocalStorageLink** and **@LocalStorageProp** in the child component.

  To change these variables from the parent component, use the API provided by the **LocalStorage** (such as the **set** API) to assign values to them.

2. For details about how to use @ObjectLink, see @ObjectLink usage guide.


## cl.arkui.LocalStorage.1 Return Type Change of the get API

**Change Impact**

Changed the return type from **get\<T>(propName: string): T** to **get<T>(propName: string): T | undefined**.

No adaptation is needed.

## cl.arkui.LocalStorage.2 Mandatory/Optional Change of the newValue Parameter in setOrCreate
**Change Impact**

API declaration before change:
```js
setOrCreate<T>(propName: string, newValue?: T): boolean
```
API declaration after change:
```js
setOrCreate<T>(propName: string, newValue: T): boolean
```
The **newValue** parameter becomes mandatory.
If it is not specified when an application calls the API, the build will fail after the SDK is replaced.

**Adaptation Guide**

```js
let storage = new LocalStorage();
storage.setOrCreate('propA', 'hello');
```
## cl.arkui.LocalStorage.3 link Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
link<T>(propName: string, linkUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
link<T>(propName: string): SubscribedAbstractProperty<T>
```
1. The second and third parameters of the **link** API are reserved for internal use by the framework. Therefore, the API is changed to contain only one parameter.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.link("PropA");
linA.set(50);
```

## cl.arkui.LocalStorage.4 setAndLink Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
setAndLink<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
setAndLink<T>(propName: string, defaultValue: T): SubscribedAbstractProperty<T>
```
1. The third and fourth parameters of the **setAndLink** API are reserved for internal use by the framework. Therefore, the API is changed to contain two parameters.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let linA = storage.setAndLink("PropA", "48")
linA.set(50);
```

## cl.arkui.LocalStorage.5 prop Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
prop<T>(propName: string, propUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
prop<S>(propName: string): SubscribedAbstractProperty<S>
```
1. The second and third parameters of the **prop** API are reserved for internal use by the framework. Therefore, the API is changed to contain only one parameter.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.prop("PropA");
propA.set(51); // one-way sync
```

## cl.arkui.LocalStorage.6 setAndProp Parameter and Return Type Changes
**Change Impact**

API declaration before change:
```js
setAndProp<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T
```
API declaration after change:
```js
setAndProp<S>(propName: string, defaultValue: S): SubscribedAbstractProperty<S>
```
1. The third and fourth parameters of the **setAndProp** API are reserved for internal use by the framework. Therefore, the API is changed to contain two parameters.
2. The return type **T** is changed to **SubscribedAbstractProperty**.

**Adaptation Guide**

```js
let storage = new LocalStorage({"PropA": "47"});
let propA = storage.setAndProp("PropA", "48");
propA.set(51); // one-way sync
```
