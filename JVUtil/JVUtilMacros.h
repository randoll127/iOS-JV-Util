
#pragma mark Tool for Log
#ifdef DEBUG
#define LOG_FUN             NSLog(@"#####%s#####", __FUNCTION__);
#define LOG(CON)            NSLog(@"%@",CON)
#define DLog(fmt, ...)      NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#define  DEALLOC_LOG        -(void)dealloc{DLog(@"%@ is dealloc",NSStringFromClass([self class]));}
#else
#define LOG_FUN
#define LOG(CON)
#define DLog(fmt, ...)
#define  DEALLOC_LOG
#endif
#define LOG_ERROR(fmt, ...)    NSLog((@"!!!!!!!!!!!%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);



#pragma mark 常用目录
#define TMP_PATH                    NSTemporaryDirectory()
#define DOCUMENTS_PATH              [NSString stringWithFormat: @"%@/Documents", NSHomeDirectory()]
#define LIBRARY_CACHE_PATH          [NSString stringWithFormat: @"%@/Library/Caches", NSHomeDirectory()]
#define JV_BUNDLE_PATH              [NSBundle mainBundle].bundlePath
#define BUNDLE_WITH_PATH(PATH)      [NSString stringWithFormat:@"%@/%@",JV_BUNDLE_PATH,PATH]
#define FRAMEWORK_BUNDLE_WITH_FILENAME(FILENAME)     [[NSBundle bundleForClass:self.class] pathForResource:[FILENAME stringByDeletingPathExtension] ofType:[FILENAME pathExtension]]


#pragma mark 常用方法--转换类型
#define STRING_TO_DATA(__STR__)         [__STR__ dataUsingEncoding:NSUTF8StringEncoding]
#define DATA_TO_STRING(__DATA__)        [[NSString alloc]initWithData:__DATA__ encoding:NSUTF8StringEncoding]
#define JSON_DIC_FROM_STRING(__STR__)   [JVUtility dictionaryFromJSONString:__STR__]
#define JSON_OBJ_FROM_STRING(__STR__)   [JVUtility objectFromJSONString:__STR__]
#define JSON_STRING_FROM_DIC(__DIC__)   [JVUtility stringFromDictionary:__DIC__]
#define JSON_STRING_FROM_ARRAY(__ARRAY__)   [JVUtility stringFromArray:__ARRAY__]
