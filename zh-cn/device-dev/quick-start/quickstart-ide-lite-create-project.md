# 导入源码工程


在完成[搭建Windows+Ubuntu混合开发环境](../quick-start/quickstart-ide-lite-env-setup-win-ubuntu.md)和[获取源码](../quick-start/quickstart-ide-lite-sourcecode-acquire.md)后，您需要在Windows环境中按照如下步骤创建源码工程，之后方可在DevEco Device Tool中进行后续的操作。


1. 打开DevEco Device Tool，进入Home页，点击**Import Project**打开工程。

   ![zh-cn_image_0000001278358765](figures/zh-cn_image_0000001278358765.png)

2. 选择OpenHarmony源码根目录路径，然后再选择**Import OpenHarmony Source**选项，点击**Import**进行导入。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 工程存储路径不能包含中文字符、空格。如果工程存储路径包含中文字符或空格，可能导致编译失败。

   ![zh-cn_image_0000001271477045](figures/zh-cn_image_0000001271477045.png)   
   
3. 在Import Project界面，选择**Product**后，会自动填充对应的SOC、Board、Company和Kernel信息，然后Ohos Ver选择对应的OpenHarmony源码版本。
   
   ![zh-cn_image_0000001271237242](figures/zh-cn_image_0000001271237242.png)
   
4. 点击**Open**打开工程或源码。