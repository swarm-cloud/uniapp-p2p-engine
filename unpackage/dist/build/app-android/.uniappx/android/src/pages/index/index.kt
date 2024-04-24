@file:Suppress("UNCHECKED_CAST", "USELESS_CAST", "INAPPLICABLE_JVM_NAME")
package uni.UNI1EF92C5;
import io.dcloud.uniapp.*;
import io.dcloud.uniapp.extapi.*;
import io.dcloud.uniapp.framework.*;
import io.dcloud.uniapp.runtime.*;
import io.dcloud.uniapp.vue.*;
import io.dcloud.uniapp.vue.shared.*;
import io.dcloud.uts.*;
import io.dcloud.uts.Map;
import io.dcloud.uts.Set;
import io.dcloud.uts.UTSAndroid;
import kotlinx.coroutines.CoroutineScope;
import kotlinx.coroutines.Deferred;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.async;
import uts.sdk.modules.cdnbyeSwarmcloud.ConfigOptions;
import uts.sdk.modules.cdnbyeSwarmcloud.initP2p;
import uts.sdk.modules.cdnbyeSwarmcloud.getP2pUrl;
import uts.sdk.modules.cdnbyeSwarmcloud.getP2pEngineVersion;
import uts.sdk.modules.cdnbyeSwarmcloud.p2pIsConnected;
import uts.sdk.modules.cdnbyeSwarmcloud.stopP2p;
import io.dcloud.uniapp.extapi.createVideoContext as uni_createVideoContext;
open class GenPagesIndexIndex : BasePage {
    constructor(instance: ComponentInternalInstance) : super(instance) {
        onReady(fun() {
            this.videoContext = uni_createVideoContext("video", this);
        }
        , instance);
        onLoad(fun(_: OnLoadOptions) {}, instance);
        onPageShow(fun() {}, instance);
    }
    @Suppress("UNUSED_PARAMETER", "UNUSED_VARIABLE")
    override fun `$render`(): Any? {
        val _ctx = this;
        val _cache = this.`$`.renderCache;
        return createElementVNode("view", utsMapOf("class" to "content"), utsArrayOf(
            createElementVNode("video", utsMapOf("class" to "video", "ref" to "video", "id" to "video", "header" to _ctx.header, "src" to _ctx.src, "onError" to _ctx.onError, "controls" to true), null, 40, utsArrayOf(
                "header",
                "src",
                "onError"
            )),
            createElementVNode("button", utsMapOf("type" to "primary", "onClick" to _ctx.initCdnbye), "初始化cdnbye", 8, utsArrayOf(
                "onClick"
            )),
            createElementVNode("button", utsMapOf("onClick" to _ctx.startPlay), "p2p播放", 8, utsArrayOf(
                "onClick"
            )),
            createElementVNode("button", utsMapOf("onClick" to _ctx.stop), "停止播放", 8, utsArrayOf(
                "onClick"
            )),
            createElementVNode("button", utsMapOf("onClick" to _ctx.stopP2p), "停止P2P", 8, utsArrayOf(
                "onClick"
            )),
            createElementVNode("button", utsMapOf("onClick" to _ctx.isConnected), "是否CDNBye连接", 8, utsArrayOf(
                "onClick"
            ))
        ));
    }
    open var videoContext: VideoContext? by `$data`;
    open var header: UTSJSONObject by `$data`;
    open var src: String by `$data`;
    open var oldsrc: String by `$data`;
    @Suppress("USELESS_CAST")
    override fun data(): Map<String, Any?> {
        return utsMapOf("videoContext" to null as VideoContext?, "header" to object : UTSJSONObject() {
            var `User-Agent` = "User-Agent test"
            var header = "header test"
            var cookie = "cookie test"
        }, "src" to "", "oldsrc" to "https://s5.bfengbf.com/video/17haoyinlecangkudierji/20240216/index.m3u8");
    }
    override fun `$initMethods`() {
        this.initCdnbye = fun() {
            var options = ConfigOptions(logEnabled = true, logLevel = 1, trackerZone = 0);
            initP2p("4-iRPC_GR", options);
            console.log(getP2pEngineVersion(), " at pages/index/index.uvue:38");
        }
        ;
        this.startPlay = fun() {
            this.src = getP2pUrl(this.oldsrc);
            console.log(this.src, " at pages/index/index.uvue:44");
            this.videoContext?.play();
        }
        ;
        this.isConnected = fun() {
            console.log(p2pIsConnected(), " at pages/index/index.uvue:54");
        }
        ;
        this.stopP2p = fun() {
            stopP2p();
        }
        ;
        this.stop = fun() {
            this.videoContext?.stop();
        }
        ;
        this.onError = fun(res: UniVideoErrorEvent) {
            console.log(res.type + " -> " + JSON.stringify(res.detail), " at pages/index/index.uvue:64");
        }
        ;
    }
    open lateinit var initCdnbye: () -> Unit;
    open lateinit var startPlay: () -> Unit;
    open lateinit var isConnected: () -> Unit;
    open lateinit var stopP2p: () -> Unit;
    open lateinit var stop: () -> Unit;
    open lateinit var onError: (res: UniVideoErrorEvent) -> Unit;
    companion object {
        val styles: Map<String, Map<String, Map<String, Any>>>
            get() {
                return normalizeCssStyles(utsArrayOf(
                    styles0
                ), utsArrayOf(
                    GenApp.styles
                ));
            }
        val styles0: Map<String, Map<String, Map<String, Any>>>
            get() {
                return utsMapOf("content" to padStyleMapOf(utsMapOf("display" to "flex", "alignItems" to "center", "justifyContent" to "center")), "logo" to padStyleMapOf(utsMapOf("height" to "200rpx", "width" to "200rpx", "marginTop" to "200rpx", "marginBottom" to "50rpx")), "title" to padStyleMapOf(utsMapOf("fontSize" to "36rpx", "color" to "#8f8f94")));
            }
        var inheritAttrs = true;
        var inject: Map<String, Map<String, Any?>> = utsMapOf();
        var emits: Map<String, Any?> = utsMapOf();
        var props = normalizePropsOptions(utsMapOf());
        var propsNeedCastKeys: UTSArray<String> = utsArrayOf();
        var components: Map<String, CreateVueComponent> = utsMapOf();
    }
}
