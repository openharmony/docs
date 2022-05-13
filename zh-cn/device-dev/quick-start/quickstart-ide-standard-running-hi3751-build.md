# 编译


1. 在Projects中，点击**Settings**按钮，进入Hi3751V350配置界面。

   ![zn-cn_image_20220428163840](figures/zn-cn_image_20220428163840.png)

2. 在toolchain页签中，DevEco Device Tool会自动检测依赖的编译工具链是否完备，如果提示部分工具缺失，可点击**SetUp**按钮，自动安装所需工具链。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果出现安装pip组件失败，可参考[修改Python源的方法](https://device.harmonyos.com/cn/docs/documentation/guide/ide-set-python-source-0000001227639986)进行修改，完成尝试重新安装。

   ![zn-cn_image_20220428164441](figures/zn-cn_image_20220428164441.png)

   工具链自动安装完成后如下图所示。

   ![zn-cn_image_20220428165528](figures/zn-cn_image_20220428165528.png)

3. 在“hi3751v350”配置页签中，设置源码的编译类型**build_type**，默认为“debug“类型，请根据需要进行修改。然后点击**Save**按钮进行保存。

   ![zn-cn_image_20220428165737](figures/zn-cn_image_20220428165737.png)

4. 在“PROJECT TASKS”中，点击对应开发板下的**Build**按钮，执行编译。

   ![zn-cn_image_20220428170003](figures/zn-cn_image_20220428170003.png)

   等待**TERMINAL**窗口输出“SUCCESS”，编译完成。

   ![zn-cn_image_20220428183538](figures/zn-cn_image_20220428183538.png)

   编译完成后，可以在工程的**out**目录下，查看编译生成的文件，用于后续的[Hi3751V350开发板烧录](./quickstart-ide-standard-running-hi3751-burning.md)。
