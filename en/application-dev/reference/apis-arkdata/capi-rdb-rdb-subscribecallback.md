# Rdb_SubscribeCallback
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a callback used to return the subscribed event.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                                        | Description                              |
| ------------------------------------------------------------ | ---------------------------------- |
| [Rdb_DetailsObserver](capi-relational-store-h.md#rdb_detailsobserver) detailsObserver | Callback used to return the details about the device-cloud data change.|
| [Rdb_BriefObserver](capi-relational-store-h.md#rdb_briefobserver) briefObserver | Callback used to return the device-cloud data change event.      |
