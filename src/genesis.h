// Copyright (c) 2016-2018 The CryptoCoderz Team / Newyorkcoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef NEWYORKCOIN_GENESIS_H
#define NEWYORKCOIN_GENESIS_H

#include "bignum.h"

/** Genesis Start Time */
static const unsigned int timeGenesisBlock = 1535932800; // Mon, 05 Sep 2016 07:00:00 GMT
/** Genesis RegNet Start Time */
static const unsigned int timeRegNetGenesis = 1535933000; // Mon, 05 Sep 2016 07:00:00 GMT
/** Genesis Nonce */
static const unsigned int nNonceMain = 1791365;
/** Genesis Nonce Testnet */
static const unsigned int nNonceTest = 136026;
/** Genesis Nonce Regnet */
static const unsigned int nNonceReg = 8;
/** Main Net Genesis Block */
static const uint256 nGenesisBlock("0x0000035c3b0548a250776f683710a34055e35dbe57ec99d23c824b988997303a");
/** Test Net Genesis Block */
static const uint256 hashTestNetGenesisBlock("0x00009f331214dd765725ed4a388a20646019445e0c77eb4adc9846cb36dae687");
/** Reg Net Genesis Block */
static const uint256 hashRegNetGenesisBlock("0x6c793942dc19f09ceb17a17eb9da6dcc357cd4ebfa29c0f53dd82decfba92cd6");
/** Genesis Merkleroot */
static const uint256 nGenesisMerkle("0xca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1");

/** Genesis Block MainNet */
/*
Hashed MainNet Genesis Block Output
block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
block.nTime = 1535932800
block.nNonce = 1791365
block.GetHash = 0000035c3b0548a250776f683710a34055e35dbe57ec99d23c824b988997303a

*/

/** Genesis Block TestNet */
/*
Hashed TestNet Genesis Block Output
block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
block.nTime = 1535932800
block.nNonce = 136026
block.GetHash = 00009f331214dd765725ed4a388a20646019445e0c77eb4adc9846cb36dae687
*/

/** Genesis Block RegNet */
/*
Hashed RegNet Genesis Block Output
block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
block.nTime = 1535933000
block.nNonce = 8
block.GetHash = 6c793942dc19f09ceb17a17eb9da6dcc357cd4ebfa29c0f53dd82decfba92cd6
*/

#endif
