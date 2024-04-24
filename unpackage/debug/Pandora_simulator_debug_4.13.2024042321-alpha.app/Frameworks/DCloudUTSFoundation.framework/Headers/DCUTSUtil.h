//
//  DCUTSUtil.h
//  DCloudUTSFoundation
//
//  Created by lizhongyi on 2024/1/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,DCUTSBlockType){
    DCUTSBlockTypeParams,
    DCUTSBlockTypeReturn
};

typedef void (^DCUTSBlock)(id result, DCUTSBlockType type);

extern NSString *const kUTSCallbackId;
extern NSString *const kUTSWXCallback;
extern NSString *const kUTSWXCallbackName;

@class UTSCallback;

@interface DCUTSUtil : NSObject

+ (UTSCallback *)getUTSCallBackWithId:(NSInteger)callbackId;

+ (NSString *)utsJsonObjectToString:(id)obj;

+ (BOOL)isBaseObject:(id)obj;

+ (NSString *)originTypeFromNumber:(NSNumber *)data;

@end

NS_ASSUME_NONNULL_END
