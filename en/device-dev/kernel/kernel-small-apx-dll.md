# Doubly Linked List


## Basic Concepts

A doubly linked list (DLL) is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains a pointer to the previous node and a pointer to the next node in the sequence of nodes. The pointer head is unique. A DLL allows access from a list node to its next node and also the previous node on the list. This data structure facilitates data search, especially traversal of a large amount of data.  The symmetry of the DLL also makes operations, such as insertion and deletion, easy. However, pay attention to the pointer direction when performing operations.


## Available APIs

The table below describes APIs available for the DLL. For more details about the APIs, see the API reference.

| Category                | API Description                                          |
| ------------------------ | ------------------------------------------------------------ |
| Initializing a DLL              | - **LOS_ListInit**: initializes a node as a DLL node.<br>- **LOS_DL_LIST_HEAD**: defines a node and initializes it as a DLL node.|
| Adding a node                | - **LOS_ListAdd**: adds a node to the head of a DLL.<br>- **LOS_ListHeadInsert**: same as **LOS_ListAdd**.<br>- **LOS_ListTailInsert**: inserts a node to the tail of a DLL.|
| Adding a DLL                | - **LOS_ListAddList**: adds the head of a DLL to the head of this DLL.<br>- **LOS_ListHeadInsertList**: inserts the head of a DLL to the head of this DLL.<br>- **LOS_ListTailInsertList**: inserts the end of a DLL to the head of this DLL.|
| Deleting a node                | - **LOS_ListDelete**: deletes a node from this DLL.<br>- **LOS_ListDelInit**: deletes a node from this DLL and uses this node to initialize the DLL.|
| Checking a DLL            | - **LOS_ListEmpty**: checks whether a DLL is empty.<br>- **LOS_DL_LIST_IS_END**: checks whether a node is the tail of the DLL.<br>- **LOS_DL_LIST_IS_ON_QUEUE**: checks whether a node is in the DLL.|
| Obtaining structure information          | - **LOS_OFF_SET_OF**: obtains the offset of a member in the specified structure relative to the start address of the structure.<br>- **LOS_DL_LIST_ENTRY**: obtains the address of the structure that contains the first node in the DLL. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure.<br>- **LOS_ListPeekHeadType**: obtains the address of the structure that contains the first node in the linked list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure. Null will be returned if the DLL is empty.<br>- **LOS_ListRemoveHeadType**: obtains the address of the structure that contains the first node in the linked list, and deletes the first node from the list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure. Null will be returned if the DLL is empty.<br>- **LOS_ListNextType**: obtains the address of the structure that contains the next node of the specified node in the linked list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the specified node, the third parameter indicates the name of the structure to be obtained, and the fourth input parameter indicates the name of the linked list in the structure. If the next node of the linked list node is the head node and is empty, NULL will be returned.|
| Traversing a DLL            | - **LOS_DL_LIST_FOR_EACH**: traverses a DLL.<br>- **LOS_DL_LIST_FOR_EACH_SAFE**: traverses the DLL and stores the subsequent nodes of the current node for security verification.|
| Traversing the structure that contains a DLL| - **LOS_DL_LIST_FOR_EACH_ENTRY**: traverses a DLL and obtains the address of the structure that contains the linked list node.<br>- **LOS_DL_LIST_FOR_EACH_ENTRY_SAFE**: traverses a DLL, obtains the address of the structure that contains the linked list node, and stores the address of the structure that contains the subsequent node of the current node.|

## How to Develop

The typical development process of the DLL is as follows:

1. Call **LOS_ListInit** or **LOS_DL_LIST_HEAD** to initialize a DLL.

2. Call **LOS_ListAdd** to add a node into the DLL.

3. Call **LOS_ListTailInsert** to insert a node into the tail of the DLL.

4. Call **LOS_ListDelete** to delete the specified node.

5. Call **LOS_ListEmpty** to check whether the DLL is empty.

6. Call **LOS_ListDelInit** to delete the specified node and initialize the DLL based on the node.


> **NOTE**<br>
>
> - Pay attention to the operations before and after the node pointer.
>
> - The DLL APIs are underlying interfaces and do not check whether the input parameters are empty. You must ensure that the input parameters are valid.
>
> - If the memory of a linked list node is dynamically allocated, release the memory when deleting the node.


## Development Example


###  Example Description

This example implements the following:


1. Initialize a DLL.

2. Add nodes.

3. Delete nodes.

4. Check the operation result.

### Sample Code

The sample code can be compiled and verified in **./kernel/liteos_a/testsuites/kernel/src/osTest.c**. The **ListSample** function is called in **TestTaskEntry**.

The sample code is as follows:

```
#include "stdio.h"
#include "los_list.h"

static UINT32 ListSample(VOID)
{
    LOS_DL_LIST listHead = {NULL,NULL};
    LOS_DL_LIST listNode1 = {NULL,NULL};
    LOS_DL_LIST listNode2 = {NULL,NULL};

    // Initialize the DLL.
    PRINTK("Initial head\n");
    LOS_ListInit(&listHead);

    // Add node 1 and node 2 and verify their relationship.
    LOS_ListAdd(&listHead, &listNode1);
    if (listNode1.pstNext == &listHead && listNode1.pstPrev == &listHead) {
        PRINTK("Add listNode1 success\n");
    }

    LOS_ListTailInsert(&listHead, &listNode2);
    if (listNode2.pstNext == &listHead && listNode2.pstPrev == &listNode1) {
        PRINTK("Tail insert listNode2 success\n");
    }

    // Delete the two nodes.
    LOS_ListDelete(&listNode1);
    LOS_ListDelete(&listNode2);

    // Check whether the DLL is empty.
    if (LOS_ListEmpty(&listHead)) {
        PRINTK("Delete success\n");
    }

    return LOS_OK;
}
```


**Verification**


The development is successful if the return result is as follows:



```
Initial head 
Add listNode1 success 
Tail insert listNode2 success
Delete success
```
