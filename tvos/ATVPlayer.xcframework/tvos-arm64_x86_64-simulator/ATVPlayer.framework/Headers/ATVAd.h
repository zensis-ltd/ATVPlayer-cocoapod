//
//  ATVAd.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2018 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * To specify which roll of this ad.
 */
typedef enum {
    /** Represent a preroll ad */
            ATVPreRollAd,
    /** Represent a midroll ad */
            ATVMidRollAd,
    /** Represent a postroll ad */
            ATVPostRollAd
} ATVAdRoll;

/**
 * Represent one ad break.
 */
@interface ATVAd : NSObject <NSCopying>

/** VAST 2 URL */
@property(nonatomic, readonly) NSURL *vastUrl;
/** When will this ad break plays (unit: second) */
@property(nonatomic, readonly) unsigned long offset;
/** Whether this ad break is played by ATVVideoPlayer */
@property(nonatomic) BOOL isPlayed;
/** The ad is in which ad roll */
@property(nonatomic, readonly) ATVAdRoll roll;
/** Ad title from vast response */
@property(nonatomic, copy) NSString *adTitle;
/** Ad description from vast response */
@property(nonatomic, copy) NSString *adDescription;

/**
 * Please use the other init methods.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * Create a midroll ad break.
 *
 * @param vastUrl VAST 2 XML URL
 * @param offset when will this ad break plays (unit: second)
 *
 * @return midroll ad break
 */
- (id)initMidRollWithVastUrl:(NSURL *)vastUrl offset:(unsigned long)offset;

/**
 * Create a preroll ad break.
 *
 * @param vastUrl VAST 2 XML URL
 *
 * @return preroll ad break
 */
- (id)initPreRollWithVastUrl:(NSURL *)vastUrl;

/**
 * Create a postroll ad break.
 *
 * @param vastUrl VAST 2 XML URL
 *
 * @return postroll ad break
 */
- (id)initPostRollWithVastUrl:(NSURL *)vastUrl;

/**
 * Description for this object.
 *
 * Useful for debugging.
 *
 * @return description with attributes' values
 */
- (NSString *)description;

/**
 * Copy object.
 *
 * @param zone This parameter is ignored. Memory zones are no longer used by Objective-C.
 * @return a new instance that's a copy of the receiver
 */
- (id)copyWithZone:(NSZone *)zone;

@end
