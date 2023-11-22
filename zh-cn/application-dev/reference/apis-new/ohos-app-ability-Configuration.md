# @ohos.app.ability.Configuration    
定义环境变化信息。Configuration是接口定义，仅做字段声明。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## Configuration  
 **系统能力:**  SystemCapability.Ability.AbilityBase    
### 属性    
 **系统能力:**  SystemCapability.Ability.AbilityBase    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| language | string | false | false | 表示应用程序的当前语言，例如“zh"。  |  
| colorMode | ConfigurationConstant.ColorMode | false | false | 表示深浅色模式，默认为浅色。取值范围：<br />- COLOR_MODE_NOT_SET：未设置<br />- COLOR_MODE_LIGHT：浅色模式<br />- COLOR_MODE_DARK：深色模式 |  
| direction | ConfigurationConstant.Direction | false | false | 表示屏幕方向，取值范围：<br />- DIRECTION_NOT_SET：未设置<br />- DIRECTION_HORIZONTAL：水平方向<br />- DIRECTION_VERTICAL：垂直方向 |  
| screenDensity | ConfigurationConstant.ScreenDensity | false | false | 表示屏幕像素密度，取值范围：<br />- SCREEN_DENSITY_NOT_SET：未设置<br />- SCREEN_DENSITY_SDPI：120<br />- SCREEN_DENSITY_MDPI：160<br />- SCREEN_DENSITY_LDPI：240<br />- SCREEN_DENSITY_XLDPI：320<br />- SCREEN_DENSITY_XXLDPI：480<br />- SCREEN_DENSITY_XXXLDPI：640 |  
| displayId | number | false | false | 表示应用所在的物理屏幕ID。 |  
| hasPointerDevice | boolean | false | false | 指示指针类型设备是否已连接，如键鼠、触控板等。 |  
