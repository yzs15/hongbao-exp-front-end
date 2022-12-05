## Qt run in lucaszy/cs101

```bash
docker run -p 5581:80 -p 5580:8080 -e USER="root" -v /dev/shm:/dev/shm -v <path/to/project>:/hongbao-fe --name=hongbao-fe lucaszy/cs101
```

1. docker 镜像中的 apt 源存在问题，替换成阿里源后才能下载 libczmq
2. docker 缺少Qt运行时和插件的依赖，在代码文件的lib文件夹下有相关文件
```bash
export LD_LIBRARY_PATH=<path/to/project>/src/lib:$LD_LIBRARY_PATH
export QT_PLUGIN_PATH=<path/to/project>/src/lib/qt5/plugins
```
3. Qt 默认在`/usr/local/lib/fonts`寻找字体，需要将字体复制到该文件夹
```bash
cp -r <path/to/project>/src/fonts /usr/loca/lib/
```
4.前端界面如下图所示，王老师对应独占用户，彭老师对应高级用户
![image](./IMG/%E5%BC%80%E5%8F%91%E5%9B%A2%E9%98%9F.jpg)

![image](./IMG/%E7%8E%8B%E8%80%81%E5%B8%88.jpg)
