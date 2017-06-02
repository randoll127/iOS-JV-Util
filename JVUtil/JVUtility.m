//
//  JVUtility.m
//  JVUtil
//
//  Created by fengchao on 2017/6/2.
//  Copyright © 2017年 FC. All rights reserved.
//

#import "JVUtility.h"

@implementation JVUtility

//jsontStr to Dictionary
+(NSDictionary*)dictionaryFromJSONString:(NSString*)jsonStr{
    NSError * error = nil;
    NSData * jsonData = [jsonStr dataUsingEncoding:NSUTF8StringEncoding];
    if (!jsonData) {
        return nil;
    }
    NSMutableDictionary * jsonDic = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error];
    
    if (![jsonDic isKindOfClass:[NSDictionary class]]) {
        return nil;
    }
    
    if(error){
        return nil;
    }else{
        return jsonDic;
    }
}

//jsontStr to Dictionary
+(id)objectFromJSONString:(NSString*)jsonStr{
    NSError * error = nil;
    NSData * jsonData = [jsonStr dataUsingEncoding:NSUTF8StringEncoding];
    id jsonObject = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error];
    if(error){
        return nil;
    }else{
        return jsonObject;
    }
}

//Dictionary to jsontStr
+(NSString*)stringFromDictionary:(NSDictionary*)dict{
    if (dict == nil || ![dict isKindOfClass:[NSDictionary class]] || dict.count == 0)
        return nil;
    NSError * error = nil;
    NSString* jsonStr = [[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:dict options:0 error:&error]encoding:NSUTF8StringEncoding];
    if(error){
        return nil;
    }else{
        return jsonStr;
    }
}

//NSArray to jsontStr
+(NSString*)stringFromArray:(NSArray*)array{
    NSError * error = nil;
    NSString* jsonStr = [[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:array options:NSJSONWritingPrettyPrinted error:&error]encoding:NSUTF8StringEncoding];
    if(error){
        return nil;
    }else{
        return jsonStr;
    }
}


@end
