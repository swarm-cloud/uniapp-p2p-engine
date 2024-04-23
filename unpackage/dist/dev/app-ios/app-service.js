(function (vue) {
	'use strict';

	const { registerUTSInterface, initUTSProxyClass, initUTSProxyFunction, initUTSPackageName, initUTSIndexClassName, initUTSClassName } = uni;
	const name = 'xtfSwarmcloud';
	const moduleName = 'xtf-swarmcloud';
	const moduleType = '';
	const errMsg = ``;
	const is_uni_modules = true;
	const pkg = /*#__PURE__*/ initUTSPackageName(name, is_uni_modules);
	const cls = /*#__PURE__*/ initUTSIndexClassName(name, is_uni_modules);



	const initP2p = /*#__PURE__*/ initUTSProxyFunction(false, { moduleName, moduleType, errMsg, main: true, package: pkg, class: cls, name: 'initP2pByJs', params: [{"name":"token","type":"string"},{"name":"configOptions","type":"UTSSDKModulesXtfSwarmcloudConfigOptionsJSONObject","default":"UTSNull"}], return: ""});
	const getP2pUrl = /*#__PURE__*/ initUTSProxyFunction(false, { moduleName, moduleType, errMsg, main: true, package: pkg, class: cls, name: 'getP2pUrlByJs', params: [{"name":"url","type":"string"},{"name":"videoId","type":"","default":"UTSNull"}], return: ""});
	const getP2pEngineVersion = /*#__PURE__*/ initUTSProxyFunction(false, { moduleName, moduleType, errMsg, main: true, package: pkg, class: cls, name: 'getP2pEngineVersionByJs', params: [], return: ""});
	const p2pIsConnected = /*#__PURE__*/ initUTSProxyFunction(false, { moduleName, moduleType, errMsg, main: true, package: pkg, class: cls, name: 'p2pIsConnectedByJs', params: [], return: ""});
	const shutdownP2p = /*#__PURE__*/ initUTSProxyFunction(false, { moduleName, moduleType, errMsg, main: true, package: pkg, class: cls, name: 'shutdownP2pByJs', params: [], return: ""});

	const _sfc_main$1 = vue.defineComponent({
	    onReady() {
	        //注意uniappx 的video组建ios没有实现 请自行更换其他播放器
	        this.videoContext = uni.createVideoContext('video', this);
	    },
	    data() {
	        return {
	            videoContext: null,
	            header: new UTSJSONObject({
	                'User-Agent': 'User-Agent test',
	                'header': 'header test',
	                'cookie': 'cookie test'
	            }),
	            // 属性
	            src: "",
	            oldsrc: "https://s5.bfengbf.com/video/17haoyinlecangkudierji/20240216/index.m3u8",
	        };
	    },
	    onLoad() {
	    },
	    onShow() {
	    },
	    methods: {
	        initCdnbye: function () {
	            let options = {
	                logEnabled: true,
	                logLevel: 1,
	                trackerZone: 0
	            };
	            initP2p("4-iRPC_GR", options);
	            uni.__log__('log', 'at pages/index/index.uvue:52', getP2pEngineVersion());
	        },
	        startPlay() {
	            var _a;
	            this.src = getP2pUrl(this.oldsrc);
	            uni.__log__('log', 'at pages/index/index.uvue:58', this.src);
	            (_a = this.videoContext) === null || _a === void 0 ? void 0 : _a.play();
	        },
	        isConnected() {
	            //开始播放了才为true
	            uni.__log__('log', 'at pages/index/index.uvue:68', p2pIsConnected());
	        },
	        stopP2p() {
	            shutdownP2p();
	        },
	        stop() {
	            var _a;
	            (_a = this.videoContext) === null || _a === void 0 ? void 0 : _a.stop();
	        },
	        onError: function (res) {
	            uni.__log__('log', 'at pages/index/index.uvue:78', res.type + " -> " + UTS.JSON.stringify(res.detail));
	        },
	    }
	});

	const _style_0$1 = {"content":{"":{"display":"flex","alignItems":"center","justifyContent":"center"}},"logo":{"":{"height":"200rpx","width":"200rpx","marginTop":"200rpx","marginBottom":"50rpx"}},"title":{"":{"fontSize":"36rpx","color":"#8f8f94"}}};

	const _export_sfc = (sfc, props) => {
	  const target = sfc.__vccOpts || sfc;
	  for (const [key, val] of props) {
	    target[key] = val;
	  }
	  return target;
	};

	function _sfc_render(_ctx, _cache) {
	  return vue.openBlock(), vue.createElementBlock("view", { class: "content" }, [
	    vue.createElementVNode("video", {
	      class: "video",
	      ref: "video",
	      id: "video",
	      header: _ctx.header,
	      src: _ctx.src,
	      onError: _cache[0] || (_cache[0] = (...args) => _ctx.onError && _ctx.onError(...args)),
	      controls: true
	    }, null, 40, ["header", "src"]),
	    vue.createElementVNode("button", {
	      type: "primary",
	      onClick: _cache[1] || (_cache[1] = (...args) => _ctx.initCdnbye && _ctx.initCdnbye(...args))
	    }, "\u521D\u59CB\u5316cdnbye"),
	    vue.createElementVNode("button", {
	      onClick: _cache[2] || (_cache[2] = (...args) => _ctx.startPlay && _ctx.startPlay(...args))
	    }, "p2p\u64AD\u653E"),
	    vue.createElementVNode("button", {
	      onClick: _cache[3] || (_cache[3] = (...args) => _ctx.stop && _ctx.stop(...args))
	    }, "\u505C\u6B62\u64AD\u653E"),
	    vue.createElementVNode("button", {
	      onClick: _cache[4] || (_cache[4] = (...args) => _ctx.stopP2p && _ctx.stopP2p(...args))
	    }, "\u505C\u6B62P2P"),
	    vue.createElementVNode("button", {
	      onClick: _cache[5] || (_cache[5] = (...args) => _ctx.isConnected && _ctx.isConnected(...args))
	    }, "\u662F\u5426CDNBye\u8FDE\u63A5")
	  ]);
	}
	const PagesIndexIndex = /* @__PURE__ */ _export_sfc(_sfc_main$1, [["render", _sfc_render], ["styles", [_style_0$1]], ["__file", "/Users/taifuxia/Documents/HBuilderProjects/sctest/pages/index/index.uvue"]]);

	__definePage('pages/index/index',PagesIndexIndex);

	const _sfc_main = vue.defineComponent({
	    onLaunch: function () {
	        uni.__log__('log', 'at App.uvue:5', 'App Launch');
	    },
	    onShow: function () {
	        uni.__log__('log', 'at App.uvue:8', 'App Show');
	    },
	    onHide: function () {
	        uni.__log__('log', 'at App.uvue:11', 'App Hide');
	    },
	    onExit: function () {
	        uni.__log__('log', 'at App.uvue:32', 'App Exit');
	    },
	});

	const _style_0 = {"uni-row":{"":{"flexDirection":"row"}},"uni-column":{"":{"flexDirection":"column"}}};

	const App = /* @__PURE__ */ _export_sfc(_sfc_main, [["styles", [_style_0]], ["__file", "/Users/taifuxia/Documents/HBuilderProjects/sctest/App.uvue"]]);

	const __global__ = typeof globalThis === 'undefined' ? Function('return this')() : globalThis;
	__global__.__uniX = true;
	function createApp() {
	    const app = vue.createSSRApp(App);
	    return {
	        app
	    };
	}
	createApp().app.mount("#app");

})(Vue);
