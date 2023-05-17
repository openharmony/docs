# 三四方库使用常见问题

## 如何获取可用的三方库

适用于OpenHarmony 3.1 Beta5  API 9

通过ohpm可以获取的三四方库在Gitee上做了汇总（[OpenHarmony上可直接使用的三方组件汇总](https://gitee.com/openharmony-tpc/tpc_resource)），针对于不同功能三方库内容做了分类，开发者可以根据需要进行参考。

## 网络相关的三方库有哪些

适用于OpenHarmony 3.1 Beta5  API 9

网络相关的三方库有[Axios](https://gitee.com/openharmony-sig/axios)、httpclient、okdownload等，具体分类可以参考[三四方库网络分类](https://gitee.com/openharmony-tpc/tpc_resource?_from=gitee_search#%E7%BD%91%E7%BB%9C)。

## 如何使用ohpm引入三四方库

适用于OpenHarmony 3.1 Beta5  API 9

**解决措施**

-   方式一：
    1.  打开Terminal窗口，通过如下指令进入到entry目录。

        ```
        cd entry
        ```

    2.  以引入“dayjs”为例，执行以下指令进行安装。

        ```
        ohpm install dayjs
        ```

    3.  在对应的js文件中直接引用。

        ```
        import dayjs from 'dayjs'; 
        ```


-   方式二：
    1.  打开工程目录下的entry目录，找到该目录下的oh-package.json5文件。
    2.  在oh-package.json5文件中写入想要安装的三方库，以“dayjs”为例，示例如下：

        ```
        {
          "dependencies": {
            "dayjs": "^1.10.4",
          }
        }
        ```

    3.  打开Terminal窗口，通过如下指令进入到entry目录。

        ```
        cd entry
        ```

    4.  执行指令进行安装。

        ```
        ohpm install
        ```

    5.  在对应的js文件中直接引用。

        ```
        import dayjs from 'dayjs'; 
        ```



