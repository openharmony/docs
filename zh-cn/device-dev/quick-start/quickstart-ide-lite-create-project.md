# 导入源码工程


在完成[搭建Windows+Ubuntu混合开发环境](../quick-start/quickstart-ide-lite-env-setup-win-ubuntu.md)和[获取源码](../quick-start/quickstart-ide-lite-sourcecode-acquire.md)后，您需要在Windows环境中按照如下步骤创建源码工程，之后方可在DevEco Device Tool中进行后续的操作。


1. 打开DevEco Device Tool，进入Home页，点击**Import Project**打开工程。

   ![zh-cn_image_0000001278358765](figures/zh-cn_image_0000001278358765.png)

2. 选择要导入的源码目录，点击**Import**打开。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 工程存储路径不能包含中文字符、空格。如果工程存储路径包含中文字符或空格，可能导致编译失败。

   ![zh-cn_image_0000001271477045](figures/zh-cn_image_0000001271477045.png)

3. 首次导入时，会出现如下提示框，点击**Import**。

   ![zh-cn_image_0000001314157517](figures/zh-cn_image_0000001314157517.png)

4. 在Select Project type界面，选择**Import from OpenHarmony Source**。

   ![zh-cn_image_0000001215743910](figures/zh-cn_image_0000001215743910.png)

5. 在Import Project界面，选择**Product**后，会自动填充对应的MCU、Board、company和kernel信息，然后**ohosVersion**选择对应的OpenHarmony源码版本。下图以导入wifiiot_hispark_pegasus为例进行说明。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > - Hi3861开发板Product选择“wifiiot_hispark_pegasus”。
   > 
   > - Hi3516DV300开发板Product选择“ipcamera_hispark_taurus”。

   ![zh-cn_image_0000001271237241](figures/zh-cn_image_0000001271237241.png)

6. 点击**Open**打开工程或源码。
