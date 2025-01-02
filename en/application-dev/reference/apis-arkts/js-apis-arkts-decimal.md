# @arkts.math.Decimal (High-Precision Math Library Decimal)

The Decimal module provides a high-precision math library that offers the capability of high-precision floating-point arithmetic.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


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
| 9                      | Positive remainder from Euclid's division. It is the same as [Decimal.EUCLID](#constants).|

## DecimalConfig

Describes the configuration of a **Decimal** object. You can call [Decimal.set](#set) to set these properties.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name     | Type                  | Read-Only| Mandatory| Description                                                        |
| --------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| precision | number                 | No  | No  | Maximum number of significant digits of the result of an operation. The value range is [1, 1e9], and the default value is **20**.    |
| rounding  | [Rounding](#rounding) | No  | No  | Rounding mode. The value is an integer ranging from 0 to 8, and the default value is **4**.                 |
| toExpNeg  | number                 | No  | No  | Negative exponent value at and below which [toString](#tostring) returns exponential notation. The value range is [-9e15, 0], and the default value is **-7**.|
| toExpPos  | number                 | No  | No  | Positive exponent value at and above which [toString](#tostring) returns exponential notation. The value range is [0, 9e15], and the default value is **20**.|
| minE      | number                 | No  | No  | Minimum negative exponents. A decimal with an exponent less than this minimum value underflows towards zero. The value range is [-9e15, 0], and the default value is **-9e15**.|
| maxE      | number                 | No  | No  | Maximum positive exponent. A decimal with an exponent greater than this maximum value overflows to infinity. The value range is [0, 9e15], and the default value is **9e15**.|
| crypto    | boolean                | No  | No  | Whether to use a pseudorandom number for encryption. The default value is **false**.     |
| modulo    | [Modulo](#modulo)      | No  | No  | Rounding mode used in the modulo operation. The value is an integer ranging from 0 to 9, and the default value is **1**.   |
| defaults  | boolean                | No  | No  | Whether the default value is used if no value is passed in for a property. The value **true** means that the default value is used, and **false** means the opposite. The default value is **false**.|

## Decimal

Decimal with any precision.

### Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

| Name| Type    | Read-Only| Mandatory| Description                                     |
| ---- | -------- | ---- | ---- | ----------------------------------------- |
| d    | number[] | Yes  | Yes  | Digits in the integer part and factional part of a decimal.|
| e    | number   | Yes  | Yes  | Exponent in a decimal.|
| s    | number   | Yes  | Yes  | Sign in a decimal.            |

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
| EUCLID             | number | 9    | Always a positive remainder in the modulo operation. The Euclid's division formula is used: q = sign(x) * floor(a / abs(x)).|

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(5);
console.info("test Decimal constructor:" + a.toString()); // '5'
```

### abs

abs(): Decimal

Returns a new **Decimal** object representing the absolute value of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                               |
| ------------------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the absolute value.|

**Example**

```ts
let a: Decimal = new Decimal(-0.5).abs();
console.info("test Decimal abs:" + a.toString()); // '0.5'
```

### floor

floor(): Decimal

Returns a new **Decimal** object representing the nearest integer to which this decimal is rounded down.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Example**

```ts
let a: Decimal = new Decimal(1.8).floor();
console.info("test Decimal floor:" + a.toString()); // '1'
```

### ceil

ceil(): Decimal

Returns a new **Decimal** object representing the nearest integer to which this decimal is rounded up.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the nearest integer rounded.|

**Example**

```ts
let a: Decimal = new Decimal(1.8).ceil();
console.info("test Decimal ceil:" + a.toString()); // '2'
```

### trunc

trunc(): Decimal

Returns a new **Decimal** object representing the integer part truncated from this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the integer part.|

**Example**

```ts
let a: Decimal = new Decimal(2.5).trunc();
console.info("test Decimal trunc:" + a.toString()); // '2'
```

### clamp

clamp(min: Value, max: Value): Decimal

Returns a new **Decimal** object representing the value clamped to the inclusive range of **min** and **max**.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200001 | The value of 'min' is out of range.                          |

**Example**

```ts
let a: Decimal = new Decimal(10.1).clamp(0, 10);
console.info("test Decimal clamp:" + a.toString()); // '10'
```



### add

add(n: Value): Decimal;

Returns a new **Decimal** object representing the sum of adding the specified number *n* to this decimal.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0.5).add(0.5);
console.info("test Decimal add:" + a.toString()); // '1'
```

### sub

sub(n: Value): Decimal

Returns a new **Decimal** object representing the difference of subtracting the specified number *n* from this decimal.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(1).sub(0.5);
console.info("test Decimal sub:" + a.toString()); // '0.5'
```

### mul

mul(n: Value): Decimal

Returns a new **Decimal** object representing the product of multiplying this decimal by the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(1).mul(0.5);
console.info("test Decimal mul:" + a.toString()); // '0.5'
```

### div

div(n: Value): Decimal

Returns a new **Decimal** object representing the quotient of dividing this decimal by the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(1).div(0.5);
console.info("test Decimal div:" + a.toString()); // '2'
```

### mod

mod(n: Value): Decimal

Returns a new **Decimal** object representing the remainder of dividing this decimal by the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(2).mod(1);
console.info("test Decimal mod:" + a.toString()); // '0'
```

### sqrt

sqrt(): Decimal

Returns a new **Decimal** object representing the square root of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the square root.|

**Example**

```ts
let a: Decimal = new Decimal(3).sqrt();
console.info("test Decimal sqrt:" + a.toString()); // '1.7320508075688772935'
```

### cbrt

cbrt(): Decimal

Returns a new **Decimal** object representing the cube root of this decimal.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                             |
| ------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cube root.|

**Example**

```ts
let a: Decimal = new Decimal(3).cbrt();
console.info("test Decimal cbrt:" + a.toString()); // '1.4422495703074083823'
```

### pow

pow(n: Value): Decimal

Returns a new **Decimal** object representing the value resulting from raising this decimal to the power of the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = new Decimal(3).pow(-2);
console.info("test Decimal pow:" + a.toString()); // '0.11111111111111111111'
```

### exp

exp(): Decimal

Returns a new **Decimal** object representing the value resulting from raising e to the power of this decimal.

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
let a: Decimal = new Decimal(2).exp();
console.info("test Decimal exp:" + a.toString()); // '7.3890560989306502272'
```

### log

log(n: Value): Decimal

Returns a new **Decimal** object representing the logarithm of this decimal to the specified base *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = new Decimal(2).log(256);
console.info("test Decimal log:" + a.toString()); // '0.125'
```

### ln

ln(): Decimal

Returns a new **Decimal** object representing the natural logarithm of this decimal.

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
let a: Decimal = new Decimal(1.23e+30).ln();
console.info("test Decimal ln:" + a.toString()); // '69.284566959205696648'
```

### cos

cos(): Decimal

Returns a new **Decimal** object representing the cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the cosine.|

**Example**

```ts
let a: Decimal = new Decimal(-0.25).cos();
console.info("test Decimal cos:" + a.toString()); // '0.96891242171064478414'
```

### sin

sin(): Decimal

Returns a new **Decimal** object representing the sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sine.|

**Example**

```ts
let a: Decimal = new Decimal(0.75).sin();
console.info("test Decimal sin:" + a.toString()); // '0.68163876002333416673'
```

### tan

tan(): Decimal

Returns a new **Decimal** object representing the tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the tangent.|

**Example**

```ts
let a: Decimal = new Decimal(0.75).tan();
console.info("test Decimal tan:" + a.toString()); // '0.93159645994407246117'
```

### cosh

cosh(): Decimal

Returns a new **Decimal** object representing the hyperbolic cosine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic cosine.|

**Example**

```ts
let a: Decimal = new Decimal(0.5).cosh();
console.info("test Decimal cosh:" + a.toString()); // '1.1276259652063807852'
```

### sinh

sinh(): Decimal

Returns a new **Decimal** object representing the hyperbolic sine of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic sine.|

**Example**

```ts
let a: Decimal = new Decimal(0.5).sinh();
console.info("test Decimal sinh:" + a.toString()); // '0.52109530549374736162'
```

### tanh

tanh(): Decimal

Returns a new **Decimal** object representing the hyperbolic tangent of this decimal.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the hyperbolic tangent.|

**Example**

```ts
let a: Decimal = new Decimal(0.5).tanh();
console.info("test Decimal tanh:" + a.toString()); // '0.4621171572600097585'
```

### acos

acos(): Decimal

Returns a new **Decimal** object representing the arc cosine of this decimal.

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
let a: Decimal = new Decimal(0.5).acos();
console.info("test Decimal acos:" + a.toString()); // '1.0471975511965977462'
```

### asin

asin(): Decimal

Returns a new **Decimal** object representing the arc sine of this decimal.

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
let a: Decimal = new Decimal(0.75).asin();
console.info("test Decimal asin:" + a.toString()); // '0.84806207898148100805'
```

### atan

atan(): Decimal

Returns a new **Decimal** object representing the arc tangent of this decimal.

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
let a: Decimal = new Decimal(0.75).atan();
console.info("test Decimal atan:" + a.toString()); // '0.6435011087932843868'
```

### acosh

acosh(): Decimal

Returns a new **Decimal** object representing the inverse hyperbolic cosine of this decimal.

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
let a: Decimal = new Decimal(50).acosh();
console.info("test Decimal acosh:" + a.toString()); // '4.6050701709847571595'
```

### asinh

asinh(): Decimal

Returns a new **Decimal** object representing the inverse hyperbolic sine of this decimal.

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
let a: Decimal = new Decimal(50).asinh();
console.info("test Decimal asinh:" + a.toString()); // '4.6052701709914238266'
```

### atanh

atanh(): Decimal

Returns a new **Decimal** object representing the inverse hyperbolic tangent of this decimal.

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
let a: Decimal = new Decimal(0.75).atanh();
console.info("test Decimal atanh:" + a.toString()); // '0.97295507452765665255'
```

### comparedTo

comparedTo(n: Value): number

Compares this decimal with the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Comparison result, which can be any of the following:<br>**1**: The decimal is greater than *n*.<br>**-1**: The decimal is less than *n*.<br>**0**: The decimal is equal to *n*.<br>**NaN**: Either the decimal or *n* is Not a Number (NaN).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(Infinity);
let b: Decimal = new Decimal(5);
let c: number = a.comparedTo(b);
console.info("test Decimal comparedTo:" + c); // '1'

let d: number = b.comparedTo(10.5);
console.info("test Decimal comparedTo:" + d); // '-1'
```

### equals

equals(n: Value): boolean

Checks whether this decimal is equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type   | Description                                            |
| ------- | ------------------------------------------------ |
| boolean | **true**: They are equal.<br>**false**: They are not equal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0);
let b: boolean = a.equals('1e-324');
console.info("test Decimal equals:" + b); // 'false'
```

### greaterThan

greaterThan(n: Value): boolean

Checks whether this decimal is greater than the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| boolean | **true**: The decimal is greater than *n*.<br>**false**: The decimal is not greater than *n*.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0.1);
let b: boolean = a.greaterThan(new Decimal(0.3).sub(0.2)); // 'false'
console.info("test Decimal greaterThan:" + b); // 'false'
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(n: Value): boolean

Checks whether this decimal is greater than or equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type   | Description                                              |
| ------- | -------------------------------------------------- |
| boolean | **true**: The decimal is greater than or equal to *n*.<br>**false**: The decimal is not greater than or equal to *n*.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0.3).sub(0.2);
let b: boolean = a.greaterThanOrEqualTo(0.1);
console.info("test Decimal greaterThanOrEqualTo:" + b); // 'true'
```

### lessThan

lessThan(n: Value): boolean

Checks whether this decimal is less than the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| boolean | **true**: The decimal is less than *n*.<br>**false**: The decimal is not less than *n*.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0.3).sub(0.2);
let b: boolean = a.lessThan(0.1)
console.info("test Decimal lessThan:" + b); // 'false'
```

### lessThanOrEqualTo

lessThanOrEqualTo(n: Value): boolean

Checks whether this decimal is less than or equal to the specified number *n*.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                 |
| ------ | --------------- | ---- | --------------------- |
| n      | [Value](#value) | Yes  | Target number to compare.|

**Return value**

| Type   | Description                                              |
| ------- | -------------------------------------------------- |
| boolean | **true**: The decimal is less than or equal to *n*.<br>**false**: The decimal is not less than or equal to *n*.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(0.1);
let b: boolean = a.lessThanOrEqualTo(new Decimal(0.3).sub(0.2))
console.info("test Decimal lessThanOrEqualTo:" + b); // 'true'
```

### isFinite

isFinite(): boolean

Checks whether this decimal is finite.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                        |
| ------- | -------------------------------------------- |
| boolean | **true**: The decimal is finite.<br>**false**: The decimal is not finite.|

**Example**

```ts
let a: Decimal = new Decimal(1);
let b: boolean = a.isFinite();
console.info("test Decimal isFinite:" + b); // 'true'
```

### isInteger

isInteger(): boolean

Checks whether this decimal is an integer.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | **true**: The decimal is an integer.<br>**false**: The decimal is not an integer.|

**Example**

```ts
let a: Decimal = new Decimal(123.456);
let b: boolean = a.isInteger();
console.info("test Decimal isInteger:" + b); // 'false'
```

### isNaN

isNaN(): boolean

Checks whether this decimal is NaN.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                     |
| ------- | ----------------------------------------- |
| boolean | **true**: The decimal is NaN.<br>**false**: The decimal is not NaN.|

**Example**

```ts
let a: Decimal = new Decimal(NaN);
let b: boolean = a.isNaN();
console.info("test Decimal isNaN:" + b); // 'true'
```

### isNegative

isNegative(): boolean

Checks whether this decimal is negative.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | **true**: The decimal is negative.<br>**false**: The decimal is not negative.|

**Example**

```ts
let a: Decimal = new Decimal(-5);
let b: boolean = a.isNegative();
console.info("test Decimal isNegative:" + b); // 'true'

let c: Decimal = new Decimal(-0);
let d: boolean = a.isNegative();
console.info("test Decimal isNegative:" + d); // 'true'
```

### isPositive

isPositive(): boolean

Checks whether this decimal is positive.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | **true**: The decimal is positive.<br>**false**: The decimal is not positive.|

**Example**

```ts
let a: Decimal = new Decimal(5);
let b: boolean = a.isPositive();
console.info("test Decimal isPositive:" + b); // 'true'

let c: Decimal = new Decimal(0);
let d: boolean = a.isPositive();
console.info("test Decimal isPositive:" + d); // 'true'
```

### isZero

isZero(): boolean

Returns whether this decimal is zero or minus zero.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | **true**: The decimal is zero or minus zero.<br>**false**: The decimal is not zero.|

**Example**

```ts
let a: Decimal = new Decimal(0);
let b: boolean = a.isZero();
console.info("test Decimal isZero:" + b.toString()); // 'true'
```

### dividedToIntegerBy

dividedToIntegerBy(n: Value): Decimal

Returns a new **Decimal** object representing the integer part of this decimal divided by the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = new Decimal(5);
let b: Decimal = new Decimal(3);
let c: Decimal = a.dividedToIntegerBy(b);
console.info("test Decimal dividedToIntegerBy:" + c.toString()); // '1'
```

### negate

negate(): Decimal

Returns a new **Decimal** object representing the result of multiplying this decimal by negative one.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| [Decimal](#decimal) | **Decimal** object representing the negated value of the decimal.|

**Example**

```ts
let a: Decimal = new Decimal(1.8);
let b: Decimal = a.negate();
console.info("test Decimal negate:" + b.toString()); // '-1.8'
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

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toBinary();
console.info("test Decimal toBinary:" + b); // '0b100000000'
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
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toBinary(1);
console.info("test Decimal toBinary:" + b); // '0b1p+8'
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
| 10200001 | The value of 'significantDigits \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toBinary(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toBinary:" + b); // '0b1p+8'
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
let a: Decimal = new Decimal(256);
let b: string = a.toOctal();
console.info("test Decimal toOctal:" + b); // '0o400'
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
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toOctal(1);
console.info("test Decimal toOctal:" + b); // '0o1p+8'
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
| 10200001 | The value of 'significantDigits \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toOctal(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toOctal:" + b); // '0o1p+8'
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
let a: Decimal = new Decimal(256);
let b: string = a.toHexadecimal();
console.info("test Decimal toHexadecimal:" + b); // '0x100'
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
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toHexadecimal(1);
console.info("test Decimal toHexadecimal:" + b); // '0x1p+8'
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
| 10200001 | The value of 'significantDigits \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(256);
let b: string = a.toHexadecimal(1, Decimal.ROUND_HALF_UP);
console.info("test Decimal toHexadecimal:" + b); // '0x1p+8'
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
let a: Decimal = new Decimal(12.34567);
let b: Decimal = a.toDecimalPlaces();
console.info("test Decimal toDecimalPlaces:" + b.toString()); // '12.34567'
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
| 10200001 | The value of 'decimalPlaces' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(9876.54321);
let b: Decimal = a.toDecimalPlaces(3);
console.info("test Decimal toDecimalPlaces:" + b.toString()); // '9876.543'
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
| 10200001 | The value of 'decimalPlaces \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(9876.54321);
let b: Decimal = a.toDecimalPlaces(1, 0);
console.info("test Decimal toDecimalPlaces:" + b.toString()); // '9876.6'
b = a.toDecimalPlaces(1, Decimal.ROUND_DOWN) // b: '9876.5'
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
let a: Decimal = new Decimal(45.6);
let b: string = a.toExponential();
console.info("test Decimal toExponential:" + b); // '4.56e+1'
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
| 10200001 | The value of 'decimalPlaces' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(45.6);
let b: string = a.toExponential(0);
console.info("test Decimal toExponential:" + b); // '5e+1'
b = a.toExponential(1) // b: '4.6e+1'
b = a.toExponential(3) // b: '4.560e+1'
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
| 10200001 | The value of 'decimalPlaces \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(45.6);
let b = a.toExponential(1, Decimal.ROUND_DOWN)
console.info("test Decimal toExponential:" + b); // '4.5e+1'
```

### toFixed

toFixed(): string

Converts this decimal to a string expressed in decimal fixed-point mode, without rounding.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type               | Description                                            |
| ------------------- | ------------------------------------------------ |
| [Decimal](#decimal) | String expressed in decimal fixed-point mode.|

**Example**

```ts
let a: Decimal = new Decimal(3.456);
let b: string = a.toFixed();
console.info("test Decimal toFixed:" + b); // '3.456'
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
| [Decimal](#decimal) | String expressed in decimal fixed-point mode.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                     |
| -------- | --------------------------------------------- |
| 10200001 | The value of 'decimalPlaces' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(3.456);
let b: string = a.toFixed(0)
console.info("test Decimal toFixed:" + b); // '3'
b = a.toFixed(2) // b: '3.46'
b = a.toFixed(5) // b: '3.45600'
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
| [Decimal](#decimal) | String expressed in decimal fixed-point mode.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                 |
| -------- | --------------------------------------------------------- |
| 10200001 | The value of 'decimalPlaces \| rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(3.456);
let b: string = a.toFixed(2, Decimal.ROUND_DOWN);
console.info("test Decimal toFixed:" + b); // b: '3.45'
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
let a: Decimal = new Decimal(1.75);
let b: Decimal[] = a.toFraction();
console.info("test Decimal toFraction:" + b.toString()); // '7,4'
```

### toFraction

toFraction(max_denominator: Value): Decimal[]

Converts this decimal to a fraction, with the maximum denominator specified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name         | Type           | Mandatory| Description                    |
| --------------- | --------------- | ---- | ------------------------ |
| max_denominator | [Value](#value) | Yes  | Maximum denominator. This value is inclusive.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| [Decimal](#decimal)[] | Decimal array with a fixed length of 2. The two integers in the array represent the numerator and the denominator, respectively.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let pi: Decimal = new Decimal('3.14159265358')
let b = pi.toFraction() // b: '157079632679,50000000000'
b = pi.toFraction(100000) // b: '312689, 99532'
b = pi.toFraction(10000) // b: '355, 113'
b = pi.toFraction(100) // b: '311, 99'
b = pi.toFraction(10) // b: '22, 7'
b = pi.toFraction(1) // b: '3, 1'
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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 10200001 | The value of 'rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(1.39);
let b: Decimal = a.toNearest(0.25);
console.info("test Decimal toNearest:" + b.toString()); // '1.5'
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

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 10200001 | The value of 'rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(9.499)
let b = a.toNearest(0.5, Decimal.ROUND_UP) // b: '9.5'
b = a.toNearest(0.5, Decimal.ROUND_DOWN) // b: '9'
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
let a: Decimal = new Decimal(45.6);
let b: string = a.toPrecision();
console.info("test Decimal toPrecision:" + b); // '45.6'
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
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(45.6);
let b: string = a.toPrecision(1);
console.info("test Decimal toPrecision:" + b); // '5e+1'
b = a.toPrecision(5); // b: '45.600'
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
| 10200001 | The value of 'significantDigits \|  rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(45.6);
let b: string = a.toPrecision(2, Decimal.ROUND_UP) // b: '46'
b = a.toPrecision(2, Decimal.ROUND_DOWN) // b: '45'
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
let a: Decimal = new Decimal(987.654321);
let b: Decimal = a.toSignificantDigits();
console.info("test Decimal toSignificantDigits:" + b.toString()); // '987.654321'
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
| 10200001 | The value of 'significantDigits' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(987.654321);
let b: Decimal = a.toSignificantDigits(6);
console.info("test Decimal toSignificantDigits:" + b.toString()); // '987.654'
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
| 10200001 | The value of 'significantDigits \|  rounding' is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(987.654321);
let b: Decimal = a.toSignificantDigits(6, Decimal.ROUND_UP);
console.info("test Decimal toSignificantDigits:" + b.toString()); // '987.655'
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
let a: Decimal = new Decimal(456.789);
let b: number = a.toNumber();
console.info("test Decimal toNumber:" + b.toString()); // '456.789'
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
let a: Decimal = new Decimal(750000);
let b: string = a.toString();
console.info("test Decimal toString:" + b); // '750000'

Decimal.set({ toExpPos: 5 })
b = a.toString() // b:'7.5e+5'

let c: Decimal = new Decimal(0.000000123)
console.info("test Decimal toString:" + c.toString()); // '1.23e-7'

Decimal.set({ toExpNeg: -7 })
b = c.toString() // b:'1.23e-7'
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
let a: Decimal = new Decimal(-0);
let b: string = a.valueOf();
console.info("test Decimal valueOf:" + b); // '-0'
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
let a: Decimal = new Decimal(1.234);
let b: number = a.decimalPlaces();
console.info("test Decimal decimalPlaces:" + b); // '3'
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
let a: Decimal = new Decimal(1.234);
let b: number = a.precision();
console.info("test Decimal precision:" + b); // '4'
```

### precision

precision(includeZeros: boolean | number): number

Returns the number of significant digits of this decimal, with **includeZeros** specified to determine whether to count the number of trailing zeros in the integer part.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type   | Mandatory| Description                                                        |
| ------------ | ------- | ---- | ------------------------------------------------------------ |
| includeZeros | boolean | Yes  | Whether to count the number of trailing zeros in the integer part. The value **true** means to count the number of trailing zeros in the integer part, and **false** means the opposite.|

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| number | Number of significant digits.|

**Error codes**

For details about the error codes, see [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                  |
| -------- | ------------------------------------------ |
| 10200001 | The value of includeZeros is out of range. |

**Example**

```ts
let a: Decimal = new Decimal(987000);
let b: number = a.precision();
console.info("test Decimal precision:" + b); // '3'
b = a.precision(true) // b:'6'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.abs(-0.5);
console.info("test Decimal abs:" + a.toString()); // '0.5'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.floor(1.8);
console.info("test Decimal floor:" + a.toString()); // '1'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.ceil(1.8);
console.info("test Decimal ceil:" + a.toString()); // '2'
```

### trunc

static trunc(n: Value): Decimal

Returns a **Decimal** object representing the integer part truncated from the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.trunc(2.5);
console.info("test Decimal trunc:" + a.toString()); // '2'
```

### clamp

static clamp(n: Value, min: Value, max: Value): Decimal

Returns a **Decimal** object representing the value clamped to the inclusive range of **min** and **max** of the specified number *n*.

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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200001 | The value of 'min' is out of range.                          |

**Example**

```ts
let a: Decimal = Decimal.clamp(10.1, 0, 10);
console.info("test Decimal clamp:" + a.toString()); // '10'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.add(0.5, 0.5);
console.info("test Decimal add:" + a.toString()); // '1'
```

### sum

static sum(...n: Value[]): Decimal

Returns a **Decimal** object representing the sum of elements in an array.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description        |
| ------ | ----------------- | ---- | ------------ |
| n      | [Value](#value)[] | Yes  | Array of addends.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the sum.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.sum(0.5, 0.5);
console.info("test Decimal sum:" + a.toString()); // '1'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.sub(1, 0.5);
console.info("test Decimal sub:" + a.toString()); // '0.5'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.mul(1, 0.5);
console.info("test Decimal mul:" + a.toString()); // '0.5'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |


**Example**

```ts
let a: Decimal = Decimal.div(1, 0.5);
console.info("test Decimal div:" + a.toString()); // '2'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.mod(2, 1);
console.info("test Decimal mod:" + a.toString()); // '0'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.sqrt(3);
console.info("test Decimal sqrt:" + a.toString()); // '1.7320508075688772935'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.cbrt(3);
console.info("test Decimal cbrt:" + a.toString()); // '1.4422495703074083823'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.pow(3, -2);
console.info("test Decimal pow:" + a.toString()); // '0.11111111111111111111'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.exp(2);
console.info("test Decimal exp:" + a.toString()); // '7.3890560989306502272'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.log(2, 256);
console.info("test Decimal log:" + a.toString()); // '0.125'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.ln(1.23e+30);
console.info("test Decimal ln:" + a.toString()); // '69.284566959205696648'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.log2(4);
console.info("test Decimal log2:" + a.toString()); // '2'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.log10(10000);
console.info("test Decimal log10:" + a.toString()); // '4'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.cos(-0.25);
console.info("test Decimal cos:" + a.toString()); // '0.96891242171064478414'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.sin(0.75);
console.info("test Decimal sin:" + a.toString()); // '0.68163876002333416673'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.tan(0.75);
console.info("test Decimal tan:" + a.toString()); // '0.93159645994407246117'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.cosh(0.5);
console.info("test Decimal cosh:" + a.toString()); // '1.1276259652063807852'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.sinh(0.5);
console.info("test Decimal sinh:" + a.toString()); // '0.52109530549374736162'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.tanh(0.5);
console.info("test Decimal tanh:" + a.toString()); // '0.4621171572600097585'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.acos(0.5);
console.info("test Decimal acos:" + a.toString()); // '1.0471975511965977462'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.asin(0.75);
console.info("test Decimal asin:" + a.toString()); // '0.84806207898148100805'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.atan(0.75);
console.info("test Decimal atan:" + a.toString()); // '0.6435011087932843868'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.acosh(50);
console.info("test Decimal acosh:" + a.toString()); // '4.6050701709847571595'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.asinh(50);
console.info("test Decimal asinh:" + a.toString()); // '4.6052701709914238266'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.atanh(0.75);
console.info("test Decimal atanh:" + a.toString()); // '0.97295507452765665255'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200060 | Precision limit exceeded.                                    |

**Example**

```ts
let a: Decimal = Decimal.atan2(2, 3);
console.info("test Decimal atan2:" + a.toString()); // '0.58800260354756755125'
```

### hypot

static hypot(...n: Value[]): Decimal

Returns a **Decimal** object representing the Euclidean norm of elements in an array.

You can use [DecimalConfig.precision](#decimalconfig) to specify the precision and use [DecimalConfig.rounding](#decimalconfig) to specify the rounding mode.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description                |
| ------ | ----------------- | ---- | -------------------- |
| n      | [Value](#value)[] | Yes  | Target array to operate.|

**Return value**

| Type               | Description                                             |
| ------------------- | ------------------------------------------------- |
| [Decimal](#decimal) | ** Decimal** object representing the Euclidean norm of the elements.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.hypot(2, 3, 4);
console.info("test Decimal hypot:" + a.toString()); // '5.3851648071345040313'
```

### max

static max(...n: Value[]): Decimal

Returns a **Decimal** object representing the maximum value among all elements in an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type             | Mandatory| Description                |
| ------ | ----------------- | ---- | -------------------- |
| n      | [Value](#value)[] | Yes  | Target array to operate.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the maximum value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.max(2, 3, 4);
console.info("test Decimal max:" + a.toString()); // '4'
```

### min

static min(...n: Value[]): Decimal

Returns a **Decimal** object representing the minimum value among all elements in an array.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type           | Mandatory| Description                |
| ------ | --------------- | ---- | -------------------- |
| n      | [Value](#value) | Yes  | Target array to operate.|

**Return value**

| Type               | Description                                     |
| ------------------- | ----------------------------------------- |
| [Decimal](#decimal) | **Decimal** object representing the minimum value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: Decimal = Decimal.min(2, 3, 4);
console.info("test Decimal min:" + a.toString()); // '2'
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
let a: Decimal = Decimal.random();
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200061 | Crypto unavailable.                                          |

**Example**

```ts
let a: Decimal = Decimal.random(20);
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let a: number = Decimal.sign(2);
console.info("test Decimal sign:" + a); // '1'
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
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |

**Example**

```ts
let x = 3.3333333333333;
let a = Decimal.round(x);
console.info("test Decimal round:" + a.toString()); // '3'
```

### set

static set(object: DecimalConfig):void

Sets the properties for this **Decimal** object. The properties set by calling this API take effect globally.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                           | Mandatory| Description                |
| ------ | ------------------------------- | ---- | -------------------- |
| object | [DecimalConfig](#decimalconfig) | Yes  | Properties to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Incorrect parameter types;<br>2. Parameter verification failed. |
| 10200001 | The value of 'DecimalConfig.properties' is out of range.     |
| 10200061 | Crypto unavailable.                                          |

**Example 1**

```ts
let a : Decimal = new Decimal(1.2345678901234567);
Decimal.set({
    precision: 5,
    rounding: 4,
    toExpNeg: -7,
    toExpPos: 7,
    maxE: 9e15,
    minE: -9e15,
    modulo: 1,
    crypto: false
})
let b : Decimal = a.add(0.5);
console.info("test Decimal set:" + b.toString()); // "1.7346"
// Set all properties to their default values.
Decimal.set({ defaults: true })
let c : Decimal = a.add(0.5);
console.info("test Decimal set:" + c.toString()); // "1.7345678901234567"
// Set the maximum number of significant digits to 10 and retain the default values for other properties.
Decimal.set({ precision: 10, defaults: true })
let d : Decimal = a.add(0.5);
console.info("test Decimal set:" + d.toString()); // "1.73456789"

// Usage of toExpNeg and toExpPos:
Decimal.set({ toExpNeg: -7 })
let x0 : Decimal = new Decimal(0.00000123) // '0.00000123'
let x1 : Decimal = new Decimal(0.000000123) // '1.23e-7'

Decimal.set({ toExpPos: 2 })
let y0 : Decimal = new Decimal(12.3) // '12.3'
let y1 : Decimal = new Decimal(123) // '1.23e+2'

// All data is expressed in scientific notation.
Decimal.set({ toExpPos: 0 })

// Usage of minE and maxE:
Decimal.set({ minE: -500 })
let a0 : Decimal = new Decimal('1e-500') // '1e-500'
let a1 : Decimal = new Decimal('9.9e-501') // '0'

Decimal.set({ minE: -3 })
let b0 : Decimal = new Decimal(0.001) // '0.001'
let b1 : Decimal = new Decimal(0.0001) // '0'

Decimal.set({ maxE: 500 })
let c0 : Decimal = new Decimal('9.999e500') // '9.999e+500'
let c1 : Decimal = new Decimal('1e501') // 'Infinity'

Decimal.set({ maxE: 4 })
let d0 : Decimal = new Decimal(99999) // '9.9999e+4'
let d1 : Decimal = new Decimal(100000) // 'Infinity'
```

**Example 2**

```ts
// /entry/src/main/ets/pages/test.ets
export function test(){
  let a : Decimal = new Decimal(1.2345678901234567);
  Decimal.set({
    precision: 5,
    rounding: 0,
    toExpNeg: -7,
    toExpPos: 7,
    maxE: 9e15,
    minE: -9e15,
    modulo: 1,
    crypto: false
  })
  let b : Decimal = a.add(0.5);
  console.info("test Decimal set:" + b.toString()); // "1.7346"
}
```

```ts
// /entry/src/main/ets/pages/Index.ets
import {test} from './test'

let a : Decimal = new Decimal(1.2345678901234567);
Decimal.set({
  precision: 6,
  rounding: 1,
  toExpNeg: -7,
  toExpPos: 7,
  maxE: 9e15,
  minE: -9e15,
  modulo: 1,
  crypto: false
})
let b : Decimal = a.add(0.5);
console.info("test Decimal set:" + b.toString()); // "1.73456"
test();
b = b.add(0);                                     // "1.7346"
console.info("test Decimal set:" + b.toString()); // "1.7346"
```
