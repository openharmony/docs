# Types
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @lijiamin2025-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->
> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## ISendable

type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description  |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | Parent type of all sendable types.|

## ArrayFromMapFn<sup>18+</sup>
type ArrayFromMapFn<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

Defines the ArkTS Array reduction function, which is used by the **from** API of the Array class.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | Yes| Element that is being processed.|
| index | number | Yes| Index of the element in the ArkTS array.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ToElementType | Result of the reduction function, which is used as a new element in the array.|

## ArrayPredicateFn<sup>18+</sup>
type ArrayPredicateFn<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

Defines the ArkTS Array reduction function, which is used by the **some** and **every** APIs of the Array class to determine whether array elements meet certain test conditions.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being processed.|
| index | number | Yes| Index of the element in the ArkTS array.|
| array | ArrayType | Yes| ArkTS array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| boolean | Result of the reduction function, indicating whether the current element meets the test condition. The value **true** means that the current element or a previous element meets the condition, and **false** means that no element meets the condition.|

## ArrayReduceCallback<sup>18+</sup>
type ArrayReduceCallback<AccType, ElementType, ArrayType> =
    (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

Defines the ArkTS Array reduction function, which is used by the **reduceRight** API of the Array class.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 18.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | Yes| Accumulated value of the current traversal.|
| currentValue | ElementType | Yes| Element that is being traversed in the ArkTS array.|
| currentIndex | number | Yes| Index of the element in the ArkTS array.|
| array | ArrayType | Yes| ArkTS array that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| AccType | Result of the reduction function, which is used as the **previousValue** parameter in the next call of **ArrayReduceCallback**.|



## TypedArrayFromMapFn
type TypedArrayFromMapFn\<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

Describes the mapping function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | Yes| Element that is currently traversed and used to construct an ArkTS TypedArray.|
| index | number | Yes| Index of the element, beginning at 0.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ToElementType | Element value after the mapping.|

## TypedArrayPredicateFn
type TypedArrayPredicateFn\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

Describes the assertion function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being traversed in the ArkTS TypedArray.|
| index | number | Yes| Index of the element, beginning at 0.|
| array | ArrayType | Yes| ArkTS TypedArray that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| boolean | Operation result. The value **true** is returned if the value meets the condition; otherwise, **false** is returned.|

## TypedArrayForEachCallback
type TypedArrayForEachCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void

Describes the traversal function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being traversed in the ArkTS TypedArray.|
| index | number | Yes| Index of the element, beginning at 0.|
| array | ArrayType | Yes| ArkTS TypedArray that is being traversed.|

## TypedArrayMapCallback
type TypedArrayMapCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => ElementType

Describes the conversion mapping function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | Yes| Element that is being mapped in the ArkTS TypedArray.|
| index | number | Yes| Index of the element, beginning from 0.|
| array | ArrayType | Yes| ArkTS TypedArray that is being mapped.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| ElementType | Element value after the mapping.|

## TypedArrayReduceCallback
type TypedArrayReduceCallback\<AccType, ElementType, ArrayType> = (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

Describes the reduce function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | Yes| Accumulated value of the current traversal.|
| currentValue | ElementType | Yes| Element that is being traversed in the ArkTS TypedArray.|
| currentIndex | number | Yes| Index of the element, beginning at 0.|
| array | ArrayType | Yes| ArkTS TypedArray that is being traversed.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| AccType | Result of the reduce function. The result is passed in to the **previousValue** parameter when **TypedArrayReduceCallback** is called next time.|

## TypedArrayCompareFn
type TypedArrayCompareFn\<ElementType> = (first: ElementType, second: ElementType) => number

Describes the sort function of the ArkTS TypedArray.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| first | ElementType | Yes| First element to be compared.|
| second | ElementType | Yes| Second element to be compared.|

**Return value**

| Type  | Description                         |
| ------ | --------------------------- |
| number | Comparison result of the elements. If `first` is less than `second`, the return value is a negative number. If `first` is greater than `second`, the return value is a positive number. If `first` is equal to `second`, the return value is 0.|
