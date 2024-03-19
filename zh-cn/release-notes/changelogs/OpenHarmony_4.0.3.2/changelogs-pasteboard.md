# 剪贴板子系统ChangeLog

OpenHarmony 4.0.3.2 版本相较于OpenHarmony 之前的版本，剪贴板子系统的API变更如下。

## cl.pasteboard.1 convertToTextV9接口变更

接口convertToTextV9由于命名规范和接口返回方式问题，名称变更为toPlainText()，返回方式改为同步方式。

**变更影响**

4.0.3.3版本之前使用接口convertToTextV9开发的应用，在4.0.3.3版本及后续版本中无法继续正常使用。

**关键的接口/组件变更**

- 涉及接口

  function convertToTextV9

- 变更前：

  ```ts
  convertToTextV9(callback: AsyncCallback<string>): void;
  convertToTextV9(): Promise<string>;
  ```

- 变更后：

  ```ts
  toPlainText(): string;
  ```
变更前：

**适配指导**

请使用toPlainText替换convertToTextV9，并注意接口返回方式。

## cl.pasteboard.2 ShareOption属性名称变更，删除了未支持的属性

ShareOption枚举命名从**大驼峰**改成了**全大写**。

**变更影响**

4.0.3.3版本之前使用InApp/LocalDevice/CrossDevice类型开发的应用，在4.0.3.3版本及后续版本中无法继续正常使用。

**关键接口/组件变更**

ShareOption<sup>9+</sup>

变更前：
| 名称 | 值 | 说明                |
| ---- |---|-------------------|
| InApp | 0 | 表示仅允许同应用内粘贴。      |
| LocalDevice | 1 | 表示允许在此设备中任何应用内粘贴。 |
| CrossDevice | 2 | 表示允许跨设备在任何应用内粘贴。  |


变更后：
| 名称 | 值 | 说明                |
| ---- |---|-------------------|
| INAPP | 0 | 表示仅允许同应用内粘贴。      |
| LOCALDEVICE | 1 | 表示允许在此设备中任何应用内粘贴。 |
| CROSSDEVICE | 2 | 表示允许跨设备在任何应用内粘贴。  |

**适配指导**

按新的语义进行适配。

## cl.pasteboard.3 getData()接口所需权限变更。

增加了访问getData接口时所需的权限。

**变更影响**

5.0.0.18及后续版本中，业务需要申请ohos.permission.READ_PASTEBOARD权限，使用安全控件访问剪贴板内容。

**关键接口/组件变更**

getData<sup>12+</sup>

- 变更前：

  ```ts
    /**
     * Gets pastedata from the system pasteboard.
     * @param { AsyncCallback<PasteData> } callback - the callback of getData.
     * @throws { BusinessError } 401 - if type of callback is not AsyncCallback<PasteData>.
     * @throws { BusinessError } 12900003 - Another copy or paste is in progress.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 11
     */
    getData(callback: AsyncCallback<PasteData>): void;

    /**
     * Gets pastedata from the system pasteboard.
     * @returns { Promise<PasteData> } the promise returned by the getData.
     * @throws { BusinessError } 12900003 - Another copy or paste is in progress.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 11
     */  
    getData(): Promise<PasteData>;

    /**
     * Gets pasteData from the system pasteboard.
     * @returns { PasteData }  a new PasteData.
     * @throws { BusinessError } 12900005 - Request time out.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 11
     */
    getDataSync(): PasteData;
  ```

- 变更后：

  ```ts
    /**
     * Gets pastedata from the system pasteboard.
     * @permission ohos.permission.READ_PASTEBOARD
     * @param { AsyncCallback<PasteData> } callback - the callback of getData.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 401 - if type of callback is not AsyncCallback<PasteData>.
     * @throws { BusinessError } 12900003 - Another copy or paste is in progress.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 12
     */
    getData(callback: AsyncCallback<PasteData>): void;
    /**
     * Gets pastedata from the system pasteboard.
     * @permission ohos.permission.READ_PASTEBOARD
     * @returns { Promise<PasteData> } the promise returned by the getData.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 12900003 - Another copy or paste is in progress.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 12
     */
    getData(): Promise<PasteData>;
    /**
     * Gets pasteData from the system pasteboard.
     * @permission ohos.permission.READ_PASTEBOARD
     * @returns { PasteData }  a new PasteData.
     * @throws { BusinessError } 201 - Permission denied.
     * @throws { BusinessError } 12900005 - Request time out.
     * @syscap SystemCapability.MiscServices.Pasteboard
     * @atomicservice
     * @since 12
     */
    getDataSync(): PasteData;
  ```

**适配指导**

按新的语义进行适配。