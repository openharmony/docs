# @ohos.base (Public Callback Information)

The **Base** module defines the public callback types of ArkTS APIs, including the common and error callbacks.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - Since API version 12, the APIs of this module are supported in ArkTS widgets.

## Modules to Import

```
import base from '@ohos.base';
```

## Callback

Callback\<T> {

(data: T): void;

}

Defines a common callback.

You can set **data** to customize the data type of the information returned by the callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Base

| Name| Type| Mandatory| Description                      |
| ---- | ---- | ---- | -------------------------- |
| data | T    | Yes  | Common callback information.|

## ErrorCallback

ErrorCallback\<T extends Error = BusinessError> {

(err: T): void;

}

Defines a common callback that carries an error parameter.

The information returned by the callback is of the [BusinessError](#businesserror) type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Base

**Parameters**

| Name| Type| Mandatory| Description                        |
| ---- | ---- | ---- | ---------------------------- |
| err  | T    | Yes  | Common error information about the API invoking failure.|

## AsyncCallback

AsyncCallback\<T, E = void> {

(err: BusinessError\<E>, data: T): void;

}

Defines a common callback that carries an error parameter and asynchronous return value.

The error parameter is of the [BusinessError](#businesserror) type.

The type of the asynchronous return value is defined by the developer.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Base

| Name| Type                                                        | Mandatory| Description                        |
| ---- | ------------------------------------------------------------ | ---- | ---------------------------- |
| err  | [BusinessError](#businesserror) | Yes  | Common error information about the API invoking failure.|
| data | T                                                            | Yes  | Common callback information.  |

## BusinessError

BusinessError\<T = void> extends Error {

code: number;

data?: T;
}

Defines the error parameter.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Base

| Name| Type  | Mandatory| Description                                                      |
| ---- | ------ | ---- | ---------------------------------------------------------- |
| code | number | Yes  | Common error information about the API invoking failure.                            |
| data | T      | No  | Common callback information. If this parameter is left empty, no related information is returned.|
