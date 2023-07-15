# arkui子系统ChangeLog

## cl.arkui.1 FormComponent组件中的JS卡片禁用网络图片

FormComponent组件中的JS卡片禁止使用网络图片。

**变更影响**

影响FormComponent中JS卡片中网络图片的加载显示。变更前JS卡片支持网络图片加载，变更后JS卡片不支持网络图片的加载。变更后建议将所需的网络图片下载至内存后刷新。
