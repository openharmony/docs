# 烧录异常


## 烧写选择串口后提示“Error: Opening COMxx: Access denied”

- **现象描述**

  点击烧写并选择串口后，出现Error: Opening COMxx: Access denied。

    **图1** 打开串口失败图  

  ![zh-cn_image_0000001271202461](figures/zh-cn_image_0000001271202461.png)

- **可能原因**
  串口已经被占用。

- **解决办法**

1. 按图依次选择下拉框，查找带有serial-xx的终端。

     **图2** 查找是否存在占用串口的终端  

   ![zh-cn_image_0000001271202473](figures/zh-cn_image_0000001271202473.png)

2. 点击标号中的垃圾桶图标，关闭串口。

     **图3** 关闭串口终端  

   ![zh-cn_image_0000001271202469](figures/zh-cn_image_0000001271202469.png)

3. 重新点击烧写，选择串口并开始烧写程序。

     **图4** 重新启动烧写任务  

   ![zh-cn_image_0000001271562449](figures/zh-cn_image_0000001271562449.png)


## Windows电脑与单板网络连接失败

- **现象描述**

  点击烧写并选择串口后，无法获取文件。

    **图5** 网络不通，单板无法获取文件图  

  ![zh-cn_image_0000001226922306](figures/zh-cn_image_0000001226922306.png)

- **可能原因**

  单板网络与Windows电脑不联通。

  Windows电脑防火墙未允许Visual Studio Code联网。

- **解决方法**

1. 检查网线是否连接。

2. 点击Windows防火墙。

     **图6** 网络防火墙设置图  

   ![zh-cn_image_0000001227082322](figures/zh-cn_image_0000001227082322.png)

3. 点击“允许应用通过防火墙”。

     **图7** 防火墙和网络保护界面图  

   ![zh-cn_image_0000001271202457](figures/zh-cn_image_0000001271202457.png)

4. 查找Visual Studio Code应用。

     **图8** 查找Visual Studio Code应用图  

   ![zh-cn_image_0000001271562445](figures/zh-cn_image_0000001271562445.png)

5. 勾选Visual Studio Code的专用和公用网络的访问权限。

     **图9** 允许Visual Studio Code应用访问网络 
 
   ![zh-cn_image_0000001271442273](figures/zh-cn_image_0000001271442273.png)


## 烧写失败

- **现象描述**
  点击烧写并选择串口后，出现无法烧写的情况。

- **可能原因**
  安装IDE插件DevEco后未重启。

- **解决方法**
  重启IDE。
