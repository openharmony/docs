# Test Subsystem ChangeLog

## cl.testfwk_arkxtest.1 Exception Handling Support of On, Driver, and Component APIs

The original APIs in API version 8 are deprecated, and substitute APIs that support exception handling are introduced in API version 9. You must use **try catch** to capture exceptions thrown by the APIs.

## Change Impacts

This change affects the JS APIs in API version 9 provided by **@ohos.uitest**. If you have used the API of **@ohos.uitest-api9** during test case development, adaptation is required so that the compilation can be successful in the SDK environment of the new version.

## Key API/Component Changes

- The **By** class in API version 8 is deprecated and replaced by the **On** class in API version 9. The APIs of the **On** class support exception handling and retain their original name, with the exception of **By#key**, which is renamed **On.id**.
- The **BY** object in API version 8 is deprecated and replaced by the **ON** object in API version 9.
- The **UiDriver** class in API version 8 is deprecated and replaced by the **Driver** class in API version 9. The APIs of the **Driver** class support exception handling and retain their original name.
- The **UiComponent** class in API version 8 is deprecated and replaced by the **Component** class in API version 9. The APIs of the **Component** class support exception handling and retain their original name.

## Adaptation Guide

1. Adapt to the API name changes.

   You can replace the class name according to the following rules:

   - `By-->On`
   - `BY-->ON`
   - `UiDriver-->Driver`
   - `UiComponent-->Component`

2. Catch and handle exceptions.

   Use **try-catch** to catch and handle exceptions thrown by the APIs. Below is the sample code:

   ```typescript
   import {Driver,ON,Component} from '@ohos.uitest'
   
   try {
       let driver = Driver.create();
   } catch (error) {
       // error handle; error.code indicates the error code.
   }
   ```