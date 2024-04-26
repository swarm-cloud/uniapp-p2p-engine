<h1 align="center"><a href="" target="_blank" rel="noopener noreferrer"><img width="250" src="https://www.cdnbye.com/img/logo.png" alt="logo"></a></h1>
<h4 align="center">UniappX 视频/直播APP省流量&加速引擎</h4>


该插件的优势如下：
- 支持iOS和安卓平台，可与[Web端插件](https://gitee.com/cdnbye/hlsjs-p2p-engine)P2P互通
- 支持基于HLS流媒体协议(m3u8)的直播和点播场景
- 支持加密HLS传输
- 支持ts文件缓存从而避免重复下载
- 几行代码即可在现有uniappx项目中快速集成
- 支持任何播放器
- 通过预加载形式实现P2P加速，完全不影响用户的播放体验
- 高可配置化，用户可以根据特定的使用环境调整各个参数
- 通过有效的调度策略来保证用户的播放体验以及p2p分享率

## 使用方法
1，导入uts插件
```javascript
import { ConfigOptions,initP2p,getP2pUrl,getP2pEngineVersion,p2pIsConnected,stopP2p } from "@/uni_modules/cdnbye-swarmcloud";
```

2，初始化插件，必须先初始化再调用其他方法 否则报错
```javascript
//token去官网获取
let token="";
//构造配置项
let options = {
   logEnabled: true,
   logLevel: 1,
   trackerZone:0
 } as ConfigOptions;
// 初始化    options可不传使用默认配置
initP2p(token, options);
```

3，获取P2P播放地址
```javascript
//正常播放地址
let playUrl="https://s5.bfengbf.com/video/17haoyinlecangkudierji/20240216/index.m3u8";
//p2p地址
let p2pPlayUrl = getP2pUrl(playUrl);
console.log(p2pPlayUrl);
//将p2pPlayUrl给播放器
```

## 配置项
```javascript
export type ConfigOptions = {
  p2pEnabled?: boolean,// 开启或关闭p2p engine 默认true
  useStrictHlsSegmentId?: boolean,//使用基于url的SegmentId，替代默认基于序列号的 默认false
  isSetTopBox?: boolean,// 如果运行于机顶盒请设置成true 默认false 安卓有 ios没有
  logEnabled?: boolean,// 是否打印日志 默认false
  logLevel?: number,// 打印日志的级别0:VERBOSE,1:DEBUG,2:INFO,3:WARN,4:ERROR 默认3
  trackerZone?:number,// tracker服务器地址所在国家的枚举，分为0:Europe,1:HongKong,2:USA 默认0
  downloadTimeout?:number,// HTTP下载ts文件超时时间  默认30000ms 安卓有 ios没有
  localPortHls?:number,// HLS本地代理服务器的端口号(默认随机端口)
  localPortDash?:number,// DASH本地代理服务器的端口号(默认随机端口) 安卓有 ios没有
  diskCacheLimit?:number,// 点播模式下P2P在磁盘缓存的最大数据量(设为0可以禁用磁盘缓存) 默认2000*1024*1024
  memoryCacheCountLimit?:number,// P2P在内存缓存的最大数据量，用ts文件个数表示 默认15
  maxPeerConnections?:number,// 最大连接节点数量 默认25
  useHttpRange?:boolean,// 在可能的情况下使用Http Range请求来补足p2p下载超时的剩余部分数据 默认true
  httpHeadersForHls?:Map<string,string>,// 设置请求ts和m3u8时的HTTP请求头 默认null
  httpHeadersForDash?:Map<string,string>,// 设置请求Dash文件时的HTTP请求头 默认null 安卓有 ios没有
  httpLoadTime?:number,// P2P下载超时后留给HTTP下载的时间 默认3s
  sharePlaylist?:boolean,// 是否允许m3u8文件的P2P传输 默认false
  insertTimeOffsetTag?:number,// 仅在直播模式生效，在m3u8文件中插入 "#EXT-X-START:TIME-OFFSET=[timeOffset]"，强制播放器从某个位置开始加载，其中 [timeOffset] 是在播放列表的偏移量，如果为负则从播放列表结尾往前偏移（单位：秒）
  mediaFileSeparator?:string,// 媒体文件后缀分隔符 默认“.”
}
```

## API
```javascript
//初始化
function initP2p (token:string,configOptions:ConfigOptions|null=null):void

//如果媒体文件是由多个服务器生成的，为避免冲突，请调用此函数：
function setHlsSegmentIdGenerator():void

//将url转换成p2pUrl
//除了原始播放地址(m3u8/mpd)，同时传入videoId用以构造channelId
//除了原始播放地址(m3u8/mpd)以及videoId，同时传入mimeType（目前支持MimeType.APPLICATION_M3U8和MimeType.APPLICATION_MPD），用于无".m3u8"或".mpd"后缀的url。传入字符串m3u8或mpd
function  getP2pUrl(url : string,videoId:string|null=null,mimeType:string|null=null) : string

//当前插件的版本号。
function getP2pEngineVersion():string

//是否已与CDNBye后台建立连接。
function p2pIsConnected():boolean

//立即停止P2P加速并释放资源，一般只需要在退出APP的时候调用即可。SDK采用"懒释放"的策略，只有在重启p2p的时候才释放资源。对于性能较差的设备起播耗时可能比较明显，建议在视频播放之前提前调用 engine.stopP2p() 。
function stopP2p():void

//重启P2P加速服务，一般不需要调用。
function restartP2p():boolean

//获取对等连接的id。
function peerId():string

//动态设置请求ts和m3u8时的HTTP请求头。仅安卓
function setHttpHeadersForHls(headers: Map<String, String>):void

//动态设置请求Dash文件时的HTTP请求头。仅安卓
function setHttpHeadersForDash(headers: Map<String, String>):void

//运行时动态关闭P2P，在播放下一个媒体文件时才生效。
function disableP2p():void

//运行时动态开启P2P，在播放下一个媒体文件时才生效。
function enableP2p():void

//停止P2P并关闭代理服务器。
function shutdownP2p():void
```

## 获取Token
参考[如何获取token](https://www.cdnbye.com/cn/bindings.html#%E7%BB%91%E5%AE%9A-app-id-%E5%B9%B6%E8%8E%B7%E5%8F%96token)

## 控制台
登录 https://oms.cdnbye.com 并绑定 APPId, 即可查看P2P效果、在线人数等信息。

## 反馈及意见
当你遇到任何问题时，可以通过在 GitHub 的 repo 提交 issues 来反馈问题，请尽可能的描述清楚遇到的问题，如果有错误信息也一同附带，并且在 Labels 中指明类型为 bug 或者其他。

## FAQ
我们收集了一些[常见问题](https://www.cdnbye.com/faq.html)。在报告issue之前请先查看一下。

## 联系我们
邮箱：service@cdnbye.com
