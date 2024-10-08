# 配置分层图标

应用图标如果采用分层图标（包括前景图和背景图两层），可以参考本章节进行配置。图标规范详见[图标资源规范](https://developer.huawei.com/consumer/cn/doc/design-guides/application-icon-0000001953444009#section634668113212)。

## 配置步骤
1. 将前景资源和背景资源，放置到AppScope\resources\base\media文件下。
    

2. 创建前景和背景描述json文件。
- 创建json文件。创建layered_image.json文件放置到AppScope\resources\base\media文件下。

- 配置json文件。设置"background"和"foreground"，与上一步归档的图片资源名称对应。
    ```bash
    {
      "layered-image":
      {
        "background" : "$media:background",
        "foreground" : "$media:foreground"
      }
    }
    ```

3. 引用分层图标。在app.json5配置文件中修改"icon"对应的的资源为"$media:layered_image"。

