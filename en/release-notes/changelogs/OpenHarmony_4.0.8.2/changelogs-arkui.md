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

## cl.arkui.3 Change of the bottom Definition in Toast Options in the PromptAction Module

Changed the definition of the **bottom** attribute in toast options from distance between the top of the toast and the bottom of the screen to distance between the bottom of the toast and the bottom of the screen.

**Example**

```ts
import promptAction from '@ohos.promptAction';
@Entry
@Component
struct Index {
  build() {
    Row() {
      Button()
      .onClick(() => {
        try {
          promptAction.showToast({
            message: 'Message Info',
            duration: 2000
          });
        } catch (error) {
          console.error(`showToast args error code is ${error.code}, message is ${error.message}`);
        };
      })
    }
  }
}
```

**Change Impacts**

In the **PromptAction** module, the same value for the **bottom** attribute may result in different toast appearances, depending on whether the API version used by the compiler is earlier than 10 or not.

**Key API/Component Changes**

N/A

**Adaptation Guide**

When setting the **bottom** attribute, account for the definition change.

## cl.arkui.4 Content Layout Change of AlertDialog

The content layout of the alert dialog box varies according to the following conditions: 1. whether there is a title. 2. whether the text is on a single line.

Currently, only the single-line text without a title is centered. In other cases, the text is left-aligned.

**Example**

```ts
// xxx.ets
@Entry
@Component
struct AlertDialogExample {
  build() {
    Column({ space: 5 }) {
      Button('one button dialog')
        .onClick(() => {
          AlertDialog.show(
            {
              title: 'title',
              message: 'text'.repeat(20),
              autoCancel: true,
              alignment: DialogAlignment.Bottom,
              offset: { dx: 0, dy: -20 },
              gridCount: 3,
              confirm: {
                value: 'button',
                action: () => {
                  console.info('Button-clicking callback')
                }
              },
              cancel: () => {
                console.info('Closed callbacks')
              }
            }
          )
        })
        .backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

**Change Impacts**

The layout for the text specified by the **message** attribute of the alert dialog box is subject to the title and number of lines of the text.

**Key API/Component Changes**

N/A

**Adaptation Guide**

No proactive adaptation is required. You can also use **customDialog** for related implementation.

## cl.arkui.5 Avoidance Behavior Optimization of Popup

Before the change, the popup preferentially uses the lower area for avoidance. As a result, it cannot be displayed in the upper area even if the space is sufficient.

After the change: The popup preferentially uses the upper area for avoidance when it is configured to show above the target component; it preferentially uses the upper or lower area for avoidance when it is configured to show below the target component.

**Change Impacts**

The optimized popup avoidance behavior occurs when the **bindpopup** attribute is used.

**Key API/Component Changes**

N/A

**Adaptation Guide**

If the popup position is not as expected, you can adjust the **placement** settings.
