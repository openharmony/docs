# @ohos.file.PhotoPickerComponent (\<PhotoPicker> Component)

The \<**PhotoPicker**> component embedded in an application allows the application to access images or video files in the user directory without any permission.
The user can directly tap this component to select images or videos.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { PhotoPickerComponent, PickerController, PickerOptions, DataType } from '@ohos.file.PhotoPickerComponent'
```

## Name

The [universal attributes](../apis-arkui/arkui-ts/ts-universal-attributes-size.md) are supported.

## PhotoPickerComponent

The \<**PhotoPicker**> component embedded in an application allows the application to access images or video files in the user directory without any permission.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name                     | Type                                 | Mandatory | Decorator Description     |Description                        |
|--------------------------|---------------------------------------|-----|------------|-----------------------------|
| pickerOptions            | [PickerOptions](#pickeroptions)       | No  | - | Configuration of Picker.                |
| onSelect:(uri: string)  | void                                  | No  | - | Callback to be invoked when an image is selected by using the \<**PhotoPicker**> component. This callback returns the URI of the image selected to the application.|
| onDeselect:(uri: string)| void                                  | No  | - | Callback to be invoked when an image is deselected by using the \<**PhotoPicker**> component. This callback returns the URI of the image deselected to the application.|
| pickerController         | [PickerController](#pickercontroller) | No  | @ObjectLink | Controller used to send data to the \<**PhotoPicker**> component.|

## PickerOptions

Defines the configuration of Picker. It inherits from [BaseSelectOptions](js-apis-photoAccessHelper.md#baseselectoptions12).

 

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                    | Type   | Mandatory | Description                |
|-------------------------|---------|-----|----------------------|
| checkBoxColor           | string  | No  | Background color of the check box. The value is an 8-digit hexadecimal color code.       |
| backgroundColor         | string  | No  | Background color of the Picker grid page. The value is an 8-digit hexadecimal color code.|
| isRepeatSelectSupported | boolean | No  | Whether to support repeated selection of a single image. The value **true** means a single image can be repeatedly selected.|

## PickerController

Defines an instance used to send data to the \<**PhotoPicker**> component.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name                                  | Type| Mandatory | Description                                                         |
|---------------------------------------|------|-----|---------------------------------------------------------------|
| setData(type: DataType, data: Object) | void | No  | Instance used to send data to the \<**PhotoPicker**> component. [DataType](#datatype) specifies the type of data to be sent.|


## DataType

Enumerates the types of data sent from **PickerController** to the \<**PhotoPicker**> component.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name               | Value     | Description                                                                                                                       |
|-------------------|--------|---------------------------------------------------------------------------------------------------------------------------|
| SET_SELECTED_URIS | 1      | List of selected data to be sent. A string array needs to be passed in. The \<**PhotoPicker**> component is notified of refreshing the selection status.<br>For example, after an image is deleted from an application's page, the application calls **setData** to notify the \<**PhotoPicker**> component of the list of the remaining selected data. Then, the \<**PhotoPicker**> component refreshes the check box status.|

## Example

```ts
// xxx.ets
import { PhotoPickerComponent, PickerController, PickerOptions, DataType } from '@ohos.file.PhotoPickerComponent'
import { photoAccessHelper } from '@kit.MediaLibraryKit';

@Entry
@Component
struct PickerDemo {
  pickerOptions: PickerOptions = new PickerOptions();
  @State pickerController: PickerController = new PickerController();
  @State selectUris: Array<string> = new Array<string>();

  aboutToAppear() {
    this.pickerOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
    this.pickerOptions.maxSelectNumber = 10;
    this.pickerOptions.isSearchSupported = false;
    this.pickerOptions.isPhotoTakingSupported = false;
    // Other attributes
  }
  
  private onSelect(uri: string): void {
    // Add
    if (uri) {
      this.selectUris.push(uri);
    }
  }

  private onDeselect(uri: string): void {
    // Remove
    if (uri) {
      this.selectUris = this.selectUris.filter((item: string) => {
        return item != uri;
      })
    }
  }

  build() {
    Stack() {
      PhotoPickerComponent({
        pickerOptions: this.pickerOptions,
        onSelect:(uri: string): void => this.onSelect(uri),
        onDeselect:(uri: string): void => this.onDeselect(uri),
        pickerController: this.pickerController,
      }).height('100%').width('100%')


      // Simulate the selection bar at the bottom of the application.
      Row() {
        ForEach(this.selectUris, (uri: string) => {
          Image(uri).height('10%').width('10%').onClick(() => {
            // After the button is clicked to delete an image, pickerController sends the list of remaining selected data to the PhotoPicker component to refresh of the check box status.
            this.selectUris = this.selectUris.filter((item: string) => {
              return item != uri;
            })
            this.pickerController.setData(DataType.SET_SELECTED_URIS, this.selectUris);
          })
        }, (uri: string) => JSON.stringify(uri))
      }
    }
  }
}
