首先按照常规方式下载安装golang、goland

会遇到两个大问题

1、同一目录下的文件相互调用，

2、不同目录下的文件相互调用

安装后的部分配置需要注意以下几点配置

GOROOT

![pic01](pic/pic01.png)

GOPATH

![pic02](pic/pic02.png)

Go Modules

![pic03](pic/pic03.png)



然后使用`go mod init name`生成`go.mod`