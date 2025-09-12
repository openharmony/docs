# Application Event Logging Error Codes

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @liujiaxing2024-->
<!--SE: @junjie_shi-->
<!--TSE: @gcw_KuLfPSbe-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 11100001 Application Event Logging Disabled

**Error Message**

Function disabled. Possible caused by the param disable in ConfigOption is true.

**Description**

- The **write** API is called to perform application event logging, but the system ignores related events because the logging function is disabled.
- The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the logging function is disabled.

**Possible Causes**

The application event logging function is disabled.

**Solution**

Invoke the **configure** API to enable the application event logging function.

   ```ts
   import { hiAppEvent } from '@kit.PerformanceAnalysisKit';

   hiAppEvent.configure({
       disable: false
   });
   ```

## 11101001 Invalid Event Domain Name
**Error Message**

Invalid event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid.

**Description**

- The **write** API is called to perform application event logging, but the system ignores related events because the input event domain name is invalid.
- The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the input event domain name is invalid.

**Possible Causes**

The specified event domain name does not comply with the following rules:

- The event domain name contains only digits, letters, and underscores (\_).
- The event domain name starts with a letter and does not end with an underscore (\_).
- The event domain name is not empty and contains a maximum of 32 characters.

**Solution**

Specify a valid event domain name.

## 11101002 Invalid Event Name

**Error Message**

Invalid event name. Possible causes: 1. Contain invalid characters; 2. Length is invalid.

**Description**

- The **write** API is called to perform application event logging, but the system ignores related events because the input event name is invalid.
- The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the input event name is invalid.

**Possible Causes**

The specified event name does not comply with the following rules:

- The event name contains only the dollar sign ($), digits, letters, and underscores (_).
- The event name must start with a letter or dollar sign ($) and end with a digit or letter.
- The event name is not empty and contains a maximum of 48 characters.

**Solution**

Specify a valid event name.

## 11101003 Invalid Number of Event Parameters

**Error Message**

Invalid number of event parameters. Possible caused by the number of parameters is over 32.

**Description**

This error code is reported if the **write** API is called to perform application event logging but the system discards extra event parameters because the number of input event parameters exceeds the limit.

**Possible Causes**

The number of input event parameters exceeds 32.

**Solution**

Specify a valid number of event parameters.

## 11101004 Invalid Event Parameter String Length

**Error Message**

Invalid string length of the event parameter.

**Description**

- The **write** API is called to perform application event logging, but the system ignores related event parameters because the value of the input event parameter is excessively long.
- The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the input event parameter value is invalid.

**Possible Causes**

- The length of the string of the event parameter value passed by the **write** API exceeds 8 x 1024 characters.
- The length of the custom event parameter value passed by the **setEventParam** API exceeds 1024 characters.

**Solution**

Specify an event parameter value with a valid length.

## 11101005 Invalid Event Parameter Name

**Error Message**

Invalid event parameter name. Possible causes: 1. Contain invalid characters; 2. Length is invalid.

**Description**

- The **write** API is called to perform application event logging but the system ignores related event parameters because the input event parameter name is invalid.
- The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the input event parameter name is invalid.

**Possible Causes**

The specified event parameter name does not comply with the following rules:

- The event parameter name contains only the dollar sign ($), digits, letters, and underscores (_).
- The event parameter name must start with a letter or dollar sign ($) and end with a digit or letter.
- The event parameter name is not empty and contains a maximum of 32 characters.

**Solution**

Specify a valid event parameter name.

## 11101006 Invalid Array Length of Event Parameter Values

**Error Message**

Invalid array length of the event parameter.

**Description**

This error code is reported if the **write** API is called to perform application event logging but the system discards extra array elements because the array of the event parameter value is excessively long.

**Possible Causes**

The array length of the event parameter value exceeds 100.

**Solution**

Specify a valid array length for the event parameter value.

## 11101007 Invalid Number of Custom Event Parameters

**Error Message**

The number of parameter keys exceeds the limit.

**Description**

The **setEventParam** API is called to set custom event parameters, but the system ignores the calling because the number of event parameters is invalid.

**Possible Causes**

The number of custom event parameters passed exceeds 64.

**Solution**

Specify a valid number of custom event parameters.

## 11102001 Invalid Watcher Name

**Error Message**

Invalid watcher name. Possible causes: 1. Contain invalid characters; 2. Length is invalid.

**Description**

This error code is reported if the **addWatcher** API is called to subscribe to application events but the system ignores the subscription because the specified watcher name is invalid.

**Possible Causes**

The specified watcher name does not comply with the following rules:

- The watcher name can contain only digits, letters, and underscores (\_).
- The watcher name starts with a letter and does not end with an underscore (\_).
- The watcher name is not empty and contains a maximum of 32 characters.

**Solution**

Specify a valid watcher name.

## 11102002 Invalid Filtering Event Domain Name

**Error Message**

Invalid filtering event domain. Possible causes: 1. Contain invalid characters; 2. Length is invalid.

**Description**

This error code is reported if the **addWatcher** API is called to subscribe to application events but the system ignores the subscription because the specified filtering event domain name is invalid.

**Possible Causes**

The specified filtering event domain name does not comply with the following rules:

- The event domain name contains only digits, letters, and underscores (\_).
- The event domain name starts with a letter and does not end with an underscore (\_).
- The event domain name is not empty and contains a maximum of 32 characters.

**Solution**

Specify a valid filtering event domain name.

## 11102003 Invalid Event Number

**Error Message**

Invalid row value. Possible caused by the row value is less than zero.

**Description**

This error code is reported if the **addWatcher** API is called to subscribe to application events but the system ignores the subscription because an invalid event number is passed in the callback trigger condition.

**Possible Causes**

The event number passed in the input callback triggering condition is a negative number.

**Solution**

Specify a valid event number.

## 11102004 Invalid Event Size

**Error Message**

Invalid size value. Possible caused by the size value is less than zero.

**Description**

This error code is reported if the **addWatcher** API is called to subscribe to application events but the system ignores the subscription because an invalid event size is passed in the callback trigger condition.

**Possible Causes**

The event size passed in the input callback triggering condition is a negative number.

**Solution**

Specify a valid event size.

## 11102005 Invalid Timeout Value

**Error Message**

Invalid timeout value. Possible caused by the timeout value is less than zero.

**Description**

This error code is reported if the **addWatcher** API is called to subscribe to application events but the system ignores the subscription because an invalid timeout value is passed in the callback trigger condition.

**Possible Causes**

The timeout value passed in the input callback triggering condition is a negative number.

**Solution**

Specify a valid timeout value.

## 11103001 Invalid Maximum Storage Quota

**Error Message**

Invalid max storage quota value. Possible caused by incorrectly formatted.

**Description**

This error code is reported if the **configure** API is called to subscribe to application events but the system ignores the setting because the specified maximum storage quota is invalid.

**Possible Causes**

The maximum storage quota does not meet the following rules:

- The quota value consists of only digits and a unit (including b|k|kb|m|mb|g|gb|t|tb, which are case-insensitive).
- The quota value must start with a digit. You can determine whether to pass the unit. If the unit is left empty, **b** (that is, byte) is used by default.

**Solution**

Specify a valid maximum storage quota.

## 11104001 Invalid Event Package Size

**Error Message**

Invalid size value. Possible caused by the size value is less than or equal to zero.

**Description**

This error code is reported if the **setSize** API is called to set the threshold of the event package size but the system ignores the setting because the specified event package size is invalid.

**Possible Causes**

The specified event package size is a negative number.

**Solution**

Specify a valid event package size.

## 11105001 Invalid Parameter Value

**Error Message**

Invalid parameter value. Possible causes: 1. Incorrect parameter length; 2. Incorrect parameter format.

**Description**

When the **hiAppEvent** API is called to set the input parameter, the system ignores the setting because the input parameter value is invalid.

**Possible Causes**

- The length of the input parameter does not meet the requirements.
- The format of the input parameter does not meet the specifications.

**Solution**

Input a parameter value that meets the specifications.
