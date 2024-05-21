# DDK_Ashmem


## Overview

Defines the data structure of **Ashmem** objects.

**Since**

12

**Related module**

[BASE DDK](_base_ddk.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [ashmemFd](#ashmemfd) | File descriptor of the **Ashmem** object.| 
| [address](#address) | Mapping address of the **Ashmem** object.| 
| [size](#size) | Length of the data array.| 
| [offset](#offset) | Data offset.| 
| [bufferLength](#bufferlength) | Length of the data array that is actually used.| 
| [transferredLength](#transferredlength) | Length of the data to transfer.| 


## Member Variable Description


### ashmemFd


~~~
int32_t ashmemFd
~~~

**Description**

File descriptor of the **Ashmem** object.


### address


~~~
const uint8_t * address
~~~

**Description**

Mapping address of the **Ashmem** object.


### size


~~~
const uint32_t size
~~~

**Description**

Length of the data array.


### offset


~~~
uint32_t offset
~~~

**Description**

Data offset.


### bufferLength


~~~
uint32_t bufferLength
~~~

**Description**

Length of the data array that is actually used.


### transferredLength


~~~
uint32_t transferredLength
~~~

**Description**

Length of the data to transfer.
