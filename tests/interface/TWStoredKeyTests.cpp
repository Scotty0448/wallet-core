// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TWTestUtilities.h"

#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWStoredKey.h>

#include "../src/HexCoding.h"

#include <gtest/gtest.h>

TEST(TWStoredKey, importInvalidKey) {
    auto bytes = TW::parse_hex("fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141");
    auto data = WRAPD(TWDataCreateWithBytes(bytes.data(), bytes.size()));
    auto name = WRAPS(TWStringCreateWithUTF8Bytes("test"));

    auto eth = TWStoredKeyImportPrivateKey(data.get(), name.get(), name.get(), TWCoinTypeEthereum);
    auto ont = TWStoredKeyImportPrivateKey(data.get(), name.get(), name.get(), TWCoinTypeOntology);
    auto tezos = TWStoredKeyImportPrivateKey(data.get(), name.get(), name.get(), TWCoinTypeTezos);

    ASSERT_EQ(eth, nullptr);
    ASSERT_EQ(ont, nullptr);
    ASSERT_NE(tezos, nullptr);
}
