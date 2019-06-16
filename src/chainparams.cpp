// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2016-2018 The Newyorkcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x1a;
        pchMessageStart[1] = 0x2a;
        pchMessageStart[2] = 0x3a;
        pchMessageStart[3] = 0x4a;
        vAlertPubKey = ParseHex("04e22531e96c9056be6b659c91a94fbf1ab8cd54b88695c62f7c2f81f85d1615975131a669df3be611393f454852a2d08c6314bba5ca3cbe5616262da3d4a6efac");
        nDefaultPort = 17020;
        nRPCPort = 17021;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Taiwan Hospital Initiates A Blockchain Record Storage Platform | Steve Kaaru"; // 1535932800 Monday, September 3, 2018 12:00:00 AM
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, timeGenesisBlock, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = timeGenesisBlock;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = nNonceMain;
        /** Genesis Block MainNet */
        /*
        Hashed MainNet Genesis Block Output
        block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
        block.nTime = 1535932800
        block.nNonce = 1791365
        block.GetHash = 0000035c3b0548a250776f683710a34055e35dbe57ec99d23c824b988997303a

        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == nGenesisBlock);
        assert(genesis.hashMerkleRoot == nGenesisMerkle);

        /** DEPRICATED IN QT 5.6+ (To compile on Qt5.5.1 and lower uncomment  */
        /*
        base58Prefixes[PUBKEY_ADDRESS] = list_of(60);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(22);
        base58Prefixes[SECRET_KEY] =     list_of(188);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
        */
        /** REQUIRED IN QT 5.6+  (To compile on Qt5.5.1 and lower comment out below) */
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,22);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,188);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // Newyorkcoin dns seeds
        //vSeeds.push_back(CDNSSeedData("location",  "location"));

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        // Initial block spacing, attempted 40 second block time
        nTargetSpacing = 1 * 40;
        // Block rate reduced for ~40 Second block times
        // Due to hybrid mining blocktime still varied wildly during
        // this time between 15 seconds and 1 minute
        if(nBestHeight > nBlocktimeregress)
            nTargetSpacing = 2.5 * 60;
        // Block rate reduced for 3-5 Minute block times
        // this is in conjunction with DGW-v3 retarget fork
        if(nBestHeight > nGravityFork)
            nTargetSpacing = BLOCK_SPACING * 1;
        nTargetTimespan = 10 * nTargetSpacing;
        nStartPoSBlock = 2125; // Delay PoS start until swap start

    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xb1;
        pchMessageStart[1] = 0xb2;
        pchMessageStart[2] = 0xb3;
        pchMessageStart[3] = 0xb4;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);

        vAlertPubKey = ParseHex("02e22531e96c9056be6b659c91a94f9089897d5257fe044b88695c62f7c2f81879898967345612e611393f454852a2d08c6314bba5ca3cbe5616262db3d4a6efac");
        nDefaultPort = 27020;
        nRPCPort = 27021;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = nNonceTest;

        /** Genesis Block TestNet */
        /*
        Hashed TestNet Genesis Block Output
        block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
        block.nTime = 1535932800
        block.nNonce = 136026
        block.GetHash = 00009f331214dd765725ed4a388a20646019445e0c77eb4adc9846cb36dae687
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == hashTestNetGenesisBlock);

        vFixedSeeds.clear();
        vSeeds.clear();

        /** DEPRICATED IN QT 5.6+ (To compile on Qt5.5.1 and lower uncomment  */
        /*
        base58Prefixes[PUBKEY_ADDRESS] = list_of(113);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(196);
        base58Prefixes[SECRET_KEY]     = list_of(241);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
        */
        /** REQUIRED IN QT 5.6+  (To compile on Qt5.5.1 and lower comment out below */
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,113);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,241);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nTargetSpacing = 20;
        nStartPoSBlock = 2880;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0x1c;
        pchMessageStart[1] = 0x2c;
        pchMessageStart[2] = 0x3c;
        pchMessageStart[3] = 0x4c;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = timeRegNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = nNonceReg;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18444;
        strDataDir = "regtest";

        /** Genesis Block RegNet */
        /*
        Hashed RegNet Genesis Block Output
        block.hashMerkleRoot == ca3ff1a46e9b1e241c6a7cc46a388183236d1414402cb569dd72e6ba0671e4a1
        block.nTime = 1535933000
        block.nNonce = 8
        block.GetHash = 6c793942dc19f09ceb17a17eb9da6dcc357cd4ebfa29c0f53dd82decfba92cd6
        */

        assert(hashGenesisBlock == hashRegNetGenesisBlock);

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
