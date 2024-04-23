@file:Suppress("UNCHECKED_CAST", "USELESS_CAST", "INAPPLICABLE_JVM_NAME")
package uts.sdk.modules.xtfSwarmcloud;
import com.p2pengine.core.p2p.P2pConfig;
import com.p2pengine.core.tracking.TrackerZone;
import com.p2pengine.core.utils.LogLevel;
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
enum class MyLogLevel(override val value: Int) : UTSEnumInt {
    VERBOSE(0),
    DEBUG(1),
    INFO(2),
    WARN(3),
    ERROR(4)
}
enum class MyTrackerZone(override val value: Int) : UTSEnumInt {
    Europe(0),
    HongKong(2),
    USA(3)
}
open class ConfigOptions (
    open var logEnabled: Boolean? = null,
    open var logLevel: Number? = null,
    open var trackerZone: Number? = null,
) : UTSObject()
fun initP2p(token: String, configOptions: ConfigOptions?): Unit {
    var configBuilder = P2pConfig.Builder();
    if (configOptions != null) {
        if (configOptions.logEnabled != null) {
            configBuilder = configBuilder.logEnabled(configOptions.logEnabled as Boolean);
        }
        if (configOptions.logLevel != null) {
            console.log(UTSAndroid.`typeof`( configOptions.logLevel), " at uni_modules/xtf-swarmcloud/utssdk/app-android/index.uts:36");
            configBuilder = configBuilder.logLevel(logArr[configOptions.logLevel as Number]);
        }
        if (configOptions.trackerZone != null) {
            configBuilder = configBuilder.trackerZone(zoneArr[configOptions.trackerZone as Number]);
        }
    }
    var config = configBuilder.build();
    P2pEngine.init(UTSAndroid.getAppContext()!!, token, config);
}
fun p2pUrl(url: String): String {
    return P2pEngine.instance!!.parseStreamUrl(url);
}
