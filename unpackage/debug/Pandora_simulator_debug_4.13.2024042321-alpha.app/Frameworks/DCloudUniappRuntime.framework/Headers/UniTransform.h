//
//  UniTransform.h
//  UniCore
//
//  Created by DCloud-iOS-XHY on 2023/4/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class DCUniComponent;
@class UniLength;

NS_ASSUME_NONNULL_BEGIN

@interface UniTransform : NSObject

@property (nonatomic, assign, readonly) float rotateAngle;
@property (nonatomic, assign, readonly) float rotateX;
@property (nonatomic, assign, readonly) float rotateY;
@property (nonatomic, assign, readonly) float rotateZ;
@property (nonatomic, strong, readonly) UniLength *translateX;
@property (nonatomic, strong, readonly) UniLength *translateY;
@property (nonatomic, assign, readonly) float scaleX;
@property (nonatomic, assign, readonly) float scaleY;
@property (nonatomic, assign) float perspective;

- (instancetype)initWithCSSValue:(NSString *__nullable)cssValue origin:(NSString *__nullable)origin instance:(DCUniComponent *__nullable)component;

- (instancetype)initWithNativeTransform:(CATransform3D)transform instance:(DCUniComponent *)component;

- (void)applyTransformForView:(UIView *)view;

- (void)dc_resetTranform:(UIView*)view;
- (void)dc_resetTranformOrigin:(UIView*)view;

- (void)setTransformOrigin:(NSString *)transformOriginCSS;

@end

NS_ASSUME_NONNULL_END
