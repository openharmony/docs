# ResourceManager_Configuration


## Overview

Enumerates device states.

**Since**: 12

**Related module**: [Resourcemanager](resourcemanager.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ResourceManager_Direction](resourcemanager.md#resourcemanager_direction) [direction](#direction) | Screen orientation. | 
| char \* [locale](#locale) | Locale, for example, zh-Hans-CN. | 
| [ResourceManager_DeviceType](resourcemanager.md#resourcemanager_devicetype) [deviceType](#devicetype) | Device type. | 
| [ScreenDensity](resourcemanager.md#screendensity) [screenDensity](#screendensity) | Screen density. | 
| [ResourceManager_ColorMode](resourcemanager.md#resourcemanager_colormode) [colorMode](#colormode) | Color mode. | 
| uint32_t [mcc](#mcc) | Mobile country code (MCC). | 
| uint32_t [mnc](#mnc) | Mobile network code (MNC). | 
| uint32_t [reserved](#reserved)  | Reserved. | 


## Member Variable Description


### colorMode

```
ResourceManager_ColorMode ResourceManager_Configuration::colorMode
```
**Description**

Defines the color mode.


### deviceType

```
ResourceManager_DeviceType ResourceManager_Configuration::deviceType
```
**Description**

Defines the device type.


### direction

```
ResourceManager_Direction ResourceManager_Configuration::direction
```
**Description**

Defines the screen orientation.


### locale

```
char* ResourceManager_Configuration::locale
```
**Description**

Defines the locale, for example, zh-Hans-CN.


### mcc

```
uint32_t ResourceManager_Configuration::mcc
```
**Description**

Defines the MCC.


### mnc

```
uint32_t ResourceManager_Configuration::mnc
```
**Description**

Defines the MNC.


### reserved

```
uint32_t ResourceManager_Configuration::reserved[20]
```
**Description**

Reserved.


### screenDensity

```
ScreenDensity ResourceManager_Configuration::screenDensity
```
**Description**

Defines the screen density.
