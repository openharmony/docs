# File Subsystem Changelog

## cl.file.1 Change of picker PhotoViewPicker.save() Compatibility

Changed the [PhotoViewPicker.save()](../../../application-dev/reference/apis/js-apis-file-picker.md#save) interface compatibility.

**Change Impact**

For applications developed based on earlier versions, **PhotoViewPicker.save()** saves files only to the file manager directory, and these files are invisible in **Gallery**. To save a file to **Gallery**, create a media asset using a security component. For details, see [Creating a Media Asset Using a Security Component](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| picker   |   **function** PhotoViewPicker.save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt; | Interface compatibility    |
| picker   |   **function** PhotoViewPicker.save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | Interface compatibility    |
| picker   |   **function** PhotoViewPicker.save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | Interface compatibility    |

**Adaptation Guide**

**PhotoViewPicker.save()** starts **FilePicker** and saves files to a directory in the system file manager.
From OpenHarmony_4.0.11.2, **FilePicker** cannot access assets in the media library. As a result, the files in the file manager directory cannot be viewed in **Gallery**. To enable the images or videos to be viewed in **Gallery**, use [**\<SaveButton>**](../../../application-dev/reference/arkui-ts/ts-security-components-savebutton.md) to save images or videos.

**Example**

See [Creating a Media Asset Using a Security Component](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

<!--no_check-->