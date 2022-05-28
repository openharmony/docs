# Active Tag

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import connectedTag from '@ohos.connectedTag';
```


## connectedTag.init

init(): boolean

Initializes the active tag chip.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Return value
 | **Type** | **Description** |
 | -------- | -------- |
 | boolean | Returns **true** if the initialization is successful; returns **false** otherwise. |


## connectedTag.uninit

uninit(): boolean

Uninitializes the active tag resources.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Return value
 | **Type** | **Description** |
 | -------- | -------- |
 | boolean | Returns **true** if the operation is successful; returns **false** otherwise. |


## connectedTag.readNdefTag

readNdefTag(): Promise&lt;string&gt;

Reads the content of this active tag. This method uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Return value
 | **Type** | **Description** |
 | -------- | -------- |
 | Promise&lt;string&gt; | Promise used to return the content of the active tag. |

- Example
  ```
  import connectedTag from '@ohos.connectedTag';
  
  connectedTag.readNdefTag().then(result => {
      console.log("promise recv ndef response: " + result);
  });
  ```

## connectedTag.readNdefTag

readNdefTag(callback: AsyncCallback&lt;string&gt;): void

Reads the content of this active tag. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Parameters
 | **Name** | **Type** | **Mandatory** | **Description** |
 | -------- | -------- | -------- | -------- |
 | callback | AsyncCallback&lt;string&gt; | Yes | Callback invoked to return the active tag content obtained. |

- Example
  ```
  import connectedTag from '@ohos.connectedTag';
  
  connectedTag.readNdefTag(result => {
      console.log("callback recv ndef response: " + result);
  });
  ```

## connectedTag.writeNdefTag

writeNdefTag(data: string): Promise&lt;void&gt;

Writes data to this active tag. This method uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Parameters
 | **Name** | **Type** | **Mandatory** | **Description** |
 | -------- | -------- | -------- | -------- |
 | data | string | Yes | Data to write. The maximum length is 1024 bytes. |

- Return value
 | **Type** | **Description** |
 | -------- | -------- |
 | Promise&lt;void&gt; | Promise used to return the result. This method returns no value. |

- Example
  ```
  import connectedTag from '@ohos.connectedTag';
  
  writeNdefTag.write("010203")
      .then((value) => {
          // Data is written to the tag.
          console.log(`success to write event: ${value}`);
      }).catch((err) => {
          // Failed to write data to the tag.
          console.error(`failed to write event because ${err.code}`);
      });
  ```

## connectedTag.writeNdefTag

writeNdefTag(data: string, callback: AsyncCallback&lt;string&gt;): void

Writes data to this active tag. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Parameters
 | **Name** | **Type** | **Mandatory** | **Description** |
 | -------- | -------- | -------- | -------- |
 | data | string | Yes | Data to write. The maximum length is 1024 bytes. |
 | callback | AsyncCallback&lt;string&gt; | Yes | Callback invoked to return the operation result. |

- Example
  ```
  import connectedTag from '@ohos.connectedTag';
  
  connectedTag.writeNdefTag("010203", (err, value) => {
      if (err) {
          // Failed to write data to the tag.
          console.error(`failed to write event because ${err.code}`);
          return;
      }
  
      // Data is written to the tag.
      console.log(`success to write event: ${value}`);
  });
  ```

## connectedTag.on('notify')

on(type: "notify", callback: Callback&lt;number&gt;): void

Registers the NFC field strength state events.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Parameters
 | **Name** | **Type** | **Mandatory** | **Description** |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Event type. The value is **notify**. |
 | callback | Callback&lt;number&gt; | Yes | Callback invoked to return the field strength state. |

- Enumerates the field strength states.
 | **Value** | **Description** |
 | -------- | -------- |
 | 0 | Field off. |
 | 1 | Field on. |


## connectedTag.off('notify')

off(type: "notify", callback?: Callback&lt;number&gt;): void

Unregisters the NFC field strength state events.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

- Parameters
 | **Name** | **Type** | **Mandatory** | **Description** |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Event type. The value is **notify**. |
 | callback | Callback&lt;number&gt; | No | Callback used to return the field strength state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered. |

- Example
  ```
  import connectedTag from '@ohos.connectedTag';
  
  var NFC_RF_NOTIFY = "notify";
  
  var recvNfcRfNotifyFunc = result => {
      console.info("nfc rf receive state: " + result);
  }
  
  // Register event notification
  connectedTag.on(NFC_RF_NOTIFY, recvNfcRfNotifyFunc);
  
  // Unregister event notification
  connectedTag.off(NFC_RF_NOTIFY, recvNfcRfNotifyFunc);
  ```

## NfcRfType

Enumerates the NFC states.

 | Name | Default Value | Description |
 | -------- | -------- | -------- |
 | NFC_RF_LEAVE | 0 | Field off. |
 | NFC_RF_ENTER | 1 | Field on. |
