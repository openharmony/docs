# NFS


## 基本概念

NFS是Network File System（网络文件系统）的缩写。它最大的功能是可以通过网络，让不同的机器、不同的操作系统彼此分享其他用户的文件。因此，用户可以简单地将它看做是一个文件系统服务，在一定程度上相当于Windows环境下的共享文件夹。


## 运行机制

OpenHarmony LiteOS-A内核的NFS文件系统指的是NFS的客户端，NFS客户端能够将远程的NFS服务端分享的目录挂载到本地的机器中，运行程序和共享文件，但不占用当前系统的存储空间，在本地端的机器看起来，远程服务端的目录就好像是自己的一个磁盘一样。


## 开发指导

1. 搭建NFS服务器

   这里以Ubuntu操作系统为例，说明服务器端设置步骤。

   - 安装NFS服务器软件。

     设置好Ubuntu系统的下载源，保证网络连接好的情况下执行：


     ```
     sudo apt-get install nfs-kernel-server
     ```

   - 创建用于挂载的目录并设置完全权限

  
     ```
     mkdir -p /home/sqbin/nfs
     sudo chmod 777 /home/sqbin/nfs
     ```

   - 设置和启动NFS server。

     修改NFS配置文件/etc/exports，添加如下一行：


     ```
     /home/sqbin/nfs *(rw,no_root_squash,async)
     ```

     其中/home/sqbin/nfs是NFS共享的根目录。

     执行以下命令启动NFS server：


     ```
     sudo /etc/init.d/nfs-kernel-server start
     ```

     执行以下命令重启NFS server：


     ```
     sudo /etc/init.d/nfs-kernel-server restart
     ```

2. 设置单板为NFS客户端

   本指导中的NFS客户端指运行OpenHarmony内核的设备。

   - 硬件连接设置。

     OpenHarmony内核设备连接到NFS服务器的网络。设置两者IP，使其处于同一网段。比如，设置NFS服务器的IP为10.67.212.178/24，设置OpenHarmony内核设备IP为 
  10.67.212.3/24，注意：此IP为内网私有IP地址，用户使用时有差异，以用户实际IP为准。

     OpenHarmony内核设备上的IP信息可通过ifconfig命令查看。

   - 启动网络，确保单板到NFS服务器之间的网络通畅。

     启动以太网或者其他类型网络，使用ping命令检查到服务器的网络是否通畅。


     ```
     OHOS # ping 10.67.212.178
     [0]Reply from 10.67.212.178: time=1ms TTL=63
     [1]Reply from 10.67.212.178: time=0ms TTL=63
     [2]Reply from 10.67.212.178: time=1ms TTL=63
     [3]Reply from 10.67.212.178: time=1ms TTL=63
     --- 10.67.212.178 ping statistics ---
3. packets transmitted, 4 received, 0 loss

   客户端NFS初始化，运行命令：


   ```
   OHOS # mkdir /nfs
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   ```

   将从串口得到如下回应信息，表明初始化NFS客户端成功。


   ```
   OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
   Mount nfs on 10.67.212.178:/home/sqbin/nfs, uid:1011, gid:1000
   Mount nfs finished.
   ```

   该命令将服务器10.67.212.178上的/home/sqbin/nfs目录挂载到OpenHarmony内核设备上的/nfs上。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 本例默认nfs server已经配置可用，即示例中服务器10.67.212.178上的/home/sqbin/nfs已配置可访问。
   > 
   > mount命令的格式为：
   > 
   > 
   > ```
   > mount <SERVER_IP:SERVER_PATH> <CLIENT_PATH> nfs
   > ```
   > 
   > 其中“SERVER_IP”表示服务器的IP地址；“SERVER_PATH”表示服务器端NFS共享目录路径；“CLIENT_PATH”表示设备上的NFS路径，“nfs”表示客户端要挂载的路径，可以根据自己需要替换。
   > 
   > 如果不想有NFS访问权限限制，可以在Linux命令行将NFS根目录权限设置成777：
   > 
   > 
   > ```
   > chmod -R 777 /home/sqbin/nfs
   > ```
   > 
   > 至此，NFS客户端设置完毕。NFS文件系统已成功挂载。

4. 利用NFS共享文件

   在NFS服务器下新建目录dir，并保存。在OpenHarmony内核下运行ls命令：

   ```
   OHOS # ls /nfs
   ```

   则可从串口得到如下回应：


   ```
   OHOS # ls /nfs 
   Directory /nfs:                 
   drwxr-xr-x 0        u:0     g:0     dir
   ```

   可见，刚刚在NFS服务器上新建的dir目录已同步到客户端(OpenHarmony内核系统)的/nfs目录，两者保持同步。

   同样地，在客户端(OpenHarmony内核系统)上创建文件和目录，在NFS服务器上也可以访问，读者可自行体验。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 目前，NFS客户端仅支持NFS v3部分规范要求，因此对于规范支持不全的服务器，无法完全兼容。在开发测试过程中，建议使用Linux的NFS server，其对NFS支持很完善。
