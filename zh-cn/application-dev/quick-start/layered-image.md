# 配置分层图标

应用图标如果采用分层图标（包括前景图和背景图两层），可以参考本章节进行配置。图标规范详见[图标资源规范](https://developer.huawei.com/consumer/cn/doc/design-guides/application-icon-0000001953444009#section634668113212)。

## 配置步骤
1. 将前景资源和背景资源文件放在“AppScope\resources\base\media”文件下。
   本例中采用的前景资源和背景资源的文件名分别为“foreground.png”和"background.png"。
2. 在“AppScope\resources\base\media”文件夹下创建layered_image.json文件，并在该文件中配置分层图标的前景资源与背景资源信息。
    ```bash
    {
      "layered-image":
      {
        "background" : "$media:background",
        "foreground" : "$media:foreground"
      }
    }
    ```
3. 在app.json5配置文件中引用分层图标资源文件。示例如下：
     ```bash
        {
          "app": {
            "icon": "$media:layered_image",
            // ...
          }
        }
    ```

