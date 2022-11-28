#include <list>
#include <string>

using namespace std;

class personal_contact
{
private:
    string name;
    time_t dateOfBirth;

public:
    string get_name();
    void   set(string _name);

    time_t getDOB();
    void   setDoB(time_t dateOfBirth);
};

enum c_type
{
    BITCOIN = 1,
    ECN
};

class crypto
{
private:
    c_type crypto_type;
    int    crypto_count;
    int    crypto_value;

public:
    c_type get_crypto_type(c_type type);
    void   set_crypto_type();

    int  get_crypto_count();
    void set_crypto_count(int count);

    int  get_crypto_value();
    void set_crypto_value(int value);
};

class transaction
{
private:
    time_t transaction_date;
    int    amount;

public:
    time_t get_transaction_date();
    void   set_transaction_date(time_t date);

    int  get_amount();
    void set_amount(int amount);
};

class bank_infomation
{
private:
    string bank_name;
    int    Account_number;
    bool   Account_type;
    int    bank_balance;

public:
    string get_bank_name();
    void   set_bank_name(string name);

    int  get_accoun_number();
    void set_account_number();

    bool get_account_type();
    void set_account_type(bool account);

    int  get_bank_balance();
    void set_account_balance(int balance);
};

class Account
{
private:
    list<crypto>      crypto_own_by_account;
    int               current_cash_balance;
    list<transaction> info_past_transactions;
    bank_infomation   _bank_info_for_owner;
    personal_contact  _personal_info;

public:
    list<crypto> get_coin_own();
    void         set_coin_own(list<crypto> crypto);

    int  get_cash_balance();
    void set_cash_balance(int cash_balance);

    list<transaction> get_info_past_transaction();
    void              set_info_past_transaction(list<transaction> transaction);

    bank_infomation get_bank_info();
    void            set_bank_info(bank_infomation bnk_info);

    personal_contact get_personal_info();
    void             set_personal_contact(personal_contact personal_cntct);
};
