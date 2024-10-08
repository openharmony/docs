# 配置分层图标

应用图标需分层，满足以下规范要求：
- 应用图标需分为前景图和背景图两层。
- 图片资源尺寸要求为1024*1024px。
- 图片资源必须为正方形图像，系统会为对应场景自动生成遮罩裁切。

## 配置步骤
1. 归档前景和背景资源。将前景资源和背景资源，放置到resources\base\media文件下。
    

2. 提供前景和背景描述json文件。
- 配置json文件。"background"和"foreground"下的资源名，与上一步归档的图片资源名称对应。

    ```bash
    {
      "layered-image":
      {
        "background" : "$media:background",
        "foreground" : "$media:foreground"
      }
    }
    ```
- 归档json文件。将配置好的layered_image.json文件放置到resources\base\media文件下。

3. 在app.json5配置文件或者mooudle.json5配置文件中修改"icon"对应的的资源为"$media:layered_image"。

