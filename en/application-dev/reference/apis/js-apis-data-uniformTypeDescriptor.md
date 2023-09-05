# @ohos.data.uniformTypeDescriptor (Standard Data Definition)

The **uniformTypeDescriptor** module provides abstract definitions of OpenHarmony standardized data types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';
```

## UniformDataType

Enumerates the types of OpenHarmony standard data.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name                        | Value                           | Description       |
|----------------------------|------------------------------|-----------|
| TEXT                       | 'general.text'                   | Text.    |
| PLAIN_TEXT                 | 'general.plain-text'             | Plaintext.   |
| HYPERLINK                  | 'general.hyperlink'              | Hyperlink.   |
| HTML                       | 'general.html'                   | HyperText Markup Language (HTML).   |
| FILE                       | 'general.file'                   | File.    |
| IMAGE                      | 'general.image'                  | Image.    |
| VIDEO                      | 'general.video'                  | Video.    |
| AUDIO                      | 'general.audio'                  | Audio.    |
| FOLDER                     | 'general.folder'                 | Folder.   |
| OPENHARMONY_FORM           | 'openharmony.form'               | Widget.    |
| OPENHARMONY_APP_ITEM       | 'openharmony.app-item'           | Icon.    |
| OPENHARMONY_PIXEL_MAP      | 'openharmony.pixel-map'          | Pixel map. |
