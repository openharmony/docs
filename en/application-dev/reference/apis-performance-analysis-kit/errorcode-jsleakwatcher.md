# JsLeakWatcher Error Codes

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @lu-tao-->
<!--Designer: @martin-duan-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 10801001 Invalid isEnabled

**Error Message**

The parameter isEnabled is invalid.

**Description**

When the **enableLeakWatcher** function is called, the invalid parameter **isEnabled** is input.

**Possible Causes**

1. The type of **isEnabled** is incorrect.

2. Mandatory parameters are not specified.


**Solution**

Ensure that the type of **isEnabled** is correct.

## 10801002 Invalid config

**Error Message**

The parameter config is invalid.

**Description**

When the **enableLeakWatcher** function is called, the invalid parameter **config** is input.

**Possible Causes**

1. The type of **config** is incorrect.

2. Mandatory parameters are not specified.

3. Parameter verification failed. This parameter is an array of strings. The array must contain one or more of **XComponent**, **NodeContainer**, **Window**, Custom Component, and Ability.

**Solution**

Ensure that the type of **config** is correct.

## 10801003 Invalid callback

**Error Message**

The parameter callback is invalid.

**Description**

When the **enableLeakWatcher** function is called, the invalid parameter **callback** is input.

**Possible Causes**

1. The type of **callback** is incorrect.

2. Mandatory parameters are not specified.

3. Parameter verification failed.  

**Solution**

Ensure that the type of **callback** is correct. The input parameter of the **callback** function is an array of two strings.

Index **0** indicates the name of the leak list file, whose name extension is **.jsleaklist**. Index **1** indicates the name of the VM memory snapshot file, whose name extension is **.rawheap**.
