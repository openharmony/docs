# Rdb_ProgressObserver
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for the observer for the device-cloud sync progress.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| void* context                                                | Context of the device-cloud sync progress observer.  |
| [Rdb_ProgressCallback](capi-relational-store-h.md#rdb_progresscallback) callback | Callback used to return the device-cloud sync progress.|
