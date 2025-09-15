# @arkts.math.Decimal (High-Precision Math Library Decimal)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

The Decimal module provides high-precision mathematical operation capabilities, supporting high-precision floating-point calculations.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module can be imported only to ArkTS files (with the file name extension .ets).

## Modules to Import

```ts
import { Decimal } from '@kit.ArkTS';
```

## Value

type Value = string | number | Decimal

Enumerates the value types available for constructing a decimal.

The actual value type can be the union of the types listed below.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type               | Description                          |
| ------------------- | ------------------------------ |
| string              | The value can be any string.|
| number              | The value can be any number.|
| [Decimal](#decimal) | The value is a decimal.     |

## Rounding

type Rounding = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8

Enumerates the rounding modes available.

The actual rounding mode can be the union of the types listed below.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| 0    | Rounds in such a way that the result heads away from zero. It is the same as [Decimal.ROUND_UP](#constants).       |
| 1    | Rounds in such a way that the result heads towards zero. It is the same as [Decimal.ROUND_DOWN](#constants).     |
| 2    | Rounds towards positive infinity. It is the same as [Decimal.ROUND_CEILING](#constants).    |
| 3    | Rounds towards negative infinity. It is the same as [Decimal.ROUND_FLOOR](#constants).      |
| 4    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds away from zero. It is the same as [Decimal.ROUND_HALF_UP](#constants).|
| 5    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards zero. It is the same as [Decimal.ROUND_HALF_DOWN](#constants).|
| 6    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards the even neighbor. It is the same as [Decimal.ROUND_HALF_EVEN](#constants).|
| 7    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards positive infinity. It is the same as [Decimal.ROUND_HALF_CEILING](#constants).|
| 8    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards negative infinity. It is the same as [Decimal.ROUND_HALF_FLOOR](#constants).|

## Modulo

type Modulo = Rounding | 9

Enumerates the rounding modes available in the modulo operation.

The actual rounding mode can be the union of the types listed below.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| [Rounding](#rounding) | Same rounding mode as that represented by [Rounding](#constants). |
| 9                      | Positive remainder Euclid's division, which is the same as [Decimal.EUCLIDEAN](#constants).|

## DecimalConfig

Describes the configuration of a **Decimal** object. You can call [Decimal.set](#set) to set these properties.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name     | Type                  | Read-Only| Optional| Description                                                        |
| --------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| precision | number                 | No  | Yes  | Maximum number of significant digits of the result of an operation. The value range is [1, 1e9], and the default value is **20**.    |
| rounding  | [Rounding](#rounding) | No  | Yes  | Rounding mode. The value is an integer ranging from 0 to 8, and the default value is **4**.                 |
| toExpNeg  | number                 | No  | Yes  | Negative exponent value at and below which [toString](#tostring) returns exponential notation. The value range is [-9e15, 0], and the default value is **-7**.|
| toExpPos  | number                 | No  | Yes  | Positive exponent value at and above which [toString](#tostring) returns exponential notation. The value range is [0, 9e15], and the default value is **21**.|
| minE      | number                 | No  | Yes  | Minimum negative exponents. A decimal with an exponent less than this minimum value underflows towards zero. The value range is [-9e15, 0], and the default value is **-9e15**.|
| maxE      | number                 | No  | Yes  | Maximum positive exponent. A decimal with an exponent greater than this maximum value overflows to infinity. The value range is [0, 9e15], and the default value is **9e15**.|
| crypto    | boolean                | No  | Yes  | Whether to use a pseudorandom number for encryption. The value **true** means to use a pseudorandom number for encryption, and **false** means the opposite. The default value is **false**. The capability is not supported yet, and error code 10200061 is reported if it is used. |
| modulo    | [Modulo](#modulo)      | No  | Yes  | Rounding mode used in the modulo operation. The value is an integer ranging from 0 to 9, and the default value is **1**.   |
| defaults  | boolean                | No  | Yes  | Whether the default value is used if no value is passed in for a property. The value **true** means that the default value is used, and **false** means the opposite. The default value is **true**.|

## Decimal

Decimal with any precision.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type    | Read-Only| Optional| Description                                     |
| ---- | -------- | ---- | ---- | ----------------------------------------- |
| d    | number[] | Yes  | No  | Digits in the integer part and factional part of a decimal.|
| e    | number   | Yes  | No  | Exponent in a decimal.|
| s    | number   | Yes  | No  | Sign in a decimal. **0**: positive; **1**: negative.|

### Constants

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name              | Type  | Value  | Description                                                        |
| ------------------ | ------ | ---- | ------------------------------------------------------------ |
| ROUND_UP           | number | 0    | Rounds in such a way that the result heads away from zero. In the modulo operation, if the dividend is negative, the remainder is positive; otherwise, the remainder is negative.|
| ROUND_DOWN         | number | 1    | Rounds in such a way that the result heads towards zero. In the modulo operation, the remainder has the same sign as the dividend, and truncating division is used.|
| ROUND_CEILING      | number | 2    | Rounds towards positive infinity.                                          |
| ROUND_FLOOR        | number | 3    | Rounds towards negative infinity. In the modulo operation, the remainder has the same sign as the dividend.          |
| ROUND_HALF_UP      | number | 4    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds away from zero.          |
| ROUND_HALF_DOWN    | number | 5    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards zero.          |
| ROUND_HALF_EVEN    | number | 6    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards the even neighbor. In the modulo operation, the modulo function in IEEE 754 is used.|
| ROUND_HALF_CEILING | number | 7    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards positive infinity.        |
| ROUND_HALF_FLOOR   | number | 8    | Rounds towards the nearest neighbor, and if both neighbors are equidistant, rounds towards negative infinity.        |
| EUCLIDEAN          | number | 9    | Always a positive remainder in the modulo operation. The Euclid's division formula is used: q = sign(x) * floor(a / abs(x)).|

### constructor

constructor(n: Value)

A constructor used to create a **Decimal** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                   |
| ------ | --------------- | ---- | ----------------------- |
| n      | [Value](#value) | Yes  | Initial value used to create the **Decimal** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(5);
console.info("test Decimal constructor:" + data.toString()); // 'test Decimal constructor:5'
```

### abs

abs(): Decimal

Returns a **Decimal** object representing the absolute value of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                               |
| ------------------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the absolute value.|

**Example**

```ts
let data: Decimal = new Decimal(-0.5).abs();
console.info("test Decimal abs:" + data.toString()); // 'test Decimal abs:0.5'
```

### floor

floor(): Decimal

Returns a **Decimal** object representing the nearest integer to which this decimal is rounded down.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Example**

```ts
let data: Decimal = new Decimal(1.8).floor();
console.info("test Decimal floor:" + data.toString()); // 'test Decimal floor:1'
```

### ceil

ceil(): Decimal

Returns a **Decimal** object representing the nearest integer to which this decimal is rounded up.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Example**

```ts
let data: Decimal = new Decimal(1.8).ceil();
console.info("test Decimal ceil:" + data.toString()); // 'test Decimal ceil:2'
```

### trunc

trunc(): Decimal

Returns a **Decimal** object representing the integer part truncated from this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the integer part.|

**Example**

```ts
let data: Decimal = new Decimal(2.5).trunc();
console.info("test Decimal trunc:" + data.toString()); // 'test Decimal trunc:2'
```

### clamp

clamp(min: Value, max: Value): Decimal

Returns a **Decimal** object representing the value clamped to the inclusive range of **min** and **max**. If the value is greater than **max**, **max** is returned. If the value is less than **min**, **min** is returned. Otherwise, the actual value is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                    |
| ------ | --------------- | ---- | ------------------------ |
| min    | [Value](#value) | Yes  | Lower bound of the range. This value is inclusive.|
| max    | [Value](#value) | Yes  | Upper bound of the range. This value is inclusive.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing a value within the range.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200001 | The value of \`min\` is out of range.                          |

**Example**

```ts
let data1: Decimal = new Decimal(10.1).clamp(0, 10);
console.info("test Decimal clamp:" + data1.toString()); // 'test Decimal clamp:10'

let data2: Decimal = new Decimal(-5).clamp(0, 10);
console.info("test Decimal clamp:" + data2.toString()); // 'test Decimal clamp:0'

let data3: Decimal = new Decimal(7.5).clamp(0, 10);
console.info("test Decimal clamp:" + data3.toString()); // 'test Decimal clamp:7.5'
```



### add

add(n: Value): Decimal

Returns a **Decimal** object representing the sum of adding the specified number *n* to this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Addend.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sum.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0.5).add(0.5);
console.info("test Decimal add:" + data.toString()); // 'test Decimal add:1'
```

### sub

sub(n: Value): Decimal

Returns a **Decimal** object representing the difference of subtracting the specified number *n* from this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Subtrahend.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the difference.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(1).sub(0.5);
console.info("test Decimal sub:" + data.toString()); // 'test Decimal sub:0.5'
```

### mul

mul(n: Value): Decimal

Returns a **Decimal** object representing the product of multiplying this decimal by the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Multiplicand.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the product.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(1).mul(0.5);
console.info("test Decimal mul:" + data.toString()); // 'test Decimal mul:0.5'
```

### div

div(n: Value): Decimal

Returns a **Decimal** object representing the quotient of dividing this decimal by the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Divisor.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the quotient.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(1).div(0.5);
console.info("test Decimal div:" + data.toString()); // 'test Decimal div:2'
```

### mod

mod(n: Value): Decimal

Returns a **Decimal** object representing the remainder of dividing this decimal by the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Divisor.|

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the remainder.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(2).mod(1);
console.info("test Decimal mod:" + data.toString()); // 'test Decimal mod:0'
```

### sqrt

sqrt(): Decimal

Returns a **Decimal** object representing the square root of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the square root.|

**Example**

```ts
let data: Decimal = new Decimal(3).sqrt();
console.info("test Decimal sqrt:" + data.toString()); // 'test Decimal sqrt:1.7320508075688772935'
```

### cbrt

cbrt(): Decimal

Returns a **Decimal** object representing the cube root of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cube root.|

**Example**

```ts
let data: Decimal = new Decimal(3).cbrt();
console.info("test Decimal cbrt:" + data.toString()); // 'test Decimal cbrt:1.4422495703074083823'
```

### pow

pow(n: Value): Decimal

Returns a **Decimal** object representing the value resulting from raising this decimal to the power of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Power of the exponentiation operation.|

**Return value**

| Type   | Description                         |
| ------- | ----------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the result of the exponentiation operation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = new Decimal(3).pow(-2);
console.info("test Decimal pow:" + data.toString()); // 'test Decimal pow:0.11111111111111111111'
```

### exp

exp(): Decimal

Returns a **Decimal** object representing the value resulting from raising e to the power of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                               |
| ------------------- | ------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the result of the natural exponentiation operation.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(2).exp();
console.info("test Decimal exp:" + data.toString()); // 'test Decimal exp:7.3890560989306502272'
```

### log

log(n: Value): Decimal

Returns a **Decimal** object representing the logarithm of this decimal to the specified base *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description              |
| ------ | --------------- | ---- | ------------------ |
| n      | [Value](#value) | Yes  | Base of the logarithm.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the logarithm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = new Decimal(2).log(256);
console.info("test Decimal log:" + data.toString()); // 'test Decimal log:0.125'
```

### ln

ln(): Decimal

Returns a **Decimal** object representing the natural logarithm of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the natural logarithm.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(1.23e+30).ln();
console.info("test Decimal ln:" + data.toString()); // 'test Decimal ln:69.284566959205696648'
```

### cos

cos(): Decimal

Returns a **Decimal** object representing the cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cosine.|

**Example**

```ts
let data: Decimal = new Decimal(-0.25).cos();
console.info("test Decimal cos:" + data.toString()); // 'test Decimal cos:0.96891242171064478414'
```

### sin

sin(): Decimal

Returns a **Decimal** object representing the sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sine.|

**Example**

```ts
let data: Decimal = new Decimal(0.75).sin();
console.info("test Decimal sin:" + data.toString()); // 'test Decimal sin:0.68163876002333416673'
```

### tan

tan(): Decimal

Returns a **Decimal** object representing the tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the tangent.|

**Example**

```ts
let data: Decimal = new Decimal(0.75).tan();
console.info("test Decimal tan:" + data.toString()); // 'test Decimal tan:0.93159645994407246117'
```

### cosh

cosh(): Decimal

Returns a **Decimal** object representing the hyperbolic cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic cosine.|

**Example**

```ts
let data: Decimal = new Decimal(0.5).cosh();
console.info("test Decimal cosh:" + data.toString()); // 'test Decimal cosh:1.1276259652063807852'
```

### sinh

sinh(): Decimal

Returns a **Decimal** object representing the hyperbolic sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic sine.|

**Example**

```ts
let data: Decimal = new Decimal(0.5).sinh();
console.info("test Decimal sinh:" + data.toString()); // 'test Decimal sinh:0.52109530549374736162'
```

### tanh

tanh(): Decimal

Returns a **Decimal** object representing the hyperbolic tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic tangent.|

**Example**

```ts
let data: Decimal = new Decimal(0.5).tanh();
console.info("test Decimal tanh:" + data.toString()); // 'test Decimal tanh:0.4621171572600097585'
```

### acos

acos(): Decimal

Returns a **Decimal** object representing the arc cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc cosine.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(0.5).acos();
console.info("test Decimal acos:" + data.toString()); // 'test Decimal acos:1.0471975511965977462'
```

### asin

asin(): Decimal

Returns a **Decimal** object representing the arc sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc sine.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(0.75).asin();
console.info("test Decimal asin:" + data.toString()); // 'test Decimal asin:0.84806207898148100805'
```

### atan

atan(): Decimal

Returns a **Decimal** object representing the arc tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc tangent.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(0.75).atan();
console.info("test Decimal atan:" + data.toString()); // 'test Decimal atan:0.6435011087932843868'
```

### acosh

acosh(): Decimal

Returns a **Decimal** object representing the inverse hyperbolic cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic cosine.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(50).acosh();
console.info("test Decimal acosh:" + data.toString()); // 'test Decimal acosh:4.6050701709847571595'
```

### asinh

asinh(): Decimal

Returns a **Decimal** object representing the inverse hyperbolic sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic sine.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(50).asinh();
console.info("test Decimal asinh:" + data.toString()); // 'test Decimal asinh:4.6052701709914238266'
```

### atanh

atanh(): Decimal

Returns a **Decimal** object representing the inverse hyperbolic tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic tangent.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                 |
| -------- | ------------------------- |
| 10200060 | Precision limit exceeded. |

**Example**

```ts
let data: Decimal = new Decimal(0.75).atanh();
console.info("test Decimal atanh:" + data.toString()); // 'test Decimal atanh:0.97295507452765665255'
```

### comparedTo

comparedTo(n: Value): number

Compares this decimal with the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Comparison result, which can be any of the following:<br>**1**: The decimal is greater than *n*.<br>**-1**: The decimal is less than *n*.<br>**0**: The decimal is equal to *n*.<br>**NaN**: Either the decimal or *n* is Not a Number (NaN).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(Infinity);
let data1: Decimal = new Decimal(5);
let data2: number = data.comparedTo(data1);
console.info("test Decimal comparedTo:" + data2); // 'test Decimal comparedTo:1'

let data3: number = data1.comparedTo(10.5);
console.info("test Decimal comparedTo:" + data3); // 'test Decimal comparedTo:-1'
```

### equals

equals(n: Value): boolean

Checks whether this decimal is equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type   | Description                                            |
| ------- | ------------------------------------------------ |
| boolean | Check result. The value **true** is returned if they are equal; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0);
let data1: boolean = data.equals('1e-324');
console.info("test Decimal equals:" + data1); // 'test Decimal equals:false'
```

### greaterThan

greaterThan(n: Value): boolean

Checks whether this decimal is greater than the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is greater than *n*; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0.1);
let data1: boolean = data.greaterThan(new Decimal(0.3).sub(0.2)); 
console.info("test Decimal greaterThan:" + data1); // 'test Decimal greaterThan:false'
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(n: Value): boolean

Checks whether this decimal is greater than or equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type   | Description                                              |
| ------- | -------------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is greater than or equal to *n*; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0.3).sub(0.2);
let data1: boolean = data.greaterThanOrEqualTo(0.1);
console.info("test Decimal greaterThanOrEqualTo:" + data1); // 'test Decimal greaterThanOrEqualTo:true'
```

### lessThan

lessThan(n: Value): boolean

Checks whether this decimal is less than the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is less than *n*; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0.3).sub(0.2);
let data1: boolean = data.lessThan(0.1)
console.info("test Decimal lessThan:" + data1); // 'test Decimal lessThan:false'
```

### lessThanOrEqualTo

lessThanOrEqualTo(n: Value): boolean

Checks whether this decimal is less than or equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Value to be compared.|

**Return value**

| Type   | Description                                              |
| ------- | -------------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is less than or equal to *n*; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(0.1);
let data1: boolean = data.lessThanOrEqualTo(new Decimal(0.3).sub(0.2))
console.info("test Decimal lessThanOrEqualTo:" + data1); // 'test Decimal lessThanOrEqualTo:true'
```

### isFinite

isFinite(): boolean

Checks whether this decimal is finite.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                        |
| ------- | -------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is finite; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(1);
let data1: boolean = data.isFinite();
console.info("test Decimal isFinite:" + data1); // 'test Decimal isFinite:true'
```

### isInteger

isInteger(): boolean

Checks whether this decimal is an integer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | Check result. The value **true** is returned if the decimal is an integer; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(123.456);
let data1: boolean = data.isInteger();
console.info("test Decimal isInteger:" + data1); // 'test Decimal isInteger:false'
```

### isNaN

isNaN(): boolean

Checks whether this decimal is NaN.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                     |
| ------- | ----------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is NaN; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(NaN);
let data1: boolean = data.isNaN();
console.info("test Decimal isNaN:" + data1); // 'test Decimal isNaN:true'
```

### isNegative

isNegative(): boolean

Checks whether this decimal is negative (including a distinction between positive and negative zero).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | Check result. The value **true** is returned if the decimal is negative; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(-5);
let data1: boolean = data.isNegative();
console.info("test Decimal isNegative:" + data1); // 'test Decimal isNegative:true'

let data2: Decimal = new Decimal(-0);
let data3: boolean = data2.isNegative();
console.info("test Decimal isNegative:" + data3); // 'test Decimal isNegative:true'
```

### isPositive

isPositive(): boolean

Checks whether this decimal is positive (including a distinction between positive and negative zero).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | Check result. The value **true** is returned if the decimal is positive; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(5);
let data1: boolean = data.isPositive();
console.info("test Decimal isPositive:" + data1); // 'test Decimal isPositive:true'

let data2: Decimal = new Decimal(0);
let data3: boolean = data2.isPositive();
console.info("test Decimal isPositive:" + data3); // 'test Decimal isPositive:true'
```

### isZero

isZero(): boolean

Returns whether this decimal is zero or minus zero.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Check result. The value **true** is returned if the decimal is zero or minus zero; otherwise, **false** is returned.|

**Example**

```ts
let data: Decimal = new Decimal(0);
let data1: boolean = data.isZero();
console.info("test Decimal isZero:" + data1.toString()); // 'test Decimal isZero:true'
```

### dividedToIntegerBy

dividedToIntegerBy(n: Value): Decimal

Returns a **Decimal** object representing the integer part of this decimal divided by the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Divisor.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the integer part.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(5);
let data1: Decimal = new Decimal(3);
let data2: Decimal = data.dividedToIntegerBy(data1);
console.info("test Decimal dividedToIntegerBy:" + data2.toString()); // 'test Decimal dividedToIntegerBy:1'
```

### negate

negate(): Decimal

Negates this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the negated value of the decimal.|

**Example**

```ts
let data: Decimal = new Decimal(1.8);
let data1: Decimal = data.negate();
console.info("test Decimal negate:" + data1.toString()); // 'test Decimal negate:-1.8'
```

### toBinary

toBinary(): string

Converts this decimal into a binary string.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Binary string.|

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toBinary();
console.info("test Decimal toBinary:" + data1); // 'test Decimal toBinary:0b100000000'
```

### toBinary

toBinary(significantDigits: number): string

Converts this decimal into a binary string, with the number of significant digits specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                                            |
| ----------------- | ------ | ---- | ------------------------------------------------ |
| significantDigits | number | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Binary string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of \`significantDigits\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toBinary(1);
console.info("test Decimal toBinary:" + data1); // 'test Decimal toBinary:0b1p+8'
```

### toBinary

toBinary(significantDigits: number, rounding: Rounding): string

Converts this decimal into a binary string, with the number of significant digits and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type                 | Mandatory| Description                                                     |
| ----------------- | --------------------- | ---- | --------------------------------------------------------- |
| significantDigits | number                | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].         |
| rounding          | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Binary string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of \`significantDigits \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toBinary(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toBinary:" + data1); // 'test Decimal toBinary:0b1p+8'
```

### toOctal

toOctal(): string

Converts this decimal into an octal string.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Octal string.|

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toOctal();
console.info("test Decimal toOctal:" + data1); // 'test Decimal toOctal:0o400'
```

### toOctal

toOctal(significantDigits: number): string

Converts this decimal into an octal string, with the number of significant digits specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                                            |
| ----------------- | ------ | ---- | ------------------------------------------------ |
| significantDigits | number | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Octal string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of \`significantDigits\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toOctal(1);
console.info("test Decimal toOctal:" + data1); // 'test Decimal toOctal:0o1p+8'
```

### toOctal

toOctal(significantDigits: number, rounding: Rounding): string

Converts this decimal into an octal string, with the number of significant digits and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type                 | Mandatory| Description                                                     |
| ----------------- | --------------------- | ---- | --------------------------------------------------------- |
| significantDigits | number                | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].         |
| rounding          | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Octal string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of \`significantDigits \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toOctal(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toOctal:" + data1); // 'test Decimal toOctal:0o1p+8'
```

### toHexadecimal

toHexadecimal(): string

Converts this decimal into a hexadecimal string.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Hexadecimal string.|

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toHexadecimal();
console.info("test Decimal toHexadecimal:" + data1); // 'test Decimal toHexadecimal:0x100'
```

### toHexadecimal

toHexadecimal(significantDigits: number): string

Converts this decimal into a hexadecimal string, with the number of significant digits specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                                            |
| ----------------- | ------ | ---- | ------------------------------------------------ |
| significantDigits | number | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Hexadecimal string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of \`significantDigits\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toHexadecimal(1);
console.info("test Decimal toHexadecimal:" + data1); // 'test Decimal toHexadecimal:0x1p+8'
```

### toHexadecimal

toHexadecimal(significantDigits: number, rounding: Rounding): string

Converts this decimal into a hexadecimal string, with the number of significant digits and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type                 | Mandatory| Description                                                     |
| ----------------- | --------------------- | ---- | --------------------------------------------------------- |
| significantDigits | number                | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].         |
| rounding          | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Hexadecimal string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of \`significantDigits \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(256);
let data1: string = data.toHexadecimal(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toHexadecimal:" + data1); // 'test Decimal toHexadecimal:0x1p+8'
```

### toDecimalPlaces

toDecimalPlaces(): Decimal

Truncates this decimal, without rounding.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object presenting the value with the given number of decimal places.|

**Example**

```ts
let data: Decimal = new Decimal(12.34567);
let data1: Decimal = data.toDecimalPlaces();
console.info("test Decimal toDecimalPlaces:" + data1.toString()); // 'test Decimal toDecimalPlaces:12.34567'
```

### toDecimalPlaces

toDecimalPlaces(decimalPlaces: number): Decimal

Truncates this decimal to a given number of decimal places.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                                                    |
| ------------- | ------ | ---- | -------------------------------------------------------- |
| decimalPlaces | number | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9].|

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object presenting the value with the given number of decimal places.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 10200001 | The value of \`decimalPlaces\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(9876.54321);
let data1: Decimal = data.toDecimalPlaces(3);
console.info("test Decimal toDecimalPlaces:" + data1.toString()); // 'test Decimal toDecimalPlaces:9876.543'
```

### toDecimalPlaces

toDecimalPlaces(decimalPlaces: number, rounding: Rounding): Decimal

Truncates this decimal to a given number of decimal places, with the rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type                 | Mandatory| Description                                                     |
| ------------- | --------------------- | ---- | --------------------------------------------------------- |
| decimalPlaces | number                | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9]. |
| rounding      | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object presenting the value with the given number of decimal places.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 10200001 | The value of \`decimalPlaces \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(9876.54321);
let data1: Decimal = data.toDecimalPlaces(1, 0);
console.info("test Decimal toDecimalPlaces:" + data1.toString()); // 'test Decimal toDecimalPlaces:9876.6'
data1 = data.toDecimalPlaces(1, Decimal.ROUND_DOWN) // data1: '9876.5'
```

### toExponential

toExponential(): string

Converts this decimal to a string expressed in exponential notation, without rounding.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | String expressed in exponential notation.|

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1: string = data.toExponential();
console.info("test Decimal toExponential:" + data1); // 'test Decimal toExponential:4.56e+1'
```

### toExponential

toExponential(decimalPlaces: number): string

Converts this decimal to a string expressed in exponential notation, with the number of decimal places specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                                                    |
| ------------- | ------ | ---- | -------------------------------------------------------- |
| decimalPlaces | number | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9].|

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | String expressed in exponential notation.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 10200001 | The value of \`decimalPlaces\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1: string = data.toExponential(0);
console.info("test Decimal toExponential:" + data1); // 'test Decimal toExponential:5e+1'
data1 = data.toExponential(1); // data1: '4.6e+1'
data1 = data.toExponential(3); // data1: '4.560e+1'
```

### toExponential

toExponential(decimalPlaces: number, rounding: Rounding): string

Converts this decimal to a string expressed in exponential notation, with the number of decimal places and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type                 | Mandatory| Description                                                     |
| ------------- | --------------------- | ---- | --------------------------------------------------------- |
| decimalPlaces | number                | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9]. |
| rounding      | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| string | String expressed in exponential notation.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 10200001 | The value of \`decimalPlaces \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1 = data.toExponential(1, Decimal.ROUND_DOWN);
console.info("test Decimal toExponential:" + data1); // 'test Decimal toExponential:4.5e+1'
```

### toFixed

toFixed(): string

Converts this decimal to a string expressed in decimal fixed-point mode, without rounding.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| string | String expressed in decimal fixed-point mode.|

**Example**

```ts
let data: Decimal = new Decimal(3.456);
let data1: string = data.toFixed();
console.info("test Decimal toFixed:" + data1); // 'test Decimal toFixed:3.456'
```

### toFixed

toFixed(decimalPlaces: number): string

Converts this decimal to a string expressed in decimal fixed-point mode, with the number of decimal places specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type  | Mandatory| Description                                                    |
| ------------- | ------ | ---- | -------------------------------------------------------- |
| decimalPlaces | number | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9].|

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| string | String expressed in decimal fixed-point mode.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 10200001 | The value of \`decimalPlaces\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(3.456);
let data1: string = data.toFixed(0)
console.info("test Decimal toFixed:" + data1); // 'test Decimal toFixed:3'
data1 = data.toFixed(2) // data1: '3.46'
data1 = data.toFixed(5) // data1: '3.45600'
```

### toFixed

toFixed(decimalPlaces: number, rounding: Rounding): string

Converts this decimal to a string expressed in decimal fixed-point mode, with the number of decimal places and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name       | Type                 | Mandatory| Description                                                     |
| ------------- | --------------------- | ---- | --------------------------------------------------------- |
| decimalPlaces | number                | Yes  | Number of decimal places to reserve. The value is an integer in the range of [0, 1e9]. |
| rounding      | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| string | String expressed in decimal fixed-point mode.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 10200001 | The value of \`decimalPlaces \| rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(3.456);
let data1: string = data.toFixed(2, Decimal.ROUND_DOWN);
console.info("test Decimal toFixed:" + data1); // b: 'test Decimal toFixed:3.45'
```

### toFraction

toFraction(): Decimal[]

Converts this decimal into a fraction.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| [Decimal](#decimal)[] | Decimal array with a fixed length of 2. The two integers in the array represent the numerator and the denominator, respectively.|

**Example**

```ts
let data: Decimal = new Decimal(1.75);
let data1: Decimal[] = data.toFraction();
console.info("test Decimal toFraction:" + data1.toString()); // 'test Decimal toFraction:7,4'
```

### toFraction

toFraction(maxDenominator: Value): Decimal[]

Converts this decimal to a fraction, with the maximum denominator specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name         | Type           | Mandatory| Description                    |
| --------------- | --------------- | ---- | ------------------------ |
| maxDenominator | [Value](#value) | Yes  | Maximum denominator. This value is inclusive.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| [Decimal](#decimal)[] | Decimal array with a fixed length of 2. The two integers in the array represent the numerator and the denominator, respectively.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let pi: Decimal = new Decimal('3.14159265358');
let data1 = pi.toFraction(); // data1: '157079632679,50000000000'
data1 = pi.toFraction(100000); // data1: '312689, 99532'
data1 = pi.toFraction(10000); // data1: '355, 113'
data1 = pi.toFraction(100); // data1: '311, 99'
data1 = pi.toFraction(10); // data1: '22, 7'
data1 = pi.toFraction(1); // data1: '3, 1'
```

### toNearest

toNearest(n: Value): Decimal

Multiplies the specified number *n* to a value closet to this decimal and returns this closest value in the form of a **Decimal object**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Number to be multiplied.|

**Return value**

| Type   | Description                                       |
| ------- | ------------------------------------------- |
| Decimal | **Decimal** object representing the closest value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = new Decimal(1.39);
let data1: Decimal = data.toNearest(0.25);
console.info("test Decimal toNearest:" + data1.toString()); // 'test Decimal toNearest:1.5'
```

### toNearest

toNearest(n: Value, rounding: Rounding): Decimal

Multiplies the specified number *n* to a value closet to this decimal and returns this closest value after rounding in the form of a **Decimal** object.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                 | Mandatory| Description                                                     |
| -------- | --------------------- | ---- | --------------------------------------------------------- |
| n        | [Value](#value)       | Yes  | Number to be multiplied.                                           |
| rounding | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the closest value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200001 | The value of \`rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(9.499);
let data1 = data.toNearest(0.5, Decimal.ROUND_UP); // data1: '9.5'
data1 = data.toNearest(0.5, Decimal.ROUND_DOWN); // data1: '9'
```

### toPrecision

toPrecision(): string

Converts this decimal into a string.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| string | **Decimal** object representing the string.|

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1: string = data.toPrecision();
console.info("test Decimal toPrecision:" + data1); // 'test Decimal toPrecision:45.6'
```

### toPrecision

toPrecision(significantDigits: number): string

Converts this decimal into a string, with the number of significant digits specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                  |
| ----------------- | ------ | ---- | ---------------------- |
| significantDigits | number | Yes  | Number of significant digits to reserve.|

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| string | **Decimal** object representing the string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of \`significantDigits\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1: string = data.toPrecision(1);
console.info("test Decimal toPrecision:" + data1); // 'test Decimal toPrecision:5e+1'
data1 = data.toPrecision(5); // data1: '45.600'
```

### toPrecision

toPrecision(significantDigits: number, rounding: Rounding): string

Converts this decimal into a string, with the number of significant digits and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type                 | Mandatory| Description                                                     |
| ----------------- | --------------------- | ---- | --------------------------------------------------------- |
| significantDigits | number                | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].         |
| rounding          | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| string | **Decimal** object representing the string.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of \`significantDigits \|  rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(45.6);
let data1: string = data.toPrecision(2, Decimal.ROUND_UP); // data1: '46'
data1 = data.toPrecision(2, Decimal.ROUND_DOWN); // data1: '45'
```

### toSignificantDigits

toSignificantDigits(): Decimal

Converts this decimal into another one with the number of significant digits specified.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                   |
| ------- | --------------------------------------- |
| [Decimal](#decimal) | **Decimal** object with the specified number of significant digits.|

**Example**

```ts
let data: Decimal = new Decimal(987.654321);
let data1: Decimal = data.toSignificantDigits();
console.info("test Decimal toSignificantDigits:" + data1.toString()); // 'test Decimal toSignificantDigits:987.654321'
```

### toSignificantDigits

toSignificantDigits(significantDigits: number): Decimal

Converts this decimal into another one with the number of significant digits specified.

You can use [DecimalConfig.rounding](#decimalconfig) to set the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                  |
| ----------------- | ------ | ---- | ---------------------- |
| significantDigits | number | Yes  | Number of significant digits to reserve.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object with the specified number of significant digits.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of \`significantDigits\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(987.654321);
let data1: Decimal = data.toSignificantDigits(6);
console.info("test Decimal toSignificantDigits:" + data1.toString()); // 'test Decimal toSignificantDigits:987.654'
```

### toSignificantDigits

toSignificantDigits(significantDigits: number, rounding: Rounding): Decimal

Converts this decimal into another one with the number of significant digits and rounding mode specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type                 | Mandatory| Description                                                     |
| ----------------- | --------------------- | ---- | --------------------------------------------------------- |
| significantDigits | number                | Yes  | Number of significant digits to reserve. The value is an integer in the range of [1, 1e9].         |
| rounding          | [Rounding](#rounding) | Yes  | Rounding mode. For details, see [Rounding](#rounding).|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object with the specified number of significant digits.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 10200001 | The value of \`significantDigits \|  rounding\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(987.654321);
let data1: Decimal = data.toSignificantDigits(6, Decimal.ROUND_UP);
console.info("test Decimal toSignificantDigits:" + data1.toString()); // 'test Decimal toSignificantDigits:987.655'
```

### toNumber

toNumber(): number

Converts this decimal into a number.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                           |
| ------ | ------------------------------- |
| number | Number representing the decimal.|

**Example**

```ts
let data: Decimal = new Decimal(456.789);
let data1: number = data.toNumber();
console.info("test Decimal toNumber:" + data1.toString()); // 'test Decimal toNumber:456.789'
```

### toString

toString(): string

Converts this decimal into a string. If the positive exponent of the decimal is greater than or equal to [toExpPos](#decimalconfig), or if the negative exponent is less than or equal to [toExpNeg](#decimalconfig), exponential notation is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                         |
| ------ | ----------------------------- |
| string | String representing the decimal.|

**Example**

```ts
let data: Decimal = new Decimal(750000);
let data1: string = data.toString();
console.info("test Decimal toString:" + data1); // 'test Decimal toString:750000'

Decimal.set({ toExpPos: 5 });
data1 = data.toString(); // data1:'7.5e+5'

let data2: Decimal = new Decimal(0.000000123);
console.info("test Decimal toString:" + data2.toString()); // 'test Decimal toString:1.23e-7'

Decimal.set({ toExpNeg: -7 });
data1 = data2.toString(); // data1:'1.23e-7'
```

### valueOf

valueOf(): string

Returns a string representing the value of this decimal. Negative zeros contain minus signs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                         |
| ------ | ----------------------------- |
| string | String representing the decimal.|

**Example**

```ts
let data: Decimal = new Decimal(-0);
let data1: string = data.valueOf();
console.info("test Decimal valueOf:" + data1); // 'test Decimal valueOf:-0'
```

### decimalPlaces

decimalPlaces(): number

Returns the number of decimal places of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | Number of decimal places.|

**Example**

```ts
let data: Decimal = new Decimal(1.234);
let data1: number = data.decimalPlaces();
console.info("test Decimal decimalPlaces:" + data1); // 'test Decimal decimalPlaces:3'
```

### precision

precision(): number

Returns the number of significant digits of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | Number of significant digits.|

**Example**

```ts
let data: Decimal = new Decimal(1.234);
let data1: number = data.precision();
console.info("test Decimal precision:" + data1); // 'test Decimal precision:4'
```

### precision

precision(includeZeros: boolean | number): number

Returns the number of significant digits of this decimal, with **includeZeros** specified to determine whether to count the number of trailing zeros in the integer part.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type   | Mandatory| Description                                                        |
| ------------ | ------- | ---- | ------------------------------------------------------------ |
| includeZeros | boolean \| number | Yes  | Whether to count the number of trailing zeros in the integer part. The value **true** or **1** means to count the number of trailing zeros in the integer part, and **false** or **0** means the opposite.|

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | Number of significant digits.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 10200001 | The value of \`includeZeros\` is out of range. |

**Example**

```ts
let data: Decimal = new Decimal(987000);
let data1: number = data.precision();
console.info("test Decimal precision:" + data1); // 'test Decimal precision:3'
data1 = data.precision(true); // data1:'6'
```

### abs

static abs(n: Value): Decimal

Returns a **Decimal** object representing the absolute value of the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the absolute value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.abs(-0.5);
console.info("test Decimal abs:" + data.toString()); // 'test Decimal abs:0.5'
```

### floor

static floor(n: Value): Decimal

Returns a **Decimal** object representing the nearest integer to which the specified number *n* is rounded down.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.floor(1.8);
console.info("test Decimal floor:" + data.toString()); // 'test Decimal floor:1'
```

### ceil

static ceil(n: Value): Decimal

Returns a **Decimal** object representing the nearest integer to which the specified number *n* is rounded up.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.ceil(1.8);
console.info("test Decimal ceil:" + data.toString()); // 'test Decimal ceil:2'
```

### trunc

static trunc(n: Value): Decimal

Returns a **Decimal** object representing the integer part truncated from this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the integer part.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.trunc(2.5);
console.info("test Decimal trunc:" + data.toString()); // 'test Decimal trunc:2'
```

### clamp

static clamp(n: Value, min: Value, max: Value): Decimal

Returns a **Decimal** object representing the value clamped to the inclusive range of **min** and **max** of the specified number *n*. If the actual value exceeds the maximum limit, **max** is returned; if it falls below the minimum limit, **min** is returned; otherwise, the actual value is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                    |
| ------ | --------------- | ---- | ------------------------ |
| n      | [Value](#value) | Yes  | Value to be clamped.        |
| min    | [Value](#value) | Yes  | Lower bound of the range. This value is inclusive.|
| max    | [Value](#value) | Yes  | Upper bound of the range. This value is inclusive.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing a value within the range.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200001 | The value of \`min\` is out of range.                          |

**Example**

```ts
let data: Decimal = Decimal.clamp(10.1, 0, 10);
console.info("test Decimal clamp:" + data.toString()); // 'test Decimal clamp:10'
```

### add

static add(x: Value, y: Value): Decimal

Returns a **Decimal** object representing the sum of two numbers *x* and *y*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description              |
| ------ | --------------- | ---- | ------------------ |
| x      | [Value](#value) | Yes  | Augend.  |
| y      | [Value](#value) | Yes  | Addend.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sum.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.add(0.5, 0.5);
console.info("test Decimal add:" + data.toString()); // 'test Decimal add:1'
```

### sum

static sum(...n: Value[]): Decimal

Returns a **Decimal** object representing the sum of elements in an array. This API is used to sum up the parameters. If no parameter is passed, a runtime exception will be thrown.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description        |
| ------ | ----------------- | ---- | ------------ |
| n      | [Value](#value)[] | No  | Target array to operate.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sum.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.sum(0.5, 0.5);
console.info("test Decimal sum:" + data.toString()); // 'test Decimal sum:1'
```

### sub

static sub(x: Value, y: Value): Decimal

Returns a **Decimal** object representing the difference between two numbers *x* and *y*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| x      | [Value](#value) | Yes  | Minuend.|
| y      | [Value](#value) | Yes  | Subtrahend.  |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the difference.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.sub(1, 0.5);
console.info("test Decimal sub:" + data.toString()); // 'test Decimal sub:0.5'
```

### mul

static mul(x: Value, y: Value): Decimal

Returns a **Decimal** object representing the product of two numbers *x* and *y*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| x      | [Value](#value) | Yes  | Multiplier.|
| y      | [Value](#value) | Yes  | Multiplicand.  |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the product.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.mul(1, 0.5);
console.info("test Decimal mul:" + data.toString()); // 'test Decimal mul:0.5'
```

### div

static div(x: Value, y: Value): Decimal

Returns a **Decimal** object representing the quotient of two numbers *x* and *y*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| x      | [Value](#value) | Yes  | Dividend.|
| y      | [Value](#value) | Yes  | Divisor.  |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the quotient.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |


**Example**

```ts
let data: Decimal = Decimal.div(1, 0.5);
console.info("test Decimal div:" + data.toString()); // 'test Decimal div:2'
```

### mod

static mod(x: Value, y: Value): Decimal

Returns a **Decimal** object representing the remainder of two numbers *x* and *y*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description              |
| ------ | --------------- | ---- | ------------------ |
| x      | [Value](#value) | Yes  | Dividend.|
| y      | [Value](#value) | Yes  | Divisor.  |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the remainder.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.mod(2, 1);
console.info("test Decimal mod:" + data.toString()); // 'test Decimal mod:0'
```

### sqrt

static sqrt(n: Value): Decimal

Returns a **Decimal** object representing the square root of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                               |
| ------------------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the square root.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.sqrt(3);
console.info("test Decimal sqrt:" + data.toString()); // 'test Decimal sqrt:1.7320508075688772935'
```

### cbrt

static cbrt(n: Value): Decimal

Returns a **Decimal** object representing the cube root of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                               |
| ------------------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cube root.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.cbrt(3);
console.info("test Decimal cbrt:" + data.toString()); // 'test Decimal cbrt:1.4422495703074083823'
```

### pow

static pow(base: Value, exponent: Value): Decimal

Returns a **Decimal** object representing the value resulting from raising a number to the power of another number. You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type           | Mandatory| Description              |
| -------- | --------------- | ---- | ------------------ |
| base     | [Value](#value) | Yes  | Base of the exponentiation operation.|
| exponent | [Value](#value) | Yes  | Power of the exponentiation operation.  |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the result of the exponentiation operation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.pow(3, -2);
console.info("test Decimal pow:" + data.toString()); // 'test Decimal pow:0.11111111111111111111'
```

### exp

static exp(n: Value): Decimal

Returns a **Decimal** object representing the value resulting from raising e to the power of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value) | Yes  | Power of the natural exponentiation operation.|

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the result of the natural exponentiation operation.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.exp(2);
console.info("test Decimal exp:" + data.toString()); // 'test Decimal exp:7.3890560989306502272'
```

### log

static log(n: Value, base: Value): Decimal

Returns a **Decimal** object representing the logarithm of the specified number *n* to the specified base.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Real number of the logarithmic operation.|
| base   | [Value](#value) | Yes  | Base of the logarithmic operation.  |

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the logarithm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.log(2, 256);
console.info("test Decimal log:" + data.toString()); // 'test Decimal log:0.125'
```

### ln

static ln(n: Value): Decimal

Returns a **Decimal** object representing the natural logarithm of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Real number of the logarithmic operation.|

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the natural logarithm.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.ln(1.23e+30);
console.info("test Decimal ln:" + data.toString()); // 'test Decimal ln:69.284566959205696648'
```

### log2

static log2(n: Value): Decimal

Returns a **Decimal** object representing the base 2 logarithm of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Real number of the logarithmic operation.|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the base 2 logarithm of the specified number.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.log2(4);
console.info("test Decimal log2:" + data.toString()); // 'test Decimal log2:2'
```

### log10

static log10(n: Value): Decimal

Returns a **Decimal** object representing the base 10 logarithm of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Real number of the logarithmic operation.|

**Return value**

| Type               | Description                                       |
| ------------------- | ------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the base 10 logarithm of the specified number.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.log10(10000);
console.info("test Decimal log10:" + data.toString()); // 'test Decimal log10:4'
```

### cos

static cos(n: Value): Decimal

Returns a **Decimal** object representing the cosine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cosine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.cos(-0.25);
console.info("test Decimal cos:" + data.toString()); // 'test Decimal cos:0.96891242171064478414'
```

### sin

static sin(n: Value): Decimal

Returns a **Decimal** object representing the sine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.sin(0.75);
console.info("test Decimal sin:" + data.toString()); // 'test Decimal sin:0.68163876002333416673'
```

### tan

static tan(n: Value): Decimal

Returns a **Decimal** object representing the tangent of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description            |
| ------ | --------------- | ---- | ---------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the tangent.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.tan(0.75);
console.info("test Decimal tan:" + data.toString()); // 'test Decimal tan:0.93159645994407246117'
```

### cosh

static cosh(n: Value): Decimal

Returns a **Decimal** object representing the hyperbolic cosine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                  |
| ------ | --------------- | ---- | ---------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic cosine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.cosh(0.5);
console.info("test Decimal cosh:" + data.toString()); // 'test Decimal cosh:1.1276259652063807852'
```

### sinh

static sinh(n: Value): Decimal

Returns a **Decimal** object representing the hyperbolic sine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                  |
| ------ | --------------- | ---- | ---------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic sine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.sinh(0.5);
console.info("test Decimal sinh:" + data.toString()); // 'test Decimal sinh:0.52109530549374736162'
```

### tanh

static tanh(n: Value): Decimal

Returns a **Decimal** object representing the hyperbolic tangent of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                  |
| ------ | --------------- | ---- | ---------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                      |
| ------------------- | ------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic tangent.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.tanh(0.5);
console.info("test Decimal tanh:" + data.toString()); // 'test Decimal tanh:0.4621171572600097585'
```

### acos

static acos(n: Value): Decimal

Returns a **Decimal** object representing the arc cosine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc cosine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.acos(0.5);
console.info("test Decimal acos:" + data.toString()); // 'test Decimal acos:1.0471975511965977462'
```

### asin

static asin(n: Value): Decimal

Returns a **Decimal** object representing the arc sine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc sine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.asin(0.75);
console.info("test Decimal asin:" + data.toString()); // 'test Decimal asin:0.84806207898148100805'
```

### atan

static atan(n: Value): Decimal

Returns a **Decimal** object representing the arc tangent of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc tangent.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.atan(0.75);
console.info("test Decimal atan:" + data.toString()); // 'test Decimal atan:0.6435011087932843868'
```

### acosh

static acosh(n: Value): Decimal

Returns a **Decimal** object representing the inverse hyperbolic cosine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                      |
| ------ | --------------- | ---- | -------------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                          |
| ------------------- | ---------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic cosine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.acosh(50);
console.info("test Decimal acosh:" + data.toString()); // 'test Decimal acosh:4.6050701709847571595'
```

### asinh

static asinh(n: Value): Decimal

Returns a **Decimal** object representing the inverse hyperbolic sine of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                      |
| ------ | --------------- | ---- | -------------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                          |
| ------------------- | ---------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic sine.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.asinh(50);
console.info("test Decimal asinh:" + data.toString()); // 'test Decimal asinh:4.6052701709914238266'
```

### atanh

static atanh(n: Value): Decimal

Returns a **Decimal** object representing the inverse hyperbolic tangent of the specified number *n*.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                      |
| ------ | --------------- | ---- | -------------------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                          |
| ------------------- | ---------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the inverse hyperbolic tangent.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.atanh(0.75);
console.info("test Decimal atanh:" + data.toString()); // 'test Decimal atanh:0.97295507452765665255'
```

### atan2

static atan2(y: Value, x: Value): Decimal

Returns a **Decimal** object representing the arc tangent of y/x in the range from -π to π.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| y      | [Value](#value) | Yes  | Dividend.|
| x      | [Value](#value) | Yes  | Divisor.  |

**Return value**

| Type               | Description                                                      |
| ------------------- | ---------------------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the arc tangent of y/x in the range from -π to π.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let data: Decimal = Decimal.atan2(2, 3);
console.info("test Decimal atan2:" + data.toString()); // 'test Decimal atan2:0.58800260354756755125'
```

### hypot

static hypot(...n: Value[]): Decimal

Returns a **Decimal** object representing the Euclidean norm of elements in an array. If no parameter is passed, 0 is returned by default.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description                |
| ------ | ----------------- | ---- | -------------------- |
| n      | [Value](#value)[] | No  | Target array to operate.|

**Return value**

| Type               | Description                                             |
| ------------------- | ------------------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the Euclidean norm of the elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.hypot(2, 3, 4);
console.info("test Decimal hypot:" + data.toString()); // 'test Decimal hypot:5.3851648071345040313'
```

### max

static max(...n: Value[]): Decimal

Returns a **Decimal** object representing the maximum value among all elements in an array. This API is used to obtain the maximum value of the parameters. If no parameter is passed, a runtime exception occurs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description                |
| ------ | ----------------- | ---- | -------------------- |
| n      | [Value](#value)[] | No  | Target array to operate.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the maximum value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.max(2, 3, 4);
console.info("test Decimal max:" + data.toString()); // 'test Decimal max:4'
```

### min

static min(...n: Value[]): Decimal

Returns a **Decimal** object representing the minimum value among all elements in an array. This API is used to obtain the minimum value of the parameters. If no parameter is passed, a runtime exception occurs.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value)[] | No  | Target array to operate.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the minimum value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data: Decimal = Decimal.min(2, 3, 4);
console.info("test Decimal min:" + data.toString()); // 'test Decimal min:2'
```

### random

static random(): Decimal

Returns a **Decimal** object representing a random number in the range [0, 1).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing a random number in the range [0, 1).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message           |
| -------- | ------------------- |
| 10200061 | Crypto unavailable. |

**Example**

```ts
let data: Decimal = Decimal.random();
```

### random

static random(significantDigits: number): Decimal

Returns a **Decimal** object representing a random number in the range [0, 1), with the number of significant digits specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name           | Type  | Mandatory| Description                  |
| ----------------- | ------ | ---- | ---------------------- |
| significantDigits | number | Yes  | Number of significant digits reserved for the random number.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing a random number in the range [0, 1).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200061 | Crypto unavailable.                                          |

**Example**

```ts
let data: Decimal = Decimal.random(20);
```

### sign

static sign(n: Value): number

Checks the specified number **n**. In the case of n>0, **1** is returned; in the case of n<0, **-1** is returned; in the case of n==0, **0** is returned; in the case of n==-0, **-0** is returned; in any other cases, **NaN** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Number to check.|

**Return value**

| Type  | Description                              |
| ------ | ---------------------------------- |
| number | Value based on the check result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let data1: number = Decimal.sign(2);
console.info("test Decimal sign:" + data1); // 'test Decimal sign:1'

let data2: number = Decimal.sign(-3);
console.info("test Decimal sign:" + data2); // 'test Decimal sign:-1'

let data3: number = Decimal.sign(0);
console.info("test Decimal sign:" + data3); // 'test Decimal sign:0'

let data4: number = Decimal.sign(3.14);
console.info("test Decimal sign:" + data4); // 'test Decimal sign:1'

let data5: number = Decimal.sign(-1.618);
console.info("test Decimal sign:" + data5); // 'test Decimal sign:-1'

let data6: number = Decimal.sign("100");
console.info("test Decimal sign:" + data6); // 'test Decimal sign:1'

let data7: number = Decimal.sign("-50");
console.info("test Decimal sign:" + data7); // 'test Decimal sign:-1'

let data8: number = Decimal.sign(NaN);
console.info("test Decimal sign:" + data8); // 'test Decimal sign:NaN'

```

### round

static round(n: Value): Decimal

Returns a **Decimal** object representing the specified number *n* rounded to an integer using the rounding mode specified by [DecimalConfig.rounding](#decimalconfig).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description          |
| ------ | --------------- | ---- | -------------- |
| n      | [Value](#value) | Yes  | Target number to operate.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the integer rounded.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |

**Example**

```ts
let x = 3.3333333333333;
let data = Decimal.round(x);
console.info("test Decimal round:" + data.toString()); // 'test Decimal round:3'
```

### set

static set(config: DecimalConfig):void

Sets the properties for this **Decimal** object. The properties set by calling this API take effect globally.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                           | Mandatory| Description                |
| ------ | ------------------------------- | ---- | -------------------- |
| config | [DecimalConfig](#decimalconfig) | Yes  | Properties to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:1. Incorrect parameter types;2. Parameter verification failed. |
| 10200001 | The value of \`DecimalConfig.properties\` is out of range.     |
| 10200061 | Crypto unavailable.                                          |

**Example 1**

```ts
let data : Decimal = new Decimal(1.2345678901234567);
Decimal.set({
    precision: 5,
    rounding: 4,
    toExpNeg: -7,
    toExpPos: 7,
    maxE: 9e15,
    minE: -9e15,
    modulo: 1,
    crypto: false
});
let data1 : Decimal = data.add(0.5);
console.info("test Decimal set:" + data1.toString()); // "test Decimal set:1.7346"
// Set all properties to their default values.
Decimal.set({ defaults: true });
let data2 : Decimal = data.add(0.5);
console.info("test Decimal set:" + data2.toString()); // "test Decimal set:1.7345678901234567"
// Set the maximum number of significant digits to 10 and retain the default values for other properties.
Decimal.set({ precision: 10, defaults: true });
let data3 : Decimal = data.add(0.5);
console.info("test Decimal set:" + data3.toString()); // "test Decimal set:1.73456789"

// Usage of toExpNeg and toExpPos:
Decimal.set({ toExpNeg: -7 });
let x0 : Decimal = new Decimal(0.00000123); // x0:'0.00000123'
let x1 : Decimal = new Decimal(0.000000123); // x1:'1.23e-7'

Decimal.set({ toExpPos: 2 });
let y0 : Decimal = new Decimal(12.3); // y0:'12.3'
let y1 : Decimal = new Decimal(123); // y1:'1.23e+2'

// All data is expressed in scientific notation.
Decimal.set({ toExpPos: 0 });

// Usage of minE and maxE:
Decimal.set({ minE: -500 });
let a0 : Decimal = new Decimal('1e-500'); // a0:'1e-500'
let a1 : Decimal = new Decimal('9.9e-501'); // a1:'0e0'

Decimal.set({ minE: -3 });
let b0 : Decimal = new Decimal(0.001); // b0:'0.001'
let b1 : Decimal = new Decimal(0.0001); // b1:'0e0'

Decimal.set({ maxE: 500 });
let c0 : Decimal = new Decimal('9.999e500'); // c0:'9.999e+500'
let c1 : Decimal = new Decimal('1e501'); // c1:'Infinity'

Decimal.set({ maxE: 4 });
let d0 : Decimal = new Decimal(99999); // d0:'9.9999e+4'
let d1 : Decimal = new Decimal(100000); // d1:'Infinity'
```

**Example 2**
<!--code_no_check-->
```ts
// /entry/src/main/ets/pages/test.ets
export function test(){
  let data : Decimal = new Decimal(1.2345678901234567);
  Decimal.set({
    precision: 5,
    rounding: 0,
    toExpNeg: -7,
    toExpPos: 7,
    maxE: 9e15,
    minE: -9e15,
    modulo: 1,
    crypto: false
  });
  let data1 : Decimal = data.add(0.5);
  console.info("test Decimal set:" + data1.toString()); // 'test Decimal set:1.7346'
}
```
<!--code_no_check-->
```ts
// /entry/src/main/ets/pages/Index.ets
import {test} from './test';

let data : Decimal = new Decimal(1.2345678901234567);
Decimal.set({
  precision: 6,
  rounding: 1,
  toExpNeg: -7,
  toExpPos: 7,
  maxE: 9e15,
  minE: -9e15,
  modulo: 1,
  crypto: false
});
let data1 : Decimal = data.add(0.5);
console.info("test Decimal set:" + data1.toString()); // 'test Decimal set:1.73456'
test();
data1 = data1.add(0); // data1:'1.7346'
console.info("test Decimal set:" + data1.toString()); // 'test Decimal set:1.7346'
```
