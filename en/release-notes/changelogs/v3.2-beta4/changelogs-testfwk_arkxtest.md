# Test Subsystem ChangeLog

## cl.testfwk_arkxtest.1 On, Driver, and Component APIs Support Exception Handling

The APIs of API version 8 are deprecated and replaced by new APIs in API version 9 to capture exceptions using **try catch**.

## Change Impact

The api9-JS APIs provided by @ohos.uitest are affected. If you have used the APIs of **@ohos.uitest-api9** during test case development, adaptation is required so that the compilation can be successful in the SDK environment of the new version.

## Key API/Component Changes

- Deprecated the **By** class of API version 8 and replaced it with the **On** class in API version 9. The APIs of the **On** class support exception handling. The API names in the class remain unchanged, except that **By#key** is replaced with **On.id**.
- Deprecated the **BY** object of API version 8 and replaced it with the **ON** object in API version 9.
- Deprecated the **UiDriver** class of API version 8 and replaced it with the **Driver** class in API version 9. The APIs of the **Driver** class support exception handling, and the API names in the class remain unchanged.
- Deprecated the **UiComponent** class of API version 8 and replaced it with the **Component** class in API version 9. The APIs of the **Component** class support exception handling, and the API names in the class remain unchanged.

## Adaptation Guide

1. Replace the class names as follows:

   - `By-->On`
   - `BY-->ON`
   - `UiDriver-->Driver`
   - `UiComponent-->Component`

2. Capture the exception thrown.

   Use **try-catch** to capture exceptions thrown.<br>Example:

```typescript
import {Driver,ON,Component} from '@ohos.uitest'

try {
    let driver = Driver.create();
} catch (error) {
    // error handle; error.code indicates the error code.
}
```
