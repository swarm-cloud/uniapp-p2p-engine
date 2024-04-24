//
//  DCUniComponent+Layout.h
//  UniCore
//
//  Created by DCloud-iOS-XHY on 2023/4/15.
//

#import <DCloudUniappRuntime/DCUniComponent.h>
#import <DCloudUniappRuntime/UniUtility.h>

NS_ASSUME_NONNULL_BEGIN

@interface DCUniComponent ()
{
@package
    CGRect _calculatedFrame;
    CGPoint _absolutePosition;
    BOOL _isLastLayoutDirectionRTL;
    BOOL _isLayoutDirectionRTL;
}

@property(nonatomic, assign) UniPositionType positionType;


/**
 * @abstract Convert layout dimension value like 'left', 'width' to style value in js considering viewport and scale.
 */
- (NSString*)convertLayoutValueToStyleValue:(NSString*)valueName;

/**
 * @abstract Delete css node of a subcomponent.
 */
- (void)removeSubcomponentCssNode:(DCUniComponent *)subcomponent;

#pragma mark - RTL

@property (nonatomic, assign, readonly) BOOL isDirectionRTL;

// Now we scrollView RTL solution is tranform
// so scrollView need tranform subviews when RTL by default
// if your component view is not scrollView but also implement RTL layout by tranform，you need return YES
- (BOOL)shouldTransformSubviewsWhenRTL;

@end

NS_ASSUME_NONNULL_END
