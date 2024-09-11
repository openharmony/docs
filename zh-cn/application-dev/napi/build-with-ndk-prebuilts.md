# 在NDK工程中使用预构建库


在NDK工程中，可以通过CMake语法规则引入并使用预构建库。在引用预构建库时，模块libs目录中的预构建库，以及在CMakeList.txt编译脚本中声明的预构建库都会被打包。


例如在项目中需要使用预构建库libavcodec_ffmpeg.so，其开发态存放路径如下图所示：


![Snipaste_2023-10-30_14-39-27](figures/Snipaste_2023-10-30_14-39-27.png)


在模块的CMakeLists.txt编译脚本中通过add_library添加所需的预构建库，并声明预构建库路径等信息后，可以在target_link_libraries中声明链接该预构建库，脚本示例如下所示：


```
add_library(library SHARED hello.cpp)

add_library(avcodec_ffmpeg SHARED IMPORTED)
set_target_properties(avcodec_ffmpeg
    PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/third_party/FFmpeg/libs/${OHOS_ARCH}/libavcodec_ffmpeg.so)

target_link_libraries(library PUBLIC libace_napi.z.so avcodec_ffmpeg)
```


当在HAR中使用预构建库时，当前编译的库和链接所需预构建库会打包到HAR中的libs目录下，如下图所示：


![zh-cn_image_0000001693795070](figures/zh-cn_image_0000001693795070.png)


当使用远程依赖HAR中集成的预构建库时，CMakeLists.txt文件中引用脚本如下所示：


```
set(DEPENDENCY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../oh_modules)
add_library(library SHARED IMPORTED)
set_target_properties(library
    PROPERTIES
    IMPORTED_LOCATION ${DEPENDENCY_PATH}/library/libs/${OHOS_ARCH}/liblibrary.so)
add_library(entry SHARED hello.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so library)
```


当使用本地HAR中集成的预构建库时，CMakeLists.txt文件中引用脚本如下所示：


```
set(LIBRARY_DIR "${NATIVERENDER_ROOT_PATH}/../../../../library/build/default/intermediates/libs/default/${OHOS_ARCH}/")
add_library(library SHARED IMPORTED)
set_target_properties(library
    PROPERTIES
    IMPORTED_LOCATION ${LIBRARY_DIR}/liblibrary.so)
add_library(entry SHARED hello.cpp)
target_link_libraries(entry PUBLIC libace_napi.z.so)
```
