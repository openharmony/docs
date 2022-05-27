# NFS


## Basic Concepts<a name="section195414101464"></a>

NFS allows you to share files across hosts and OSs over a network. You can treat NFS as a file system service, which is equivalent to folder sharing in the Windows OS to some extent.

## Working Principles<a name="section165621321194618"></a>

The NFS of the OpenHarmony LiteOS-A kernel acts as an NFS client. The NFS client can mount the directory shared by a remote NFS server to the local machine and run the programs and shared files without occupying the storage space of the current system. To the local machine, the directory on the remote server is like its disk.

## Development Guidelines<a name="section7454935184611"></a>

1.  Create an NFS server.

The following uses the Ubuntu OS as an example to describe how to configure an NFS server.

-   Install the NFS server software.

Set the download source of the Ubuntu OS when the network connection is normal.

```
sudo apt-get install nfs-kernel-server
```

-   Create a directory for mounting and assign full permissions for the directory.

```
mkdir -p /home/sqbin/nfs
sudo chmod 777 /home/sqbin/nfs
```

-   Configure and start the NFS server.

Append the following line in the  **/etc/exports**  file:

```
/home/sqbin/nfs *(rw,no_root_squash,async)
```

**/home/sqbin/nfs**  is the root directory shared by the NFS server.

Start the NFS server.

```
sudo /etc/init.d/nfs-kernel-server start
```

Restart the NFS server.

```
sudo /etc/init.d/nfs-kernel-server restart
```

1.  Configure the board as an NFS client.

In this section, the NFS client is a device running the OpenHarmony kernel.

-   Set the hardware connection.

Connect the OpenHarmony kernel device to the NFS server. Set their IP addresses in the same network segment. For example, set the IP address of the NFS server to  **10.67.212.178/24**  and set the IP address of the OpenHarmony kernel device to  **10.67.212.3/24**. Note that the preceding IP addresses are private IP addresses used as examples. You need to use your actual IP addresses.

You can run the  **ifconfig**  command to check the OpenHarmony kernel device's IP address.

-   Start the network and ensure that the network between the board and NFS server is normal.

Start the Ethernet or another type of network, and then run  **ping**  to check whether the network connection to the server is normal.

```
OHOS # ping 10.67.212.178
[0]Reply from 10.67.212.178: time=1ms TTL=63
[1]Reply from 10.67.212.178: time=0ms TTL=63
[2]Reply from 10.67.212.178: time=1ms TTL=63
[3]Reply from 10.67.212.178: time=1ms TTL=63
--- 10.67.212.178 ping statistics ---
4 packets transmitted, 4 received, 0 loss
```

Initialize the NFS client.

```
OHOS # mkdir /nfs
OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
```

If the following information is displayed, the NFS client is initialized.

```
OHOS # mount 10.67.212.178:/home/sqbin/nfs /nfs nfs 1011 1000
Mount nfs on 10.67.212.178:/home/sqbin/nfs, uid:1011, gid:1000
Mount nfs finished.
```

This command mounts the  **/home/sqbin/nfs**  directory on the NFS server whose IP address is 10.67.212.178 to the  **/nfs**  directory on the OpenHarmony kernel device.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>This section assumes that the NFS server is available, that is, the  **/home/sqbin/nfs**  directory on the NFS server 10.67.212.178 is accessible.
>The  **mount**  command format is as follows:
>```
>mount <SERVER_IP:SERVER_PATH> <CLIENT_PATH> nfs
>```
>-   **SERVER\_IP**  indicates the IP address of the server.
>-   **SERVER\_PATH**  indicates the path of the shared directory on the NFS server.
>-   **CLIENT\_PATH**  indicates the NFS path on the local device.
>-   **nfs**  indicates the path to which the remote shared directory is mounted on the local device.
>Replace the parameters as required.
>If you do not want to restrict the NFS access permission, set the permission of the NFS root directory to  **777**  on the Linux CLI.
>```
>chmod -R 777 /home/sqbin/nfs
>```
>The NFS client setting is complete, and the NFS file system has been mounted.

1.  Share files using NFS.

Create the  **dir**  directory on the NFS server and save the directory. Run the  **ls**  command in the OpenHarmony kernel.

```
OHOS # ls /nfs
```

The following information is returned from the serial port:

```
OHOS # ls /nfs 
Directory /nfs:                 
drwxr-xr-x 0        u:0     g:0     dir
```

The  **dir**  directory created on the NFS server has been synchronized to the  **/nfs**  directory on the client \(OpenHarmony kernel system\).

Similarly, you can create files and directories on the client \(OpenHarmony kernel system\) and access them from the NFS server.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Currently, the NFS client supports some NFS v3 specifications. Therefore, the NFS client is not fully compatible with all types of NFS servers. You are advised to use the Linux NFS server to perform the development.

