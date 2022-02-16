# Overview of FAQs<a name="EN-US_TOPIC_0000001169691604"></a>

FAQs are used to help developers solve problems frequently encountered during development. They cover a wide range of topics.

## Environment Setup<a name="section93289248249"></a>

### Mini and Small Systems<a name="section197234983111"></a>

-   [What should I do if garbled characters and segmentation faults occur during hb installation?](environment-setup.md#section36351051193919)
-   [What should I do if the message "cannot import 'sysconfig' from 'distutils'" is displayed during hb installation?](environment-setup.md#section48221013144011)
-   [What should I do if the message "module 'platform' has no attribute 'linux\_distribution'" is displayed during hb installation?](environment-setup.md#section10307193044111)
-   [What should I do if the message "Could not find a version that satisfies the requirement ohos-build" is displayed during hb installation?](environment-setup.md#section8692735427)
-   [What should I do when the message configure: error: no acceptable C compiler found in $PATH is displayed during Python 3 installation?](environment-setup.md#section870082884217)
-   [What should I do when the message -bash: make: command not found is displayed during Python 3 installation?](environment-setup.md#section198707170455)
-   [What should I do when the message zlib not available is displayed during Python 3 installation?](environment-setup.md#section85401445204518)
-   [What should I do when the message No module named '\_ctypes' is displayed during Python 3 installation?](environment-setup.md#section12202694460)
-   [What should I do when an error with lsb\_release occurs during kconfiglib installation?](environment-setup.md#section5803174135115)
-   [What should I do if the message "ImportError: No module named apt\_pkg" is displayed during the execution of an unidentifiable command?](environment-setup.md#section510820516515)

## Compilation and Building<a name="section18826114693810"></a>

### Mini and Small Systems<a name="section693410399"></a>

-   [Invalid -- w Option](compilation-and-building-subsystem.md#section67961431372)
-   [Library ncurses Not Found](compilation-and-building-subsystem.md#section199631617371)
-   [mcopy not Found](compilation-and-building-subsystem.md#section937435175)
-   [No riscv File or Directory](compilation-and-building-subsystem.md#section1115535018713)
-   [No Crypto](compilation-and-building-subsystem.md#section17982573813)
-   [Unexpected Operator](compilation-and-building-subsystem.md#section53663205819)
-   [What should I do when the message Could not find a version that satisfies the requirement six\>=1.9.0 is displayed during compilation and building?](compilation-and-building-subsystem.md#section1917790845)
-   [What should I do when the message cannot find -lgcc is displayed during compilation and building?](compilation-and-building-subsystem.md#section141771701647)
-   [What should I do when the message indicating Python cannot be found is displayed during compilation and building?](compilation-and-building-subsystem.md#section51781202415)
-   [What should I do when the message indicating Python 3 cannot be found is displayed during compilation and building?](compilation-and-building-subsystem.md#section1917950148)

## Burning<a name="section6556741113712"></a>

### Mini and Small Systems<a name="section1029933713812"></a>

-   ["Error: Opening COMxx: Access denied" Is Displayed After a Serial Port Is Selected for Burning](burning.md#section18988185615914)

-   [What should I do when the image failed to be burnt?](burning.md#section1370982513317)
-   [What should I do when no command output is displayed?](burning.md#section183421944953)
-   [What should I do when Windows-based PC failed to be connected to the board?](burning.md#section1215410450215)

## Kernel<a name="section13741125564211"></a>

### Basic Kernel<a name="section1723365191114"></a>

-   [What are the differences between APIs provided by LiteOS-A and LiteOS-M?](kernel.md#section447571122918)
-   [How do I analyze thread stack overflow?](kernel.md#section8623141711293)

### File System<a name="section14523145918136"></a>

-   [What should I do when the Hi3516 board fails to open the same file in write mode \(LiteOS-A\)?](kernel.md#section517972255311)

### Chip Adaptation<a name="section141541939159"></a>

-   [What hardware platforms are supported by the LiteOS kernel?](kernel.md#section868413518533)
-   [What chip architectures are supported by the LiteOS kernel?](kernel.md#section1131661465417)

### Third-party Components<a name="section4988163321816"></a>

-   [What third-party components are supported by OpenHarmony?](kernel.md#section74138185411)
-   [What should I do if the key length verification fails when OpenSSL is used on OpenHarmony?](kernel.md#section10564614135516)
-   [Does setsockopt support SO\_RCVBUF and SO\_SNDBUF?](kernel.md#section2093373215556)

### Compilation and Linking<a name="section080219574225"></a>

-   [How do I run an application developed by ARM Linux on LiteOS-A?](kernel.md#section1164175713557)
-   [What system is used for OpenHarmony compilation? What compiler is used?](kernel.md#section132287223567)
-   [For a third-party component that is independently compiled into a static library and used on LiteOS-M, what should I do when the component's global variable value is incorrect or the system is suspended after the component's function is called?](kernel.md#section15189154225619)
-   [What should I do if the message "use VFP register arguments, xxx.o does not" is displayed when LiteOS-A generates a target executable file?](kernel.md#section193571012578)
-   [What should I do when calling clock\_gettime obtains an incorrect time?](kernel.md#section8973152015717)

## Porting<a name="section129331824154313"></a>

-   [How Do I Mount the Heap Memory to the Kernel?](porting.md#section21471536184914)

## Startup and Recovery<a name="section83501764443"></a>

-   [System startup interrupted due to "parse failed!" error](startup-and-recovery.md#section835662214302)
-   [System automatically restarted again and again](startup-and-recovery.md#section3857921143117)
-   [Failed to call the SetParameter or GetParameter API with correct parameter values](startup-and-recovery.md#section548818116328)

## System Services<a name="section19567132114455"></a>

### Utils<a name="section3214181711465"></a>

-   [1. Failure in running the KV store on the LiteOS-A kernel \(Hi3516 or Hi3518\) due to incorrect path setting for the KV store](system-applications.md#section16520347131511)

### Visual Applications<a name="section295651815466"></a>

-   [Is there a global variable that can be accessed by all pages?](system-applications.md#section187297991718)
-   [How do I obtain DOM elements?](system-applications.md#section1833493719175)
-   [How do I pass values between pages?](system-applications.md#section184283812183)
-   [How do I scroll a list to an item?](system-applications.md#section11897734131811)
-   [Does the <text\> component support multiple lines?](system-applications.md#section5872656121814)
-   [Why is a component not displayed?](system-applications.md#section7397125317107)
-   [How do I implement scrolling on a page?](system-applications.md#section338794422010)
-   [Why do not the left and top attributes take effect?](system-applications.md#section2597193611217)
-   [Why does not dynamic binding take effect?](system-applications.md#section6939050172115)
-   [How do I implement relative and absolute positioning?](system-applications.md#section5547311192215)
-   [How do I display or hide a component?](system-applications.md#section16107113352213)
-   [What are the precautions for using the margin attribute?](system-applications.md#section1524910142314)
-   [What are the precautions for event subscription?](system-applications.md#section1537132012231)
-   [What are the precautions for using dynamic binding?](system-applications.md#section96561452236)
-   [How does the loop attribute take effect for <swiper\>?](system-applications.md#section690166112414)
-   [What are the precautions for using an array?](system-applications.md#section1554552822414)

### HDC<a name="section178081876506"></a>

-   [hdc\_std Fails to Connect to a Device](system-applications.md#section1965012223257)
-   [hdc\_std Fails to Run](system-applications.md#section1157575212515)

