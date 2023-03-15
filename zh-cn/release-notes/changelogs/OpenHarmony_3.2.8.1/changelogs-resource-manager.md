# 资源管理changeLog

## cl.resourceManager.1  资源API9部分多工程接口命名变更

资源管理从API9开始提供接口的错误码和错误信息返回，涉及API9提供的部分多工程接口需要适配。从API9开始作以下变更：

资源API部分多工程接口需要用新的接口替换，参数不变。

**变更影响**

基于此前版本开发的应用，涉及下面多工程接口的JS接口需要替换为新的接口。

**关键接口/组件变更**

| **涉及接口**                            | **对应替换接口** |
| ----------------                         | ------------ |
| getString(resource: Resource, </br>callback: AsyncCallback\<string>): void;   | getStringValue(resource: Resource, </br>callback: AsyncCallback\<string>): void;       |
| getString(resource: Resource): Promise\<string>;   | getStringValue(resource: Resource): Promise\<string>;       |
| getStringArray(resource: Resource, </br>callback: AsyncCallback\<Array\<string>>): void;    | getStringArrayValue(resource: Resource, </br>callback: AsyncCallback\<Array\<string>>): void;       |
| getStringArray(resource: Resource): Promise\<Array\<string>>;    | getStringArrayValue(resource: Resource): Promise\<Array\<string>>;       |
| getMedia(resource: Resource, </br>callback: AsyncCallback\<Uint8Array>): void;    | getMediaContent(resource: Resource, </br>callback: AsyncCallback\<Uint8Array>): void;       |
| getMedia(resource: Resource): Promise\<Uint8Array>;   | getMediaContent(resource: Resource): Promise\<Uint8Array>;       |
| getMediaBase64(resource: Resource, </br>callback: AsyncCallback\<string>): void;   | getMediaContentBase64(resource: Resource, </br>callback: AsyncCallback\<string>): void;       |
| getMediaBase64(resource: Resource): Promise\<string>;  | getMediaContentBase64(resource: Resource): Promise\<string>;       |
| getPluralString(resource: Resource, num: number, </br>callback: AsyncCallback<string>): void;   | getPluralStringValue(resource: Resource, num: number, </br>callback: AsyncCallback\<string>): void;       |
| getPluralString(resource: Resource, num: number): Promise\<string>;   | getPluralStringValue(resource: Resource, num: number): Promise\<string>;       |

**适配指导**

以getMedia修改为getMediaContent的callback调用为例，其promise方式类似，只需修改函数名，且增加错误码和错误信息返回，其它不变。示例代码如下：

- 变更前：getMedia(resource: Resource, callback: AsyncCallback<Uint8Array>): void;
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

- 变更后：getMediaContent(resource: Resource, callback: AsyncCallback<Uint8Array>): void;
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
