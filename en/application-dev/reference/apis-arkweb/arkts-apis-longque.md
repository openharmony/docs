# Class (Longque)

Provides the Longque JS APIs.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can use **__Longque__.version** to obtain the API version for determining features.
>

## createDelegate

```
export function createDelegate(
  underlyingObject: object,
  initObject?: object,
  propertyFilterFlags?: PropertyFilterFlags): object;
```

Creates a delegate object.


**Parameters**

| Name   | Type  | Mandatory  | Description       |
| ------ | ------ | ---- | ----------- |
| underlyingObject | object | Yes   | Underlying object to delegate.|
| initObject | object | No   | Initial delegate object.|
| propertyFilterFlags | PropertyFilterFlags | No   | Property filter.|
