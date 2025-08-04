# 使用crashpad收集Web组件崩溃信息
<!--Kit: ArkWeb-->
<!--Subsystem: ArkWeb-->
<!--Owner: @qq_44167590-->
<!--SE: @hjoksky-->
<!--TSE: @ghiker-->

Web组件支持使用crashpad记录进程崩溃信息。crashpad是chromium内核提供的进程崩溃信息处理工具，在应用使用Web组件导致的进程崩溃出现后（包括应用主进程与Web渲染进程），crashpad会在应用主进程沙箱目录写入minidump文件。该文件为二进制格式，后缀为dmp，其记录了进程崩溃的原因、线程信息、寄存器信息等，应用可以使用该文件分析Web组件相关进程崩溃问题。

使用步骤如下：

1. 在应用使用Web组件导致的进程崩溃出现后，会在应用主进程沙箱目录下产生对应的dmp文件，对应的沙箱路径如下：

   ```c
   /data/storage/el2/log/crashpad
   ```

2. 应用可以访问该路径拿到目录下的dmp文件，然后进行解析，具体步骤如下：

   * 通过minidump_stackwalk工具解析dmp文件，可以得到上述dmp文件对应的进程崩溃信息（崩溃的原因、线程信息、寄存器信息等），示例如下（Linux环境）：

     ```c
     ./minidump_stackwalk b678e0b5-894b-4794-9ab3-fb5d6dda06a3.dmp > parsed_stacktrace.txt
     ```

     minidump_stackwalk由breakpad项目源码编译得到，编译方法见项目仓库：[breakpad仓库地址](https://chromium.googlesource.com/breakpad/breakpad)。

   * 查看解析后的文件，以下示例列出部分内容：

     ```c
     Crash reason:  SIGSEGV /SEGV_MAPERR    表示导致进程crash的信号，此处示例为段错误
     Crash address: 0x0
     Process uptime: 12 seconds

     Thread 0 (crashed)                     表示Thread 0发生crash
      0  libweb_engine.so + 0x2e0b340       0层调用栈，0x2e0b340为so偏移地址，可用来反编译解析crash源码（依赖unstripped so）
          x0 = 0x00000006a5719ff8    x1 = 0x000000019a5a28c0
          x2 = 0x0000000000020441    x3 = 0x00000000000001b6
          x4 = 0x0000000000000018    x5 = 0x0000000000008065
          x6 = 0x0000000000008065    x7 = 0x63ff686067666d60
          x8 = 0x0000000000000000    x9 = 0x5f129cf9e7bf008c
         x10 = 0x0000000000000001   x11 = 0x0000000000000000
         x12 = 0x000000069bfcc6d8   x13 = 0x0000000009a1746e
         x14 = 0x0000000000000000   x15 = 0x0000000000000000
         x16 = 0x0000000690df4850   x17 = 0x000000010c0d47f8
         x18 = 0x0000000000000000   x19 = 0x0000005eea827db8
         x20 = 0x0000005eea827c38   x21 = 0x00000006a56b1000
         x22 = 0x00000006a8b85020   x23 = 0x00000020002103c0
         x24 = 0x00000006a56b8a70   x25 = 0x0000000000000000
         x26 = 0x00000006a8b84e00   x27 = 0x0000000000000001
         x28 = 0x0000000000000000    fp = 0x0000005eea827c10
          lr = 0x000000069fa4b33c    sp = 0x0000005eea827c10
          pc = 0x000000069fa4b340
         Found by: given as instruction pointer in context
      1  libweb_engine.so + 0x2e0b338
          fp = 0x0000005eea827d80    lr = 0x000000069fa48d44
          sp = 0x0000005eea827c20    pc = 0x000000069fa4b33c
         Found by: previous frame's frame pointer
      2  libweb_engine.so + 0x2e08d40
          fp = 0x0000005eea827e50    lr = 0x00000006a385cef8
          sp = 0x0000005eea827d90    pc = 0x000000069fa48d44
         Found by: previous frame's frame pointer
      3  libweb_engine.so + 0x6c1cef4
          fp = 0x0000005eea828260    lr = 0x00000006a0f11298
          sp = 0x0000005eea827e60    pc = 0x00000006a385cef8
      ......
     ```

   * 使用llvm工具链解析crash源码位置，示例如下（Linux环境）：

     ```c
     ./llvm-addr2line -Cfpie libweb_engine.so 0x2e0b340
     ```

     llvm-addr2line工具链位于sdk中。
<!--no_check-->