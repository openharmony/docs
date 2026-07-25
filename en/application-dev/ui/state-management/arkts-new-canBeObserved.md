# canBeObserved API: Determining Whether an Object Can Be Observed

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3efb4ba336409dd0731ba011e1e227786db57fa2 translatedAt=2026-07-22T02:05:02.402Z pushedAt=2026-07-24T01:13:44.253Z -->

To determine whether an object is observable and to obtain component information associated with the object, you can use [canBeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#canbeobserved23).

Before using this API, you are advised to read [State Management Overview](./arkts-state-management-overview.md) to have a basic understanding of the state management framework.

>**NOTE**
>
>Since API version 23, you can use the canBeObserved API in UIUtils to determine whether a data object is an observable object.

## Overview

During development and debugging, you may encounter issues where the UI page does not refresh after modifying an object's value (for details, see [State Management Development](./arkts-state-management-faq.md)). Troubleshooting such issues is particularly inconvenient in complex business scenarios. To address this, the **canBeObserved** API is provided to help you locate and analyze problems. Using this API, you can not only determine whether an object is observable, but also obtain component information associated with the object.

To use the **canBeObserved** API, you need to import the UIUtils.

```ts
import { UIUtils } from '@kit.ArkUI';
```

## Constraints

The parameters of **canBeObserved** support only non-null object types. If **undefined** or **null** is passed, **isObserved** returns **false**. If a non-object type is passed, a compilation error will be reported.

``` ts
import { UIUtils } from '@kit.ArkUI';

let res1 = UIUtils.canBeObserved(2); // Invalid input parameter. An error is reported during compilation.
let res2 = UIUtils.canBeObserved(undefined); // Invalid input parameter. isObserved returns false.
let res3 = UIUtils.canBeObserved(null); // Invalid input parameter. isObserved returns false.

class User {
  name?: string;
}

let result: ObservedResult = UIUtils.canBeObserved(new User()); // Correct usage.
```

## Scenarios Where Objects Can Be Observed

The object calls the **canBeObserved** API. The value of **reason** in the returned [ObservedResult](../../reference/apis-arkui/js-apis-stateManagement.md#observedresult23) object can be any of the following:

| reason Value| Description|
| ---- | ---- |
| The object data is decorated with @Observed or wrapped by makeV1Observed | The object is decorated with the [@Observed](./arkts-observed-and-objectlink.md) decorator or wrapped by the [makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19) method. For details, see [Scenarios Where V1 Component Objects Can Be Observed](#scenarios-where-v1-component-objects-can-be-observed).|
| The object data is decorated with V2 @ObservedV2 and @Trace | The object and its properties are decorated with the [@ObservedV2 and @Trace](./arkts-new-observedV2-and-trace.md) decorators. For details, see [Scenarios Where V2 Component Objects Can Be Observed](#scenarios-where-v2-component-objects-can-be-observed).|
| The object data is wrapped by V2's makeObserved | The object is wrapped using the [makeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#makeobserved) method. For details, see [Scenarios Where V2 Component Objects Can Be Observed](#scenarios-where-v2-component-objects-can-be-observed).|
| The object data is built-in type proxy data (Array/Map/Set/Date) decorated with @Trace | Data objects of the **Array**, **Set**, **Map**, and **Date** types are decorated with the state management V2 decorators or decorated with the [@Trace](./arkts-new-observedV2-and-trace.md) decorator as object properties. For details, see [Scenarios Where V2 Component Objects Can Be Observed](#scenarios-where-v2-component-objects-can-be-observed).|
| The V1 Observed object data is wrapped by enableV2Compatibility and used in @ComponentV2 | When V1 and V2 components are mixed up, the object is wrapped using the [enableV2Compatibility](./arkts-v1-v2-mixusage.md#enablev2compatibility) method. For details, see [Scenarios Where Objects Become Observable When Mixing V1 and V2 Components](#scenarios-where-objects-become-observable-when-mixing-v1-and-v2-components).|

Note that if the value of **reason** ends with **but not used in UI** or **but not used in @ComponentV2**, the object is observable but not used by any UI component. Therefore, changing the object value will not refresh the UI.

### Scenarios Where V1 Component Objects Can Be Observed

In V1 components, the following objects can be observed:

- Objects decorated with a state management V1 decorator in a component (including **Array**, **Set**, **Map**, and **Date** data objects)

- Objects decorated with the [@Observed](./arkts-observed-and-objectlink.md) decorator

- Objects wrapped using the [makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19) method

The state management V1 decorators refer to [@State](./arkts-state.md), [@Prop](./arkts-prop.md), [@Link](./arkts-link.md), [@ObjectLink](./arkts-observed-and-objectlink.md), [@StorageLink](./arkts-appstorage.md#storagelink), [@StorageProp](./arkts-appstorage.md#storageprop), [@LocalStorageLink](./arkts-localstorage.md#localstoragelink), [@LocalStorageProp](./arkts-localstorage.md#localstorageprop), [@Provide](./arkts-provide-and-consume.md), and [@Consume](./arkts-provide-and-consume.md).

If the object decorated with [@Observed](./arkts-observed-and-objectlink.md) and the object wrapped by [makeV1Observed](../../reference/apis-arkui/js-apis-stateManagement.md#makev1observed19) are not decorated by the state management V1 decorator in the component, the result returned by calling the **canBeObserved** API is as follows:

``` json5
{
    // The object decorated with @Observed and the object wrapped by the makeV1Observed method are observable objects.
    "isObserved": true,
    // If the component is not decorated with the state management V1 decorator, the reason returned is that the component is not used by the UI component and therefore the UI is not refreshed.
    // The refresh of a V1 component depends on the state management V1 decorator.
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed, but not used in UI",
    // No state management decorator is collected.
    "decoratorInfo": []
}
```

**Objects decorated with a state management V1 decorator**

The following describes how to use the [@State](./arkts-state.md) decorator to decorate an object in a component so that the object can be observed.

The sample code is as follows:

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

  // Provide a method in the object to determine whether the object can be observed.
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@Component
struct V1State {
  // When @State is used to decorate an object in a V1 component, the object becomes observable.
  @State stateUser: StateUser = new StateUser('James', 33);

  build() {
    Column({ space: 20 }) {
      // The component uses the properties of the observable object.
      Text('user name: ' + this.stateUser.name)
      // The component uses the properties of the observable object.
      Text('user age: ' + this.stateUser.age)
      Button('test')
        .onClick(() => {
          // You can use this API on any page to determine whether the current object is observable and obtain the component information associated with the object.
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

Returned result:

``` json5
{
    // The object is observable.
    "isObserved": true,
    // In V1 components, objects decorated by the state management decorator are observable.
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    // Collect the decorator information of the object.
    "decoratorInfo": [{
        // Decorator name.
        "decoratorName": "@State",
        // Name of the attribute decorated by the decorator.
        "stateVariableName": "stateUser",
        // Name of the component where the decorator is located.
        "owningComponentOrClassName": "V1State",
        // ID of the component where the decorator is located.
        "owningComponentId": 4,
        // Information about the component associated with the object
        "dependentInfo": [{
            // Component name.
            "elementName": "Text",
            // Component ID.
            "elementId": 6
        }, {
            "elementName": "Text",
            "elementId": 7
        }]
    }]
}
```

**Objects decorated with the @Observed decorator**

The following describes how to use the [@Observed](./arkts-observed-and-objectlink.md) decorator to decorate an object and the [@Track](./arkts-track.md) decorator to decorate the object properties.

The sample code is as follows:

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

  // Provide a method in the object to determine whether the object can be observed.
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
          // You can use this API on any page to determine whether the current object is observable and obtain the component information associated with the object.
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
      // The component uses the properties of the observable object.
      Text('user name: ' + this.trackUser.name)
      // The component uses the properties of the observable object.
      Text('user age: ' + this.trackUser.age)
    }
  }
}
```

When an object property is decorated with the [@Track](./arkts-track.md) decorator, the decorator information collection specifications are the same as those of the V2 component decorator. For details, see [Scenarios Where V2 Component Objects Can Be Observed](#scenarios-where-v2-component-objects-can-be-observed).

Returned result:

``` json5
{
    // The object is observable.
    "isObserved": true,
    // The object decorated by @Observed is observable.
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed",
    // The object property is decorated with @Track. The information collection specifications of the decorator are the same as those of the V2 component.
    "decoratorInfo": [{
        // When the object property is decorated with @Track, the decorator name is fixed to @Track.
        "decoratorName": "@Track",
        // When the object property is decorated with @Track, stateVariableName indicates the name of the property decorated with @Track.
        "stateVariableName": "name",
        // When the object property is decorated with @Track, owningComponentOrClassName indicates the class name.
        "owningComponentOrClassName": "TrackUser",
        // When owningComponentOrClassName is a class name, the value of owningComponentId is always -1.
        "owningComponentId": -1,
        // Information about the component associated with the name property of the object.
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 10
        }]
    }, {
        "decoratorName": "@Track",
        "stateVariableName": "age",
        "owningComponentOrClassName": "TrackUser",
        "owningComponentId": -1,
        // Information about the component associated with the name property of the object.
        "dependentInfo": [{
            "elementName": "Text",
            "elementId": 11
        }]
    }]
}
```

### Scenarios Where V2 Component Objects Can Be Observed

In V2 components, the following objects can be observed:

- Objects decorated with the [@ObservedV2](./arkts-new-observedV2-and-trace.md) decorator

- **Array**, **Set**, **Map**, and **Date** data objects decorated with state management V2 decorators

- Objects wrapped using the [makeObserved](../../reference/apis-arkui/js-apis-stateManagement.md#makeobserved) method

State management V2 decorators refer to [@Local](./arkts-new-local.md), [@Param](./arkts-new-param.md), [@Provider](./arkts-new-provider-and-consumer.md) and [@Consumer](./arkts-new-provider-and-consumer.md).

The specifications for collecting decorators of V2 components are different from those of V1 components. V2 components collect decorator information based on the object properties decorated with the @Trace decorator. The following TestClass is used as an example. The @Trace decorator displays information about associated components by property.

``` TypeScript
// Define a class.
@ObservedV2
class TestClass {
  @Trace a?: string;
  @Trace b?: string;
  @Trace c?: string;
}
```

``` json5
// Analyze the returned result.
{
    // The object is observable.
    "isObserved": true,
    "reason": "The object data is decorated with V2 @ObservedV2 and @Trace",
    // Decorator information is classified and collected based on the properties decorated with @Trace.
    "decoratorInfo": [{
        "decoratorName": "@Trace",
        // Name of the @Trace decorated object property.
        "stateVariableName": "a",
        // Class name of the object.
        "owningComponentOrClassName": "TestClass",
        // Return -1 for owningComponentId.
        "owningComponentId": -1,
        // Component information associated with the same @Trace decorated property is collected together.
        "dependentInfo": [{
            "elementId": 5,
            "elementName": "Text"
        }]
    },{
        "decoratorName": "@Trace",
        "stateVariableName": "b",
        "owningComponentOrClassName": "TestClass",
        "owningComponentId": -1,
        // Component information associated with the same @Trace decorated property is collected together.
        "dependentInfo": [{
            "elementId": 6,
            "elementName": "Text"
        }]
    },{
        "decoratorName": "@Trace",
        "stateVariableName": "c",
        "owningComponentOrClassName": "TestClass",
        "owningComponentId": -1,
        // Component information associated with the same @Trace decorated property is collected together.
        "dependentInfo": [{
            "elementId": 7,
            "elementName": "Text"
        }]
    }]
}
```

**Objects decorated with the @ObservedV2 decorator**

The following describes a usage scenario where an object is decorated with the [@ObservedV2](./arkts-new-observedV2-and-trace.md) decorator in a V2 component.

The sample code is as follows:

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

  // Provide a method in the object to determine whether the object can be observed.
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
          // You can use this API on any page to determine whether the current object can be observed.
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

Returned result:

``` json5
{
    // The object is observable.
    "isObserved": true,
    // The object decorated by @ObservedV2 is observable.
    "reason": "The object data is decorated with V2 @ObservedV2 and @Trace",
    // Decorator information on the object, which is collected by category based on the property decorated with @Trace.
    "decoratorInfo": [{
        // The decorator name is fixed to @Trace.
        "decoratorName": "@Trace",
        // Name of the property decorated by @Trace.
        "stateVariableName": "name",
        // Class name of the object.
        "owningComponentOrClassName": "LocalUser",
        // Return -1 for owningComponentId.
        "owningComponentId": -1,
        // Information about the component associated with the name property of the object.
        "dependentInfo": [{
            "elementId": 6,
            "elementName": "Text"
        }]
    }, {
        "decoratorName": "@Trace",
        "stateVariableName": "age",
        "owningComponentOrClassName": "LocalUser",
        "owningComponentId": -1,
        // Information about the component associated with the name property of the object.
        "dependentInfo": [{
            "elementId": 7,
            "elementName": "Text"
        }]
    }]
}
```

### Scenarios Where Objects Become Observable When Mixing V1 and V2 Components

In scenarios where V1 and V2 components are used together, to keep objects synchronously refreshed in both V1 and V2 components, you need to use the [enableV2Compatibility](./arkts-v1-v2-mixusage.md#enablev2compatibility) method in the V1 component to wrap the observable V1 object before passing it to the V2 component.

Code example:

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

  // Provide a method in the object to determine whether the object can be observed.
  test(): void {
    hilog.info(0x00, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this))}`);
  }
}

@Entry
@Component
struct V1AndV2Compatibility {
  // The V1 object converted by enableV2Compatibility must be observable.
  @State temp: CompatibilityUser = new CompatibilityUser('Thomas', 43);
  @State compatibilityUser: CompatibilityUser = UIUtils.enableV2Compatibility(this.temp);

  build() {
    Column({ space: 20 }) {
      Text('V1 name: ' + this.compatibilityUser.name)
      Text('V1 age: ' + this.compatibilityUser.age)

      V2Child({ compatibilityUser: this.compatibilityUser })

      Button('test')
        .onClick(() => {
          // You can use this API on any page to determine whether the current object can be observed.
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

Returned result:

``` json5
{
    // The object is observable.
    "isObserved": true,
    // The object converted using the enableV2Compatibility method is also observable.
    "reason": "The V1 Observed object data is wrapped by enableV2Compatibility and used in @ComponentV2",
    // Decorator information, which is collected separately for V1 and V2 components.
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
        // decoratorName of the V2 component is fixed to EnableV2Compatible.
        "decoratorName": "EnableV2Compatible",
        // The V2 component collects information by object property.
        "stateVariableName": "name",
        "owningComponentOrClassName": "CompatibilityUser",
        "owningComponentId": -1,
        // Information about the component associated with the name property of the object in the V2 component.
        "dependentInfo": [{
            "elementId": 12,
            "elementName": "Text"
        }]
    }, {
        "decoratorName": "EnableV2Compatible",
        "stateVariableName": "age",
        "owningComponentOrClassName": "CompatibilityUser",
        "owningComponentId": -1,
        // Information about the component associated with the age property of the object in the V2 component.
        "dependentInfo": [{
            "elementId": 13,
            "elementName": "Text"
        }]
    }]
}
```

## Analysis of Common State Management Non-Refresh Issues

The [State Management Development](./arkts-state-management-faq.md) topic introduces common issues where state management objects do not refresh the UI or where page performance is suboptimal. The following describes how to use the **canBeObserved** API to help you analyze and locate the causes of such issues.

### a.b(this.object) Case Analysis

In the [a.b(this.object)](./arkts-state-management-faq-inner-component.md#using-the-abthisobject-pattern-fails-to-trigger-ui-re-rendering) counter-example, the parameter passed to b is the raw object of **this.object**, which is not observable, resulting in the UI being unable to refresh. You can call the **canBeObserved** API before modifying properties to determine whether the parameter object is observable.

In the counter-example, two methods are provided to modify object properties. Before modifying the properties, the **canBeObserved** API is used to determine whether the object is observable. The code is as follows:

<!-- @[case_a_b_call_error_increaseVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallError.ets) -->

``` TypeScript
static increaseVolume(balloon: Balloon) {
  // Before modifying the attribute, use canBeObserved to check whether the balloon object can be observed.
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume += 2;
}
```

<!-- @[case_a_b_call_error_reduceVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallError.ets) -->

``` TypeScript
reduceVolume(balloon: Balloon) {
  // Before modifying the attribute, use canBeObserved to check whether the balloon object can be observed.
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume -= 1;
}
```

The return results of calling the **canBeObserved** API in both methods are the same (as shown below), indicating that the parameters received by both methods are non-observable objects, so the UI cannot refresh.

``` json5
{
    // Not observable.
    "isObserved": false,
    // Cause: The object is not observable.
    "reason": "The object data is not an observable object",
    // The decorator information is empty.
    "decoratorInfo": []
}
```

In the correct example, before modifying the property, check whether the object can be observed. The code is as follows:

<!-- @[case_a_b_call_right_increaseVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallRight.ets) -->

``` TypeScript
static increaseVolume(balloon: Balloon) {
  // Before modifying the attribute, use canBeObserved to check whether the balloon object can be observed.
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume += 2;
}
```

<!-- @[case_a_b_call_right_reduceVolume](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseABCallRight.ets) -->

``` TypeScript
reduceVolume(balloon: Balloon) {
  // Before modifying the attribute, use canBeObserved to check whether the balloon object can be observed.
  hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(balloon))}`);
  balloon.volume -= 1;
}
```

The two methods call the **canBeObserved** API and return the same result (as shown below), indicating that the input parameters received by both methods are observable objects and are used by UI components, so the UI can be refreshed properly.

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

### Performance Degradation Due to Too Many Components Associated with State Variables

In the [Performance Deteriorates Due to Too Many Components Associated with State Variables](./arkts-state-management-faq-inner-component.md#performance-deteriorates-due-to-too-many-components-associated-with-state-variables) case, the HiDumper tool is provided to view components associated with state variables. If too many components are associated, page performance degrades. You can also use the **canBeObserved** API in service code to obtain components associated with state management objects and optimize service code based on the API return results.

In the counter-example, properties of the **this.translateObj** object are modified via the **move** button. Before modifying the properties, the **canBeObserved** API can be called to obtain component information associated with the object. The code is as follows:

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
      // Before modifying a state variable, call the canBeObserved API to obtain the components associated with the state variable.
      hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(this.translateObj))}`);
      this.translateObj.translateX = (this.translateObj.translateX + 50) % 150;
    });
  })
```

Returned result:

``` json5
// Counter-example result: The object is associated with 5 components.
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

In the correct example, the **canBeObserved** API is also called before modifying the object property to obtain components associated with the state variable. The code is as follows:

<!-- @[control_counter_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseControlCounterRight.ets) -->

``` TypeScript
Button('move')
  .onClick(() => {
    this.getUIContext().animateTo({
      duration: 50
    }, () => {
      // Before modifying a state variable, call the canBeObserved API to obtain the components associated with the state variable.
      hilog.info(0x00, 'test_log', `res: ${JSON.stringify(UIUtils.canBeObserved(this.translateObj))}`);
      this.translateObj.translateX = (this.translateObj.translateX + 50) % 150;
    });
  })
```

Returned result:

``` json5
// Correct example result: The object is associated with one component.
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

The comparison shows that the number of components associated with the object in the correct example is fewer than that in the counter-example, thereby achieving performance improvement. 

### UI Refresh Failure Due to the Combination of ForEach and Object Arrays

In the case of [UI Is Not Refreshed Due to the Combination of ForEach and Object Arrays](./arkts-state-management-faq-inner-component.md#ui-is-not-refreshed-due-to-the-combination-of-foreach-and-object-arrays), the **canBeObserved** API is used to determine whether an object is observable.

In the **onClick** method of the counter-example, before modifying the object property, call the **canBeObserved** API to check whether the **this.styleList[i]** object can be observed. The code is as follows:

<!-- @[array_foreach_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayForEachError.ets) -->

``` TypeScript
Text('Font Size List')
  .fontSize(50)
  .onClick(() => {
    for (let i = 0; i < this.styleList.length; i++) {
      // The fontSize property of the this.styleList[i] object needs to be modified.
      // Before the modification, call the canBeObserved API to obtain the component information associated with the this.styleList[i] object.
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.styleList[i]))}`);
      this.styleList[i].fontSize++;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'change font size');
  })
```

The returned result is as follows. Although **this.styleList[i]** (that is, the **TextStyles** object) is decorated by the [@Observed](./arkts-observed-and-objectlink.md) decorator and is observable, it is not used by the UI component. Therefore, the UI component is not refreshed.

``` json5
{
    // The object is observable.
    "isObserved": true,
    // The object decorated by @Observed is observable.
    "reason": "The object data is decorated with @Observed or wrapped by makeV1Observed, but not used in UI",
    // The collected decorator information is empty.
    "decoratorInfo": []
}
```

In the correct example, the code also checks whether the object can be observed first. The code is as follows:

<!-- @[array_foreach_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayForEachRight.ets) -->

``` TypeScript
Text('Font Size List')
  .fontSize(50)
  .onClick(() => {
    for (let i = 0; i < this.styleList.length; i++) {
      // The fontSize property of the this.styleList[i] object needs to be modified.
      // Before the modification, call the canBeObserved API to obtain the component information associated with the this.styleList[i] object.
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.styleList[i]))}`);
      this.styleList[i].fontSize++;
    }
    hilog.info(DOMAIN_NUMBER, TAG, 'change font size');
  })
```

The returned result is as follows, indicating that this.styleList[i] is an observable object, has associated UI components, and can properly refresh the UI components.

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

### UI Refresh Failure Due to Data Reset

In the [UI Is Not Refreshed Due to Data Reset](./arkts-state-management-faq-inner-class.md#ui-is-not-refreshed-due-to-data-reset), use the **canBeObserved** API to locate the cause of the UI refresh failure.

In the **X** button of the counter-example, before modifying the object property, call the **canBeObserved** API to check whether the object can be observed. The code is as follows:

<!-- @[array_observed_error](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayObservedError.ets) -->

``` TypeScript
Button('X')
  .backgroundColor(Color.Red)
  .onClick(() => {
    let index = this.childList.findIndex((item) => {
      return item.count === this.child.count;
    });
    if (index !== -1) {
      // Before deleting elements in the array, call the canBeObserved API to check whether this.childList is an observable object.
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.childList))}`);
      this.childList.splice(index, 1);
    }
  })
  .margin({
    left: 200,
    right: 30
  })
```

After clicking the **Recover** button and then the **X** button again, the elements in the array are not deleted. The result returned by calling the **canBeObserved** API shows that the **this.childList** array is no longer observable after the recovery.

``` json5
{
    "isObserved": false,
    "reason": "The object data is not an observable object",
    "decoratorInfo": []
}
```

In the correct example, before modifying the element property, check whether the object can be observed. The code is as follows:

<!-- @[array_observed_right](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIUtilsCanBeObserved/entry/src/main/ets/pages/CaseArrayObservedRight.ets) -->

``` TypeScript
Button('X')
  .backgroundColor(Color.Red)
  .onClick(() => {
    let index = this.childList.findIndex((item) => {
      return item.count === this.child.count;
    });
    if (index !== -1) {
      // Before deleting elements in the array, call the canBeObserved API to check whether this.childList is an observable object.
      hilog.info(DOMAIN_NUMBER, TAG, `res: ${JSON.stringify(UIUtils.canBeObserved(this.childList))}`);
      this.childList.splice(index, 1);
    }
  })
  .margin({
    left: 200,
    right: 30
  })
```

The key information in the returned result is as follows, indicating that **this.childList** is an observable array, has associated UI components, and can properly refresh the UI components.

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
    //The following result is omitted.
  ]
}
```