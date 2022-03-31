# 创建源码工程


Import Project适用于打开DevEco Device Tool创建的工程项目和[获取的OpenHarmony源码](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/sourcecode-acquire.md)。如果是打开OpenHarmony源码，在打开工程时，点击**Import**，然后配置开发板类型和项目结构类型即可。


1. 打开DevEco Device Tool，进入Home页，点击**Import Project**打开工程。
   ![zh-cn_image_0000001171426014](figures/zh-cn_image_0000001171426014.png)

2. 选择待打开的工程目录，点击**Import**打开。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 工程存储路径不能包含中文字符、空格。如果工程存储路径包含中文字符或空格，可能导致编译失败。

   ![zh-cn_image_0000001260943159](figures/zh-cn_image_0000001260943159.png)

3. 如果您打开的目录不是DevEco Device Tool工程，则会出现如下提示框，点击**Import**。
   ![zh-cn_image_0000001135394334](figures/zh-cn_image_0000001135394334.png)

4. 在Select Project type界面，选择**Import from OpenHarmony Source**。
   ![zh-cn_image_0000001215743910](figures/zh-cn_image_0000001215743910.png)

5. 在Import Project界面，选择**Product**后，会自动填充对应的MCU、Board、company和kernel信息，然后**ohosVersion**选择对应的OpenHarmony源码版本。下图以导入wifiiot_hispark_pegasus为例进行说明。
   ![zh-cn_image_0000001260864961](figures/zh-cn_image_0000001260864961.png)

6. 点击**Open**打开工程或源码。
