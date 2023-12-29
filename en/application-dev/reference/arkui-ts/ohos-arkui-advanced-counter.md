# @ohos.arkui.advanced.Counter (Counter)

A counter is a component used to accurately adjust values.

>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import {CounterType, CounterComponent, CounterOptions, DateData} from '@ohos.arkui.advanced.Counter';
```

##  Child Components

Not supported

## CounterComponent

CounterComponent({options:CounterOptions} )

**Decorator**: @Component

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                             | Mandatory| Decorator| Description                   |
| ------- | --------------------------------- | ---- | ---------- | ----------------------- |
| options | [CounterOptions](#counteroptions) | Yes  | @Prop      | Parameters of the counter.|

## CounterOptions

Defines the type and style parameters of the counter.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type      | Mandatory       | Description                           |
| ----------- | ---------- | ------| --------------------------------- |
| type | [CounterTyle](#countertyle) | Yes  | Type of the current counter.|
| numberOptions | [NumberStyleOptions](#numberstyleoptions) | No   | Parameters of the number style counter.|
| inlineOptions | [InlineStyleOptions](#inlinestyleoptions) | No| Parameters of the inline number style counter.  |
| dateOptions | [DateStyleOptions](#datestyleoptions) | No| Parameters of the inline date style counter.|

A counter type must go with parameters of the matching counter style. Below is a mapping between the counter types and counter styles.

| Counter Type            | Counter Style       |
| ----------------------- | ------------------ |
| CounterTyle.LIST        | NumberStyleOptions |
| CounterTyle.COMPACT     | NumberStyleOptions |
| CounterTyle.INLINE      | InlineStyleOptions |
| CounterTyle.INLINE_DATE | DateStyleOptions   |

## CounterTyle

Enumerates the counter types.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Description                       |
| ----------- | --------------------------- |
| LIST        | List counter.            |
| COMPACT     | Compact counter.            |
| INLINE      | Inline number counter.|
| INLINE_DATE | Inline date counter.      |
## CommonOptions

Defines common attributes and events of counters.

**System capability**: SystemCapability.ArkUI.ArkUI.Full


| Name           | Type                     | Mandatory| Default Value| Description                                                        |
| --------------- | ------------------------- | ---- | ------ | ------------------------------------------------------------ |
| focusable       | boolean                   | No  | true   | Whether the counter is focusable.                                   |
| step            | number                    | No  | 1      | Step of the counter.<br>Value range: an integer greater than or equal to 1.         |
| onHoverIncrease | (isHover: boolean) =>void | No  | -      | Callback invoked when the mouse pointer is moved over or away from the Increase button of the counter.<br>**isHover**: whether the mouse pointer hovers over the component. The value **true** means that the mouse pointer enters the component, and the value **false** means that the mouse pointer leaves the component.|
| onHoverDecrease | (isHover: boolean) =>void | No  | -      | Callback invoked when the mouse pointer is moved over or away from the Decrease button of the counter.<br>**isHover**: whether the mouse pointer hovers over the component. The value **true** means that the mouse pointer enters the component, and the value **false** means that the mouse pointer leaves the component.|

##  InlineStyleOptions

Defines the attributes and events of the inline number style counter.

Inherited from [CommonOptions](#commonoptions).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                  | Mandatory| Default Value| Description                                                  |
| --------- | ---------------------- | ---- | ------ | ------------------------------------------------------ |
| value     | number                 | No  | 0      | Initial value of the counter.                                 |
| min       | number                 | No  | 0      | Minimum value of the counter.                                 |
| max       | number                 | No  | 999    | Maximum value of the counter.                                 |
| textWidth | number                 | No  | 0      | Text width of the counter.                                  |
| onChange  | (value: number) =>void | No  | -      | Callback invoked when the value changes. The current value is returned.<br>**value**: current value.|

## NumberStyleOptions

Defines the attributes and events of the number style counter.

Inherited from [InlineStyleOptions](#inlinestyleoptions).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type                                                        | Mandatory| Default Value| Description                                         |
| --------------- | ------------------------------------------------------------ | ---- | ------ | --------------------------------------------- |
| label           | [ResourceStr](ts-types.md#resourcestr) | No  | -      | Label of the counter.                      |
| onFocusIncrease | () =>void                                                    | No  | -      | Callback invoked when the Increase button of the counter gains focus.|
| onFocusDecrease | () =>void                                                    | No  | -      | Callback invoked when the Decrease button of the counter gains focus.|
| onBlurIncrease  | () =>void                                                    | No  | -      | Callback invoked when the Increase button of the counter loses focus.|
| onBlurDecrease  | () =>void                                                    | No  | -      | Callback invoked when the Decrease button of the counter loses focus.|

## DateStyleOptions

Defines the attributes and events of the inline date style counter.

Inherited from [CommonOptions](#commonoptions).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                               | Mandatory| Default Value| Description                                                     |
| ------------ | ----------------------------------- | ---- | ------ | --------------------------------------------------------- |
| year         | number                              | No  | 1      | Initial year of the counter.                                 |
| month        | number                              | No  | 1      | Initial month of the counter.                                 |
| day          | number                              | No  | 1      | Initial day of the counter.                                   |
| onDateChange | (date: [DateData](#datedata))=>void | No  | -      | Callback invoked when the date changes. The current date is returned.<br>**date**: current date.|

## DateData

Defines common date attributes and methods.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type  | Mandatory| Default Value| Description                        |
| ---------- | ------ | ---- | ------ | ---------------------------- |
| year       | number | Yes  | 1      | Initial year of the counter.    |
| month      | number | Yes  | 1      | Initial month of the counter.    |
| day        | number | Yes  | 1      | Initial day of the counter.      |
| toString() | string | Yes  | -      | Current date.|

## Example  

### Example 1

```ts
import {CounterType, CounterComponent, CounterOptions, DateData} from '@ohos.arkui.advanced.Counter';
@Entry
@Component
struct ListCounterExample {
  build() {
    Column() {
      // List counter
      CounterComponent({ options: {
        type: CounterType.LIST,
        numberOptions: {
          label: "Price",
          min: 0,
          value: 5,
          max: 10,
        }
      }
      })
    }
  }
}
```

![listcounter](figures/listcounter.gif)
### Example 2
```ts
import {CounterType, CounterComponent, CounterOptions, DateData} from '@ohos.arkui.advanced.Counter';
@Entry
@Component
struct CompactCounterExample {
  build() {
    Column() {
      // Compact counter
      CounterComponent({ options: {
        type: CounterType.COMPACT,
        numberOptions: {
          label: "Quantity",
          value: 10,
          min: 0,
          max: 100,
          step: 10
        }
      }
      })
    }
  }
}
```
![compactcounter](figures/compactcounter.gif)
### Example 3
```ts
import {CounterType, CounterComponent, CounterOptions, DateData} from '@ohos.arkui.advanced.Counter';
@Entry
@Component
struct NumberStyleExample {
  build() {
    Column() {
      // Inline number counter
      CounterComponent({ options: {
        type: CounterType.INLINE,
        inlineOptions: {
          value: 100,
          min: 10,
          step: 2,
          max: 1000,
          textWidth: 100,
          onChange: (value: number) => {
          }
        } }
       })
    }
  }
}
```
![numberstyle](figures/numberstyle.gif)
### Example 4
```ts
import {CounterType, CounterComponent, CounterOptions, DateData} from '@ohos.arkui.advanced.Counter';
@Entry
@Component
struct DataStyleExample {
  build() {
    Column() {
      // Inline date counter
      CounterComponent({ options: {
        type: CounterType.INLINE_DATE,
        dateOptions: {
          year: 2016,
          onDateChange: (date: DateData) => {
            console.log("onDateChange Date: " + date.toString());
          }
        } }
       })
    }
  }
}
```
![datestyle](figures/datestyle.gif)
