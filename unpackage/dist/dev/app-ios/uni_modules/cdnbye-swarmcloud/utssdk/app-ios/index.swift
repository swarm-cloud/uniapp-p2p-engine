import DCloudUTSFoundation;
import DCloudUniappRuntime;
import SwarmCloudKit;
import Swift;
public var logArr = [
    LogLevel.VERBOSE,
    LogLevel.DEBUG,
    LogLevel.INFO,
    LogLevel.WARN,
    LogLevel.ERROR
];
public var zoneArr = [
    TrackerZone.Europe,
    TrackerZone.HongKong,
    TrackerZone.USA
];
@objc(UTSSDKModulesCdnbyeSwarmcloudConfigOptions)
@objcMembers
public class ConfigOptions : NSObject, UTSObject {
    public var p2pEnabled: Bool = false;
    public var useStrictHlsSegmentId: Bool = false;
    public var isSetTopBox: Bool = false;
    public var logEnabled: Bool = false;
    public var logLevel: NSNumber?;
    public var trackerZone: NSNumber?;
    public var downloadTimeout: NSNumber?;
    public var localPortHls: NSNumber?;
    public var localPortDash: NSNumber?;
    public var diskCacheLimit: NSNumber?;
    public var memoryCacheCountLimit: NSNumber?;
    public var maxPeerConnections: NSNumber?;
    public var useHttpRange: Bool = false;
    public var httpHeadersForHls: Map<String, String>?;
    public var httpHeadersForDash: Map<String, String>?;
    public var httpLoadTime: NSNumber?;
    public var sharePlaylist: Bool = false;
    public var insertTimeOffsetTag: NSNumber?;
    public var mediaFileSeparator: String?;
    public subscript(_ key: String) -> Any? {
        get {
            return utsSubscriptGetValue(key);
        }
        set {
            switch(key){
                case "p2pEnabled":
                    self.p2pEnabled = try! utsSubscriptCheckValue(newValue);
                case "useStrictHlsSegmentId":
                    self.useStrictHlsSegmentId = try! utsSubscriptCheckValue(newValue);
                case "isSetTopBox":
                    self.isSetTopBox = try! utsSubscriptCheckValue(newValue);
                case "logEnabled":
                    self.logEnabled = try! utsSubscriptCheckValue(newValue);
                case "logLevel":
                    self.logLevel = try! utsSubscriptCheckValueIfPresent(newValue);
                case "trackerZone":
                    self.trackerZone = try! utsSubscriptCheckValueIfPresent(newValue);
                case "downloadTimeout":
                    self.downloadTimeout = try! utsSubscriptCheckValueIfPresent(newValue);
                case "localPortHls":
                    self.localPortHls = try! utsSubscriptCheckValueIfPresent(newValue);
                case "localPortDash":
                    self.localPortDash = try! utsSubscriptCheckValueIfPresent(newValue);
                case "diskCacheLimit":
                    self.diskCacheLimit = try! utsSubscriptCheckValueIfPresent(newValue);
                case "memoryCacheCountLimit":
                    self.memoryCacheCountLimit = try! utsSubscriptCheckValueIfPresent(newValue);
                case "maxPeerConnections":
                    self.maxPeerConnections = try! utsSubscriptCheckValueIfPresent(newValue);
                case "useHttpRange":
                    self.useHttpRange = try! utsSubscriptCheckValue(newValue);
                case "httpHeadersForHls":
                    self.httpHeadersForHls = try! utsSubscriptCheckValueIfPresent(newValue);
                case "httpHeadersForDash":
                    self.httpHeadersForDash = try! utsSubscriptCheckValueIfPresent(newValue);
                case "httpLoadTime":
                    self.httpLoadTime = try! utsSubscriptCheckValueIfPresent(newValue);
                case "sharePlaylist":
                    self.sharePlaylist = try! utsSubscriptCheckValue(newValue);
                case "insertTimeOffsetTag":
                    self.insertTimeOffsetTag = try! utsSubscriptCheckValueIfPresent(newValue);
                case "mediaFileSeparator":
                    self.mediaFileSeparator = try! utsSubscriptCheckValueIfPresent(newValue);
                default:
                    break;
            }
        }
    }
    public override init() {
        super.init();
    }
    public init(_ obj: UTSJSONObject) {
        self.p2pEnabled = (obj["p2pEnabled"] as? Bool) ?? false;
        self.useStrictHlsSegmentId = (obj["useStrictHlsSegmentId"] as? Bool) ?? false;
        self.isSetTopBox = (obj["isSetTopBox"] as? Bool) ?? false;
        self.logEnabled = (obj["logEnabled"] as? Bool) ?? false;
        self.logLevel = obj["logLevel"] as! NSNumber?;
        self.trackerZone = obj["trackerZone"] as! NSNumber?;
        self.downloadTimeout = obj["downloadTimeout"] as! NSNumber?;
        self.localPortHls = obj["localPortHls"] as! NSNumber?;
        self.localPortDash = obj["localPortDash"] as! NSNumber?;
        self.diskCacheLimit = obj["diskCacheLimit"] as! NSNumber?;
        self.memoryCacheCountLimit = obj["memoryCacheCountLimit"] as! NSNumber?;
        self.maxPeerConnections = obj["maxPeerConnections"] as! NSNumber?;
        self.useHttpRange = (obj["useHttpRange"] as? Bool) ?? false;
        self.httpHeadersForHls = obj["httpHeadersForHls"] as! Map<String, String>?;
        self.httpHeadersForDash = obj["httpHeadersForDash"] as! Map<String, String>?;
        self.httpLoadTime = obj["httpLoadTime"] as! NSNumber?;
        self.sharePlaylist = (obj["sharePlaylist"] as? Bool) ?? false;
        self.insertTimeOffsetTag = obj["insertTimeOffsetTag"] as! NSNumber?;
        self.mediaFileSeparator = obj["mediaFileSeparator"] as! String?;
    }
}
public func initP2p(_ token: String, _ configOptions: ConfigOptions? = nil) -> Void {
    if (configOptions != nil) {
        var config = P2pConfig();
        if (configOptions!.p2pEnabled != nil) {
            config.p2pEnabled = configOptions!.p2pEnabled as! Bool;
        }
        if (configOptions!.useStrictHlsSegmentId != nil) {
            config.useStrictHlsSegmentId = configOptions!.useStrictHlsSegmentId as! Bool;
        }
        if (configOptions!.trackerZone != nil) {
            config.trackerZone = zoneArr[configOptions!.trackerZone as! NSNumber];
        }
        if (configOptions!.logEnabled != nil) {
            config.debug = configOptions!.logEnabled as! Bool;
        }
        if (configOptions!.logLevel != nil) {
            config.logLevel = logArr[configOptions!.logLevel as! NSNumber];
        }
        if (configOptions!.localPortHls != nil) {
            config.localPortHls = (configOptions!.localPortHls as! NSNumber).toUInt();
        }
        if (configOptions!.diskCacheLimit != nil) {
            config.diskCacheLimit = (configOptions!.diskCacheLimit as! NSNumber).toUInt();
        }
        if (configOptions!.memoryCacheCountLimit != nil) {
            config.memoryCacheCountLimit = (configOptions!.memoryCacheCountLimit as! NSNumber).toUInt();
        }
        if (configOptions!.maxPeerConnections != nil) {
            config.maxPeerConnections = (configOptions!.maxPeerConnections as! NSNumber).toInt();
        }
        if (configOptions!.useHttpRange != nil) {
            config.useHttpRange = configOptions!.useHttpRange as! Bool;
        }
        if (configOptions!.httpHeadersForHls != nil) {
            config.httpHeadersHls = configOptions!.httpHeadersForHls;
        }
        if (configOptions!.httpLoadTime != nil) {
            config.httpLoadTime = (configOptions!.httpLoadTime as! NSNumber).toDouble();
        }
        if (configOptions!.sharePlaylist != nil) {
            config.sharePlaylist = configOptions!.sharePlaylist as! Bool;
        }
        if (configOptions!.insertTimeOffsetTag != nil) {
            config.playlistTimeOffset = (configOptions!.insertTimeOffsetTag as! NSNumber).toDouble();
        }
        if (configOptions!.mediaFileSeparator != nil) {
            config.mediaFileSeparator = configOptions!.mediaFileSeparator as! String;
        }
        P2pEngine.setup(token: token, config: config);
    } else {
        P2pEngine.setup(token: token);
    }
    console.log("初始化完成", " at uni_modules/cdnbye-swarmcloud/utssdk/app-ios/index.uts:94");
}
public func getP2pUrl(_ url: String, _ videoId: String? = nil) -> String {
    var parseUrl: String;
    if (videoId != nil) {
        parseUrl = P2pEngine.shared.parseStreamUrl(url, videoId: videoId);
    } else {
        parseUrl = P2pEngine.shared.parseStreamUrl(url);
    }
    return parseUrl;
}
public func getP2pEngineVersion() -> String {
    return P2pEngine.VERSION;
}
public func p2pIsConnected() -> Bool {
    return P2pEngine.shared.isConnected;
}
public func stopP2p() -> Void {
    P2pEngine.shared.stopP2p();
}
public func restartP2p() -> Bool {
    return P2pEngine.shared.restartP2p();
}
public func peerId() -> String {
    return P2pEngine.shared.peerId;
}
public func disableP2p() -> Void {
    P2pEngine.shared.disableP2p();
}
public func enableP2p() -> Void {
    P2pEngine.shared.enableP2p();
}
public func shutdownP2p() -> Void {
    P2pEngine.shared.shutdown();
}
@objc(UTSSDKModulesCdnbyeSwarmcloudConfigOptionsJSONObject)
@objcMembers
public class ConfigOptionsJSONObject : NSObject {
    public var p2pEnabled: Bool = false;
    public var useStrictHlsSegmentId: Bool = false;
    public var isSetTopBox: Bool = false;
    public var logEnabled: Bool = false;
    public var logLevel: NSNumber?;
    public var trackerZone: NSNumber?;
    public var downloadTimeout: NSNumber?;
    public var localPortHls: NSNumber?;
    public var localPortDash: NSNumber?;
    public var diskCacheLimit: NSNumber?;
    public var memoryCacheCountLimit: NSNumber?;
    public var maxPeerConnections: NSNumber?;
    public var useHttpRange: Bool = false;
    public var httpHeadersForHls: Map<String, String>?;
    public var httpHeadersForDash: Map<String, String>?;
    public var httpLoadTime: NSNumber?;
    public var sharePlaylist: Bool = false;
    public var insertTimeOffsetTag: NSNumber?;
    public var mediaFileSeparator: String?;
}
public func initP2pByJs(_ token: String, _ configOptions: ConfigOptionsJSONObject? = nil) -> Void {
    return initP2p(token, configOptions != nil ? ConfigOptions(UTSJSONObject([
        "p2pEnabled": configOptions!.p2pEnabled,
        "useStrictHlsSegmentId": configOptions!.useStrictHlsSegmentId,
        "isSetTopBox": configOptions!.isSetTopBox,
        "logEnabled": configOptions!.logEnabled,
        "logLevel": configOptions!.logLevel,
        "trackerZone": configOptions!.trackerZone,
        "downloadTimeout": configOptions!.downloadTimeout,
        "localPortHls": configOptions!.localPortHls,
        "localPortDash": configOptions!.localPortDash,
        "diskCacheLimit": configOptions!.diskCacheLimit,
        "memoryCacheCountLimit": configOptions!.memoryCacheCountLimit,
        "maxPeerConnections": configOptions!.maxPeerConnections,
        "useHttpRange": configOptions!.useHttpRange,
        "httpHeadersForHls": configOptions!.httpHeadersForHls,
        "httpHeadersForDash": configOptions!.httpHeadersForDash,
        "httpLoadTime": configOptions!.httpLoadTime,
        "sharePlaylist": configOptions!.sharePlaylist,
        "insertTimeOffsetTag": configOptions!.insertTimeOffsetTag,
        "mediaFileSeparator": configOptions!.mediaFileSeparator
    ])) : nil);
}
public func getP2pUrlByJs(_ url: String, _ videoId: String? = nil) -> String {
    return getP2pUrl(url, videoId);
}
public func getP2pEngineVersionByJs() -> String {
    return getP2pEngineVersion();
}
public func p2pIsConnectedByJs() -> Bool {
    return p2pIsConnected();
}
public func stopP2pByJs() -> Void {
    return stopP2p();
}
public func restartP2pByJs() -> Bool {
    return restartP2p();
}
public func peerIdByJs() -> String {
    return peerId();
}
public func disableP2pByJs() -> Void {
    return disableP2p();
}
public func enableP2pByJs() -> Void {
    return enableP2p();
}
public func shutdownP2pByJs() -> Void {
    return shutdownP2p();
}
@objc(UTSSDKModulesCdnbyeSwarmcloudIndexSwift)
@objcMembers
public class UTSSDKModulesCdnbyeSwarmcloudIndexSwift : NSObject {
    public static func s_initP2pByJs(_ token: String, _ configOptions: ConfigOptionsJSONObject? = nil) -> Void {
        return initP2pByJs(token, configOptions);
    }
    public static func s_getP2pUrlByJs(_ url: String, _ videoId: String? = nil) -> String {
        return getP2pUrlByJs(url, videoId);
    }
    public static func s_getP2pEngineVersionByJs() -> String {
        return getP2pEngineVersionByJs();
    }
    public static func s_p2pIsConnectedByJs() -> Bool {
        return p2pIsConnectedByJs();
    }
    public static func s_stopP2pByJs() -> Void {
        return stopP2pByJs();
    }
    public static func s_restartP2pByJs() -> Bool {
        return restartP2pByJs();
    }
    public static func s_peerIdByJs() -> String {
        return peerIdByJs();
    }
    public static func s_disableP2pByJs() -> Void {
        return disableP2pByJs();
    }
    public static func s_enableP2pByJs() -> Void {
        return enableP2pByJs();
    }
    public static func s_shutdownP2pByJs() -> Void {
        return shutdownP2pByJs();
    }
}
