//
//  UniJsBridge.h
//  DCloudUniappRuntime
//
//  Created by X on 2023/8/15.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <DCloudUniappRuntime/UniUTSProxy.h>

NS_ASSUME_NONNULL_BEGIN

typedef  NSDictionary<NSString*, id> UniJsObjectType;
typedef UniJsObjectType  UniElementStyleType;
typedef UniJsObjectType UniElementAttsType;
typedef UniJsObjectType UniElementPageType;

typedef  UniJsObjectType UniJsEventObject;
typedef id _Nullable (^UniEventCallBack)(UniJsEventObject*);
typedef void (^UniPageShowCallback)(void);
typedef void (^UniPageHideCallback)(void);
typedef void (^UniPageDestoryCallback)(void);
/*channel*/
typedef void(^UniJsChannelModuleCallback)(NSString *name, UniEventCallBack callback);
/*app*/
typedef  NSString*_Nonnull(^UniJsAppAddEventListenerCallback)(NSString *name, UniEventCallBack callback);
typedef void(^UniJsAppRemoveEventListenerCallback)(NSString *appid, NSString *tag);
typedef void(^UniJsAppReloadCallback)(void);
typedef void(^UniJsAppLoadFontFace)(NSString *family, NSString *source, void(^success)(void), void(^fail)(UniJsObjectType*));
typedef NSArray*_Nonnull(^UniJsAppGetExtElments)(void);
typedef NSDictionary *_Nullable(^UniJSAppGetRedirectInfo)(void);
typedef void(^UniJsAppUpdateStatusBarStyleCallback)(NSString* style);
/*page*/
typedef void(^UniJsPageCreateCallback)(NSString *pageId, NSString* url, UniElementPageType* style);
typedef void(^UniJsPageShowCallback)(NSString *pageId, UniElementPageType*, UniPageShowCallback);
typedef void(^UniJsPageHideCallback)(NSString *pageId, UniElementPageType*, UniPageHideCallback);
typedef void(^UniJsPageDestoryCallback)(NSString *pageId, UniElementPageType*, UniPageDestoryCallback);
typedef void(^UniJsPageRenderCallback)(NSString *pageId);
typedef void(^UniJSDccumentOnPopGestureStart)(NSString *pageId, NSString*functionName);
typedef void(^UniJSDccumentOffPopGestureStart)(NSString *pageId);
typedef void(^UniJsPageCreateDocumentCallback)(NSString *pageId, NSString* rootId, NSString* type, UniElementStyleType* style, UniElementAttsType* atts, NSArray *events);
typedef void(^UniJsPageUpdateStyleCallback)(NSString *pageId, UniElementStyleType* style);
typedef NSString*_Nonnull(^UniJsPageAddEventListenerCallback)(NSString *pageId, NSString *name, UniEventCallBack);
typedef void(^UniJsPageRemoveEventListenerCallback)(NSString *pageId, NSString *tag);
typedef void(^UniJsPageSnaphostCallback)(NSString *pageId, NSDictionary *options, UniEventCallBack);
typedef void(^UniJsPageLoadFontFaceCallback)(NSString *pageId, NSString *family, NSString *source, void(^success)(void), void(^fail)(UniJsObjectType*));
typedef NSString*_Nonnull(^UniJsPageGetDomJsonCallback)(NSString *pageId);
typedef void(^UniJSPageViewToTempFilePath)(NSString *pageId, NSString* eleId, NSString* offsetX, NSString* offsetY, BOOL wholeContent, NSString* path, BOOL overwrite, void(^success)(UniJsObjectType*), void(^fail)(UniJsObjectType*));
typedef void(^UniJSPageStartPullDownRefresh)(NSString *pageId, void(^success)(void), void(^fail)(UniJsObjectType*));
typedef void(^UniJSPageStopPullDownRefresh)(NSString *pageId, void(^success)(void), void(^fail)(UniJsObjectType*));
typedef void(^UniJSPageStopSetEnablePullDownRefresh)(NSString *pageId, BOOL enable);


/*document*/
typedef void(^UniJsDocumentAddElementCallback)(NSString *pageId, NSString* parentId, NSString* childId, NSString*anchorElemId,  NSString* type, UniElementStyleType*, UniElementAttsType* atts, NSArray *events);
typedef NSString*_Nonnull(^UniJsDocumentAddEventListenerCallback)(NSString *pageId, NSString* eleId, NSString *name, UniEventCallBack callback);
typedef void(^UniJsDocumentRemoveEventListenerCallback)(NSString *pageId, NSString* eleId, NSString *tag);
typedef void(^UniJsDocumentUpdateStyleCallback)(NSString *pageId, NSString* eleId, UniElementStyleType*);
typedef void(^UniJsDocumentUpdateAttrsCallback)(NSString *pageId, NSString* eleId, UniElementAttsType*);
typedef id __nullable(^UniJsDocumentGetAttrCallback)(NSString *pageId, NSString *eleId, NSString *attrName);
typedef UniJsObjectType*_Nonnull(^UniJsDocumentGetBoundingClientRectCallback)(NSString *pageId, NSString* eleId);
typedef void(^UniJsDocumentRemoveElementCallback)(NSString *pageId, NSString* parentId, NSString* eleId);
typedef id<JSExport> __nullable(^UniJsDocumentGetJSExportCallback)(NSString *pageId, NSString* eleId);
typedef void(^UniJSDccumentWaitNativeRender)(NSString *pageId, void(^callback)(void));
typedef float (^UniJsDocumentGetOffsetCallback)(NSString *pageId, NSString* eleId, NSString* attr);
typedef void(^UniJSDccumentTakeSnapshot)(NSString *pageId, NSString* eleId, NSString* type, NSString* format, void(^success)(UniJsObjectType*), void(^fail)(UniJsObjectType*));


@interface UniJsBridgeImpl : NSObject {
    @private
    JSContext *_globalConext;
    UniUTSProxyManager *_proxyManager;
    NSMutableArray *_timers;
    NSMutableArray *_intervalTimers;
    NSMutableDictionary *_callbackMaps;
}
+(instancetype)shared;
-(void)create;
-(void)destroy;
-(void)loadFramework:(NSString*)framework;
-(void)loadFramework:(NSString*)framework withSourceURL:(NSString*)url;
-(id)callFunction:(NSString*)method withArguments:(NSArray*)argument;
-(id)evalJs:(NSString*)js;
-(void)registerPageApi:(UniJsPageCreateCallback)createCallback
                  show:(UniJsPageShowCallback)showCallback
                  hide:(UniJsPageHideCallback)hideCallback
               destroy:(UniJsPageDestoryCallback)destroyCallback
           startRender:(UniJsPageRenderCallback)renderCallback
        createDocument:(UniJsPageCreateDocumentCallback)createDocumentCallback
           updateStyle:(UniJsPageUpdateStyleCallback)updateStyleCallback
      addEventListener:(UniJsPageAddEventListenerCallback)eventListenerCallback
   removeEventListener:(UniJsPageRemoveEventListenerCallback)removeEventListenerCallback
              snaphost:(UniJsPageSnaphostCallback)snaphostCallback
          loadFontFace:(nonnull UniJsPageLoadFontFaceCallback)loadFontFace
            getDomJson:(UniJsPageGetDomJsonCallback)getDomJsonCallback
    viewToTempFilePath:(UniJSPageViewToTempFilePath)viewToTempFilePathCallback
    onPopGestureStart:(UniJSDccumentOnPopGestureStart)popGetstureStartCallback
    offPopGestureStart:(UniJSDccumentOffPopGestureStart)popGetstureStartCallback
  startPullDownRefresh:(UniJSPageStartPullDownRefresh)startPullDownRefreshCallback
   stopPullDownRefresh:(UniJSPageStopPullDownRefresh)stopPullDownRefreshCallback
setEnablePullDownRefresh:(UniJSPageStopSetEnablePullDownRefresh)setEnablePullDownRefreshCallback;

-(void)registerDocumentApi:(UniJsDocumentAddElementCallback)addElementCallback
             removeElement:(UniJsDocumentRemoveElementCallback)removeElement
          addEventListener:(UniJsDocumentAddEventListenerCallback)eventListenerCallback
       removeEventListener:(UniJsDocumentRemoveEventListenerCallback)removeEventListenerCallback
               updateStyle:(UniJsDocumentUpdateStyleCallback)updateStyleCallback
               updateAttrs:(UniJsDocumentUpdateAttrsCallback)updateAttrsCallback
        boundingClientRect:(UniJsDocumentGetBoundingClientRectCallback)boundingClientRectCallback
                 getOffset:(UniJsDocumentGetOffsetCallback)getOffsetCallback
               getElement:(UniJsDocumentGetJSExportCallback)getElementCallback
        getDrawableContext:(UniJsDocumentGetJSExportCallback)getDrawableContext
          waitNativeRender:(UniJSDccumentWaitNativeRender)waitNativeRenderCallback
              takeSnapshot:(UniJSDccumentTakeSnapshot)takeSnapshot
                   getAttr:(UniJsDocumentGetAttrCallback)getAttrCallback;


-(void)registerAppApi:(UniJsAppAddEventListenerCallback)addEventListenerCallback
  removeEventListener:(UniJsAppRemoveEventListenerCallback)removeEventListenerCallback
       reloadCallback:(UniJsAppReloadCallback)reloadCallback
         loadFontFace:(UniJsAppLoadFontFace)loadFontFace
       getExtElements:(UniJsAppGetExtElments)getExtElementsCallback
      getRedirectInfo:(UniJSAppGetRedirectInfo)getRedirectInfo
 updateStatusBarStyle:(UniJsAppUpdateStatusBarStyleCallback)updateStatusBarStyleCallback;

-(void)registerUTSChannelApi;
-(void)destoryPage:(NSString*)pageId;
-(void)registerGlobalObject:(id)object forName:(NSString*)name;
- (NSString*)getSysPath:(NSString*)filePath;
- (NSString*)getAppResoucePath;
-(bool)preventPopGestureStartWithPageId:(NSString*)pageId;
- (JSContext*)getContext;
- (void)onJsException:(NSString*)jsException;
@end

@interface JSValue(UniEvent)
- (JSValue *)dc_safeCallWithArguments:(NSArray*)arguments;
- (NSString*)dc_getEventIdentityAndRemoveByScope:(const NSString*)scope name:(const NSString*)name;
@end

NS_ASSUME_NONNULL_END
