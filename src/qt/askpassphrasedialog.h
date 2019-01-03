// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKpassphraseDIALOG_H
#define BITCOIN_QT_ASKpassphraseDIALOG_H

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskpassphraseDialog;
}

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskpassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passphrase twice and encrypt */
        UnlockAnonymize, /**< Ask passphrase and unlock only for anonymization */
        Unlock,          /**< Ask passphrase and unlock */
        ChangePass,      /**< Ask old passphrase + new passphrase twice */
        Decrypt          /**< Ask passphrase and decrypt wallet */
    };

    explicit AskpassphraseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskpassphraseDialog();

    void accept();

private:
    Ui::AskpassphraseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // BITCOIN_QT_ASKpassphraseDIALOG_H
