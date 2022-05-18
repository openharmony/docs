# Native_Bundle


## **Overview**

**Description:**

Describes the Native Bundle.

**Since:**

9

**Version:**

1.0


## **Summary**


### Files

  | File&nbsp;Name | Description | 
| -------- | -------- |
| [native_interface_bundle.h](native__interface__bundle_8h.md) | Declares&nbsp;the&nbsp;**Bundle**-specific&nbsp;function,&nbsp;including&nbsp;function&nbsp;for&nbsp;obtaining&nbsp;application&nbsp;ID. | 


### Functions

  | Function | Description | 
| -------- | -------- |
| OH_NativeBundle_GetAppIdByBundleName&nbsp;(const&nbsp;char&nbsp;\*bundleName) | char&nbsp;\*<br/>Obtains&nbsp;the&nbsp;application&nbsp;ID&nbsp;based&nbsp;on&nbsp;the&nbsp;given&nbsp;bundle&nbsp;name. | 


## **Details**


## **Function**


### OH_NativeBundle_GetAppIdByBundleName()

  
```
char* OH_NativeBundle_GetAppIdByBundleName (const char * bundleName)
```

**Description:**

Obtains the application ID based on the given bundle name.

**Parameters:**

  | Name | Description | 
| -------- | -------- |
| bundleName | Indicates&nbsp;the&nbsp;bundle&nbsp;name&nbsp;of&nbsp;the&nbsp;application. | 

**Returns:**

Returns the application ID pointer if successfully obtained and needs to be freed; returns nullptr otherwise.
