//
//  FlexNode.h
//  UniCore
//
//  Created by X on 2023/2/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT const NSString* UniLayoutBuildString;

typedef NS_ENUM(NSInteger, UniCSSBoxSizing){
    UniCSSBoxSizingBorderBox,
    UniCSSBoxSizingContentBox
};

typedef NS_ENUM(NSInteger, UniCSSFlexAlign){
    UniCSSFlexAlignAuto,
    UniCSSFlexAlignFlexStart,
    UniCSSFlexAlignCenter,
    UniCSSFlexAlignFlexEnd,
    UniCSSFlexAlignStretch,
    UniCSSFlexAlignBaseline,
    UniCSSFlexAlignSpaceBetween,
    UniCSSFlexAlignSpaceAround
};

typedef NS_ENUM(NSInteger, UniCSSFlexDirection){
    UniCSSFlexDirectionRow,
    UniCSSFlexDirectionRowReverse,
    UniCSSFlexDirectionColumn,
    UniCSSFlexDirectionColumnReverse,
    UniCSSFlexDirectionInvalid
};

typedef NS_ENUM(NSInteger, UniCSSDirection){
    UniCSSDirectionInherit,
    UniCSSDirectionLTR,
    UniCSSDirectionRTL
};

typedef NS_ENUM(NSInteger, UniCSSFlexJustify){
    UniCSSFlexJustifyFlexStart = UniCSSFlexAlignFlexStart,
    UniCSSFlexJustifyCenter = UniCSSFlexAlignCenter,
    UniCSSFlexJustifyFlexEnd = UniCSSFlexAlignFlexEnd,
    UniCSSFlexJustifySpaceBetween = UniCSSFlexAlignSpaceBetween,
    UniCSSFlexJustifySpaceAround = UniCSSFlexAlignSpaceAround
} ;
  
typedef NS_ENUM(NSInteger,UniCSSFlexOverflow){
    UniCSSFlexOverflowVisible,
    UniCSSFlexOverflowHidden,
    UniCSSFlexOverflowScroll
} ;

typedef NS_ENUM(NSInteger,UniCSSPositionType){
    UniCSSPositionTypeRelative,
    UniCSSPositionTypeAbsolute,
    UniCSSPositionTypeFixed,
    UniCSSPositionTypeSticky
} ;

typedef NS_ENUM(NSInteger, UniCSSFlexWrap){
    UniCSSFlexWrapNoWrap,
    UniCSSFlexWrapWrap,
    UniCSSFlexWrapWrapReverse,
    UniCSSFlexWrapInvalid
} ;

typedef NS_ENUM(NSInteger, UniCssDisplayType){
    UniCssDisplayTypeFlex,
    UniCssDisplayTypeNone
} ;

typedef NS_ENUM(NSInteger, UniCssFlexEdge){
    UniCssFlexEdgeLeft,
    UniCssFlexEdgeTop,
    UniCssFlexEdgeRight,
    UniCssFlexEdgeBottom,
    UniCssFlexEdgeStart,
    UniCssFlexEdgeEnd,
    UniCssFlexEdgeHorizontal,
    UniCssFlexEdgeVertical,
    UniCssFlexEdgeAll,
    UniCssFlexEdgeNone = -1
};

typedef NS_ENUM(NSInteger, UniCSSBorderStyle){
    UniCSSBorderStyleNone,
    UniCSSBorderStyleBoreder
} ;

typedef NS_ENUM(NSInteger, UniCSSNodeLevel){
    UniCSSNodeLevelDefalut = 0,
    UniCSSNodeLevelRoot
};

@protocol UniLayoutFlexMeasureDelegate
-(CGSize)onSizeMeasureFuncWidth:(float) width mode:(int)widthMode height:(float)height mode:(int)heightMode;
@end

@interface UniLayoutFlexNode : NSObject
- (instancetype)initWithLevel:(UniCSSNodeLevel)level;
- (void)setLevel:(UniCSSNodeLevel)level;
- (void)insertChild:(UniLayoutFlexNode*)child atIndex:(NSUInteger)index;
- (UniLayoutFlexNode*)removeChildNode:(UniLayoutFlexNode*)child atIndex:(NSUInteger)index;
- (UniLayoutFlexNode*)removeChildNode:(UniLayoutFlexNode*)child;
//- (NSUInteger)getChildCount;
//- (NSUInteger)dirtyChildCount;
//- (UniLayoutFlexNode*)getChildAt:(NSUInteger)index;
//- (UniLayoutFlexNode*)getParent;
//- (NSUInteger)indexOf:(UniLayoutFlexNode*)child;

//bool FlexNodeNode(JNIEnv* env, const base::android::JavaParamRef<jobject>& obj);
//void FlexNodeNodeSetHasMeasureFunc(JNIEnv* env,
//                                   const base::android::JavaParamRef<jobject>& obj,
//                                   jboolean hasMeasureFunc);
//void FlexNodeNodeSetHasBaselineFunc(JNIEnv* env,
//                                    const base::android::JavaParamRef<jobject>& obj,

- (void)setMeasureOCDelegate:(nullable id<UniLayoutFlexMeasureDelegate>)delegate;
- (void)reset;
- (void)free;
- (void)calculateLayoutWithWidth:(float)width height:(float)height direction:(UniCSSDirection)direction;
- (void)dirty;
- (bool)isDirty;
- (bool)isDescendantDirty;
- (bool)hasNewLayout;
- (void)markLayoutSeen;
- (UniCSSDirection)getDirection;
- (void)setDirection:(UniCSSDirection)direction;
- (UniCSSBoxSizing)getBoxSizing;
- (void)setBoxSizing:(UniCSSBoxSizing)BoxSizing;
- (UniCSSFlexDirection)getFlexDirection;
- (void)setFlexDirection:(UniCSSFlexDirection)flexDirection;
- (UniCSSFlexJustify)getJustifyContent;
- (void)setJustifyContent:(UniCSSFlexJustify)JustifyContent;
- (UniCSSFlexAlign)getAlignItems;
- (void)setAlignItems:(UniCSSFlexAlign)AlignItems;
- (UniCSSFlexAlign)getAlignSelf;
- (void)setAlignSelf:(UniCSSFlexAlign)AlignSelf;
- (UniCSSFlexAlign)getAlignContent;
- (void)setAlignContent:(UniCSSFlexAlign)AlignContent;
- (UniCSSPositionType)getPositionType;
- (void)setPositionType:(UniCSSPositionType)PositionType;
- (UniCSSFlexWrap)getFlexWrap;
- (void)setFlexWrap:(UniCSSFlexWrap)FlexWrap;
- (UniCSSFlexOverflow)getOverflow;
- (void)setOverflow:(UniCSSFlexOverflow)Overflow;
- (void)setDisplay:(UniCssDisplayType)Display;

- (float)getFlex;
- (void)setFlex:(float)Flex;

- (float)getFlexGrow;
- (void)setFlexGrow:(float)FlexGrow;

- (float)getFlexShrink;
- (void)setFlexShrink:(float)FlexShrink;

- (float)getFlexBasis;
- (void)setFlexBasis:(float)FlexBasis;
- (float)getFlexBasisPercent;
- (void)setFlexBasisPercent:(float)FlexBasisPercent;
- (void)setFlexBasisAuto;

- (float)getContentWidth:(BOOL)round ;
- (float)getContentHeight:(BOOL)round;

- (float)getContentWidth;
- (float)getContentHeight;

- (float)getLayoutWidth;
- (float)getLayoutHeight;
- (float)getLayoutMargin:(UniCssFlexEdge)edge;
- (float)getLayoutBorder:(UniCssFlexEdge)edge;
- (float)getLayoutPadding:(UniCssFlexEdge)edge;
- (float)getLayoutLeft;
- (float)getLayoutTop;
- (float)getLayoutRight;
- (float)getLayoutBottom;

- (float)getStyleWidth;
- (float)getStyleHeight;
- (void)setStyleWidth:(float)width;
- (void)setStyleWidthPercent:(float)width;
- (void)setStyleHeight:(float)width;
- (void)setStyleHeightPercent:(float)height;

- (float)getStyleMaxWidth;
- (void)setStyleMaxWidth:(float)width;
- (void)setStyleMaxWidthPercent:(float)width;
- (float)getStyleMaxHeight;
- (void)setStyleMaxHeight:(float)width;
- (void)setStyleMaxHeightPercent:(float)width;

- (float)getStyleMinWidth;
- (void)setStyleMinWidth:(float)width;
- (void)setStyleMinWidthPercent:(float)width;
- (float)getStyleMinHeight;
- (void)setStyleMinHeight:(float)width;
- (void)setStyleMinHeightPercent:(float)width;

- (void)setMarginAutoEdge:(UniCssFlexEdge)edge;
- (void)setMarginEdge:(UniCssFlexEdge)edge value:(float)value;
- (void)setMarginEdge:(UniCssFlexEdge)edge percentValue:(float)value;
- (void)setPaddingEdge:(UniCssFlexEdge)edge value:(float)value;
- (void)setPaddingEdge:(UniCssFlexEdge)edge percentValue:(float)value;
- (void)setBorderEdge:(UniCssFlexEdge)edge value:(float)value;
- (void)setBorderEdge:(UniCssFlexEdge)edge percentValue:(float)value;
- (void)setPositionEdge:(UniCssFlexEdge)edge value:(float)value;
- (void)setPositionEdge:(UniCssFlexEdge)edge percentValue:(float)value;

- (void)setBorderEdge:(UniCssFlexEdge)edge style:(UniCSSBorderStyle)value;
- (void)setBackgroundColor:(NSString*)color;
- (void)setDebugData:(NSString*)value forKey:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
