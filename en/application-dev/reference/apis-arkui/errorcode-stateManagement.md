# State Management Error Codes
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 130000 Invalid Target Object for addMonitor/clearMonitor

**Error Message**

The target is not a custom component instance or V2 class instance.

**Description**

This error code is reported when the target object parameter for [addMonitor](./js-apis-stateManagement.md#addmonitor20) or [clearMonitor](./js-apis-stateManagement.md#clearmonitor20) is invalid.

**Possible Causes**

The target object does not meet the following requirements:
- A class decorated with [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md) (must have at least one variable decorated with [\@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md))
- An instance of a custom component decorated with [\@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2)

**Solution**

Ensure that the target object for **addMonitor** or **clearMonitor** is valid. For details, see [addMonitor and clearMonitor APIs: Dynamically Adding or Removing Listeners](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#constraints).

## 130001 Invalid Path for addMonitor/clearMonitor

**Error Message**

The path is invalid.

**Description**

This error code is reported when the path parameter for **addMonitor** or **clearMonitor** is invalid.

**Possible Causes**

The path is not a string or not an array type.

**Solution**

Ensure that the path for **addMonitor** or **clearMonitor** is valid. For details, see [addMonitor and clearMonitor APIs: Dynamically Adding or Removing Listeners](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#constraints).

## 130002 Invalid Callback for addMonitor/clearMonitor

**Error Message**

addMonitor/clearMonitor failed because the monitorFunc is illegal, monitorFunc must be function or but cannot be an anonymous function.

**Description**

This error code is reported when the callback parameter for **addMonitor** or **clearMonitor** is invalid.

**Possible Causes**

The callback is not of the function type or is of an anonymous function type.

**Solution**

Ensure that the callback for **addMonitor** or **clearMonitor** is valid. For details, see [addMonitor and clearMonitor APIs: Dynamically Adding or Removing Listeners](../../ui/state-management/arkts-new-addMonitor-clearMonitor.md#constraints).

## 140001 Invalid Invocation of applySync, flushUpdates, or flushUIUpdates

**Error Message**

The function is not allowed to be called in @Computed.

**Description**

This error code is reported when the **applySync**, **flushUpdates**, or **flushUIUpdates** API is called in a getter method decorated with @Computed.

**Possible Causes**

The **applySync**, **flushUpdates**, or **flushUIUpdates** API is called in a getter method decorated with @Computed.

**Solution**

Ensure that the **applySync**, **flushUpdates**, and **flushUIUpdates** APIs are not called within getter methods decorated with @Computed.

## 140002 Invalid Invocation of flushUpdates or flushUIUpdates

**Error Message**

The function is not allowed to be called in @Monitor.

**Description**

This error code is reported when the **flushUpdates** or **flushUIUpdates** API is called in an @Monitor callback method.

**Possible Causes**

The **flushUpdates** or **flushUIUpdates** API is called in an @Monitor callback method.

**Solution**

Ensure that the **flushUpdates** and **flushUIUpdates** APIs are not called in @Monitor callback methods.

## 140103 AppStorageV2 and PersistenceV2 Use Unsupported Data Types

**Error Message**

Not supported type! The type should have function constructor signature.

**Description**

When [connect](./js-apis-stateManagement.md#connect) of [AppStorageV2](./js-apis-stateManagement.md#appstoragev2) or [connect](./js-apis-stateManagement.md#connect) and [globalConnect](./js-apis-stateManagement.md#globalconnect18) of [PersistenceV2](./js-apis-stateManagement.md#persistencev2) are used, the **type** parameter is invalid.

**Possible Causes**

When **connect** of **AppStorageV2** or **connect** and **globalConnect** of **PersistenceV2** are used, the **type** parameter is not of the [TypeConstructorWithArgs\<T\>](./js-apis-stateManagement.md#typeconstructorwithargst) type.

**Solution**

Ensure that the **type** parameter passed by **connect** or **globalConnect** is of the **TypeConstructorWithArgs\<T\>** type. For details about the supported types, see the [PersistenceV2 usage constraints](../../ui/state-management/arkts-new-persistencev2.md#constraints) and [AppStorageV2 usage constraints](../../ui/state-management/arkts-new-appstoragev2.md#constraints).

## 140104 AppStorageV2 and PersistenceV2 Use the Invalid Default Value to Create a Function

**Error Message**

The default creator should be function when first connect.

**Description**

When [connect](./js-apis-stateManagement.md#connect) of [AppStorageV2](./js-apis-stateManagement.md#appstoragev2) or [connect](./js-apis-stateManagement.md#connect) and [globalConnect](./js-apis-stateManagement.md#globalconnect18) of [PersistenceV2](./js-apis-stateManagement.md#persistencev2) are used, the default data constructor specified by **defaultCreator** is not [StorageDefaultCreator\<T\>](./js-apis-stateManagement.md#storagedefaultcreatort).

**Possible Causes**

**defaultCreator** is not of the **StorageDefaultCreator\<T\>** type.

**Solution**

Ensure that **defaultCreator** passed by **connect** or **globalConnect** is of the **StorageDefaultCreator\<T\>** type. The following uses **globalConnect** as an example. For details, see [globalConnect](./js-apis-stateManagement.md#globalconnect18).

## 140105 PersistenceV2 Mixes connect and globalConnect That Use the Same Key

**Error Message**

ERROR, Duplicate key used when connect

**Description**

This error code is reported when [connect](./js-apis-stateManagement.md#connect) and [globalConnect](./js-apis-stateManagement.md#globalconnect18) use the same key.

**Possible Causes**

**connect** and **globalConnect** use the same key.

**Solution**

You are not advised to use **connect** and **globalConnect** together. If you need to use them together, ensure that the two APIs do not use the same key. For details, see the [PersistenceV2 usage constraints](../../ui/state-management/arkts-new-persistencev2.md#constraints).

## 140106 Using PersistenceV2 to Store Data at an Unsupported Encryption Level

**Error Message**

AreaMode Value Error! value range can only in EL1-EL5

**Description**

This error code is reported when the encryption level set for [globalConnect](./js-apis-stateManagement.md#globalconnect18) of [PersistenceV2](./js-apis-stateManagement.md#persistencev2) to store data is not within the range of EL1 to EL5.

**Possible Causes**

The value of the [areaMode](./js-apis-stateManagement.md#connectoptionst18) attribute of [ConnectOptions](./js-apis-stateManagement.md#connectoptionst18) of **globalConnect** is not within the range of EL1 to EL5.

**Solution**

Set the encryption level range to EL1 to EL5. For details, see [Using globalConnect to Store Data](../../ui/state-management/arkts-new-persistencev2.md#using-globalconnect-to-store-data).

## 140107 Data Types of AppStorageV2 and PersistenceV2 Do Not Match

**Error Message**

The type of target mismatches the type of source.

**Description**

This error code is reported when [connect](./js-apis-stateManagement.md#connect) of [AppStorageV2](./js-apis-stateManagement.md#appstoragev2) or [connect](./js-apis-stateManagement.md#connect) and [globalConnect](./js-apis-stateManagement.md#globalconnect18) of [PersistenceV2](./js-apis-stateManagement.md#persistencev2) are used.

**Possible Causes**

- The type of the **type** parameter is inconsistent with the return type of **defaultCreator**.
- The persistent data structure is modified. As a result, when the data is read from the disk to the memory again, the type does not match. In this case, only an error code is reported in the log, and no runtime exception is thrown.

**Solution**

- Ensure that the type of the **type** parameter is consistent with the return type of **defaultCreator**.
- Ensure that the data type remains unchanged before and after data persistence. If the type needs to be changed, you need to manually uninstall the application, clear the persistent data of the current application, and install the application again.

## 140108 Type Parameter Is Missing in PersistenceV2

**Error Message**

Miss @Type.

**Description**

The [\@Type](../../ui/state-management/arkts-new-type.md) decorator is missing when [globalConnect](./js-apis-stateManagement.md#globalconnect18) of [PersistenceV2](./js-apis-stateManagement.md#persistencev2) is used.

**Possible Causes**

When the **globalConnect** API is used to persist data, the \@Type decorator is missing in the data type. This error code is reported in the log and no runtime exception is thrown.

**Solution**

Ensure that the \@Type decorator is used to decorate the class name when the **globalConnect** API is used to persist complex types of data.

## 140109 @Builder Triggers Invalid Parameter Settings

**Error Message**

@Builder: Invalid attempt to set(write to) parameter error!

**Description**

This error code is reported when the input parameters are modified in the function decorated by [\@Builder](../../ui/state-management/arkts-builder.md).

**Possible Causes**

The input parameters are modified in the function decorated by \@Builder. For details, see the [@Builder constraints](../../ui/state-management/arkts-builder.md#constraints).

**Solution**

Do not modify the input parameters in the function decorated by \@Builder. You can use [MutableBinding](./js-apis-stateManagement.md#mutablebindingt20) instead. For details, see [Modifying the Input Parameters in the Function Decorated by @Builder](../../ui/state-management/arkts-builder.md#changing-the-input-parameters-in-the-builder-decorated-function).

## 140110 Using Non-\@Track Decorated Properties in the UI Causes Errors

**Error Message**

Illegal usage of not @Track'ed property on UI!

**Description**

If a property in a class is decorated by [\@Track](../../ui/state-management/arkts-track.md), do not use the class's properties that are not decorated by @Track in the UI.

**Possible Causes**

Bind the properties that are not decorated by \@Track in the class decorated by \@Track to the UI. For details, see the [@Track constraints](../../ui/state-management/arkts-track.md#constraints).

**Solution**

Add the \@Track decorator to the properties that report errors. For details, see [Improperly Using Non-@Track Decorated Properties Causes Errors](../../ui/state-management/arkts-track.md#improperly-using-non-track-decorated-properties-causes-errors).

## 140112 @Consume Does Not Have the Corresponding @Provide

**Error Message**

@Consume missing @Provide property with name or default value. Fail to resolve @Consume.

**Description**

[\@Consume](../../ui/state-management/arkts-provide-and-consume.md) fails to be initialized because @Consume does not find the matching [@Provide](../../ui/state-management/arkts-provide-and-consume.md) data source, and the default value of @Consume is not provided.

**Possible Causes**

The possible causes why @Consume fails to find @Provide are as follows:
1. The parent component of the component where @Consume is located does not define the @Provide with the same key, and @Consume does not have the default value. As a result, @Consume fails to be initialized.
2. When @Consume searches upwards for the component where @Provide is defined, the parent component or ancestor node of the component has been destroyed. As a result, @Consume fails to find the @Provide.

**Solution**

1. Ensure that when @Consume is initialized, the parent component of the component where @Consume is located has the @Provide variable with the same key, or the default value is set. For details, see the [@Consume constraints](../../ui/state-management/arkts-provide-and-consume.md#constraints)
2. Ensure that when the component where @Consume is located is created, the lifecycle of its parent component and ancestor node does not end, that is, [aboutToDisappear](./arkui-ts/ts-custom-component-lifecycle.md#abouttodisappear) is not called.

## 140113 Toolchain Version Is Too Early When @ComponentV2 Custom Components Are Reused

**Error Message**

Old toolchain detected. Please upgrade to the latest.

**Description**

Since API version 23, [@ComponentV2](../../ui/state-management/arkts-create-custom-components.md#componentv2) (in the child component) can be created in [@Reusable](../../ui/state-management/arkts-reusable.md) (in the parent component). However, you need to use the SDK of API version 18 or later. For details, see the [@ReusableV2 usage constraints](../../ui/state-management/arkts-new-reusableV2.md#constraints).

**Possible Causes**

Since API version 18, mixed usage of @Reusable (in the parent component) and @ComponentV2 (in the child component) is supported. If you use API version 18 or later, but does not use the SDK of API version 18 or later for compilation, an error is reported during running, indicating that the SDK version is too early.

**Solution**

Use the SDK of API version 18 or later to compile the application.

## 140114 @Provide Decorators with the Duplicate Key Declared

**Error Message**

duplicate @Provide property. Property with this name is provided by one of the ancestor Views already.

**Description**

This error code is reported when the @Provide decorators with the duplicate key declared exist in the same component, parent component, or ancestor node. For details, see the [@Provide constraints](../../ui/state-management/arkts-provide-and-consume.md#constraints).

**Possible Causes**

The @Provide decorators with the duplicate key declared exist in the same component, parent component, or ancestor node.

**Solution**

Ensure that the keys of the @Provide decorators are different in the same component, including its parent component and ancestor node. Alternatively, set allowOverride for the @Provide decorators with the duplicate key declared. For details, see [Support for the allowOverride Parameter](../../ui/state-management/arkts-provide-and-consume.md#support-for-the-allowoverride-parameter).

## 140115 Invalid Type of a State Variable in State Management V1

**Error Message**

Illegal variable value error with decorated variable

**Description**

This error code is reported when an unsupported type is used when you create a state variable in state management V1.

**Possible Causes**

The type decorated by the state variable decorator of state management V1 is invalid.

**Solution**

Use the type supported by the state variable of state management V1. @State is used as an example. For details, see the [@State usage rules](../../ui/state-management/arkts-state.md#usage-rules).

## 140116 Invalid Key Used by AppStorageV2

**Error Message**

The key is invalid, key must be string or TypeConstructorWithArgs type.

**Description**

This error code is reported when an invalid key is passed for using the [remove](./js-apis-stateManagement.md#remove) API of [AppStorageV2](./js-apis-stateManagement.md#appstoragev2) and [PersistenceV2](./js-apis-stateManagement.md#persistencev2) and the [save](./js-apis-stateManagement.md#save) API of **PersistenceV2**.

**Possible Causes**

The key is not of the string or [TypeConstructorWithArgs\<T\>](./js-apis-stateManagement.md#typeconstructorwithargst) type.

**Solution**

Ensure that the key passed for using the **remove** API of **AppStorageV2** and **PersistenceV2** and the **save** API of **PersistenceV2** is of the string or **TypeConstructorWithArgs\<T\>** type.
