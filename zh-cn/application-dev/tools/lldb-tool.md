### lldb使用命令行远程调试hap应用的过程


- 1.首先推送lldb-server到远程设备
- 2.启动本地lldb，并选择远程平台remote-ohos，建立连接
- 3.设置hap运行所需库路径
-   `settings append target.exec-search-paths "MyApp2/entry/build/default/intermediates/cmake/default/obj/armeabi-v7a"`
- 4. dc install 安装hap包，然后启动hap应用
-    `hdc shell aa start -a EntryAbility -b com.example.myapplication`
- 5. 获取hap应用进程pid
- 6.对C++代码打断点
    `breakpoint set --file hello.cpp --line 154`
- 7.attach 应用的进程
    `attach -p pid`
- 8.执行continue命令
   ` continue`
- 9.进行后续调试流程
