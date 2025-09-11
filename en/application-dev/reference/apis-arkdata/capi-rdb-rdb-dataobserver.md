# Rdb_DataObserver
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for the data observer.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                                        | Description                    |
| ------------------------------------------------------------ | ------------------------ |
| void* context                                                | Pointer to the context of the data observer.|
| [Rdb_SubscribeCallback](capi-rdb-rdb-subscribecallback.md) callback | Callback used to return the result.      |
