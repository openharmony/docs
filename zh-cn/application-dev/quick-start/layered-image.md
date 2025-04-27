# 配置分层图标

应用图标如果采用分层图标（包括前景图和背景图两层），可以参考本章节进行配置。图标规范详见<!--RP1-->[图标交付](https://docs.openharmony.cn/pages/v5.0/zh-cn/design/ux-design/visual-app-icons.md#%E5%9B%BE%E6%A0%87%E4%BA%A4%E4%BB%98)<!--RP1End-->，图标配置规则详见[图标配置](../application-models/application-component-configuration-stage.md#图标和标签配置)。

## 配置步骤
1. 将前景资源和背景资源文件放在“AppScope\resources\base\media”文件下。
   本例中采用的前景资源和背景资源的文件名分别为“foreground.png”和“background.png”。
2. 在“AppScope\resources\base\media”文件夹下创建layered_image.json文件，并在该文件中配置分层图标的前景资源与背景资源信息。
    ```json
    {
      "layered-image":
      {
        "background" : "$media:background",
        "foreground" : "$media:foreground"
      }
    }
    ```
3. 在app.json5配置文件中引用分层图标资源文件。示例如下：
     ```json
        {
          "app": {
            "icon": "$media:layered_image",
            // ...
          }
        }
    ```

