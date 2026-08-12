# About This Kit

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b2cda26727201a42e46e7a87886b946af8e04dbf translatedAt=2026-08-11T01:57:24.940Z pushedAt=2026-08-12T03:41:50.586Z -->

Media Library Kit provides the capabilities of managing albums and media files, including images and videos, to enable your application to quickly display images and play back videos.

## Available Capabilities

With Media Library Kit, you can manage albums and media files, including creating and accessing albums and modifying media assets in albums.

The following capabilities are opened to all applications:

- Selecting or saving media assets

  - [Selecting Media Assets Using Picker](photoAccessHelper-photoviewpicker.md)

  - [Saving Media Assets](photoAccessHelper-savebutton.md)

- Managing moving photos

  - [Accessing and Managing Moving Photos](photoAccessHelper-movingphoto.md)

  - [Playing Moving Photos with MovingPhotoView](movingphotoview-guidelines.md)

<!--RP2--><!--RP2End-->

The following capabilities are restrictedly opened to third-party applications:

> **NOTE**
> 
> The restrictedly opened capabilities require [requesting permissions related to album management module features](photoAccessHelper-preparation.md#requesting-permissions).<!--RP1-->These permissions are restrictedly opened.<!--RP1End-->

- [Managing media assets](photoAccessHelper-resource-guidelines.md)

  - Obtaining media assets

  - Obtaining image and video thumbnails

  - Renaming a media asset

- [Managing user albums](photoAccessHelper-userAlbum-guidelines.md)

  - Obtaining a user album

  - Renaming a user album

  - Adding images and videos to a user album.

  - Obtaining images and videos from a user album

  - Removing images and videos from a user album

- [Managing system albums](photoAccessHelper-systemAlbum-guidelines.md)

  - Favorites

  - Video album

- [Monitoring media asset changes](photoAccessHelper-notify-guidelines.md)

  - Registering a listener for the specified URI

  - Unregistering a listener for the specified URI

<!--Del-->

The following capabilities are opened to system applications:

- Media asset operations, including:

  - Creating a media asset

  - Moving a media asset to the trash

  - Deleting a media asset permanently

- Album-related operations, including:

  - Creating a user album

  - Deleting a user album

  - Hiding an album

  - Favoriting and unfavoriting an album

  - Using the Screenshots album

<!--DelEnd-->

## Features

- Simple and efficient development thanks to object-based API design.

- Integrated device-cloud access management.

- Secure, precise, and tightly controlled, with automatic authorization for picker and save components.

- Intelligent format conversion completed at the framework layer in a unified manner.

## Working Principles

The media library receives requests for obtaining or changing media assets from users, verifies the request validity and permissions, interacts with the database if the verification is successful, and returns the result.

<!--RP3--><!--RP3End-->