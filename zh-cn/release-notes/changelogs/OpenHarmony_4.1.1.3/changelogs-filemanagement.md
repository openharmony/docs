# 文件子系统ChangeLog

## cl.file.1 picker PhotoViewPicker.save 接口兼容性变更

[PhotoViewPicker.save](../../../application-dev/reference/apis/js-apis-file-picker.md#save)接口兼容性变更。

**变更影响**

基于此前版本开发的应用，使用PhotoViewPicker.save接口保存文件只能保存到文管目录，文管目录下的文件在图库中并不可见。如果需要保存到图库则需要切换为使用[安全控件创建媒体资源](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)的方式。

**关键接口/组件变更**

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| picker   |   **function** PhotoViewPicker.save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt; | 接口兼容性变更     |
| picker   |   **function** PhotoViewPicker.save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | 接口兼容性变更     |
| picker   |   **function** PhotoViewPicker.save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | 接口兼容性变更     |

**适配指导**

PhotoViewPicker.save接口的具体行为是拉起FilePicker，将文件保存在系统文件管理器的特定目录中。
从OpenHarmony_4.0.11.2版本开始，文件访问框架管理的资源范围发生变化，不再支持访问媒体库管理的资源。导致与图库管理的资源隔离，无法在图库中看到。如需要在图库中看到所保存的图片、视频资源，请使用安全控件的[保存控件](../../../../zh-cn/application-dev/reference/arkui-ts/ts-security-components-savebutton.md)。

**使用安全控件创建媒体资源示例：**

示例代码详情见媒体资源使用指导中的[安全控件创建媒体资源](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)
