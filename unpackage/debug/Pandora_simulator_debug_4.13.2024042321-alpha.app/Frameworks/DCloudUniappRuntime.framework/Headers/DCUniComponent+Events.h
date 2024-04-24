//
//  DCUniComponent+Events.h
//  UniCore
//
//  Created by DCloud-iOS-XHY on 2023/4/19.
//

#import <DCloudUniappRuntime/DCUniComponent.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN
@interface UniTouchGestureRecognizer : UIGestureRecognizer
@end

@interface DCUniComponent (Events) <UIGestureRecognizerDelegate>
- (BOOL)gestureShouldStopPropagation:(UIGestureRecognizer *)gestureRecognizer shouldReceiveTouch:(UITouch *)touch;
@end

NS_ASSUME_NONNULL_END
