// Copyright (c) 2016-2018 The CryptoCoderz Team / Newyorkcoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef NEWYORKCOIN_FORK_H
#define NEWYORKCOIN_FORK_H

#include "bignum.h"

/** Genesis Block Height */
static const int64_t nGenesisHeight = 0;
/** Reserve Phase start block */
static const int64_t nReservePhaseStart = 10;
/** Reserve Phase end block */
static const int64_t nReservePhaseEnd = 356; // rounded +95 blocks for ~17.2 Swap mine
/** Target Blocktime Retard */
static const int64_t nBlocktimeregress = 125000; // Retard block time
/** Newyorkcoin system patch fork*/
static const int64_t nGravityFork = 615000; // Light Newyorkcoin chain fork for DarkGravityWave and block time redux.
/** Newyorkcoin low gravity fix fork*/
static const int64_t nlowGravity = 642000; // Correct low gravity issue with DGW implementation.
/** PoS25 Phase start block */
static const int64_t nPoS25PhaseStart = 20000; // Dropped date due to 25% staking miscalculation
/** PoS5 Phase start block */
static const int64_t nPoS5PhaseStart = 2000800; // Begins @ ~48892586514.24 NYC
/** PoS1 Phase start block */
static const int64_t nPoS1PhaseStart = 3000300; // Begins @ ~48892586514.24 NYC
/** System Upgrade 01 */
static const int64_t sysUpgrade_01 = 674400; // Start swinging difficulty skew, and adaptive block sizes
/** Block type swing patch */
static const int64_t SWING_PATCH = 1509537600; // Patch skew to a more even swing w/ 50/50 block select
/** Value patch on swing */
static const int64_t STALL_PULL = 1515153600; // Revision to swing patch | Friday, January 5, 2018 12:00:00 PM
/** Velocity toggle block */
static const int64_t VELOCITY_TOGGLE = 650000; // Implementation of the Velocity system into the chain.
/** Velocity retarget toggle block */
static const int64_t VELOCITY_TDIFF = 667350; // Use Velocity's retargetting method.
/** Proof-of-Stake Version 3.0 implementation fork */
inline bool IsProtocolV3(int64_t nTime) { return TestNet() || nTime > 1535673600; } // ON (TOGGLED Fri, 31 Aug 2018 00:00:00 GMT)

#endif
