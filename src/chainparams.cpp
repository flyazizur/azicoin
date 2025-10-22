// AZIcoin modifications: bech32 HRP, default port, message start, genesis template

#include <assert.h>
#include "chainparams.h"
#include "consensus/params.h"
#include "util/strencodings.h"

// NOTE: This is a focused snippet intended to replace the relevant section in CMainParams/ CRegTestParams
// Ensure you merge into the correct surrounding file context in your local repo.

namespace {

static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward);

} // anonymous namespace

void UpdateAZIChainParams(CChainParams& params)
{
    CMutableChainParams &p = static_cast<CMutableChainParams&>(params);
    CChainParams::BaseParams& base = p.BaseParams();

    // Set bech32 HRP to "az"
    p.SetBech32HRP(std::string("az"));

    // Default network port for AZI mainnet
    p.SetDefaultPort(18888);

    // Unique message start (avoid Bitcoin collisions)
    unsigned char msgStart[4] = {0xa1, 0xcf, 0x7d, 0x2b};
    p.SetMessageStart(msgStart);

    // Genesis template (low difficulty for local genesis finding). Replace nTime/nNonce/assert after running genesis_finder.
    CBlock genesis = CreateGenesisBlock(1700000000 /* nTime: replace after genesis find */, 0 /* nNonce: replace */, 0x1f00ffff /* nBits: low difficulty for fast finding */, 1 /* version */, 1269 * COIN);
    p.SetGenesisBlock(genesis);

    // Placeholder hash: replace with the real genesis hash after running the finder
    p.SetGenesisHash(uint256S("0000000000000000000000000000000000000000000000000000000000000000"));

    // Halving interval remains Bitcoin's default (210000)
    p.GetConsensus().nSubsidyHalvingInterval = 210000;
}