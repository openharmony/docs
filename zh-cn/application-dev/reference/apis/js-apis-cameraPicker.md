# @ohos.multimedia.camerapicker (相机选择器)

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import picker from '@ohos.multimedia.camerapicker';
```

## picker.takePhoto

takePhoto(context: Context, photoProfile: PhotoProfileForPicker): Promise\<PickerResult\>

拉起相机选择器，进入拍照模式。操作结束通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名          | 类型                                                   | 必填 | 说明                           |
| -------------- | ------------------------------------------------------ | ---- | ---------------------------- |
| context        | [BaseContext](js-apis-inner-application-baseContext.md)| 是   | 应用上下文。                   |
| photoProfile   | [PhotoProfileForPicker](#photoprofileforpicker)        | 是   | photoProfile对象。            |

**返回值：**

| 类型                                             | 说明                                                                                   |
| ----------------------------------------------- | -------------------------------------------------------------------------------------- |
| Promise\<PickerResult\>                         | 使用Promise的方式获取相机选择器的处理结果。具体返回值[PickerResult](#pickerresult)           |


**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
let context = getContext(this) as common.Context;
let photoProfile: picker.PhotoProfileForPicker = {
    cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK,
    saveUri: ''
};
let pickerResult: picker.PickerResult = {
    resultCode: -1,
    resultUri: ''
};

async function takePhoto(context: Context, photoProfile: PhotoProfileForPicker): picker.PickerResult {
  try {
    this.pickerResult = await picker.takePhoto(context, photoProfile);
    console.log(`takePhoto is called. resultCode: ${this.pickerResult.resultCode}. resultUri: ${this.pickerResult.resultUri}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The takePhoto call failed. error code: ${err.code}`);
  }
  return this.pickerResult;
}
```

## picker.recordVideo

recordVideo(context: Context, videoProfile: VideoProfileForPicker): Promise\<PickerResult\>

拉起相机选择器，进入录制模式。操作结束通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名          | 类型                                                   | 必填 | 说明                           |
| -------------- | ------------------------------------------------------ | ---- | ---------------------------- |
| context        | [BaseContext](js-apis-inner-application-baseContext.md)| 是   | 应用上下文。                   |
| videoProfile   | [VideoProfileForPicker](#videoprofileforpicker)        | 是   | videoProfile对象。            |

**返回值：**

| 类型                                             | 说明                                                                                   |
| ----------------------------------------------- | -------------------------------------------------------------------------------------- |
| Promise\<PickerResult\>                         | 使用Promise的方式获取相机选择器的处理结果。具体类型[PickerResult](#pickerresult)           |


**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
let context = getContext(this) as common.Context;
let videoProfile: picker.VideoProfileForPicker = {
    cameraPosition: camera.CameraPosition.CAMERA_POSITION_FRONT,
    saveUri: '',
    videoDuration: 0
};
let pickerResult: picker.PickerResult = {
    resultCode: -1,
    resultUri: ''
};

async function recordVideo(context: Context, videoProfile: VideoProfileForPicker): picker.PickerResult {
  try {
    this.pickerResult = await picker.recordVideo(context, videoProfile);
    console.log(`recordVideo is called. resultCode: ${this.pickerResult.resultCode}. resultUri: ${this.pickerResult.resultUri}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The recordVideo call failed. error code: ${err.code}`);
  }
  return this.pickerResult;
}
```

## PhotoProfileForPicker

相机选择器的照片信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                               | 必填   | 说明         |
| -------------- | --------------------------------- | ----- | ------------ |
| position       | [CameraPosition](js-apis-camera.md#cameraposition) | 是    | 相机的位置。   |
| saveUri        | string                            | 是    | 保存图片的uri地址。|


## VideoProfileForPicker

相机选择器的视频信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                               | 必填   | 说明         |
| -------------- | --------------------------------- | ----- | ------------ |
| position       | [CameraPosition](js-apis-camera.md#cameraposition) | 是    | 相机的位置。   |
| saveUri        | string                            | 是    | 保存视频的uri地址。|
| videoDuration  | number                            | 是    | 录制的最大时长。|


## PickerResult

相机选择器的处理结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                               | 必填   | 说明                            |
| -------------- | --------------------------------- | ----- | -------------------------------- |
| resultCode     | number                            | 是    | 处理的结果，成功返回0，失败返回-1。 |
| resultUri      | string                            | 是    | 返回的uri地址。                   |