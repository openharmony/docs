# AppStorageV2: Storing Application-wide UI State

To enhance the capability of the state management framework to store global UI status variables of applications, you are advised to use AppStorageV2.

AppStorageV2 provides the capability of globally sharing state variables within an application. You can bind the same key through **connect** to share data across abilities.

Before reading this topic, you are advised to read [\@ComponentV2](./arkts-new-componentV2.md), [\@ObservedV2 and \@Trace](./arkts-new-observedV2-and-trace.md), and API reference of [AppStorageV2](../../reference/apis-arkui/js-apis-StateManagement.md#appstoragev2).

>**NOTE**
>
>AppStorageV2 is supported since API version 12.
>


## Overview

AppStorageV2 is a singleton to be created when the application UI is started. Its purpose is to provide central storage for application UI state attributes. And AppStorageV2 retains data during application running. Each attribute is accessed using a unique key, which is a string.

UI components synchronize application state attributes with AppStorageV2. AppStorageV2 can be accessed during implementation of application service logic as well.

AppStorageV2 supports state sharing among multiple UIAbility instances in the [main thread](../../application-models/thread-model-stage.md) of an application.


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
| Parameter        | **type**: specified type. If no **key** is specified, the name of the **type** is used as the **key**.<br> **keyOrDefaultCreator**: specified key or default constructor.<br> **defaultCreator**: default constructor.                                         |
| Return value      | After creating or obtaining data, value is returned. Otherwise, **undefined** is returned.|

>**NOTE**
>
>1. The third parameter is used when no **key** is specified or the second parameter is invalid, and the third parameter is used in all other cases.
>
>2. If the data has been stored in AppStorageV2, you can obtain the stored data without using the default constructor. If the data has not been stored, you must specify a default constructor; otherwise, an application exception will be thrown.
>
>3. Ensure that the data types match the key. Connecting different types of data to the same key will result in an application exception.
>
>4. You are advised to use meaningful values for keys. The values can contain letters, digits, and underscores (_) and a maximum of 255 characters. Using invalid characters or null characters will result in undefined behavior.
>
>5. When match the key with the [\@Observed](arkts-observed-and-objectlink.md) object, specify the key or customize the **name** attribute.

### remove: Deleting the Stored Data of a Specified Key

```JavaScript
static remove<T>(keyOrType: string | TypeConstructorWithArgs<T>): void;
```

| remove       | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | **keyOrType**: key to be deleted. If the key is of the **Type**, the key to be deleted is the name of the **Type**.                                         |
| Return value      | None.|

>**NOTE**
>
>If a key that does not exist in AppStorageV2 is deleted, a warning is reported.

### keys: Returning All Keys Stored in AppStorageV2

```JavaScript
static keys(): Array<string>;
```

| keys         | Description                                                 |
| ------------ | ----------------------------------------------------- |
| Parameter        | None.                                        |
| Return value      | All keys stored in AppStorageV2.|


## Constraints

1. This singleton must be used together with the UI thread only. Other threads, for example, @Sendable decorator is not supported.

2. Types such as collections.Set and collections.Map are not supported.

3. Non-buildin types, such as native PixelMap, NativePointer, and ArrayList types, are not supported.

## Use Scenarios

### Storing Data Between Two Pages

Data page
```ts
// Data center
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
  // Create a KV pair whose key is Sample in AppStorageV2 (if the key exists, the data in AppStorageV2 is returned) and associate it with prop.
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
            // Create a KV pair whose key is Sample in AppStorageV2 (if the key exists, the data in AppStorageV2 is returned) and associate it with prop.
            this.prop = AppStorageV2.connect(Sample, 'Sample', () => new Sample())!;
          })

        Button('Page1 remove the key Sample')
          .onClick(() => {
            // After being deleted from AppStorageV2, prop will no longer be associated with the value whose key is Sample.
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

        // Obtain all keys in the current AppStorageV2.
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
  // Create a KV pair whose key is Sample in AppStorageV2 (if the key exists, the data in AppStorageV2 is returned) and associate it with prop.
  @Local prop: Sample = AppStorageV2.connect(Sample, () => new Sample())!;
  pathStack: NavPathStack = new NavPathStack();

  build() {
    NavDestination() {
      Column() {
        Button('Page2 connect the key Sample1')
          .onClick(() => {
            // Create a KV pair whose key is Sample1 in AppStorageV2 (if the key exists, the data in AppStorageV2 is returned) and associate it with prop.
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

        // Obtain all keys in the current AppStorageV2.
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
When using **Navigation**, you need to add the **route_map.json** file to the **src/main/resources/base/profile** directory, replace the value of **pageSourceFile** with the path of **Page2**, and add **"routerMap": "$profile: route_map"** to the **module.json5** file.
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
