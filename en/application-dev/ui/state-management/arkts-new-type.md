# \@Type Decorator: Marking the Types of the Class Property
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:09:56.120Z pushedAt=2026-07-23T10:40:23.373Z -->

To prevent the loss of complex types of properties during class serialization, developers can use the [@Type](../../reference/apis-arkui/arkui-ts/ts-state-management-type.md#type) decorator to decorate class properties.

\@Type is used to mark class properties. Used together with **PersistenceV2**, \@Type can prevent class loss during serialization. Before reading this topic, you are advised to read [PersistenceV2](./arkts-new-persistencev2.md).

>**NOTE**
>
> \@Type is supported since API version 12.
>
> This decorator can be used in atomic services since API version 12.

## Overview

\@Type marks class properties to avoid losing type information during class property serialization, facilitating class deserialization.

## Decorator Description

| \@Type Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Parameters| Type.|
| Allowed type| Object class and embedded types such as Array, Date, Map, and Set.|

## Constraints

1. @Type can be used only in classes decorated with [\@ObservedV2](./arkts-new-observedV2-and-trace.md) and cannot be used in custom components.

   <!-- @[DataModel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NewType/entry/src/main/ets/pages/DataModel.ets) --> 

   ``` TypeScript
   class Sample {
     private data: number = 0;
   }
   @ObservedV2
   class Info {
     @Type(Sample)
     @Trace public sample: Sample = new Sample(); // Correct usage
   }
   ```

   ```ts
    @Observed
    class Info2 {
      @Type(Sample)
      sample: Sample = new Sample(); // Incorrect usage. @Type cannot be used in the @Observed decorated class. Otherwise, an error is reported during compilation.
    }
    @ComponentV2
    struct Index {
      @Type(Sample)
      sample: Sample = new Sample(); // Incorrect usage. @Type cannot be used in the customized component. Otherwise, an error is reported during compilation.
      build() {
      }
    }
   ```

2. Types such as **collections.Set** and **collections.Map** are not supported.

3. Non-built-in types, such as [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md), NativePointer, and [ArrayList](../../reference/apis-arkts/js-apis-arraylist.md), are not supported.

4. Simple types such as **string**, **number**, and **boolean**, are not supported.

5. Classes whose constructor functions contain parameters are not supported.

## Use Cases

### Saving Data for Persistence

<!-- @[NewType](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/NewType/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace childNumber: number = 1;
}

@ObservedV2
class Sample {
  // @Type is required for complex objects to ensure successful deserialization. If @Type is removed, deserialization fails.
  @Type(SampleChild)
  // If a class attribute does not have an initial value, it needs to be manually saved after being decorated with @Type. Otherwise, the persistence fails.
  // If a class attribute cannot be decorated with @Type, it must have an initial value to be persisted.
  @Trace sampleChild?: SampleChild = undefined;
}

@Entry
@ComponentV2
struct TestCase {
  @Local sample: Sample = PersistenceV2.connect(Sample, () => new Sample)!;

  build() {
    Column() {
      Text('childNumber value:' + this.sample.sampleChild?.childNumber)
        .fontSize(30)
        .margin(10)
        .onClick(() => {
          this.sample.sampleChild = new SampleChild();
          this.sample.sampleChild.childNumber = 2;
          PersistenceV2.save(Sample);
        })
    }
    .width('100%')
  }
}
```

![type-sync-0](./figures/type-sync-0.gif)