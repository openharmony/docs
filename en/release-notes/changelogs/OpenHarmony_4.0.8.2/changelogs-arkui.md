# ArkUI Subsystem Changelog

## cl.arkui.1 Restrictions on Data Type Declarations of State Variables

The data types of state variables decorated by state decorators must be explicitly declared. They cannot be declared as **any**.

**Example**

```ts
// xxx.ets
@Entry
@Component
struct DatePickerExample {
  // Incorrect: @State isLunar: any = false
  @State isLunar: boolean = false

  build() {
   ...
  }
}
```

**Change Impacts**

If the data type of a state variable decorated by a state decorator is declared as **any**, a WARN-level (previously ERROR-level) build error will occur.

```ts
// ArkTS:ERROR Please define an explicit type, not any.
@State isLunar: any = false
```

**Key API/Component Changes**

N/A

**Adaptation Guide**

Explicitly declare the data type for state variables decorated by state decorators.

## cl.arkui.2 Initialization Rules and Restrictions of Custom Components' Member Variables

**@LocalStorageLink** and **@LocalStorageProp** variables cannot be initialized from the parent component.

**Example**

```ts
let NextID: number = 0;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

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
        objectName: new ClassA(1)
      })
    }
  }
}

@Component
struct Child {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
  @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA(1);

  build() {
  }
}
```

**Change Impacts**

If **@LocalStorageLink** and **@LocalStorageProp** variables are initialized from the parent component, a WARN-level (previously ERROR-level) build error will occur.

**Key API/Component Changes**

N/A

**Adaptation Guide**

When building a child component, do not assign values to the variables by **@LocalStorageLink** and **@LocalStorageProp** in the child component.

To change these variables from the parent component, use the API provided by the **LocalStorage** (such as the **set** API) to assign values to them.
