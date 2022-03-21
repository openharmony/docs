# Combination Key


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module are system APIs and cannot be called by third-party applications.


## Modules to Import


```
import inputConsumer from '@ohos.multimodalInput.inputConsumer';
```


## inputConsumer.on

on(type: "key", keyOption: KeyOption, callback: Callback&lt;KeyOption&gt;): void

Enables listening for combination key events. When a combination key event that meets the specified conditions occurs, **keyOption** will be passed as an input parameter to **callback**.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

  **Parameters**
  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the key input event to listen for. Only **key** is supported. | 
| keyOption | [KeyOption](#keyoption) | Yes | Key option, which specifies the condition for combination key input. | 
| callback | Callback&lt;KeyOption&gt; | Yes | Callback function. When a key input event that meets the specified options occurs, **keyOption** will be passed as an input parameter to **callback**. | 

  **Example**

```
let keyOption = {preKeys: [], finalKey: 3, isFinalKeyDown: true, finalKeyDownDuration: 0}
let callback = function(keyOption) {
    console.info("preKeys: " + keyOption.preKeys, "finalKey: " + keyOption.finalKey, 
                 "isFinalKeyDown: " + keyOption.isFinalKeyDown, "finalKeyDownDuration: " + keyOption.finalKeyDownDuration)
}
inputConsumer.on('key', keyOption, callback);
```


## inputConsumer.off

off(type: "key", keyOption: KeyOption, callback: Callback&lt;KeyOption&gt;): void

Stops listening for combination key events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

  **Parameters**
  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| type | string | Yes | Type of the key input event to listen for. Only **key** is supported. | 
| keyOption | [KeyOption](#keyoption) | Yes | Key option passed to the key input event when listening starts. | 
| callback | Callback&lt;KeyOption&gt; | Yes | Callback function passed to the key input event with the key option when listening starts. | 

  **Example**

```
let keyOption = {preKeys: [], finalKey: 3, isFinalKeyDown: true, finalKeyDownDuration: 0}
let callback = function(keyOption) {
    console.info("preKeys: " + keyOption.preKeys, "finalKey: " + keyOption.finalKey, 
                 "isFinalKeyDown: " + keyOption.isFinalKeyDown, "finalKeyDownDuration: " + keyOption.finalKeyDownDuration)
}
inputConsumer.off('key', keyOption, callback);
```


## KeyOption

Defines the key options that are met when a combination key input event occurs.

  **System capability**: SystemCapability.MultimodalInput.Input.InputConsumer
  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| preKeys | Array | Yes | Array of precedent keys. This parameter can be left empty. There is no requirement on the sequence of precedent keys. | 
| finalKey | Number | Yes | Final key in the combination key. This parameter cannot be left blank. | 
| isFinalKeyDown | boolean | Yes | Indicates whether the final key is pressed or released. By default, the final key is pressed. | 
| finalKeyDownDuration | Number | Yes | Duration for pressing the final key. By default, there is no requirement on the duration. | 
