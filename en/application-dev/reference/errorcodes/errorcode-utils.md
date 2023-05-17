# Utils Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](errorcode-universal.md).

## 10200001 Value Out of Range

**Error Message**

The value of ${param} is out of range.

**Description**

The value of a parameter passed in the API exceeds the valid range.

**Possible Causes**

The parameter value exceeds the value range.

**Solution**

Use a valid parameter value.

## 10200002 Parameter Parsing Error

**Error Message**

Invalid ${param} string.

**Description**

Failed to parse a string.

**Possible Causes**

A parameter of the string type passed in the API is a non-standard string. As a result, the string fails to be parsed.

**Solution**

Check the format of the string.

## 10200003 Failed to Initialize the Worker Instance

**Error Message**

Worker initialization failure.

**Description**

The **Worker** instance fails to be initialized when the API is called.

**Possible Causes**

1. The number of **Worker** instances to be created exceeds the upper limit.
2. The options for setting the **Worker** instance are incorrect.

**Solution**

1. Check whether the number of **Worker** instances exceeds 8. If yes, destroy idle **Worker** instances.
2. If **WorkerOptions** is set, check the parameter type and validity.

## 10200004 Worker Instance Is Not Running

**Error Message**

Worker instance is not running.

**Description**

The **Worker** instance is not running when the API is called.

**Possible Causes**

When the API is called, the **Worker** instance has been destroyed or is being destroyed.

**Solution**

Ensure that the **Worker** instance is running properly.

## 10200005 Worker Thread Does Not Support an API

**Error Message**

The invoked API is not supported in workers.

**Description**

An API that is not supported by the worker thread is called.

**Possible Causes**

The worker thread does not support the API.

**Solution**

Use a supported API.

## 10200006 Worker Transmission Information Serialization Exception

**Error Message**

Serializing an uncaught exception failed.

**Description**

An error occurs when serializing transmission information.

**Possible Causes**

The transmission information is not serializable.

**Solution**

Use transmission information that is a valid serialized object.

## 10200007 Abnormal Worker File Path

**Error Message**

The worker file path is invalid.

**Description**

The file path is invalid, and the **Worker** instance cannot be loaded.

**Possible Causes**

The worker file path is invalid. As a result, a valid **worker.abc** file cannot be generated during the build.

**Solution**

Ensure that the worker file path complies with the specifications for creating **Worker** instances. For details, see the example under [constructor<sup>9+</sup>](../apis/js-apis-worker.md#constructor9).

## 10200009 Buffer Size Error

**Error Message**

Buffer size must be a multiple of ${size}.

**Description**

The buffer size does not meet the requirement.

**Possible Causes**

The buffer size is not an integer multiple of **size**, which can be 16-bit, 32-bit, or 64-bit.

**Solution**

Use a buffer the size of which meets the requirements.
  

## 10200010 Empty Container

**Error Message**

The container is empty.

**Description**

The container to be operated is empty.

**Possible Causes**

No element is added to the container.

**Solution**

Add elements to the container first.

## 10200011 Passed this.object Is Not an Instance of the containers Class

**Error Message**

The {methodName} method cannot be bound.

**Description**

**this.object** passed in the API is not an instance of the **containers** class.

**Possible Causes**

The APIs of the **containers** class do not support **bind()**.

**Solution**

1. Check whether **bind()** is used to call the API.
2. Check whether an object that is not a container instance is assigned to the API.

## 10200012 Constructor Calling Failure

**Error Message**

The {className}'s constructor cannot be directly invoked.

**Description**

A constructor of the **containers** class is called directly to create an instance.

**Possible Causes**

The constructors of the **containers** class cannot be directly called. The keyword **new** must be used.

**Solution**

Use the keyword **new** to create an instance.

## 10200013 Read-Only Properly

**Error Message**

Cannot set property ${propertyName} of Buffer which has only a getter.

**Description**

The buffer ${propertyName} is read-only and cannot be set.

**Possible Causes**

The buffer is read-only.

**Solution**

Do not set the read-only attribute for the buffer.

## 10200014 Non-Concurrent Function Error

**Error Message**

The function is not mark as concurrent.

**Description**

The function is not marked as **concurrent**.

**Possible Causes**

**@Concurrent** is not added to the function required by the task to be executed in the task pool.

**Solution**

Check the functions required by the tasks executed by the task pool and add the **@Concurrent** decorator.

## 10200015 Failed to Cancel a Task That Does Not Exist

**Error Message**

The task is not exist when cancel it.

**Description**

This error code is reported when you attempt to cancel a task that does not exist.

**Possible Causes**

The task to cancel does not exist in the task pool.

**Solution**

Before canceling a task, ensure that the task is placed into the task pool by calling **taskpool.execute**.

## 10200016 Failed to Cancel a Task Being Executed

**Error Message**

The task is running when cancel it.

**Description**

This error code is reported when you attempt to cancel a task that is being executed.

**Possible Causes**

The task to cancel is being executed.

**Solution**

Before canceling a task, ensure that the task finishes execution.

## 10200017 Failed to Delete an Element That Does Not Exist

**Error Message**

The element does not exist in this container.

**Description**

This error code is reported when you attempt to delete an element that does not exist in the container.

**Possible Causes**

The element to delete does not exist in the container.

**Solution**

Before deleting an element, ensure that the element exists in this container.
