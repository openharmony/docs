# multimedia子系统变更说明

## cl.multimedia.1 Image.ImageSource.DecodingOptionsForPicture接口的desiredAuxiliaryPictures属性系统能力变更

**访问级别**

公开接口

**变更原因**

接口DecodingOptionsForPicture与属性desiredAuxiliaryPictures归属的系统能力不一致，会影响对接口支持系统能力情况的判断，需要将desiredAuxiliaryPictures的SystemCapability中的SystemCapability.Multimedia.Image.Core改为SystemCapability.Multimedia.Image.ImageSource。

**变更影响**

此变更为不兼容变更。
对接口中属性的SystemCapability进行调整，对接口本身的使用方式无影响。

变更前：

DecodingOptionsForPicture接口的系统能力要求为“SystemCapability.Multimedia.Image.Core”。

变更后：

DecodingOptionsForPicture接口的系统能力要求为“SystemCapability.Multimedia.Image.ImageSource”。

**起始 API Level**

13

**变更发生版本**

从OpenHarmony 5.0.0.57版本开始。

**变更的接口/组件**

@ohos.multimedia.image中涉及修改的属性如下：

| 接口名| 接口说明 | 属性名 | 属性说明 |
| -------- | -------- | -------- | -------- |
|image.ImageSource.DecodingOptionsForPicture|图像解码设置选项|desiredAuxiliaryPictures|设置AuxiliaryPicture类型，默认解码所有AuxiliaryPicture类型|


**适配指导**

接口中属性的SystemCapability正常应该与对应接口的SystemCapability一致。但如果代码中涉及调用canIUse()方法对本次变更涉及接口支持情况进行判断，则应修改canIUse()方法传入的SystemCapability，判断设备是否支持图片源解码解析能力需使用canIUse("SystemCapability.Multimedia.Image.ImageSource")。
