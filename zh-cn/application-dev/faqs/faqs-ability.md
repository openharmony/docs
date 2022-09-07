# Ability框架开发常见问题



## Stage模型中是否有类似FA模型的DataAbility的开发指导文档

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

Stage模型中DataShareExtensionAbility提供了向其他应用共享以及管理其数据的方法。

参考文档：[数据共享开发指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/database/database-datashare-guidelines.md)

## 拉起Ability为什么在界面上没反应？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

1. 如果是通过startAbility的方式拉起，检查want中abilityName字段是否携带了bundleName做前缀，如果有，请删除;

2. 检查MainAbility.ts文件中onWindowStageCreate方法配置的Ability首页文件是否在main_pages.json中有定义，如果没有定义，请补齐;

3. SDK和OpenHarmony SDK系统推荐同一天的版本。

参考文档：[OpenHarmony版本转测试信息](https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/Release-Testing-Version.md)

## 调用方法的时候，如何解决方法内部的this变成undefined？

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

方式一：在调用方法的时候加上.bind(this)；

方式二：使用箭头函数。

## 如何解决must have required property 'startWindowIcon'报错 

适用于：OpenHarmony SDK 3.2.3.5版本，API9 Stage模型

Ability配置中缺少startWindowIcon属性配置，需要在module.json5中abilities中配置startWindowIcon。

参考文档：[Stage模型配置文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/stage-structure.md)

  示例：
  
```
{
  "module": {
    // do something
    "abilities": [{
      // do something
      "startWindowIcon": "$media:space",
      "startWindowBackground": "$color:white",
    }]
  }
}
```

## 如何获取设备横竖屏的状态变化的通知

适用于：OpenHarmony SDK 3.2.3.5版本， API9 Stage模型

使用Ability的onConfigurationUpdated回调实现，系统语言、颜色模式以及Display相关的参数，比如方向、Density，发生变化时触发该回调。

参考文档：[Ability开发指导](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/ability/stage-ability.md)
