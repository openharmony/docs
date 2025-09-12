# HiLog

## Overview

HiLog provides logging functionalities. For example, you can use logging functions to output logs of the specified log type, service domain, log tag, and log level.

**System capability**: SystemCapability.HiviewDFX.HiLog

**Since**: 8
## Files

| Name| Description|
| -- | -- |
| [log.h](capi-log-h.md) | Defines the logging functionalities of the HiLog module. Before outputting logs, you must define the service domain, and log tag, use the API with the specified log type and level, and specify the privacy identifier.<br> **Service domain**: service domain of logs. You can define the value as required. Its value is a hexadecimal integer ranging from 0x0 to 0xFFFF. If the value exceeds the range, logs cannot be printed.<br> **Log tag**: a string used to identify the class, file, or service behavior.<br> **Log level**: DEBUG, INFO, WARN, ERROR, or FATAL.<br> **Parameter format**: printf format string, which starts with a % character, including a parameter type identifier and a variable parameter.<br> **Privacy identifier**: **{public}** or **{private}** added between the % character and the parameter type identifier in each parameter. **Note**: If no privacy identifier is added, the parameter is considered to be **private**.|
