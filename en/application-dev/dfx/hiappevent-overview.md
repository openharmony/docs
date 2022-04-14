# Overview of Application Event Logging

HiAppEvent provides event logging APIs for applications to log the fault, statistical, security, and user behavior events reported during running. Based on event information, you will be able to analyze the running status of your application.

## Basic Concepts

The HiAppEvent module of OpenHarmony can be used to develop application event services and provide functions related to application events, including flushing application events to a disk and querying historical application event data.

**Logging**: Logs changes caused by user operations to provide service data for development, product, and O&M analysis.

## Event Verification Result Codes

| Result Code | Cause                              | Check Rule                                                   | Processing Method                                            |
| ----------- | ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 0           | None                               | Event verification is successful.                            | Event logging is normal. No action is required.              |
| -1          | Invalid event name                 | The event name is not empty and contains a maximum of 48 characters.<br/>The event name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore (\_).<br/>The event name does not start with a digit or underscore (_). | Ignore this event and do not perform logging.                |
| -2          | Invalid event parameter type       | The event name must be a string.<br/>The event type must be a number.<br/>The key value must be an object. | Ignore this event and do not perform logging.                |
| -99         | Application event logging disabled | The application event logging function is disabled.          | Ignore this event and do not perform logging.                |
| -100        | Unknown error                      | None                                                         | Ignore this event and do not perform logging.                |
| 1           | Invalid key name                   | The key name is not empty and contains a maximum of 16 characters.<br/>The key name consists of only the following characters: digits (0 to 9), letters (a to z), and underscore (\_).<br/>The key name does not start with a digit or underscore (\_).<br/>The key name does not end with an underscore (_). | Ignore the key-value pair and continue to perform logging.   |
| 2           | Invalid key type                   | The key must be a string.                                    | Ignore the key-value pair and continue to perform logging.   |
| 3           | Invalid value type                 | The supported value types vary depending on the programming language:<br/>boolean, number, string, or Array [basic element] | Ignore the key-value pair and continue to perform logging.   |
| 4           | Value too long                     | The value can contain a maximum of 8*1024 characters.        | Ignore the key-value pair and continue to perform logging.   |
| 5           | Excess key-value pairs             | The number of key-value pairs must be less than or equal to 32. | Ignore the excess key-value pairs and continue to perform logging. |
| 6           | Excess elements in a list value    | The number of elements in a list value must be less than or equal to 100. | Truncate the list with only the first 100 elements retained, and continue to perform logging. |
| 7           | Invalid list value                 | A list value can only be a basic element.<br/>The elements in a list value must be of the same type. | Ignore the key-value pair and continue to perform logging.   |