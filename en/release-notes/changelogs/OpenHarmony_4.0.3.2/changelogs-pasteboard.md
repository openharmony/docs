# Pasteboard Subsystem Changelog

Compared with earlier versions, OpenHarmony 4.0.3.2 has the following API changes in its pasteboard subsystem:

## cl.pasteboard.1 convertToTextV9 Changed

Renamed the **convertToTextV9** API to **toPlainText()** due to naming specifications and return mode and changed the API from asynchronous to synchronous.

**Change Impact**

Applications developed using the **convertToTextV9** API in versions earlier than OpenHarmony 4.0.3.3 cannot be used in OpenHarmony 4.0.3.3 and later versions.

**Key API/Component Changes**

- Involved APIs:

  function convertToTextV9

- Before change:

  ```ts
  convertToTextV9(callback: AsyncCallback<string>): void;
  convertToTextV9(): Promise<string>;
  ```

- After change:

  ```ts
  toPlainText(): string;
  ```
 

**Adaptation Guide**

Replace **convertToTextV9**, an asynchronous API, with **toPlainText**, a synchronous API.

## cl.pasteboard.2 Enum names of ShareOption Changed and Unsupported Properties Deleted

Changed the enum names of **ShareOption** from UpperCamelCase to all caps.

**Change Impact**

Applications developed using the **InApp/LocalDevice/CrossDevice** attributes in versions earlier than OpenHarmony 4.0.3.3 cannot be used in OpenHarmony 4.0.3.3 and later versions.

**Key API/Component Changes**

ShareOption<sup>9+</sup>

Before change:
| Name| Value| Description               |
| ---- |---|-------------------|
| InApp | 0 | Only intra-application pasting is allowed.     |
| LocalDevice | 1 | Paste is allowed in any application on the local device.|
| CrossDevice | 2 | Paste is allowed in any application across devices. |


After change:
| Name| Value| Description               |
| ---- |---|-------------------|
| INAPP | 0 | Only intra-application pasting is allowed.     |
| LOCALDEVICE | 1 | Paste is allowed in any application on the local device.|
| CROSSDEVICE | 2 | Paste is allowed in any application across devices. |

**Adaptation Guide**

Perform adaptation based on the new semantics.
