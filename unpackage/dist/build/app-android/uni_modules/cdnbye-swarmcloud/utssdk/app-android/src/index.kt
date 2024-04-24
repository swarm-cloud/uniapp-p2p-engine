@file:Suppress("UNCHECKED_CAST", "USELESS_CAST", "INAPPLICABLE_JVM_NAME")
package uts.sdk.modules.cdnbyeSwarmcloud;
import com.p2pengine.core.p2p.P2pConfig;
import com.p2pengine.core.segment.StrictHlsSegmentIdGenerator;
import com.p2pengine.core.tracking.TrackerZone;
import com.p2pengine.core.utils.LogLevel;
import com.p2pengine.sdk.MimeType;
import com.p2pengine.sdk.P2pEngine;
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
import java.util.concurrent.TimeUnit;
import kotlinx.coroutines.CoroutineScope;
import kotlinx.coroutines.Deferred;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.async;
var logArr = utsArrayOf(
    LogLevel.VERBOSE,
    LogLevel.DEBUG,
    LogLevel.INFO,
    LogLevel.WARN,
    LogLevel.ERROR
);
var zoneArr = utsArrayOf(
    TrackerZone.Europe,
    TrackerZone.HongKong,
    TrackerZone.USA
);
open class ConfigOptions (
    open var p2pEnabled: Boolean? = null,
    open var useStrictHlsSegmentId: Boolean? = null,
    open var isSetTopBox: Boolean? = null,
    open var logEnabled: Boolean? = null,
    open var logLevel: Number? = null,
    open var trackerZone: Number? = null,
    open var downloadTimeout: Number? = null,
    open var localPortHls: Number? = null,
    open var localPortDash: Number? = null,
    open var diskCacheLimit: Number? = null,
    open var memoryCacheCountLimit: Number? = null,
    open var maxPeerConnections: Number? = null,
    open var useHttpRange: Boolean? = null,
    open var httpHeadersForHls: Map<String, String>? = null,
    open var httpHeadersForDash: Map<String, String>? = null,
    open var httpLoadTime: Number? = null,
    open var sharePlaylist: Boolean? = null,
    open var insertTimeOffsetTag: Number? = null,
    open var mediaFileSeparator: String? = null,
) : UTSObject()
fun initP2p(token: String, configOptions: ConfigOptions? = null): Unit {
    var configBuilder = P2pConfig.Builder();
    if (configOptions != null) {
        if (configOptions.p2pEnabled != null) {
            configBuilder = configBuilder.p2pEnabled(configOptions.p2pEnabled as Boolean);
        }
        if (configOptions.useStrictHlsSegmentId != null) {
            configBuilder = configBuilder.useStrictHlsSegmentId(configOptions.useStrictHlsSegmentId as Boolean);
        }
        if (configOptions.isSetTopBox != null) {
            configBuilder = configBuilder.isSetTopBox(configOptions.isSetTopBox as Boolean);
        }
        if (configOptions.logEnabled != null) {
            configBuilder = configBuilder.logEnabled(configOptions.logEnabled as Boolean);
        }
        if (configOptions.logLevel != null) {
            configBuilder = configBuilder.logLevel(logArr[configOptions.logLevel as Number]);
        }
        if (configOptions.trackerZone != null) {
            configBuilder = configBuilder.trackerZone(zoneArr[configOptions.trackerZone as Number]);
        }
        if (configOptions.downloadTimeout != null) {
            configBuilder = configBuilder.downloadTimeout((configOptions.downloadTimeout as Number).toInt(), TimeUnit.MILLISECONDS);
        }
        if (configOptions.localPortHls != null) {
            configBuilder = configBuilder.localPortHls((configOptions.localPortHls as Number).toInt());
        }
        if (configOptions.localPortDash != null) {
            configBuilder = configBuilder.localPortDash((configOptions.localPortDash as Number).toInt());
        }
        if (configOptions.diskCacheLimit != null) {
            configBuilder = configBuilder.diskCacheLimit((configOptions.diskCacheLimit as Number).toLong());
        }
        if (configOptions.memoryCacheCountLimit != null) {
            configBuilder = configBuilder.memoryCacheCountLimit((configOptions.memoryCacheCountLimit as Number).toInt());
        }
        if (configOptions.maxPeerConnections != null) {
            configBuilder = configBuilder.maxPeerConnections((configOptions.maxPeerConnections as Number).toInt());
        }
        if (configOptions.useHttpRange != null) {
            configBuilder = configBuilder.useHttpRange(configOptions.useHttpRange as Boolean);
        }
        if (configOptions.httpHeadersForHls != null) {
            configBuilder = configBuilder.httpHeadersForHls(configOptions.httpHeadersForHls as Map<String, String>);
        }
        if (configOptions.httpHeadersForDash != null) {
            configBuilder = configBuilder.httpHeadersForDash(configOptions.httpHeadersForDash as Map<String, String>);
        }
        if (configOptions.httpLoadTime != null) {
            configBuilder = configBuilder.httpLoadTime(((configOptions.httpLoadTime as Number) * 1000).toLong());
        }
        if (configOptions.sharePlaylist != null) {
            configBuilder = configBuilder.sharePlaylist(configOptions.sharePlaylist as Boolean);
        }
        if (configOptions.insertTimeOffsetTag != null) {
            configBuilder = configBuilder.insertTimeOffsetTag((configOptions.insertTimeOffsetTag as Number).toDouble());
        }
        if (configOptions.mediaFileSeparator != null) {
            configBuilder = configBuilder.mediaFileSeparator(configOptions.mediaFileSeparator as String);
        }
    }
    var config = configBuilder.build();
    P2pEngine.init(UTSAndroid.getAppContext()!!, token, config);
}
fun setHlsSegmentIdGenerator(): Unit {
    P2pEngine.instance?.setHlsSegmentIdGenerator(StrictHlsSegmentIdGenerator());
}
fun getP2pUrl(url: String, videoId: String? = null, mimeType: String? = null): String {
    var parseUrl: String;
    if (videoId != null) {
        if (mimeType != null) {
            when (mimeType) {
                "m3u8" -> 
                    parseUrl = P2pEngine.instance!!.parseStreamUrl(url, videoId, MimeType.APPLICATION_M3U8);
                "mpd" -> 
                    parseUrl = P2pEngine.instance!!.parseStreamUrl(url, videoId, MimeType.APPLICATION_MPD);
                else -> 
                    parseUrl = P2pEngine.instance!!.parseStreamUrl(url, videoId);
            }
        } else {
            parseUrl = P2pEngine.instance!!.parseStreamUrl(url, videoId);
        }
    } else {
        parseUrl = P2pEngine.instance!!.parseStreamUrl(url);
    }
    return parseUrl;
}
fun getP2pEngineVersion(): String {
    return P2pEngine.version;
}
fun p2pIsConnected(): Boolean {
    return P2pEngine.instance!!.isConnected;
}
fun stopP2p(): Unit {
    P2pEngine.instance!!.stopP2p();
}
fun restartP2p(): Boolean {
    return P2pEngine.instance!!.restartP2p();
}
fun peerId(): String {
    return P2pEngine.instance!!.peerId;
}
fun setHttpHeadersForHls(headers: Map<String, String>): Unit {
    P2pEngine.instance!!.setHttpHeadersForHls(headers);
}
fun setHttpHeadersForDash(headers: Map<String, String>): Unit {
    P2pEngine.instance!!.setHttpHeadersForDash(headers);
}
fun disableP2p(): Unit {
    P2pEngine.instance!!.disableP2p();
}
fun enableP2p(): Unit {
    P2pEngine.instance!!.enableP2p();
}
fun shutdownP2p(): Unit {
    P2pEngine.instance!!.shutdown();
}
