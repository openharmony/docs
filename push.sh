#!/bin/bash

git checkout "libuvDocUpdate"
git status
git add .
git commit --signoff -m "libuv文档表格修改"
git push --set-upstream origin libuvDocUpdate
