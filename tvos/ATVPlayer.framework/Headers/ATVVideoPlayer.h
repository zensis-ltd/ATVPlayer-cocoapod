//
//  ATVVideoPlayer.h
//  ATVPlayer SDK
//
//  Created by Zensis on 6/8/2018.
//  Copyright © 2018 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ATVAdSchedule;
@class ATVAd;
@class ATVSubtitleConfig;
@class ATVMediaItem;

/**
 * To specify the type of error for a vast ad
 */
typedef enum {
    VastErrorRequestNetworkError,
    VastErrorUnknownResponse,
    VastErrorUnknownError,
    VastErrorEmptyResponse,
    VastErrorLinearAssetMismatch,
    VastErrorLoadTimeout,
    VastErrorNoAdsAfterWrapper,
    VastErrorSchemaValidationError,
    VastErrorTooManyRedirects,
    VastErrorWrapperError,
    VastErrorPlaybackError,
} ATVVastError;

typedef enum {
    VastFirstQuartile,
    VastMidpoint,
    VastThirdQuartile,
} ATVVastQuartile;


/**
 * Callback for video player events. Useful for analytic tracking.
 */
@protocol ATVVideoPlayerDelegate <NSObject>

@optional
/**
 * Called when video playback is finished.
 */
- (void)videoDidPlayFinished;

/**
 * Called when video player is dismissed.
 */
- (void)playerDidDismiss;

/**
 * Called when video player will be dismissed.
 */
- (void)playerWillDismiss;

/**
 * Called when the playhead is moved by user.
 *
 * @param second the new playhead position in seconds
 */
- (void)videoDidSeekTo:(double)second;

/**
 * Called when the player finishes buffering.
 */
- (void)videoDidBuffer __attribute__((deprecated("Replaced by -videoOnBuffer")));

/**
 * Called when the player is waiting for buffering.
 */
- (void)videoOnBuffer;

/**
 * Called when error occured during loading the video item.
 *
 * @param error the error occured
 */
- (void)videoOnError:(NSError*)error;

/**
 * Called when the player plays the video.
 */
- (void)videoOnPlay __attribute__((deprecated("Replaced by -videoOnPlay:duration:")));

/**
 * Called when the player plays the video.
 *
 * @param second current position in seconds
 * @param duration video total duration
 */
- (void)videoOnPlay:(double)second duration:(double)duration;

/**
 * Called when the player is playing.
 *
 * @param second current position in seconds
 */
- (void)videoOnTime:(double)second __attribute__((deprecated("Replaced by -videoOnTime:duration:")));

/**
 * Called during video play.
 *
 * @param second current position in seconds
 * @param duration video total duration
 */
- (void)videoOnTime:(double)second duration:(double)duration;

/**
 * Called when the player pauses.
 *
 * @param second pause position in seconds
 */
- (void)videoOnPause:(double)second __attribute__((deprecated("Replaced by -videoOnPause:duration:")));

/**
 *
 * Called when the player pauses.
 *
 * @param second pause position in seconds
 * @param duration video total duration
 */
- (void)videoOnPause:(double)second duration:(double)duration;

/**
 *
 * Called when user change closed caption from info view.
 * @param languageCode selected languageCode
 *
 */
- (void)videoClosedCaptionDidChange:(NSString *)languageCode;

/**
 * Called when start requesting ad.
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnRequest:(ATVAd*)adBreak;

/**
 * Called when ad response and parsed successfully.
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnResponse:(ATVAd*)adBreak;

/**
 * Called when the Ad start.
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnStart:(ATVAd*)adBreak;

/**
 * Called when ad is played
 *
 * @param adBreak fired ad break
 * @param duration ad total duration
 * @param second current position in seconds
 */
- (void)videoAdOnPlay:(ATVAd*)adBreak duration:(double)duration second:(double)second;

/**
 * Called when ad play reach certain quartile (first quartile, midpoint, third quartile)
 *
 * @param adBreak fired ad break
 * @param quartile quartile which playback reached
 * @param duration ad total duration
 */
- (void)videoAdOnPlayQuartile:(ATVAd*)adBreak quartile:(ATVVastQuartile)quartile duration:(double)duration;

/**
 * Called during Ad play
 *
 * @param adBreak fired ad break
 * @param duration ad total duration
 * @param second current position in seconds
 */
- (void)videoAdOnTime:(ATVAd*)adBreak duration:(double)duration second:(double)second;

/**
 * Called when Ad pause
 *
 * @param adBreak fired ad break
 * @param duration ad total duration
 * @param second pause position in second
 */
- (void)videoAdOnPause:(ATVAd*)adBreak duration:(double)duration second:(double)second;

/**
 * Called when Ad complete
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnComplete:(ATVAd*)adBreak;

/**
 * Called when ad is waiting for buffering
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnBuffer:(ATVAd*)adBreak duration:(double)duration second:(double)second;

/**
 * Called when the first ad in a linear ad pod (a sequenced group of ads) has started
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnPodStart:(ATVAd*)adBreak;

/**
 * Called when the last ad in a linear ad pod (a sequenced group of ads) has finished
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnPodComplete:(ATVAd*)adBreak;

/**
 * Called when Ad error
 *
 * @param adBreak fired ad break
 * @param error error description in string
 */
- (void)videoAdOnError:(ATVAd*)adBreak error:(NSString*)error __attribute__((deprecated("Replaced by -videoAdOnError:error:desc:")));

/**
 * Called when Ad error
 *
 * @param adBreak fired ad break
 * @param error error enum
 * @param desc error description
 */
- (void)videoAdOnError:(ATVAd*)adBreak error:(ATVVastError)error desc:(NSString*)desc;

@end


/**
 * Video player that is capable to play VAST 2 video ads and showing subtitles in SRT format.
 */
@interface ATVVideoPlayer : NSObject

/**
 * Callback for video player events.
 */
@property(weak, nonatomic) id <ATVVideoPlayerDelegate> delegate;

/**
 * VAST Ad schedule configuration.
 * The schedule should be configured before video start.
 */
@property(strong, nonatomic) ATVAdSchedule *adSchedule;

/**
 * SRT subtitle configuation.
 * Call reloadSubtitle if you modify it after video start.
 */
@property(strong, nonatomic) ATVSubtitleConfig *subtitle;

/**
 * Customize the overlay view. Useful for showing logo when playing video. The overlay layer is not shown when playing video ad.
 */
@property(nonatomic) UIView *overlayView;


/**
 * Bind the view controller with the video player.
 *
 * @param controller controller to be binded.
 */
- (void)presentWithController:(UIViewController *)controller;

/**
 * Play video.
 *
 * @param item ATVMediaItem
 * @param startPosition the starting position of video playback, default is 0
 */
- (void)playWithMediaItem:(ATVMediaItem *)item startPosition:(NSInteger)startPosition;

/**
 * Switch subtitle by index.
 * @param index ATVSubtitleConfig subtitle array index
 */
- (void)switchSubtitle:(int)index;

/**
 * On/Off subtitle
 * @param on Boolean to determine subtitle on/off
 */
- (void)toggleSubtitle:(BOOL)on;

/**
 * Start the player.
 */
- (void)start;

/**
 * Dismiss the player.
 */
- (void)dismiss;

/**
 * Get current Playing position
 */
- (double)currentPosition;

/**
 * Get duration of video
 * @return 0 will be returned when AVPlayerItem is nil
 */
- (double)videoDuration;

/**
 * Get language code of closed captions. Select closed caption with setClosedCaption by this code. This method should be called after player start to play.
 * @return list of language code in closed caption. Return empty array if no closed caption found.
 */
-(NSArray<NSString*>*)getClosedCaptionLanguageList;

/**
 * Set closed captions language. No effect if provided language not found. This method should be called after player start to play.
 *
 * @param language code getting from getClosedCaptionLanguageList
 *
 * @return Boolean to determine set closed caption success or not. Provide invalid code will return False
 */
-(BOOL)setClosedCaption:(NSString*)language;

/**
 * Get current selected closed caption. This method should be called after player start to play.
 * @return selected language code.
 */
-(NSString*)currentClosedCaption;


/**
 * Disable "Auto" options in subtitle control. This method should be called after player start to play.
 */
-(void)disableAutoClosedCaptionOptions;

@end
