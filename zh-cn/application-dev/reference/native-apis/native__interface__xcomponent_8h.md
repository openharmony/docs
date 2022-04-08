# native_interface_xcomponent.h


## **Overview**

**Related Modules:**

[Native XComponent](_o_h___native_x_component.md)

**Description:**

Declares APIs for accessing a Native XComponent.

**Since:**
8
**Version:**
1.0

## **Summary**


### Classes

  | Classe&nbsp;Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) |  | 
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) |  | 
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | Registers&nbsp;the&nbsp;surface&nbsp;lifecycle&nbsp;and&nbsp;touch&nbsp;event&nbsp;callbacks. | 


### Macros

  | Macro&nbsp;Name&nbsp;and&nbsp;Value | Description | 
| -------- | -------- |
| **OH_NATIVE_XCOMPONENT_OBJ**&nbsp;&nbsp;&nbsp;("__NATIVE_XCOMPONENT_OBJ__") |  | 


### Typedefs

  | Typedef&nbsp;Name | Description | 
| -------- | -------- |
| [OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1) | typedef&nbsp;struct&nbsp;[OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)<br/>Provides&nbsp;an&nbsp;encapsulated&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
| [OH_NativeXComponent_Callback](_o_h___native_x_component.md#gaf629ecc5d06f0a69aea9da3511679ea5) | typedef&nbsp;struct&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)<br/>Registers&nbsp;the&nbsp;surface&nbsp;lifecycle&nbsp;and&nbsp;touch&nbsp;event&nbsp;callbacks. | 


### Enumerations

  | Enumeration&nbsp;Name | Description | 
| -------- | -------- |
| {&nbsp;[OH_NATIVEXCOMPONENT_RESULT_SUCCESS](_o_h___native_x_component.md#gga06fc87d81c62e9abb8790b6e5713c55baf2a815b270113979adea7b9440e0b80e)&nbsp;=&nbsp;0,&nbsp;[OH_NATIVEXCOMPONENT_RESULT_FAILED](_o_h___native_x_component.md#gga06fc87d81c62e9abb8790b6e5713c55bad6e4a33f3c594e267b8101bbc8ba682f)&nbsp;=&nbsp;-1,&nbsp;[OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](_o_h___native_x_component.md#gga06fc87d81c62e9abb8790b6e5713c55baa12565a3677df7c8dc60e216ed40e580)&nbsp;=&nbsp;-2&nbsp;} | Enumerates&nbsp;the&nbsp;API&nbsp;access&nbsp;states. | 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#ga0a8c68dd460d7e801e7c0ff771f09182)&nbsp;{&nbsp;&nbsp;&nbsp;[OH_NATIVEXCOMPONENT_DOWN](_o_h___native_x_component.md#gga0a8c68dd460d7e801e7c0ff771f09182a87b4dfe82e5aafd40c202484fc10dfb4)&nbsp;=&nbsp;0,&nbsp;[OH_NATIVEXCOMPONENT_UP](_o_h___native_x_component.md#gga0a8c68dd460d7e801e7c0ff771f09182ae2da3fbb127398f9a749070edf671597),&nbsp;[OH_NATIVEXCOMPONENT_MOVE](_o_h___native_x_component.md#gga0a8c68dd460d7e801e7c0ff771f09182a0b97e9e7830d0363e3617e2a7d33b378),&nbsp;[OH_NATIVEXCOMPONENT_CANCEL](_o_h___native_x_component.md#gga0a8c68dd460d7e801e7c0ff771f09182a8593a5e1053e9c9df74d6b0e8a9bbb0a),&nbsp;&nbsp;&nbsp;[OH_NATIVEXCOMPONENT_UNKNOWN](_o_h___native_x_component.md#gga0a8c68dd460d7e801e7c0ff771f09182aff39d23c1412b3b110a19df4893651d3)&nbsp;} |  | 


### Functions

  | Function | Description | 
| -------- | -------- |
| [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#ga1aa5d0ac3778b9caef35f93b54a6f677)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)&nbsp;\*component,&nbsp;char&nbsp;\*id,&nbsp;uint64_t&nbsp;\*size) | int32_t<br/>Obtains&nbsp;the&nbsp;ID&nbsp;of&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#ga8f60375298a5d9eae57d03d4c5cf5f3f)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;uint64_t&nbsp;\*width,&nbsp;uint64_t&nbsp;\*height) | int32_t<br/>Obtains&nbsp;the&nbsp;size&nbsp;of&nbsp;the&nbsp;surface&nbsp;held&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#ga3a594868e2d0f633026b7fea2f45812a)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;double&nbsp;\*x,&nbsp;double&nbsp;\*y) | int32_t<br/>Obtains&nbsp;the&nbsp;offset&nbsp;of&nbsp;the&nbsp;surface&nbsp;held&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#ga5b0e85c74dab846b5b61a5e244ee60ca)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md)&nbsp;\*touchEvent) | int32_t<br/>Obtains&nbsp;the&nbsp;touch&nbsp;event&nbsp;dispatched&nbsp;by&nbsp;the&nbsp;ArkUI&nbsp;XComponent. | 
| [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#gaf9b8b470cd51ac0e339710926bca72e3)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#ga0e676460ec145b81bdb07a97a368a5f1)&nbsp;\*component,&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)&nbsp;\*callback) | int32_t<br/>Registers&nbsp;a&nbsp;callback&nbsp;for&nbsp;this&nbsp;**OH_NativeXComponent**&nbsp;instance. | 
