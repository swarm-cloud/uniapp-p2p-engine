//
//  UniLength.h
//  UniCore
//
//  Created by DCloud-iOS-XHY on 2023/4/18.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    UniLengthTypeFixed,
    UniLengthTypePercent,
    UniLengthTypeAuto,
    UniLengthTypeNormal
} UniLengthType;

NS_ASSUME_NONNULL_BEGIN

@interface UniLength : NSObject

+ (instancetype)lengthWithFloat:(float)value type:(UniLengthType)type;

+ (instancetype)lengthWithInt:(int)value type:(UniLengthType)type;

- (float)valueForMaximum:(float)maximumValue;

- (int)intValue;

- (float)floatValue;

- (BOOL)isEqualToLength:(UniLength *)length;

- (BOOL)isFixed;

- (BOOL)isPercent;

- (BOOL)isAuto;

- (BOOL)isNormal;

@end

NS_ASSUME_NONNULL_END
