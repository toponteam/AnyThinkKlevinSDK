//
//  KLNSplashAd.h
//  KlevinAdSDK
//
//  Copyright © 2022 Tencent. All rights reserved.
//  Created by Klevin on 2022/2/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <KlevinAdSDK/KLNAdRequest.h>
#import <KlevinAdSDK/KLNAdVideoController.h>
#import <KlevinAdSDK/KLNAdBiddingProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class KLNSplashAd;

typedef NS_ENUM(NSUInteger, KLNSplashAdType) {
    /// 未知模版
    KLNSplashAdTypeUnknown = 1,
    /// 竖版9:16开屏大图
    KLNSplashAdTypeVerImage = 2001,
    /// 竖版9:16开屏视频
    KLNSplashAdTypeVerVideo = 2002,
    
};

@protocol KLNSplashAdDelegate;

/// 加载开屏广告回调。
/// 成功时，splashAd不为nil, error为nil。失败时，splashAd为nil，error不为nil。
typedef void (^KLNSplashAdLoadCompletionHandler)(KLNSplashAd *_Nullable splashAd,
                                                  NSError *_Nullable error);

/// 新版开屏广告2.0。请注意，在主线程中使用该类！！
@interface KLNSplashAd : NSObject<KLNAdBiddingProtocol>

/// 广告事件回调对象
@property (nonatomic, weak, nullable) id<KLNSplashAdDelegate> delegate;

/// 开发者传入的用来present目标页的ViewController，必传
@property (nonatomic, weak, readwrite) UIViewController *viewController;

/// 广告类型
@property (nonatomic, readonly) KLNSplashAdType adType;

/// 是否隐藏SDK跳过按钮，如果隐藏，接入方必须自定义跳过按钮。默认为NO。
/// 请注意：请在获取adView之前设置改属性
@property (nonatomic, assign) BOOL hideSkipButton;

/// 视频播放器
@property (nonatomic, strong, readonly, nullable) KLNAdVideoController *videoController;

/// 广告view
@property (nonatomic, strong, readonly) UIView *adView;

/// 加载开屏广告方法
/// @param request 开屏广告请求对象
/// @param completionHandler 广告加载结果回调（成功/失败），请注意：回调非线程安全
+ (void)loadWithRequest:(nonnull KLNSplashAdRequest *)request
      completionHandler:(KLNSplashAdLoadCompletionHandler)completionHandler;

/// 关闭广告时，建议先调用该方法释放资源。比如停止倒计时，自定义跳过按钮时停止视频播放
/// 请注意：在主线程调用该方法
- (void)removeSplashAd;

@end


@protocol KLNSplashAdDelegate <NSObject>

@optional

/// 广告曝光回调
/// 业务方可以通过实现该方法，统计｜曝光｜量（对账）
/// @param ad  KLNNewSplashAd 实例
- (void)kln_splashAdWillExpose:(KLNSplashAd *)ad;

/// 广告点击回调
/// 业务方可以通过实现该方法，统计｜点击｜量（对账）
/// @param ad KLNNewSplashAd 实例
- (void)kln_splashAdDidClick:(KLNSplashAd *)ad;

/// 广告被关闭
/// @param ad  KLNTemplateAd 实例
- (void)kln_splashAdClosed:(KLNSplashAd *)ad;

/// 广告点击跳过回调
/// @param ad  KLNNewSplashAd 实例
- (void)kln_splashAdClickSkip:(KLNSplashAd *)ad;

@end

NS_ASSUME_NONNULL_END
