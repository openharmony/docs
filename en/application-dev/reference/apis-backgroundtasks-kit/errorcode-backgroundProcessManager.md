# backgroundProcessManager Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 31800002 Invalid Parameter

**Error Message**

Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. PowerSaveMode status is out of range.

**Description**

Invalid parameter.

**Possible Causes**

1. The number of parameters is incorrect.
2. The parameter type is incorrect.
3. The parameter value is out of range.

**Solution**

Make sure all the mandatory parameters are passed in and the parameter types are valid. If parameter verification fails, read the parameter specifications and locate the fault based on the possible causes.

## 31800003 Setting Overriden by Task Manager

**Error Message**

Setup error, This setting is overridden by setting in Task Manager.

**Description**

The setting fails because it has already been configured by the Task Manager.

**Possible Causes**

The setting has been configured by the Task Manager. The priority of the parameters set by the Task Manager is higher than that of the application.

**Solution**

Use the Task Manager to set the parameters.

## 31800004 Setting Failure Due to System Scheduling

**Error Message**

The setting failed due to system scheduling reasons.

**Description**

The setting fails due to system scheduling.

**Possible Causes**

The system scheduling is performed.

**Solution**

Perform the setting again.
