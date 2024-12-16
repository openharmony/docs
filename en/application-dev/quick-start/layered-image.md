# Configuring Layered Icons

If the application icon is a layered icon (including the foreground and background images), you can configure the icon by referring to this topic. For details about the icon specifications, see <!--RP1-->[Icon Deliverables](https://docs.openharmony.cn/pages/v5.0/zh-cn/design/ux-design/visual-app-icons.md#%E5%9B%BE%E6%A0%87%E4%BA%A4%E4%BB%98)<!--RP1End-->.

## Procedure
1. Place the foreground and background resource files in **AppScope\resources\base\media**.
   In this example, the file names of the foreground and background resource files are **foreground.png** and **background.png** respectively.
2. Create an **layered_image.json** file in the **AppScope\resources\base\media** directory and configure the foreground and background resource information of the layered icon in the file.
    ```json
    {
      "layered-image":
      {
        "background" : "$media:background",
        "foreground" : "$media:foreground"
      }
    }
    ```
3. Reference the layered icon resource file in the **app.json5** configuration file. Example:
     ```json
        {
          "app": {
            "icon": "$media:layered_image",
            // ...
          }
        }
    ```
