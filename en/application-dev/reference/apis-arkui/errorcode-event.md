# Interaction Event Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 100017 Component Does Not Support Default Event Prevention

**Error Message**

Component does not support prevent function.

**Description**

This error code is reported when an attempt is made to call **preventDefault** on a component that does not support default event prevention.

**Possible Causes**

The target component does not support the **preventDefault()** functionality.

**Solution**

N/A

## 180001 Component Is Not a Scrollable Container

**Error Message**

Component is not a scroll container.

**Description**

This error code is reported when the component is not a scrollable container.

**Possible Causes**

The component being used is not a scrollable container.

**Solution**

N/A

## 180002 Buffer Is Not Large Enough

**Error Message**

Buffer is not large enough.

**Description**

This error code is reported when the buffer size is insufficient.

**Possible Causes**

The input array length is too small.

**Solution**

Expand the size of the input array.

## 180003 Input Event Is Not a Cloned Event

**Error Message**

The input event pointer is not a cloned event pointer.

**Description**

This error code is reported when the input event is not a cloned event.

**Solution**

N/A

## 180005 No Component Hit to Respond to the Event

**Error Message**

No component hit to response to the event.

**Description**

This error code is reported when no component is found to handle the event.

**Solution**

N/A

## 180102 Gesture Recognizer Type Is Not Supported

**Error Message**

The gesture recognizer type is not supported.

**Description**

This error code is reported when the gesture recognizer type is not supported.

**Solution**

N/A
