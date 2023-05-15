# OPCLR
OP插件的.Net中间件，免注册不使用COM
使用了CLRFor.NetCore的CPP类库作为中间件
注意CLR不支持MT编译，只支持MD/MDd 所以相关类库全部必须使用同一模式编译MD/MDd

使用方式：
.NetCore程序直接引用OPCLR.DLL即可，运行目录放置OPCLR.dll、Ijwhost.dll

宿主项目 https://github.com/WallBreaker2/op
宿主QQGroup：743710486
