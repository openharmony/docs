# DFX Development

## How do I locate the fault when the application crashes?

Applicable to: OpenHarmony SDK 3.2.5.5

1. Locate the crash-related code based on the service log.

2. View the error information in the crash file, which is located at **/data/log/faultlog/faultlogger/**.

## Why cannot access controls in the UiTest test framework?

Applicable to: OpenHarmony SDK 3.2.5.5

Check whether **persist.ace.testmode.enabled** is turned on.

Run **hdc\_std shell param get persist.ace.testmode.enabled**. 

If the value is **0**, run the **hdc\_std shell param set persist.ace.testmode.enabled 1** to enable the test mode.


## Why is private displayed in logs when the format parameter type of HiLog in C++ code is %d or %s?

When format parameters such as **%d** and **%s** are directly used, the standard system uses **private** to replace the actual data for printing by default to prevent data leakage. To print the actual data, replace **%d** with **%{public}d** or replace **%s** with **%{public}s**.

## What should I do if the hilog.debug log cannot be printed?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Run **hdc_std shell hilog -b D** to turn on the debugging switch.

## Is HiLog or console recommended for log printing? How do I set the domain if HiLog is used?

Applicable to: OpenHarmony SDK 3.2.2.5

You are advised to use the [HiLog](../reference/apis/js-apis-hilog.md) for log printing. For details about how to set the **domain** parameter, see the [Development Guide](../reference/apis/js-apis-hilog.md#hilogisloggable).

## What is the maximum length of a log record when HiLog is used? Is it configurable?

Applicable to: OpenHarmony SDK 3.2.2.5

The maximum length of a log record is 1,024 characters, and it is not changeable.

## Can I separate multiple strings by spaces in the tag parameter of the HiLog API?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

No. Separating multiple strings by spaces is not allowed.

## How do I print real data if HiLog does not contain data labeled by {public}?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

Run **hdc\_std shell hilog -p off** to disable logging of data labeled by {public}.
