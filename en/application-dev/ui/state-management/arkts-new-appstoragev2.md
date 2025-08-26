# AppStorageV2: Storing Application-wide UI State
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

To enhance the capability of the state management framework to store global UI status variables of applications, you are advised to use AppStorageV2.

AppStorageV2 provides the capability of globally sharing state variables within an application. You can bind the same key through **connect** to share data across abilities.

Before reading this topic, you are advised to read [\@ComponentV2](./arkts-new-componentV2.md), [\@ObservedV2 and \@Trace](./arkts-new-observedV2-and-trace.md), and [AppStorageV2 API reference](../../reference/apis-arkui/js-apis-StateManagement.md#appstoragev2).

>**NOTE**
>
>AppStorageV2 is supported since API version 12.
>

## Overview

AppStorageV2 is a singleton created when the application UI is started. It provides central storage for application state data that is accessible at the application level and remains persistent throughout the application lifecycle. Properties in AppStorageV2 are accessed using unique key strings. It should be noted that data between AppStorage and AppStorageV2 is not shared.

The **connect** API of AppStorageV2 enables customizable synchronization between stored data and UI components.

AppStorageV2 supports state sharing among multiple UIAbility instances in the [main thread](../../application-models/thread-model-stage.md) of the same application.

## How to Use

### connect: Creating or Obtaining Stored Data

```JavaScript
static connect<T extends object>(
    type: TypeConstructorWithArgs<T>,
    keyOrDefaultCreator?: string | StorageDefaultCreator<T>,
    defaultCreator?: StorageDefaultCreator<T> 
): T | undefined;
```

| connect      | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameters        | **type**: specified type. If no **key** is specified, the name of the **type** is used as the **key**.<br>**keyOrDefaultCreator**: specified key or default constructor.<br>**defaultCreator**: default constructor.                                         |
| Return value      | Returns the data if creation or acquisition is successful; otherwise, returns **undefined**.|

>**NOTE**
>
>1. The second parameter is used when no **key** is specified, and the third parameter is used otherwise (including when the second parameter is invalid).
>
>2. If the data has been stored in AppStorageV2, you can obtain the stored data without using the default constructor. If the data has not been stored, you must specify a default constructor; otherwise, an application exception will be thrown.
>
>3. Ensure that the data types match the key. Connecting different types of data to the same key will result in an application exception.
>
>4. You are advised to use meaningful values for keys. The values can contain letters, digits, and underscores (_) and a maximum of 255 characters. Using invalid characters or null characters will result in undefined behavior.
>
>5. When matching the key with the [\@Observed](arkts-observed-and-objectlink.md) object, specify the key or customize the **name** property.

### remove: Deleting the Stored Data of a Specified Key

```JavaScript
static remove<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| remove       | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameters        | **keyOrType**: key to be deleted. If the key is of the **Type**, the key to be deleted is the name of the **Type**.                                         |
| Return value      | N/A|

>**NOTE**
>
>If a key that does not exist in AppStorageV2 is deleted, a warning is reported.

### keys: Returning All Keys Stored in AppStorageV2

```JavaScript
static keys(): Array<string>;
```

| keys         | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameters        | N/A                                        |
| Return value      | All keys stored in AppStorageV2.|


## Constraints

1. This singleton must be used together with the UI thread only. Other threads, for example, @Sendable decorator is not supported.

2. Types such as **collections.Set** and **collections.Map** are not supported.

3. Non-built-in types, such as PixelMap, NativePointer, ArrayList, and other native types, are not supported.

4. Primitive types, such as string, number, and boolean, are not supported.

## Use Scenarios

### Using AppStorageV2

AppStorageV2 provides the **connect** API to enable data modification and synchronization. When modified data is decorated with @Trace, changes automatically trigger UI re-rendering. Note that the **remove** API only deletes data from AppStorageV2 without affecting already instantiated component data.

```ts
import { AppStorageV2 } from '@kit.ArkUI';

@ObservedV2
class Message {
  @Trace userID: number;
  userName: string;

  constructor(userID?: number, userName?: string) {
    this.userID = userID ?? 1;
    this.userName = userName ?? 'Jack';
  }
}

@Entry
@ComponentV2
struct Index {
  // Use connect to create an object with key Message in AppStorageV2.
  // Changes to the return value of connect will be synchronized back to AppStorageV2.
  @Local message: Message = AppStorageV2.connect<Message>(Message, () => new Message())!;

  build() {
    Column() {
      // Modifying class properties decorated with @Trace will synchronously update the UI.
      Button(`Index userID: ${this.message.userID}`)
        .onClick(() => {
          this.message.userID += 1;
        })
      // Modifying class properties not decorated with @Trace will not update the UI, but changes are still synchronized back to AppStorageV2.
      Button(`Index userName: ${this.message.userName}`)
        .onClick(() => {
          this.message.userName += 'suf';
        })
      // Clicking the button deletes the object with key Message from AppStorageV2.
      // After removal, changes to the parent component's userId are still synchronized to the child component, because remove only deletes the object from AppStorageV2 and does not affect the existing component data.
      Button('remove key: Message')
        .onClick(() => {
          AppStorageV2.remove<Message>(Message);
        })
      // Clicking the button adds an object with key Message to AppStorageV2.
      // After removal, when the key is re-added and the userID in both parent and child components is modified, it is found that the data is out of sync. Once the child component reconnects via connect(), the data becomes consistent again.
      Button('connect key: Message')
        .onClick(() => {
          this.message = AppStorageV2.connect<Message>(Message, () => new Message(5, 'Rose'))!;
        })
      Divider()
      Child()
    }
    .width('100%')
    .height('100%')
  }
}

@ComponentV2
struct Child {
  // Use connect to obtain the object with key Message from AppStorageV2 (created in the parent component).
  @Local message: Message = AppStorageV2.connect<Message>(Message, () => new Message())!;
  @Local name: string = this.message.userName;

  build() {
    Column() {
      // Modifying @Trace decorated properties updates the UI, and the change is propagated to the parent component.
      Button(`Child userID: ${this.message.userID}`)
        .onClick(() => {
          this.message.userID += 5;
        })
      // After the userName property is modified in the parent component, clicking the name button synchronizes the parent's class property changes.
      Button(`Child name: ${this.name}`)
        .onClick(() => {
          this.name = this.message.userName;
        })
      // Clicking the button deletes the object with key Message from AppStorageV2.
      Button('remove key: Message')
        .onClick(() => {
          AppStorageV2.remove<Message>(Message);
        })
      // Clicking the button adds an object with key Message to AppStorageV2.
      Button('connect key: Message')
        .onClick(() => {
          this.message = AppStorageV2.connect<Message>(Message, () => new Message(10, 'Lucy'))!;
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

### Storing Data Between Two Pages

Data page
```ts
// Data center.
// Sample.ets
@ObservedV2
export class Sample {
  @Trace p1: number = 0;
  p2: number = 10;
}
```

Page 1
```ts
// Page1.ets
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Entry
@ComponentV2
struct Page1 {
  // Create a key-value pair with Sample as the key in AppStorageV2 (if the key exists, existing data in AppStorageV2 is returned) and associate it with prop.
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pageStack: NavPathStack = new NavPathStack();

  build() {
    Navigation(this.pageStack) {
      Column() {
        Button('Go to page2')
          .onClick(() => {
            this.pageStack.pushPathByName('Page2', null);
          })

        Button('Page1 connect the key Sample')
          .onClick(() => {
            // Create a key-value pair with Sample as the key in AppStorageV2 (if the key exists, existing data in AppStorageV2 is returned) and associate it with prop.
            this.prop = AppStorageV2.connect(Sample, 'Sample', () => new Sample())!;
          })

        Button('Page1 remove the key Sample')
          .onClick(() => {
            // After deletion from AppStorageV2, prop will no longer be associated with the value whose key is Sample.
            AppStorageV2.remove(Sample);
          })

        Text(`Page1 add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`Page1 add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .onClick(() => {
            // The page is not re-rendered, but the value of p2 is changed.
            this.prop.p2++;
          })

        // Obtain all current keys in AppStorageV2.
        Text(`all keys in AppStorage: ${AppStorageV2.keys()}`)
          .fontSize(30)
      }
    }
  }
}
```

Page 2
```ts
// Page2.ets
import { AppStorageV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Builder
export function Page2Builder() {
  Page2()
}

@ComponentV2
struct Page2 {
  // Create a key-value pair with Sample as the key in AppStorageV2 (if the key exists, existing data in AppStorageV2 is returned) and associate it with prop.
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Button('Page2 connect the key Sample1')
          .onClick(() => {
            // Create a key-value pair with Sample1 as the key in AppStorageV2 (if the key exists, existing data in AppStorageV2 is returned) and associate it with prop.
            this.prop = AppStorageV2.connect(Sample, 'Sample1', () => new Sample())!;
          })

        Text(`Page2 add 1 to prop.p1: ${this.prop.p1}`)
          .fontSize(30)
          .onClick(() => {
            this.prop.p1++;
          })

        Text(`Page2 add 1 to prop.p2: ${this.prop.p2}`)
          .fontSize(30)
          .onClick(() => {
            // The page is not re-rendered, but the value of p2 is changed, which is performed after re-initialization.
            this.prop.p2++;
          })

        // Obtain all current keys in AppStorageV2.
        Text(`all keys in AppStorage: ${AppStorageV2.keys()}`)
          .fontSize(30)
      }
    }
    .onReady((context: NavDestinationContext) => {
      this.pathStack = context.pathStack;
    })
  }
}
```
When using **Navigation**, create a **route_map.json** file as shown below in the **src/main/resources/base/profile** directory, replacing the value of **pageSourceFile** with the actual path to **Page2**. Then, add **"routerMap": "$profile: route_map"** to the **module.json5** file.
```json
{
  "routerMap": [
    {
      "name": "Page2",
      "pageSourceFile": "src/main/ets/pages/Page2.ets",
      "buildFunction": "Page2Builder",
      "data": {
        "description" : "AppStorageV2 example"
      }
    }
  ]
}
```
