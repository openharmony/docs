# ArkWeb_WebMessageAPI


## Overview

Defines a native API struct of the post message data. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [size](#size) | Size of the struct. | 
| [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr)(\* [createWebMessage](#createwebmessage) )() | Pointer to the message to create. | 
| void(\* [destroyWebMessage](#destroywebmessage) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) \*webMessage) | Pointer to the message to destroy. | 
| void(\* [setType](#settype) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype) type) | Pointer to the message type to set. | 
| [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype)(\* [getType](#gettype) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage) | Pointer to the message type to obtain. | 
| void(\* [setData](#setdata) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, void \*data, size_t dataLength) | Pointer to the data to set. | 
| void \*(\* [getData](#getdata) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, size_t \*dataLength) | Pointer to the data to obtain. | 


## Member Variable Description


### createWebMessage

```
ArkWeb_WebMessagePtr(* ArkWeb_WebMessageAPI::createWebMessage) ()
```
**Description**

Pointer to the message to create.

**Returns**

Returns the message struct.


### destroyWebMessage

```
void(* ArkWeb_WebMessageAPI::destroyWebMessage) (ArkWeb_WebMessagePtr *webMessage)
```
**Description**

Pointer to the message to destroy.

**Parameters**

| Name| Description| 
| -------- | -------- |
| webMessage | Message to destroy. | 


### getData

```
void*(* ArkWeb_WebMessageAPI::getData) (ArkWeb_WebMessagePtr webMessage, size_t *dataLength)
```
**Description**

Pointer to the data to obtain.

**Parameters**

| Name| Description| 
| -------- | -------- |
| webMessage | Pointer to the message struct. | 
| dataLength | Data length, which is an output parameter. | 

**Returns**

Returns the pointer to the data.


### getType

```
ArkWeb_WebMessageType(* ArkWeb_WebMessageAPI::getType) (ArkWeb_WebMessagePtr webMessage)
```
**Description**

Pointer to the message type to obtain.

**Parameters**

| Name| Description| 
| -------- | -------- |
| webMessage | Pointer to the message struct. | 

**Returns**

Returns the message type.


### setData

```
void(* ArkWeb_WebMessageAPI::setData) (ArkWeb_WebMessagePtr webMessage, void *data, size_t dataLength)
```
**Description**

Pointer to the data to set.

**Parameters**

| Name| Description| 
| -------- | -------- |
| webMessage | Pointer to the message struct. | 
| data | Pointer to the data. | 
| dataLength | Data length. | 


### setType

```
void(* ArkWeb_WebMessageAPI::setType) (ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)
```
**Description**

Pointer to the message type to set.

**Parameters**

| Name| Description| 
| -------- | -------- |
| webMessage | Pointer to the message struct. | 
| type | Message type. | 


### size

```
size_t ArkWeb_WebMessageAPI::size
```
**Description**

Size of the struct.
