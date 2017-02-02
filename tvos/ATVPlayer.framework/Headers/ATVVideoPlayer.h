//
//  ATVVideoPlayer.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2016 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ATVAdSchedule;
@class ATVAd;
@class ATVSubtitleConfig;
@class ATVMediaItem;

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
 * Called when the playhead is moved by user.
 *
 * @param second the new playhead position in seconds
 */
- (void)videoDidSeekTo:(double)second;

/**
 * Called when the player finishes buffering.
 */
- (void)videoDidBuffer;

/**
 * Called when the player plays the video.
 */
- (void)videoOnPlay;

/**
 * Called when the player pauses.
 *
 * @param second pause position in seconds
 */
- (void)videoOnPause:(double)second;

/**
 * Called when the player has error.
 *
 * @param error error description in string
 */
- (void)videoOnError:(NSString*)error;

/**
 * Called when the Ad start.
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnStart:(ATVAd*)adBreak;

/**
 * Called when Ad playing
 *
 * @param adBreak fired ad break
 * @param duration ad total duration
 * @param second remaining time in seconds
 */
- (void)videoAdOnPlay:(ATVAd*)adBreak duration:(double)duration second:(double)second;

/**
 * Called when Ad complete
 *
 * @param adBreak fired ad break
 */
- (void)videoAdOnComplete:(ATVAd*)adBreak;

/**
 * Called when Ad complete
 *
 * @param adBreak fired ad break
 * @param error error description in string
 */
- (void)videoAdOnError:(ATVAd*)adBreak error:(NSString*)error;

@end

/**
 * Video player that is capable to play VAST 2 video ads and showing subtitles in SRT format.
 */
@interface ATVVideoPlayer : NSObject

/**
 * Callback for video player events.
 */
@property(strong, nonatomic) id <ATVVideoPlayerDelegate> delegate;

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
-(void)toggleSubtitle:(BOOL)on;

/**
 * Start the player.
 */
- (void)start;

/**
 * Dismiss the player.
 */
- (void)dismiss;

@end
