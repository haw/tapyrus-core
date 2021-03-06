// Copyright (c) 2018-2019 Chaintope Inc.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/test_keys_helper.h>

#include <key.h>
#include <pubkey.h>
#include <secp256k1.h>
#include <utilstrencodings.h>

std::vector<CPubKey> validPubKeys(unsigned int keyCount)
{
    std::vector<CPubKey> keys;
    for (unsigned int i = 0; i < keyCount; i++) {
        std::vector<unsigned char> vch = ParseHex(ValidPubKeyStrings[i]);
        CPubKey pubkey(vch.begin(), vch.end());
        keys.push_back(pubkey);
    }
    return keys;
}

std::string combinedPubkeyString(unsigned int keyCount)
{
    std::string r;
    for (unsigned int i = 0; i < keyCount; i++) {
        r += ValidPubKeyStrings[i];
    }
    return r;
}

std::vector<CKey> getValidPrivateKeys(const unsigned int keycount)
 {
    std::vector<CKey> privateKeys;
    for(unsigned int i = 0; i < keycount; i ++)
    {
        CKey keyBuffer;
        keyBuffer.Set(validPrivateKeys[i], validPrivateKeys[i] + 32, true);
        privateKeys.push_back(keyBuffer);
    }
    return privateKeys;
}