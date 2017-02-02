//
//  ATVAdSchedule.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2016 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ATVAd;

/**
 * Ad container holds all the ad breaks that will be played in the video player.
 */
@interface ATVAdSchedule : NSObject <NSCopying>

/** Preroll ads in sorted order */
@property(nonatomic, readonly) NSMutableArray<ATVAd *> *preRolls;
/** Midroll ads in sorted order */
@property(nonatomic, readonly) NSMutableArray<NSMutableArray<ATVAd *> *> *midRolls;
/** Postroll ads in sorted order */
@property(nonatomic, readonly) NSMutableArray<ATVAd *> *postRolls;
/** Midroll offsets in sorted order */
@property(nonatomic, readonly) NSMutableArray<NSNumber *> *midRollOffsets;

/**
 * Customize the ad loading text.
 */
@property(nonatomic) NSString *adLoadingText;

/**
 * Customize the ad countdown text. Remember to have a <code>%d</code> placehold to show the number of seconds left for that video ad.
 */
@property(nonatomic) NSString *adCountdownText;

/**
 * Ad countdown text font.
 */
@property(nonatomic) UIFont *adCountdownFont;

/**
 * Ad countdown text text color.
 */
@property(nonatomic) UIColor *adCountdownTextColor;

/**
 * Ad countdown text stroke color.
 */
@property(nonatomic) UIColor *adCountdownStrokeColor;

/**
 * Ad countdown text stroke width.
 *
 * Note that the countdown text is in two layers: stroke and foreground text. The stroke width should be doubled as
 * inner half of the stroke is covered by the foreground text.
 */
@property(nonatomic) CGFloat adCountdownStrokeWidth;

/**
 * Add a ad break to the container.
 *
 * It will organize the ad break when inserting.
 *
 * @param adBreak ad break to be added
 */
- (void)addAdBreak:(ATVAd *)adBreak;

/**
 * Copy object.
 *
 * @param zone This parameter is ignored. Memory zones are no longer used by Objective-C.
 * @return a new instance that's a copy of the receiver
 */
- (id)copyWithZone:(NSZone *)zone;

@end
