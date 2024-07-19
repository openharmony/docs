# Using Crashpad to Collect Web Component Crash Information

Web components can use crashpad to record process crash information. Crashpad is a process crash information processing tool provided by the Chromium kernel. When a process crash (including the main process and web rendering process) occurs due to the use of web components by an application, Crashpad writes the minidump file in the sandbox directory of the main process of the application. This file is in binary format and the file name extension is .dmp. It records process crash causes, thread information, and register information. Applications can use this file to analyze process crash problems related to web components.

Procedure:

1. If the process breaks down because the application uses the web component, the corresponding DMP file is generated in the sandbox directory of the main process of the application. The sandbox path is as follows:

   ```c
   /data/storage/el2/log/crashpad
   ```

2. The application can access the path to obtain the DMP file in the directory and parse the file. The procedure is as follows:

   * Use the minidump_stackwalk tool to parse the DMP file and obtain the process crash information (crash cause, thread information, and register information) corresponding to the preceding DMP file. The following is an example (Linux environment):

     ```c
     ./minidump_stackwalk b678e0b5-894b-4794-9ab3-fb5d6dda06a3.dmp > parsed_stacktrace.txt
     ```

     minidump_stackwalk is obtained by compiling the breakpad project source code. For details about the compilation method, see [breakpad repository address](https://chromium.googlesource.com/breakpad/breakpad).

   * View the parsed file. The following is an example:

     ```c
     Crash reason: SIGSEGV /SEGV_MAPERR indicates the signal that causes the process crash. In this example, the signal is a segment error.
     Crash address: 0x0
     Process uptime: 12 seconds

     Thread 0 (crashed) indicates that Thraed 0 crashes.
      0 libweb_engine.so + 0x2e0b340 Layer 0 call stack. 0x2e0b340 is the offset address of the .so file, which can be used to decompile and parse the crash source code (depending on the unstripped .so file).
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

   * Use the llvm tool chain to parse the crash source code location. The following is an example (Linux environment):

     ```c
     ./llvm-addr2line -Cfpie libweb_engine.so 0x2e0b340
     ```

     The llvm-addr2line toolchain is located in the SDK.
<!--no_check-->
