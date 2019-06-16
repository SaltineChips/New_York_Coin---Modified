// Copyright (c) 2016-2018 The CryptoCoderz Team / Newyorkcoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef NEWYORKCOIN_MINING_H
#define NEWYORKCOIN_MINING_H

#include "bignum.h"

/** Minimum nCoinAge required to stake PoS (v2) */
static const unsigned int nStakeMinAge = 2 * 60 * 60; // 2 hours
/** Minimum nCoinAge required to stake PoS (v3) */
static const int nStakeMinConfirmations = 90; // 5(minutes) × 90(confirms) ÷ 60(minutes) = 7.5 hours
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 10 * 60;
/** PoS Subsidy */
static const int64_t COIN_YEAR_REWARD = 250 * CENT; // Miscalculated (2 day hinderance, no major issues)
/** PoS Subsidy 2 */
static const int64_t COIN_YEAR_REWARD2 = 19 * CENT; // ~25% 4300000000 annually
/** PoS Subsidy 3 */
static const int64_t COIN_YEAR_REWARD3 = 4 * CENT; // ~5% 860000000 annually
/** PoS Subsidy 4 */
static const int64_t COIN_YEAR_REWARD4 = 1 * CENT; // ~1% TODO: Correct numbers
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = double(0.5) * 60;
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = double(0.25) * 60;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 1 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Reserve block subsidy */
static const int64_t nBlockRewardReserve = 200000000 * COIN; // 12.5B Currently + 4739414758.4 for new chain swap (94.788295168 blocks)
/** Starting block subsidy */
static const int64_t nBlockPoWReward = 10000 * COIN;
/** Invalid block subsidy */
static const int64_t nBlockRewardBuffer = double(0.1) * COIN;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 60;

#endif
