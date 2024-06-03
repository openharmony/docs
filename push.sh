#!/bin/bash

git checkout "libuvDocUpdate"
git status
git add .
git commit --signoff -m "libuv文档内容锚点测试"
git push --set-upstream origin libuvDocUpdate
