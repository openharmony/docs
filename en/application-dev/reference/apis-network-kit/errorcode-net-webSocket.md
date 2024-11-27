# WebSocket Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 2302001 WebSocket URL Error

**Error Message**

Websocket url error.

**Description**

This error code is reported if the WebSocket URL is incorrect.

**Possible Causes**

The WebSocket URL is incorrect.

## 2302002 WebSocket Certificate Does Not Exist

**Error Message**

Websocket certificate file does not exist.

**Description**

The WebSocket certificate does not exist.

**Possible Causes**

The certificate path is incorrect or no certificate is configured.

## 2302003 WebSocket Connection Already Exists

**Error Message**

Websocket connection already exists.

**Description**

The WebSocket connection already exists.

**Possible Causes**

The WebSocket connection has been established.

## 2302998 Domain Access Denied

**Error Message**

It is not allowed to access this domain.

**Description**

This error code is reported if access to a certain domain is prohibited.

**Possible Causes**

An incorrect server domain name is configured for the atomic service.

**Solution**

Configure a correct server domain name for the atomic service. For details, see [Network Connection Management](https://developer.huawei.com/consumer/en/doc/atomic-guides-V5/atomic-net-connection-manager-V5).

## 2302999 Unknown WebSocket Errors

**Error Message**

Websocket other unknown error.

**Description**

This error code is reported if other unknown WebSocket errors occur.

**Possible Causes**

Other system faults occur.

**Solution**

Contact technical support.