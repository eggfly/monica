#### 工具链：ESP-IDF v5.1.2

1. 更新依赖

   ```
   git submodule init
   git submodule update
   
   cd components/mooncake/
   git checkout main
   ```

2. 编译

   ```
   idf.py build
   ```

   
nvs,data,nvs,0x9000,20K,
otadata,data,ota,0xe000,8K,
app0,app,ota_0,0x10000,5M,
spiffs_res_0,data,spiffs,0x510000,1M,
spiffs_res_1,data,spiffs,0x610000,64K,
spring_wreath,data,undefined,0x620000,0xa2d9b0,
walking,data,undefined,0x104e000,0x128832,
