# Migration for Built-in Objects

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=5cbda8a742fe4c75db3800c28ccfc8ffcd9cebc0 translatedAt=2026-06-30T03:38:04.684Z pushedAt=2026-06-30T09:13:35.339Z -->

This document describes how to migrate built-in objects in a component from V1 to V2, involving the following decorators.

| V1 Decorator/Scenario| V2 Decorator|
| -------- | -------- |
| Scrollable component scenarios| [makeObserved](./arkts-new-makeObserved.md) |
| [Modifier](../arkts-user-defined-modifier.md) | [makeObserved](./arkts-new-makeObserved.md), [\@ObservedV2](./arkts-new-observedV2-and-trace.md), and [\@Trace](./arkts-new-observedV2-and-trace.md) |

## Scrollable Component

### List

You can use [ChildrenMainSize](../../reference/apis-arkui/arkui-ts/ts-container-list.md#childrenmainsize12) to set the size information about the child components of [List](../../reference/apis-arkui/arkui-ts/ts-container-list.md) along the main axis.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe API calls.

The following is an example:

<!-- @[Internal_Other_Migrations_List_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalOtherMigrationsListV1.ets) -->

``` TypeScript
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
      .childrenMainSize(this.listChildrenSize)
    }
  }
}
```

V2:

In V2, [@Local](./arkts-new-local.md) can only observe changes to the variable itself, but not its top-level changes. In addition, because **ChildrenMainSize** is defined by the **List** component framework, you cannot decorate its properties with [\@Trace](./arkts-new-observedV2-and-trace.md). You can use [makeObserved](./arkts-new-makeObserved.md) instead. Starting from API version 22, it is no longer required to use **makeObserved**; you can directly use \@Local-annotated **ChildrenMainSize** to set the size information about the child components of **List** along the main axis.

The following is an example:

<!-- @[Internal_Other_Migrations_List_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalOtherMigrationsListV2.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct ListExample {
  private arr: Array<number> = new Array(10).fill(0);
  private scroller: ListScroller = new ListScroller();
  listSpace: number = 10;
  // Use makeObserved to enable observation of ChildrenMainSize changes.
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
      .childrenMainSize(this.listChildrenSize)
    }
  }
}
```

### WaterFlow

You can use [WaterFlowSections](../../reference/apis-arkui/arkui-ts/ts-container-waterflow.md#waterflowsections12) to configure sections in a **WaterFlow** component.

Note that the length of array **arr** must match the total sum of **itemsCount** values across all **SectionOptions** in **WaterFlowSections**. Mismatch will prevent proper **WaterFlow** processing and cause UI re-render issues.

The following two examples show buttons **push option**, **splice option**, and **update option** are clicked in sequence.

V1:

In V1, you can use [\@State](./arkts-state.md) to observe API calls.

The following is an example:

<!-- @[Internal_Other_Migrations_WaterFlow_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalOtherMigrationsWaterFlowV1.ets) --> 

``` TypeScript
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

      // @State decorates sections, allowing observation of changes caused by calling the WaterFlowSections API.
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
        this.arr = new Array(16).fill(1);
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

In V2, [@Local](./arkts-new-local.md) can only observe changes to the variable itself, but not its top-level changes. In addition, because **WaterFlowSections** is defined by the framework, you cannot decorate its properties with [@Trace](./arkts-new-observedV2-and-trace.md). You can use [makeObserved](./arkts-new-makeObserved.md) instead.

The following is an example:

<!-- @[Internal_Other_Migrations_WaterFlow_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalOtherMigrationsWaterFlowV2.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';

@Entry
@ComponentV2
struct WaterFlowSample {
  colors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Blue, Color.Pink];
  // Use makeObserved to enable observation of WaterFlowSections changes.
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
        this.arr = new Array(16).fill(1);
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

## Modifier

### attributeModifier

You can use [attributeModifier](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#attributemodifier) to dynamically set component attributes.

V1:

In V1, you can use [@State](./arkts-state.md) to observe changes.

The following is an example:

<!-- @[Internal_attribute_Modifier_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalattributeModifierV1.ets) --> 

``` TypeScript
class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  public isDark: boolean = false;

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
            // In V1 state management, @State can be used to observe changes to modifier.
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

In V2, [@Local](./arkts-new-local.md) can only observe changes to the variable itself, but not its top-level changes. To observe the attribute changes of **attributeModifier**, use [makeObserved](./arkts-new-makeObserved.md) instead.

The following is an example:

<!-- @[Internal_attribute_Modifier_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalattributeModifierV2.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';

class MyButtonModifier implements AttributeModifier<ButtonAttribute> {
  public isDark: boolean = false;

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
  // Use makeObserved to enable property (this.modifier) observation for attributeModifier.
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

### CommonModifier

A class for dynamically setting component attributes. Take [Custom Modifiers](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#custom-modifiers) as an example.

V1:

In V1, you can use [@State](./arkts-state.md) to observe changes.

The following is an example:

<!-- @[Internal_Common_Modifier_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalCommonModifierV1.ets) --> 

``` TypeScript
import { CommonModifier } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

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
    // 'app.media.app_icon' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
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
          hilog.info(DOMAIN, 'testTag', 'Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.myModifier as MyModifier).setGroup1();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup1');
          } else {
            (this.myModifier as MyModifier).setGroup2();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup2');
          }
        })

      MyImage1({ modifier: this.myModifier })
    }
    .width('100%')
  }
}
```

V2:

In state management V2, [@Local](./arkts-new-local.md) can only observe its own changes and cannot observe first-level changes. Additionally, because the [custom modifiers](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-attribute-modifier.md#custom-modifier) trigger refresh through its attributes within the framework, [makeObserved](./arkts-new-makeObserved.md) can be used as an alternative.

The following is an example:

<!-- @[Internal_Common_Modifier_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalCommonModifierV2.ets) -->

``` TypeScript
import { UIUtils, CommonModifier } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

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
    // 'app.media.app_icon' is only an example. Replace it with the actual one in use. Otherwise, the imageSource instance fails to be created, and subsequent operations cannot be performed.
    Image($r('app.media.app_icon'))
      .attributeModifier(this.modifier as MyModifier)
  }
}

@Entry
@ComponentV2
struct Index {
  // Use makeObserved to enable observation of CommonModifier changes.
  @Local myModifier: CommonModifier = UIUtils.makeObserved(new MyModifier().width(100).height(100).margin(10));
  index: number = 0;

  build() {
    Column() {
      Button($r('app.string.EntryAbility_label'))
        .margin(10)
        .onClick(() => {
          hilog.info(DOMAIN, 'testTag', 'Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.myModifier as MyModifier).setGroup1();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup1');
          } else {
            (this.myModifier as MyModifier).setGroup2();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup2');
          }
        })

      MyImage1({ modifier: this.myModifier })
    }
    .width('100%')
  }
}
```

### Component Modifier

The component modifier is used to dynamically set component attributes. The following uses the **Text** component as an example.

V1:

In V1, you can use [@State](./arkts-state.md) to observe changes.

The following is an example:

<!-- @[Internal_Module_Modifier_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalModuleModifierV1.ets) -->  

``` TypeScript
import { TextModifier } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

class MyModifier extends TextModifier {
  applyNormalAttribute(instance: TextAttribute): void {
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
          // Change the index value by clicking to dynamically set the attribute class of Text
          hilog.info(DOMAIN, 'testTag', 'Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.modifier as MyModifier).setGroup1();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup1');
          } else {
            (this.modifier as MyModifier).setGroup2();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup2');
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

In V2, [@Local](./arkts-new-local.md) can only observe its own changes, but cannot observe the top-level changes. You can use [makeObserved](./arkts-new-makeObserved.md) instead.

The following is an example:

<!-- @[Internal_Module_Modifier_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalModuleModifierV2.ets) --> 

``` TypeScript
import { UIUtils, TextModifier } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

class MyModifier extends TextModifier {
  applyNormalAttribute(instance: TextAttribute): void {
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
          hilog.info(DOMAIN, 'testTag', 'Modifier', 'onClick');
          this.index++;
          if (this.index % 2 === 1) {
            (this.modifier as MyModifier).setGroup1();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup1');
          } else {
            (this.modifier as MyModifier).setGroup2();
            hilog.info(DOMAIN, 'testTag', 'Modifier', 'setGroup2');
          }
        })
    }
  }
}

@Entry
@ComponentV2
struct Index {
  // Use makeObserved to enable observation of TextModifier changes.
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

### AttributeUpdater

[AttributeUpdater](../arkts-user-defined-extension-attributeUpdater.md) allows attributes to be directly applied to components, enabling UI updates without marking them as state variables.

V1:

In V1, you can change the **flag** property in **MyButtonModifier** to update the attributes bound to the **Button**. Because \@State supports observation of both the object itself and its top-level properties, simply decorating **AttributeUpdater** with \@State is enough to listen for changes and trigger updates.

<!-- @[Internal_Attribute_Updater_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAttributeUpdaterV1.ets) -->

``` TypeScript
// xxx.ets
import { AttributeUpdater } from '@kit.ArkUI';

class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  public flag: boolean = false;

  initializeModifier(instance: ButtonAttribute): void {
    instance.backgroundColor('#ff2787d9')
      .width('50%')
      .height(30)
  }

  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.flag) {
      instance.borderWidth(2);
    } else {
      instance.borderWidth(10);
    }
  }
}

@Entry
@Component
struct Index {
  @State modifier: MyButtonModifier = new MyButtonModifier();

  build() {
    Row() {
      Column() {
        Button('Button')
          .attributeModifier(this.modifier)
        Button('Update')
          .onClick(() => {
            this.modifier.flag = !this.modifier.flag;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

V2:

Unlike in V1, \@Local in V2 only observes changes to the object itself. Therefore, **MyButtonModifier** must be decorated with \@ObservedV2, and the **flag** property must be decorated with \@Trace. In addition, **flag** must be accessed during component creation to establish its dependency with the **Button** component. In this scenario, it should be accessed in **initializeModifier** (as shown below); otherwise, the dependency will not be established.

<!-- @[Internal_Attribute_Updater_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/internalmigrate/InternalAttributeUpdaterV2.ets) -->

``` TypeScript
// xxx.ets
import { AttributeUpdater } from '@kit.ArkUI';

@ObservedV2
class MyButtonModifier extends AttributeUpdater<ButtonAttribute> {
  @Trace public flag: boolean = false;

  initializeModifier(instance: ButtonAttribute): void {
    // initializeModifier is called during component initialization. Accessing flag here ensures it is bound with the Button component.
    this.flag;
    instance.backgroundColor('#ff2787d9')
      .width('50%')
      .height(30)
  }

  applyNormalAttribute(instance: ButtonAttribute): void {
    if (this.flag) {
      instance.borderWidth(2);
    } else {
      instance.borderWidth(10);
    }
  }
}

@Entry
@ComponentV2
struct Index {
  // In V2, decorators only observe this layer, that is, changes when modifier is reassigned.
  @Local modifier: MyButtonModifier = new MyButtonModifier();

  build() {
    Row() {
      Column() {
        Button('Button')
          .attributeModifier(this.modifier)
        Button('Update')
          .onClick(() => {
            this.modifier.flag = !this.modifier.flag;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
<!--no_check-->