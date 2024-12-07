# \@Type Decorator: Marking the Types of the Class Property

To avoid losing complex types of the properties when serializing classes, you can use the \@Type Decorator to decorate class.

>**NOTE**
>
>\@Type is supported since API version 12.
>


## Overview

\@Type marks class properties to avoid losing type information during class property serialization, facilitating class deserialization.


## Decorator Description

| \@Type Decorator| Description|
| ------------------- | ------------------------------------------------------------ |
| Parameter| Type.|
| Allowed type| Object class and embedded types such as Array, Date, Map, and Set.|


## Constraints

1. \@Type can be used only in classes decorated by \@ObservedV2 and cannot be used in custom components.

```ts
class Sample {
  data: number = 0;
}
@ObservedV2
class Info {
  @Type(Sample)
  @Trace sample: Sample = new Sample(); // Correct usage.
}
@Observed
class Info2 {
  @Type(Sample)
  sample: Sample = new Sample(); // Incorrect usage. @Type cannot be used in the @Observed decorated class. Otherwise, an error is reported during compilation.
}
@ComponentV2
struct Index {
  @Type(Sample)
  sample: Sample = new Sample(); // Incorrect usage. @Type cannot be used in the custom component.
  build() {
  }
}
```

2. Types such as collections.Set and collections.Map are not supported.

3. Non-buildin types, such as native PixelMap, NativePointer, and ArrayList types, are not supported.

4. Simple types such as string, number, and boolean, are not supported.

## When to Use

### Saving Data for Persistence

Data page
```ts
import { Type } from '@kit.ArkUI';

// Data center
@ObservedV2
class SampleChild {
  @Trace p1: number = 0;
  p2: number = 10;
}

@ObservedV2
export class Sample {
  // Complex objects need to be decorated by @Type to ensure successful serialization.
  @Type(SampleChild)
  @Trace f: SampleChild = new SampleChild();
}
```

Page
```ts
import { PersistenceV2 } from '@kit.ArkUI';
import { Sample } from '../Sample';

@Entry
@ComponentV2
struct Page {
  prop: Sample = PersistenceV2.connect(Sample, () => new Sample())!;

  build() {
    Column() {
      Text(`Page1 add 1 to prop.p1: ${this.prop.f.p1}`)
        .fontSize(30)
        .onClick(() => {
          this.prop.f.p1++;
        })
    }
  }
}
```
