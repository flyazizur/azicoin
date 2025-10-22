// AZIcoin: modified GetBlockSubsidy with initial 1269 AZI and floor at 0.1269 AZI
#include <consensus/amount.h>
#include "validation.h"
#include "consensus/params.h"

CAmount GetBlockSubsidy(int nHeight, const Consensus::Params& consensusParams)
{
    // Initial subsidy: 1269 AZI
    CAmount nSubsidy = 1269 * COIN;
    int halvings = nHeight / consensusParams.nSubsidyHalvingInterval;

    // floor value in smallest units (zoo): 0.1269 AZI = 0.1269 * 1e8 = 12,690,000
    const CAmount nFloor = (CAmount)12690000; // 0.1269 * COIN

    for (int i = 0; i < halvings; ++i) {
        nSubsidy = nSubsidy / 2;
        if (nSubsidy <= nFloor) {
            nSubsidy = nFloor;
            break;
        }
    }
    return nSubsidy;
}