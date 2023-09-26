# arkui子系统ChangeLog

## cl.arkui.1 FormComponent组件中的JS卡片禁用网络图片

FormComponent组件中的JS卡片禁止使用网络图片。

**变更影响**

影响FormComponent中JS卡片中网络图片的加载显示。变更前JS卡片支持网络图片加载，变更后JS卡片不支持网络图片的加载。变更后建议将所需的网络图片下载至内存后刷新。
## cl.arkui.2 TextInput、TextArea、Search组件行为变更
TextInput、TextArea、Search组件获焦默认拉起输入法

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响Api version 10的TextInput、TextArea、Search组件

**关键的接口/组件变更**

TextInput、TextArea、Search组件获焦会拉起输入法

**适配指导**   

可以通过接口enableKeyboardOnFocus(bool)控制是否获焦拉起输入法，此接口参数默认值为true。

## cl.arkui.3 组件属性以及参数非法值拦截  


非法值使用默认值

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响所有设置了非法值的组件属性

**关键的接口/组件变更**

原先属性值由正常值变为非法值会跳过非法值的设置，变更后会拦截非法值并设置属性的默认值。对于没有默认值的属性如width、height等，则会取消其原先的正常值设置。

**适配指导**


组件属性以及参数非法值拦截排查非法值如"100abc"等，将其改为正常值。
        
