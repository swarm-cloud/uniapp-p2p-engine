// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from libdc.djinni

#import <Foundation/Foundation.h>


@protocol DCDcMessageCallback <NSObject>

- (void)onText:(nonnull NSString *)msg;

- (void)onBinary:(nonnull NSData *)msg;

@end