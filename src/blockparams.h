// Copyright (c) 2016-2018 The CryptoCoderz Team / Newyorkcoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef NEWYORKCOIN_BLOCKPARAMS_H
#define NEWYORKCOIN_BLOCKPARAMS_H

#include "net.h"
#include "core.h"
#include "bignum.h"

// Define difficulty retarget algorithms
enum DiffMode {
    DIFF_DEFAULT = 0, // Default to invalid 0
    DIFF_PPC     = 1, // Retarget using Peercoin per-block
    DIFF_DGW     = 2, // Retarget using DarkGravityWave v3
    DIFF_VRX     = 3, // Retarget using Terminal-Velocity-RateX
};

void VRXswngPoSdebug();
void VRXswngPoWdebug();
void VRXdebug();
void GNTdebug();
void VRX_BaseEngine(const CBlockIndex* pindexLast, bool fProofOfStake);
void VRX_ThreadCurve(const CBlockIndex* pindexLast, bool fProofOfStake);
unsigned int PeercoinDiff(const CBlockIndex* pindexLast, bool fProofOfStake);
unsigned int DarkGravityWave(const CBlockIndex* pindexLast, bool fProofOfStake);
unsigned int VRX_Retarget(const CBlockIndex* pindexLast, bool fProofOfStake);
unsigned int GetNextTargetRequired(const CBlockIndex* pindexLast, bool fProofOfStake);
int64_t GetProofOfWorkReward(int64_t nHeight, int64_t nFees);
int64_t GetProofOfStakeReward(int64_t nCoinAge, int64_t nFees);


#endif // NEWYORKCOIN_BLOCKPARAMS_H
