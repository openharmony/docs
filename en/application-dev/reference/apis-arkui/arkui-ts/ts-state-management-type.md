# @Type: Marking Types of Class Properties

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zhangboren-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=bbb682e63876992d34ec9fd16b00a36fec86c65e translatedAt=2026-08-13T07:02:27.268Z pushedAt=2026-08-14T03:31:02.733Z -->

**\@Type** is used in [state management V2](../../../ui/state-management/arkts-state-management-overview.md#state-management-v2) to ensure that the complex types of properties are not lost during class serialization. When persistence capabilities such as [PersistenceV2](../js-apis-stateManagement.md#persistencev2) are used to serialize and deserialize complex class objects, the property type information of the classes may be lost. By using **\@Type** to mark the original type of a property, you can ensure that the complex type information of the property is correctly retained and restored during serialization. This is applicable to scenarios where complex objects need to be persisted or serialized, such as persistent storage of application states and cross-component complex data transfer.

For details, see [@Type Decorator: Marking the Types of the Class Property](../../../ui/state-management/arkts-new-type.md).

> **NOTE**
>
> This decorator is supported since API version 12.

## @Type

const Type: TypeDecorator

Marks the original type of a property, ensuring that the complex type information of the property is correctly retained and restored during serialization.

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 12.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type               | Mandatory | Description               |
| ------ | ------------------ | ---- | ------------------ |
| type   | [TypeConstructor\<T\>](../js-apis-stateManagement.md#typeconstructort) | Yes   | Type of the class property to be marked. The value is the constructor of the corresponding class and must be the same as the type of the decorated property. |

**Example:**

```ts
import { PersistenceV2, Type } from '@kit.ArkUI';

@ObservedV2
class SampleChild {
  @Trace childNumber: number = 1;
}

@ObservedV2
class Sample {
  // Use @Type to mark the type of the sampleChild property as SampleChild.
  // Ensure that the complex type information of the property is not lost during serialization.
  @Type(SampleChild)
  @Trace sampleChild?: SampleChild = undefined;
}

@Entry
@ComponentV2
struct Index {
  // Use @Local to declare the internal state variable of the component.
  // Use PersistenceV2.connect to connect to persistent data. If the data does not exist, create a new Sample instance.
  @Local sample: Sample = PersistenceV2.connect(Sample, () => new Sample)!;

  build() {
    Column() {
      Text(`childNumber value: ${this.sample.sampleChild?.childNumber}`)
        .onClick(() => {
          this.sample.sampleChild = new SampleChild();
          this.sample.sampleChild.childNumber = 2;
          PersistenceV2.save(Sample);
        })
        .fontSize(30)
    }
  }
}
```