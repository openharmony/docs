# Using Crashpad to Collect Web Component Crash Information

The **Web** component supports process crash information collection using Crashpad. Crashpad is a process crash information handling tool provided by the Chromium kernel. When a process (including the main process and web rendering process) crashes due to the use of a **Web** component, Crashpad writes the **minidump** file in the sandbox directory of the main process of the application. This file is in binary format and the filename extension is **.dmp**. It records crash causes, thread information, and register information. You can use this file to analyze process crashes related to **Web** components.

How to use

1. When a process crashes because a **Web** component is used in the application, the corresponding **dmp** file is generated in the sandbox directory of the main process of the application. The sandbox path is as follows:

   ```c
   /data/storage/el2/log/crashpad
   ```

2. Obtain the DMP file in the directory and then parse it. The procedure is as follows:

   * Use the minidump_stackwalk tool to parse the DMP file, and then you can obtain the process crash information (crash cause, thread information, and register information). The example is as follows (Linux environment):

     ```c
     ./minidump_stackwalk b678e0b5-894b-4794-9ab3-fb5d6dda06a3.dmp > parsed_stacktrace.txt
     ```

     You can obtain minidump_stackwalk by compiling the source code of breakpad project. For details, see [Breakpad](https://chromium.googlesource.com/breakpad/breakpad).

   * Sample of the parsed file is as follows:

     ```c
     Crash reason:  SIGSEGV /SEGV_MAPERR    The signal that causes the process crash, which is a segment error.
     Crash address: 0x0
     Process uptime: 12 seconds

     Thread 0 (crashed)                     The Thread 0 crashes.
      0 libweb_engine.so + 0x2e0b340        Call stack of layer 0. 0x2e0b340 is the offset address of the .so file, which can be used to decompile and parse the crash source code (depending on the unstripped .so file).
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

   * Use the llvm toolchain to parse the crash source code. The example is as follows (Linux environment):

     ```c
     ./llvm-addr2line -Cfpie libweb_engine.so 0x2e0b340
     ```

     The llvm-addr2line toolchain can be obtained in the SDK.
<!--no_check-->
