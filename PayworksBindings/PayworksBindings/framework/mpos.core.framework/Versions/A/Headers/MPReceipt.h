//
// PAYWORKS GMBH ("COMPANY") CONFIDENTIAL
// Copyright (c) 2013 Payworks GmbH, All Rights Reserved.
//
// NOTICE:  All information contained herein is, and remains the property of COMPANY. The intellectual and technical concepts contained
// herein are proprietary to COMPANY and may be covered by European or foreign Patents, patents in process, and are protected by trade secret or copyright law.
// Dissemination of this information or reproduction of this material is strictly forbidden unless prior written permission is obtained
// from COMPANY.  Access to the source code contained herein is hereby forbidden to anyone except current COMPANY employees, managers or contractors who have executed
// Confidentiality and Non-disclosure agreements explicitly covering such access.
//
// The copyright notice above does not evidence any actual or intended publication or disclosure of this source code, which includes
// information that is confidential and/or proprietary, and is a trade secret, of COMPANY.
// ANY REPRODUCTION, MODIFICATION, DISTRIBUTION, PUBLIC  PERFORMANCE,
// OR PUBLIC DISPLAY OF OR THROUGH USE  OF THIS  SOURCE CODE  WITHOUT  THE EXPRESS WRITTEN CONSENT OF COMPANY IS STRICTLY PROHIBITED, AND IN VIOLATION OF APPLICABLE
// LAWS AND INTERNATIONAL TREATIES.  THE RECEIPT OR POSSESSION OF  THIS SOURCE CODE AND/OR RELATED INFORMATION DOES NOT CONVEY OR IMPLY ANY RIGHTS
// TO REPRODUCE, DISCLOSE OR DISTRIBUTE ITS CONTENTS, OR TO MANUFACTURE, USE, OR SELL ANYTHING THAT IT  MAY DESCRIBE, IN WHOLE OR IN PART.
#import <Foundation/Foundation.h>
#import "MPTransaction.h"
#import "MPReceiptLineItem.h"


/**
 * Receipt object containing all data that must be printed/provided on a receipt. The items are already localized accoring to the current locale and region format of the device the SDK is running on.
 * @since 2.1.0
 */
@interface MPReceipt: NSObject

/**
 * Type of the receipt (merchant or customer).
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *receiptType;

/**
 * Type of the transaction (charge or refund).
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *transactionType;

/**
 * The subject of the receipt.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nullable) MPReceiptLineItem *subject;

/**
 * The transaction identifier.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *identifier;

/**
 * The amount and currency formatted for the current system locale, using the NumberFormat.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *amountAndCurrency;

/**
 * The included tip amount and currency formatted for the current system locale, using the NumberFormat.
 * @since 2.22.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *includedTipAmountAndCurrency;

/**
 * The date formatted for the current system locale, using the ShortDatePattern.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *date;

/**
 * The time formatted for the current system locale, using the LongTimePattern.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *time;

/**
 * The status text based on the transaction state.
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) MPReceiptLineItem *statusText;

/**
 * Indicates if a signature line must be present on the receipt.
 * @since 2.1.0
 */
@property (assign, readonly, nonatomic) BOOL printSignatureLine;

/**
 * Indicates if a tip line must be present on the receipt.
 * @since 2.22.0
 */
@property (assign, readonly, nonatomic) BOOL printTipLine;

/**
 * Clearing details of the receipt.
 * Array of MPReceiptLineItem objects
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) NSArray *clearingDetails;

/**
 * Payment details of the receipt.
 * Array of MPReceiptLineItem objects
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) NSArray *paymentDetails;

/**
 * Merchant details of the receipt.
 * Array of MPReceiptLineItem objects
 * @since 2.1.0
 */
@property (strong, readonly, nonatomic, nonnull) NSArray *merchantDetails;

/**
 * Key-based lookup for individual line items.
 * @param key The key to look up
 * @return The respective line item, or nil if the item is not available
 * @since 2.1.0
 */
- (nullable MPReceiptLineItem *)receiptLineItemForKey:(MPReceiptLineKey)key;

/**
 * Pretty printed debug representation of the receipt.
 * @return A formatted string that holds all receipt information.
 * @since 2.1.0
 */
- (nonnull NSString *)prettyPrinted;

@end
