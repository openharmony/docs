# 双向链表


## 基本概念

双向链表是指含有往前和往后两个方向的链表，即每个结点中除存放下一个节点指针外，还增加一个指向前一个节点的指针。其头指针head是唯一确定的。从双向链表中的任意一个结点开始，都可以很方便地访问它的前驱结点和后继结点，这种数据结构形式使得双向链表在查找时更加方便，特别是大量数据的遍历。由于双向链表具有对称性，能方便地完成各种插入、删除等操作，但需要注意前后方向的操作。


## 功能说明

双向链表模块为用户提供下面几种功能，接口详细信息可以查看[API参考](https://gitee.com/openharmony/kernel_liteos_m/blob/master/utils/los_list.h)。

  | | |
| -------- | -------- |
| **功能分类** | **接口名** | 
| 初始化链表 | -&nbsp;LOS_ListInit：将指定节点初始化为双向链表节点。<br/>-&nbsp;LOS_DL_LIST_HEAD：定义一个节点并初始化为双向链表节点。 | 
| 增加节点 | -&nbsp;LOS_ListAdd：将指定节点插入到双向链表头端。<br/>-&nbsp;LOS_ListHeadInsert：将指定节点插入到双向链表头端，同LOS_ListAdd。<br/>-&nbsp;LOS_ListTailInsert：将指定节点插入到双向链表尾端。 | 
| 增加链表 | -&nbsp;LOS_ListAddList：将指定链表的头端插入到双向链表头端。<br/>-&nbsp;LOS_ListHeadInsertList：将指定链表的头端插入到双向链表头端。<br/>-&nbsp;LOS_ListTailInsertList：将指定链表的尾端插入到双向链表头端。 | 
| 删除节点 | -&nbsp;LOS_ListDelete：将指定节点从链表中删除。<br/>-&nbsp;LOS_ListDelInit：将指定节点从链表中删除，并使用该节点初始化链表。 | 
| 判断双向链表 | -&nbsp;LOS_ListEmpty：判断链表是否为空。<br/>-&nbsp;LOS_DL_LIST_IS_END：判断指定链表节点是否为链表尾端。<br/>-&nbsp;LOS_DL_LIST_IS_ON_QUEUE：判断链表节点是否在双向链表里。 | 
| 获取结构体信息 | -&nbsp;LOS_OFF_SET_OF：获取指定结构体内的成员相对于结构体起始地址的偏移量。<br/>-&nbsp;LOS_DL_LIST_ENTRY：获取双向链表中第一个链表节点所在的结构体地址，接口的第一个入参表示的是链表中的头节点，第二个入参是要获取的结构体名称，第三个入参是链表在该结构体中的名称<br/>-&nbsp;LOS_ListPeekHeadType：获取双向链表中第一个链表节点所在的结构体地址，接口的第一个入参表示的是链表中的头节点，第二个入参是要获取的结构体名称，第三个入参是链表在该结构体中的名称。如果链表为空，返回NULL。<br/>-&nbsp;LOS_ListRemoveHeadType：获取双向链表中第一个链表节点所在的结构体地址，并把第一个链表节点从链表中删除。接口的第一个入参表示的是链表中的头节点，第二个入参是要获取的结构体名称，第三个入参是链表在该结构体中的名称。如果链表为空，返回NULL。<br/>-&nbsp;LOS_ListNextType：获取双向链表中指定链表节点的下一个节点所在的结构体地址。接口的第一个入参表示的是链表中的头节点，第二个入参是指定的链表节点，第三个入参是要获取的结构体名称，第四个入参是链表在该结构体中的名称。如果链表节点下一个为链表头结点为空，返回NULL。| 
| 遍历双向链表 | -&nbsp;LOS_DL_LIST_FOR_EACH：遍历双向链表。<br/>-&nbsp;LOS_DL_LIST_FOR_EACH_SAFE：遍历双向链表，并存储当前节点的后继节点用于安全校验。 | 
| 遍历包含双向链表的结构体 | -&nbsp;LOS_DL_LIST_FOR_EACH_ENTRY：遍历指定双向链表，获取包含该链表节点的结构体地址。<br/>-&nbsp;LOS_DL_LIST_FOR_EACH_ENTRY_SAFE：遍历指定双向链表，获取包含该链表节点的结构体地址，并存储包含当前节点的后继节点的结构体地址。 | 


## 开发流程

双向链表的典型开发流程：

1. 调用LOS_ListInit/LOS_DL_LIST_HEAD初始双向链表。

2. 调用LOS_ListAdd向链表插入节点。

3. 调用LOS_ListTailInsert向链表尾部插入节点。

4. 调用LOS_ListDelete删除指定节点。

5. 调用LOS_ListEmpty判断链表是否为空。

6. 调用LOS_ListDelInit删除指定节点并以此节点初始化链表。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 需要注意节点指针前后方向的操作。
> 
> - 链表操作接口，为底层接口，不对入参进行判空，需要使用者确保传参合法。
> 
> - 如果链表节点的内存是动态申请的，删除节点时，要注意释放内存。


## 编程实例 


###  实例描述

本实例实现如下功能：


1. 初始化双向链表。

2. 增加节点。

3. 删除节点。

4. 测试操作是否成功。

### 编程示例

本演示代码在./kernel/liteos_a/testsuites/kernel/src/osTest.c中编译验证，在TestTaskEntry中调用验证入口函数ListSample

示例代码如下：
  
```
#include "stdio.h"
#include "los_list.h"

static UINT32 ListSample(VOID)
{
    LOS_DL_LIST listHead = {NULL,NULL};
    LOS_DL_LIST listNode1 = {NULL,NULL};
    LOS_DL_LIST listNode2 = {NULL,NULL};

    //首先初始化链表
    PRINTK("Initial head\n");
    LOS_ListInit(&listHead);

    //添加节点1和节点2，并校验他们的相互关系
    LOS_ListAdd(&listHead, &listNode1);
    if (listNode1.pstNext == &listHead && listNode1.pstPrev == &listHead) {
        PRINTK("Add listNode1 success\n");
    }

    LOS_ListTailInsert(&listHead, &listNode2);
    if (listNode2.pstNext == &listHead && listNode2.pstPrev == &listNode1) {
        PRINTK("Tail insert listNode2 success\n");
    }

    //删除两个节点
    LOS_ListDelete(&listNode1);
    LOS_ListDelete(&listNode2);

    //确认链表为空
    if (LOS_ListEmpty(&listHead)) {
        PRINTK("Delete success\n");
    }

    return LOS_OK;
}
```


**结果验证**


编译运行得到的结果为：


  
```
Initial head 
Add listNode1 success 
Tail insert listNode2 success
Delete success
```
