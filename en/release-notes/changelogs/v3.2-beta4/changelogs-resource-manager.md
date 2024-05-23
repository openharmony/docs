# Resource Manager ChangeLog

## cl.resourceManager.1 Name Change of Some Multi-Project APIs in API Version 9 of Resource Manager

The resource manager can return error codes and error information for APIs in API version 9 and later. Some multi-project APIs in API version 9 need to be adapted. The following changes are made in API version 9 and later:

Some multi-project APIs of the resource manager need to be replaced with new APIs, and the parameters remain unchanged.

**Change Impacts**

For applications developed based on earlier versions, relevant JavaScript multi-project APIs need to be replaced with new APIs.

**Key API/Component Changes**

| **Original API**                           | **New API**|
| ----------------                         | ------------ |
| getString(resource: Resource, <br>callback: AsyncCallback\<string>): void;   | getStringValue(resource: Resource, <br>callback: AsyncCallback\<string>): void;       |
| getString(resource: Resource): Promise\<string>;   | getStringValue(resource: Resource): Promise\<string>;       |
| getStringArray(resource: Resource, <br>callback: AsyncCallback\<Array\<string>>): void;    | getStringArrayValue(resource: Resource, <br>callback: AsyncCallback\<Array\<string>>): void;       |
| getStringArray(resource: Resource): Promise\<Array\<string>>;    | getStringArrayValue(resource: Resource): Promise\<Array\<string>>;       |
| getMedia(resource: Resource, <br>callback: AsyncCallback\<Uint8Array>): void;    | getMediaContent(resource: Resource, <br>callback: AsyncCallback\<Uint8Array>): void;       |
| getMedia(resource: Resource): Promise\<Uint8Array>;   | getMediaContent(resource: Resource): Promise\<Uint8Array>;       |
| getMediaBase64(resource: Resource, <br>callback: AsyncCallback\<string>): void;   | getMediaContentBase64(resource: Resource, <br>callback: AsyncCallback\<string>): void;       |
| getMediaBase64(resource: Resource): Promise\<string>;  | getMediaContentBase64(resource: Resource): Promise\<string>;       |
| getPluralString(resource: Resource, num: number, <br>callback: AsyncCallback<string>): void;   | getPluralStringValue(resource: Resource, num: number, <br>callback: AsyncCallback\<string>): void;       |
| getPluralString(resource: Resource, num: number): Promise\<string>;   | getPluralStringValue(resource: Resource, num: number): Promise\<string>;       |

**Adaptation Guide**

The following describes how to change **getMedia** to **getMediaContent** in callback mode. The promise mode is similar. You only need to change the function name, add the error code and error information, and keep other information unchanged. The sample code is as follows:

- Before the change: **getMedia(resource: Resource, callback: AsyncCallback<Uint8Array>): void;**
```ts
let resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
};
this.context.resourceManager.getMedia(resource, (error, value) => {
    if (error != null) {
      console.log("error is " + error);
    } else {
      let media = value;
    }
});
```

- After the change: **getMediaContent(resource: Resource, callback: AsyncCallback<Uint8Array>): void;**
```ts
let resource = {
    bundleName: "com.example.myapplication",
    moduleName: "entry",
    id: $r('app.media.test').id
};
try {
  this.context.resourceManager.getMediaContent(resource, (error, value) => {
      if (error != null) {
        console.log("error is " + error);
      } else {
        let media = value;
      }
  });
} catch (error) {
  console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
}
```
