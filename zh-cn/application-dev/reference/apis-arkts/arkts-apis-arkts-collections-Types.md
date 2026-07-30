# Types
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 此模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。

## ISendable

type ISendable = lang.ISendable

ISendable是所有Sendable类型（除`null`和`undefined`）的父类型。自身没有定义任何必需实现的方法和属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型 | 说明   |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | 所有Sendable类型的父类型。 |

## ArrayFromMapFn<sup>18+</sup>
type ArrayFromMapFn<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

ArkTS Array映射函数类型，被Array类的[from](arkts-apis-arkts-collections-Array.md#from18)接口使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | 是 | 当前遍历的ArkTS Array元素，用于映射转换为新的数组元素。|
| index | number | 是 | 当前遍历的ArkTS Array元素索引，从0开始。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ToElementType | 映射函数的结果，该结果会作为数组的新元素。 |

## ArrayPredicateFn<sup>18+</sup>
type ArrayPredicateFn<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

ArkTS Array断言函数类型，被Array类的[some](arkts-apis-arkts-collections-Array.md#some18)和[every](arkts-apis-arkts-collections-Array.md#every18)接口使用，用来判断数组元素是否满足测试条件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前遍历的ArkTS Array元素，用于判断是否满足测试条件。|
| index | number | 是 | 当前遍历的ArkTS Array元素索引，从0开始。 |
| array | ArrayType | 是 | 当前遍历的ArkTS Array本身。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| boolean | 断言函数的结果，该结果作为判断当前元素是否通过测试条件。为true时表示当前或之前的某个元素已满足条件，为false时表示尚未找到符合条件的元素。 |

## ArrayReduceCallback<sup>18+</sup>
type ArrayReduceCallback<AccType, ElementType, ArrayType> = (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

ArkTS Array归约函数类型，被Array类的[reduceRight](arkts-apis-arkts-collections-Array.md#reduceright18)接口使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | 是 | 当前遍历所累积的值。|
| currentValue | ElementType | 是 | 当前遍历的ArkTS Array元素，该元素将与previousValue进行归约计算。 |
| currentIndex | number | 是 | 当前遍历的ArkTS Array元素索引，从0开始。 |
| array | ArrayType | 是 | 当前遍历的ArkTS Array实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| AccType | 归约函数的结果，该结果会作为下一次调用ArrayReduceCallback时的previousValue参数。 |



## TypedArrayFromMapFn
type TypedArrayFromMapFn\<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

ArkTS TypedArray映射函数类型，被TypedArray类的from()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | 是 | 当前遍历的用于构造ArkTS TypedArray的元素。 |
| index | number | 是 | 当前遍历的用于构造ArkTS TypedArray的元素索引，从0开始。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ToElementType | 转换后的元素值。 |

## TypedArrayPredicateFn
type TypedArrayPredicateFn\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

ArkTS TypedArray断言函数类型，被TypedArray类的some()、every()、filter()、find()和findIndex()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前遍历的ArkTS TypedArray元素，用于判断是否满足测试条件。 |
| index | number | 是 | 当前遍历的ArkTS TypedArray元素索引，从0开始。 |
| array | ArrayType | 是 | 当前遍历的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| boolean | 断言函数的结果，该结果作为判断当前元素是否通过测试条件。为true时表示当前元素已满足测试条件，为false时表示当前元素不满足测试条件。  |

## TypedArrayForEachCallback
type TypedArrayForEachCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void

ArkTS TypedArray遍历函数类型，被TypedArray类的forEach()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 否 | 当前遍历的ArkTS TypedArray元素。 |
| index | number | 否 | 当前遍历的ArkTS TypedArray元素索引，从0开始。 |
| array | ArrayType | 否 | 当前遍历的ArkTS TypedArray实例。 |

## TypedArrayMapCallback
type TypedArrayMapCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => ElementType

ArkTS TypedArray映射函数类型，被TypedArray类的map()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前映射的ArkTS TypedArray元素。 |
| index | number | 是 | 当前映射的ArkTS TypedArray元素索引，从0开始。 |
| array | ArrayType | 是 | 当前映射的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ElementType | 转换后的元素值。 |

## TypedArrayReduceCallback
type TypedArrayReduceCallback\<AccType, ElementType, ArrayType> = (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

ArkTS TypedArray归约函数类型，被TypedArray类的reduce()和reduceRight()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | 是 | 当前遍历所累积的值。|
| currentValue | ElementType | 是 | 当前遍历的ArkTS TypedArray元素，该元素将与previousValue进行归约计算。 |
| currentIndex | number | 是 | 当前遍历的ArkTS TypedArray元素索引，从0开始。 |
| array | ArrayType | 是 | 当前遍历的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| AccType | 归约函数的结果。该结果会作为下一次调用TypedArrayReduceCallback时的previousValue参数。 |

## TypedArrayCompareFn
type TypedArrayCompareFn\<ElementType> = (first: ElementType, second: ElementType) => number

ArkTS TypedArray排序函数类型，被TypedArray类的sort()接口使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| first | ElementType | 是 | 当前待比较的第一个元素。 |
| second | ElementType | 是 | 当前待比较的第二个元素。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| number | 元素比较的结果。如果`first`小于`second`，返回值为负数；如果`first`大于`second`，返回值为正数；如果两个值相等，返回值为0。 |
