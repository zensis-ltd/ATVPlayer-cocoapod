//
//  SKVASTError.h
//  VAST
//
//  Created by Jay Tucker on 11/12/13.
//  Copyright (c) 2013 Nexage. All rights reserved.
//

// Error definitions
typedef enum {
    VASTErrorNoAd,
    VASTErrorNoAdAfterRedirect,
    VASTErrorXMLParse,
    VASTErrorSchemaValidation,
    VASTErrorTooManyWrappers,
    VASTErrorNoCompatibleMediaFile,
    VASTErrorNoInternetConnection,
    VASTErrorLoadTimeout,
    VASTErrorPlayerNotReady,
    VASTErrorPlaybackError,
    VASTErrorMovieTooShort,
    VASTErrorPlayerHung,
    VASTErrorPlaybackAlreadyInProgress
} SKVASTError;
