// Small helper to brute-force a genesis block for the modified chainparams.
// Build this against the AZIcoin/Bitcoin Core build environment.

#include <iostream>
#include <stdint.h>
#include "chainparams.h"
#include "primitives/block.h"
#include "pow.h"
#include "uint256.h"
#include "arith_uint256.h"

int main(int argc, char* argv[])
{
    // Use regtest parameters (assumes chainparams.cpp regtest uses same template nBits)
    SelectParams(CBaseChainParams::REGTEST);
    const CChainParams &params = Params();

    CBlock genesis = CreateGenesisBlock(1700000000, 0, 0x1f00ffff, 1, 1269 * COIN);

    for (uint32_t n = 0; n < UINT32_MAX; ++n) {
        genesis.nNonce = n;
        uint256 hash = genesis.GetHash();
        arith_uint256 ahash = UintToArith256(hash);
        arith_uint256 target = UintToArith256(params.GetConsensus().powLimit);
        if (ahash <= target) {
            std::cout << "FOUND genesis: nonce=" << n << " hash=" << hash.GetHex() << " time=" << genesis.nTime << std::endl;
            return 0;
        }
        if ((n & 0xFFFF) == 0) genesis.nTime += 1;
    }
    std::cout << "No genesis found in uint32 range. Increase search or lower difficulty." << std::endl;
    return 1;
}