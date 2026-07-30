# canBeObserved接口：判断对象是否可被观察
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

为了判断对象是否为可被观察对象和获取对象关联的组件信息，开发者可以使用[canBeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#canbeobserved23)。

在使用该接口前，建议开发者对状态管理框架有基本的了解。提前阅读：[状态管理概述](./arkts-state-management-overview.md)。

>**说明：**
>
>从API version 23开始，开发者可以使用UIUtils中的canBeObserved接口判断数据对象是否为可观察对象。

## 概述

在开发和调试过程中，开发者会遇到修改对象的值后UI页面不刷新的问题（详见[状态管理常见问题](./arkts-state-management-faq.md)），在复杂业务中排查此类问题尤为不便。为此，提供了canBeObserved接口帮助开发者定位和分析问题。开发者使用该接口不仅可以判断对象是否为可被观察的对象，还能获取对象关联的组件信息。

使用canBeObserved接口需要导入UIUtils工具。

```ts
import { UIUtils } from '@kit.ArkUI';
```

## 限制条件

canBeObserved仅支持非空的对象类型传参。如果传入`undefined`或`null`，`isObserved`返回`false`。如果传入非Object类型，则会编译报错。

``` ts
import { UIUtils } from '@kit.ArkUI';

let res1 = UIUtils.canBeObserved(2); // 非法类型入参，错误用法，编译报错
let res2 = UIUtils.canBeObserved(undefined); // 非法类型入参，错误用法，isObserved返回false
let res3 = UIUtils.canBeObserved(null); // 非法类型入参，错误用法，isObserved返回false

class User {
  name?: string;
}

let result: ObservedResult = UIUtils.canBeObserved(new User()); // 正确用法
```

## 对象可被观察场景

可被观察对象调用canBeObserved接口，返回的[ObservedResult](../../reference/apis-arkui/js-apis-stateManagement.md#observedresult23)结果对象中`reason`的值包含以下情况：

| reason值 | 说明 |
| ---- | ---- |
| The object data is decorated with @Observed or wrapped by makeV1Observed | 对象被[@Observed](./arkts-observed-and-objectlink.md)装饰器装饰或对象是使用[makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19)方法包装得到的，详见[V1组件对象可被观察场景](#v1组件对象可被观察场景) 。|
| The object data is decorated with V2 @ObservedV2 and @Trace | 对象和对象属性被[@ObservedV2和@Trace](./arkts-new-observedV2-and-trace.md)装饰器装饰，详见[V2组件对象可被观察场景](#v2组件对象可被观察场景) 。|
| The object data is wrapped by V2's makeObserved | 对象是使用[makeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#makeobserved)方法包装得到的，详见[V2组件对象可被观察场景](#v2组件对象可被观察场景) 。|
| The object data is built-in type proxy data (Array/Map/Set/Date) decorated with @Trace | Array、Set、Map、Date类型数据对象被状态管理V2装饰器装饰或作为对象属性被[@Trace](./arkts-new-observedV2-and-trace.md)装饰器装饰，详见[V2组件对象可被观察场景](#v2组件对象可被观察场景) 。 |
| The V1 Observed object data is wrapped by enableV2Compatibility and used in @ComponentV2 | V1组件和V2组件混用时，对象是使用[enableV2Compatibility](./arkts-v1-v2-mixusage.md#enablev2compatibility)方法包装得到的，详见[V1组件和V2组件混用对象可被观察场景](#v1组件和v2组件混用对象可被观察场景) 。|

需要注意，上述情况`reason`的值结尾如果有`but not used in UI`或`but not used in @ComponentV2`则表示：对象虽然是可被观察的，但是没有被UI组件所使用，因此改变对象值的时候也无法刷新UI。

### V1组件对象可被观察场景

在V1组件中，可被观察对象场景如下：
- 组件内被状态管理V1装饰器装饰的对象（包括Array、Set、Map、Date类型数据对象）。
- 被[@Observed](./arkts-observed-and-objectlink.md)装饰器装饰的对象。
- 使用[makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19)方法包装的对象。

其中状态管理V1装饰器指的是：[@State](./arkts-state.md)、[@Prop](./arkts-prop.md)、[@Link](./arkts-link.md)、[@ObjectLink](./arkts-observed-and-objectlink.md)、[@StorageLink](./arkts-appstorage.md#storagelink)、[@StorageProp](./arkts-appstorage.md#storageprop)、[@LocalStorageLink](./arkts-localstorage.md#localstoragelink)、[@LocalStorageProp](./arkts-localstorage.md#localstorageprop)、[@Provide](./arkts-provide-and-consume.md)、[@Consume](./arkts-provide-and-consume.md)。

被[@Observed](./arkts-observed-and-objectlink.md)装饰的对象和使用[makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19)包装的对象，如果在组件内没有状态管理V1装饰器装饰，调用canBeObserved接口返回结果如下：

``` json5
{
    // 被@Observed装饰的对象和使用makeV1Observed方法包装的对象，是可被观察的对象
    "isObserved": true,
    // 如果在组件内没有状态管理V1装饰器装饰，reason会返回：没有被UI组件使用，也就不会刷新UI
    // V1组件刷新依赖的是状态管理V1装饰器
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed, but not used in UI",
    // 收集不到状态管理装饰器
    "decoratorInfo": []
}
```

**组件内被状态管理V1装饰器装饰的对象**

以下介绍组件中使用[@State](./arkts-state.md)装饰器装饰对象，使其变成可被观察对象的使用场景。

示例代码：

<!-- @[v1_state](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/V1State.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = 'CanBeObserved';

class StateUser {
  public name?: string;
  public age?: number;

  constructor(name?: string, age?: number) {
    this.name = name ?? '';
    this.age = age ?? 0;
  }

  // 在对象中提供判断该对象是否为可被观察对象的方法
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@Component
struct V1State {
  // V1组件中使用@State装饰对象时，会将该对象变成可被观察对象
  @State stateUser: StateUser = new StateUser('James', 33);

  build() {
    Column({ space: 20 }) {
      // 组件使用了可被观察对象的属性
      Text('user name: ' + this.stateUser.name)
      // 组件使用了可被观察对象的属性
      Text('user age: ' + this.stateUser.age)
      Button('test')
        .onClick(() => {
          // 开发者可以在任意页面中使用接口来判断当前对象是否为可被观察对象，并且可被获取对象关联的组件信息
          this.stateUser.test();
        })

    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}
```

返回结果：

``` json5
{
    // 对象是可被观察的
    "isObserved": true,
    // V1组件中被状态管理装饰器装饰的对象是可被观察的
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    // 收集对象的装饰器信息
    "decoratorInfo": [{
        // 装饰器的名称
        "decoratorName": "@State",
        // 装饰器装饰的属性名称
        "stateVariableName": "stateUser",
        // 装饰器所在的组件名称
        "owningComponentOrClassName": "V1State",
        // 装饰器所在的组件id
        "owningComponentId": 4,
        // 对象关联的组件信息
        "dependentInfo": [{
            // 组件名称
            "elementName": "Text",
            // 组件id
            "elementId": 6
        }, {
            "elementName": "Text",
            "elementId": 7
        }]
    }]
}
```

**被@Observed装饰器装饰的对象**

以下介绍对象使用[@Observed](./arkts-observed-and-objectlink.md)装饰器装饰，且对象属性使用[@Track](./arkts-track.md)装饰器装饰的使用场景。

示例代码：

<!-- @[v1_track](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/V1Track.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = 'CanBeObserved';

@Observed
class TrackUser {
  @Track
  public name?: string;
  @Track
  public age?: number;

  constructor(name?: string, age?: number) {
    this.name = name ?? '';
    this.age = age ?? 0;
  }

  // 在对象中提供判断该对象是否为可被观察对象的方法
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@Component
struct V1Track {
  @State trackUser: TrackUser = new TrackUser('Robert', 25);

  build() {
    Column({ space: 20 }) {
      TrackChild({ trackUser: this.trackUser })
      Button('test')
        .onClick(() => {
          // 开发者可以在任意页面中使用接口来判断当前对象是否为可被观察对象，并且可被获取对象关联的组件信息
          this.trackUser.test();
        })
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}

@Component
struct TrackChild {
  @ObjectLink trackUser: TrackUser;

  build() {
    Column() {
      // 组件中使用可被观察对象的属性
      Text('user name: ' + this.trackUser.name)
      // 组件中使用可被观察对象的属性
      Text('user age: ' + this.trackUser.age)
    }
  }
}
```

对象属性使用[@Track](./arkts-track.md)装饰器时，其装饰器信息的收集规格与V2组件装饰器收集规格一致，可参考[V2组件对象可被观察场景](#v2组件对象可被观察场景)。

返回结果：

``` json5
{
    // 对象可被观察
    "isObserved": true,
    // 使用@Observed装饰器装饰的对象是可被观察对象
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    // 对象属性使用了@Track装饰器，装饰器信息收集规格与V2组件的收集规格一致
    "decoratorInfo": [{
        // 对象属性使用了@Track装饰时，装饰器名称固定为@Track
        "decoratorName": "@Track",
        // 对象属性使用了@Track装饰时，stateVariableName表示被@Track装饰是的属性名称
        "stateVariableName": "name",
        // 对象属性使用了@Track装饰时，owningComponentOrClassName表示类的名称
        "owningComponentOrClassName": "TrackUser",
        // owningComponentOrClassName为类名称时，owningComponentId固定返回-1
        "owningComponentId": -1,
        // 对象的name属性关联的组件信息
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 10
        }]
    }, {
        "decoratorName": "@Track",
        "stateVariableName": "age",
        "owningComponentOrClassName": "TrackUser",
        "owningComponentId": -1,
        // 对象的age属性关联的组件信息
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 11
        }]
    }]
}
```

### V2组件对象可被观察场景

V2组件中，对象可被观察场景如下：
- 被[@ObservedV2](./arkts-new-observedV2-and-trace.md)装饰器装饰的对象。
- 被状态管理V2装饰器装饰的Array、Set、Map、Date类型数据对象。
- 使用[makeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#makeobserved)方法包装的对象。

其中状态管理V2装饰器指的是：[@Local](./arkts-new-local.md)、[@Param](./arkts-new-param.md)、[@Provider](./arkts-new-provider-and-consumer.md)、[@Consumer](./arkts-new-provider-and-consumer.md)。

V2组件收集装饰器的规格与V1组件不同，V2组件收集装饰器信息时，是按照对象的@Trace装饰的属性进行分类收集的。以下面的TestClass为例，@Trace将以属性为单位展示关联组件的信息：
``` TypeScript
// 定义Class
@ObservedV2
class TestClass {
  @Trace a?: string;
  @Trace b?: string;
  @Trace c?: string;
}
```
``` json5
// 返回结果分析
{
    // 对象是可被观察的
    "isObserved": true,
    "reason": "The object data is decorated with V2 @ObservedV2 and @Trace",
    // 装饰器信息是按照@Trace装饰的属性进行分类收集
    "decoratorInfo": [{
        "decoratorName": "@Trace",
        // 对象中@Trace属性的名称
        "stateVariableName": "a",
        // 对象的类名称
        "owningComponentOrClassName": "TestClass",
        // owningComponentId固定返回-1
        "owningComponentId": -1,
        // 同一个@Trace属性关联的组件信息集合在一起
        "dependentInfo": [{
            "elementId": 5,
            "elementName": "Text"
        }]
    },{
        "decoratorName": "@Trace",
        "stateVariableName": "b",
        "owningComponentOrClassName": "TestClass",
        "owningComponentId": -1,
        // 同一个@Trace属性关联的组件信息集合在一起
        "dependentInfo": [{
            "elementId": 6,
            "elementName": "Text"
        }]
    },{
        "decoratorName": "@Trace",
        "stateVariableName": "c",
        "owningComponentOrClassName": "TestClass",
        "owningComponentId": -1,
        // 同一个@Trace属性关联的组件信息集合在一起
        "dependentInfo": [{
            "elementId": 7,
            "elementName": "Text"
        }]
    }]
}
```

**被@ObservedV2装饰器装饰的对象**

以下介绍V2组件中使用[@ObservedV2](./arkts-new-observedV2-and-trace.md)装饰器装饰对象的使用场景。

示例代码：

<!-- @[v2_local](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/V2Local.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = 'CanBeObserved';

@ObservedV2
class LocalUser {
  @Trace
  public name?: string;
  @Trace
  public age?: number;

  constructor(name?: string, age?: number) {
    this.name = name ?? '';
    this.age = age ?? 0;
  }

  // 在对象中提供判断该对象是否为可被观察对象的方法
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@ComponentV2
struct V2Local {
  @Local localUser: LocalUser = new LocalUser('Michael', 29);

  build() {
    Column({ space: 20 }) {
      Text('index ' + this.localUser.name)
      Text('index ' + this.localUser.age)
      Button('test')
        .onClick(() => {
          // 开发者可以在任意页面中使用接口来判断当前对象是否为可被观察对象
          this.localUser.test();
        })
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}
```

返回结果：

``` json5
{
    // 对象是可被观察的
    "isObserved": true,
    // @ObservedV2装饰的对象是可被观察的
    "reason": "The object data is decorated with V2 @ObservedV2 and @Trace",
    // 对象上装饰器信息，按@Trace装饰的属性分类收集
    "decoratorInfo": [{
        // 装饰器名称固定为@Trace
        "decoratorName": "@Trace",
        // @Trace装饰的属性名称
        "stateVariableName": "name",
        // 对象类名称
        "owningComponentOrClassName": "LocalUser",
        // owningComponentId固定返回-1
        "owningComponentId": -1,
        // 对象的name属性关联的组件信息
        "dependentInfo": [{
            "elementId": 6,
            "elementName": "Text"
        }]
    }, {
        "decoratorName": "@Trace",
        "stateVariableName": "age",
        "owningComponentOrClassName": "LocalUser",
        "owningComponentId": -1,
        // 对象的age属性关联的组件信息
        "dependentInfo": [{
            "elementId": 7,
            "elementName": "Text"
        }]
    }]
}
```

### V1组件和V2组件混用对象可被观察场景

V1组件和V2组件混用的场景中，要使对象能在V1组件和V2组件保持同步刷新，则需要在V1组件中使用[enableV2Compatibility](./arkts-v1-v2-mixusage.md#enablev2compatibility)方法将V1组件的可被观察对象包装后传入V2组件。

代码示例：

<!-- @[v1_and_v2_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/V1AndV2Compatibility.ets) -->

``` TypeScript
import { UIUtils } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = 'CanBeObserved';

class CompatibilityUser {
  public name?: string;
  public age?: number;

  constructor(name?: string, age?: number) {
    this.name = name ?? '';
    this.age = age ?? 0;
  }

  // 在对象中提供判断该对象是否为可被观察对象的方法
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@Component
struct V1AndV2Compatibility {
  // 被enableV2Compatibility转换的V1对象必须是可被观察的V1对象
  @State temp: CompatibilityUser = new CompatibilityUser('Thomas', 43);
  @State compatibilityUser: CompatibilityUser = UIUtils.enableV2Compatibility(this.temp);

  build() {
    Column({ space: 20 }) {
      Text('V1 name: ' + this.compatibilityUser.name)
      Text('V1 age: ' + this.compatibilityUser.age)

      V2Child({ compatibilityUser: this.compatibilityUser })

      Button('test')
        .onClick(() => {
          // 开发者可以在任意页面中使用接口来判断当前对象是否为可被观察对象
          this.compatibilityUser.test();
        })
    }
    .height('100%')
    .width('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}

@ComponentV2
export struct V2Child {
  @Param compatibilityUser: CompatibilityUser = new CompatibilityUser();

  build() {
    Column() {
      Text('V2Child name ' + this.compatibilityUser.name)
      Text('V2Child age ' + this.compatibilityUser.age)
    }
  }
}
```

返回结果：

``` json5
{
    // 对象是可被观察的
    "isObserved": true,
    // 通过enableV2Compatibility方法转换的对象也是可被观察的
    "reason": "The V1 Observed object data is wrapped by enableV2Compatibility and used in @ComponentV2",
    // 装饰器信息，V1组件和V2组件分别收集
    "decoratorInfo": [{
        "decoratorName": "@State",
        "stateVariableName": "temp",
        "owningComponentOrClassName": "V1AndV2Compatibility",
        "owningComponentId": 4,
        "dependentInfo": []
    }, {
        "decoratorName": "@State",
        "stateVariableName": "compatibilityUser",
        "owningComponentOrClassName": "V1AndV2Compatibility",
        "owningComponentId": 4,
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 6
        }, {
            "elementName": "Text",
            "elementId": 7
        }, {
            "elementName": "V2Child",
            "elementId": 8
        }]
    }, {
        // V2组件的decoratorName名称固定EnableV2Compatible
        "decoratorName": "EnableV2Compatible",
        // V2组件按对象属性分类收集
        "stateVariableName": "name",
        "owningComponentOrClassName": "CompatibilityUser",
        "owningComponentId": -1,
        // 对象name属性在V2组件中关联的组件信息
        "dependentInfo": [{
            "elementId": 12,
            "elementName": "Text"
        }]
    }, {
        "decoratorName": "EnableV2Compatible",
        "stateVariableName": "age",
        "owningComponentOrClassName": "CompatibilityUser",
        "owningComponentId": -1,
        // 对象age属性在V2组件中关联的组件信息
        "dependentInfo": [{
            "elementId": 13,
            "elementName": "Text"
        }]
    }]
}
```

## 状态管理常见不刷新问题分析

在[状态管理常见问题](./arkts-state-management-faq.md)的案例中介绍了常见的状态管理对象不刷新UI或者页面性能不达标的问题，以下介绍如何使用canBeObserved接口来帮助开发者分析和定位问题原因。

### a.b(this.object)案例分析

在[a.b(this.object)](./arkts-state-management-faq-inner-component.md#使用abthisobject形式调用不会触发ui刷新)案例的反例中，由于b的入参传入的是this.object的原始对象，原始对象是不可被观察的，所以导致UI无法刷新。开发者可以在修改属性前调用canBeObserved接口判断入参对象是否可被观察。

在反例中提供了两个修改对象属性的方法，在修改属性前先使用canBeObserved接口判断对象是否可被观察，代码如下：

<!-- @[case_a_b_call_error_increaseVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallError.ets) -->

``` TypeScript
static increaseVolume(balloon: Balloon) {
  // 修改属性前，通过canBeObserved来判断入参balloon对象是否可被观察
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume += 2;
}
```

<!-- @[case_a_b_call_error_reduceVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallError.ets) -->

``` TypeScript
reduceVolume(balloon: Balloon) {
  // 修改属性前，通过canBeObserved来判断入参balloon对象是否可被观察
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume -= 1;
}
```

两个方法调用canBeObserved接口返回结果一样（如下所示），表示两个方法接收的入参都是不可被观察对象，所以UI无法刷新。

``` json5
{
    // 不可被观察
    "isObserved": false,
    // 原因：不是可被观察对象
    "reason": "The object data is not an observable object",
    // 装饰器信息为空
    "decoratorInfo": []
}
```

在正例中修改属性方法前判断对象是否可被观察，代码如下：

<!-- @[case_a_b_call_right_increaseVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallRight.ets) -->

``` TypeScript
static increaseVolume(balloon: Balloon) {
  // 修改属性前，通过canBeObserved来判断入参balloon对象是否可被观察
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume += 2;
}
```
<!-- @[case_a_b_call_right_reduceVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallRight.ets) -->

``` TypeScript
reduceVolume(balloon: Balloon) {
  // 修改属性前，通过canBeObserved来判断入参balloon对象是否可被观察
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume -= 1;
}
```

两个方法调用canBeObserved接口返回结果一样（如下所示），表示两个方法接收的入参都是可被观察对象，且被UI组件所使用，UI可以正常刷新。

``` json5
{
    "isObserved": true,
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    "decoratorInfo": [{
        "decoratorName": "@State",
        "stateVariableName": "balloon",
        "owningComponentOrClassName": "Index",
        "owningComponentId": 4,
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 6
        }]
    }]
}
```

### 状态变量关联的组件数过多导致性能下降案例分析

在[状态变量关联的组件数过多导致性能下降](./arkts-state-management-faq-inner-component.md#状态变量关联的组件数过多导致性能下降)案例中提供了HiDumper工具来查看状态变量关联的组件，若组件关联过多，则页面性能下降。开发者也可以使用canBeObserved接口在业务代码中获取状态管理对象关联的组件，根据接口返回结果优化业务代码。

在反例中通过`move`按钮修改`this.translateObj`对象的属性，可以在修改属性前先调用canBeObserved接口来获取对象关联的组件信息，代码如下：

<!-- @[control_counter_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseControlCounterError.ets) -->

``` TypeScript
Button('move')
  .translate({
    x: this.translateObj.translateX
  })
  .onClick(() => {
    this.getUIContext().animateTo({
      duration: 50
    }, () => {
      // 在修改状态变量之前，调用canBeObserved接口获取状态变量关联的组件
      hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(this.translateObj))}`);
      this.translateObj.translateX = (this.translateObj.translateX + 50) % 150;
    });
  })
```

返回结果：

``` json5
// 反例的获取结果，对象关联5个组件
{
    "isObserved": true,
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    "decoratorInfo": [{
        "decoratorName": "@State",
        "stateVariableName": "translateObj",
        "owningComponentOrClassName": "Page",
        "owningComponentId": 4,
        "dependentInfo": [{
            "elementName": "Title",
            "elementId": 6
        }, {
            "elementName": "Stack",
            "elementId": 7
        }, {
            "elementName": "Button",
            "elementId": 8
        }]
    }, {
        "decoratorName": "@ObjectLink",
        "stateVariableName": "translateObj",
        "owningComponentOrClassName": "Title",
        "owningComponentId": 6,
        "dependentInfo": [{
            "elementName": "Image",
            "elementId": 11
        }, {
            "elementName": "Text",
            "elementId": 12
        }]
    }]
}
```

在正例中修改对象的属性前也调用canBeObserved接口获取状态变量关联的组件，代码如下：

<!-- @[control_counter_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseControlCounterRight.ets) -->

``` TypeScript
Button('move')
  .onClick(() => {
    this.getUIContext().animateTo({
      duration: 50
    }, () => {
      // 在修改状态变量之前，调用canBeObserved接口获取状态变量关联的组件
      hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(this.translateObj))}`);
      this.translateObj.translateX = (this.translateObj.translateX + 50) % 150;
    });
  })
```

返回结果：

``` json5
// 正例的获取结果，对象关联1个组件
{
    "isObserved": true,
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    "decoratorInfo": [{
        "decoratorName": "@State",
        "stateVariableName": "translateObj",
        "owningComponentOrClassName": "Page1",
        "owningComponentId": 4,
        "dependentInfo": [{
            "elementName": "Column",
            "elementId": 5
        }]
    }]
}
```

对比可知：正例中对象关联的组件数量少于反例中对象关联的组件数量，从而实现性能提升。

### ForEach和对象数组结合使用导致UI不刷新案例分析

在[ForEach和对象数组结合使用导致UI不刷新](./arkts-state-management-faq-inner-component.md#foreach和对象数组结合使用导致ui不刷新)案例中，使用canBeObserved接口获取判断对象是否是可被观察的。

在反例的`onClick`方法中，修改对象属性前先调用canBeObserved接口判断`this.styleList[i]`对象是否可被观察，代码如下：

<!-- @[array_foreach_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayForEachError.ets) -->

``` TypeScript
Text('Font Size List')
  .fontSize(50)
  .onClick(() => {
    for (let i = 0; i < this.styleList.length; i++) {
      // 此处想要修改的是this.styleList[i]对象的fontSize属性
      // 修改之前调用canBeObserved接口获取this.styleList[i]对象关联的组件信息
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.styleList[i]))}`);
      this.styleList[i].fontSize++;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'change font size');
  })
```

返回结果如下，虽然`this.styleList[i]`（也就是`TextStyles`对象）被[@Observed](./arkts-observed-and-objectlink.md)装饰器装饰，是可被观察的，但没有被UI组件所使用，所以UI组件不刷新。

``` json5
{
    // 对象是可被观察的
    "isObserved": true,
    // @Observed装饰的对象是可被观察的
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed, but not used in UI",
    // 收集的装饰器信息为空
    "decoratorInfo": []
}
```

在正例中同样先判断对象是否可被观察，代码如下：

<!-- @[array_foreach_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayForEachRight.ets) -->

``` TypeScript
Text('Font Size List')
  .fontSize(50)
  .onClick(() => {
    for (let i = 0; i < this.styleList.length; i++) {
      // 此处想要修改的是this.styleList[i]对象的fontSize属性
      // 修改之前调用canBeObserved接口获取this.styleList[i]对象关联的组件信息
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.styleList[i]))}`);
      this.styleList[i].fontSize++;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'change font size');
  })
```

返回结果如下，可知`this.styleList[i]`是可被观察对象，且有关联的UI组件，能正常刷新UI组件。

``` json5
{
    "isObserved": true,
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    "decoratorInfo": [{
        "decoratorName": "@ObjectLink",
        "stateVariableName": "textStyle",
        "owningComponentOrClassName": "TextComponent",
        "owningComponentId": 147,
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 148
        }]
    }]
}
```

### 数据重置导致UI不刷新使用场景

在[数据重置导致UI不刷新使用场景](./arkts-state-management-faq-inner-class.md#数据重置导致ui不刷新)案例中，使用canBeObserved接口定位UI不刷新原因。

在反例的`X`按钮修改对象属性前先调用canBeObserved接口判断对象是否可被观察，代码如下：

<!-- @[array_observed_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayObservedError.ets) -->

``` TypeScript
Button('X')
  .backgroundColor(Color.Red)
  .onClick(() => {
    let index = this.childList.findIndex((item) => {
      return item.count === this.child.count;
    });
    if (index !== -1) {
      // 在删除数组元素之前，调用canBeObserved接口判断this.childList是否是一个可被观察对象
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.childList))}`);
      this.childList.splice(index, 1);
    }
  })
  .margin({
    left: 200,
    right: 30
  })
```

在点击`Recover`按钮后，再次点击`X`按钮，数组元素不会删除，调用canBeObserved接口返回的结果发现，`Recover`之后的`this.childList`数组已经不是可被观察的了。

``` json5
{
    "isObserved": false,
    "reason": "The object data is not an observable object",
    "decoratorInfo": []
}
```

在正例中修改元素属性前判断对象是否可被观察，代码如下：

<!-- @[array_observed_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayObservedRight.ets) -->

``` TypeScript
Button('X')
  .backgroundColor(Color.Red)
  .onClick(() => {
    let index = this.childList.findIndex((item) => {
      return item.count === this.child.count;
    });
    if (index !== -1) {
      // 在删除数组元素之前，调用canBeObserved接口判断this.childList是否是一个可被观察对象
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.childList))}`);
      this.childList.splice(index, 1);
    }
  })
  .margin({
    left: 200,
    right: 30
  })
```

返回结果中关键信息如下，可知`this.childList`数组是可被观察的，且有关联的UI组件，能正常刷新UI组件。

``` json5
{
    "isObserved": true,
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    "decoratorInfo": [{
        "decoratorName": "@ObjectLink",
        "stateVariableName": "childList",
        "owningComponentOrClassName": "CompList",
        "owningComponentId": 8,
        "dependentInfo": [{
            "elementName": "ForEach",
            "elementId": 16
        }]
    }, 
    ...
    // 以下结果省略
  ]
}
```