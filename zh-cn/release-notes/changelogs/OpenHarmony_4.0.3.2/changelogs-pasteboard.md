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